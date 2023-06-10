/*
 * LM35.h
 *
 *  Created on: Apr 20, 2023
 *      Author: HAZEM-PC
 */

#ifndef HAL_TEMP_SENSOR_LM35_H_
#define HAL_TEMP_SENSOR_LM35_H_
/*******************************************************************************
 *                             FILE INCLUSION                                  *
 *******************************************************************************/
#include "../../MCAL/ADC/ADC.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */

uint8 LM35_getTemperature(EN_ADC_channel sensor_channel_ID);

#endif /* HAL_TEMP_SENSOR_LM35_H_ */
