/*
 * TIMER_0.h
 *
 *  Created on: Apr 9, 2023
 *      Author: HAZEM-PC
 */

#ifndef MCAL_TIMER_0_TIMER_0_H_
#define MCAL_TIMER_0_TIMER_0_H_

/*============= FILE INCLUSION =============*/
#include "../../Utilities/Std_Types.h"
#include "../../Utilities/Registers.h"

/*============= FUNCTION PROTOTYPE =============*/
void Timer0_Delay(float delay);
void Timer0_event(uint16 delay,void(*g_ptr)(void));

#endif /* MCAL_TIMER_0_TIMER_0_H_ */
