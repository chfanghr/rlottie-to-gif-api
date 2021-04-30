CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(rlottie-to-gif-api)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_SUBDIRECTORY(libs/zlib)
ADD_SUBDIRECTORY(libs/gzip-hpp)
ADD_SUBDIRECTORY(libs/oatpp)
ADD_SUBDIRECTORY(libs/rlottie)

ADD_LIBRARY(gif
            libs/gif-h/gif.h
            libs/gif-h/gif.cc
            libs/gif-h/helper.h
            libs/gif-h/helper.cc)

ADD_LIBRARY(service-lib
            src/controller/RenderController.h
            src/controller/RenderController.cc
            src/dto/RenderRequest.h
            src/dto/RenderResult.h
            src/dto/RenderError.h
            src/AppComponent.h
            src/utility/DoRender.h
            src/utility/DoRender.cc
            src/utility/GifBuilder.h
            src/utility/GifBuilder.cc)

ADD_EXECUTABLE(service src/App.cc)

TARGET_INCLUDE_DIRECTORIES(service-lib PRIVATE libs/rlottie/inc)
TARGET_INCLUDE_DIRECTORIES(service-lib PRIVATE libs/gif-h)
TARGET_INCLUDE_DIRECTORIES(service-lib PRIVATE libs/gzip-hpp/include)
TARGET_INCLUDE_DIRECTORIES(service-lib PRIVATE src/)

TARGET_INCLUDE_DIRECTORIES(service PRIVATE src/)

TARGET_LINK_LIBRARIES(service-lib PRIVATE oatpp)
TARGET_LINK_LIBRARIES(service-lib PRIVATE rlottie)
TARGET_LINK_LIBRARIES(service-lib PRIVATE gif)
TARGET_LINK_LIBRARIES(service-lib PRIVATE zlib)

TARGET_LINK_LIBRARIES(service PRIVATE service-lib)
TARGET_LINK_LIBRARIES(service PRIVATE oatpp)
