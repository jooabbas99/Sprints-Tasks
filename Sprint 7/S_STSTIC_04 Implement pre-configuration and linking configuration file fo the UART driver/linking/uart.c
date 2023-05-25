/*
 * uart.c
 *
 * Created: 5/1/2023 6:22:40 PM
 *  Author: Youssef Abbas
 */ 
#include "uart.h"
#include "uart_register.h"
#include "../utilities/BIT_MATH.h"

void UART_init(ST_UART_config_t *conf) {
	// Set UART mode (Async/Sync)
	if (conf->uart_mode == ASYNC_MODE) {
		// Set asynchronous mode
		UCSRC &= ~(1 << UMSEL);
		} else {
		// Set synchronous mode
		UCSRC |= (1 << UMSEL);
	}

	// Set character size
	UCSRC = (UCSRC & 0xF9) | (conf->uart_cs_mode << UCSZ);

	// Set parity mode
	UCSRC = (UCSRC & 0xCF) | (conf->uart_parity_mode << UPM);

	// Set stop bits
	UCSRC = (UCSRC & 0xF7) | (conf->uart_stop_mode << USBS);

	// Set clock polarity
	UCSRC = (UCSRC & 0xFE) | (conf->uart_clock_polarity << UCPOL);

	// Set speed mode
	if (conf->uart_speed_mode == SYNC_SPEED_MODE) {
		// Set synchronous speed mode
		UCSRA &= ~(1 << U2X);
		} else {
		// Set asynchronous speed mode
		UCSRA |= (1 << U2X);
	}

	// Enable/disable receive and transmit
	UCSRB = (UCSRB & 0xFB) | (conf->uart_rx_mode << RXEN);
	UCSRB = (UCSRB & 0xF7) | (conf->uart_tx_mode << TXEN);

	// Enable/disable receive interrupt
	UCSRB = (UCSRB & 0x7F) | (conf->uart_rcie_mode << RXCIE);

	// Enable/disable transmit interrupt
	UCSRB = (UCSRB & 0xBF) | (conf->uart_tcie_mode << TXCIE);

	// Enable/disable data register empty interrupt
	UCSRB = (UCSRB & 0xDF) | (conf->uart_urie_mode << UDRIE);

	// Set USART baud rate
	uint16_t ubrr = F_CPU / (8 * conf->usart_buadrate) - 1;
	UBRRH = (uint8_t)(ubrr >> 8);
	UBRRL = (uint8_t)(ubrr);
}

void UART_sendData(uint16_t data) {
	// Wait for the transmit buffer to be empty
	while (!(UCSRA & (1 << UDRE)));

	// Send the data
	UDR = (uint8_t)data;
}

void UART_getData(uint16_t *data) {
	// Wait for the receive buffer to be full
	while (!(UCSRA & (1 << RXC)));

	// Read the received data
	*data = (uint16_t)UDR;
}
