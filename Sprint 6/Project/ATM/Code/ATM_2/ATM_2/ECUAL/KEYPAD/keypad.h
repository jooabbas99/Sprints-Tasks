/*
 * keypad.h
 *
 * Created: 5/4/2023 1:17:25 PM
 *  Author: Youssef Abbas
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../utilities/types.h"

typedef struct {
	uint8 number_of_cols;
	uint8 number_of_rows;
	uint8 cols_first_pin;
	uint8 rows_first_pin;
	uint8 cols_port;
	uint8 rows_port;
}ST_KPD_t;


#define KPD_NO_KEY_PRESSED 12
void KPD_init(ST_KPD_t kpd);

void KPD_get_pressed_key(ST_KPD_t kpd,uint8*key);
  
#endif /* KEYPAD_H_ */