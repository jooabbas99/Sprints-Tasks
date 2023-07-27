/*
 * led.c
 *
 * Created: 4/6/2023 9:49:15 PM
 *  Author: youss
 */ 
#include "led.h"


void LED_init(ST_led_t *led){
	DIO_init(led->portNmber,led->pinNumber,OUT);
	led->ledStatus = LOW;
}
void LED_on(ST_led_t *led){
	DIO_write(led->portNmber,led->pinNumber,HIGH);
	led->ledStatus = HIGH;
}
void LED_off(ST_led_t *led){
	DIO_write(led->portNmber,led->pinNumber,LOW);
	led->ledStatus = LOW;
	
	
}
void LED_toggle(ST_led_t *led){
	DIO_toggle(led->portNmber,led->pinNumber);
	led->ledStatus = (led->ledStatus == LOW)? HIGH : LOW;
}