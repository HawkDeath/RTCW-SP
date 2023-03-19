#include "../renderer_vk/vk_local.h"
#include "resource.h"
#include "glw_win.h"
#include "win_local.h"

#include <Windows.h>

#include <stdio.h>

static qboolean s_classRegistered = qfalse;
#define WINDOW_CLASS_NAME "Wolfenstein"
//
// variable declarations
//
glwstate_t glw_state;

/*
** GLW_CreateWindow
**
** Responsible for creating the Win32 window and initializing the OpenGL driver.
*/
#define WINDOW_STYLE (WS_OVERLAPPED | WS_BORDER | WS_CAPTION | WS_VISIBLE)
static qboolean GLW_CreateWindow(int width, int height,
                                 int colorbits, qboolean cdsFullscreen) {
  RECT r;
  cvar_t *vid_xpos, *vid_ypos;
  int stylebits;
  int x, y, w, h;
  int exstyle;

  //
  // register the window class if necessary
  //
  if (!s_classRegistered) {
    WNDCLASS wc;

    memset(&wc, 0, sizeof(wc));

    wc.style = 0;
    wc.lpfnWndProc = (WNDPROC)glw_state.wndproc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = g_wv.hInstance;
    wc.hIcon = LoadIcon(g_wv.hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (void *)COLOR_GRAYTEXT;
    wc.lpszMenuName = 0;
    wc.lpszClassName = WINDOW_CLASS_NAME;

    if (!RegisterClass(&wc)) {
      ri.Error(ERR_FATAL, "GLW_CreateWindow: could not register window class");
    }
    s_classRegistered = qtrue;
    ri.Printf(PRINT_ALL, "...registered window class\n");
  }

  //
  // create the HWND if one does not already exist
  //
  if (!g_wv.hWnd) {
    //
    // compute width and height
    //
    r.left = 0;
    r.top = 0;
    r.right = width;
    r.bottom = height;

    if (cdsFullscreen) {
      exstyle = WS_EX_TOPMOST;
      stylebits = WS_POPUP | WS_VISIBLE | WS_SYSMENU;
    } else {
      exstyle = 0;
      stylebits = WINDOW_STYLE | WS_SYSMENU;
      AdjustWindowRect(&r, stylebits, FALSE);
    }

    w = r.right - r.left;
    h = r.bottom - r.top;

    if (cdsFullscreen) {
      x = 0;
      y = 0;
    } else {
      vid_xpos = ri.Cvar_Get("vid_xpos", "", 0);
      vid_ypos = ri.Cvar_Get("vid_ypos", "", 0);
      x = vid_xpos->integer;
      y = vid_ypos->integer;

      // adjust window coordinates if necessary
      // so that the window is completely on screen
      if (x < 0) {
        x = 0;
      }
      if (y < 0) {
        y = 0;
      }

      if (w < glw_state.desktopWidth && h < glw_state.desktopHeight) {
        if (x + w > glw_state.desktopWidth) {
          x = (glw_state.desktopWidth - w);
        }
        if (y + h > glw_state.desktopHeight) {
          y = (glw_state.desktopHeight - h);
        }
      }
    }

    g_wv.hWnd =
        CreateWindowExA(exstyle, WINDOW_CLASS_NAME, "Wolfenstein", stylebits, x,
                       y, w, h, NULL, NULL, g_wv.hInstance, NULL);

    if (!g_wv.hWnd) {
      ri.Error(ERR_FATAL, "GLW_CreateWindow() - Couldn't create window");
    }

    ShowWindow(g_wv.hWnd, SW_SHOW);
    UpdateWindow(g_wv.hWnd);
    ri.Printf(PRINT_ALL, "...created window@%d,%d (%dx%d)\n", x, y, w, h);
  } else {
    ri.Printf(PRINT_ALL, "...window already present, CreateWindowEx skipped\n");
  }


  SetForegroundWindow(g_wv.hWnd);
  SetFocus(g_wv.hWnd);

  return qtrue;
}

void OS_CreateWindow()
{
  cvar_t *cv;
  // save off hInstance and wndproc
  cv = ri.Cvar_Get("win_hinstance", "", 0);
  sscanf(cv->string, "%i", (int *)&g_wv.hInstance);

  cv = ri.Cvar_Get("win_wndproc", "", 0);
  sscanf(cv->string, "%i", (int *)&glw_state.wndproc);
  renderConfig.isFullscreen = qfalse;
  renderConfig.vidWidth = 1280;
  renderConfig.vidHeight = 720;
  GLW_CreateWindow(renderConfig.vidWidth, renderConfig.vidHeight, 24,
                   renderConfig.isFullscreen);
}