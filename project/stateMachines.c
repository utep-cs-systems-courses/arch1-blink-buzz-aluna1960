#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

int i;
int hertz;
void noise(){
  static char sound_state = 0;
  for(i = 0; sound_state!=9;i++){
    switch(sound_state){
    case 0:
      hertz = 1318;
      buzzer_set_period(hertz);
      hertz = 0;
      sound_state = 1;
    case 1:
      hertz = 1244;
      buzzer_set_period(hertz);
      sound_state = 2;
      hertz = 0;
    case 2:
      hertz = 1318;
      buzzer_set_period(hertz);
      sound_state = 3;
      hertz = 0;
    case 3:
      hertz = 1244;
      buzzer_set_period(hertz);
      sound_state = 4;
      hertz = 0;
    case 4:
      hertz = 1318;
      buzzer_set_period(hertz);
      sound_state = 4;
      hertz = 0;
    case 5:
      hertz = 988;
      buzzer_set_period(hertz);
      sound_state = 5;
      hertz = 0;
    case 6:
      hertz = 1177;
      buzzer_set_period(hertz);
      sound_state = 6;
      hertz = 0;
    case 7:
      hertz = 1046;
      buzzer_set_period(hertz);
      sound_state = 7;
      hertz = 0;
    case 8:
      hertz = 1760;
      buzzer_set_period(hertz);
      sound_state = 9;
      hertz = 0;
    }
  }    
}  


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
    green_on |= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}



