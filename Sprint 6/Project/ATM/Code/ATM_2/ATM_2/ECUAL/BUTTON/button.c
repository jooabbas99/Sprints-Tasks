/*
 * button.c
 *
 * Created: 4/6/2023 10:30:06 PM
 *  Author: youss
 */ 
#include "button.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/timer0/timer0.h"

volatile uint8_t buttonEnterState = 0 ;

void BUTTON_init(uint8_t button_port , uint8_t button_pin){
	dio_init(button_port,button_pin,DIO_IN);
}
void BUTTON_status(uint8_t button_port , uint8_t button_pin,uint8_t *status){
	dio_read_pin(button_port,button_pin,status);
}

static volatile void button_delay_event(void){
	buttonEnterState = 1;
}

void BUTTON_read_zero_enter(uint8_t button_port , uint8_t button_pin,uint8_t *status){
	uint8_t btn_state , timer_flag = 0;
	dio_read_pin(button_port,button_pin,&btn_state);
	if (btn_state == DIO_HIGH)
	{
		while(btn_state == DIO_HIGH){
			// polling
			if (timer_flag == 0)
			{
				Timer0_event(2000,button_delay_event);
				timer_flag = 1;
			}
			dio_read_pin(button_port,button_pin,&btn_state);
			if (buttonEnterState == 1)
			{
				break;
			}
		}
			// check for enter flag 
		if (buttonEnterState == 1)
		{
			*status = 1;
		}
		else{
			*status = 0;
		}
	}else{
		*status = 2;
	}
	buttonEnterState = 0;

}