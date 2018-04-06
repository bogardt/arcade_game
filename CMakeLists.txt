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
    SOURCES_DIR_MSDL_1_2 ${CMAKE_SOURCE_DIR}/graphics/SDL-1.2
)

set (
    INCLUDES_DIR ${CMAKE_SOURCE_DIR}/includes
)

set (
    INCLUDES_DIR_MSDL_1_2 ${CMAKE_SOURCE_DIR}/graphics/SDL-1.2
)

set (
    INCLUDE_DIR_SDL_HEADERS_DIR ${CMAKE_SOURCE_DIR}/libraries/unix/SDL/headers
)

set (
    SOURCES
    ${SOURCES_DIR}/Main.cpp
)

set (
    SOURCES_MSDL_1_2
    ${SOURCES_DIR_MSDL_1_2}/mSDL.cpp
)

include_directories(
  ${INCLUDES_DIR}
  ${INCLUDES_DIR_MSDL_1_2}
  ${INCLUDE_DIR_SDL_HEADERS_DIR}
)

add_executable (
    Arcade
    ${SOURCES}
    ${SOURCES_MSDL_1_2}
)
if (UNIX)
target_link_libraries(
    Arcade
    ${CMAKE_SOURCE_DIR}/libraries/unix/SDL/libs/libSDL-1.2.so
)
endif (UNIX)
if (WIN32)
endif (WIN32)
