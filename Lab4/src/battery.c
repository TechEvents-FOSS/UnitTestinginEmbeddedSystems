#include "battery.h"
#include "adc.h"

/**
 * @brief Convert battery voltage into percentage.
 *
 * Assumes:
 * 3200mV = 0%
 * 4200mV = 100%
 *
 * @param mv Battery voltage.
 *
 * @return Battery percentage.
 */
static uint8_t battery_voltage_to_percent(uint16_t mv)
{
    if(mv <= 3200)
    {
        return 0;
    }
    else if(mv >= 4200)
    {
        return 100;
    }

    return (uint8_t)(((mv - 3200U) * 100U) / 1000U);
}

/**
 * @brief Get battery percentage.
 *
 * Reads battery voltage using ADC and converts
 * it into percentage.
 *
 * @return Battery percentage.
 */
uint8_t battery_get_percentage(void)
{
    uint16_t voltage = adc_read_battery_mv();

    return battery_voltage_to_percent(voltage);
}

/**
 * @brief Get battery health.
 *
 * GOOD      > 25%
 * LOW       <=25%
 * CRITICAL  <=10%
 *
 * @return Battery health status.
 */
battery_health_t battery_get_health(void)
{
    uint8_t percentage = battery_get_percentage();

    if(percentage <= 10U)
    {
        return BATTERY_HEALTH_CRITICAL;
    }

    if(percentage <= 25U)
    {
        return BATTERY_HEALTH_LOW;
    }

    return BATTERY_HEALTH_GOOD;
}