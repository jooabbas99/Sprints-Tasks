/*
 * timer.c
 *
 * Created: 4/10/2023 9:58:40 PM
 *  Author: youss
 */ 
#include "timer.h"

uint32_t number_of_overflow = 0;
uint32_t timer_init_value = 0;


void timer0_init(void){
		if (WAVE_GENERATION_MODE == NORMAL_MODE){
			CLEAR_BIT(TCCR0, WGM01);
			CLEAR_BIT(TCCR0, WGM00);
		}
		else if( WAVE_GENERATION_MODE == PHASE_CORRECT_PWM){
			CLEAR_BIT(TCCR0, WGM01);
			SET_BIT(TCCR0, WGM00);
		}
		else if( WAVE_GENERATION_MODE == CTC_MODE){
			SET_BIT(TCCR0, WGM01);
			CLEAR_BIT(TCCR0, WGM00);
		}
		else if (WAVE_GENERATION_MODE == FAST_PWM){
			SET_BIT(TCCR0, WGM01);
			SET_BIT(TCCR0, WGM00);
		}
}
void timer0_loop(){
	uint32_t counter = 0;
	while(counter < number_of_overflow){
		// stop after one overflow
		while((TIFR & (1<<0)) == 0);
		//clear overflow
		TIFR |= (1<<0);
		counter ++;
	}
}
void timer0_start(void){
	if (TIMER0_PRESCALAR == CLK_1024){
		SET_BIT(TCCR0, CS02);
		CLEAR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
	}
}
void timer0_stop(void){
		if (TIMER0_PRESCALAR == NO_CLK){
			CLEAR_BIT(TCCR0, CS02);
			CLEAR_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS00);
		}
}
void timer0_set_delay(uint32_t delay){
		if (WAVE_GENERATION_MODE == NORMAL_MODE){
			uint8_t tick = PRESCALER / F_CPU; // p = 1024 , Fcpu = 16
			uint32_t total_number_of_overflows = (delay * 1000) / tick;
			number_of_overflow = total_number_of_overflows / 256;
			timer_init_value = 256 - (total_number_of_overflows % 256);
			TCNT0 = timer_init_value;
			number_of_overflow ++;
		}
		else if( WAVE_GENERATION_MODE == CTC_MODE){
			uint8_t tick = PRESCALER / F_CPU;
			uint32_t number_of_ticks = (delay * 1000) / tick;
			OCR0 = number_of_ticks - 1;
			number_of_overflow++;
		}		
}
void timer0_set_overflow_delay(uint32_t delay){
	uint8_t tick =  PRESCALER / F_CPU;
	uint32_t total_number_of_overflows = 256 * tick;
	number_of_overflow = (delay * 1000) / total_number_of_overflows;
	timer_init_value = 256 - (delay % 256);
	TCNT0 = timer_init_value;
	number_of_overflow++;
}
void timer0_set_ctc_delay(uint32_t delay,uint8_t OCR){
	uint8_t tick = PRESCALER / F_CPU;
	uint32_t total_number_of_overflows = (delay * 1000) / tick;
	number_of_overflow = total_number_of_overflows / OCR;
	number_of_overflow ++;
}
