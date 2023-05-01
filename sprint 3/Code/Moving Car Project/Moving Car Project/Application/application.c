/*
 * application.c
 *
 * Created: 4/13/2023 11:28:19 PM
 *  Author: youss
 */ 
#include "application.h"

ST_DCM_t motor_1,motor_2,motor_3,motor_4;
st_LED_config LED1,LED2,LED3,LED4;
ST_BUTTON_t button_on ;
uint8 car_state=0;
ST_INT_Config button_off;
uint8 button_value;
void app_init(void){
	// init led
	LED1.port = DIO_PORT_B;
	LED1.pin = DIO_PIN0;
	LED1.led_status = LED_OFF;
	
	LED2.port = DIO_PORT_B;
	LED2.pin = DIO_PIN1;
	LED2.led_status = LED_OFF;
	
	LED3.port = DIO_PORT_B;
	LED3.pin = DIO_PIN2;
	LED3.led_status = LED_OFF;
	
	LED4.port = DIO_PORT_B;
	LED4.pin = DIO_PIN3;
	LED4.led_status = LED_OFF;
	
	LED_Init(&LED1);
	LED_Init(&LED2);
	LED_Init(&LED3);
	LED_Init(&LED4);
	
	button_on.dio.direction = DIO_INPUT;
	button_on.dio.port = DIO_PORT_A;
	button_on.dio.pin = DIO_PIN0;
	button_on.mode = BTN_PULL_DOWN;
	
	BTN_init(&button_on);
		
	button_off.source = EN_INT0;
	button_off.trigger = RISING;
	
	
	motor_1.pin_1.direction = DIO_OUTPUT;
	motor_1.pin_1.port = DIO_PORT_C;
	motor_1.pin_1.pin = DIO_PIN0;
	motor_1.pin_2.direction = DIO_OUTPUT;
	motor_1.pin_2.port = DIO_PORT_C;
	motor_1.pin_2.pin = DIO_PIN1;
	
	motor_2.pin_1.direction = DIO_OUTPUT;
	motor_2.pin_1.port = DIO_PORT_C;
	motor_2.pin_1.pin = DIO_PIN3;
	motor_2.pin_2.direction = DIO_OUTPUT;
	motor_2.pin_2.port = DIO_PORT_C;
	motor_2.pin_2.pin = DIO_PIN2;
	
	motor_3.pin_1.direction = DIO_OUTPUT;
	motor_3.pin_1.port = DIO_PORT_C;
	motor_3.pin_1.pin = DIO_PIN5;
	motor_3.pin_2.direction = DIO_OUTPUT;
	motor_3.pin_2.port = DIO_PORT_C;
	motor_3.pin_2.pin = DIO_PIN4;
	
	motor_4.pin_1.direction = DIO_OUTPUT;
	motor_4.pin_1.port = DIO_PORT_C;
	motor_4.pin_1.pin = DIO_PIN7;
	motor_4.pin_2.direction = DIO_OUTPUT;
	motor_4.pin_2.port = DIO_PORT_C;
	motor_4.pin_2.pin = DIO_PIN6;
	
	DCM_init(&motor_1);
	DCM_init(&motor_2);
	DCM_init(&motor_3);
	DCM_init(&motor_4);
	INT_init(&button_off);
	
	INT0_setCallBack(stop_car);



}
void app_start(void){
	BTN_status(&button_on,&button_value);
	
	if(button_value==BTN_ACTIVE && car_state == 0)
	{
		car_state=1;
		Timer0_Delay(1000);
	}
	
	switch(car_state)
	{
		case 1:
		car_state=2;
			motor_1.direction = DCM_CL_DIR;
			motor_2.direction = DCM_CL_DIR;
			motor_3.direction = DCM_CL_DIR;
			motor_4.direction = DCM_CL_DIR;
			
			DCM_start(&motor_1,50);
			DCM_start(&motor_2,50);
			DCM_start(&motor_3,50);
			DCM_start(&motor_4,50);
			LED_On(&LED1);
			LED_Off(&LED2);
			LED_Off(&LED3);
			LED_Off(&LED4);
			Timer0_Delay(3000);
			break;
		case 2:
			car_state=3;
			DCM_start(&motor_1,0);
			DCM_start(&motor_2,0);
			DCM_start(&motor_3,0);
			DCM_start(&motor_4,0);
			
			LED_Off(&LED1);
			LED_On(&LED2);
			LED_Off(&LED3);
			LED_Off(&LED4);
			Timer0_Delay(500);
			break;
		case 3:
			car_state=4;
			DCM_start(&motor_1,50);
			DCM_start(&motor_2,50);
			DCM_start(&motor_3,50);
			DCM_start(&motor_4,50);
			
			LED_Off(&LED1);
			LED_Off(&LED2);
			LED_On(&LED3);
			LED_Off(&LED4);
			Timer0_Delay(500);
			break;
		case 4:
			car_state=5;
			DCM_start(&motor_1,0);
			DCM_start(&motor_2,0);
			DCM_start(&motor_3,0);
			DCM_start(&motor_4,0);
			
			LED_Off(&LED1);
			LED_On(&LED2);
			LED_Off(&LED3);
			LED_Off(&LED4);
			Timer0_Delay(500);
			break;
		case 5:
			car_state=6;
			motor_1.direction = DCM_CL_DIR;
			motor_2.direction = DCM_CL_DIR;
			motor_3.direction = DCM_CL_DIR;
			motor_4.direction = DCM_CL_DIR;
			DCM_start(&motor_1,30);
			DCM_start(&motor_2,30);
			DCM_start(&motor_3,30);
			DCM_start(&motor_4,30);
			LED_On(&LED1);
			LED_Off(&LED2);
			LED_Off(&LED3);
			LED_Off(&LED4);
			Timer0_Delay(2000);
			break;
		case 6:
			car_state=7;
			DCM_start(&motor_1,0);
			DCM_start(&motor_2,0);
			DCM_start(&motor_3,0);
			DCM_start(&motor_4,0);
			LED_Off(&LED1);
			LED_On(&LED2);
			LED_Off(&LED3);
			LED_Off(&LED4);
			Timer0_Delay(500);
			break;
		case 7:
			car_state=8;
			motor_1.direction = DCM_CL_DIR;
			motor_2.direction = DCM_CL_DIR;
			motor_3.direction = DCM_ACL_DIR;
			motor_4.direction = DCM_ACL_DIR;
			DCM_start(&motor_1,30);
			DCM_start(&motor_2,30);
			DCM_start(&motor_3,30);
			DCM_start(&motor_4,30);
			LED_Off(&LED1);
			LED_Off(&LED2);
			LED_On(&LED3);
			LED_Off(&LED4);
			Timer0_Delay(500);
			break;
		case 8:
		car_state=1;
		DCM_start(&motor_1,0);
		DCM_start(&motor_2,0);
		DCM_start(&motor_3,0);
		DCM_start(&motor_4,0);
		LED_Off(&LED1);
		LED_On(&LED2);
		LED_Off(&LED3);
		LED_Off(&LED4);
		Timer0_Delay(500);
		break;
		default:
		car_state=0;
		DCM_start(&motor_1,0);
		DCM_start(&motor_2,0);
		DCM_start(&motor_3,0);
		DCM_start(&motor_4,0);
		LED_Off(&LED1);
		LED_Off(&LED2);
		LED_Off(&LED3);
		LED_Off(&LED4);
		break;
	}
	
	
}




void stop_car (void)
{
	car_state=9;
	DCM_stop(&motor_1);
	LED_Off(&LED1);
	LED_Off(&LED2);
	LED_Off(&LED3);
	LED_On(&LED4);
}

