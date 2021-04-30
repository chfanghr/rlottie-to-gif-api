#pragma once

#include "RenderError.h"

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/Types.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class RenderResult : public oatpp::DTO {
  DTO_INIT(RenderResult, DTO)

  DTO_FIELD(Object < RenderError >, error) = nullptr;

  DTO_FIELD(Vector < UInt8 >, gifData, "gif_data") = {};
};

#include OATPP_CODEGEN_END(DTO)