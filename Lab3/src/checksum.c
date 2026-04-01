#include "checksum.h"

uint8_t calculate_checksum(uint8_t *buffer, uint8_t buffer_length) 
{
    uint16_t result_checksum = 0;
    uint8_t loop_index = 0;

    for (loop_index = 0; loop_index < buffer_length; loop_index ++) 
    {
        result_checksum += buffer[loop_index ];
    }
    return (uint8_t)(result_checksum % 256); 
}