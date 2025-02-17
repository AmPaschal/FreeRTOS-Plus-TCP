/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdlib.h>

#include "FreeRTOS.h"

#include "task.h"

#include "FreeRTOS_DNS.h"

uint16_t usChar2u16( const uint8_t * pucPtr ) {

    // Read the current and next value:

    uint8_t first = *pucPtr;
    uint8_t second = *(pucPtr + 1);

    // Return unconstrained size:

    uint16_t size;

    return size;
}

/**
 * @brief Read the Name field out of a DNS response packet.
 *
 * @param[in] pucByte: Pointer to the DNS response.
 * @param[in] uxRemainingBytes: Length of the DNS response.
 * @param[out] pcName: The pointer in which the name in the DNS response will be returned.
 * @param[in] uxDestLen: Size of the pcName array.
 *
 * @return If a fully formed name was found, then return the number of bytes processed in pucByte.
 */
size_t DNS_ReadNameField(const uint8_t *pucByte,
                         size_t uxRemainingBytes,
                         char *pcName,
                         size_t uxDestLen)
{

    // Determine an offset:

    size_t offset;

    // Offset MUST be less than or equal to total size:

    __CPROVER_assume(offset <= uxRemainingBytes);

    // Offset must also be smaller than destination:

    __CPROVER_assume(uxDestLen >= offset);

    // Copy values over into new destination:

    memcpy(pcName, pucByte, offset);

    // Return the offset:

    return offset;
}

/**
 * @brief Simple routine that jumps over the NAME field of a resource record.
 *
 * @param[in] pucByte: The pointer to the resource record.
 * @param[in] uxLength: Length of the resource record.
 *
 * @return It returns the number of bytes read, or zero when an error has occurred.
 */
size_t DNS_SkipNameField(const uint8_t *pucByte,
                         size_t uxLength)
{

    // Determine the offset:

    size_t offset;

    // Ensure the size does not exceed the maximum:

    __CPROVER_assume(offset <= uxLength);

    return offset;
}

/**
 * @brief Get the network buffer from the UDP Payload buffer.
 *
 * @param[in] pvBuffer: Pointer to the UDP payload buffer.
 *
 * @return The network buffer if the alignment is correct. Else a NULL is returned.
 */
NetworkBufferDescriptor_t *pxUDPPayloadBuffer_to_NetworkBuffer(const void *pvBuffer)
{
    NetworkBufferDescriptor_t* buff = malloc(sizeof(NetworkBufferDescriptor_t));

    if (buff != NULL) {

        buff->xDataLength = sizeof(UDPPacket_t);
        buff->pucEthernetBuffer = malloc(buff->xDataLength);

        __CPROVER_assume(buff->pucEthernetBuffer != NULL);
    }

    return buff;
}

/**
 * @brief Duplicate the given network buffer descriptor with a modified length.
 *
 * @param[in] pxNetworkBuffer: The network buffer to be duplicated.
 * @param[in] uxNewLength: The length for the new buffer.
 *
 * @return If properly duplicated, then the duplicate network buffer or else, NULL.
 */
NetworkBufferDescriptor_t *pxDuplicateNetworkBufferWithDescriptor(const NetworkBufferDescriptor_t *const pxNetworkBuffer,
                                                                  size_t uxNewLength)
{
    NetworkBufferDescriptor_t *buff = malloc(sizeof(NetworkBufferDescriptor_t));

    // Determine if we should model parameters:

    if (buff != NULL) {

        buff->xDataLength = uxNewLength;
        buff->pucEthernetBuffer = malloc(buff->xDataLength);

        __CPROVER_assume(buff->pucEthernetBuffer != NULL);
    }

    return buff;
}

/**
 * @brief Calculates the 16-bit checksum of an array of bytes
 *
 * @param[in] usSum: The initial sum, obtained from earlier data.
 * @param[in] pucNextData: The actual data.
 * @param[in] uxByteCount: The number of bytes.
 *
 * @return The 16-bit one's complement of the one's complement sum of all 16-bit
 *         words in the header
 */
uint16_t usGenerateChecksum(uint16_t usSum,
                            const uint8_t *pucNextData,
                            size_t uxByteCount)
{

    uint16_t sum;

    return sum;
}

/**
 * @brief Generate or check the protocol checksum of the data sent in the first parameter.
 *        At the same time, the length of the packet and the length of the different layers
 *        will be checked.
 *
 * @param[in] pucEthernetBuffer: The Ethernet buffer for which the checksum is to be calculated
 *                               or checked.
 * @param[in] uxBufferLength: the total number of bytes received, or the number of bytes written
 *                            in the packet buffer.
 * @param[in] xOutgoingPacket: Whether this is an outgoing packet or not.
 *
 * @return When xOutgoingPacket is false: the error code can be either: ipINVALID_LENGTH,
 *         ipUNHANDLED_PROTOCOL, ipWRONG_CRC, or ipCORRECT_CRC.
 *         When xOutgoingPacket is true: either ipINVALID_LENGTH, ipUNHANDLED_PROTOCOL,
 *         or ipCORRECT_CRC.
 */
uint16_t usGenerateProtocolChecksum(uint8_t *pucEthernetBuffer,
                                    size_t uxBufferLength,
                                    BaseType_t xOutgoingPacket)
{
    uint16_t sum;

    return sum;
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    NetworkBufferDescriptor_t buff;

    // Constrain the size:

    __CPROVER_assume(buff.xDataLength <= 200);

    // Allocate input data:

    buff.pucEthernetBuffer = malloc(buff.xDataLength);

    __CPROVER_assume(buff.pucEthernetBuffer != NULL);

    uint32_t res = ulDNSHandlePacket(&buff);
}
