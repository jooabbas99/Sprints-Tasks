/*
 * DIO.c
 *
 * Created: 4/6/2023 8:42:20 PM
 *  Author: youss
 */ 
// includes 
#include "DIO.h"


// global variables 

// function body 
 // init pin direction
void DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction){
	switch(portNumber){
		case PORT_A:
			(direction == IN) ? CLEAR_BIT(DDRA,pinNumber) :SET_BIT(DDRA,pinNumber);
			break;
		case PORT_B:
			(direction == IN) ? CLEAR_BIT(DDRB,pinNumber) :SET_BIT(DDRB,pinNumber);
			break;
		case PORT_C:
				(direction == IN) ? CLEAR_BIT(DDRC,pinNumber) :SET_BIT(DDRC,pinNumber);
			break;
		case PORT_D:
			(direction == IN) ? CLEAR_BIT(DDRD,pinNumber) :SET_BIT(DDRD,pinNumber);
			break;
		default:
			break;
	}
}

void DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value)
{
		switch(portNumber){
			case PORT_A:
				(value == LOW) ? CLEAR_BIT(PORTA,pinNumber) :SET_BIT(PORTA,pinNumber);
				break;
			case PORT_B:
				(value == LOW) ? CLEAR_BIT(PORTB,pinNumber) :SET_BIT(PORTB,pinNumber);
				break;
			case PORT_C:
				(value == LOW) ? CLEAR_BIT(PORTC,pinNumber):SET_BIT(PORTC,pinNumber);
				break;
			case PORT_D:
				(value == LOW) ? CLEAR_BIT(PORTD,pinNumber):SET_BIT(PORTD,pinNumber);
				break;
			default:
				break;
		}
}

void DIO_toggle(uint8_t portNumber,uint8_t pinNumber){
	switch(portNumber){
		case PORT_A:
		TOGGLE_BIT(PORTA,pinNumber);
		break;
		case PORT_B:
		 TOGGLE_BIT(PORTB,pinNumber);
		break;
		case PORT_C:
		 TOGGLE_BIT(PORTC,pinNumber); 
		break;
		case PORT_D:
		 TOGGLE_BIT(PORTD,pinNumber);
		break;
		default:
		break;
	}
}

void DIO_read(uint8_t portNumber,uint8_t pinNumber, uint8_t * data){
	switch(portNumber){
		case PORT_A:
			*data = READ_BIT(PINA,pinNumber);
		break;
		case PORT_B:
			*data =READ_BIT(PINB,pinNumber);
		break;
		case PORT_C:
			*data =READ_BIT(PINC,pinNumber);
		break;
		case PORT_D:
			*data =READ_BIT(PIND,pinNumber);
		break;
		default:
		break;
	}
}