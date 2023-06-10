/*
 * GPIO.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "GPIO.h"


/*============= FUNCTION DEFINITION =============*/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
EN_STATE GPIO_setPinDirection(uint8 port_num, uint8 pin_num, EN_PIN_DIRECTION direction)
{
	if((pin_num < 0) || (pin_num >= MAX_PIN) || (port_num < 0) || (port_num >= MAX_PORT_ID))
	{
		return FAILED;
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
	return SUCCESS;
}
/*===========================================================*/
/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
EN_STATE GPIO_writePin(uint8 port_num, uint8 pin_num, EN_PIN_VALUE value)
{
	if((pin_num < 0) || (pin_num >= MAX_PIN) || (port_num < 0) || (port_num >= MAX_PORT_ID))
	{
		return FAILED;
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(value == High)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == High)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == High)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == High)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;
		}
	}
	return SUCCESS;
}

/*===========================================================*/
/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return failed.
 */
EN_STATE GPIO_readPin(uint8 port_num, uint8 pin_num,uint8* value)
{
	if((pin_num < 0) || (pin_num >= MAX_PIN) || (port_num < 0) || (port_num >= MAX_PORT_ID))
	{
		return FAILED;
	}
	else
	{

		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				*value = LOGIC_HIGH;
			}
			else
			{
				*value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				*value = LOGIC_HIGH;
			}
			else
			{
				*value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				*value = LOGIC_HIGH;
			}
			else
			{
				*value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				*value = LOGIC_HIGH;
			}
			else
			{
				*value = LOGIC_LOW;
			}
			break;
		}
	}
	return SUCCESS;
}
/*===========================================================*/
/*
 * Description :
 * toggle the logic of the pin
 * If the input port number or pin number are not correct, The function will return failed.
 */
EN_STATE GPIO_togglePin(uint8 port_num, uint8 pin_num)
{
	if((pin_num < 0) || (pin_num >= MAX_PIN) || (port_num < 0) || (port_num >= MAX_PORT_ID))
	{
		return FAILED;
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			TOGGLE_BIT(PORTA,pin_num);
			break;
		case PORTB_ID:
			TOGGLE_BIT(PORTB,pin_num);
			break;
		case PORTC_ID:
			TOGGLE_BIT(PORTC,pin_num);
			break;
		case PORTD_ID:
			TOGGLE_BIT(PORTD,pin_num);
			break;
		}
	}
	return SUCCESS;
}
/*===========================================================*/
/*
 * Description :
 * If the input port number or pin number are not correct, The function will return failed.
 */
EN_STATE GPIO_checkstate(uint8 port_num,uint8 pin_num)
{
	if((pin_num < 0) || (pin_num >= MAX_PIN) || (port_num < 0) || (port_num >= MAX_PORT_ID))
	{
		return FAILED;
	}
	return SUCCESS;
}
/*===========================================================*/
/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
EN_STATE GPIO_setPortDirection(uint8 port_num, EN_PORT_DIRECTION direction)
{
	if(port_num < 0 || port_num >= MAX_PORT_ID )
	{
		return FAILED;
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
	return SUCCESS;
}

/*===========================================================*/

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
EN_STATE GPIO_writePort(uint8 port_num, uint8 value)
{
	if(port_num < 0 || port_num >= MAX_PORT_ID )
	{
		return FAILED;
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
	return SUCCESS;
}
/*===========================================================*/
/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return failed.
 */
EN_STATE GPIO_readPort(uint8 port_num,uint8* value)
{

	if(port_num < 0 || port_num >= MAX_PORT_ID )
	{
		return FAILED;
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			*value = PINA;
			break;
		case PORTB_ID:
			*value = PINB;
			break;
		case PORTC_ID:
			*value = PINC;
			break;
		case PORTD_ID:
			*value = PIND;
			break;
		}
	}
	return SUCCESS;
}


