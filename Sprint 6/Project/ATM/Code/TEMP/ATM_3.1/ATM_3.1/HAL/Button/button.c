/*
 * button.c
 *
 * Created: 5/4/2023 12:40:30 PM
 *  Author: Youssef Abbas
 */ 
#include "button.h"
#include "../../MCAL/DIO/GPIO.h"


void BUTTON_init(uint8 button_port , uint8 button_pin){
	GPIO_setPinDirection(button_port,button_pin,PIN_INPUT);
}
void BUTTON_status(uint8 button_port , uint8 button_pin,uint8 *status){
	GPIO_readPin(button_port,button_pin,status);
}

