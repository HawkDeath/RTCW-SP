cmake_minimum_required(VERSION 3.10)
project(splines C)

if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS)
endif()

set(SPLINES_HEADERS
    math_angles.h
    math_matrix.h
    math_quaternion.h
    math_vector.h
    ../game/q_shared.h
    q_splineshared.h
    splines.h
    util_list.h
    util_str.h
    )
set(SPLINES_SOURCES
    math_angles.cpp
    math_matrix.cpp
    math_quaternion.cpp
    math_vector.cpp
    q_parse.cpp
    q_shared.cpp
    splines.cpp
    util_str.cpp)

add_library(Splines STATIC ${SPLINES_SOURCES} ${SPLINES_HEADERS})
