#pragma once

#include "dto/RenderRequest.h"

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>

#include OATPP_CODEGEN_BEGIN(ApiController)

class RenderController : public oatpp::web::server::api::ApiController {
 public:
  explicit RenderController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
      : oatpp::web::server::api::ApiController(objectMapper) {}

 public:
  ENDPOINT("POST", "/doRender", render, BODY_DTO(Object < RenderRequest > , renderRequest));

};

#include OATPP_CODEGEN_END(ApiController)
