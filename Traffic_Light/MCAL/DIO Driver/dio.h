/*
 * dio.h
 *
 * Created: 9/27/2022 10:50:55 PM
 *  Author: Mina Maged
 */ 
#ifndef DIO_H_
#define DIO_H_
// include register.h
#include "../../Registers/registers.h"

// all internal driver typedefs
// all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// direction defines

#define IN 0
#define OUT 1
// value defines

#define LOW 0
#define HIGH 1

// PINs
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


// all driver function prototypes
void DIO_init(uint8_t pinNumber,uint8_t portNumber , uint8_t direction); // intialize dio direction
void DIO_write(uint8_t pinNumber,uint8_t portNumber , uint8_t direction); //write data to dio
void DIO_toggle(uint8_t pinNumber,uint8_t portNumber); // toggle dio
void DIO_read(uint8_t pinNumber,uint8_t portNumber, uint8_t *value); // read dio





#endif /*DIO_H_*/