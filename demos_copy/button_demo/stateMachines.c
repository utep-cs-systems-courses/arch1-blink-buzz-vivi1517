#include "led.h"
#include "switches.h"

void switchSM(){
  if (ssd1) red_on = 1;
  else red_on = 0;
  if (ssd2) green_on = 1;
  else green_on = 0;
  led_changed = 1;
  led_update();
}
