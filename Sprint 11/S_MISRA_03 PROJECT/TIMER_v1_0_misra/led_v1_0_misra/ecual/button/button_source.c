/*
 * led_source.c
 *
 * Created: 6/6/2023 12:42:15 PM
 *  Author: Youssef Abbas
 */ 
#include "button_interface.h"

enm_button_error_t button_init(str_button_t str_button){
	enm_button_error_t enm_button_error;
	enm_dio_error_t enm_dio_error;
	enm_button_error = BUTTON_NOT_COMBLETE;
	enm_dio_error = dio_init(str_button.str_dio,DIO_IN);
	
	if (enm_dio_error != DIO_SUCCESS)
	{
		enm_button_error = BUTTON_INVALID_CONF;
	}else{
		enm_button_error = BUTTON_SUCCESS;
	}
	return enm_button_error;
}
enm_button_error_t button_read(str_button_t str_button,enm_button_status_t *enm_button_status){
		enm_button_error_t enm_button_error;
		enm_dio_error_t enm_dio_error;
		enm_dio_value_t btn_temp;
		enm_button_error = BUTTON_NOT_COMBLETE;
		enm_dio_error = dio_read_pin(str_button.str_dio,&btn_temp);
		
		if (enm_dio_error != DIO_SUCCESS)
		{
			enm_button_error = BUTTON_INVALID_CONF;
		}
		else
		{
			if (str_button.enm_button_active == btn_temp)
			{
				*enm_button_status = BUTTON_PRESSED;
			}
			else
			{
				*enm_button_status = BUTTON_RELEASED;
			}
			enm_button_error = BUTTON_SUCCESS;
		}
		return enm_button_error;
}