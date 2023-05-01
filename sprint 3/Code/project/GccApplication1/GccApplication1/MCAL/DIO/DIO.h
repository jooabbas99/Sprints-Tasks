/*
 * DIO.h
 *
 * Created: 4/6/2023 8:42:11 PM
 *  Author: youss
 */ 


#ifndef DIO_H_
#define DIO_H_

// includes 
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manibulation.h"
// all internal typedefs for DIO 
/**
 * @enum en_DIO_errorState
 * @brief Defines the state of DIO functions.
 */
typedef enum EN_DIO_ERROR_STATE {
    DIO_SUCCESS = 0, DIO_PORT_INVALID, DIO_DIRECTION_INVALID, DIO_PIN_INVALID
}en_DIO_errorState;

/**
 * @enum en_DIO_direction
 * @brief Specifies the state of the pin.
 */
typedef enum EN_DIO_DIRECTION {
    DIO_INPUT = 0, DIO_OUTPUT
}en_DIO_direction;

/**
 * @enum en_DIO_pinNum
 * @brief Specifies the number of pin.
 */
typedef enum EN_DIO_PIN {
   DIO_PIN0 = 0, DIO_PIN1, DIO_PIN2, DIO_PIN3, DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7, DIO_PIN8
}en_DIO_pinNum;

/**
 * @enum en_DIO_portNum
 * @brief Specifies the port number.
 * the port number and returns the address of the corresponding port.
 */
typedef enum EN_DIO_PORT {
    DIO_PORT_A = 0, DIO_PORT_B, DIO_PORT_C, DIO_PORT_D
}en_DIO_portNum;

/**
 * @enum en_DIO_pinLevel
 * @brief Specifies the level of the pin.
 */
typedef enum EN_DIO_LEVEL {
    DIO_LOW = 0, DIO_HIGH
}en_DIO_pinLevel;

/**
 * @struct st_DIO_config
 * @brief Holds the configuration of a specific pin of a port.
 * @var st_DIO_config::port
 * Member 'port' sets the port to be configured.
 * @var st_DIO_config::pin
 * Member 'pin' sets the pin to be configured.
 * @var st_DIO_config::direction
 * Member 'direction' sets the direction of the pin.
 * @var st_DIO_config::pin_value
 * Member 'pin_value; contains the value of the pin when it's configured as input mode.
 * @var st_DIO_config::port_value
 * Member 'port_value' contains the value to be written to the port register if the pin is configured as output.
 */
typedef struct DIO_Init_t {
    en_DIO_portNum port;
    en_DIO_pinNum pin;
    en_DIO_direction direction;
    union {
        uint8_t pin_value;
        uint8_t port_value;
    };
}st_DIO_config;

/**
 * @brief Initializes the direction of the specified pin.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return DIO_PORT_INVALID Port in invalid.
 * @return DIO_SUCCESS The pin initialization is a success.
 */
en_DIO_errorState DIO_Init(st_DIO_config *p_config_struct);

/**
 * @brief Reads the state of a specific pin.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return DIO_PORT_INVALID Port is invalid.
 * @return DIO_DIRECTION_INVALID Reading from a pin that is configured as output.
 * @return DIO_SUCCESS The read operation is a success.
 */
en_DIO_errorState DIO_ReadPin(st_DIO_config *p_config_struct);

/**
 * @brief Write a specific level to a specified pin.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return DIO_PORT_INVALID Port is invalid.
 * @return DIO_DIRECTION_INVALID Writing to a pin that is configured as input.
 * @return DIO_SUCCESS The write operation is a success.
 */
en_DIO_errorState DIO_WritePin(st_DIO_config *p_config_struct);

/**
 * @brief Toggles the current level of a pin.
 * @param[in] p_config_struct Address of the configuration structure.
 *  @return DIO_PORT_INVALID Port is invalid.
 * @return DIO_DIRECTION_INVALID Toggle a pin that is configured as input.
 * @return DIO_SUCCESS The toggle operation is a success.
 */
en_DIO_errorState DIO_TogglePin(st_DIO_config *p_config_struct);

#endif /* DIO_H_ */