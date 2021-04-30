#pragma once

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/Types.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class RenderRequest : public oatpp::DTO {
  DTO_INIT(RenderRequest, DTO)

  DTO_FIELD(UInt32, width) = 200u;
  DTO_FIELD(UInt32, height) = 200u;
  DTO_FIELD(Float64 , fps) = 0.0;
  DTO_FIELD(String, rlottieData, "rlottie_data");
};

#include OATPP_CODEGEN_END(DTO)
