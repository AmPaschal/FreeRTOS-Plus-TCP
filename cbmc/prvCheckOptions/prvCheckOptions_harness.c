/**
 * @file _harness.c
 * @brief TODO
 */

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Model socket:

    FreeRTOS_Socket_t pxSocket;

    // Model network buffer:

    NetworkBufferDescriptor_t pxNetworkBuffer;

    BaseType_t res = prvCheckOptions(&pxSocket, &pxNetworkBuffer );
}
