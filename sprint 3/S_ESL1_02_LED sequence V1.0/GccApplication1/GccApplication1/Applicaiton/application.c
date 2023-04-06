/*
 * application.c
 *
 * Created: 4/6/2023 10:13:31 PM
 *  Author: youss
 */ 

#include "application.h"
uint8_t btnState , counter;
ST_led_t led[LED_NO];
void AppInit(){
	led[0].pinNumber = PIN0;
	led[0].portNmber = PORT_A;
	led[0].ledStatus = LOW;
	
	led[1].pinNumber = PIN1;
	led[1].portNmber = PORT_A;
	led[1].ledStatus = LOW;
	
	led[2].pinNumber = PIN2;
	led[2].portNmber = PORT_A;
	led[2].ledStatus = LOW;
	
	led[3].pinNumber = PIN3;
	led[3].portNmber = PORT_A;
	led[3].ledStatus = LOW;
	
	LED_init(&led[0]);
	LED_init(&led[1]);
	LED_init(&led[2]);
	LED_init(&led[3]);
	BUTTON_init(PORT_B,PIN0);
	btnState = 0;
	counter = 0;
}

void AppStart(){
	
	BUTTON_status(PORT_B,PIN0,&btnState);
	
	if (btnState == BUTTON_HIGH)
	{
		counter ++;
		if (counter <= LED_NO)
		{
			LED_on(&led[counter-1]);
		}
		else
		{	
			if (counter > 8)
			{
				counter = 0;
			}else {
				LED_off(&led[counter-5]);
				
			}
			
		}
		BUTTON_status(PORT_B,PIN0,&btnState);
		while(btnState == HIGH){
			BUTTON_status(PORT_B,PIN0,&btnState);
		}
		
	}
	
}