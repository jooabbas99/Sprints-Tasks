/*
 * led.h
 *
 * Created: 4/6/2023 9:49:06 PM
 *  Author: youss
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../Utilities/types.h"
#include "../../MCAL/DIO/DIO.h"


typedef struct{
	uint8_t portNmber;
	uint8_t pinNumber;
	uint8_t ledStatus;
}ST_led_t;

void LED_init(ST_led_t* led);
void LED_on(ST_led_t*led);
void LED_off(ST_led_t*led);
void LED_toggle(ST_led_t*led);


#endif /* LED_H_ */