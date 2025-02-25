/**
 * @file _harness.c
 * @brief TODO
 */

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"

BaseType_t xSequenceLessThan( uint32_t a, uint32_t b )
{
    BaseType_t xResult;

    return xResult;
}

BaseType_t xSequenceGreaterThan( uint32_t a,
    uint32_t b )
{
    BaseType_t xResult;

    return xResult;
}

TickType_t prvTCPNextTimeout( FreeRTOS_Socket_t * pxSocket ) {
    TickType_t val;
    return val;
}

void prvTCPTouchSocket( FreeRTOS_Socket_t * pxSocket ) {}

void vTCPStateChange( FreeRTOS_Socket_t * pxSocket,
                        enum eTCP_STATE eTCPState ) {}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Create a network buffer

    NetworkBufferDescriptor_t buff;

    __CPROVER_assume(buff.xDataLength < 1);

    // Allocate some data:

    // buff.pucEthernetBuffer = malloc(buff.xDataLength);

    buff.pucEthernetBuffer = NULL;

    // Data will not be NULL

    // __CPROVER_assume(buff.pucEthernetBuffer != NULL);

    BaseType_t res = xProcessReceivedTCPPacket( &buff );
}
