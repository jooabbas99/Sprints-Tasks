/*
 * LED.h
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#ifndef HAL_buzzer_H_
#define HAL_buzzer_H_

/*============= FILE INCLUSION =============*/
#include "../../mcal/dio/dio.h"
#include "../../utilities/types.h"



/*============= MACRO DEFINITION =============*/
#define buzzer_logic 1 //1:positive logic , 2:negative logic

typedef struct {
	uint8 buzzer_port;
	uint8 buzzer_pin;
}ST_BUZZER_t;



/*============= FUNCTION PROTOTYPE =============*/

void buzzer_init(ST_BUZZER_t buzzer);
void buzzer_digitalwrite(ST_BUZZER_t buzzer,uint8 value);
#endif /* HAL_LED_LED_H_ */
