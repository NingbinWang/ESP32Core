#ifndef __FILTER_BASE_H
#define __FILTER_BASE_H

#include <stdint.h>

#define FILTER_ABS(x)  (((x)>0)?(x):-(x))

namespace Filter
{

template <class T> class Base
{
public:
    virtual void Reset()
    {
        isFirst = true;
    }

    virtual bool CheckFirst()
    {
        bool retval = isFirst;
        isFirst = false;
        return retval;
    }

    virtual T GetNext(T value)
    {
        lastValue = value;
        return lastValue;
    }

protected:
    T lastValue;
    bool isFirst;
};

}

#endif // ! __FILTER_BASE_H
