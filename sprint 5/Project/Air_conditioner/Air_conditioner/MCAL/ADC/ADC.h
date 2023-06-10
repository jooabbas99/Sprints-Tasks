/*
 * ADC.h
 *
 *  Created on: Apr 20, 2023
 *      Author: HAZEM-PC
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

/*******************************************************************************
 *                             FILE INCLUSION                                  *
 *******************************************************************************/
#include "../../Utilities/Std_Types.h"
#include "../../Utilities/Common_Macros.h"
#include "../../Utilities/Registers.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*******************************************************************************
 *                                type definitions                             *
 *******************************************************************************/
typedef enum{
	AREF,AVCC,INTERNAL=3
}EN_ADC_Vrefernce;

typedef enum{
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}EN_ADC_channel;

typedef enum{
	F_2=1,F_4,F_8,F_16,F_32,F_64,F_128
}EN_ADC_prescaler;

typedef enum{
	Vref_error,channel_error,clk_error,success
}EN_ADC_state;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
EN_ADC_state ADC_init(EN_ADC_Vrefernce Vref,EN_ADC_prescaler ADC_CLK);
EN_ADC_state ADC_analogRead(uint8 channel_ID,uint16* ADC_read);
#endif /* MCAL_ADC_ADC_H_ */
