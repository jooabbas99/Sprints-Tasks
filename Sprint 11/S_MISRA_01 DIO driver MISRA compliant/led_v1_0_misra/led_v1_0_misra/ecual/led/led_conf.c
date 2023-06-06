/*
 * led_conf.c
 *
 * Created: 6/6/2023 12:42:24 PM
 *  Author: Youssef Abbas
 */ 


#include "led_interface.h"
const str_led_t leds[4] = {
		{
			.str_dio ={
				.pin = PIN0,
				.port = DIO_PORTA
			},
			.enm_led_status = LED_NOT_INIT
		},
		{
			.str_dio ={
				.pin = PIN1,
				.port = DIO_PORTA
			},
			.enm_led_status = LED_NOT_INIT
		},
		{
			.str_dio ={
				.pin = PIN2,
				.port = DIO_PORTA
			},
			.enm_led_status = LED_NOT_INIT
		},
		{
			.str_dio ={
				.pin = PIN3,
				.port = DIO_PORTA
			},
			.enm_led_status = LED_NOT_INIT
		}
	};
	