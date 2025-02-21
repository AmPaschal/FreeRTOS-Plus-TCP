/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdint.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"

/**
 * @brief Convert character array (of size 2) to equivalent 16-bit value.
 * @param[in] pucPtr: The character array.
 * @return 16-bit equivalent value extracted from the character array.
 *
 * @note Going by MISRA rules, these utility functions should not be defined
 *        if they are not being used anywhere. But their use depends on the
 *        application and hence these functions are defined unconditionally.
 */
uint16_t usChar2u16( const uint8_t * pucPtr )
{
    // Read two values to check for out of bounds access:

    uint8_t first = *pucPtr;
    uint8_t second = *(pucPtr+1);

    // Just return an unconstrained 16bit int:

    uint16_t res;

    return res;    
}

/**
 * @brief Convert character array (of size 4) to equivalent 32-bit value.
 * @param[in] pucPtr: The character array.
 * @return 32-bit equivalent value extracted from the character array.
 *
 * @note Going by MISRA rules, these utility functions should not be defined
 *        if they are not being used anywhere. But their use depends on the
 *        application and hence these functions are defined unconditionally.
 */
uint32_t ulChar2u32( const uint8_t * pucPtr )
{

    // Read four values to check for out of bounds read:

    uint8_t first = *pucPtr;
    uint8_t second = *(pucPtr+1);
    uint8_t third = *(pucPtr+2);
    uint8_t fourth = *(pucPtr+3);

    uint32_t res;

    return res;
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Model socket:

    FreeRTOS_Socket_t pxSocket;

    // Model network buffer:

    NetworkBufferDescriptor_t pxNetworkBuffer;

    // Allocate data of size:

    pxNetworkBuffer.pucEthernetBuffer = malloc(pxNetworkBuffer.xDataLength);

    // Data will NOT be NULL

    __CPROVER_assume(pxNetworkBuffer.pucEthernetBuffer != NULL);

    BaseType_t res = prvCheckOptions(&pxSocket, &pxNetworkBuffer );
}
