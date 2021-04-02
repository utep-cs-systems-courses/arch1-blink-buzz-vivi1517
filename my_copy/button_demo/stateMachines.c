#include "led.h"
#include "switches.h"
#include "buzzer.h"

void switchSM(){
  if(ssd1) red_on = 1; //if SW1 is pressed turn red on
  else if(ssd2) green_on = 1; //if SW2 is pressed turn green on
  else if(ssd4) {
    red_on = 1;
    green_on = 1;
  }
  else if(ssd3){
    buzzer_set_period(1000);
  }
  //else if(ssd3 && ssd1){
  //buzzer_set_period(2000);
  //}
  else{
    red_on = 0;
    green_on = 0;
    buzzer_set_period(0);
  }
  
  led_changed = 1;
  led_update();
}
