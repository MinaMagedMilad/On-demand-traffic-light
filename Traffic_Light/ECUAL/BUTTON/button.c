/*
 * button.c
 *
 * Created: 9/29/2022 10:47:04 PM
 *  Author: Mina Maged
 */ 
#include "button.h"
// button intilization
void BUTTON_init(uint8_t buttonport, uint8_t buttonpin){
	
	DIO_init(buttonpin, buttonport, IN);
	
}

// button read
void BUTTON_read(uint8_t buttonport, uint8_t buttonpin, uint8_t *value) 
{
	
	DIO_read(buttonpin, buttonport, value);
	
}