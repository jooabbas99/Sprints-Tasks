//
// Created by Youssef Abbas on 05/04/2023.
//

#ifndef ES_1_MOVING_CAR_DESIGN_TIMER_H
#define ES_1_MOVING_CAR_DESIGN_TIMER_H
#include <stdint.h>
typedef enum {
    TIMER_ERROR=0,
    TIMER_OK
}EN_timer_error_t;


/*
* TIMER_MODE_NORMAL
* TIMER_MODE_PWM  Pulse Width Modulation
* TIMER_MODE_CTC  Clear Timer on Compare Match
 */
typedef enum{
    TIMER_MODE_NORMAL,
    TIMER_MODE_PWM,
    TIMER_MODE_CTC,
}timer_mode_t;

/*
* PWM_NORMAL_DISCONNECTED
* PWM_MODE_0  Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting
* PWM_MODE_1  Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
*
*/
typedef enum{
    PWM_NORMAL_DISCONNECTED=0,
    PWM_MODE_0=2,
    PWM_MODE_1=3,
}PWM_mode_t;

/*
*  timer_mode timer mode
*  OCR the initial value of OCR
*  timer_oc_interrupt Enable or Disable interrupt compare match
*  timer_of_interrupt Enable or Disable interrupt overflow
*/
typedef struct
{   timer_mode_t timer_mode;
    uint8_t OCR;
    uint8_t timer_oc_interrupt :1;
    uint8_t timer_of_interrupt :1;

}timer_configuration_t;

/*section : Global variable*/
static void (*timer_callback_OVF)(void);
static void (*timer_callback_COMP)(void);

/* section : Function Declaration*/

/*
*   -Description-
*-this function init the timer configuration
*
*   -Input Output parameters -
*-1-it holds timer configuration  (timer_configuration_t *timer_configuration)
*
*   -Return-
*-1- TIMER_ERROR if there is something wrong
*-2- TIMER_OK otherwise
*/
EN_timer_error_t timer_init(timer_configuration_t *timer_configuration);

/*
*   -Description-
*-this function init timer_callback_OVF with address of callback address
*
*   -Input Output parameters -
*-1-it is pointer to callback funtion  (void (*callback)(void))
*
*   -Return-
*-1- TIMER_ERROR if there is something wrong
*-2- TIMER_OK otherwise
*/
EN_timer_error_t timer_init_callback_OVF(void (*callback)(void));

/*
*   -Description-
*-this function init timer_callback_COMP with address of callback address
*
*   -Input Output parameters -
*-1-it is pointer to callback funtion  (void (*callback)(void))
*   -Return-
*-1- TIMER_ERROR if there is something wrong
*-2- TIMER_OK otherwise
*/
EN_timer_error_t timer_init_callback_COMP(void (*callback)(void));

ISR (TIMER_OVF_vect)        //Timer overflow interrupt
{
        timer_callback_OVF();
}
ISR (TIMER_COMP_vect)       //Timer compare match interrupt
{
        timer_callback_OVF();
}

#endif //ES_1_MOVING_CAR_DESIGN_TIMER_H
