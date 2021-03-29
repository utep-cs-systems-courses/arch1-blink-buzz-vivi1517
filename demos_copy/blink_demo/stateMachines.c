#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  
  static int state = 0;
  switch(state){
  case 4:
    red_on = 0;
    led_changed = 1;
    state = 5;
    break;
  case 5:
    red_on = 1;
    led_changed = 1;
    state = 0;
    break;
  default:
    state++;
  }
  led_changed = changed;
  led_update();
}

void switchSM(){
  if (ssd1) red_on = 1;
  else red_on = 0;
  if (ssd2) green_on = 1;
  else green_on = 0;
  if (ssd3 & !ssd1) buzzer_set_period(2000);
  else if (ssd3 && ssd1) buzzer_set_period(1000);
  else buzzer_set_period(0);
  led_changed = 1;
  led_update();
}
