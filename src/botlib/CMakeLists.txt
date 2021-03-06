cmake_minimum_required(VERSION 3.10)
project(botlib C)

if(WIN32)
    add_definitions(-DWIN32 -DBOTLIB -D_LIB -D_CRT_SECURE_NO_WARNINGS)
else()
    add_definitions(-DBOTLIB)
endif()

set(BOTLIB_HEADERS
    aasfile.h
    be_aas.h
    be_aas_bsp.h
    be_aas_cluster.h
    be_aas_debug.h
    be_aas_def.h
    be_aas_entity.h
    be_aas_file.h
    be_aas_funcs.h
    be_aas_main.h
    be_aas_move.h
    be_aas_optimize.h
    be_aas_reach.h
    be_aas_route.h
    be_aas_routealt.h
    be_aas_routetable.h
    be_aas_sample.h
    ../game/be_ai_char.h
    ../game/be_ai_chat.h
    ../game/be_ai_gen.h
    ../game/be_ai_goal.h
    ../game/be_ai_move.h
    ../game/be_ai_weap.h
    ../game/be_ea.h
    be_ai_weight.h
    be_interface.h
    botlib.h
    l_crc.h
    l_libvar.h
    l_log.h
    l_memory.h
    l_precomp.h
    l_script.h
    l_struct.h
    l_utils.h
    ../game/q_shared.h
    ../game/surfaceflags.h
    )

set(BOTLIB_SOURCES
    be_aas_bspq3.c
    be_aas_cluster.c
    be_aas_debug.c
    be_aas_entity.c
    be_aas_file.c
    be_aas_main.c
    be_aas_move.c
    be_aas_optimize.c
    be_aas_reach.c
    be_aas_route.c
    be_aas_routealt.c
    be_aas_routetable.c
    be_aas_sample.c
    be_ai_char.c
    be_ai_chat.c
    be_ai_gen.c
    be_ai_goal.c
    be_ai_move.c
    be_ai_weap.c
    be_ai_weight.c
    be_ea.c
    be_interface.c
    l_crc.c
    l_libvar.c
    l_log.c
    l_memory.c
    l_precomp.c
    l_script.c
    l_struct.c
    )

add_library(botlib STATIC ${BOTLIB_SOURCES} ${BOTLIB_HEADERS})
