/*
 * app.c
 *
 * Created: 6/6/2023 1:39:21 PM
 *  Author: Youssef Abbas
 */ 
#include "app.h"
#include "../ecual/led/led_interface.h"
#include "../ecual/button/button_interface.h"
extern str_led_t leds[4];
extern str_button_t button;
uint8  counter;
enm_button_status_t btnState;
const leds_size = GET_ARR_SIZE(leds);
void app_init(){
	btnState = BUTTON_RELEASED;
	counter = COUNTER_INIT;
	led_init(&leds[0]);
	led_init(&leds[1]);
	led_init(&leds[2]);
	led_init(&leds[3]);
	button_init(button);
}
void app_start(){
	button_read(button,&btnState);
		if (btnState == BUTTON_PRESSED)
		{
			counter ++;
			if (counter <= leds_size)
			{
				led_on(&leds[counter-1]);
			}
			else
			{
				if (counter > leds_size*2)
				{
					counter = 0;
				}
				else 
				{
					led_off(&leds[counter-5]);
					
				}
				
			}
			button_read(button,&btnState);
			while(btnState == BUTTON_PRESSED){
				button_read(button,&btnState);
			}
			
		}
}
