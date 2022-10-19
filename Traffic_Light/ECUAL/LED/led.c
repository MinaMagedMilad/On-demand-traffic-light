/*
 * led.c
 *
 * Created: 9/29/2022 9:32:16 PM
 *  Author: Mina Maged
 */ 
#include "led.h"

void LED_init(uint8_t ledport, uint8_t ledpin) {    //output device
	
	DIO_init(ledpin, ledport,OUT);
	
}
void LED_on(uint8_t ledport, uint8_t ledpin){
	
	DIO_write(ledpin,ledport,HIGH);
	
}
void LED_off(uint8_t ledport, uint8_t ledpin){
		DIO_write(ledpin,ledport,LOW);
	
}
void LED_toggle(uint8_t ledport, uint8_t ledpin){
	
	
	DIO_toggle(ledpin,ledport);
	
}