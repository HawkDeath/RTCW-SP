#include "vk_local.h"
#include <vulkan/vulkan.h>
#include <volk.h>
glconfig_t glConfig; // dummy
refexport_t *GetRefAPI(int apiVersion, refimport_t *rimp) {
    static refexport_t re;
//    ri = *rimp;
    VkInstance instance;
    volkInitialize();
    memset(&re, 0, sizeof(re));

    return &re;
}
