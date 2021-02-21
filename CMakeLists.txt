cmake_minimum_required(VERSION 3.10)
project(wolf)

add_subdirectory(src/botlib)
add_subdirectory(src/cgame)
add_subdirectory(src/game)

add_subdirectory(src/renderer_gl)

add_subdirectory(src/splines)
add_subdirectory(src/ui)
