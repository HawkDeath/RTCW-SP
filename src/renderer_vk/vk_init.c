#include "vk_local.h"

refexport_t *GetRefAPI(int apiVersion, refimport_t *rimp) {
    static refexport_t re;
//    ri = *rimp;

    memset(&re, 0, sizeof(re));

    return &re;
}
