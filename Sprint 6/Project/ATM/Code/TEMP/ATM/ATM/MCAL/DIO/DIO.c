//
// Created by Youssef Abbas on 25/04/2023.
//

#include "./DIO.h"
#include "../../Utilities/bit_math.h"

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
EN_DIO_ERROR_t dio_init(uint8_t port,uint8_t pin,uint8_t dir){
    switch(port){
        case PORT_A:
            (dir == DIO_IN) ? CLEAR_BIT(DDRA,pin) :SET_BIT(DDRA,pin);
            break;
        case PORT_B:
            (dir == DIO_IN) ? CLEAR_BIT(DDRB,pin) :SET_BIT(DDRB,pin);
            break;
        case PORT_C:
            (dir == DIO_IN) ? CLEAR_BIT(DDRC,pin) :SET_BIT(DDRC,pin);
            break;
        case PORT_D:
            (dir == DIO_IN) ? CLEAR_BIT(DDRD,pin) :SET_BIT(DDRD,pin);
            break;
        default:
            return DIO_FAIL;
            break;
    }
    return DIO_SUCCESS;
}

EN_DIO_ERROR_t dio_write_pin(uint8_t port, uint8_t pin, uint8_t value)
{
    switch(port){
        case PORT_A:
            (value == DIO_LOW) ? CLEAR_BIT(PORTA,pin) :SET_BIT(PORTA,pin);
            break;
        case PORT_B:
            (value == DIO_LOW) ? CLEAR_BIT(PORTB,pin) :SET_BIT(PORTB,pin);
            break;
        case PORT_C:
            (value == DIO_LOW) ? CLEAR_BIT(PORTC,pin):SET_BIT(PORTC,pin);
            break;
        case PORT_D:
            (value == DIO_LOW) ? CLEAR_BIT(PORTD,pin):SET_BIT(PORTD,pin);
            break;
        default:
            return DIO_FAIL;
            break;
    }
    return DIO_SUCCESS;
}

EN_DIO_ERROR_t dio_toggle(uint8_t port,uint8_t pin){
    switch(port){
        case PORT_A:
            TOGGLE_BIT(PORTA,pin);
            break;
        case PORT_B:
            TOGGLE_BIT(PORTB,pin);
            break;
        case PORT_C:
            TOGGLE_BIT(PORTC,pin);
            break;
        case PORT_D:
            TOGGLE_BIT(PORTD,pin);
            break;
        default:
            return DIO_FAIL;
            break;
    }
    return DIO_SUCCESS;

}

EN_DIO_ERROR_t dio_read_pin(uint8_t port, uint8_t pin,uint8_t *data)
{
    switch(port){
        case PORT_A:
            *data = READ_BIT(PINA,pin);
            break;
        case PORT_B:
            *data =READ_BIT(PINB,pin);
            break;
        case PORT_C:
            *data =READ_BIT(PINC,pin);
            break;
        case PORT_D:
            *data =READ_BIT(PIND,pin);
            break;
        default:
            return DIO_FAIL;
            break;
    }
    return DIO_SUCCESS;
}