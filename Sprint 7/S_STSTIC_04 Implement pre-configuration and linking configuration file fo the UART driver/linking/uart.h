/*
 * uart.h
 *
 * Created: 5/1/2023 6:22:57 PM
 * Author: Youssef Abbas
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>

// DEFTYPES
#define	URSEL		7
#define	UMSEL		6
#define UPM			4
#define USBS		3
#define UCSZ		1
#define UCPOL		0

#define	RC		7
#define	TC		6
#define UDRE	5
#define FE		4
#define DOR	3
#define PE		2
#define U2X	1

#define	RCIE		7
#define	TCIE		6
#define UDRIE		5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2
#define RXB8		1
#define TXB8		0
typedef enum {
    STOP_1_BIT,
    STOP_2_BIT
} ST_UART_stop_mode_t;

typedef enum {
    RCIE_DISABLE,
    RCIE_ENABLE
} ST_UART_rcie_mode_t;

typedef enum {
    TCIE_DISABLE,
    TCIE_ENABLE
} ST_UART_tcie_mode_t;

typedef enum {
    UDRIE_DISABLE,
    UDRIE_ENABLE
} ST_UART_urie_mode_t;

typedef enum {
    RX_DISABLE,
    RX_ENABLE
} ST_UART_rx_mode_t;

typedef enum {
    TX_DISABLE,
    TX_ENABLE
} ST_UART_tx_mode_t;

typedef enum {
    SYNC_SPEED_MODE,
    NORMAL_MODE,
    DOUBLE_MODE
} ST_UART_speed_mode_t;

typedef enum {
    NO_CLOCK,
    TXR_RXF,
    TXF_RXR
} ST_UART_clock_polarity_t;

typedef enum {
    PARITY_DISABLED,
    PARITY_EVEN,
    PARITY_ODD
} ST_UART_parity_mode_t;

typedef enum {
    ASYNC_MODE,
    SYNC_MODE
} ST_UART_mode_t;

typedef enum {
    CS_5,
    CS_6,
    CS_7,
    CS_8,
    CS_9
} ST_UART_cs_mode_t;

typedef struct {
    ST_UART_mode_t uart_mode;
    ST_UART_cs_mode_t uart_cs_mode;
    ST_UART_parity_mode_t uart_parity_mode;
    ST_UART_stop_mode_t uart_stop_mode;
    ST_UART_clock_polarity_t uart_clock_polarity;
    ST_UART_speed_mode_t uart_speed_mode;
    ST_UART_rcie_mode_t uart_rcie_mode;
    ST_UART_tcie_mode_t uart_tcie_mode;
    ST_UART_urie_mode_t uart_urie_mode;
    ST_UART_rx_mode_t uart_rx_mode;
    ST_UART_tx_mode_t uart_tx_mode;
    uint32_t usart_buadrate;
} ST_UART_config_t;

void UART_init(ST_UART_config_t *conf);
void UART_sendData(uint16_t data);
void UART_getData(uint16_t *data);

#endif /* UART_H_ */
