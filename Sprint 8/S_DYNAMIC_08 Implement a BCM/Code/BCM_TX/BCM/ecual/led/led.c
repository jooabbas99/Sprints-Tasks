/*
 * lcd.c
 *
 * Created: 5/27/2023 11:49:23 AM
 *  Author: Youssef Abbas
 */ 
#include "led.h"



void LED_init(str_led_t *led){
	dio_init(led->str_dio,DIO_OUT);
	led->enm_led_status = LED_OFF;
}
void LED_on(str_led_t *led){
	dio_write_pin(led->str_dio,DIO_HIGH);
	led->enm_led_status = LED_ON;
}
void LED_off(str_led_t *led){
	dio_write_pin(led->str_dio,DIO_LOW);
	led->enm_led_status = LED_OFF;
}
void LED_toggle(str_led_t *led){
		dio_toggle(led->str_dio);
		led->enm_led_status != LED_OFF;
}