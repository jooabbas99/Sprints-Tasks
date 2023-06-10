/*
 * LED.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "LED.h"

/*============= FUNCTION DEFINITION =============*/

EN_STATE LED_init(uint8 PORT,uint8 led)
{
	if(PORT < 0 || PORT >= MAX_PORT_ID || led < 0 || led >= MAX_PIN)
	return FAILED;
	GPIO_setPinDirection(PORT,led,PIN_OUTPUT);
	GPIO_writePin(PORT,led,Low);
	return SUCCESS;
}

EN_STATE LED_digitalwrite(uint8 PORT,uint8 led,EN_PIN_VALUE value)
{
	if(PORT < 0 || PORT >= MAX_PORT_ID || led < 0 || led >= MAX_PIN)
		return FAILED;
	GPIO_writePin(PORT,led,value);
	return SUCCESS;
}

