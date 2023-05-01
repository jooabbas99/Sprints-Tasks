///*
 //* temp.c
 //*
 //* Created: 4/10/2023 8:38:45 PM
 //*  Author: youss
 //*/ 
///*
 //* application.c
 //*
 //* Created: 4/6/2023 10:13:31 PM
 //*  Author: youss
 //*/ 
//
//#include "application.h"
//uint8_t  counter = 0;
//ST_led_t led[LED_NO];
//uint8_t interrupt_flag;
//
//#define NUMBER_OF_OVERFLOW 20000
//unsigned int overflowCounter ;
//
//void AppInit(){
	//led[0].pinNumber = PIN0;
	//led[0].portNmber = PORT_A;
	//led[0].ledStatus = LOW;
	//
	//led[1].pinNumber = PIN1;
	//led[1].portNmber = PORT_A;
	//led[1].ledStatus = LOW;
	//
	//led[2].pinNumber = PIN2;
	//led[2].portNmber = PORT_A;
	//led[2].ledStatus = LOW;
	//
	//led[3].pinNumber = PIN3;
	//led[3].portNmber = PORT_A;
	//led[3].ledStatus = LOW;
	//
	//LED_init(&led[0]);
	//LED_init(&led[1]);
	//LED_init(&led[2]);
	//LED_init(&led[3]);
	//// interrupt 
	//BUTTON_init(EXT_INT_BTN_PORT,EXT_INT_BTN_PIN);
	//counter = 0;
	//interrupt_flag = 0;
	//// enable global interrupt 
	//sei();
	//// enable interrupt mode 
	//SET_BIT(MCUCR,ISC00);
	//SET_BIT(MCUCR,ISC01);
	////enable GICR
	//SET_BIT(GICR,GICR_INT_0);
	//
	//overflowCounter = 0;
	//// TIMER INIT 
	//TCCR0 = 0x00; // Normal mode
	//// set timer value 
	//TCNT0 = 0x00; // data register -> counter
	//
	//
	//
	//
	//
	//
	//
//}
//
//void AppStart(){
	//overflowCounter = 0;
	//
	//
	//// start timer - set prescaler
	//LED_on(&led[1]);
	//
	//SET_BIT(TCCR0,0); // no p
	//// stop after 256 tick
	//while(overflowCounter > NUMBER_OF_OVERFLOW){
		//// busy wait
		//while((TIFR & (1<<0)) == 0 );
		//// clear overflow flag
		//SET_BIT(TIFR,0);
		//
		//overflowCounter++;
	//}
	//
	//// stop timer 
	//TCCR0 = 0x00;
	//LED_off(&led[1]);
	//
	//
	////if(interrupt_flag){
		////if (counter < (LED_NO *2))
			////counter ++;
		////else
			////counter = 0;
		////interrupt_flag = 0;
		////
		////
		////if (counter <= LED_NO)
		////{
			////LED_on(&led[counter-1]);
		////}
		////else
		////{	
			////LED_off(&led[counter-(LED_NO+1)]);
		////}
	////}
//}
//
//ISR(EXT_INT_0){
	//interrupt_flag = 1;
//}