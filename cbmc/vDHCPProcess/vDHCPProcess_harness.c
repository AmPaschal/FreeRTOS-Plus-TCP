/**
 * @file vDHCPProcess_harness.c
 * @brief TODO
 */

#include <stdlib.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Routing.h"
#include "FreeRTOS_DHCP.h"
 
extern struct xNetworkEndPoint *pxNetworkEndPoints;  // Endpoints to utilize
extern Socket_t xDHCPv4Socket;  // Global socket to utilize
extern BaseType_t xDHCPSocketUserCount;

void dummy(struct xNetworkInterface *pxInterface, const uint8_t *pucMacAddressBytes) {}

void FreeRTOS_ReleaseUDPPayloadBuffer(void const *pvBuffer) {}

int32_t FreeRTOS_recvfrom( const ConstSocket_t xSocket, void * pvBuffer, size_t uxBufferLength, BaseType_t xFlags, struct freertos_sockaddr * pxSourceAddress, const socklen_t * pxSourceAddressLength ) {

    // Allocate some data of size:

    int32_t size;

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

    if (buff != NULL) {

        // Determine offset value

        uint32_t off = 100;

        // Allocate some data of size:

        buff->pucEthernetBuffer = malloc(xRequestedSizeBytes + 100);
        buff->xDataLength = xRequestedSizeBytes;

        __CPROVER_assume(buff->pucEthernetBuffer != NULL);

        // Now, move the buffer 100 positions forward:

        buff->pucEthernetBuffer += off;
        buff->xDataLength -= off;
    }

    return buff;
}

const char *pcApplicationHostnameHook(void)
{

    return "hostname";
}

BaseType_t xApplicationGetRandomNumber(uint32_t *pulNumber) {

    BaseType_t res;

    uint32_t val;

    *pulNumber = val;

    return res;
}

TickType_t xTaskGetTickCount(void)
{
    TickType_t xReturn;

    return xReturn;
}

/**
 * @brief allocate and initialise a socket.
 *
 * @param[in] xDomain The domain in which the socket should be created.
 * @param[in] xType The type of the socket.
 * @param[in] xProtocol The protocol of the socket.
 *
 * @return FREERTOS_INVALID_SOCKET if the allocation failed, or if there was
 *         a parameter error, otherwise a valid socket.
 */
Socket_t FreeRTOS_socket( BaseType_t xDomain, BaseType_t xType, BaseType_t xProtocol ) {

    // Create socket

    Socket_t sock = malloc(sizeof(struct xSOCKET));

    return sock;
}

/**
 * @brief Check whether a given socket is valid or not. Validity is defined
 *        as the socket not being NULL and not being Invalid.
 * @param[in] xSocket The socket to be checked.
 * @return pdTRUE if the socket is valid, else pdFALSE.
 *
 */
BaseType_t xSocketValid(const ConstSocket_t xSocket)
{
    BaseType_t xReturnValue = pdFALSE;

    /*
     * There are two values which can indicate an invalid socket:
     * FREERTOS_INVALID_SOCKET and NULL.  In order to compare against
     * both values, the code cannot be compliant with rule 11.4,
     * hence the Coverity suppression statement below.
     */

    /* MISRA Ref 11.4.1 [Socket error and integer to pointer conversion] */
    /* More details at: https://github.com/FreeRTOS/FreeRTOS-Plus-TCP/blob/main/MISRA.md#rule-114 */
    /* coverity[misra_c_2012_rule_11_4_violation] */
    if ((xSocket != FREERTOS_INVALID_SOCKET) && (xSocket != NULL))
    {
        xReturnValue = pdTRUE;
    }

    return xReturnValue;
}

/**
 * @brief Send data to a socket. The socket must have already been created by a
 *        successful call to FreeRTOS_socket(). It works for UDP-sockets only.
 *
 * @param[in] xSocket The socket being sent to.
 * @param[in] pvBuffer Pointer to the data being sent.
 * @param[in] uxTotalDataLength Length (in bytes) of the data being sent.
 * @param[in] xFlags Flags used to communicate preferences to the function.
 *                    Possibly FREERTOS_MSG_DONTWAIT and/or FREERTOS_ZERO_COPY.
 * @param[in] pxDestinationAddress The address to which the data is to be sent.
 * @param[in] xDestinationAddressLength This parameter is present to adhere to the
 *                  Berkeley sockets standard. Else, it is not used.
 *
 * @return When positive: the total number of bytes sent, when negative an error
 *         has occurred: it can be looked-up in 'FreeRTOS-Kernel/projdefs.h'.
 */
int32_t FreeRTOS_sendto( Socket_t xSocket, const void * pvBuffer, size_t uxTotalDataLength, BaseType_t xFlags, const struct freertos_sockaddr * pxDestinationAddress, socklen_t xDestinationAddressLength ) {
    int32_t res;
    return res;
}

/**
 * @brief Returns the IP type of the given IPv6 address.
 *
 * @param[in] pxAddress The IPv6 address whose type needs to be returned.
 * @returns The IP type of the given address.
 */
IPv6_Type_t xIPv6_GetIPType( const IPv6_Address_t * pxAddress ) {
    
    // Return unconstrained value:

    IPv6_Type_t res;

    return res;
}

/**
 * @brief Models an endpoint struct
 *
 * We do the following:
 * 1. Allocate xNetworkEndPoint struct
 * 2. Properly model socket endpoint, won't be NULL
 * 3. Model endpoint in socket, won't be NULL
 * 4. Allocate network interface, won't be NULL
 *
 * @return struct xNetworkEndPoint*
 */
struct xNetworkEndPoint* create_endpoint() {

    // Allocate network endpoint struct

    struct xNetworkEndPoint *endpoint = (struct xNetworkEndPoint *)malloc(sizeof(struct xNetworkEndPoint));

    // Determine if we should model sub components

    if (endpoint != NULL) {

        // Make next value NULL

        endpoint->pxNext = NULL;

        // Properly model socket endpoint

        endpoint->xDHCPData.xDHCPSocket = (Socket_t)malloc(sizeof(struct xSOCKET));

        // Allocated data won't be NULL

        __CPROVER_assume(endpoint->xDHCPData.xDHCPSocket != NULL);

        // Properly model socket endpoint

        endpoint->xDHCPData.xDHCPSocket->pxEndPoint = (struct xNetworkEndPoint *)malloc(sizeof(struct xNetworkEndPoint));

        // Allocated endpoint won't be NULL

        __CPROVER_assume(endpoint->xDHCPData.xDHCPSocket->pxEndPoint != NULL);

        // Model network interface

        endpoint->pxNetworkInterface = (NetworkInterface_t *)malloc(sizeof(NetworkInterface_t));

        // interface won't be NULL

        __CPROVER_assume(endpoint->pxNetworkInterface != NULL);

        // Assign dummy callback function

        endpoint->pxNetworkInterface->pfAddAllowedMAC = dummy;
    }

    return endpoint;
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Model input arguments

    BaseType_t xReset;

    // Create network endpoint

    struct xNetworkEndPoint* endpoint = create_endpoint();

    // Will not be NULL

    __CPROVER_assume(endpoint != NULL);

    // Model global arguments:

    pxNetworkEndPoints = create_endpoint();

    // Allocate the socket

    xDHCPv4Socket = (Socket_t)malloc(sizeof(struct xSOCKET));

    // Set user count to zero

    xDHCPSocketUserCount = 0;

    vDHCPProcess(xReset, endpoint);
}
