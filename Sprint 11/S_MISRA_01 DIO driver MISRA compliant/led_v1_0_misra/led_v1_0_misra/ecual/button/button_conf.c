/*
 * led_conf.c
 *
 * Created: 6/6/2023 12:42:24 PM
 *  Author: Youssef Abbas
 */ 


#include "button_interface.h"
const str_button_t button = {
		
			.str_dio ={
				.pin = PIN0,
				.port = DIO_PORTB
			},
			.enm_button_active = BUTTON_ACTIVE_HIGH
	};
	