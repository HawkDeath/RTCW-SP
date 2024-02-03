cmake_minimum_required(VERSION 3.21)
project(wolf)

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output")
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin")
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output/lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/lib")

option(WOLFSP_USE_RENDERER_VULKAN "Build a Vulkan renderer" ON)

if (WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -DBOTLIB -D_LIB -D_CRT_SECURE_NO_WARNINGS -D__i386__ -D_M_IX86)
    if (MSVC)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /INCREMENTAL:NO")
    endif()
else()
    add_definitions(-DBOTLIB -D_LIB -D_CRT_SECURE_NO_WARNINGS -D_M_IX86)
endif()

add_subdirectory(src/botlib)
add_subdirectory(src/cgame)
add_subdirectory(src/game)

if(WOLFSP_USE_RENDERER_VULKAN)
    find_package(Vulkan REQUIRED)
    add_subdirectory(src/renderer_vk)
else()
    add_subdirectory(src/renderer_gl)
endif(WOLFSP_USE_RENDERER_VULKAN)

add_subdirectory(src/splines)
add_subdirectory(src/ui)

add_subdirectory(src/win32)

if(WOLFSP_USE_RENDERER_VULKAN)
    add_dependencies(WolfSP botlib Renderer_VK Splines)
else()
    add_dependencies(WolfSP botlib Renderer_GL Splines)
endif(WOLFSP_USE_RENDERER_VULKAN)