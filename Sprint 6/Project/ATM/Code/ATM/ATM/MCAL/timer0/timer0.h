/*
 * timer0.h
 *
 * Created: 5/2/2023 8:49:11 PM
 *  Author: Youssef Abbas
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "../../Utilities/types.h"


#define max_count 256
#define min_count 1
#define init_value(T_max,T_delay,tick)  (((float)T_max-T_delay)/tick)

//pre_scaler values for TIMER0
#define N0    0
#define N1    1
#define N8    8
#define N64   64
#define N256  256
#define N1024 1024

//T_max in (ms) delay for each pre_scaler
#define Tmax_N1    0.26F
#define Tmax_N8    2.05F
#define Tmax_N64   16.38F
#define Tmax_N256  65.54F
#define Tmax_N1024 262.14F

//T_min in (ms) delay for each pre_scaler
#define Tmin_N1    0.001F
#define Tmin_N8    0.008F
#define Tmin_N64   0.064F
#define Tmin_N256  0.256F
#define Tmin_N1024 1.024F



/*============= FUNCTION PROTOTYPE =============*/
void Timer0_Delay(float delay);
void Timer0_event(uint8_t delay,void(*g_ptr)(void));


#endif /* TIMER0_H_ */