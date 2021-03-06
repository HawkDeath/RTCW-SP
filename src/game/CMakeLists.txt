cmake_minimum_required(VERSION 3.10)
project(game C)

if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -DGAMEDLL -D_CRT_SECURE_NO_WARNINGS)
else()
    add_definitions(-DGAMEDLL)
endif()

set(CGAME_HEADERS
    ai_cast.h
    ai_cast_fight.h
    ai_cast_global.h
    ../botai/ai_chat.h
    ../botai/ai_cmd.h
    ../botai/ai_dmnet.h
    ../botai/ai_dmq3.h
    ../botai/ai_main.h
    ../botai/ai_team.h
    be_aas.h
    be_ai_char.h
    be_ai_chat.h
    be_ai_gen.h
    be_ai_goal.h
    be_ai_move.h
    be_ai_weap.h
    be_ea.h
    bg_local.h
    bg_public.h
    ../botai/botai.h
    botlib.h
    ../botai/chars.h
    g_local.h
    g_public.h
    g_team.h
    ../botai/inv.h
    ../botai/match.h
    q_shared.h
    surfaceflags.h
    ../botai/syn.h
    )

set(CGAME_SOURCES
    ai_cast.c
    ai_cast_characters.c
    ai_cast_debug.c
    ai_cast_events.c
    ai_cast_fight.c
    ai_cast_func_attack.c
    ai_cast_func_boss1.c
    ai_cast_funcs.c
    ai_cast_script.c
    ai_cast_script_actions.c
    ai_cast_script_ents.c
    ai_cast_sight.c
    ai_cast_think.c
    ../botai/ai_chat.c
    ../botai/ai_cmd.c
    ../botai/ai_dmnet.c
    ../botai/ai_dmq3.c
    ../botai/ai_main.c
    ../botai/ai_team.c
    bg_animation.c
    # bg_lib.c
    bg_misc.c
    bg_pmove.c
    bg_slidemove.c
    g_active.c
    g_alarm.c
    g_bot.c
    g_client.c
    g_cmds.c
    g_combat.c
    g_items.c
    g_main.c
    g_mem.c
    g_misc.c
    g_missile.c
    g_mover.c
    g_props.c
    g_save.c
    g_script.c
    g_script_actions.c
    g_session.c
    g_spawn.c
    g_svcmds.c
    g_syscalls.c
    g_target.c
    g_team.c
    g_tramcar.c
    g_trigger.c
    g_utils.c
    g_weapon.c
    q_math.c
    q_shared.c
    )

add_library(qagamex86 SHARED game.def ${CGAME_SOURCES} ${CGAME_HEADERS})
