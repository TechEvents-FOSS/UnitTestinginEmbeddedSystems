#include "checksum.h"
#include <stddef.h>

uint8_t calculate_checksum(uint8_t *buffer, uint8_t buffer_length) 
{
    if (buffer == NULL || buffer_length == 0) {
        return 0; // Return 0 for null buffer or zero length
    }

    uint16_t result_checksum = 0;
    uint8_t loop_index = 0;

    for (loop_index = 0; loop_index < buffer_length; loop_index ++) 
    {
        result_checksum += buffer[loop_index ];
    }
    return (uint8_t)(result_checksum % 256); 
}