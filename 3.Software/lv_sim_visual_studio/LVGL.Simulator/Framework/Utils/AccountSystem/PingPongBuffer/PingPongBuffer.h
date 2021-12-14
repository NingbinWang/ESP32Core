#ifndef _PINGPONG_BUFFER_H_
#define _PINGPONG_BUFFER_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

    typedef struct
    {
        void* buffer[2];
        volatile uint8_t writeIndex;
        volatile uint8_t readIndex;
        volatile uint8_t readAvaliable[2];
    } PingPongBuffer_t;

    void PingPongBuffer_Init(PingPongBuffer_t* ppbuf, void* buf0, void* buf1);
    bool PingPongBuffer_GetReadBuf(PingPongBuffer_t* ppbuf, void** pReadBuf);
    void PingPongBuffer_SetReadDone(PingPongBuffer_t* ppbuf);
    void PingPongBuffer_GetWriteBuf(PingPongBuffer_t* ppbuf, void** pWriteBuf);
    void PingPongBuffer_SetWriteDone(PingPongBuffer_t* ppbuf);

#ifdef __cplusplus
}
#endif


#endif // !_PINGPONG_BUFFER_H_
