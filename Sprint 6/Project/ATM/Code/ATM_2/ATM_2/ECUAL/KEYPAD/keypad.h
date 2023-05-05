/*
 * keypad.h
 *
 * Created: 5/4/2023 1:17:25 PM
 *  Author: Youssef Abbas
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../Utilities/types.h"

typedef struct {
	uint8_t number_of_cols;
	uint8_t number_of_rows;
	uint8_t cols_first_pin;
	uint8_t rows_first_pin;
	uint8_t cols_port;
	uint8_t rows_port;
}ST_KPD_t;


#define NO_KEY_PRESSED 0
void KPD_init(ST_KPD_t kpd);

uint8_t KPD_get_pressed_key(ST_KPD_t kpd);
  
#endif /* KEYPAD_H_ */