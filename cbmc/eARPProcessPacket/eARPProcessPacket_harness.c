/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdlib.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

extern NetworkBufferDescriptor_t *pxARPWaitingNetworkBuffer;

NetworkBufferDescriptor_t * pxGetNetworkBufferWithDescriptor( size_t xRequestedSizeBytes, TickType_t xBlockTimeTicks ) {

    // Create the buffer struct:

    NetworkBufferDescriptor_t* buff = (NetworkBufferDescriptor_t*)malloc(sizeof(NetworkBufferDescriptor_t));

    // Determine if we should model the data:

    if (buff != NULL) {

        // Determine if we should increase the allocation size:

        size_t size = xRequestedSizeBytes;

        buff->xDataLength = xRequestedSizeBytes;
        buff->pucEthernetBuffer = malloc(size);

        __CPROVER_assume(buff->pucEthernetBuffer != NULL);
    }

    return buff;
}

BaseType_t dummy(struct xNetworkInterface *pxDescriptor, NetworkBufferDescriptor_t *const pxNetworkBuffer, BaseType_t xReleaseAfterSend) {}

/**
 * @brief Function to check whether the current context belongs to
 *        the IP-task.
 *
 * @return If the current context belongs to the IP-task, then pdTRUE is
 *         returned. Else pdFALSE is returned.
 *
 * @note Very important: the IP-task is not allowed to call its own API's,
 *        because it would easily get into a dead-lock.
 */
BaseType_t xIsCallingFromIPTask(void)
{

    BaseType_t xReturn;

    return xReturn;
}

/**
 * @brief Checks if the IP address matches the global 255.255.255.255 broadcast address or
 * the broadcast address for any of our IPv4 endpoints.
 *
 * @param[in] ulIPAddress The IP address being checked.
 *
 * @param[out] ppxEndPoint Pointer to an end-point where we store the endpoint whose broadcast address we matched. Or NULL if no IPv4 endpoints were found.
 *
 * @return pdTRUE if the IP address is a broadcast address or else, pdFALSE.
 */
BaseType_t xIsIPv4Broadcast( uint32_t ulIPAddress, struct xNetworkEndPoint ** ppxEndPoint ) {

    BaseType_t res;

    return res;
}

/**
 * @brief Find the end-point which has a given IPv4 address.
 *
 * @param[in] ulIPAddress The IP-address of interest, or 0 if any IPv4 end-point may be returned.
 *
 * @return The end-point found or NULL.
 */
NetworkEndPoint_t *FreeRTOS_FindEndPointOnIP_IPv4(uint32_t ulIPAddress)
{
    NetworkEndPoint_t *pxEndPoint = (NetworkEndPoint_t*)malloc(sizeof(NetworkEndPoint_t));

    if (pxEndPoint != NULL) {
        // Allocate the network interface:

        pxEndPoint->pxNetworkInterface = (NetworkInterface_t *)malloc(sizeof(NetworkInterface_t));

        if (pxEndPoint->pxNetworkInterface != NULL) {
            // Assign a dummy callback:

            pxEndPoint->pxNetworkInterface->pfOutput = dummy;
        }
    }

    return pxEndPoint;
}

/**
 * @brief Get the next end-point.  The parameter 'pxInterface' may be NULL, which means:
 *        don't care which interface the end-point is bound to.
 *
 * @param[in] pxInterface An interface of interest, or NULL when iterating through all
 *                         end-points.
 * @param[in] pxEndPoint This is the current end-point.
 *
 * @return The end-point that is found, or NULL when there are no more end-points in the list.
 */
NetworkEndPoint_t *FreeRTOS_NextEndPoint(const NetworkInterface_t *pxInterface,
                                         NetworkEndPoint_t *pxEndPoint)
{
    return FreeRTOS_FindEndPointOnIP_IPv4(0);
}

/**
 * @brief Find the first end-point bound to a given interface.
 *
 * @param[in] pxInterface The interface whose first end-point will be returned.
 *
 * @return The first end-point that is found to the interface, or NULL when the
 *         interface doesn't have any end-point yet.
 */
NetworkEndPoint_t *FreeRTOS_FirstEndPoint(const NetworkInterface_t *pxInterface)
{
    return FreeRTOS_FindEndPointOnIP_IPv4(0);
}

/**
 * @brief Find an end-point that defines a gateway of a certain type ( IPv4 or IPv6 ).
 *
 * @param[in] xIPType The type of Gateway to look for ( ipTYPE_IPv4 or ipTYPE_IPv6 ).
 *
 * @return The end-point that will lead to the gateway, or NULL when no gateway was found.
 */
NetworkEndPoint_t *FreeRTOS_FindGateWay(BaseType_t xIPType)
{
    return FreeRTOS_FindEndPointOnIP_IPv4(0);
}

/**
 * @brief Find an end-point that handles a given IPv4-address.
 *
 * @param[in] ulIPAddress The IP-address for which an end-point is looked-up.
 *
 * @return An end-point that has the same network mask as the given IP-address.
 */
NetworkEndPoint_t *FreeRTOS_FindEndPointOnNetMask(uint32_t ulIPAddress)
{
    return FreeRTOS_FindEndPointOnIP_IPv4(0);
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Model awaiting buffer:

    NetworkBufferDescriptor_t buff;

    // Size must be at lest ARPPacket_t

    __CPROVER_assume(buff.xDataLength >= sizeof(ARPPacket_t));

    buff.pucEthernetBuffer = malloc(buff.xDataLength);

    __CPROVER_assume(buff.pucEthernetBuffer != NULL);  // WIll NOT be NULL

    // Properly allocate the px endpoint:

    buff.pxEndPoint = FreeRTOS_FindEndPointOnIP_IPv4(0);

    // Model global buffer

    pxARPWaitingNetworkBuffer = (NetworkBufferDescriptor_t*)malloc(sizeof(NetworkBufferDescriptor_t));

    if (pxARPWaitingNetworkBuffer != NULL) {

        // Size must at least contain ip packet:

        __CPROVER_assume(pxARPWaitingNetworkBuffer->xDataLength >= sizeof(IPPacket_t));

        // Allocate data of size

        pxARPWaitingNetworkBuffer->pucEthernetBuffer = malloc(pxARPWaitingNetworkBuffer->xDataLength);

        // Allocated data will not be NULL

        __CPROVER_assume(pxARPWaitingNetworkBuffer->pucEthernetBuffer != NULL);
    }

    eFrameProcessingResult_t res = eARPProcessPacket(&buff);
}
