/*
 * uart_source.c
 *
 * Created: 5/25/2023 12:22:07 PM
 *  Author: Youssef Abbas
 */ 


#include "../../i_lib/bit_math.h"
#include "uart_private.h"
#include "uart_interface.h"
#include "../../i_lib/interrupt.h"


static void(*tx_callback)(void) = NULL;
static void(*rx_callback)(void) = NULL;

void uart_init(uart_config_t *uart_config) {
	UCSRC_REG = (1 << URSEL) 
				| (uart_config->uart_stop_mode << USBS) 
				| (uart_config->uart_mode << UMSEL)
	            | (uart_config->uart_parity_mode << UPM) 
				| (uart_config->uart_clock_polarity << UCPOL)
	            | (uart_config->uart_data_size << UCSZ);
				
	UCSRA_REG = (0xFC & UCSRA_REG) 
				| (uart_config->uart_speed_mode << U2X);
	UCSRB_REG = (uart_config->uart_rx_mode << RXEN) 
				| (uart_config->uart_tx_mode << TXEN)
	            | ((uart_config->uart_data_size >> UCSZ2) << UCSZ2) 
				| (0x03 & UCSRB_REG);
		
	UBRRL_REG = (uint8)uart_config->uart_baudrate;
	UBRRH_REG = (uint8)(uart_config->uart_baudrate >> 8);
	// Enable global interrupts
	
	if (uart_config->uart_rxc_interrupt_mode == UART_RXC_INTERRUPT_ENABLE || uart_config->uart_txc_interrupt_mode == UART_TXC_INTERRUPT_ENABLE || uart_config->uart_udre_interrupt_mode == UART_UDRE_INTERRUPT_ENABLE) {
		sei();
	}
}
void uart_udrei_enable(void){
	// enable bit UDRIE in UCSRB
	SET_BIT(UCSRB_REG,UDRIE);
}
void uart_udrei_disable(void){
	CLEAR_BIT(UCSRB_REG,UDRIE);
}
void uart_rxci_enable(void){
	SET_BIT(UCSRB_REG,RXCIE);
}
void uart_rxci_disable(void){
	CLEAR_BIT(UCSRB_REG,RXCIE);
}
void uart_txci_enable(void){
	SET_BIT(UCSRB_REG,TXCIE);
}
void uart_txci_disable(void){
	CLEAR_BIT(UCSRB_REG,TXCIE);
}
void uart_write(uint16 *data){
	while (!READ_BIT(UCSRA_REG,UDRE));
	UDR_REG = (uint8)*data;
	// if data is 9 bit 
	if (READ_BIT(UCSRB_REG, UCSZ2) == 1) {
		UCSRB_REG = (UCSRB_REG & 0xFE) 
					| ((uint8)(*data >> TXB8));
	}
}

void uart_read(uint16 *data) {
	while (!READ_BIT(UCSRA_REG,RXC));
	*data = UDR_REG;
	// if it 9 bit 
	if (READ_BIT(UCSRB_REG, UCSZ2) == 1) {
		*data = ((UCSRB_REG & 0x02) << RXB8) | *data;
	}
}

void uart_write_INT(void(*callback)(void)) {
	tx_callback = callback;
	uart_udrei_enable();
}

void uart_read_INT(void(*callback)(void)) {
	rx_callback = callback;
	uart_rxci_enable();
}

ISR(USART_RXC) {
	rx_callback();
}
ISR(USART_UDRE) {
	(*tx_callback)();
}
