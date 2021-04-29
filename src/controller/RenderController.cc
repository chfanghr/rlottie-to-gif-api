#include "RenderController.h"

#include "dto/RenderResult.h"

oatpp::Object<RenderResult> doRender(const oatpp::Object<RenderRequest> &renderRequest);

std::shared_ptr<oatpp::web::protocol::http::outgoing::Response>
RenderController::render(const Object<RenderRequest> &renderRequest) {
  auto renderResult = doRender(renderRequest);
  auto statusCode = renderResult->error ? Status::CODE_400 : Status::CODE_200;
  return createDtoResponse(statusCode, renderResult);
}