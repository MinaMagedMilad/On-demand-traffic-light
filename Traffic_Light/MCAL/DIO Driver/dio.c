/*
 * dio.c
 *
 * Created: 9/27/2022 10:50:31 PM
 *  Author: Mina Maged
 */ 
// include .h
#include "dio.h"
// global variables
// function definitions 

void DIO_init(uint8_t pinNumber,uint8_t portNumber , uint8_t direction){
	
	switch(portNumber){
		case PORT_A :
		if(direction == IN )
		DDRA &=~(1<<pinNumber);
		else if (direction == OUT)
		DDRA |= (1<<pinNumber);
		
		else {
			//error handling
			
		}
		break; 
		
		case PORT_B :
		if(direction == IN )
		DDRB &=~(1<<pinNumber);
		else if (direction == OUT)
		DDRB |= (1<<pinNumber);
		
		else {
			//error handling
			
		}
		break;
		
		case PORT_C :
		if(direction == IN )
		DDRC &=~(1<<pinNumber);
		else if (direction == OUT)
		DDRC |= (1<<pinNumber);
		
		else {
			//error handling
			
		}
		break;
		
		case PORT_D :
		if(direction == IN )
		DDRD &=~(1<<pinNumber);
		else if (direction == OUT)
		DDRD |= (1<<pinNumber);
		
		else {
			//error handling
			
		}
		break;
	}
	
	
	} // intialize dio direction
void DIO_write(uint8_t pinNumber,uint8_t portNumber , uint8_t value){
	switch(portNumber){
		case PORT_A :
		if(value == LOW )
		PORTA &=~(1<<pinNumber); //write zero
		else if (value == HIGH)
		PORTA |= (1<<pinNumber); //write one
		
		else {
			//error handling
			
		}
		break;
		
		case PORT_B :
		if(value == LOW )
		PORTB &=~(1<<pinNumber); //write zero
		else if (value == HIGH)
		PORTB |= (1<<pinNumber); //write one
		
		else {
			//error handling
			
		}
		break;
		
		case PORT_C :
		if(value == LOW )
		PORTC &=~(1<<pinNumber); //write zero
		else if (value == HIGH)
		PORTC |= (1<<pinNumber); //write one
		
		else {
			//error handling
			
		}
		break;
		
		case PORT_D :
		if(value == IN )
		PORTD &=~(1<<pinNumber); //write zero
		else if (value == OUT)
		PORTD |= (1<<pinNumber); //write one
		
		else {
			//error handling
			
		}
		break;
	
	}
	} //write data to dio
void DIO_toggle(uint8_t pinNumber,uint8_t portNumber)
{
	switch(portNumber){
		case PORT_A :
		PORTA ^= (1<<pinNumber); //write zero
		//write one
		break;
		
		case PORT_B :
		PORTB ^= (1<<pinNumber); //write zero
		//write one
		break;
		
		case PORT_C :
		PORTC ^= (1<<pinNumber); //write zero
		//write one
		break;
		
		case PORT_D :
			PORTD ^= (1<<pinNumber); //write zero
			//write one
			break;
		break;
	}
		
	
	} // toggle dio
void DIO_read(uint8_t pinNumber,uint8_t portNumber, uint8_t *value)// read dio
{
	
	switch(portNumber)
	{
	case PORT_A :
	*value = ((PORTA & (1<<pinNumber))>>pinNumber); //get state -> read bit
	break;
	
	case PORT_B :
	*value = ((PORTB & (1<<pinNumber))>>pinNumber); //get state -> read bit
	break;
	
	case PORT_C :
	*value = ((PORTC & (1<<pinNumber))>>pinNumber); //get state -> read bit
	break;
	
	case PORT_D :
	*value = ((PORTD & (1<<pinNumber))>>pinNumber); //get state -> read bit
	break;
	} 
	
	}