cmake_minimum_required(VERSION 3.10)
project(linux C)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(WolfSP linux_snd.c)
target_link_libraries(WolfSP PRIVATE Splines botlib uix86 Renderer_GL)
