#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define LEDMASKC 0b0000000001001100
#define LEDMASKB 0b0000000010000001
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut ledsC(PortC, LEDMASKC);

PortOut ledsB(PortB, LEDMASKB);

DigitalOut light1(PB_0);
DigitalOut light2(PB_7);
DigitalOut light3(PB_14);


int main()
{

    while (true) {
        //light3 = 0;
        ledsB = ledsB ^ LEDMASKB;
        ledsC = ledsC ^ LEDMASKC;  
        wait_us(500000);
  
    }
}




