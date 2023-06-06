/*
 * led_interface.h
 *
 * Created: 6/6/2023 12:42:06 PM
 *  Author: Youssef Abbas
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../mcal/dio/dio_interface.h"

typedef enum {
	LED_OFF = 0,
	LED_ON	= 1,
	LED_NOT_INIT=2
}enm_led_status_t;

typedef struct{
	str_dio_t str_dio;
	enm_led_status_t enm_led_status ;
}str_led_t;

typedef enum {
	LED_INVALID_CONF,
	LED_SUCCESS,
	LED_FAILED,
	LED_ALLREADY_INIT,
	LED_NOT_COMBLETE,
	
} enm_led_error_t;

enm_led_error_t led_init(str_led_t* led);
enm_led_error_t led_on(str_led_t*led);
enm_led_error_t led_off(str_led_t*led);
enm_led_error_t led_toggle(str_led_t*led);

#endif /* LED_INTERFACE_H_ */