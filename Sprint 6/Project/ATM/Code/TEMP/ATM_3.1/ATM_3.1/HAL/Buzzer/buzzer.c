/*
 * LED.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "buzzer.h"

/*============= FUNCTION DEFINITION =============*/

EN_STATE buzzer_init(uint8 PORT,uint8 buzzer)
{
	if(PORT < 0 || PORT >= MAX_PORT_ID || buzzer < 0 || buzzer >= MAX_PIN)
	return FAILED;
	GPIO_setPinDirection(PORT,buzzer,PIN_OUTPUT);
	GPIO_writePin(PORT,buzzer,Low);
	return SUCCESS;
}

EN_STATE buzzer_digitalwrite(uint8 PORT,uint8 buzzer,EN_PIN_VALUE value)
{
	if(PORT < 0 || PORT >= MAX_PORT_ID || buzzer < 0 || buzzer >= MAX_PIN)
		return FAILED;
	GPIO_writePin(PORT,buzzer,value);
	return SUCCESS;
}

