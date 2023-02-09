#include "mbed.h"
#include <cstdio>
#include "myutils.hpp"

// DigitalOut redLED(PC_2,0);
// DigitalOut yellowLED(PC_3,0);
// DigitalOut greenLED(PC_6,0);
BusOut leds(PC_2, PC_3, PC_6);

// main() runs in its own thread in the OS
int main()

// The user asked to enter a value for pattern - this should be a value between 0 and 7
// The user is then asked to enter a count - this is a value between 5 and 20
// Finally, the user should enter a value for delay - this is a value between 50 and 2000
// All the above should be validated (use a do-while loop)
// When this is done, the program should do the following:

// The LEDs flash count times, alternating between 0 and pattern (use a for-loop for this). The delay between flashes is delay ms.

// The code then repeats (outer while-loop)
{
    while (true) {
        int pattern , count, delay;
        int patternInputted, delayInputted, countInputted;
   

        do {
            flushInputBuffer();
            printf("\n\nenter a value for pattern - this should be a value between 0 and 7 press return\n");
            patternInputted = scanf("%d", &pattern);
            flushInputBuffer();
            printf("\n\nenter a value for count - this should be a value between 5 and 20 press return\n");
            countInputted = scanf("%d", &count);
            flushInputBuffer();
            printf("\n\nenter a value for delay - this should be a value between 50 and 2000 press return\n");
            delayInputted = scanf("%d", &delay);
        }while ((patternInputted< 1) || (countInputted< 1) || (delayInputted< 1));

        printf("%d pattern, %d count, %d delay", pattern, count, delay);
        
        for (int n=0; n<count; n = n+1) {
            
            leds = pattern;
            wait_us((delay/2) * 1000);
            leds = 0;
            wait_us((delay/2) * 1000);
        }


        

        //For-Loop
        // volatile int n;


        //2s pause
        wait_us(2000000);
    }
}

