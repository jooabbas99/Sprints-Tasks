/*
 * button.c
 *
 * Created: 4/6/2023 10:30:06 PM
 *  Author: youss
 */ 
#include "button.h"



void BUTTON_init(uint8_t button_port , uint8_t button_pin){
	DIO_init(button_port,button_pin,IN);
}
void BUTTON_status(uint8_t button_port , uint8_t button_pin,uint8_t *status){
	DIO_read(button_port,button_pin,status);
}
