#include "DoRender.h"

#include "GifBuilder.h"

#include <cmath>

oatpp::Object<RenderResult> doRender(const oatpp::Object<RenderRequest> &renderRequest) {
  static unsigned int cacheCounter = 0; // rlottie uses caches for internal optimizations

  auto errorObject = RenderError::createShared();
  auto resultObject = RenderResult::createShared();

  auto player = rlottie::Animation::loadFromData(renderRequest->rlottieData->std_str(), std::to_string(cacheCounter++));

  if (!player) {
    errorObject->reason = "failed to create rlottie animation";
    resultObject->error = errorObject;
    return resultObject;
  }

  double fps = 0;
  if (renderRequest->fps == 0.0) {
    fps = player->frameRate();
  }

  const double averageDelay = 100 / fps;
  const double averageDelayFractional = averageDelay - (int) averageDelay;
  const int longFrameFrequency = averageDelayFractional > 0 ? (int) std::round(1 / averageDelayFractional) : 1;

  const size_t longFrameDuration = (size_t) std::max(2.0, ceil(averageDelay));
  const size_t shortFrameDuration = (size_t) std::max(2.0, floor(averageDelay));

  uint32_t width = renderRequest->width;
  uint32_t height = renderRequest->height;

  auto buffer = std::unique_ptr<uint32_t[]>(new uint32_t[width * height]);
  size_t frameCount = player->totalFrame();

  GifBuilder builder(width, height, 2);
  for (size_t i = 0; i < frameCount; i++) {
    rlottie::Surface surface(buffer.get(), width, height, width * 4);
    player->renderSync(i, surface);

    const auto currentDelay = i % longFrameFrequency ? shortFrameDuration : longFrameDuration;
    builder.addFrame(surface, currentDelay);
  }

  auto gifData = builder.done();

  std::copy(gifData.begin(), gifData.end(), std::back_inserter(*resultObject->gifData));

  if (resultObject->gifData->back() == 0) {
    resultObject->gifData->pop_back();
  }

  return resultObject;
}