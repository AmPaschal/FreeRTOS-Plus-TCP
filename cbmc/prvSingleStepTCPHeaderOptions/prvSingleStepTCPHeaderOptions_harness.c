/**
 * @file _harness.c
 * @brief TODO
 */

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Define some data size:

    size_t size;

    // Allocate some data:

    uint8_t* data = (uint8_t*)malloc(size);

    // Model other input types:

    FreeRTOS_Socket_t pxSocket;
    BaseType_t xHasSYNFlag;

    int32_t res = prvSingleStepTCPHeaderOptions( data, size, &pxSocket, xHasSYNFlag);
}
