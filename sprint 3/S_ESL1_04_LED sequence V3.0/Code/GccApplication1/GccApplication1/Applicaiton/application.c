/*
 * temp.c
 *
 * Created: 4/10/2023 8:38:45 PM
 *  Author: youss
 */ 
/*
 * application.c
 *
 * Created: 4/6/2023 10:13:31 PM
 *  Author: youss
 */ 

#include "application.h"
uint8_t  counter = 0;
ST_led_t led[LED_NO];
uint8_t interrupt_flag;
uint8_t blink_mode;
uint32_t delay_on;
uint32_t delay_off;

void AppInit(){
	led[0].pinNumber = PIN0;
	led[0].portNmber = PORT_A;
	led[0].ledStatus = LOW;
	
	led[1].pinNumber = PIN1;
	led[1].portNmber = PORT_A;
	led[1].ledStatus = LOW;
	
	led[2].pinNumber = PIN2;
	led[2].portNmber = PORT_A;
	led[2].ledStatus = LOW;
	
	led[3].pinNumber = PIN3;
	led[3].portNmber = PORT_A;
	led[3].ledStatus = LOW;
	
	LED_init(&led[0]);
	LED_init(&led[1]);
	LED_init(&led[2]);
	LED_init(&led[3]);
	// interrupt 
	BUTTON_init(EXT_INT_BTN_PORT,EXT_INT_BTN_PIN);
	BUTTON_init(EXT_TIM_BTN_PORT,EXT_TIM_BTN_PIN);
	counter = 0;
	interrupt_flag = 0;
	// enable global interrupt 
	sei();
	// enable interrupt mode 
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	//enable GICR
	SET_BIT(GICR,GICR_INT_0);
	//default delay
	blink_mode = 0;
	delay_on = 100;
	delay_off = 900;
	timer0_init();
	
	
	
	
}

void AppStart(){
	
	if(interrupt_flag){
		if (counter < (LED_NO *2))
			counter ++;
		else
			counter = 0;
		interrupt_flag = 0;
		
		
	}else {
		if (counter <= LED_NO)
		{
			
			LED_on(&led[counter-1]);
			timer0_start();
			timer0_set_delay(delay_on);
			timer0_loop();
			timer0_stop();
			LED_off(&led[counter-1]);
			timer0_start();
			timer0_set_delay(delay_off);
			timer0_loop();
			timer0_stop();
		}
		else
		{	
			LED_off(&led[counter-(LED_NO+1)]);
		}
	}
}

ISR(EXT_INT_0){
	interrupt_flag = 1;
}

ISR(EXT_INT_1){
	// timer interrupts
	blink_mode ++;
	switch(blink_mode){
		case 0 :
			delay_on = 100;
			delay_off = 900;
			break;
		case 1:
			delay_on = 200;
			delay_off = 800;
			break;
			
		case 2:
			delay_on = 300;
			delay_off = 700;
			break;
			
		case 3:
		
			delay_on = 500;
			delay_off = 500;
			break;
			
		case 4:
			delay_on = 800;
			delay_off = 200;
			break;
		default:
			blink_mode = 0;
			delay_on = 100;
			delay_off = 900;
			break;
	}
}