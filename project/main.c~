#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

int main(){
  configureClocks();
  led_init();
  enableWDTInterrupts();
  buzzer_init();
  switch_init();


  or_sr(0x18);
}
