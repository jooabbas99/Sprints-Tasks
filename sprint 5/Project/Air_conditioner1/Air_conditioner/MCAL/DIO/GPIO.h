/*
 * GPIO.h
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#ifndef MCAL_DIO_GPIO_H_
#define MCAL_DIO_GPIO_H_

/*============= FILE INCLUSION =============*/

#include "../../Utilities/Registers.h"
#include "../../Utilities/Common_Macros.h"

/*============= TYPE DEFINITION =============*/
typedef enum{
	PIN_INPUT,PIN_OUTPUT
}EN_PIN_DIRECTION;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}EN_PORT_DIRECTION;

typedef enum{
	Low,High
}EN_PIN_VALUE;

typedef enum{
	LOW,HIGH=0xFF
}EN_PORT_VALUE;

typedef enum{
	FAILED,SUCCESS
}EN_STATE;


/*============= FUNCTION PROTOTYPE =============*/
EN_STATE GPIO_setPinDirection(uint8 port_num, uint8 pin_num, EN_PIN_DIRECTION direction);
EN_STATE GPIO_writePin(uint8 port_num, uint8 pin_num, EN_PIN_VALUE value);
EN_STATE GPIO_readPin(uint8 port_num, uint8 pin_num,uint8* value);
EN_STATE GPIO_togglePin(uint8 port_num, uint8 pin_num);
EN_STATE GPIO_setPortDirection(uint8 port_num, EN_PORT_DIRECTION direction);
EN_STATE GPIO_writePort(uint8 port_num, uint8 value);
EN_STATE GPIO_readPort(uint8 port_num,uint8* value);
EN_STATE GPIO_checkstate(uint8 port_num,uint8 pin_num);


#endif /* MCAL_DIO_GPIO_H_ */



