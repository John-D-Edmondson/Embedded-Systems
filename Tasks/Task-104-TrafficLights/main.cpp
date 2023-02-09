#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_S 1000000 

DigitalOut red(TRAF_RED1_PIN,0);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);
BusOut myleds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

LCD_16X2_DISPLAY lcd;

int main()
{
    // lcd.puts("RED");
    // wait_us(1000000);

    // amber = 1;
    // lcd.cls();
    // lcd.puts("Amber");
    // wait_us(1000000);

    // green = 1;
    // lcd.cls();
    // lcd.puts("Green");    
    // wait_us(1000000);

    lcd.cls();
    lcd.puts("TASK-104");

    while (true)
    {

        Timer timer;
        timer.reset();
        
       

        myleds = 1; // red on


        while (duration_cast<milliseconds>(timer.elapsed_time()).count() < 5000){
            timer.start();
        }
        timer.reset();

       
        myleds = 3; // red on, yel on

        while (duration_cast<milliseconds>(timer.elapsed_time()).count() < 2000){
            timer.start();
        }
        timer.reset();
        myleds = 4; // green on


       while (duration_cast<milliseconds>(timer.elapsed_time()).count() < 5000){
            timer.start();
        }
        timer.reset();

        for (int i =0;i<4;++i ){
            myleds = 2; // yel on
            wait_us(WAIT_TIME_S * 0.25);
            myleds = 0;   //all off
            wait_us(WAIT_TIME_S * 0.25);
        }

        
        //red = !red; // red on
 
        //wait_us(WAIT_TIME_S * 5); // wait 5

         // amber = !amber; // amber on
        
        //wait_us(WAIT_TIME_S * 2); //wait 2

        // red =!red; // red off
        // amber = !amber; // amber off
        
        // green = !green; //green on
        // wait_us(WAIT_TIME_S * 5); //wait 10
        
        // for (int i =0;i<4;++i ){
        //     myleds = 2; // yel on
        //     wait_us(WAIT_TIME_S * 0.25);
        //     myleds = 0;   //all off
        //     wait_us(WAIT_TIME_S * 0.25);
        // }

    }
}
