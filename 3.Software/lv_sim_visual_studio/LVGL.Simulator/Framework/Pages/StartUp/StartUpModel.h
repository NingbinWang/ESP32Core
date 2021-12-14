#ifndef __STARTUP_MODEL_H
#define __STARTUP_MODEL_H

//#include "Common/DataProc/DataProc.h"
#include "HAL/HAL.h"

namespace Page
{

    class StartupModel
    {
    public:
        void Init();
        void Deinit();
        void PlayMusic(const char* music);


    private:
       // Account* account;
    };

}

#endif
