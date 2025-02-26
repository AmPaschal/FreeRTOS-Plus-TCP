/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdlib.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"

BaseType_t xNetworkInterfaceOutput( NetworkBufferDescriptor_t * const pxDescriptor, BaseType_t xReleaseAfterSend ) {
    BaseType_t res;
    return res;
}

BaseType_t xProcessReceivedTCPPacket( NetworkBufferDescriptor_t * pxDescriptor ) {
    BaseType_t res;
    return res;
}

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

    __CPROVER_assume(buff.xDataLength < 10);

    buff.pucEthernetBuffer = malloc(buff.xDataLength);

    // Allocated data will not be NULL

    __CPROVER_assume(buff.pucEthernetBuffer != NULL);

    eFrameProcessingResult_t res = prvProcessIPPacket( &pack, &buff );
}
