#ifndef MOVING_CAR_SYSTEM_LED_H
#define MOVING_CAR_SYSTEM_LED_H

#include "../../MCAL/DIO/dio.h"

/**
 * @enum en_LED_errorState
 * @brief Defines the state of LED functions.
 */
typedef enum EN_LED_API_STATE {
    LED_SUCCESS = 0, LED_FAILED, LED_PORT_INVALID, LED_STATUS_INVALID
}en_LED_errorState;

/**
 * @enum en_LED_state
 * @brief Defines the LED status.
 */
typedef enum EN_LED_STATUS {
    LED_OFF = 0, LED_ON
}en_LED_state;

/**
 * @struct st_LED_config
 * @brief Holds the port number and the pin number of the LED.
 * @var st_LED_config::port
 * Member 'port' specifies the port number.
 * @var st_LED_config::pin
 * Member 'pin' specifies the pin number.
 * @var LED_INIT_t::led_status
 * Member 'led_status' specifies the status of the LED.
 */
typedef struct {
    en_DIO_portNum port;
    en_DIO_pinNum pin;
    en_LED_state led_status;
}st_LED_config;

/**
 * @brief Initializes the pin attached to the LED.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return LED_SUCCESS Initialization is done successfully.
 */
en_LED_errorState LED_Init(st_LED_config *p_led_config_struct);

/**
 * @brief Turns the LED on.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return LED_PORT_INVALID
 * @return LED_SUCCESS
 */
en_LED_errorState LED_On(st_LED_config *p_led_config_struct);

/**
 * @brief Turns the LED off.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return LED_PORT_INVALID
 * @return LED_SUCCESS
 */
en_LED_errorState LED_Off(st_LED_config *p_led_config_struct);

#endif //MOVING_CAR_SYSTEM_LED_H
