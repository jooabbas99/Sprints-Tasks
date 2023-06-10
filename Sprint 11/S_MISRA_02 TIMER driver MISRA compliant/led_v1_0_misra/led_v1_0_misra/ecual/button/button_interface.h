/*
 * led_interface.h
 *
 * Created: 6/6/2023 12:42:06 PM
 *  Author: Youssef Abbas
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "../../mcal/dio/dio_interface.h"

typedef enum {
	BUTTON_PRESSED = 1,
	BUTTON_RELEASED	= 0,
}enm_button_status_t;

typedef enum {
	BUTTON_ACTIVE_LOW = 0,
	BUTTON_ACTIVE_HIGH 
} enm_button_active_t;
typedef enum {
	BUTTON_INVALID_CONF,
	BUTTON_SUCCESS,
	BUTTON_FAILED,
	BUTTON_ALLREADY_INIT,
	BUTTON_NOT_COMBLETE,
	
} enm_button_error_t;
typedef struct {
	str_dio_t str_dio;
	enm_button_active_t enm_button_active;
} str_button_t;

enm_button_error_t button_init(str_button_t str_button);
enm_button_error_t button_read(str_button_t str_button,enm_button_status_t *enm_button_status);


#endif /* BUTTON_INTERFACE_H_ */