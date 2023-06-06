/*
 * dio_interface.h
 *
 * Created: 5/25/2023 11:23:26 AM
 *  Author: Youssef Abbas
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../i_lib/std_types.h"
#include "dio_private.h"
// define ports 
typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}enm_dio_port_t;

// dio value 
typedef enum {
	DIO_LOW = 0,
	DIO_HIGH
}enm_dio_value_t;

// dio direction
typedef enum {
	DIO_IN = 0,
	DIO_OUT
}enm_dio_dir_t;

// DIO Errors
typedef enum {
	DIO_FAIL=0,
	DIO_SUCCESS
}enm_dio_error_t;

typedef struct {
	enm_dio_port_t port;
	uint8 pin;
}str_dio_t;



// DIO functions

enm_dio_error_t dio_init(str_dio_t dio_pin,enm_dio_dir_t dir);

enm_dio_error_t dio_write_pin(str_dio_t dio_pin, enm_dio_value_t value);


enm_dio_error_t dio_toggle(str_dio_t dio_pin);

enm_dio_error_t dio_read_pin(str_dio_t dio_pin,uint8 *value);

enm_dio_error_t dio_write_port(enm_dio_port_t port,enm_dio_value_t value);

enm_dio_error_t dio_read_port(enm_dio_port_t port,uint8 *data);

#endif /* DIO_INTERFACE_H_ */