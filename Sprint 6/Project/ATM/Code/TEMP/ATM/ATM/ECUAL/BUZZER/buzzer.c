/*
 * LED.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "buzzer.h"

/*============= FUNCTION DEFINITION =============*/


void buzzer_init(uint8_t buzzer_port , uint8_t buzzer_pin){
	dio_init(buzzer_port,buzzer_pin,DIO_LOW);
}
void buzzer_digitalwrite(uint8_t buzzer_port , uint8_t buzzer_pin,uint8_t value){
	dio_write_pin(buzzer_port,buzzer_pin,value);
}


