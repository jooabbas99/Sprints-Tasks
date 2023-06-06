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
				.pin = PIN4,
				.port = DIO_PORTB
			},
			.enm_led_status = LED_NOT_INIT
		},
		{
			.str_dio ={
				.pin = PIN5,
				.port = DIO_PORTB
			},
			.enm_led_status = LED_NOT_INIT
		},
		{
			.str_dio ={
				.pin = PIN6,
				.port = DIO_PORTB
			},
			.enm_led_status = LED_NOT_INIT
		},
		{
			.str_dio ={
				.pin = PIN7,
				.port = DIO_PORTB
			},
			.enm_led_status = LED_NOT_INIT
		}
	};
	