/*
 * button.h
 *
 * Created: 4/6/2023 10:29:47 PM
 *  Author: youss
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../mcal/dio/dio.h"
#include "../../utilities/types.h"

#define BUTTON_HIGH 1
#define BUTTON_LOW 0

#define EXT_INT_BTN_PORT PORT_D
#define EXT_INT_BTN_PIN PIN2

#define BTN_2_SECOND 1500
#define BTN_MIN_SECOND 50

#define BTN_ZERO_PRESSED 10
#define BTN_ENTER_PRESSED 11
#define BTN_NO_PRESS	12

typedef struct {
	uint8 button_port;
	uint8 button_pin;
}ST_PBTN_t;


void BUTTON_init(ST_PBTN_t button);
void BUTTON_status(ST_PBTN_t button,uint8 *status);
void BUTTON_read_zero_enter(ST_PBTN_t button,uint8 * value);

void BUTTON_enter(void);


#endif /* BUTTON_H_ */