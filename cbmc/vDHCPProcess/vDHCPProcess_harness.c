/**
 * @file vDHCPProcess_harness.c
 * @brief TODO
 */

#include <stdlib.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_DHCP.h"

int32_t FreeRTOS_recvfrom( const ConstSocket_t xSocket, void * pvBuffer, size_t uxBufferLength, BaseType_t xFlags, struct freertos_sockaddr * pxSourceAddress, const socklen_t * pxSourceAddressLength ) {

    // Allocate some data of size:

    int32_t size;

    // __CPROVER_assume(size <= 100);

    // Allocate some data:

    void *data = malloc(size);

    // Data won't be NULL:

    __CPROVER_assume(data != NULL);

    // Set the destination buffer

    *((void **)pvBuffer) = data;

    return size;
}

NetworkBufferDescriptor_t * pxGetNetworkBufferWithDescriptor( size_t xRequestedSizeBytes, TickType_t xBlockTimeTicks ) {

    // Create a network buffer instance:

    NetworkBufferDescriptor_t *buff = (NetworkBufferDescriptor_t *)malloc(sizeof(NetworkBufferDescriptor_t));

    __CPROVER_assume(buff != NULL);

    // Allocate some data of size:

    buff->pucEthernetBuffer = malloc(xRequestedSizeBytes);
    buff->xDataLength = xRequestedSizeBytes;

    __CPROVER_assume(buff->pucEthernetBuffer != NULL);

    return buff;
}

const char *pcApplicationHostnameHook(void)
{

    return "hostname";
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    BaseType_t xReset;

    eDHCPState_t eExpectedState;

    vDHCPProcess(xReset, eExpectedState);
}
