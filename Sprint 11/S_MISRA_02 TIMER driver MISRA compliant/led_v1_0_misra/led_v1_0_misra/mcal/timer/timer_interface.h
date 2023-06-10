/*
 * timer_interface.h
 *
 * Created: 6/10/2023 10:20:42 AM
 *  Author: Youssef Abbas
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
#include "timer_registers.h"

/* TCCRO REGSTERS */
#define CS00		0
#define CS01		1
#define CS02		2
#define WGM01		3
#define COM00		4
#define COM01		5
#define WGM00		6
#define FOC0		7

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

typedef enum {
	NORMAL_MODE        = 0,
	PHASE_CORRECT_PWM  = 1,
	CTC_MODE           = 2,
	FAST_PWM           = 3
}enm_timer0_modes_t;

typedef enum {
	INVERTING_MODE		= 0,
	NON_INVERTING_MODE	= 1	
}enm_timer0_inverting_mode_t;

typedef enum {
	NO_CLK		=	0,
	CLK_1024	=	5
}enm_timer0_prescaller_t;


typedef enum {
	TIMER_NOT_OK = 0,
	TIMER_OK = 1
}enm_timer0_error_t;

typedef struct {
	enm_timer0_modes_t enm_timer0_modes;
	enm_timer0_inverting_mode_t  enm_timer0_inverting_mode;
	enm_timer0_prescaller_t	enm_timer0_prescaller;
}str_timer0_conf_t;

enm_timer0_error_t timer0_init(str_timer0_conf_t str_timer0_conf);
enm_timer0_error_t timer0_start(str_timer0_conf_t str_timer0_conf);
enm_timer0_error_t timer0_stop(str_timer0_conf_t str_timer0_conf);
enm_timer0_error_t timer0_set_delay(str_timer0_conf_t str_timer0_conf , uint32_t delay);
enm_timer0_error_t timer0_set_overflow_delay(str_timer0_conf_t str_timer0_conf,uint32_t delay);
enm_timer0_error_t timer0_set_ctc_delay(str_timer0_conf_t str_timer0_conf,uint32_t delay,uint8_t OCR);
void timer0_loop(void);




#endif /* TIMER_INTERFACE_H_ */