cmake_minimum_required(VERSION 3.10)
project(renderer_gl C)

if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS) # -DBUILD_FREETYPE)
endif()

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
