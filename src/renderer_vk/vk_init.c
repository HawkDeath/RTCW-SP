// tr_init.c -- functions that are not called every frame

#include "vk_local.h"

// temporary solution; only for windows
#ifdef WIN32 || WIN64
#define VK_USE_PLATFORM_WIN32_KHR
#include "../win32/win_local.h"
#include <Windows.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_win32.h>
#endif // WIN32 || WIN64

#include <stdio.h>
// #ifdef __USEA3D
//// Defined in snd_a3dg_refcommon.c
// void RE_A3D_RenderGeometry (void *pVoidA3D, void *pVoidGeom, void *pVoidMat,
// void *pVoidGeomStatus); #endif

#define COUNT_OF(x)                                                            \
  ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

renderconfig_t renderConfig;
vkContext vkConfig;
glstate_t glState;

static void VkInfo_f(void);

cvar_t *r_flareSize;
cvar_t *r_flareFade;

cvar_t *r_railWidth;
cvar_t *r_railCoreWidth;
cvar_t *r_railSegmentLength;

cvar_t *r_ignoreFastPath;

cvar_t *r_verbose;
cvar_t *r_ignore;

cvar_t *r_displayRefresh;

cvar_t *r_detailTextures;

cvar_t *r_znear;
cvar_t *r_zfar;

cvar_t *r_smp;
cvar_t *r_showSmp;
cvar_t *r_skipBackEnd;

cvar_t *r_ignorehwgamma;
cvar_t *r_measureOverdraw;

cvar_t *r_inGameVideo;
cvar_t *r_fastsky;
cvar_t *r_drawSun;
cvar_t *r_dynamiclight;
cvar_t *r_dlightBacks;
cvar_t *r_dlightScale; //----(SA)	added

cvar_t *r_waterFogColor; //----(SA)	added
cvar_t *r_mapFogColor;
cvar_t *r_savegameFogColor; //----(SA)	added

cvar_t *r_lodbias;
cvar_t *r_lodscale;

cvar_t *r_norefresh;
cvar_t *r_drawentities;
cvar_t *r_drawworld;
cvar_t *r_speeds;
cvar_t *r_fullbright;
cvar_t *r_novis;
cvar_t *r_nocull;
cvar_t *r_facePlaneCull;
cvar_t *r_showcluster;
cvar_t *r_nocurves;

cvar_t *r_allowExtensions;

cvar_t *r_ext_compressed_textures;
cvar_t *r_ext_gamma_control;
cvar_t *r_ext_multitexture;
cvar_t *r_ext_compiled_vertex_array;
cvar_t *r_ext_texture_env_add;

//----(SA)	added
cvar_t *r_ext_texture_filter_anisotropic;

cvar_t *r_ext_NV_fog_dist;
cvar_t *r_nv_fogdist_mode;

cvar_t *r_ext_ATI_pntriangles;
cvar_t *r_ati_truform_tess;       //
cvar_t *r_ati_truform_normalmode; // linear/quadratic
cvar_t *r_ati_truform_pointmode;  // linear/cubic
//----(SA)	end

cvar_t *r_ati_fsaa_samples; // DAJ valids are 1, 2, 4

cvar_t *r_logFile;

cvar_t *r_stencilbits;
cvar_t *r_depthbits;
cvar_t *r_colorbits;
cvar_t *r_stereo;
cvar_t *r_primitives;
cvar_t *r_texturebits;

cvar_t *r_drawBuffer;
cvar_t *r_vkDriver;
cvar_t *r_glIgnoreWicked3D;
cvar_t *r_lightmap;
cvar_t *r_vertexLight;
cvar_t *r_uiFullScreen;
cvar_t *r_shadows;
cvar_t *r_portalsky; //----(SA)	added
cvar_t *r_flares;
cvar_t *r_mode;
cvar_t *r_nobind;
cvar_t *r_singleShader;
cvar_t *r_roundImagesDown;
cvar_t *r_lowMemTextureSize;
cvar_t *r_lowMemTextureThreshold;
cvar_t *r_colorMipLevels;
cvar_t *r_picmip;
cvar_t *r_picmip2;
cvar_t *r_showtris;
cvar_t *r_showsky;
cvar_t *r_shownormals;
cvar_t *r_finish;
cvar_t *r_clear;
cvar_t *r_swapInterval;
cvar_t *r_textureMode;
cvar_t *r_offsetFactor;
cvar_t *r_offsetUnits;
cvar_t *r_gamma;
cvar_t *r_intensity;
cvar_t *r_lockpvs;
cvar_t *r_noportals;
cvar_t *r_portalOnly;

cvar_t *r_subdivisions;
cvar_t *r_lodCurveError;

cvar_t *r_fullscreen;

cvar_t *r_customwidth;
cvar_t *r_customheight;
cvar_t *r_customaspect;

cvar_t *r_overBrightBits;
cvar_t *r_mapOverBrightBits;

cvar_t *r_debugSurface;
cvar_t *r_simpleMipMaps;

cvar_t *r_showImages;

cvar_t *r_ambientScale;
cvar_t *r_directedScale;
cvar_t *r_debugLight;
cvar_t *r_debugSort;
cvar_t *r_printShaders;
cvar_t *r_saveFontData;

// Ridah
cvar_t *r_cache;
cvar_t *r_cacheShaders;
cvar_t *r_cacheModels;
cvar_t *r_compressModels;
cvar_t *r_exportCompressedModels;

cvar_t *r_cacheGathering;

cvar_t *r_buildScript;

cvar_t *r_bonesDebug;
// done.

// Rafael - wolf fog
cvar_t *r_wolffog;
// done

cvar_t *r_highQualityVideo;
cvar_t *r_rmse;

cvar_t *r_maxpolys;
int max_polys;
cvar_t *r_maxpolyverts;
int max_polyverts;

static void AssertCvarRange(cvar_t *cv, float minVal, float maxVal,
                            qboolean shouldBeIntegral) {
  if (shouldBeIntegral) {
    if ((int)cv->value != cv->integer) {
      ri.Printf(PRINT_WARNING, "WARNING: cvar '%s' must be integral (%f)\n",
                cv->name, cv->value);
      ri.Cvar_Set(cv->name, va("%d", cv->integer));
    }
  }

  if (cv->value < minVal) {
    ri.Printf(PRINT_WARNING, "WARNING: cvar '%s' out of range (%f < %f)\n",
              cv->name, cv->value, minVal);
    ri.Cvar_Set(cv->name, va("%f", minVal));
  } else if (cv->value > maxVal) {
    ri.Printf(PRINT_WARNING, "WARNING: cvar '%s' out of range (%f > %f)\n",
              cv->name, cv->value, maxVal);
    ri.Cvar_Set(cv->name, va("%f", maxVal));
  }
}

/*
** InitVulkan
**
** This function is responsible for initializing a valid Vulkan subsystem.
*/
static void InitVulkan(void) {
  char renderer_buffer[1024];

  //
  // initialize OS specific portions of the renderer
  //
  // GLimp_Init directly or indirectly references the following cvars:
  //		- r_fullscreen
  //		- r_vkDriver
  //		- r_mode
  //		- r_(color|depth|stencil)bits
  //		- r_ignorehwgamma
  //		- r_gamma
  //
  memset(&vkConfig, 0, sizeof(vkConfig));
  vkConfig.renderConfig = &renderConfig;
  VK_CreateInstance();
  VK_CreateSurface();
  VK_PickPhysicalDevice();
  VK_CreateDevice();
  VK_CreateSwapChain();
  VK_CreateRenderPass();
  // print info
  VkInfo_f();
}

// Vulkan stuff init
void VK_CreateInstance() {
  VkApplicationInfo appInfo;
  memset(&appInfo, 0, sizeof(VkApplicationInfo));
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pNext = VK_NULL_HANDLE;
  appInfo.apiVersion = VK_API_VERSION_1_1;
  appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 2);
  appInfo.pApplicationName = "Wolfenstein";
  appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
  appInfo.pEngineName = "Wolfenstein_vk_idtech3_custom";

  char *extensions[2];
  extensions[0] = "VK_KHR_surface";
#ifdef WIN32 || WIN64
  extensions[1] = "VK_KHR_win32_surface";
#endif

  VkInstanceCreateInfo createInfo;
  memset(&createInfo, 0, sizeof(createInfo));
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pNext = VK_NULL_HANDLE;
  createInfo.flags = (VkInstanceCreateFlags)0u;
  createInfo.pApplicationInfo = &appInfo;
  createInfo.enabledLayerCount = 0u;
  createInfo.ppEnabledLayerNames = VK_NULL_HANDLE;
  createInfo.enabledExtensionCount = 2u;
  createInfo.ppEnabledExtensionNames = extensions;

  VK_CHECK(vkCreateInstance(&createInfo, NULL, &vkConfig.instance),
           "Failed to create intance");
}

void VK_PickPhysicalDevice() {
  uint32_t deviceCount = 0;
  vkEnumeratePhysicalDevices(vkConfig.instance, &deviceCount, NULL);
  if (deviceCount == 0) {
    ri.Printf(PRINT_ERROR, "No availalble GPU supported Vulkan");
    exit(0);
  } else {
    ri.Printf(PRINT_ALL, "Available Vulkan devices %d\n", deviceCount);
  }
  VkPhysicalDevice *availableDevices =
      (VkPhysicalDevice *)malloc(deviceCount * sizeof(VkPhysicalDevice));
  vkEnumeratePhysicalDevices(vkConfig.instance, &deviceCount, availableDevices);

  vkConfig.physicalDevice = *availableDevices; // get first available as default

  for (int i = 0; i < deviceCount; ++i) {
    VkPhysicalDevice *device =
        availableDevices + (sizeof(VkPhysicalDevice) *
                            i); // addres of next physical device if available
    VkPhysicalDeviceProperties props;
    vkGetPhysicalDeviceProperties(*device, &props);
    if (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
      vkConfig.physicalDevice = *device;
      break;
    }
  }

  if (vkConfig.physicalDevice == VK_NULL_HANDLE) {
    ri.Printf(PRINT_ERROR, "Cannot find the suitable physical device");
    exit(0);
  }
  free(availableDevices);

  vkGetPhysicalDeviceProperties(vkConfig.physicalDevice,
                                &vkConfig.gpuProperties);

  ri.Printf(PRINT_ALL, "Choosen the %s\n", vkConfig.gpuProperties.deviceName);
  printf("Choosen the %s\n", vkConfig.gpuProperties.deviceName);
}

void VK_CreateSurface() {
#ifdef WIN32 || WIN64
  VkWin32SurfaceCreateInfoKHR winSurface;
  memset(&winSurface, 0, sizeof(VkWin32SurfaceCreateInfoKHR));
  winSurface.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
  winSurface.hwnd = g_wv.hWnd;
  winSurface.hinstance = g_wv.hInstance;
  VK_CHECK(vkCreateWin32SurfaceKHR(vkConfig.instance, &winSurface,
                                   VK_NULL_HANDLE, &vkConfig.surface),
           "Failed to create Win32 surface");

#endif // WIN32 || WIN64
}

void VK_CreateDevice() {
  uint32_t queueFamiliesCount = 0;
  vkGetPhysicalDeviceQueueFamilyProperties(vkConfig.physicalDevice,
                                           &queueFamiliesCount, NULL);
  VkQueueFamilyProperties *queueFamilies = (VkQueueFamilyProperties *)calloc(
      queueFamiliesCount, sizeof(VkQueueFamilyProperties));
  memset(queueFamilies, 0,
         queueFamiliesCount * sizeof(VkQueueFamilyProperties));
  vkGetPhysicalDeviceQueueFamilyProperties(vkConfig.physicalDevice,
                                           &queueFamiliesCount, queueFamilies);

  for (uint32_t i = 0; i < queueFamiliesCount;) {
    VkQueueFamilyProperties *familyQueue =
        queueFamilies + (sizeof(VkQueueFamilyProperties) * i);

    if (familyQueue->queueFlags & VK_QUEUE_GRAPHICS_BIT) {
      vkConfig.graphicsQueueFamily = i;
      vkConfig.hasGraphicsQueueFamily = qtrue;
    }

    VkBool32 presentSupported = VK_FALSE;
    vkGetPhysicalDeviceSurfaceSupportKHR(vkConfig.physicalDevice, i,
                                         vkConfig.surface, &presentSupported);

    if (presentSupported) {
      vkConfig.presentQueueFamily = i;
      vkConfig.hasPresentQueueFamily = qtrue;
    }

    if (vkConfig.hasGraphicsQueueFamily && vkConfig.hasPresentQueueFamily) {
      break;
    }
    ++i;
  }

  float queuePriority = 1.0f;

  VkDeviceQueueCreateInfo *queuesInfos =
      (VkDeviceQueueCreateInfo *)calloc(2u, sizeof(VkDeviceQueueCreateInfo));
  VkDeviceQueueCreateInfo *qi = queuesInfos;
  assert(qi);
  qi->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  qi->pNext = VK_NULL_HANDLE;
  qi->flags = (VkDeviceQueueCreateFlags)0U;
  qi->queueFamilyIndex = vkConfig.graphicsQueueFamily;
  qi->queueCount = 1U;
  qi->pQueuePriorities = &queuePriority;

  qi = queuesInfos + sizeof(VkDeviceQueueCreateInfo);
  qi->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  qi->pNext = VK_NULL_HANDLE;
  qi->flags = (VkDeviceQueueCreateFlags)0U;
  qi->queueFamilyIndex = vkConfig.presentQueueFamily;
  qi->queueCount = 1U;
  qi->pQueuePriorities = &queuePriority;

  // get all available features on gpu
  memset(&vkConfig.gpuFeatures, 0, sizeof(vkConfig.gpuFeatures));
  vkGetPhysicalDeviceFeatures(vkConfig.physicalDevice, &vkConfig.gpuFeatures);

  VkPhysicalDeviceFeatures reqFeatures;
  memset(&reqFeatures, 0, sizeof(VkPhysicalDeviceFeatures));
  reqFeatures.samplerAnisotropy = VK_TRUE;
  reqFeatures.depthClamp = VK_TRUE;

  const char *pDevExt[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};

  VkDeviceCreateInfo deviceInfo;
  memset(&deviceInfo, 0, sizeof(VkDeviceCreateInfo));

  deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
  deviceInfo.pNext = VK_NULL_HANDLE;
  deviceInfo.flags = (VkDeviceCreateFlags)0;
  deviceInfo.queueCreateInfoCount = 2u;
  deviceInfo.pQueueCreateInfos = queuesInfos;
  deviceInfo.enabledLayerCount = 0u;
  deviceInfo.ppEnabledLayerNames = VK_NULL_HANDLE;
  deviceInfo.enabledExtensionCount = (uint32_t)(COUNT_OF(pDevExt));
  deviceInfo.ppEnabledExtensionNames = pDevExt;
  deviceInfo.pEnabledFeatures = &reqFeatures;

  VK_CHECK(vkCreateDevice(vkConfig.physicalDevice, &deviceInfo, VK_NULL_HANDLE,
                          &vkConfig.device),
           "Failed to create logical device");

  vkGetDeviceQueue(vkConfig.device, vkConfig.graphicsQueueFamily, 0,
                   &vkConfig.graphicsQueue);

  vkGetDeviceQueue(vkConfig.device, vkConfig.presentQueueFamily, 0,
                   &vkConfig.presentQueue);

  free(queueFamilies);
  free(queuesInfos);
  qi = NULL;
}

void VK_CreateSwapChain() {

  VkSurfaceFormatKHR surfaceFormat;
  surfaceFormat.format = VK_FORMAT_B8G8R8A8_SRGB;
  surfaceFormat.colorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
  VkPresentModeKHR presentMode = VK_PRESENT_MODE_FIFO_KHR; // TODO: add support VK_PRESENT_MODE_MAILBOX_KHR
  VkExtent2D windowExtent;
  windowExtent.width = vkConfig.renderConfig->vidWidth;
  windowExtent.height = vkConfig.renderConfig->vidHeight;

  VkSurfaceCapabilitiesKHR surfaceCapabilities;
  vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
      vkConfig.physicalDevice, vkConfig.surface, &surfaceCapabilities);

  uint32_t imageCount = surfaceCapabilities.minImageCount + 1u;
  if (surfaceCapabilities.maxImageCount > 0u && imageCount > surfaceCapabilities.maxImageCount)
  {
    imageCount = surfaceCapabilities.maxImageCount;
  }

  VkSwapchainCreateInfoKHR swapchainInfo;
  memset(&swapchainInfo, 0, sizeof(VkSwapchainCreateInfoKHR));
  swapchainInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
  swapchainInfo.surface = vkConfig.surface;

  swapchainInfo.minImageCount = imageCount;
  swapchainInfo.imageFormat = surfaceFormat.format;
  swapchainInfo.imageColorSpace = surfaceFormat.colorSpace;
  swapchainInfo.imageExtent = windowExtent;
  swapchainInfo.imageArrayLayers = 1u;
  swapchainInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
  uint32_t familesIndices[] = {vkConfig.graphicsQueueFamily,
                               vkConfig.presentQueueFamily};

  if (vkConfig.graphicsQueueFamily != vkConfig.presentQueueFamily)
  {
    swapchainInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
    swapchainInfo.queueFamilyIndexCount = 2u;
    swapchainInfo.pQueueFamilyIndices = &familesIndices;
  } else {
    swapchainInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
  }

  swapchainInfo.preTransform = surfaceCapabilities.currentTransform;
  swapchainInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
  swapchainInfo.presentMode = presentMode;
  swapchainInfo.clipped = VK_TRUE;


  VK_CHECK(vkCreateSwapchainKHR(vkConfig.device, &swapchainInfo, NULL,
                                &vkConfig.swapchain.swapchain),
           "Failed to create swapchain");

  // TODO: get swapchain images 

  vkGetSwapchainImagesKHR(vkConfig.device, vkConfig.swapchain.swapchain,
                          &imageCount, VK_NULL_HANDLE);
  vkConfig.swapchain.swapchainImageCount = imageCount;
  vkConfig.swapchain.swapchainImage =
      (VkImage *)calloc(imageCount, sizeof(VkImage));
  vkGetSwapchainImagesKHR(vkConfig.device, vkConfig.swapchain.swapchain,
                          &imageCount, vkConfig.swapchain.swapchainImage);

  vkConfig.swapchain.imageExtent = windowExtent;
  vkConfig.swapchain.swapchainImageFormat = surfaceFormat.format;
}
void VK_CreateRenderPass() {}

/*
** R_GetModeInfo
*/
typedef struct vidmode_s {
  const char *description;
  int width, height;
  float pixelAspect; // pixel width / height
} vidmode_t;

vidmode_t r_vidModes[] = {
    // TODO: find solution for add support for modern resolutions
    {"Mode  0: 320x240", 320, 240, 1},
    {"Mode  1: 400x300", 400, 300, 1},
    {"Mode  2: 512x384", 512, 384, 1},
    {"Mode  3: 640x480", 640, 480, 1},
    {"Mode  4: 800x600", 800, 600, 1},
    {"Mode  5: 960x720", 960, 720, 1},
    {"Mode  6: 1024x768", 1024, 768, 1},
    {"Mode  7: 1152x864", 1152, 864, 1},
    {"Mode  8: 1280x1024", 1280, 1024, 1},
    {"Mode  9: 1600x1200", 1600, 1200, 1},
    {"Mode 10: 2048x1536", 2048, 1536, 1},
    {"Mode 11: 856x480 (wide)", 856, 480, 1},
    {"Mode 12: 1920x1200 (wide)", 1920, 1200, 1} //----(SA)	added
};
static int s_numVidModes = (sizeof(r_vidModes) / sizeof(r_vidModes[0]));

qboolean R_GetModeInfo(int *width, int *height, float *windowAspect, int mode) {
  vidmode_t *vm;

  if (mode < -1) {
    return qfalse;
  }
  if (mode >= s_numVidModes) {
    return qfalse;
  }

  if (mode == -1) {
    *width = r_customwidth->integer;
    *height = r_customheight->integer;
    *windowAspect = r_customaspect->value;
    return qtrue;
  }

  vm = &r_vidModes[mode];

  *width = vm->width;
  *height = vm->height;
  *windowAspect = (float)vm->width / (vm->height * vm->pixelAspect);

  return qtrue;
}

/*
** R_ModeList_f
*/
static void R_ModeList_f(void) {
  int i;

  ri.Printf(PRINT_ALL, "\n");
  for (i = 0; i < s_numVidModes; i++) {
    ri.Printf(PRINT_ALL, "%s\n", r_vidModes[i].description);
  }
  ri.Printf(PRINT_ALL, "\n");
}

void R_TakeScreenshot(int x, int y, int width, int height, char *fileName) {
  byte *buffer;
  int i, c, temp;

  buffer = ri.Hunk_AllocateTempMemory(
      renderConfig.vidWidth * renderConfig.vidHeight * 3 + 18);

  memset(buffer, 0, 18);
  buffer[2] = 2; // uncompressed type
  buffer[12] = width & 255;
  buffer[13] = width >> 8;
  buffer[14] = height & 255;
  buffer[15] = height >> 8;
  buffer[16] = 24; // pixel size

  // qglReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, buffer + 18);

  // swap rgb to bgr
  c = 18 + width * height * 3;
  for (i = 18; i < c; i += 3) {
    temp = buffer[i];
    buffer[i] = buffer[i + 2];
    buffer[i + 2] = temp;
  }

  // gamma correct
  if ((tr.overbrightBits > 0) && renderConfig.deviceSupportsGamma) {
    R_GammaCorrect(buffer + 18,
                   renderConfig.vidWidth * renderConfig.vidHeight * 3);
  }

  ri.FS_WriteFile(fileName, buffer, c);

  ri.Hunk_FreeTempMemory(buffer);
}

/*
==============
R_TakeScreenshotJPEG
==============
*/
void R_TakeScreenshotJPEG(int x, int y, int width, int height, char *fileName) {
  byte *buffer;

  buffer = ri.Hunk_AllocateTempMemory(renderConfig.vidWidth *
                                      renderConfig.vidHeight * 4);

  // qglReadPixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

  // gamma correct
  if ((tr.overbrightBits > 0) && renderConfig.deviceSupportsGamma) {
    R_GammaCorrect(buffer, renderConfig.vidWidth * renderConfig.vidHeight * 4);
  }

  ri.FS_WriteFile(fileName, buffer, 1); // create path
  SaveJPG(fileName, 95, renderConfig.vidWidth, renderConfig.vidHeight, buffer);

  ri.Hunk_FreeTempMemory(buffer);
}

/*
==================
R_ScreenshotFilename
==================
*/
void R_ScreenshotFilename(int lastNumber, char *fileName) {
  int a, b, c, d;

  if (lastNumber < 0 || lastNumber > 9999) {
    Com_sprintf(fileName, MAX_OSPATH, "screenshots/shot9999.tga");
    return;
  }

  a = lastNumber / 1000;
  lastNumber -= a * 1000;
  b = lastNumber / 100;
  lastNumber -= b * 100;
  c = lastNumber / 10;
  lastNumber -= c * 10;
  d = lastNumber;

  Com_sprintf(fileName, MAX_OSPATH, "screenshots/shot%i%i%i%i.tga", a, b, c, d);
}

/*
==============
R_ScreenshotFilenameJPEG
==============
*/
void R_ScreenshotFilenameJPEG(int lastNumber, char *fileName) {
  int a, b, c, d;

  if (lastNumber < 0 || lastNumber > 9999) {
    Com_sprintf(fileName, MAX_OSPATH, "screenshots/shot9999.jpg");
    return;
  }

  a = lastNumber / 1000;
  lastNumber -= a * 1000;
  b = lastNumber / 100;
  lastNumber -= b * 100;
  c = lastNumber / 10;
  lastNumber -= c * 10;
  d = lastNumber;

  Com_sprintf(fileName, MAX_OSPATH, "screenshots/shot%i%i%i%i.jpg", a, b, c, d);
}

/*
====================
R_LevelShot

levelshots are specialized 128*128 thumbnails for
the menu system, sampled down from full screen distorted images
====================
*/
void R_LevelShot(void) {
  char checkname[MAX_OSPATH];
  byte *buffer;
  byte *source;
  byte *src, *dst;
  int x, y;
  int r, g, b;
  float xScale, yScale;
  int xx, yy;

  sprintf(checkname, "levelshots/%s.tga", tr.world->baseName);

  source = ri.Hunk_AllocateTempMemory(renderConfig.vidWidth *
                                      renderConfig.vidHeight * 3);

  buffer = ri.Hunk_AllocateTempMemory(128 * 128 * 3 + 18);
  memset(buffer, 0, 18);
  buffer[2] = 2; // uncompressed type
  buffer[12] = 128;
  buffer[14] = 128;
  buffer[16] = 24; // pixel size

  // TODO: give a acces to frame buffer
  /* qglReadPixels(0, 0, glConfig.vidWidth, glConfig.vidHeight, GL_RGB,
                 GL_UNSIGNED_BYTE, source);*/

  // resample from source
  xScale = renderConfig.vidWidth / 512.0f;
  yScale = renderConfig.vidHeight / 384.0f;
  for (y = 0; y < 128; y++) {
    for (x = 0; x < 128; x++) {
      r = g = b = 0;
      for (yy = 0; yy < 3; yy++) {
        for (xx = 0; xx < 4; xx++) {
          src = source +
                3 * (renderConfig.vidWidth * (int)((y * 3 + yy) * yScale) +
                     (int)((x * 4 + xx) * xScale));
          r += src[0];
          g += src[1];
          b += src[2];
        }
      }
      dst = buffer + 18 + 3 * (y * 128 + x);
      dst[0] = b / 12;
      dst[1] = g / 12;
      dst[2] = r / 12;
    }
  }

  // gamma correct
  if ((tr.overbrightBits > 0) && renderConfig.deviceSupportsGamma) {
    R_GammaCorrect(buffer + 18, 128 * 128 * 3);
  }

  ri.FS_WriteFile(checkname, buffer, 128 * 128 * 3 + 18);

  ri.Hunk_FreeTempMemory(buffer);
  ri.Hunk_FreeTempMemory(source);

  ri.Printf(PRINT_ALL, "Wrote %s\n", checkname);
}

/*
==================
R_ScreenShot_f

screenshot
screenshot [silent]
screenshot [levelshot]
screenshot [filename]

Doesn't print the pacifier message if there is a second arg
==================
*/
void R_ScreenShot_f(void) {
  char checkname[MAX_OSPATH];
  int len;
  static int lastNumber = -1;
  qboolean silent;

  if (!strcmp(ri.Cmd_Argv(1), "levelshot")) {
    R_LevelShot();
    return;
  }

  if (!strcmp(ri.Cmd_Argv(1), "silent")) {
    silent = qtrue;
  } else {
    silent = qfalse;
  }

  if (ri.Cmd_Argc() == 2 && !silent) {
    // explicit filename
    Com_sprintf(checkname, MAX_OSPATH, "screenshots/%s.tga", ri.Cmd_Argv(1));
  } else {
    // scan for a free filename

    // if we have saved a previous screenshot, don't scan
    // again, because recording demo avis can involve
    // thousands of shots
    if (lastNumber == -1) {
      lastNumber = 0;
    }
    // scan for a free number
    for (; lastNumber <= 9999; lastNumber++) {
      R_ScreenshotFilename(lastNumber, checkname);

      len = ri.FS_ReadFile(checkname, NULL);
      if (len <= 0) {
        break; // file doesn't exist
      }
    }

    if (lastNumber >= 9999) {
      ri.Printf(PRINT_ALL, "ScreenShot: Couldn't create a file\n");
      return;
    }

    lastNumber++;
  }

  R_TakeScreenshot(0, 0, renderConfig.vidWidth, renderConfig.vidHeight,
                   checkname);

  if (!silent) {
    ri.Printf(PRINT_ALL, "Wrote %s\n", checkname);
  }
}

void R_ScreenShotJPEG_f(void) {
  char checkname[MAX_OSPATH];
  int len;
  static int lastNumber = -1;
  qboolean silent;

  if (!strcmp(ri.Cmd_Argv(1), "levelshot")) {
    R_LevelShot();
    return;
  }

  if (!strcmp(ri.Cmd_Argv(1), "silent")) {
    silent = qtrue;
  } else {
    silent = qfalse;
  }

  if (ri.Cmd_Argc() == 2 && !silent) {
    // explicit filename
    Com_sprintf(checkname, MAX_OSPATH, "screenshots/%s.jpg", ri.Cmd_Argv(1));
  } else {
    // scan for a free filename

    // if we have saved a previous screenshot, don't scan
    // again, because recording demo avis can involve
    // thousands of shots
    if (lastNumber == -1) {
      lastNumber = 0;
    }
    // scan for a free number
    for (; lastNumber <= 9999; lastNumber++) {
      R_ScreenshotFilenameJPEG(lastNumber, checkname);

      len = ri.FS_ReadFile(checkname, NULL);
      if (len <= 0) {
        break; // file doesn't exist
      }
    }

    if (lastNumber == 10000) {
      ri.Printf(PRINT_ALL, "ScreenShot: Couldn't create a file\n");
      return;
    }

    lastNumber++;
  }

  R_TakeScreenshotJPEG(0, 0, renderConfig.vidWidth, renderConfig.vidHeight,
                       checkname);

  if (!silent) {
    ri.Printf(PRINT_ALL, "Wrote %s\n", checkname);
  }
}

void VkInfo_f(void) {}

// RF
extern void R_CropImages_f(void);

void R_Register(void) {
  //
  // latched and archived variables
  //
  r_vkDriver =
      ri.Cvar_Get("r_vkDriver", VULKAN_DRIVER_NAME, CVAR_ARCHIVE | CVAR_LATCH);
  r_allowExtensions =
      ri.Cvar_Get("r_allowExtensions", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_ext_compressed_textures =
      ri.Cvar_Get("r_ext_compressed_textures", "1",
                  CVAR_ARCHIVE | CVAR_LATCH); // (SA) ew, a spelling change I
                                              // missed from the missionpack
  r_ext_gamma_control =
      ri.Cvar_Get("r_ext_gamma_control", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_ext_multitexture =
      ri.Cvar_Get("r_ext_multitexture", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_ext_compiled_vertex_array = ri.Cvar_Get("r_ext_compiled_vertex_array", "1",
                                            CVAR_ARCHIVE | CVAR_LATCH);
  r_glIgnoreWicked3D =
      ri.Cvar_Get("r_glIgnoreWicked3D", "0", CVAR_ARCHIVE | CVAR_LATCH);

  //----(SA)	added
  r_ext_ATI_pntriangles =
      ri.Cvar_Get("r_ext_ATI_pntriangles", "0",
                  CVAR_ARCHIVE | CVAR_LATCH); //----(SA)	default to '0'
  r_ati_truform_tess = ri.Cvar_Get("r_ati_truform_tess", "1", CVAR_ARCHIVE);
  // GR - Change default mode -- linear doesn't do much...
  r_ati_truform_normalmode =
      ri.Cvar_Get("r_ati_truform_normalmode", "QUADRATIC", CVAR_ARCHIVE);
  r_ati_truform_pointmode =
      ri.Cvar_Get("r_ati_truform_pointmode", "CUBIC", CVAR_ARCHIVE);

  r_ati_fsaa_samples = ri.Cvar_Get("r_ati_fsaa_samples", "1",
                                   CVAR_ARCHIVE); // DAJ valids are 1, 2, 4

  r_ext_texture_filter_anisotropic =
      ri.Cvar_Get("r_ext_texture_filter_anisotropic", "0", CVAR_ARCHIVE);

  r_ext_NV_fog_dist =
      ri.Cvar_Get("r_ext_NV_fog_dist", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_nv_fogdist_mode = ri.Cvar_Get("r_nv_fogdist_mode", "GL_EYE_RADIAL_NV",
                                  CVAR_ARCHIVE); // default to 'looking good'
  //----(SA)	end

#ifdef __linux__ // broken on linux
  r_ext_texture_env_add =
      ri.Cvar_Get("r_ext_texture_env_add", "0", CVAR_ARCHIVE | CVAR_LATCH);
#else
  r_ext_texture_env_add =
      ri.Cvar_Get("r_ext_texture_env_add", "1", CVAR_ARCHIVE | CVAR_LATCH);
#endif

  r_picmip = ri.Cvar_Get("r_picmip", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_picmip2 = ri.Cvar_Get(
      "r_picmip2", "2",
      CVAR_ARCHIVE | CVAR_LATCH); // used for character skins picmipping at a
                                  // different level from the rest of the game
  r_roundImagesDown =
      ri.Cvar_Get("r_roundImagesDown", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_lowMemTextureSize =
      ri.Cvar_Get("r_lowMemTextureSize", "0", CVAR_ARCHIVE | CVAR_LATCH);
  r_lowMemTextureThreshold = ri.Cvar_Get("r_lowMemTextureThreshold", "15.0",
                                         CVAR_ARCHIVE | CVAR_LATCH);
  r_rmse = ri.Cvar_Get("r_rmse", "0.0", CVAR_ARCHIVE | CVAR_LATCH);
  r_colorMipLevels = ri.Cvar_Get("r_colorMipLevels", "0", CVAR_LATCH);
  AssertCvarRange(r_picmip, 0, 16, qtrue);
  AssertCvarRange(r_picmip2, 0, 16, qtrue);
  r_detailTextures =
      ri.Cvar_Get("r_detailtextures", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_texturebits = ri.Cvar_Get("r_texturebits", "0", CVAR_ARCHIVE | CVAR_LATCH);
  r_colorbits = ri.Cvar_Get("r_colorbits", "0", CVAR_ARCHIVE | CVAR_LATCH);
  r_stereo = ri.Cvar_Get("r_stereo", "0", CVAR_ARCHIVE | CVAR_LATCH);
#if defined(__linux__)
  r_stencilbits = ri.Cvar_Get("r_stencilbits", "0", CVAR_ARCHIVE | CVAR_LATCH);
#elif defined(__MACOS__)
  {
    //	extern long gSystemVersion;
    //	if(gSystemVersion >= 0x1000)
    //		r_stencilbits = ri.Cvar_Get( "r_stencilbits", "8", CVAR_ARCHIVE
    //| CVAR_LATCH ); 	else
    r_stencilbits =
        ri.Cvar_Get("r_stencilbits", "0", CVAR_ARCHIVE | CVAR_LATCH);
  }
#else
  r_stencilbits = ri.Cvar_Get("r_stencilbits", "8", CVAR_ARCHIVE | CVAR_LATCH);
#endif
  r_depthbits = ri.Cvar_Get("r_depthbits", "0", CVAR_ARCHIVE | CVAR_LATCH);
  r_overBrightBits =
      ri.Cvar_Get("r_overBrightBits", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_ignorehwgamma = ri.Cvar_Get(
      "r_ignorehwgamma", "1",
      CVAR_ARCHIVE |
          CVAR_LATCH); //----(SA) changed this to default to '1' for Drew
  r_mode = ri.Cvar_Get("r_mode", "3", CVAR_ARCHIVE | CVAR_LATCH);
  r_fullscreen = ri.Cvar_Get("r_fullscreen", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_customwidth =
      ri.Cvar_Get("r_customwidth", "1600", CVAR_ARCHIVE | CVAR_LATCH);
  r_customheight =
      ri.Cvar_Get("r_customheight", "1024", CVAR_ARCHIVE | CVAR_LATCH);
  r_customaspect =
      ri.Cvar_Get("r_customaspect", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_simpleMipMaps =
      ri.Cvar_Get("r_simpleMipMaps", "1", CVAR_ARCHIVE | CVAR_LATCH);
  r_vertexLight = ri.Cvar_Get("r_vertexLight", "0", CVAR_ARCHIVE | CVAR_LATCH);
  r_uiFullScreen = ri.Cvar_Get("r_uifullscreen", "0", 0);
  r_subdivisions =
      ri.Cvar_Get("r_subdivisions", "4", CVAR_ARCHIVE | CVAR_LATCH);
#ifdef MACOS_X
  // Default to using SMP on Mac OS X if we have multiple processors
  r_smp = ri.Cvar_Get("r_smp", Sys_ProcessorCount() > 1 ? "1" : "0",
                      CVAR_ARCHIVE | CVAR_LATCH);
#else
  r_smp = ri.Cvar_Get("r_smp", "0", CVAR_ARCHIVE | CVAR_LATCH);
#endif
  r_ignoreFastPath =
      ri.Cvar_Get("r_ignoreFastPath", "1", CVAR_ARCHIVE | CVAR_LATCH);

  //
  // temporary latched variables that can only change over a restart
  //
  r_displayRefresh = ri.Cvar_Get("r_displayRefresh", "0", CVAR_LATCH);
  AssertCvarRange(r_displayRefresh, 0, 200, qtrue);
  r_fullbright = ri.Cvar_Get("r_fullbright", "0", CVAR_LATCH | CVAR_CHEAT);
  r_mapOverBrightBits = ri.Cvar_Get("r_mapOverBrightBits", "2", CVAR_LATCH);
  r_intensity = ri.Cvar_Get("r_intensity", "1", CVAR_LATCH);
  r_singleShader = ri.Cvar_Get("r_singleShader", "0", CVAR_CHEAT | CVAR_LATCH);

  //
  // archived variables that can change at any time
  //
  r_lodCurveError = ri.Cvar_Get("r_lodCurveError", "250", CVAR_ARCHIVE);
  r_lodbias = ri.Cvar_Get("r_lodbias", "0", CVAR_ARCHIVE);
  r_flares = ri.Cvar_Get("r_flares", "1", CVAR_ARCHIVE);
  r_znear = ri.Cvar_Get("r_znear", "4", CVAR_CHEAT);
  AssertCvarRange(r_znear, 0.001f, 200, qtrue);
  //----(SA)	added
  r_zfar = ri.Cvar_Get("r_zfar", "0", CVAR_CHEAT);
  //----(SA)	end
  r_fastsky = ri.Cvar_Get("r_fastsky", "0", CVAR_ARCHIVE);
  r_inGameVideo = ri.Cvar_Get("r_inGameVideo", "1", CVAR_ARCHIVE);
  r_drawSun = ri.Cvar_Get("r_drawSun", "1", CVAR_ARCHIVE);
  r_dynamiclight = ri.Cvar_Get("r_dynamiclight", "1", CVAR_ARCHIVE);
  r_dlightScale =
      ri.Cvar_Get("r_dlightScale", "1.0", CVAR_ARCHIVE); //----(SA)	added
  r_dlightBacks = ri.Cvar_Get("r_dlightBacks", "1", CVAR_ARCHIVE);
  r_finish = ri.Cvar_Get("r_finish", "0", CVAR_ARCHIVE);
  r_textureMode =
      ri.Cvar_Get("r_textureMode", "GL_LINEAR_MIPMAP_NEAREST", CVAR_ARCHIVE);
  r_swapInterval = ri.Cvar_Get("r_swapInterval", "0", CVAR_ARCHIVE);
#ifdef __MACOS__
  r_gamma = ri.Cvar_Get("r_gamma", "1.2", CVAR_ARCHIVE);
#else
  r_gamma = ri.Cvar_Get("r_gamma", "1.3", CVAR_ARCHIVE);
#endif
  r_facePlaneCull = ri.Cvar_Get("r_facePlaneCull", "1", CVAR_ARCHIVE);

  r_railWidth = ri.Cvar_Get("r_railWidth", "16", CVAR_ARCHIVE);
  r_railCoreWidth = ri.Cvar_Get("r_railCoreWidth", "1", CVAR_ARCHIVE);
  r_railSegmentLength = ri.Cvar_Get("r_railSegmentLength", "32", CVAR_ARCHIVE);

  r_waterFogColor =
      ri.Cvar_Get("r_waterFogColor", "0", CVAR_ROM); //----(SA)	added
  r_mapFogColor =
      ri.Cvar_Get("r_mapFogColor", "0", CVAR_ROM); //----(SA)	added
  r_savegameFogColor =
      ri.Cvar_Get("r_savegameFogColor", "0", CVAR_ROM); //----(SA)	added

  r_primitives = ri.Cvar_Get("r_primitives", "0", CVAR_ARCHIVE);

  r_ambientScale = ri.Cvar_Get("r_ambientScale", "0.5", CVAR_CHEAT);
  r_directedScale = ri.Cvar_Get("r_directedScale", "1", CVAR_CHEAT);

  //
  // temporary variables that can change at any time
  //
  r_showImages = ri.Cvar_Get("r_showImages", "0", CVAR_TEMP);

  r_debugLight = ri.Cvar_Get("r_debuglight", "0", CVAR_TEMP);
  r_debugSort = ri.Cvar_Get("r_debugSort", "0", CVAR_CHEAT);
  r_printShaders = ri.Cvar_Get("r_printShaders", "0", 0);
  r_saveFontData = ri.Cvar_Get("r_saveFontData", "0", 0);

  // Ridah
  // show_bug.cgi?id=440
  // NOTE TTimo: r_cache is disabled by default in SP
  ri.Cvar_Set("r_cache", "0");
  r_cache = ri.Cvar_Get("r_cache", "1",
                        CVAR_LATCH); // leaving it as this for backwards
                                     // compability. but it caches models and
                                     // shaders also (SA) disabling cacheshaders
  ri.Cvar_Set("r_cacheShaders", "0");
  r_cacheShaders = ri.Cvar_Get("r_cacheShaders", "0", CVAR_LATCH);
  //----(SA)	end

  r_cacheModels = ri.Cvar_Get("r_cacheModels", "1", CVAR_LATCH);
  r_compressModels = ri.Cvar_Get("r_compressModels", "0",
                                 0); // converts MD3 -> MDC at run-time
  r_exportCompressedModels = ri.Cvar_Get("r_exportCompressedModels", "0",
                                         0); // saves compressed models
  r_cacheGathering = ri.Cvar_Get("cl_cacheGathering", "0", 0);
  r_buildScript = ri.Cvar_Get("com_buildscript", "0", 0);
  r_bonesDebug = ri.Cvar_Get("r_bonesDebug", "0", CVAR_CHEAT);
  // done.

  // Rafael - wolf fog
  r_wolffog = ri.Cvar_Get("r_wolffog", "1", 0);
  // done

  r_nocurves = ri.Cvar_Get("r_nocurves", "0", CVAR_CHEAT);
  r_drawworld = ri.Cvar_Get("r_drawworld", "1", CVAR_CHEAT);
  r_lightmap = ri.Cvar_Get("r_lightmap", "0", CVAR_CHEAT);
  r_portalOnly = ri.Cvar_Get("r_portalOnly", "0", CVAR_CHEAT);

  r_flareSize = ri.Cvar_Get("r_flareSize", "40", CVAR_CHEAT);
  r_flareFade = ri.Cvar_Get("r_flareFade", "5", CVAR_CHEAT);

  r_showSmp = ri.Cvar_Get("r_showSmp", "0", CVAR_CHEAT);
  r_skipBackEnd = ri.Cvar_Get("r_skipBackEnd", "0", CVAR_CHEAT);

  r_measureOverdraw = ri.Cvar_Get("r_measureOverdraw", "0", CVAR_CHEAT);
  r_lodscale = ri.Cvar_Get("r_lodscale", "5", CVAR_CHEAT);
  r_norefresh = ri.Cvar_Get("r_norefresh", "0", CVAR_CHEAT);
  r_drawentities = ri.Cvar_Get("r_drawentities", "1", CVAR_CHEAT);
  r_ignore = ri.Cvar_Get("r_ignore", "1", CVAR_CHEAT);
  r_nocull = ri.Cvar_Get("r_nocull", "0", CVAR_CHEAT);
  r_novis = ri.Cvar_Get("r_novis", "0", CVAR_CHEAT);
  r_showcluster = ri.Cvar_Get("r_showcluster", "0", CVAR_CHEAT);
  r_speeds = ri.Cvar_Get("r_speeds", "0", CVAR_CHEAT);
  r_verbose = ri.Cvar_Get("r_verbose", "0", CVAR_CHEAT);
  r_logFile = ri.Cvar_Get("r_logFile", "0", CVAR_CHEAT);
  r_debugSurface = ri.Cvar_Get("r_debugSurface", "0", CVAR_CHEAT);
  r_nobind = ri.Cvar_Get("r_nobind", "0", CVAR_CHEAT);
  r_showtris = ri.Cvar_Get("r_showtris", "0", CVAR_CHEAT);
  r_showsky = ri.Cvar_Get("r_showsky", "0", CVAR_CHEAT);
  r_shownormals = ri.Cvar_Get("r_shownormals", "0", CVAR_CHEAT);
  r_clear = ri.Cvar_Get("r_clear", "0", CVAR_CHEAT);
  r_offsetFactor = ri.Cvar_Get("r_offsetfactor", "-1", CVAR_CHEAT);
  r_offsetUnits = ri.Cvar_Get("r_offsetunits", "-2", CVAR_CHEAT);
  r_drawBuffer = ri.Cvar_Get("r_drawBuffer", "GL_BACK", CVAR_CHEAT);
  r_lockpvs = ri.Cvar_Get("r_lockpvs", "0", CVAR_CHEAT);
  r_noportals = ri.Cvar_Get("r_noportals", "0", CVAR_CHEAT);
  r_shadows = ri.Cvar_Get("cg_shadows", "1", 0);
  r_portalsky = ri.Cvar_Get("cg_skybox", "1", 0);

  r_maxpolys = ri.Cvar_Get("r_maxpolys", va("%d", MAX_POLYS), 0);
  r_maxpolyverts = ri.Cvar_Get("r_maxpolyverts", va("%d", MAX_POLYVERTS), 0);

  r_highQualityVideo = ri.Cvar_Get("r_highQualityVideo", "1", CVAR_ARCHIVE);
  // make sure all the commands added here are also
  // removed in R_Shutdown
  ri.Cmd_AddCommand("imagelist", R_ImageList_f);
  ri.Cmd_AddCommand("shaderlist", R_ShaderList_f);
  ri.Cmd_AddCommand("skinlist", R_SkinList_f);
  ri.Cmd_AddCommand("modellist", R_Modellist_f);
  ri.Cmd_AddCommand("modelist", R_ModeList_f);
  ri.Cmd_AddCommand("screenshot", R_ScreenShot_f);
  ri.Cmd_AddCommand("screenshotJPEG", R_ScreenShotJPEG_f);
  ri.Cmd_AddCommand("vkinfo", VkInfo_f);
  ri.Cmd_AddCommand("taginfo", R_TagInfo_f);

  // Ridah
  ri.Cmd_AddCommand("cropimages", R_CropImages_f);
  // done.
}

void R_Init(void) {
  int err;
  int i;

  ri.Printf(PRINT_ALL, "----- R_Init -----\n");

  // clear all our internal state
  memset(&tr, 0, sizeof(tr));
  memset(&backEnd, 0, sizeof(backEnd));
  memset(&tess, 0, sizeof(tess));

  Swap_Init();

  if ((int)tess.xyz & 15) {
    Com_Printf("WARNING: tess.xyz not 16 byte aligned\n");
  }
  memset(tess.constantColor255, 255, sizeof(tess.constantColor255));

  //
  // init function tables
  //
  for (i = 0; i < FUNCTABLE_SIZE; i++) {
    tr.sinTable[i] = sin(DEG2RAD(i * 360.0f / ((float)(FUNCTABLE_SIZE - 1))));
    tr.squareTable[i] = (i < FUNCTABLE_SIZE / 2) ? 1.0f : -1.0f;
    tr.sawToothTable[i] = (float)i / FUNCTABLE_SIZE;
    tr.inverseSawToothTable[i] = 1.0f - tr.sawToothTable[i];

    if (i < FUNCTABLE_SIZE / 2) {
      if (i < FUNCTABLE_SIZE / 4) {
        tr.triangleTable[i] = (float)i / (FUNCTABLE_SIZE / 4);
      } else {
        tr.triangleTable[i] = 1.0f - tr.triangleTable[i - FUNCTABLE_SIZE / 4];
      }
    } else {
      tr.triangleTable[i] = -tr.triangleTable[i - FUNCTABLE_SIZE / 2];
    }
  }

  R_InitFogTable();

  R_NoiseInit();

  R_Register();

  // Ridah, init the virtual memory
  R_Hunk_Begin();

  max_polys = r_maxpolys->integer;
  if (max_polys < MAX_POLYS) {
    max_polys = MAX_POLYS;
  }

  max_polyverts = r_maxpolyverts->integer;
  if (max_polyverts < MAX_POLYVERTS) {
    max_polyverts = MAX_POLYVERTS;
  }

  backEndData[0] =
      ri.Hunk_Alloc(sizeof(*backEndData[0]) + sizeof(srfPoly_t) * max_polys +
                        sizeof(polyVert_t) * max_polyverts,
                    h_low);

  backEndData[1] = NULL; // second backend is not needed for now

  R_ToggleSmpFrame();

  OS_CreateWindow();

  InitVulkan();

  R_InitImages();

  R_InitShaders();

  R_InitSkins();

  R_ModelInit();

  R_InitFreeType();

  ri.Printf(PRINT_ALL, "----- finished R_Init -----\n");
}

/*
===============
RE_Shutdown
===============
*/
void RE_Shutdown(qboolean destroyWindow) {

  ri.Printf(PRINT_ALL, "RE_Shutdown( %i )\n", destroyWindow);

  ri.Cmd_RemoveCommand("modellist");
  ri.Cmd_RemoveCommand("screenshotJPEG");
  ri.Cmd_RemoveCommand("screenshot");
  ri.Cmd_RemoveCommand("imagelist");
  ri.Cmd_RemoveCommand("shaderlist");
  ri.Cmd_RemoveCommand("skinlist");
  ri.Cmd_RemoveCommand("gfxinfo");
  ri.Cmd_RemoveCommand("modelist");
  ri.Cmd_RemoveCommand("shaderstate");
  ri.Cmd_RemoveCommand("taginfo");

  // Ridah
  ri.Cmd_RemoveCommand("cropimages");
  // done.

  R_ShutdownCommandBuffers();

  // Ridah, keep a backup of the current images if possible
  // clean out any remaining unused media from the last backup
  R_PurgeShaders(9999999);
  R_PurgeBackupImages(9999999);
  R_PurgeModels(9999999);

  if (r_cache->integer) {
    if (tr.registered) {
      if (destroyWindow) {
        R_SyncRenderThread();
        R_ShutdownCommandBuffers();
        R_DeleteTextures();
      } else {
        // backup the current media
        R_ShutdownCommandBuffers();

        R_BackupModels();
        R_BackupShaders();
        R_BackupImages();
      }
    }
  } else if (tr.registered) {
    R_SyncRenderThread();
    R_ShutdownCommandBuffers();
    R_DeleteTextures();
  }

  R_DoneFreeType();

  // shut down platform specific OpenGL stuff
  if (destroyWindow) {
    //  GLimp_Shutdown();

    // Ridah, release the virtual memory
    R_Hunk_End();
    R_FreeImageBuffer();
    // ri.Tag_Free();	// wipe all render alloc'd zone memory
  }

  tr.registered = qfalse;
}

/*
=============
RE_EndRegistration

Touch all images to make sure they are resident
=============
*/
void RE_EndRegistration(void) {
  R_SyncRenderThread();
  if (!Sys_LowPhysicalMemory()) {
    RB_ShowImages();
  }
}

refexport_t *GetRefAPI(int apiVersion, refimport_t *rimp) {
  static refexport_t re;

  ri = *rimp;

  memset(&re, 0, sizeof(re));

  if (apiVersion != REF_API_VERSION) {
    ri.Printf(PRINT_ALL, "Mismatched REF_API_VERSION: expected %i, got %i\n",
              REF_API_VERSION, apiVersion);
    return NULL;
  }

  // the RE_ functions are Renderer Entry points

  re.Shutdown = RE_Shutdown;

  re.BeginRegistration = RE_BeginRegistration;
  re.RegisterModel = RE_RegisterModel;
  re.RegisterSkin = RE_RegisterSkin;
  //----(SA) added
  re.GetSkinModel = RE_GetSkinModel;
  re.GetShaderFromModel = RE_GetShaderFromModel;
  //----(SA) end
  re.RegisterShader = RE_RegisterShader;
  re.RegisterShaderNoMip = RE_RegisterShaderNoMip;
  re.LoadWorld = RE_LoadWorldMap;
  re.SetWorldVisData = RE_SetWorldVisData;
  re.EndRegistration = RE_EndRegistration;

  re.BeginFrame = RE_BeginFrame;
  re.EndFrame = RE_EndFrame;

  re.MarkFragments = R_MarkFragments;
  re.LerpTag = R_LerpTag;
  re.ModelBounds = R_ModelBounds;

  re.ClearScene = RE_ClearScene;
  re.AddRefEntityToScene = RE_AddRefEntityToScene;
  re.AddPolyToScene = RE_AddPolyToScene;
  // Ridah
  re.AddPolysToScene = RE_AddPolysToScene;
  // done.
  re.AddLightToScene = RE_AddLightToScene;
  //----(SA)
  re.AddCoronaToScene = RE_AddCoronaToScene;
  re.SetFog = R_SetFog;
  //----(SA)
  re.RenderScene = RE_RenderScene;

  re.SetColor = RE_SetColor;
  re.DrawStretchPic = RE_StretchPic;
  re.DrawStretchPicGradient = RE_StretchPicGradient;
  re.DrawStretchRaw = RE_StretchRaw;
  re.UploadCinematic = RE_UploadCinematic;
  re.RegisterFont = RE_RegisterFont;
  re.RemapShader = R_RemapShader;
  re.GetEntityToken = R_GetEntityToken;

  // RF
  re.ZombieFXAddNewHit = NULL; // RB_ZombieFXAddNewHit;

  return &re;
}
