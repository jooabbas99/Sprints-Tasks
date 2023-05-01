/*
 * timer.c
 *
 * Created: 4/15/2023 11:54:40 PM
 *  Author: youssef
 */ 
#include "TIMER_interface.h"

// TIMER0 ISR
void __vector_10 (void) __attribute__ ((signal,used));
void __vector_11 (void) __attribute__ ((signal,used));


// CALL BACK POINTERS
static void (*TIMER0_OVCallBackPointer)(void) = NULL;
static void (*TIMER0_CTCCallBackPointer)(void) = NULL;


void TIMER0_init(ST_timer_config_t *timer_configuration){

	TCCR0 |= ((1&timer_configuration->timer_mode)<<WGM00);
	TCCR0 |= ((timer_configuration->timer_mode>>1)<<WGM01);
	if(timer_configuration->timer_mode == TIMER_MODE_NORMAL){
			
		TIMSK |= ((timer_configuration->timer_oc_interrupt<<1)|timer_configuration->timer_of_interrupt);
		if(timer_configuration->timer_of_interrupt == 1 || timer_configuration->timer_oc_interrupt == 1){
			sei();
		}
	}
	
}

void timer_start(ST_timer_config_t *timer_configuration){
	if(timer_configuration->timer_mode == TIMER_MODE_NORMAL){
		TCNT0 = timer_configuration->OCR;
		TCCR0 |= timer_configuration->timer_prescaller;
	}
}

void timer_stop(ST_timer_config_t *timer_configuration){
	if(timer_configuration->timer_mode == TIMER_MODE_NORMAL){
		TCCR0 &= ~0b00000111;
	}
}

void timer_initialize_callback_OVF(void (*callback)(void)){
	TIMER0_OVCallBackPointer = callback;
}

void timer_initialize_callback_COMP(void (*callback)(void)){
	TIMER0_CTCCallBackPointer = callback;
}


ISR (TIMER0_OVF_vect)        //Timer overflow interrupt
{
	(*TIMER0_OVCallBackPointer)();
	
}
ISR (TIMER0_COMP_vect)       //Timer compare match interrupt
{
	(*TIMER0_CTCCallBackPointer)();
}