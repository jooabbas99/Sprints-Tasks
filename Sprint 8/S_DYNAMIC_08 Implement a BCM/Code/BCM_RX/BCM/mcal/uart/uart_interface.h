/*
 * uart_interface.h
 *
 * Created: 5/25/2023 12:21:37 PM
 *  Author: Youssef Abbas
 */ 

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "../../i_lib/std_types.h"

// Enums

typedef enum {
	UART_RECEIVE_DISABLE = 0,  // Disable receive
	UART_RECEIVE_ENABLE        // Enable receive
} uart_receive_mode_t;

typedef enum {
	UART_TRANSMIT_DISABLE = 0,  // Disable transmit
	UART_TRANSMIT_ENABLE        // Enable transmit
} uart_transmit_mode_t;

typedef enum {
	UART_UDRE_INTERRUPT_DISABLE = 0, // Disable interrupt
	UART_UDRE_INTERRUPT_ENABLE       // Enable interrupt
} uart_udre_interrupt_mode_t;
typedef enum {
	UART_RXC_INTERRUPT_DISABLE = 0,    // Disable RX
	UART_RXC_INTERRUPT_ENABLE          // Enable RX
} uart_rxc_interrupt_mode_t;

typedef enum {
	UART_TXC_INTERRUPT_DISABLE = 0,    // Disable TX
	UART_TXC_INTERRUPT_ENABLE          // Enable TX
} uart_txc_interrupt_mode_t;
typedef enum {
	UART_RX_DISABLE = 0,    // Disable RX
	UART_RX_ENABLE          // Enable RX
} uart_rx_mode_t;

typedef enum {
	UART_TX_DISABLE = 0,    // Disable TX
	UART_TX_ENABLE          // Enable TX
} uart_tx_mode_t;

typedef enum {
	UART_SYNC_SPEED_MODE = 0,   // Sync mode
	UART_NORMAL_MODE=0,           // Normal mode
	UART_DOUBLE_MODE            // Double speed
} uart_speed_mode_t;

typedef enum {
	UART_NO_CLOCK = 0,          // No clock in async mode
	UART_TXR_RXF,
	UART_TXF_RXR
} uart_clock_polarity_t;

typedef enum {
	UART_STOP_1_BIT = 0,           // One bit
	UART_STOP_2_BIT               // Two bits
} uart_stop_mode_t;

typedef enum {
	UART_PARITY_DISABLED = 0,   // No parity mode
	UART_PARITY_EVEN,           // Even parity mode
	UART_PARITY_ODD             // Odd parity mode
} uart_parity_mode_t;

typedef enum {
	UART_ASYNC_MODE = 0,        // Async mode
	UART_SYNC_MODE              // Sync mode
} uart_operating_mode_t;

typedef enum {
	UART_CS_5 = 0,              // 5 bits length
	UART_CS_6,                  // 6 bits length
	UART_CS_7,                  // 7 bits length
	UART_CS_8,                  // 8 bits length
	UART_CS_9= 7                // 9 bits length
} uart_data_size_t;

// Structures

typedef struct {
	uart_operating_mode_t uart_mode;
	uart_data_size_t uart_data_size;
	uart_parity_mode_t uart_parity_mode;
	uart_stop_mode_t uart_stop_mode;
	uart_clock_polarity_t uart_clock_polarity;
	uart_speed_mode_t uart_speed_mode;
	uart_receive_mode_t uart_receive_mode;
	uart_transmit_mode_t uart_transmit_mode; 
	uart_udre_interrupt_mode_t uart_udre_interrupt_mode;
	uart_rx_mode_t uart_rx_mode;
	uart_tx_mode_t uart_tx_mode;
	uart_rxc_interrupt_mode_t uart_rxc_interrupt_mode;
	uart_txc_interrupt_mode_t uart_txc_interrupt_mode;
	uint16 uart_baudrate;
} uart_config_t;

// Function Prototypes


void uart_init(uart_config_t *uart_config);
void uart_write(uint16 *data);
void uart_read(uint16 *data);
void uart_write_INT(void(*callback)(void));
void uart_read_INT(void(*callback)(void));
void uart_udrei_enable(void);
void uart_udrei_disable(void);
void uart_rxci_enable(void);
void uart_rxci_disable(void);
void uart_txci_enable(void);
void uart_txci_disable(void);
#endif /* UART_INTERFACE_H_ */
