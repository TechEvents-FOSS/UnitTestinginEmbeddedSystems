#include "adc.h"

/**
 * @brief Read ADC value and convert to millivolts.
 *
 * In real firmware this function would read
 * from ADC hardware registers and convert to mv.
 */
uint16_t adc_read_battery_mv(void)
{
    return 3700;
}