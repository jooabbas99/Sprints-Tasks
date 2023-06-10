/*
 * eint.c
 *
 * Created: 5/18/2023 9:47:27 PM
 *  Author: Youssef Abbas
 */ 
#include "eint.h"
#include "eint_reg.h"
#include "../../utilities/bit_math.h"
volatile void(*callBack)(void) ;
volatile void(*callBackFunc)(void) ;
volatile void(*callBackFunc2)(void) ;
void eint_init(){

		// enable INTERRRUPT
		// enable interrupt mode
		SET_BIT(MCUCSR,ISC2);
		//enable GICR
		//SET_BIT(GICR,GICR_INT_2);
		SET_BIT(GICR,5);
		SET_BIT(SREG,1);
		sei();
}
void set_call_back_int0(void(*g_ptr)(void)){
	callBack = g_ptr;
}

void set_call_back_int1(void(*g_ptr)(void)){
	callBackFunc = g_ptr;
}

void set_call_back_int2(void(*g_ptr)(void)){
	callBackFunc2 = g_ptr;
}
ISR(INT0_vect)
{
	callBack();
}

ISR(INT1_vect)
{
	callBackFunc();
}
ISR(INT2_vect)
{
	callBackFunc2();
}