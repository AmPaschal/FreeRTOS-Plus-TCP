/**
 * @file _harness.c
 * @brief TODO
 */

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

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
 * @brief Dummy socket send callback
 * 
 * Removes function pointer violation
 * 
 * @param xSocket 
 * @param xLength 
 */
void sock_call( Socket_t xSocket, size_t xLength ) {}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Define some data size:

    size_t size;

    // A well-formed option MUST be at least two bytes
    // Or, it must be a single byte specifying the end of an option
    // We get out of bounds errors when this is not enforced
    // Potential vulnerability?

    __CPROVER_assume(size >= 1);

    // Allocate some data:

    uint8_t* data = (uint8_t*)malloc(size);

    // No NULL checks present, data will NOT be NULL:

    __CPROVER_assume(data != NULL);

    // Model other input types:

    FreeRTOS_Socket_t pxSocket;
    BaseType_t xHasSYNFlag;

    // Add function pointer to dummy callback:

    pxSocket.u.xTCP.pxHandleSent = sock_call;

    int32_t res = prvSingleStepTCPHeaderOptions( data, size, &pxSocket, xHasSYNFlag);
}
