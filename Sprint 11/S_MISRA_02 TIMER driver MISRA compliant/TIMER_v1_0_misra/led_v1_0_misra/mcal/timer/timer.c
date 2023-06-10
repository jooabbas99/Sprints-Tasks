/*
 * timer.c
 *
 * Created: 6/10/2023 10:21:49 AM
 *  Author: Youssef Abbas
 */ 
#include "timer_interface.h"
#include "timer_registers.h"

uint32_t number_of_overflow = 0;
uint32_t timer_init_value = 0;


enm_timer0_error_t timer0_init(str_timer0_conf_t str_timer0_conf){
	enm_timer0_error_t ret_err = TIMER_OK;
	switch(str_timer0_conf.enm_timer0_modes){
		case  NORMAL_MODE :
		CLEAR_BIT(TCCR0, WGM01);
		CLEAR_BIT(TCCR0, WGM00);
		break;
		case PHASE_CORRECT_PWM:
		CLEAR_BIT(TCCR0, WGM01);
		SET_BIT(TCCR0, WGM00);
		break;
		case CTC_MODE:
		SET_BIT(TCCR0, WGM01);
		CLEAR_BIT(TCCR0, WGM00);
		break;
		case FAST_PWM:
		SET_BIT(TCCR0, WGM01);
		SET_BIT(TCCR0, WGM00);
		break;
		default:
		ret_err = TIMER_NOT_OK;
		break;
	}
	return ret_err;
}
void timer0_loop(void){
	uint32_t counter = 0;
	while(counter < number_of_overflow){
		// stop after one overflow
		while((TIFR & (1<<0)) == 0);
		//clear overflow
		TIFR |= (1<<0);
		counter ++;
	}
}
enm_timer0_error_t timer0_start(str_timer0_conf_t str_timer0_conf){
	enm_timer0_error_t ret_err = TIMER_OK;
	switch(str_timer0_conf.enm_timer0_prescaller){
		case CLK_1024:
		SET_BIT(TCCR0, CS02);
		CLEAR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
		break;
		default:
		ret_err = TIMER_NOT_OK;
		break;
	}
		return ret_err ;
}
enm_timer0_error_t timer0_stop(str_timer0_conf_t str_timer0_conf){
	enm_timer0_error_t ret_err = TIMER_OK;
	switch(str_timer0_conf.enm_timer0_prescaller){
		case NO_CLK:
		CLEAR_BIT(TCCR0, CS02);
		CLEAR_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS00);
		break;
		default:
		ret_err = TIMER_NOT_OK;
		break;
	}
	return ret_err;
}
enm_timer0_error_t timer0_set_delay(str_timer0_conf_t str_timer0_conf,uint32_t delay){
	enm_timer0_error_t ret_err = TIMER_OK;
	switch(str_timer0_conf.enm_timer0_modes){
		case NORMAL_MODE:
		uint8_t tick = str_timer0_conf.enm_timer0_prescaller / F_CPU; // p = 1024 , Fcpu = 16
		uint32_t total_number_of_overflows = (delay * 1000) / tick;
		number_of_overflow = total_number_of_overflows / 256;
		timer_init_value = 256 - (total_number_of_overflows % 256);
		TCNT0 = timer_init_value;
		number_of_overflow ++;
		break;
		case CTC_MODE:
		uint8_t tick = str_timer0_conf.enm_timer0_prescaller / F_CPU;
		uint32_t number_of_ticks = (delay * 1000) / tick;
		OCR0 = number_of_ticks - 1;
		number_of_overflow++;
		break;
		default:
		ret_err = TIMER_NOT_OK;
		break;
	}
	return ret_err;
}
enm_timer0_error_t timer0_set_overflow_delay(str_timer0_conf_t str_timer0_conf,uint32_t delay){
	uint8_t tick =  str_timer0_conf.enm_timer0_prescaller / F_CPU;
	uint32_t total_number_of_overflows = 256 * tick;
	number_of_overflow = (delay * 1000) / total_number_of_overflows;
	timer_init_value = 256 - (delay % 256);
	TCNT0 = timer_init_value;
	number_of_overflow++;
	
	
	return TIMER_OK;
}
enm_timer0_error_t timer0_set_ctc_delay(str_timer0_conf_t str_timer0_conf,uint32_t delay,uint8_t OCR){
	
	uint8_t tick = str_timer0_conf.enm_timer0_prescaller / F_CPU;
	uint32_t total_number_of_overflows = (delay * 1000) / tick;
	number_of_overflow = total_number_of_overflows / OCR;
	number_of_overflow ++;
	
	return TIMER_OK;
}
