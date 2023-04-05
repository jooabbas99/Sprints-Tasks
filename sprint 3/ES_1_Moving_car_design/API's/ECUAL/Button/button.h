//
// Created by Youssef Abbas on 05/04/2023.
//

#ifndef ES_1_MOVING_CAR_DESIGN_BUTTON_H
#define ES_1_MOVING_CAR_DESIGN_BUTTON_H
#include "../../MCAL/DIO/DIO.h"

/*
*
*
* -button_state_t datatype enum has all button state
*   -Members-
*
* -1-BUTTON_RELEASED
* -2-BUTTON_PRESSED
*
*
*/
typedef enum {
    BUTTON_RELEASED=0,
    BUTTON_PRESSED

}EN_button_state_t;

typedef enum {
    BUTTON_ERROR=0,
    BUTTON_OK

}EN_button_error_t;
/*
*
*
* -button_state_t datatype enum has all activaton state of button

* -1-BUTTON_ACTIVE_LOW
* -2-BUTTON_ACTIVE_HIGH
*/

typedef enum{
    BUTTON_ACTIVE_LOW=0,
    BUTTON_ACTIVE_HIGH
}EN_button_active_t;



/*
*
*
* -button_t datatype hold motor driver configuration
*   -Members-
* -1-  (pin_config_t button_pin) pin configration connected to that button
* -2-  (button_state_t button_state) released or pressed
* -3-  (button_active_t button_active) activation state
*
*/
typedef struct{
    ST_DIO_config_t button_pin;
    EN_button_state_t button_state;
    EN_button_active_t button_active;
}EN_button_t;



/* section : Function Declaration*/

/*
*   -Description-
*-this function init button
*
*   -Input Output parameters -
*-1-it holds button configuration  (button_t* btn)

*/
EN_button_error_t button_init(const EN_button_t* btn);



/*
*   -Description-
*-this function init button
*
*   -Output parameters -
*-1-it holds the state of button (button_state_t *btn_state)
*   -Input Output parameters -
*-1-it holds button configuration  (button_t* btn)

*/
EN_button_error_t button_read_state( EN_button_t *btn, EN_button_state_t *btn_state);
#endif //ES_1_MOVING_CAR_DESIGN_BUTTON_H
