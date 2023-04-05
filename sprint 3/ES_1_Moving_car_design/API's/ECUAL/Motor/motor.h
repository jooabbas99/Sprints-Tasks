//
// Created by Youssef Abbas on 05/04/2023.
//

#ifndef ES_1_MOVING_CAR_DESIGN_MOTOR_H
#define ES_1_MOVING_CAR_DESIGN_MOTOR_H
#include "../../MCAL/DIO/DIO.h"
/*
* -dc_motor_status_t datatype enum has all motor status
*   -Members-
*/
typedef enum{
    DC_MOTOR_OFF=0,
    DC_MOTOR_ON
}EN_DC_motor_status_t;


typedef enum{
    DC_MOTOR_ERROR=0,
    DC_MOTOR_OK
}EN_DC_motor_error_t;


/*
*
*
* -dc_motor_direction_t datatype enum has all motor direction
*   -Members-
*
* -1-DC_MOTOR_RIGHT
* -2-DC_MOTOR_LEFT
*
*
*/
typedef enum{
    DC_MOTOR_RIGHT=0,
    DC_MOTOR_LEFT
}EN_DC_motor_direction_t;


/*
*
*
* -dc_motor_config_t datatype hold motor driver configuration
*/
typedef struct{
    ST_DIO_config_t dc_motor_pins[2];
    ST_DIO_config_t dc_motor_EN;
    EN_DC_motor_status_t dc_motor_status;
    EN_DC_motor_direction_t dc_motor_direction;
    uint8_t dc_motor_speed ;
}dc_motor_config_t;

/* section : Function Declaration*/


/*
*   -Description-
*-this function init motor driver
*
*   -Input Output parameters -
*-1-it holds motor driver configuration  (tdc_motor_config_t *dc_motor)

*/
EN_DC_motor_error_t motor_initialize(const dc_motor_config_t *dc_motor);



/*
*   -Description-
*-this function turn on motor driver
*
*   -Input Output parameters -
*-1-it holds motor driver configuration  (tdc_motor_config_t *dc_motor)
*-2-it holds motor direction  (dc_motor_direction_t dc_motor_direction)

*/
EN_DC_motor_error_t motor_turn_on(dc_motor_config_t *dc_motor, EN_DC_motor_direction_t dc_motor_direction );

/*
*   -Description-
*-this function turn off motor
*
*   -Input Output parameters -
*-1-it holds motor driver configuration  (dc_motor_config_t *dc_motor)
*/
EN_DC_motor_error_t motor_stop(dc_motor_config_t *dc_motor);

/*
*   -Description-
*-this function set motor speed
*
*   -Input Output parameters -
*-1-it holds motor driver configuration  (dc_motor_config_t *dc_motor)
*-1-it holds motor speed  (uint8_t dc_motor_speed)

*/
EN_DC_motor_error_t motor_set_speed(dc_motor_config_t *dc_motor, uint8_t dc_motor_speed);
#endif //ES_1_MOVING_CAR_DESIGN_MOTOR_H
