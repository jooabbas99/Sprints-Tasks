/*
 * button.c
 *
 * Created: 4/6/2023 10:30:06 PM
 *  Author: Youssef Abbas
 */ 
#include "button.h"
/*
		BUTTON_init:
			the aim duty for this function is to define btn and its ports in DIO driver 
			-inputs : *ST_BUTTON_t 
			- return : EN_BTN_ERROR_t with error status
*/
EN_BTN_ERROR_t BTN_init(ST_BUTTON_t * btn){
	// initialize button with DIO driver 
	if(DIO_Init(&(btn->dio)) != DIO_SUCCESS){
		return BTN_ERROR_DIO;
	}
	return BTN_OK;
}

/*
		BUTTON_status:
			return BTN_ACTIVE when the button is pressed  
			-inputs : *ST_BUTTON_t , *uint8_t pointer value
			- return : EN_BTN_ERROR_t with *uint8_t pointer value
*/
EN_BTN_ERROR_t BTN_status(ST_BUTTON_t * btn,uint8 *status){
	
		if(DIO_ReadPin(&(btn->dio))!= DIO_SUCCESS){
			return BTN_ERROR_DIO;
		}
		if (btn->mode == BTN_PULL_DOWN)
		{
			*status = (btn->dio.port_value == DIO_HIGH) ? BTN_ACTIVE : BTN_DISABLE;
		} 
		else 
		{
			*status = (btn->dio.port_value == DIO_HIGH) ? BTN_DISABLE  : BTN_ACTIVE;
		}
		return BTN_OK;
}
