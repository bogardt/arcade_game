cmake_minimum_required (
    VERSION 3.5
)

project (
    Arcade
)

set (
    CMAKE_CXX_FLAGS "-Wall -Wextra -g3 -O0"
)

set (
    SOURCES_DIR ${CMAKE_SOURCE_DIR}/srcs
)

set (
    SOURCES_DIR_SDL_1_2 ${CMAKE_SOURCE_DIR}/graphic/SDL-1.2
)

set (
    INCLUDES_DIR ${CMAKE_SOURCE_DIR}/includes
)

set (
    SDL_HEADERS_DIR ${CMAKE_SOURCE_DIR}/libraries/unix/SDL/headers
)

set (
    SOURCES
    ${SOURCES_DIR}/Main.cpp
)

set (
    SOURCES_SDL_1_2
    ${SOURCES_DIR_SDL_1_2}/Init.cpp
)

include_directories(
  ${INCLUDES_DIR}
  ${SDL_HEADERS_DIR}
)

add_executable (
    Arcade
    ${SOURCES}
    ${SOURCES_SDL_1_2}
)

target_link_libraries(
    Arcade
    ${CMAKE_SOURCE_DIR}/libraries/unix/SDL/libs/libSDL-1.2.so
)

