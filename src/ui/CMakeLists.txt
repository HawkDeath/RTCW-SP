cmake_minimum_required(VERSION 3.10)
project(ui C)

if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS)
endif()

set(UI_HEADERS
    ../game/bg_public.h
    keycodes.h
    ../../main/ui/menudef.h
    ../game/q_shared.h
    ../game/surfaceflags.h
    ../cgame/tr_types.h
    ui_local.h
    ui_public.h
    ui_shared.h
    )
set(UI_SOURCES
    #../game/bg_lib.c
    ../game/bg_misc.c
    ../game/q_math.c
    ../game/q_shared.c
    ui_atoms.c
    ui_gameinfo.c
    ui_main.c
    ui_players.c
    ui_shared.c
    ui_syscalls.c
    ui_util.c
    )

add_library(uix86 SHARED ui.def ${UI_SOURCES} ${UI_HEADERS})
