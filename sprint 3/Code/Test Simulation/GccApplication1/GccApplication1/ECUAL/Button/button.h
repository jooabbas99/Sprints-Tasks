/*
 * button.h
 *
 * Created: 4/6/2023 10:29:47 PM
 *  Author: youss
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"

#define BUTTON_1_PORT PORT_C
#define BUTTON_1_PIN PIN4

#define BUTTON_2_PORT PORT_B
#define BUTTON_2_PIN PIN2

#define BUTTON_HIGH 1
#define BUTTON_LOW 0

void BUTTON_init(uint8_t button_port , uint8_t button_pin);
void BUTTON_status(uint8_t button_port , uint8_t button_pin,uint8_t *status);




#endif /* BUTTON_H_ */