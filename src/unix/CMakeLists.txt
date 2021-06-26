cmake_minimum_required(VERSION 3.10)
project(linux CXX C)

add_definitions(-D__LCC__)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(WOLFSP_UNIX_HEADERS
    ../qcommon/qcommon.h
    linux_local.h
    qasm.h

    )

set(WOLFSP_UNIX_SOURCES
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
    linux_common.c
    linux_joystick.c
    ftol.nasm
    snapvector.nasm
    sys_dosa.s
    unix_main.c
    unix_shared.c
    unix_net.c
    linux_snd.c)

add_executable(WolfSP quake3.xpm ${WOLFSP_UNIX_SOURCES} ${WOLFSP_UNIX_HEADERS})
target_link_libraries(WolfSP PRIVATE Splines botlib uix86 Renderer_GL dl X11 Xxf86dga)
set_target_properties(WolfSP PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

