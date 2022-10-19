/*
 * application.c
 *
 * Created: 10/7/2022 10:10:10 PM
 *  Author: Mina Maged
 */ 
#include "application.h"
//#include <avr/interrupt.h>
	uint8_t mode = 1; // mode = 1 (normal mode)  mode = 0 (pedestrains mode)
	uint8_t state = 1; // 1 = green   2 = yellow   3 = red
	
	//-------------------- Intialize APP-------------------
	
void app_init(){
	
	// -------------I/O initilizations----------------------
	
	LED_init(PORT_A,PIN0);   // car green
	LED_init(PORT_A,PIN1);   // car yellow
	LED_init(PORT_A,PIN2);   // car red
	LED_init(PORT_B,PIN0);   // ped green
	LED_init(PORT_B,PIN1);   // ped yellow
	LED_init(PORT_B,PIN2);   // ped red
	
	
	BUTTON_init(PORT_D,PIN2); //interrupt button
	
	//Interrupt enable
	
	sei();
	
	RISING_EDGE_SETUP();
	SETUP_INT0() ;
	Timer_init();
}

// ---------------- Start APP ---------------

void APP_start(void){

// Check Cars and pedestrians Traffic light state ( Green, yellow or red)

switch(state){
	case 1:   //Car traffic light is green and pedestrains traffic light is red
	LED_on(PORT_A,PIN0);  // Car = green
	LED_on(PORT_B,PIN2); // ped = red
	//
	for(int i = 0 ; i<20 ; i++){  // delay for 5 sec.
	start_timer(250);
	if(mode == 0){ // check if there is an interrupt
	break;
	}
	}
	if(state == 1 && mode == 0){ // if there is an interrupt while car = green
	LED_off(PORT_A,PIN0); // Off car green
	LED_off(PORT_B,PIN2); // Off ped red
	for (int i = 0 ; i < 10 ; i++){ // blink yellow for car and ped
		LED_toggle(PORT_A,PIN1);
		LED_toggle(PORT_B,PIN1);
		start_timer(500);
	}
	LED_off(PORT_A,PIN1); //Off yellow for car 
	LED_off(PORT_B,PIN1); //Off yellow for ped 
	LED_on(PORT_A,PIN2);  // On red for car
	LED_on(PORT_B,PIN0);  // On green for ped
	start_timer(5000);    // wait for 5 sec
	LED_off(PORT_A,PIN2); // Off red for car
	LED_off(PORT_B,PIN0); // Off green for ped
	
	for (int i = 0 ; i < 10 ; i++){ // blink yellow for car and ped for 5 sec.
		LED_toggle(PORT_A,PIN1);
		LED_toggle(PORT_B,PIN1);
		start_timer(500);
	}
	state--; //return to case 1 (green car - red ped)
	}
	LED_off(PORT_A,PIN0);
	LED_off(PORT_B,PIN2);
	
	mode = 1; // return to normal mode if changed
	state++;
	break;
	
	case 2:
	
	for (int i = 0 ; i < 10 ; i++){ //blink yellow in car and ped for 5 sec.
	LED_toggle(PORT_A,PIN1);
	LED_toggle(PORT_B,PIN1);
	start_timer(500);
	if(!mode){ //checks if interrupt
	break;
	}
	}
	
	if(state == 2 && mode == 0){ //if interrupt while car and ped are in yellow
		for (int i = 0 ; i < 10 ; i++){ //toggle for 5 sec.
			LED_toggle(PORT_A,PIN1);
			LED_toggle(PORT_B,PIN1);
			start_timer(500);
		}
		LED_off(PORT_A,PIN1); // Off yellow in car
		LED_off(PORT_B,PIN1); // Off yellow in ped
		LED_on(PORT_A,PIN2);  // On red in car
		LED_on(PORT_B,PIN0);  // On green in ped
		start_timer(5000);   // delay for 5sec.
		LED_off(PORT_A,PIN2); // Off red in car
		LED_off(PORT_B,PIN0); // Off green in ped
		
		for (int i = 0 ; i < 10 ; i++){ //Blink yellow in car and ped for 5 sec.
			LED_toggle(PORT_A,PIN1);
			LED_toggle(PORT_B,PIN1);
			start_timer(500);
		}
	state-=2;	// return to case 1 (green car and red ped)

	}
	
	LED_off(PORT_A,PIN1); //Off yellow for car
	LED_off(PORT_B,PIN1); //Off yellow for ped
	state++;
	mode = 1; //return to normal mode (if changed)
	break; 
	
	
	case 3:
	
		LED_on(PORT_A,PIN2);  // On red in car
		LED_on(PORT_B,PIN0);  // On green in ped
		
		for(int i = 0 ; i < 10 ; i++){ // wait for 5 sec.
		start_timer(500);
		if(!mode){ // checks if interrupt
		break;
		}
		}
		if(state == 3 && mode == 0){  // if interrupt and car is red and ped is green
			LED_on(PORT_B,PIN0); // On green in ped
			LED_on(PORT_A,PIN2); // On red in car
			start_timer(5000);   // wait for 5 sec.
			LED_off(PORT_B,PIN0); // Off green in ped
			LED_off(PORT_A,PIN2); // Off green in car
			
			mode = 1; // return to normal mode
			
		}
		LED_off(PORT_A,PIN2); // Off red in car
		LED_off(PORT_B,PIN0); // Off green in ped
		
		for (int i = 0 ; i < 10 ; i++){ // blink yellow for 5 sec.
			LED_toggle(PORT_A,PIN1);
			LED_toggle(PORT_B,PIN1);
			start_timer(500);
		}
		state = 1; //return to case 1 (green car and red ped)
	
	break;
	
}
}
	
	ISR(__vector_1){
		mode=0;
	}

	
	
