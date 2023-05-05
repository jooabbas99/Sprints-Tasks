/*
 * button.c
 *
 * Created: 4/6/2023 10:30:06 PM
 *  Author: youss
 */ 
#include "button.h"

#include "../../MCAL/DIO/DIO.h"


void BUTTON_init(uint8_t button_port , uint8_t button_pin){
	dio_init(button_port,button_pin,DIO_IN);
}
void BUTTON_status(uint8_t button_port , uint8_t button_pin,uint8_t *status){
	dio_read_pin(button_port,button_pin,status);
}
