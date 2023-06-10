/*
 * timer.h
 *
 * Created: 4/10/2023 9:58:47 PM
 *  Author: youss
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utilities/bit_manibulation.h"
#include "../../Utilities/registers.h"
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


#define NORMAL_MODE         0
#define PHASE_CORRECT_PWM   1
#define CTC_MODE            2
#define FAST_PWM            3

#define INVERTING_MODE 0
#define NON_INVERTING_MODE 1

#define NO_CLK 0
#define CLK_1024 5

#define WAVE_GENERATION_MODE      NORMAL_MODE
#define TIMER0_PRESCALAR     CLK_1024
#define TIMER0_PWM_MODE  NON_INVERTING_MODE

// CPU 
#define F_CPU  16
#define PRESCALER 1024


void timer0_init(void);
void timer0_start(void);
void timer0_stop(void);
void timer0_set_delay(uint32_t delay);
void timer0_set_overflow_delay(uint32_t delay);
void timer0_set_ctc_delay(uint32_t delay,uint8_t OCR);
void timer0_loop(void);


#endif /* TIMER_H_ */