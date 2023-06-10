#include "led.h"

/**
 * @brief Initializes the pin attached to the LED.
 * - The function declares a st_DIO_config variable and extract the port and the pin from the p_led_config_struct,
 * with a constant value for the 'direction' member as DIO_OUTPUT.
 * - Then it calls DIO_Init function.
 * - The initial status of the LED is then checked and accordingly it's set.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return LED_SUCCESS Initialization is done successfully.
 */
en_LED_errorState LED_Init(st_LED_config *p_led_config_struct) {
    st_DIO_config led_config = {p_led_config_struct -> port,
                                p_led_config_struct -> pin,
                                DIO_OUTPUT};
    en_DIO_errorState led_dio_state = DIO_Init(&led_config);
	if (led_dio_state != DIO_SUCCESS) {
		return LED_FAILED;
	}
	
	if (p_led_config_struct -> led_status == LED_ON) {
		LED_On(p_led_config_struct);
	} else if (p_led_config_struct -> led_status == LED_OFF) {
		LED_Off(p_led_config_struct);
	}
    return LED_SUCCESS;
}

/**
 *
 * @param p_led_config_struct
 * Turns on the led by setting the pin to high.
 * @return LED_PORT_INVALID
 * @return LED_SUCCESS
 */
en_LED_errorState LED_On(st_LED_config *p_led_config_struct) {
    uint8 port_num = p_led_config_struct -> port;
    switch (port_num) {
        case DIO_PORT_A:
            SET_BIT(PORTA, p_led_config_struct -> pin);
            break;
        case DIO_PORT_B:
            SET_BIT(PORTB, p_led_config_struct -> pin);
            break;
        case DIO_PORT_C:
            SET_BIT(PORTC, p_led_config_struct -> pin);
            break;
        case DIO_PORT_D:
            SET_BIT(PORTD, p_led_config_struct -> pin);
            break;
        default:
            return LED_PORT_INVALID;
    }
    return LED_SUCCESS;
}

/**
 *
 * @param p_led_config_struct
 * Turns off the LED by clearing the pin.
 * @return LED_PORT_INVALID
 * @return LED_SUCCESS
 */
en_LED_errorState LED_Off(st_LED_config *p_led_config_struct) {
    uint8 port_num = p_led_config_struct -> port;
    switch (port_num) {
        case DIO_PORT_A:
            CLEAR_BIT(PORTA, p_led_config_struct -> pin);
            break;
        case DIO_PORT_B:
            CLEAR_BIT(PORTB, p_led_config_struct -> pin);
            break;
        case DIO_PORT_C:
            CLEAR_BIT(PORTC, p_led_config_struct -> pin);
            break;
        case DIO_PORT_D:
            CLEAR_BIT(PORTD, p_led_config_struct -> pin);
            break;
        default:
            return LED_PORT_INVALID;
    }
    return LED_SUCCESS;
}
