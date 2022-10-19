/*
 * timer.h
 *
 * Created: 10/7/2022 10:33:21 PM
 *  Author: Mina Maged
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../Types/types.h"
// Timer0 registers
#define TCCR0 *((volatile uint8_t*)0x53)   // 8-bit register
#define TCNT0 *((volatile uint8_t*)0x52)   // 8-bit register
#define TIFR *((volatile uint8_t*)0x58)   // 8-bit register
#define TIMSK *((volatile uint8_t*)0x59)   // 8-bit register
//#define Number_of_overflows 20
void Timer_init();
void start_timer(uint16_t delay);
//void stop_timer();



#endif /* TIMER_H_ */