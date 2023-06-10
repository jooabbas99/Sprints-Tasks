/*
 * LED.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "buzzer.h"

/*============= FUNCTION DEFINITION =============*/


void buzzer_init(ST_BUZZER_t buzzer){
	dio_init(buzzer.buzzer_port,buzzer.buzzer_pin,DIO_LOW);
}
void buzzer_digitalwrite(ST_BUZZER_t buzzer,uint8 value){
	dio_write_pin(buzzer.buzzer_port,buzzer.buzzer_pin,value);
}


