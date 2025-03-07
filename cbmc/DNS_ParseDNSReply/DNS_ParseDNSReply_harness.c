/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdint.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

#include "task.h"

#include "FreeRTOS_DNS.h"

uint32_t DNS_ParseDNSReply( uint8_t * pucUDPPayloadBuffer,
    size_t uxBufferLength,
    struct freertos_addrinfo ** ppxAddressInfo,
    BaseType_t xExpected,
    uint16_t usPort );

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    size_t bufferLength;

    uint8_t *buffer = malloc(bufferLength);
    __CPROVER_assume(buffer != NULL);

    struct freertos_addrinfo *addressInfo = malloc(sizeof(struct freertos_addrinfo));

    BaseType_t xExpected;

    uint16_t usPort;


    DNS_ParseDNSReply(buffer, bufferLength, addressInfo, xExpected, usPort);
}
