/*
 * LED.h
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#ifndef HAL_buzzer_H_
#define HAL_buzzer_H_

/*============= FILE INCLUSION =============*/
#include "../../MCAL/DIO/DIO.h"
#include "../../Utilities/types.h"



/*============= MACRO DEFINITION =============*/
#define buzzer_logic 1 //1:positive logic , 2:negative logic


/*============= FUNCTION PROTOTYPE =============*/

void buzzer_init(uint8_t buzzer_port , uint8_t buzzer_pin);
void buzzer_digitalwrite(uint8_t buzzer_port , uint8_t buzzer_pin,uint8_t value);
#endif /* HAL_LED_LED_H_ */
