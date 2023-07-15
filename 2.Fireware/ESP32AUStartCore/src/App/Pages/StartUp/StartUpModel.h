#ifndef __STARTUP_MODEL_H
#define __STARTUP_MODEL_H

#include "Framework/Notification/Notification.h"
#include  "App/Notify/NotifyCenter.h"
#include "HAL/HAL.h"

namespace Page
{

    class StartupModel
    {
    public:
        void Init();
        void DeInit();
        void PlayMusic(const char* music);
        void SetEncoderEnable(bool en)
    {
        HAL::Encoder_SetEnable(en);
    }


    private:
        Notification* account;
    };

}

#endif
