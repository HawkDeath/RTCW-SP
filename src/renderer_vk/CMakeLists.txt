cmake_minimum_required(VERSION 3.10)
project(renderer_vk C CXX)

if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS)
endif()

add_definitions(-DVK_NO_PROTOTYPES)

set(RENDERER_VK_HEADERS 
                    ../game/q_shared.h
                    ../qcommon/qcommon.h
                    ../cgame/tr_types.h
                    ../qcommon/qfiles.h
                    vk_local.h 
                    tr_public.h)

set(RENDERER_VK_SOURCES vk_init.c)

add_library(Renderer_VK STATIC ref_trin.def ${RENDERER_VK_SOURCES} ${RENDERER_VK_HEADERS})
target_link_libraries(Renderer_VK INTERFACE volk)