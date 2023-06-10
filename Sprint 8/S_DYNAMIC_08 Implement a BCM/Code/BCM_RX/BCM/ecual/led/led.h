/*
 * lcd.h
 *
 * Created: 5/27/2023 11:49:29 AM
 *  Author: Youssef Abbas
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../mcal/dio/dio_interface.h"
typedef enum {
	LED_ON=1,
	LED_OFF = 0
}enm_led_status_t;
typedef struct{
	str_dio_t str_dio;
	enm_led_status_t enm_led_status;
}str_led_t;

void LED_init(str_led_t* led);
void LED_on(str_led_t*led);
void LED_off(str_led_t*led);
void LED_toggle(str_led_t*led);



#endif /* LCD_H_ */