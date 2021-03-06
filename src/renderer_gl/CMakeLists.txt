cmake_minimum_required(VERSION 3.10)
project(renderer_gl C)

if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS) # -DBUILD_FREETYPE)
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

set(RENDERER_GL_HEADERS
    anorms256.h
    ../qcommon/cm_public.h
    ../win32/glw_win.h
    ../jpeg-6/jchuff.h
    ../game/q_shared.h
    ../qcommon/qcommon.h
    ../qcommon/qfiles.h
    qgl.h
    ../win32/resource.h
    ../game/surfaceflags.h
    tr_local.h
    tr_public.h
    ../cgame/tr_types.h
    ../win32/win_local.h
    )

set(RENDERER_GL_SOURCES
    ${JPEG_SOURCES}
    tr_animation.c
    tr_backend.c
    tr_bsp.c
    tr_cmds.c
    tr_cmesh.c
    tr_curve.c
    tr_flares.c
    tr_font.c
    tr_image.c
    tr_init.c
    tr_light.c
    tr_main.c
    tr_marks.c
    tr_mesh.c
    tr_model.c
    tr_noise.c
    tr_scene.c
    tr_shade.c
    tr_shade_calc.c
    tr_shader.c
    tr_shadows.c
    tr_sky.c
    tr_surface.c
    tr_world.c
    ../win32/win_gamma.c
    ../win32/win_glimp.c
    ../win32/win_qgl.c
    )

add_library(Renderer_GL STATIC ref_trin.def ${RENDERER_GL_SOURCES} ${RENDERER_GL_HEADERS})
