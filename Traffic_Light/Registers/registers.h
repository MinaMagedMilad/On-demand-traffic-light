/*
 * registers.h
 *
 * Created: 9/27/2022 10:31:59 PM
 *  Author: Mina Maged
 */ 

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "../Types/types.h"

// PORTA
#define PORTA *((volatile uint8_t*)0x3B)   // 8-bit register
#define DDRA *((volatile uint8_t*)0x3A)   // 8-bit register
#define PINA *((volatile uint8_t*)0x39)   // 8-bit register


//PORTB
#define PORTB *((volatile uint8_t*)0x38)   // 8-bit register
#define DDRB *((volatile uint8_t*)0x37)   // 8-bit register
#define PINB *((volatile uint8_t*)0x36)   // 8-bit register


//PORTC
#define PORTC *((volatile uint8_t*)0x35)   // 8-bit register
#define DDRC *((volatile uint8_t*)0x34)   // 8-bit register
#define PINC *((volatile uint8_t*)0x33)   // 8-bit register


//PORTD
#define PORTD *((volatile uint8_t*)0x35)   // 8-bit register
#define DDRD *((volatile uint8_t*)0x34)   // 8-bit register
#define PIND *((volatile uint8_t*)0x33)   // 8-bit register




#endif /* REGISTERS_H_ */