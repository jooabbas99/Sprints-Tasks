/*
 * BCM.c
 *
 * Created: 5/25/2023 10:54:03 AM
 * Author : Youssef Abbas
 */ 


// typedef struct{
// 	enm_uart_operating_mode_t uart_mode;
// 	enm_uart_data_size_t uart_cs_mode;
// 	enm_uart_parity_mode_t uart_parity_mode;
// 	enm_uart_stop_mode_t uart_stop_mode;
// 	enm_uart_clock_polarity_t uart_clock_polarity;
// 	enm_uart_speed_mode_t uart_speed_mode;
// 	enm_uart_r_mode_t uart_rcie_mode;
// 	enm_uart_t_mode_t uart_tcie_mode; 
// 	enm_uart_int_mode_t uart_urie_mode;
// 	enm_uart_rx_mode_t	uart_rx_mode;
// 	enm_uart_tx_mode_t	uart_tx_mode;
// 	uint32_t usart_buadrate;	
// }str_uart_config_

#include "mcal/uart/uart_interface.h"
#define F_CPU 8000000
#include <util/delay.h>
int main(void)
{
    /* Replace with your application code */
	uart_config_t uart;
	uart.uart_mode = UART_ASYNC_MODE;
	uart.uart_parity_mode = UART_PARITY_DISABLED;
	uart.uart_data_size =  UART_CS_8;
	// 8000000
	uart.uart_baudrate = 51;
	uart.uart_tx_mode =  UART_TX_ENABLE;
	uart.uart_rx_mode =  UART_RX_ENABLE;
	uart.uart_stop_mode = UART_STOP_1_BIT;
	uart.uart_interrupt_mode = UART_INTERRUPT_ENABLE;
	uart.uart_transmit_mode = UART_TRANSMIT_ENABLE;
	uart_init(&uart);
	uint16 data = "0";
    while (1) 
    {
		uart_write_INT(&uart,&data);
		_delay_ms(200);
    }
}

