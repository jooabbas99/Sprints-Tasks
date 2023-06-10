/*
 * button.h
 *
 * Created: 5/4/2023 12:40:41 PM
 *  Author: Youssef Abbas
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../Utilities/Std_Types.h"
#define BUTTON_HIGH 1
#define BUTTON_LOW 0

#define EXT_INT_BTN_PORT PORT_D
#define EXT_INT_BTN_PIN PIN2

void BUTTON_init(uint8 button_port , uint8 button_pin);
void BUTTON_status(uint8 button_port , uint8 button_pin,uint8 *status);



#endif /* BUTTON_H_ */