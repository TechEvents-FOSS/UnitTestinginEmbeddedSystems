#ifndef ADC_H
#define ADC_H

#include <stdint.h>

/**
 * @brief Read battery voltage from ADC.
 *
 * @return Battery voltage in millivolts.
 */
uint16_t adc_read_battery_mv(void);

#endif /* ADC_H */