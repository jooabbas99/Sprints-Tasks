/*
 * led.c
 *
 * Created: 4/6/2023 9:49:15 PM
 *  Author: youss
 */ 
#include "led.h"


void LED_init(uint8_t led_port,uint8_t led_pin){
	DIO_init(led_port,led_pin,OUT);
}
void LED_on(uint8_t led_port,uint8_t led_pin){
	DIO_write(led_port,led_pin,HIGH);
}
void LED_off(uint8_t led_port,uint8_t led_pin){
	DIO_write(led_port,led_pin,LOW);
	
}
void LED_toggle(uint8_t led_port,uint8_t led_pin){
	DIO_toggle(led_port,led_pin);
}