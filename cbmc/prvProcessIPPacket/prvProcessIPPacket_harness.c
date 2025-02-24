/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdlib.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Model input arguments

    IPPacket_t pack;

    NetworkBufferDescriptor_t buff;

    // Allocate data in buffer:

    buff.pucEthernetBuffer = malloc(buff.xDataLength);

    // Allocated data will not be NULL

    __CPROVER_assume(buff.pucEthernetBuffer != NULL);

    eFrameProcessingResult_t res = prvProcessIPPacket( &pack, &buff );
}
