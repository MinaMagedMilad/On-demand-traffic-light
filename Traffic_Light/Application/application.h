/*
 * application.h
 *
 * Created: 10/7/2022 10:10:25 PM
 *  Author: Mina Maged
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../MCAL/DIO Driver/dio.h"
#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/LED/led.h"
#include "../Interrupts/interrupts.h"
#include "../Timer0/timer.h"
void app_init(void);
void APP_start(void);



#endif /* APPLICATION_H_ */