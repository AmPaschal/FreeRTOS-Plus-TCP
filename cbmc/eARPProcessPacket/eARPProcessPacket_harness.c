/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdlib.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

extern NetworkBufferDescriptor_t * pxARPWaitingNetworkBuffer;

NetworkBufferDescriptor_t * pxGetNetworkBufferWithDescriptor( size_t xRequestedSizeBytes, TickType_t xBlockTimeTicks ) {

    // Create the buffer struct:

    NetworkBufferDescriptor_t* buff = (NetworkBufferDescriptor_t*)malloc(sizeof(NetworkBufferDescriptor_t));

    // Determine if we should model the data:

    if (buff != NULL) {

        // Determine if we should increase the allocation size:

        size_t size = xRequestedSizeBytes;

        if (xRequestedSizeBytes < ipconfigETHERNET_MINIMUM_PACKET_BYTES) {

            // Increase to new size:
            
            size = ipconfigETHERNET_MINIMUM_PACKET_BYTES;
        }

        buff->xDataLength = xRequestedSizeBytes;
        buff->pucEthernetBuffer = malloc(size);

        __CPROVER_assume(buff->pucEthernetBuffer != NULL);
    }

    return buff;
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Model input arguments:

    ARPPacket_t pack;

    // Model awaiting buffer:

    pxARPWaitingNetworkBuffer = (NetworkBufferDescriptor_t*)malloc(sizeof(NetworkBufferDescriptor_t));

    if (pxARPWaitingNetworkBuffer != NULL) {

        // Determine if we are too low:

        size_t size = pxARPWaitingNetworkBuffer->xDataLength;

        if (pxARPWaitingNetworkBuffer->xDataLength < ipconfigETHERNET_MINIMUM_PACKET_BYTES) {
            size = ipconfigETHERNET_MINIMUM_PACKET_BYTES;
        }

        // Size must at least be IPPacket_t

        __CPROVER_assume(pxARPWaitingNetworkBuffer->xDataLength >= sizeof(IPPacket_t));  // Potential vulnerability 

        pxARPWaitingNetworkBuffer->pucEthernetBuffer = malloc(size);

        __CPROVER_assume(pxARPWaitingNetworkBuffer->pucEthernetBuffer != NULL);  // WIll NOT be NULL
    }

    eFrameProcessingResult_t res = eARPProcessPacket(&pack);
}
