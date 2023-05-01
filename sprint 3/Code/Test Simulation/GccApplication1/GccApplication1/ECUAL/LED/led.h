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
void LED_init(uint8_t led_port,uint8_t led_pin);
void LED_on(uint8_t led_port,uint8_t led_pin);
void LED_off(uint8_t led_port,uint8_t led_pin);
void LED_toggle(uint8_t led_port,uint8_t led_pin);


#endif /* LED_H_ */