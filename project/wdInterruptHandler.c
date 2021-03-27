#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char buzz_count = 0;


  static char blink_count = 0;
  
  if (++blink_count == 125) {
    state_advance();
    blink_count = 0;
  }

  if (++buzz_count == 120){
    noise();
    buzz_count = 0;
  }
}
