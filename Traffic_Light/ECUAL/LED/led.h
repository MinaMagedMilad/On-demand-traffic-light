/*
 * led.h
 *
 * Created: 9/29/2022 9:32:01 PM
 *  Author: Mina Maged
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../Types/types.h"

void LED_init(uint8_t ledport, uint8_t ledpin);
void LED_on(uint8_t ledport, uint8_t ledpin);
void LED_off(uint8_t ledport, uint8_t ledpin);
void LED_toggle(uint8_t ledport, uint8_t ledpin);




#endif /* LED_H_ */