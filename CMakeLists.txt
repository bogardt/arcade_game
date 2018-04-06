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
    SOURCES_DIR ./srcs
)

set (
    INCLUDES_DIR ./includes
)

set (
    SOURCES
    ${SOURCES_DIR}/Main.cpp
)

include_directories(
  ${INCLUDES_DIR}
)

add_executable (
    Arcade
    ${SOURCES}
)
