cmake_minimum_required (
    VERSION 3.5
)

project (
    Arcade
)

if (UNIX)
set (
    CMAKE_CXX_FLAGS "-Wall -Wextra -g3 -O0"
)
endif (UNIX)

set (
    SOURCES_DIR ${CMAKE_SOURCE_DIR}/srcs
)

set (
    HEADERS_DIR ${CMAKE_SOURCE_DIR}/headers
)

set (
    GRAPHIC_DIR ${CMAKE_SOURCE_DIR}/graphic
)

set (
    AUDIO_DIR ${CMAKE_SOURCE_DIR}/audio
)

set (
    GRAPHIC_MSFML_DIR ${GRAPHIC_DIR}/MSFML
)

set (
    AUDIO_MSFML_DIR ${AUDIO_DIR}/MSFML
)

set (
    SOURCES
    ${SOURCES_DIR}/Main.cpp
    ${SOURCES_DIR}/Engine.cpp
    ${GRAPHIC_MSFML_DIR}/AnimatedSprite.cpp
    ${GRAPHIC_MSFML_DIR}/Animation.cpp
    ${GRAPHIC_MSFML_DIR}/TextureManager.cpp
    ${GRAPHIC_MSFML_DIR}/Timer.cpp
    ${GRAPHIC_MSFML_DIR}/mSFML.cpp
    ${AUDIO_MSFML_DIR}/Audio.cpp
)
set (
    HEADERS
    ${HEADERS_DIR}/Engine.h
    ${GRAPHIC_DIR}/IGui.hpp
    ${GRAPHIC_MSFML_DIR}/AnimatedSprite.hpp
    ${GRAPHIC_MSFML_DIR}/Animation.hpp
    ${GRAPHIC_MSFML_DIR}/TextureManager.hpp
    ${GRAPHIC_MSFML_DIR}/Timer.hpp
    ${GRAPHIC_MSFML_DIR}/mSFML.hpp
    ${AUDIO_DIR}/IAudio.hpp
    ${AUDIO_MSFML_DIR}/Audio.hpp
)

include_directories(
  ${HEADERS_DIR}
  ${GRAPHIC_DIR}
  ${AUDIO_DIR}
  ${GRAPHIC_MSFML_DIR}
  ${AUDIO_MSFML_DIR}
)

add_executable (
    Arcade
    ${SOURCES}
    ${HEADERS}
)

if (UNIX)
target_link_libraries(
    Arcade
    ${CMAKE_SOURCE_DIR}/libraries/unix/SDL/libSDL-1.2.so
)
endif (UNIX)
if (WIN32)
target_link_libraries(
    Arcade
    ${CMAKE_SOURCE_DIR}/libraries/windows/SFML/sfml-audio-d.lib
    ${CMAKE_SOURCE_DIR}/libraries/windows/SFML/sfml-graphics-d.lib
    ${CMAKE_SOURCE_DIR}/libraries/windows/SFML/sfml-network-d.lib
    ${CMAKE_SOURCE_DIR}/libraries/windows/SFML/sfml-system-d.lib
    ${CMAKE_SOURCE_DIR}/libraries/windows/SFML/sfml-window-d.lib
)
endif (WIN32)
