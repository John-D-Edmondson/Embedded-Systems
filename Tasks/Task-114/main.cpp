#include "mbed.h"

DigitalOut redLED(PC_2,1);
DigitalOut yellowLED(PC_3,1);
DigitalOut greenLED(PC_6,1);
BusOut trafficLights(PC_2, PC_3,PC_6);
int wait_ms = 2000;

// main() runs in its own thread in the OS
int main()
{
    trafficLights = 7; // all on
    wait_us(wait_ms *5000); //wait 10s all lights on

 //   -	RED, RED+YELLOW, GREEN, FLASHING YELLOW (one and off 4 times), repeat..
//-	Each phase should last 2 seconds
//-	Try and use a while-loop to implement the flashing
    while (true) {

        trafficLights = 1;  //red
        wait_us(wait_ms *1000);
        trafficLights = 3;  //red+yel
        wait_us(wait_ms *1000);
        trafficLights = 4; //green
        wait_us(wait_ms * 1000);
        for(int i = 0; i < 4; i++){
            trafficLights = 2; //yel
            wait_us((wait_ms/8) * 1000);
            trafficLights = 0;
            wait_us((wait_ms/8) * 1000);
        }
    }
}

