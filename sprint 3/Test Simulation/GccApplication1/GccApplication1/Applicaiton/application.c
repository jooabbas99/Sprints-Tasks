/*
 * application.c
 *
 * Created: 4/6/2023 10:13:31 PM
 *  Author: youss
 */ 

#include "application.h"
uint8_t btnState ;

void AppInit(){
	LED_init(PORT_A,PIN4);
	BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
	
	btnState = 0;
}

void AppStart(){
	
	BUTTON_status(BUTTON_1_PORT,BUTTON_1_PIN,&btnState);
	if (btnState == BUTTON_HIGH)
	{
		LED_on(PORT_A,PIN4);
	} else if  (btnState == BUTTON_LOW) {
		LED_off(PORT_A,PIN4);
	}
	
}