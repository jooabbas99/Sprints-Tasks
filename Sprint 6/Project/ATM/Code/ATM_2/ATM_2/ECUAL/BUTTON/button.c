/*
 * button.c
 *
 * Created: 4/6/2023 10:30:06 PM
 *  Author: youss
 */ 
#include "button.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/timer0/timer0.h"
#include <avr/interrupt.h>



void BUTTON_init(ST_PBTN_t button){
	dio_init(button.button_port,button.button_pin,DIO_IN);
}
void BUTTON_status(ST_PBTN_t button,uint8 *status){
	dio_read_pin(button.button_port,button.button_pin,status);
}


void BUTTON_read_zero_enter(ST_PBTN_t button,uint8 * value){
	 uint8 button_state = 0;
	volatile uint16 timeCounter = 0;
	dio_read_pin(button.button_port,button.button_pin,&button_state);
	if (button_state == DIO_HIGH)
	{
		while(button_state == DIO_HIGH){
			Timer0_Delay(BTN_MIN_SECOND);
			timeCounter += BTN_MIN_SECOND;
			dio_read_pin(button.button_port,button.button_pin,&button_state);
			if (button_state == DIO_LOW && timeCounter < BTN_2_SECOND)
			{
				*value = BTN_ZERO_PRESSED;
			}
			else if (timeCounter >= BTN_2_SECOND)
			{
				*value = BTN_ENTER_PRESSED;
				break;
			}
		}
	}
	else
	{
		*value = BTN_NO_PRESS;//NO
	}
}