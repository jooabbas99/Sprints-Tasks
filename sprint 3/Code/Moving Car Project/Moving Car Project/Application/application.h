/*
 * Application.h
 *
 * Created: 4/13/2023 11:28:36 PM
 *  Author: youss
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../HAL/BUTTON/BUTTON.h"
#include "../HAL/DC_MOTOR/DCmotor.h"
#include "../HAL/LED/LED.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER0/TIMER_0.h"
#include "../MCAL/EINT/EINT.h"

typedef enum{
	FWD,BWD,RIGHT,LEFT,G_STOP
}EN_direction_state;

void _4_motors_control(ST_DCM_t m1,ST_DCM_t m2,ST_DCM_t m3,ST_DCM_t m4,EN_direction_state state,uint8 speed);
void stop_car (void);
void app_init(void);
void app_start(void);


#endif /* APPLICATION_H_ */