/*
 * bcm_conf.c
 *
 * Created: 5/25/2023 8:13:33 PM
 *  Author: Youssef Abbas
 */ 

/************************************************************************/
/*	define protocols                                                    */
/************************************************************************/
#include "bcm_interface.h"
#include "../../mcal/uart/uart_interface.h"
extern const uart_config_t gstr_uart_conf;
str_bcm_instance_t bcm_instance_ch_0 = {
    .bcm_instance_id = 0,  // Set the desired instance ID
    .protocol = BCM_PROTOCOL_UART,  // Set the desired protocol
	.protocolInstance = (void*)(&gstr_uart_conf)  // Set the protocol instance (e.g., UART configuration)
};

