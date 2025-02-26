/**
 * @file _harness.c
 * @brief TODO
 */

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"

// BaseType_t xSequenceLessThan( uint32_t a, uint32_t b )
// {
//     BaseType_t xResult;

//     return xResult;
// }

// BaseType_t xSequenceGreaterThan( uint32_t a,
//     uint32_t b )
// {
//     BaseType_t xResult;

//     return xResult;
// }

// TickType_t prvTCPNextTimeout( FreeRTOS_Socket_t * pxSocket ) {
//     TickType_t val;
//     return val;
// }

FreeRTOS_Socket_t * pxTCPSocketLookup( uint32_t ulLocalIP,
                                    UBaseType_t uxLocalPort,
                                    uint32_t ulRemoteIP,
                                    UBaseType_t uxRemotePort ) {
    FreeRTOS_Socket_t *socket = malloc(sizeof(FreeRTOS_Socket_t));

    FreeRTOS_Socket_t *peerSocket = malloc(sizeof(FreeRTOS_Socket_t));

    __CPROVER_assume(peerSocket != NULL);

    if (socket != NULL) {
        socket->u.xTCP.pxPeerSocket = peerSocket;
    }

    return socket;
}

FreeRTOS_Socket_t * prvHandleListen( FreeRTOS_Socket_t * pxSocket,
    NetworkBufferDescriptor_t * pxNetworkBuffer ) {
        FreeRTOS_Socket_t *socket = malloc(sizeof(FreeRTOS_Socket_t));

        FreeRTOS_Socket_t *peerSocket = malloc(sizeof(FreeRTOS_Socket_t));

        __CPROVER_assume(peerSocket != NULL);

        if (socket != NULL) {
            socket->u.xTCP.pxPeerSocket = peerSocket;
        }

        return socket;
    }

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Create a network buffer

    NetworkBufferDescriptor_t buff;

    size_t dataLength;

    __CPROVER_assume(dataLength > ipSIZE_OF_ETH_HEADER + xIPHeaderSize( pxNetworkBuffer ) + sizeof(ProtocolHeaders_t));

    // Allocate some data:

    buff.pucEthernetBuffer = malloc(dataLength);
    __CPROVER_assume(buff.pucEthernetBuffer != NULL);

    buff.xDataLength = dataLength;

    // Data will not be NULL

    // __CPROVER_assume(buff.pucEthernetBuffer != NULL);

    BaseType_t res = xProcessReceivedTCPPacket( &buff );
}
