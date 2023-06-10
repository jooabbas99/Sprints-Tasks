//
// Created by Youssef Abbas on 05/04/2023.
//

#ifndef ES_1_MOVING_CAR_DESIGN_DIO_H
#define ES_1_MOVING_CAR_DESIGN_DIO_H
#include <stdint.h>
typedef enum EN_pins{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
}EN_pins;

typedef enum EN_pin_mode_t{
    DIO_INPUT=0,
    DIO_OUTPUT=1
}EN_mode_t;

typedef enum EN_pin_value_t{
    LOW=0,
    HIGH
}EN_pin_value_t;
typedef enum EN_port_t{
    PORTA=0,
    PORTB,
    PORTC,
    PORTD
}EN_port_t;

typedef struct ST_DIO_config_t{
    EN_port_t port;
    EN_mode_t mode;
    EN_pin_value_t value;
    EN_pins pin;
}ST_DIO_config_t;
typedef enum EN_DIO_ERROR_t{
    DIO_ERROR=0,
    DIO_OK
}EN_DIO_ERROR_t;

EN_DIO_ERROR_t DIO_init(ST_DIO_config_t * configurations);
EN_DIO_ERROR_t DIO_write(ST_DIO_config_t *configurations , uint8_t data);
EN_DIO_ERROR_t DIO_read(ST_DIO_config_t *configurations , uint8_t *data);
EN_DIO_ERROR_t DIO_toggle(ST_DIO_config_t *configurations);

#endif //ES_1_MOVING_CAR_DESIGN_DIO_H
