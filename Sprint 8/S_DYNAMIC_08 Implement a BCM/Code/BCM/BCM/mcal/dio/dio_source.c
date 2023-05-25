/*
 * dio_source.c
 *
 * Created: 5/25/2023 11:23:51 AM
 *  Author: Youssef Abbas
 */ 

#include "dio_interface.h"
#include "dio_private.h"
#include "../../i_lib/bit_math.h"

enm_dio_error_t dio_init(str_dio_t dio_pin,enm_dio_dir_t dir){
	switch(dio_pin.port){
		case PORT_A:
		(dir == DIO_IN) ? CLEAR_BIT(DDRA,dio_pin.pin) :SET_BIT(DDRA,dio_pin.pin);
		break;
		case PORT_B:
		(dir == DIO_IN) ? CLEAR_BIT(DDRB,dio_pin.pin) :SET_BIT(DDRB,dio_pin.pin);
		break;
		case PORT_C:
		(dir == DIO_IN) ? CLEAR_BIT(DDRC,dio_pin.pin) :SET_BIT(DDRC,dio_pin.pin);
		break;
		case PORT_D:
		(dir == DIO_IN) ? CLEAR_BIT(DDRD,dio_pin.pin) :SET_BIT(DDRD,dio_pin.pin);
		break;
		default:
		return DIO_FAIL;
		break;
	}
	return DIO_SUCCESS;
}

enm_dio_error_t dio_write_pin(str_dio_t dio_pin, enm_dio_value_t value)
{
	switch(dio_pin.port){
		case PORT_A:
		(value == DIO_LOW) ? CLEAR_BIT(PORTA,dio_pin.pin) :SET_BIT(PORTA,dio_pin.pin);
		break;
		case PORT_B:
		(value == DIO_LOW) ? CLEAR_BIT(PORTB,dio_pin.pin) :SET_BIT(PORTB,dio_pin.pin);
		break;
		case PORT_C:
		(value == DIO_LOW) ? CLEAR_BIT(PORTC,dio_pin.pin):SET_BIT(PORTC,dio_pin.pin);
		break;
		case PORT_D:
		(value == DIO_LOW) ? CLEAR_BIT(PORTD,dio_pin.pin):SET_BIT(PORTD,dio_pin.pin);
		break;
		default:
		return DIO_FAIL;
		break;
	}
	return DIO_SUCCESS;
}

enm_dio_error_t dio_toggle(str_dio_t dio_pin){
	switch(dio_pin.port){
		case PORT_A:
		TOGGLE_BIT(PORTA,dio_pin.pin);
		break;
		case PORT_B:
		TOGGLE_BIT(PORTB,dio_pin.pin);
		break;
		case PORT_C:
		TOGGLE_BIT(PORTC,dio_pin.pin);
		break;
		case PORT_D:
		TOGGLE_BIT(PORTD,dio_pin.pin);
		break;
		default:
		return DIO_FAIL;
		break;
	}
	return DIO_SUCCESS;

}

enm_dio_error_t dio_read_pin(str_dio_t dio_pin,uint8 *data)
{
	switch(dio_pin.port){
		case PORT_A:
		*data = READ_BIT(PINA,dio_pin.pin);
		break;
		case PORT_B:
		*data =READ_BIT(PINB,dio_pin.pin);
		break;
		case PORT_C:
		*data =READ_BIT(PINC,dio_pin.pin);
		break;
		case PORT_D:
		*data =READ_BIT(PIND,dio_pin.pin);
		break;
		default:
		return DIO_FAIL;
		break;
	}
	return DIO_SUCCESS;
}

enm_dio_error_t dio_read_port(enm_dio_port_t port,uint8 *data)
{
	switch(port){
		case PORT_A:
		*data = PINA;
		break;
		case PORT_B:
		*data =PINB;
		break;
		case PORT_C:
		*data =PINC;
		break;
		case PORT_D:
		*data =PIND;
		break;
		default:
		return DIO_FAIL;
		break;
	}
	return DIO_SUCCESS;
}


enm_dio_error_t dio_write_port(enm_dio_port_t port,enm_dio_value_t value)
{
	switch(port){
		case PORT_A:
		PORTA = value;
		break;
		case PORT_B:
		PORTB = value;
		break;
		case PORT_C:
		PORTC = value;
		break;
		case PORT_D:
		PORTD = value;
		break;
		default:
		return DIO_FAIL;
		break;
	}
	return DIO_SUCCESS;
}