/*
 * dio_interface.h
 *
 * Created: 6/6/2023 11:14:08 AM
 *  Author: Youssef Abbas
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../utility/bit_math.h"
#include "../../utility/std_types.h"
#include "dio_private.h"

typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}enm_dio_port_t;


// dio value
typedef enum {
	DIO_LOW = 0,
	DIO_HIGH = 1
}enm_dio_value_t;

// dio direction
typedef enum {
	DIO_IN = 0,
	DIO_OUT = 1
}enm_dio_dir_t;

// DIO Errors
typedef enum {
	DIO_FAIL,
	DIO_SUCCESS,
	DIO_NOT_COMPLETE ,
	DIO_VALUE_ERROR 
}enm_dio_error_t;

typedef struct {
	enm_dio_port_t port;
	enm_dio_pin_t pin;
}str_dio_t;

#define NUMBER_OF_PORTS	4
#define NUMBER_OF_PINS	7

// DIO functions

enm_dio_error_t dio_init(str_dio_t dio_pin,enm_dio_dir_t dir);

enm_dio_error_t dio_write_pin(str_dio_t dio_pin, enm_dio_value_t value);

enm_dio_error_t dio_toggle_pin(str_dio_t dio_pin);

enm_dio_error_t dio_read_pin(str_dio_t dio_pin,uint8 *data);


#endif /* DIO_INTERFACE_H_ */