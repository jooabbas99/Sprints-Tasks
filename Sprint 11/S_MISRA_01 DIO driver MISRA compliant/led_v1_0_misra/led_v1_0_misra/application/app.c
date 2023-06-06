/*
 * app.c
 *
 * Created: 6/6/2023 1:39:21 PM
 *  Author: Youssef Abbas
 */ 
#include "app.h"
#include "../ecual/led/led_interface.h"
#include "../ecual/button/button_interface.h"
#define F_CPU	8000000
#include <util/delay.h>
#include <stdlib.h>

extern str_led_t leds[LED_SIZES];                // External array of LED structures
extern str_button_t button;              // External button structure
uint8 counter;                           // Counter variable
enm_button_status_t btnState;            // Button state variable

enm_led_error_t enm_led_error;           // LED error variable
enm_button_error_t enm_button_error;     // Button error variable

const uint8 leds_size = GET_ARR_SIZE(leds);  // Size of the LED array

void app_init() {
	btnState = BUTTON_RELEASED;                // Initialize button state as released
	counter = COUNTER_INIT;                     // Initialize counter variable
	enm_led_error = led_init(&leds[LED_1]);         // Initialize the first LED
	enm_led_error = led_init(&leds[LED_2]);         // Initialize the second LED
	enm_led_error = led_init(&leds[LED_3]);         // Initialize the third LED
	enm_led_error = led_init(&leds[LED_4]);         // Initialize the fourth LED

	if (enm_led_error != LED_SUCCESS) {
		exit(enm_led_error);                     // Exit if LED initialization fails
	}

	enm_button_error = button_init(button);      // Initialize the button

	if (enm_button_error != BUTTON_SUCCESS) {
		exit(enm_button_error);                   // Exit if button initialization fails
	}
}

void app_start() {
	enm_button_error = button_read(button, &btnState);   // Read the button state

	if (enm_button_error == BUTTON_SUCCESS) {
		if (btnState == BUTTON_PRESSED) {
			counter++;                                 // Increment the counter

			if (counter <= leds_size) {
				enm_led_error = led_on(&leds[counter-1]);    // Turn on the corresponding LED
				} else {
				if (counter > (leds_size * 2)) {
					counter = COUNTER_INIT;                     // Reset the counter
					} else {
					enm_led_error = led_off(&leds[counter-5]);  // Turn off a specific LED
				}
			}

			if (enm_led_error != LED_SUCCESS) {
				counter--;                                      // Decrement the counter if LED control fails
			}
		}

		_delay_ms(200);                                           // Delay for 100 milliseconds
	}
	_delay_ms(50);                                           // Delay for 100 milliseconds

}
