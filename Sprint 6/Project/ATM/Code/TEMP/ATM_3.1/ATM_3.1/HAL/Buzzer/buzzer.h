/*
 * LED.h
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#ifndef HAL_buzzer_H_
#define HAL_buzzer_H_

/*============= FILE INCLUSION =============*/
#include "../../MCAL/DIO/GPIO.h"


/*============= MACRO DEFINITION =============*/
#define buzzer_logic 1 //1:positive logic , 2:negative logic


/*============= FUNCTION PROTOTYPE =============*/
EN_STATE buzzer_init(uint8 PORT,uint8 buzzer);
EN_STATE buzzer_digitalwrite(uint8 PORT,uint8 buzzer,EN_PIN_VALUE value);

#endif /* HAL_LED_LED_H_ */
