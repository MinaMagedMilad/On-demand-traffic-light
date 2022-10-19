/*
 * timer.c
 *
 * Created: 10/7/2022 11:34:36 PM
 *  Author: Mina Maged
 */ 

#include "timer.h"
#include <math.h>
void Timer_init(){
	
	TCCR0 = 0x00; // Normal mode
	
}

void start_timer(uint16_t delay){
	
	// Time in milli-second
	
	//---------------IF Tdelay > Tmaxdelay-------------------
	
	uint16_t Tmaxdelay = 256; //ms
	uint16_t Tinitial = 0;
	uint16_t NumberOfOverflows = 0;
	uint16_t overflowCounter = 0;
	
	if(delay < Tmaxdelay){
		
		NumberOfOverflows = 1;
		
		Tinitial = (Tmaxdelay - delay)/1;
		
	}
	
	
	else if(delay > Tmaxdelay){
		
		NumberOfOverflows = ceil((double)delay/Tmaxdelay);
		
		Tinitial = 256 - ((delay/1)/NumberOfOverflows);
	}
	
	
	else{
		
		Tinitial = 0;
		NumberOfOverflows = 1;
		
	}
	
		TCNT0 = Tinitial; // initial start
		TCCR0 |= (1<<0) | (1<<2); // Prescaler 1024
		
	while (overflowCounter < NumberOfOverflows){
	
	while ((TIFR & (1<<0)) == 0);
	TIFR |= (1<<0);
	
	overflowCounter++;
	}
	overflowCounter = 0;
	
	TCCR0 = 0x00;
	
	}
	
	