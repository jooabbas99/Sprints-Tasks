/*
 * ADC.c
 *
 *  Created on: Apr 20, 2023
 *      Author: HAZEM-PC
 */
/*******************************************************************************
 *                             FILE INCLUSION                                  *
 *******************************************************************************/
#include "ADC.h"

/*******************************************************************************
 *                             function definition                             *
 *******************************************************************************/

EN_ADC_state ADC_init(EN_ADC_Vrefernce Vref,EN_ADC_prescaler ADC_CLK)
{
	if( Vref < 0 || Vref > 3)
		return Vref_error;
	else if(ADC_CLK < 1 || ADC_CLK > 7)
		return clk_error;
	else
	{
		ADMUX =	 ((ADMUX & 0x3F) | (Vref << REFS0));	//shift left to set last two pins in the register
		ADCSRA = ((ADCSRA & 0xF1) | (ADC_CLK &0x07));	//set ADC clock pre_scaler
		SET_BIT(ADCSRA,ADEN);							//enable ADC
		return success;
	}
}

EN_ADC_state ADC_analogRead(uint8 ADC_pin,uint16* ADC_read)
{
	if(ADC_pin < 0 || ADC_pin > 8)
	{
		return channel_error;
	}
	else
	{
		ADMUX =	 ((ADMUX & 0xE0) | (ADC_pin & 0x1F)); /* Choose the correct channel by setting the channel number in MUX4:0 bits */
		SET_BIT(ADCSRA,ADSC); 						  /* Start conversion write '1' to ADSC */
		while(BIT_IS_CLEAR(ADCSRA,ADIF)); 			  /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA,ADIF); 					      /* Clear ADIF by write '1' to it :) */
		*ADC_read= ADC; 							  /* Read the digital value from the data register */
		return success;
	}
}
