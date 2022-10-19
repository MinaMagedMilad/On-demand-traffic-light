/*
 * button.h
 *
 * Created: 9/29/2022 10:46:51 PM
 *  Author: Mina Maged
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
//Initialize 
#include "../../MCAL/DIO Driver/dio.h"
#define BUTTON_1_PORT PORT_C
#define BUTTON_1_PIN PIN1
#define BUTTON_2_PORT PORT_D
#define BUTTON_2_PIN PIN7

//button state macros
#define LOW 0
#define HIGH 1
void BUTTON_init(uint8_t buttonport, uint8_t buttonpin);

// button read

void BUTTON_read(uint8_t buttonport, uint8_t buttonpin, uint8_t *value);




#endif /* BUTTON_H_ */