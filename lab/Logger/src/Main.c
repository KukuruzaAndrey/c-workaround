#include "Core.h"
#include "Main.h"
#include "LED.h"

#ifndef TEST
int main(void)
#else
int TestableMain(void)
#endif
{
    LED_Init();
    return 0;
}
