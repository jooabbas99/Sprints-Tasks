//
// Created by Youssef Abbas on 25/04/2023.
//

#ifndef ATMEGA32A_DIO_H
#define ATMEGA32A_DIO_H
#include "dio_registers.h"
#include "../../utilities/types.h"
// DIO pin configuration
#define DIO_IN      0
#define DIO_OUT     1
// DIO pin Values
#define DIO_LOW     0
#define DIO_HIGH    1

// PORTS
#define PORT_A      0
#define PORT_B      1
#define PORT_C      2
#define PORT_D      3


// DIO Errors
typedef enum {
    DIO_FAIL=0,
    DIO_SUCCESS
}EN_DIO_ERROR_t;


// DIO functions
/*
 *
    dio_init
    Parameters:

    port: The port number, which can be PORT_A, PORT_B, PORT_C, or PORT_D.
    pin: The pin number, which can be 0 to 7.
    dir: The pin direction, which can be DIO_INPUT or DIO_OUTPUT.
    Return value:

    DIO_SUCCESS: The function succeeded.
    DIO_FAIL: The function failed.
    Description:

    The dio_init function initializes the specified pin as an input or output pin.
 */
EN_DIO_ERROR_t dio_init(uint8 port,uint8 pin,uint8 dir);

/*
 * dio_write_pin

    Parameters:

    port: The port number, which can be PORT_A, PORT_B, PORT_C, or PORT_D.
    pin: The pin number, which can be 0 to 7.
    value: The pin value, which can be DIO_LOW or DIO_HIGH.
    Return value:

    DIO_SUCCESS: The function succeeded.
    DIO_FAIL: The function failed.
    Description:

    The dio_write_pin function writes the specified pin to a high or low level.


 */
EN_DIO_ERROR_t dio_write_pin(uint8 port, uint8 pin, uint8 value);

/*
     dio_toggle

    Parameters:

    port: The port number, which can be PORT_A, PORT_B, PORT_C, or PORT_D.
    pin: The pin number, which can be 0 to 7.
    Return value:

    DIO_SUCCESS: The function succeeded.
    DIO_FAIL: The function failed.
    Description:

    The dio_toggle function toggles the specified pin.


 */
EN_DIO_ERROR_t dio_toggle(uint8 port,uint8 pin);

/*
 * dio_read_pin

    Parameters:

    port: The port number, which can be PORT_A, PORT_B, PORT_C, or PORT_D.
    pin: The pin number, which can be 0 to 7.
    data: A pointer to a variable to store the pin value.
    Return value:

    DIO_SUCCESS: The function succeeded.
    DIO_FAIL: The function failed.
    Description:

    The dio_read_pin function reads the value of the specified pin and stores it in the variable pointed to by data.


 */
EN_DIO_ERROR_t dio_read_pin(uint8 port, uint8 pin,uint8 *value);




EN_DIO_ERROR_t dio_write_port(uint8 port,uint8 value);
EN_DIO_ERROR_t dio_read_port(uint8 port,uint8 *data);

#endif //ATMEGA32A_DIO_H
