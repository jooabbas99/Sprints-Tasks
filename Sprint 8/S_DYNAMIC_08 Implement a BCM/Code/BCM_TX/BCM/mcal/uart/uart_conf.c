/*
 * uart_conf.c
 *
 * Created: 5/25/2023 12:22:19 PM
 *  Author: Youssef Abbas
 */ 
#include "uart_interface.h"
const uart_config_t gstr_uart_conf = {
	.uart_mode = UART_ASYNC_MODE,
	.uart_parity_mode = UART_PARITY_DISABLED,
	.uart_data_size =  UART_CS_8,
	.uart_baudrate = 51,
	.uart_tx_mode =  UART_TX_ENABLE,
	.uart_rx_mode =  UART_RX_ENABLE,
	.uart_clock_polarity = UART_NO_CLOCK,
	.uart_stop_mode = UART_STOP_1_BIT,
	.uart_udre_interrupt_mode = UART_UDRE_INTERRUPT_ENABLE,
	.uart_txc_interrupt_mode = UART_TXC_INTERRUPT_DISABLE,
	.uart_rxc_interrupt_mode = UART_RXC_INTERRUPT_ENABLE,
	.uart_transmit_mode = UART_TRANSMIT_ENABLE,
	.uart_receive_mode = UART_RECEIVE_ENABLE,
	.uart_speed_mode = UART_NORMAL_MODE
};
