/*
 * led_source.c
 *
 * Created: 6/6/2023 12:42:15 PM
 *  Author: Youssef Abbas
 */ 
#include "led_interface.h"
enm_led_error_t led_init(str_led_t* led){
	// Rule 18.1, requires that all declarations should be at the top of the function or file scope.
	enm_led_error_t enm_led_error;
	enm_dio_error_t enm_dio_error;
	enm_led_error = LED_NOT_COMBLETE;
	// check if it initialized before 
	if (led->enm_led_status < LED_NOT_INIT)
	{
		enm_led_error = LED_ALLREADY_INIT;
	}
	else 
	{
		led->enm_led_status = LED_NOT_INIT;	
		enm_dio_error = dio_init(led->str_dio,DIO_OUT);
		// Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
		if (enm_dio_error != DIO_SUCCESS)
		{
			enm_led_error = LED_INVALID_CONF;
		}
		else
		{
			enm_dio_error = dio_write_pin(led->str_dio,DIO_LOW);
		
			if (enm_dio_error != DIO_SUCCESS)
			{
				enm_led_error = LED_FAILED;
			}else{
				led->enm_led_status = LED_OFF;
				enm_led_error = LED_SUCCESS;
			}
		}
	}
	return enm_led_error;
}
enm_led_error_t led_on(str_led_t*led){
	// Rule 18.1, requires that all declarations should be at the top of the function or file scope.
	enm_led_error_t enm_led_error;
	enm_dio_error_t enm_dio_error;
	enm_led_error = LED_NOT_COMBLETE;
	// Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
	if (led->enm_led_status >= LED_NOT_INIT)
	{
		led->enm_led_status = LED_NOT_INIT;
		enm_led_error = LED_INVALID_CONF;
	}
	else
	{
		enm_dio_error = dio_write_pin(led->str_dio,DIO_HIGH);
		
		if (enm_dio_error != DIO_SUCCESS)
		{
			enm_led_error = LED_FAILED;
		}
		else
		{
			led->enm_led_status = LED_ON;
			enm_led_error = LED_SUCCESS;
		}
	}
	return enm_led_error;
}
enm_led_error_t led_off(str_led_t*led){
	// Rule 18.1, requires that all declarations should be at the top of the function or file scope.
	enm_led_error_t enm_led_error;
	enm_dio_error_t enm_dio_error;
	enm_led_error = LED_NOT_COMBLETE;
	// Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
	if (led->enm_led_status >= LED_NOT_INIT)
	{
		led->enm_led_status = LED_NOT_INIT;
		enm_led_error = LED_INVALID_CONF;
	}
	else
	{
		enm_dio_error = dio_write_pin(led->str_dio,DIO_LOW);
		
		if (enm_dio_error != DIO_SUCCESS)
		{
			enm_led_error = LED_FAILED;
		}
		else
		{
			led->enm_led_status = LED_OFF;
			enm_led_error = LED_SUCCESS;
		}
	}
	return enm_led_error;
}
enm_led_error_t led_toggle(str_led_t*led){
		// Rule 18.1, requires that all declarations should be at the top of the function or file scope.
		enm_led_error_t enm_led_error;
		enm_dio_error_t enm_dio_error;
		enm_led_error = LED_NOT_COMBLETE;
		// Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.
		if (led->enm_led_status >= LED_NOT_INIT)
		{
			led->enm_led_status = LED_NOT_INIT;
			enm_led_error = LED_INVALID_CONF;
		}
		else
		{
			enm_dio_error = dio_toggle_pin(led->str_dio);
			
			if (enm_dio_error != DIO_SUCCESS)
			{
				enm_led_error = LED_FAILED;
			}
			else
			{
				led->enm_led_status = ! led->enm_led_status;
				enm_led_error = LED_SUCCESS;
			}
		}
		return enm_led_error;
}