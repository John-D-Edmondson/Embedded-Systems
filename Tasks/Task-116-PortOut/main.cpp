#include "mbed.h"
#include "uop_msb.h"
using namespace uop_msb;

PortOut lights(PortC, 0b0000000001001100);
Buttons buttons;

int main()
{
    //All OFF
    lights = 0;

    while (true)
    {
//         	a	RED+YELLOW
// b	YELLOW+GREEN
// c	RED + GREEN
        lights = 0b0000000000001100;
        wait_us(1000000);
        lights = 0b0000000001001000;
        wait_us(1000000);
        lights = 0b0000000001000100;
        wait_us(1000000);                
    }
}