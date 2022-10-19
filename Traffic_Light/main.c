/*
 * Traffic_Light.c
 *
 * Created: 10/7/2022 10:07:06 PM
 * Author : Mina Maged
 */ 

#include "Application/application.h"


int main(void)
{
	 app_init();
	
    // Replace with your application code 
    while (1) 
    {
		APP_start();
    }
	
	
}

// ------------------------------------------------- Test cases----------------------------------------------
/*uint8_t value = 1;

int main (void){
LED_init(PORT_A,PIN0); // green light
LED_init(PORT_B,PIN1); // yellow light
BUTTON_init(PORT_D,PIN2);

sei();

RISING_EDGE_SETUP();
SETUP_INT0() ;
Timer_init();

while(1){
//BUTTON_read(PORT_D,PIN2,&value);
if(value == 1){
LED_on(PORT_A,PIN0);
start_timer(1000);
LED_off(PORT_A,PIN0);
start_timer(1000);

}
else{
LED_on(PORT_B,PIN1);
start_timer(1000);
LED_off(PORT_B,PIN1);
start_timer(1000);
value = 0;
}

}
}
ISR(__vector_1){
	value=0;
}  // please if you want to test this intrreupt delete or comment the interrupt in application.c
*/

