#include "checksum.h"
#include "unity.h"

void setUp(void) 
{
    /* This function is called before each test case. 
    You can use it to set up any common test data or state. */
}

void tearDown(void) 
{
    /* This function is called after each test case. 
    You can use it to clean up any resources allocated in setUp or during the test. */
}

void test_calculate_checksum_with_valid_data(void) {
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04};
    uint8_t expected_checksum = 10;  // (0x01 + 0x02 + 0x03 + 0x04) % 256 = 10
    uint8_t actual_checksum = calculate_checksum(data, sizeof(data));
    TEST_ASSERT_EQUAL_UINT8(expected_checksum, actual_checksum);
}

void test_calculate_checksum_with_empty_data(void) {
    uint8_t data[] = {};
    uint8_t expected_checksum = 0;
    uint8_t actual_checksum = calculate_checksum(data, sizeof(data));
    TEST_ASSERT_EQUAL_UINT8(expected_checksum, actual_checksum);
}

void test_calculate_checksum_with_max_values(void) {
    uint8_t data[] = {0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t expected_checksum = 252;  // (0xFF + 0xFF + 0xFF + 0xFF) % 256 = 252
    uint8_t actual_checksum = calculate_checksum(data, sizeof(data));
    TEST_ASSERT_EQUAL_UINT8(expected_checksum, actual_checksum);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_calculate_checksum_with_valid_data);
    RUN_TEST(test_calculate_checksum_with_empty_data);
    RUN_TEST(test_calculate_checksum_with_max_values);
    return UNITY_END();
}

