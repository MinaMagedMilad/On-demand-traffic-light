/*
 * interrupts.c
 *
 * Created: 10/8/2022 2:45:12 AM
 *  Author: Mina Maged
 */ 
#include "interrupts.h"


 void INT_Enable() {
//SREG |= (1<<7);
MCUCR |= (1<<0) | (1<<1); // Rising edge
GICR |= (1<<6);
}



