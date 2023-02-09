// You need this to use the Module Support Board
#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 1000

Buzzer buzz;
Buttons buttons;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

   void letterS() {
        for (int i=0; i<3;++i) {
            buzz.playTone("C");
            wait_us(WAIT_TIME_MS * 150);
            buzz.rest();
            wait_us(WAIT_TIME_MS * 150);
            }
        }   

    void letterO(){
        for (int i=0; i<3;++i){
            buzz.playTone("C");
            wait_us(WAIT_TIME_MS * 450);
            buzz.rest();
            wait_us(WAIT_TIME_MS * 150);
        }   
    }

int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);
    // Modify the code to repeatedly play a major scale (C,D,E,F,G,A,B,C). Each note should last 250 ms (250,000 µS)
    //char notes[] = { 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C' };
    const char* notes[] = {"C", "D", "E", "F", "G", "A", "B", "C" };

    //Repeat everything "forever" (until the power is removed or the chip is reset)
    while (true)
    {
       
        // for ( int i=0 ; i < (sizeof(notes)/sizeof(notes[0])) ; ++i ){
        //     const char* note = notes[i];
        //     buzz.playTone(note);
        //     wait_us(WAIT_TIME_MS * 250); 
        // }

        letterS();
        wait_us(WAIT_TIME_MS * 450);
        letterO();
        wait_us(WAIT_TIME_MS * 450);
        letterS();
        wait_us(WAIT_TIME_MS * 900);


        // //Pause
        // buzz.rest();
        // wait_us(WAIT_TIME_MS * 1000);

    }
}