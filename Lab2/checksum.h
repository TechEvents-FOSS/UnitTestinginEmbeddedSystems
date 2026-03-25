/**
 * @file checksum.h
 * @brief Header file contains the declarations for checksum module
 * 
 */

 #ifndef CHECKSUM_H
#define CHECKSUM_H

#include <stdint.h>

/**
 * @brief Function to calculate the checksum of a given buffer of data. 
 * The checksum is computed by summing all the bytes in the buffer and taking the result modulo 256.
 * 
 * @param buffer Buffer of data for which the checksum is to be calculated.
 * @param length Length of the buffer.
 * @return uint8_t The calculated checksum result.
 */
uint8_t calculate_checksum(uint8_t *buffer, uint8_t length);

#endif