#pragma once

#include <sstream>
#include <vector>

#include <gif.h>
#include <rlottie.h>

class GifBuilder {
 public:
  GifBuilder(
      uint32_t width,
      uint32_t height,
      uint32_t delay
  );

  ~GifBuilder();

  void addFrame(rlottie::Surface &s, uint32_t delay);

  std::vector<uint8_t> done();
 private:
  bool isDone = false;

  gif::GifWriter handle;

  void argb2rgba(rlottie::Surface &s);
};
