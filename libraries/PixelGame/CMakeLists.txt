#
#  PixelGame
#  CMakeLists.txt
#
#  Created on: 2014/12/01
#      Author: Hans Robeers (https://github.com/hrobeers)
#

project(PixelGame)

set(SRC
    NeopixelPixelRenderer.cpp
    NeuroPixelRenderer.cpp
    SDLPixelRenderer.cpp
)

set(HDR
    NeopixelPixelRenderer.h
    NeuroPixelRenderer.h
    PixelGameInclude.h
    PixelRenderer.h
    SDLPixelRenderer.h
    SoundPlayer.h
)

add_library(PixelGame ${SRC} ${HDR})

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/../Adafruit_NeoMatrix")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/../Adafruit_NeoPixel")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/../Adafruit_GFX")

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS}) # ${SDL2IMAGE_INCLUDE_DIRS})
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

target_link_libraries(PixelGame
    ${SDL2_LIBRARIES}
)
