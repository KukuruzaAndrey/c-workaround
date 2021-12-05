#include "Core.h"
#include "unity.h"
#include "cmock.h"
#include "MockLED.h"
#include "Main.h"

void test_Main_Should_InitializeLedDriver(void) {
    LED_Init_Expect();
    TEST_ASSERT_EQUAL(0, TestableMain());
}