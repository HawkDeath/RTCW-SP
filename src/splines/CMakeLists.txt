cmake_minimum_required(VERSION 3.21)
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
    util_list.h
    util_str.h
    )
    
if (WOLFSP_USE_RENDERER_VULKAN)
    set(SPLINES_SOURCES_DEPS_TMP
        vk_splines.cpp
        vk_splines.h)
else()
  set(SPLINES_SOURCES_DEPS_TMP
          splines.cpp
          splines.h)
endif(WOLFSP_USE_RENDERER_VULKAN)


set(SPLINES_SOURCES
    math_angles.cpp
    math_matrix.cpp
    math_quaternion.cpp
    math_vector.cpp
    q_parse.cpp
    q_shared.cpp
    util_str.cpp
    ${SPLINES_SOURCES_DEPS_TMP})


add_library(Splines STATIC ${SPLINES_SOURCES} ${SPLINES_HEADERS})
set_target_properties(Splines PROPERTIES COMPILE_FLAGS " " LINK_FLAGS " ")

