cmake_minimum_required(VERSION 3.16...3.21)
project(renderer_vk C CXX)

if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS)
endif()

set(JPEG_SOURCES
    ../jpeg-6/jcapimin.c
    ../jpeg-6/jccoefct.c
    ../jpeg-6/jccolor.c
    ../jpeg-6/jcdctmgr.c
    ../jpeg-6/jchuff.c
    ../jpeg-6/jcinit.c
    ../jpeg-6/jcmainct.c
    ../jpeg-6/jcmarker.c
    ../jpeg-6/jcmaster.c
    ../jpeg-6/jcomapi.c
    ../jpeg-6/jcparam.c
    ../jpeg-6/jcphuff.c
    ../jpeg-6/jcprepct.c
    ../jpeg-6/jcsample.c
    ../jpeg-6/jctrans.c
    ../jpeg-6/jdapimin.c
    ../jpeg-6/jdapistd.c
    ../jpeg-6/jdatadst.c
    ../jpeg-6/jdatasrc.c
    ../jpeg-6/jdcoefct.c
    ../jpeg-6/jdcolor.c
    ../jpeg-6/jddctmgr.c
    ../jpeg-6/jdhuff.c
    ../jpeg-6/jdinput.c
    ../jpeg-6/jdmainct.c
    ../jpeg-6/jdmarker.c
    ../jpeg-6/jdmaster.c
    ../jpeg-6/jdpostct.c
    ../jpeg-6/jdsample.c
    ../jpeg-6/jdtrans.c
    ../jpeg-6/jerror.c
    ../jpeg-6/jfdctflt.c
    ../jpeg-6/jidctflt.c
    ../jpeg-6/jmemmgr.c
    ../jpeg-6/jmemnobs.c
    ../jpeg-6/jutils.c
    )

set(RENDERER_VK_HEADERS 
    ../qcommon/cm_public.h
    ../qcommon/qcommon.h
    ../qcommon/qfiles.h
    ../jpeg-6/jchuff.h
    ../game/q_shared.h
    ../game/surfaceflags.h
    ../cgame/tr_types.h
    ../win32/glw_win.h
    ../win32/resource.h
    ../win32/win_local.h
    anorms256.h
    vk_local.h
    vk_public.h
    )
#set(RENDERER_VK_HEADERS 
#                    ../game/q_shared.h
#                    ../qcommon/qcommon.h
#                    ../cgame/tr_types.h
#                    ../qcommon/qfiles.h
#                    vk_local.h 
#                    tr_public.h)

set(RENDERER_VK_SOURCES
    ${JPEG_SOURCES}
    vk_animation.c
    vk_backend.c
    vk_bsp.c
    vk_cmds.c
    vk_cmesh.c
    vk_curve.c
    vk_flares.c
    vk_font.c
    vk_image.c
    vk_init.c
    vk_light.c
    vk_main.c
    vk_marks.c
    vk_mesh.c
    vk_model.c
    vk_noise.c
    vk_scene.c
    vk_shade.c
    vk_shade_calc.c
    vk_shader.c
    vk_shadows.c
    vk_sky.c
    vk_surface.c
    vk_world.c
    ../win32/win_gamma.c
    ../win32/win_glimp.c)

add_library(Renderer_VK STATIC ref_trin.def ${RENDERER_VK_SOURCES} ${RENDERER_VK_HEADERS})
target_link_libraries(Renderer_VK INTERFACE ${Vulkan_LIBRARY})