/*
 * app.h
 *
 * Created: 5/25/2023 11:22:14 AM
 *  Author: Youssef Abbas
 */ 


#ifndef APP_H_
#define APP_H_

#define BUFFER_SIZE		50
typedef enum {
	BCM_TX_MODE=0,
	BCM_RX_MODE
}enm_bcm_mode_t;
void app_init(void);
void app_start(void);


#endif /* APP_H_ */