#include "uop_msb.h"
using namespace uop_msb;

// Inputs
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);
DigitalOut ledYel(TRAF_YEL1_PIN);
DigitalOut ledGrn(TRAF_GRN1_PIN);

// Timers (modified version from Timer)

// 3sep timers so one thread can manage 3 diff actions. flash controls amber flase, red and green for debouncing 
TimerCompat tmr_flash;
TimerCompat tmr_red;
TimerCompat tmr_green;

// switch has 4 states with things that happen on entry and exit of them
typedef enum {
    WAIT_FOR_PRESS,
    DEBOUNCE_PRESS,
    WAIT_FOR_RELEASE,
    DEBOUCE_RELEASE
} SWITCH_STATE;

SWITCH_STATE sw2_state = WAIT_FOR_PRESS;
SWITCH_STATE sw3_state = WAIT_FOR_PRESS;

int main()
{

    while (true) {

        int sw3 = SW3.read();
        int sw2 = SW2.read();
        long long sw2_time = tmr_red.read_ms();
        long long sw3_time = tmr_green.read_ms();

        tmr_flash.start();
        long long yellow_flash_time = tmr_flash.read_ms();
        
        if (yellow_flash_time >= 500){
            ledYel = !ledYel;
            while (tmr_flash.read_ms() < 500);
            tmr_flash.reset();
        }

        switch(sw2_state) {
            
            case WAIT_FOR_PRESS:
                if(sw2 ==1){
                    sw2_state = DEBOUNCE_PRESS;
                    tmr_red.start();
                    ledRed = !ledRed;
                }
            break;
            
            case DEBOUNCE_PRESS:
                if (sw2_time >= 300){
                    sw2_state = WAIT_FOR_RELEASE;
                    tmr_red.stop();
                    tmr_red.reset();
                }
                break;
            
            case WAIT_FOR_RELEASE:
                if(sw2 == 0){
                    sw2_state = DEBOUCE_RELEASE;
                    tmr_red.start();
                }
                break;
            
            case DEBOUCE_RELEASE:
                if (sw2_time >= 300) {
                    sw2_state = WAIT_FOR_PRESS;
                    tmr_red.stop();
                    tmr_red.reset();
                }
                break;
        }

        switch(sw3_state) {
            
            case WAIT_FOR_PRESS:
                if(sw3 ==1){
                    sw3_state = DEBOUNCE_PRESS;
                    tmr_green.start();
                    ledGrn = !ledGrn;
                }
            break;
            
            case DEBOUNCE_PRESS:
                if (sw3_time >= 300){
                    sw3_state = WAIT_FOR_RELEASE;
                    tmr_green.stop();
                    tmr_green.reset();
                }
                break;
            
            case WAIT_FOR_RELEASE:
                if(sw3 == 0){
                    sw3_state = DEBOUCE_RELEASE;
                    tmr_green.start();
                }
                break;
            
            case DEBOUCE_RELEASE:
                if (sw3_time >= 300) {
                    sw3_state = WAIT_FOR_PRESS;
                    tmr_green.stop();
                    tmr_green.reset();
                }
                break;
        }
        
        //wait_us(300000);

        // while (SW2.read() == 1);
        // wait_us(300000);        


    }
}





