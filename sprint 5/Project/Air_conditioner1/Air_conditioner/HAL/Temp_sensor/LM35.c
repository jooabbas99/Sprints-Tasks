/*
 * LM35.c
 *
 *  Created on: Apr 20, 2023
 *      Author: HAZEM-PC
 */

#include "LM35.h"

uint8 LM35_getTemperature(EN_ADC_channel sensor_channel_ID)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	ADC_analogRead(sensor_channel_ID, &adc_value);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}
