#ifndef BATTERY_H
#define BATTERY_H

#include <stdint.h>

typedef enum
{
    BATTERY_HEALTH_GOOD = 0,
    BATTERY_HEALTH_LOW,
    BATTERY_HEALTH_CRITICAL
} battery_health_t;

/**
 * @brief Get battery percentage.
 *
 * @return Percentage between 0 and 100.
 */
uint8_t battery_get_percentage(void);

/**
 * @brief Determine battery health state.
 *
 * @return Battery health status.
 */
battery_health_t battery_get_health(void);

#endif /* BATTERY_H */