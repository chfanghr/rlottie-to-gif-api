#pragma once

#include "dto/RenderRequest.h"
#include "dto/RenderResult.h"

oatpp::Object<RenderResult> doRender(const oatpp::Object<RenderRequest> &renderRequest);