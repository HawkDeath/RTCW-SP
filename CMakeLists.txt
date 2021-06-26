cmake_minimum_required(VERSION 3.10)
project(wolf)

add_definitions(-D_M_IX86)

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output")
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin")
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output/lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/lib")

#find_package()

add_subdirectory(src/botlib)
add_subdirectory(src/cgame)
add_subdirectory(src/game)

add_subdirectory(src/renderer_gl)

add_subdirectory(src/splines)
add_subdirectory(src/ui)
if (WIN32)
    add_subdirectory(src/win32)
else()
    add_subdirectory(src/unix)
endif()

add_dependencies(WolfSP botlib Renderer_GL Splines)
