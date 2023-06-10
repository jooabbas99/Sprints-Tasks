/*
 * TIMER_interface.h
 *
 * Created: 4/15/2023 11:55:15 PM
 *  Author: youss
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "TIMER_registers.h"
#include "../../Utilities/bit_manibulation.h"
/************************************************************************/
/*                              DATA TYPE                                */
/************************************************************************/
/* TCCR0 REGSTERS
	Timer/Counter Control Register – TCCR0 
*/
#define CS00		0 // R/W
#define CS01		1 // R/W
#define CS02		2 // R/W
#define WGM01		3 // R/W
#define COM00		4 // R/W
#define COM01		5 // R/W
#define WGM00		6 // R/W
#define FOC0		7 // W


/* TIMSK REGSTERS */
#define TOIE0		0
#define OCIE0		1
#define TOIE1		2
#define OCIE1A		3
#define OCIE1B		4
#define TICIE1		5
#define TOIE2		6
#define OCIE2		7

/* TIFR REGSTERS */
#define TOV0		0
#define OCF0		1
#define TOV1		2
#define OCF1A		3
#define OCF1B		4
#define ICF1		5
#define TOV2		6
#define OCF2		7


/* section : Data Types Declarations*/

typedef enum {
	TIMER_MODE_NORMAL,
	TIMER_MODE_PWM,
	TIMER_MODE_CTC
}EN_timer_mode_t;

typedef enum {
	PWM_NORMAL_DISCONNECTED,
	PWM_MODE_0=2,
	PWM_MODE_1=3
}EN_PWM_mode_t;

typedef enum{
	TIMER_STOP,
	TIMER_PRESCALLER_0,
	TIMER_PRESCALLER_8,
	TIMER_PRESCALLER_64,
	TIMER_PRESCALLER_256,
	TIMER_PRESCALLER_1024,
	TIMER_EXT_CLK_FALLING_EDGE,
	TIMER_EXT_CLK_RISING_EDGE
}EN_timer_prescaller_t;


typedef struct{
	EN_timer_mode_t timer_mode;
	EN_timer_prescaller_t timer_prescaller;
	uint16_t OCR;
	uint8_t timer_oc_interrupt :1;
	uint8_t timer_of_interrupt :1;

}ST_timer_config_t;


void TIMER0_init(ST_timer_config_t *timer_configuration);

void timer_start(ST_timer_config_t *timer_configuration);

void timer_stop(ST_timer_config_t *timer_configuration);

void timer_initialize_callback_OVF(void (*callback)(void));

void timer_initialize_callback_COMP(void (*callback)(void));


#endif /* TIMER_INTERFACE_H_ */