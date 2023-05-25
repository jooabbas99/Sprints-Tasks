/*
 * uart_source.c
 *
 * Created: 5/25/2023 12:22:07 PM
 *  Author: Youssef Abbas
 */ 


#include "../../i_lib/bit_math.h"
#include "uart_private.h"
#include "uart_interface.h"

#include <stddef.h>
#include <avr/interrupt.h>
#include "../../i_lib/std_types.h"
static volatile uint16 *rx_data = NULL ;
static volatile uint16 *tx_data = NULL ;
static volatile uint8 rx_flag_INT_used = 0;
static volatile uint8 tx_flag_INT_used = 0;




void uart_init(uart_config_t *uart_config) {
	UCSRC_REG = (1 << URSEL) | (uart_config->uart_stop_mode << USBS) | (uart_config->uart_mode << UMSEL)
	            | (uart_config->uart_parity_mode << UPM) | (uart_config->uart_clock_polarity << UCPOL)
	            | (uart_config->uart_data_size << UCSZ);
	UCSRA_REG = (0xFC & UCSRA_REG) | (uart_config->uart_speed_mode << U2X);
	UCSRB_REG = (uart_config->uart_rx_mode << RXEN) | (uart_config->uart_tx_mode << TXEN)
	            | ((uart_config->uart_data_size >> UCSZ2) << UCSZ2) | (0x03 & UCSRB_REG);
	UBRRL_REG = (uint8)uart_config->uart_baudrate;
	UBRRH_REG = (uint8)(uart_config->uart_baudrate >> 8);
	// Enable global interrupts
	if (uart_config->uart_interrupt_mode == UART_INTERRUPT_ENABLE) {
		sei();
	}
}

void uart_write(uint16 *data){
	while (tx_flag_INT_used == 1);
	while (!(UCSRA_REG & (1 << UDRE)));
	UDR_REG = (uint8)*data;
	if (READ_BIT(UCSRB_REG, UCSZ2) == 1) {
		UCSRB_REG = (UCSRB_REG & 0xFE) | ((uint8)(*data >> 8));
	}
}

void uart_read(uint16 *data) {
	while (rx_flag_INT_used == 1);
	while (!(UCSRA_REG & (1 << RXC)));
	*data = UDR_REG;
	if (READ_BIT(UCSRB_REG, UCSZ2) == 1) {
		*data = ((UCSRB_REG & 0x02) << 7) | *data;
	}
}

void uart_write_INT(uart_config_t *uart_config, uint16 *data) {
	while (tx_flag_INT_used == 1);
	tx_flag_INT_used = 1;
	tx_data = data;
	SET_BIT(UCSRB_REG, UDRIE);
}

void uart_read_INT(uart_config_t *uart_config, uint16 *data) {
	while (rx_flag_INT_used == 1);
	rx_flag_INT_used = 1;
	rx_data = data;
	SET_BIT(UCSRB_REG, RXCIE);
}

ISR(USART_RXC_vect) {
	rx_flag_INT_used = 0;
	CLEAR_BIT(UCSRB_REG, RXCIE);
	if (rx_data != NULL) {
		*rx_data = UDR_REG;
		if (READ_BIT(UCSRB_REG, UCSZ2) == 1) {
			*rx_data = ((UCSRB_REG & 0x02) << 7) | *rx_data;
		}
	}
}

ISR(USART_UDRE_vect) {
	tx_flag_INT_used = 0;
	CLEAR_BIT(UCSRB_REG, UDRIE);
	if (tx_data != NULL) {
		UDR_REG = *tx_data;
		if (READ_BIT(UCSRB_REG, UCSZ2) == 1) {
			UCSRB_REG = (UCSRB_REG & 0xFE) | ((uint8)(*tx_data >> 8));
		}
	}
}
