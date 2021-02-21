cmake_minimum_required(VERSION 3.10)
project(win32 C)

if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS) # -DBUILD_FREETYPE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /INCREMENTAL:NO" )
endif()

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(WOLFSP_HEADERS
    ../game/bg_public.h
    ../botai/botai.h
    ../game/botlib.h
    ../cgame/cg_public.h
    ../client/client.h
    ../qcommon/cm_local.h
    ../qcommon/cm_patch.h
    ../qcommon/cm_polylib.h
    ../qcommon/cm_public.h
    ../game/g_public.h
    ../ui/keycodes.h
    ../client/keys.h
    ../game/q_shared.h
    ../qcommon/qcommon.h
    ../qcommon/qfiles.h
    ../renderer_gl/qgl.h
    ../server/server.h
    ../client/snd_local.h
    ../client/snd_public.h
    ../game/surfaceflags.h
    ../renderer_gl/tr_local.h
    ../renderer_gl/tr_public.h
    ../cgame/tr_types.h
    ../ui/ui_public.h
    ../qcommon/unzip.h
    ../qcommon/vm_local.h
    win_local.h
    )

set(WOLFSP_SOURCES
    ../client/cl_cgame.c
    ../client/cl_cin.c
    ../client/cl_console.c
    ../client/cl_input.c
    ../client/cl_keys.c
    ../client/cl_main.c
    ../client/cl_net_chan.c
    ../client/cl_parse.c
    ../client/cl_scrn.c
    ../client/cl_ui.c
    ../qcommon/cm_load.c
    ../qcommon/cm_patch.c
    ../qcommon/cm_polylib.c
    ../qcommon/cm_test.c
    ../qcommon/cm_trace.c
    ../qcommon/cmd.c
    ../qcommon/common.c
    ../qcommon/cvar.c
    ../qcommon/files.c
    ../qcommon/huffman.c
    ../qcommon/md4.c
    ../qcommon/msg.c
    ../qcommon/net_chan.c
    ../game/q_math.c
    ../game/q_shared.c
    ../client/snd_adpcm.c
    ../client/snd_dma.c
    ../client/snd_mem.c
    ../client/snd_mix.c
    ../client/snd_wavelet.c
    ../server/sv_bot.c
    ../server/sv_ccmds.c
    ../server/sv_client.c
    ../server/sv_game.c
    ../server/sv_init.c
    ../server/sv_main.c
    ../server/sv_net_chan.c
    ../server/sv_snapshot.c
    ../server/sv_world.c
    ../qcommon/unzip.c
    ../qcommon/vm.c
    ../qcommon/vm_interpreted.c
    ../qcommon/vm_x86.c
    win_input.c
    win_main.c
    win_net.c
    win_shared.c
    win_snd.c
    win_syscon.c
    win_wndproc.c
    )

set(WOLFSP_RESOURCES
    winquake.rc
    qe3.ico
    )

add_executable(WolfSP ${WOLFSP_RESOURCES} ${WOLFSP_SOURCES} ${WOLFSP_HEADERS})
set_property(TARGET WolfSP PROPERTY WIN32_EXECUTABLE TRUE)
target_link_libraries(WolfSP PRIVATE Splines botlib uix86 Renderer_GL
    winmm wsock32 kernel32 user32 gdi32 winspool comdlg32 advapi32 shell32 ole32 oleaut32 uuid odbc32 odbccp32)
