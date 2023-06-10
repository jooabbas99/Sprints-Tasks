/*
 * app.c
 *
 * Created: 5/25/2023 11:22:06 AM
 *  Author: Youssef Abbas
 */ 
#include "app.h"
#include "../manager/bcm/bcm_interface.h"
#include "../i_lib/std_types.h"
#include "../ecual/led/led.h"

extern str_bcm_instance_t bcm_instance_ch_0;
static uint8 tx_data[BUFFER_SIZE] = "Confirm BCM Operating"; 
static uint8 rx_data[BUFFER_SIZE] = {0};
static uint16 rx_length;
static enm_bcm_mode_t bcm_mode;
static str_led_t str_led_txc, str_led_rxc;
void app_init(void){
	bcm_init(&bcm_instance_ch_0);
	rx_length = 0;
	bcm_mode = BCM_RX_MODE;
	str_led_txc.enm_led_status=LED_OFF;
	str_led_txc.str_dio.pin= PIND3;
	str_led_txc.str_dio.port = PORT_D;
	str_led_rxc.enm_led_status=LED_OFF;
	str_led_rxc.str_dio.pin= PIND4;
	str_led_rxc.str_dio.port = PORT_D;
	LED_init(&str_led_txc);
	LED_init(&str_led_rxc);
}
void app_start(void){
	// tx
	uint8 bcm_operating_flag;
	uint16 lenth = 22;
	bcm_dispatcher(&bcm_instance_ch_0,&bcm_operating_flag);
	if(bcm_operating_flag == BCM_IDEL_FLAG){
		LED_off(&str_led_txc);
		LED_off(&str_led_rxc);
		if (bcm_mode == BCM_TX_MODE)
		{
			// 
			LED_on(&str_led_txc);
			bcm_send_n(&bcm_instance_ch_0,tx_data,lenth);
			bcm_mode = BCM_RX_MODE;
		}else if (bcm_mode == BCM_RX_MODE){
			LED_on(&str_led_rxc);
			bcm_recive_n(&bcm_instance_ch_0,rx_data,&rx_length);
			bcm_mode = BCM_TX_MODE;
		}
	}

}