#pragma once

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/Types.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class RenderError : public oatpp::DTO {
  DTO_INIT(RenderError, DTO);

  DTO_FIELD(String, reason);
};

#include OATPP_CODEGEN_END(DTO)