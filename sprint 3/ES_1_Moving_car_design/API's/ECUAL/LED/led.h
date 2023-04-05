//
// Created by Youssef Abbas on 05/04/2023.
//

#ifndef ES_1_MOVING_CAR_DESIGN_LED_H
#define ES_1_MOVING_CAR_DESIGN_LED_H
#include <stdint.h>
//EN_LED_status_t datatype enum has all led states
typedef enum {
    LED_OFF=0,
    LED_ON=1,
}EN_LED_status_t;

typedef enum {
    LED_ERROR=0,
    LED_OK=1,
}EN_LED_ERROR_t;

//* -timer_configuration_t datatype hold the transaction data
//*   -Members-
//* -1-  (uint8_t port_name) port name contains the pin that connected to led
//* -2-  (uint8_t pin) that pin connected to led
//* -3-  (uint8_t led_status) led status
typedef struct{
    uint8_t port_name;
    uint8_t pin;
    EN_LED_status_t led_status;
}ST_LED_config_t;



/*
*   -Description-
*-this function init led configuration
*
*   -Input Output parameters -
*-1-it holds led configuration  (ST_LED_config_t *led)
*
*   -Return-
*-1- (LED_ERROR) if there is something wrong
*-2- (LED_OK) otherwise
*/

EN_LED_status_t led_init(ST_LED_config_t *led);

/*
*   -Description-
*-this function to turn on led
*
*   -Input Output parameters -
*-1-it holds led configuration  (ST_LED_config_t *led)
*   -Return-
*-1- (LED_ERROR) if there is something wrong
*-2- (LED_OK) otherwise
*/
EN_LED_status_t led_turn_on(ST_LED_config_t *led);

/*
*   -Description-
*-this function to turn off led
*
*   -Input Output parameters -
*-1-it holds led configuration  (ST_LED_config_t *led)
*   -Return-
*-1- (LED_ERROR) if there is something wrong
*-2- (LED_OK) otherwise
*/
EN_LED_status_t led_turn_off(ST_LED_config_t *led);


/*
*   -Description-
*-this function to toggle led
*
*   -Input Output parameters -
*-1-it holds led configuration  (ST_LED_config_t *led)
*
*   -Return-
*-1- (LED_ERROR) if there is something wrong
*-2- (LED_OK) otherwise
*/
EN_LED_status_t led_toggle(ST_LED_config_t *led);

#endif //ES_1_MOVING_CAR_DESIGN_LED_H
