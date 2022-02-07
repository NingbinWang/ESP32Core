#ifndef _SYSTEMINFOS_MODEL_H_
#define _SYSTEMINFOS_MODEL_H_
#include <stdint.h>

namespace Page
{

class SystemInfosModel
{
public:
    void Init();
    void Deinit();

    void GetIMUInfo(
        char* info, uint32_t len
    );

    void GetBatteryInfo(
        int* usage,
        float* voltage,
        char* state, uint32_t len
    );

    void GetStorageInfo(
        bool* detect,
        char* size, uint32_t len
    );

    void GetJointsInfo(
        char* data, uint32_t len
    );

    void GetPose6DInfo(
        char* data, uint32_t len
    );

};

}

#endif
