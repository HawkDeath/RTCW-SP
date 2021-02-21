cmake_minimum_required(VERSION 3.10)
project(cgame C)

if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -DCGAMEDLL -D_CRT_SECURE_NO_WARNINGS)
else()
    add_definitions(-DCGAMEDLL)
endif()

set(CGAME_HEADERS
    ../game/bg_local.h
    ../game/bg_public.h
    cg_local.h
    cg_public.h
    ../ui/keycodes.h
    ../../main/ui/menudef.h # TODO use cmake valuables
    ../game/q_shared.h
    ../game/surfaceflags.h
    tr_types.h
    ../ui/ui_shared.h
    )

set(CGAME_SOURCES
    ../game/bg_animation.c
    ../game/bg_misc.c
    ../game/bg_pmove.c
    ../game/bg_slidemove.c
    cg_consolecmds.c
    cg_draw.c
    cg_drawtools.c
    cg_effects.c
    cg_ents.c
    cg_event.c
    cg_flamethrower.c
    cg_info.c
    cg_localents.c
    cg_main.c
    cg_marks.c
    cg_newDraw.c
    cg_particles.c
    cg_players.c
    cg_playerstate.c
    cg_predict.c
    cg_scoreboard.c
    cg_servercmds.c
    cg_snapshot.c
    cg_sound.c
    cg_syscalls.c
    cg_trails.c
    cg_view.c
    cg_weapons.c
    ../game/q_math.c
    ../game/q_shared.c
    ../ui/ui_shared.c
    #../game/bg_lib.c
    )

add_library(cgamex86 SHARED cgame.def ${CGAME_SOURCES} ${CGAME_HEADERS})
