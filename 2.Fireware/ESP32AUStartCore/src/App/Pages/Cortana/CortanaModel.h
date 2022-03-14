#ifndef _CORTANA_MODEL_H_
#define _CORTANA_MODEL_H_
#include <stdint.h>
#include "Framework/Notification/Notification.h"

namespace Page
{

class CortanaModel
{
public:
    void Init();
    void Deinit();

    private:
        Notification* account;

};

}

#endif