#include "unity.h"
#include "battery.h"
#include "Mockadc.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/**
 * @brief Verify 100% battery.
 */
void test_battery_percentage_full(void)
{
    adc_read_battery_mv_ExpectAndReturn(4200);

    TEST_ASSERT_EQUAL_UINT8(
        100,
        battery_get_percentage());
}

/**
 * @brief Verify 50% battery.
 */
void test_battery_percentage_half(void)
{
    adc_read_battery_mv_ExpectAndReturn(3700);

    TEST_ASSERT_EQUAL_UINT8(
        50,
        battery_get_percentage());
}

/**
 * @brief Verify empty battery.
 */
void test_battery_percentage_empty(void)
{
    adc_read_battery_mv_ExpectAndReturn(3200);

    TEST_ASSERT_EQUAL_UINT8(
        0,
        battery_get_percentage());
}

/**
 * @brief Verify critical battery.
 */
void test_battery_health_critical(void)
{
    adc_read_battery_mv_ExpectAndReturn(3250);

    TEST_ASSERT_EQUAL(
        BATTERY_HEALTH_CRITICAL,
        battery_get_health());
}

/**
 * @brief Verify low battery.
 */
void test_battery_health_low(void)
{
    // TEST_IGNORE();
    adc_read_battery_mv_ExpectAndReturn(3400);

    TEST_ASSERT_EQUAL(
        BATTERY_HEALTH_LOW,
        battery_get_health());
}

/**
 * @brief Verify good battery.
 */
void test_battery_health_good(void)
{
    // TEST_IGNORE();
    adc_read_battery_mv_ExpectAndReturn(3900);

    TEST_ASSERT_EQUAL(
        BATTERY_HEALTH_GOOD,
        battery_get_health());
}