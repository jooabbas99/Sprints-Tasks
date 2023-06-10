/*
 * dio_interface.c
 *
 * Created: 6/6/2023 11:13:38 AM
 *  Author: Youssef Abbas
 */ 

#include "dio_interface.h"
/* MISRA-C Comments:
	 *
	 * Rule 18.1: All declarations should be at the top of the function or file scope.
	 * In this code, the declaration of 'enm_dio_error' is placed at the top of the function 'dio_init'.
	 * This promotes code readability and helps avoid potential issues related to variable scoping.
	 *
	 * Rule 10.1: All operands of logical and relational operators should have a Boolean type.
	 * The logical expression `(dio_pin.pin > 7) || (dio_pin.port > 4)` is used to check the validity of 'dio_pin' structure members.
	 * The relational operators (>) used in the expression compare integer values and return a Boolean result (0 or 1).
	 * This ensures that the operands used with logical operators have Boolean types as required by the rule.
	 *
	 * Rule 12.2: All switch statements should have a default case.
	 * The switch statement is used to handle different 'dio_pin.port' values and configure the corresponding port direction.
	 * A default case is provided to handle any unexpected or undefined 'dio_pin.port' value that is not covered by the existing cases.
	 * This ensures that the program has a defined behavior even in the presence of unexpected input.
	 *
 */
static bool is_pin_correct(enm_dio_pin_t pin){
	return (pin < NUMBER_OF_PINS) ? TRUE : FALSE;
}
static bool is_port_correct(enm_dio_port_t port){
	return (port < NUMBER_OF_PORTS) ? TRUE : FALSE;
}
enm_dio_error_t dio_init(str_dio_t dio_pin,enm_dio_dir_t dir){
	// Rule 18.1, requires that all declarations should be at the top of the function or file scope.
	enm_dio_error_t enm_dio_error;
	enm_dio_error = DIO_NOT_COMPLETE;
	// Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
	// (OP_1 > OP_2) return 0 if it false and 1 if it true
	if (is_pin_correct(dio_pin.pin) != TRUE || !is_port_correct(dio_pin.port) != TRUE )
	{
		enm_dio_error = DIO_VALUE_ERROR;
	}
	else
	{
		enm_dio_error = DIO_SUCCESS;
		switch(dio_pin.port){
			case DIO_PORTA:
				(dir == DIO_IN) ? CLEAR_BIT(DIO_DDRA_REG,dio_pin.pin) :SET_BIT(DIO_DDRA_REG,dio_pin.pin);
				break;
			case DIO_PORTB:
				(dir == DIO_IN) ? CLEAR_BIT(DIO_DDRB_REG,dio_pin.pin) :SET_BIT(DIO_DDRB_REG,dio_pin.pin);
				break;
			case DIO_PORTC:
				(dir == DIO_IN) ? CLEAR_BIT(DIO_DDRC_REG,dio_pin.pin) :SET_BIT(DIO_DDRC_REG,dio_pin.pin);
				break;
			case DIO_PORTD:
				(dir == DIO_IN) ? CLEAR_BIT(DIO_DDRD_REG,dio_pin.pin) :SET_BIT(DIO_DDRD_REG,dio_pin.pin);
				break;
			default:
				// Rule 12.2, which requires that all switch statements should have a default case.
				enm_dio_error = DIO_FAIL;
				break;
		}
		
	}
	return enm_dio_error;
	
}

enm_dio_error_t dio_write_pin(str_dio_t dio_pin, enm_dio_value_t value){
	// Rule 18.1, requires that all declarations should be at the top of the function or file scope.
	enm_dio_error_t enm_dio_error = DIO_NOT_COMPLETE;
	// Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
	// (OP_1 > OP_2) return 0 if it false and 1 if it true
	if (is_pin_correct(dio_pin.pin) != TRUE || !is_port_correct(dio_pin.port) != TRUE )
	{
		enm_dio_error = DIO_VALUE_ERROR;
	}
	else
	{
		enm_dio_error = DIO_SUCCESS;
		switch(dio_pin.port){
			case DIO_PORTA:
				(value == DIO_LOW) ? CLEAR_BIT(DIO_PORTA_REG,dio_pin.pin) :SET_BIT(DIO_PORTA_REG,dio_pin.pin);
				break;
			case DIO_PORTB:
				(value == DIO_LOW) ? CLEAR_BIT(DIO_PORTB_REG,dio_pin.pin) :SET_BIT(DIO_PORTB_REG,dio_pin.pin);
				break;
			case DIO_PORTC:
				(value == DIO_LOW) ? CLEAR_BIT(DIO_PORTC_REG,dio_pin.pin):SET_BIT(DIO_PORTC_REG,dio_pin.pin);
				break;
			case DIO_PORTD:
				(value == DIO_LOW) ? CLEAR_BIT(DIO_PORTD_REG,dio_pin.pin):SET_BIT(DIO_PORTD_REG,dio_pin.pin);
				break;
			default:
				// Rule 12.2, which requires that all switch statements should have a default case.
				enm_dio_error = DIO_FAIL;
				break;
		}
		
	}
	return enm_dio_error;
}

enm_dio_error_t dio_toggle_pin(str_dio_t dio_pin){
	// Rule 18.1, requires that all declarations should be at the top of the function or file scope.
	enm_dio_error_t enm_dio_error = DIO_NOT_COMPLETE;
	// Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
	// (OP_1 > OP_2) return 0 if it false and 1 if it true
	if (is_pin_correct(dio_pin.pin) != TRUE || !is_port_correct(dio_pin.port) != TRUE )
	{
		enm_dio_error = DIO_VALUE_ERROR;
	}
	else
	{
		enm_dio_error = DIO_SUCCESS;
		switch(dio_pin.port){
			case DIO_PORTA:
				TOGGLE_BIT(DIO_PORTA_REG,dio_pin.pin);
				break;
			case DIO_PORTB:
				TOGGLE_BIT(DIO_PORTB_REG,dio_pin.pin);
				break;
			case DIO_PORTC:
				TOGGLE_BIT(DIO_PORTC_REG,dio_pin.pin);
				break;
			case DIO_PORTD:
				TOGGLE_BIT(DIO_PORTD_REG,dio_pin.pin);
				break;
			default:
				// Rule 12.2, which requires that all switch statements should have a default case.
				enm_dio_error = DIO_FAIL;
				break;
		}
		
	}
	return enm_dio_error;
}

enm_dio_error_t dio_read_pin(str_dio_t dio_pin,uint8 *data){
	// Rule 18.1, requires that all declarations should be at the top of the function or file scope.
	enm_dio_error_t enm_dio_error = DIO_NOT_COMPLETE;
	// Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
	// (OP_1 > OP_2) return 0 if it false and 1 if it true
	if (is_pin_correct(dio_pin.pin) != TRUE || !is_port_correct(dio_pin.port) != TRUE )
	{
		enm_dio_error = DIO_VALUE_ERROR;
	}
	else
	{
		enm_dio_error = DIO_SUCCESS;
		switch(dio_pin.port){
			case DIO_PORTA:
				*data = READ_BIT(DIO_PINA_REG,dio_pin.pin);
				break;
			case DIO_PORTB:
				*data =READ_BIT(DIO_PINB_REG,dio_pin.pin);
				break;
			case DIO_PORTC:
				*data =READ_BIT(DIO_PINC_REG,dio_pin.pin);
				break;
			case DIO_PORTD:
				*data =READ_BIT(DIO_PIND_REG,dio_pin.pin);
				break;
			default:
				// Rule 12.2, which requires that all switch statements should have a default case.
				enm_dio_error = DIO_FAIL;
				break;
		}
		
	}
	return enm_dio_error;
}
