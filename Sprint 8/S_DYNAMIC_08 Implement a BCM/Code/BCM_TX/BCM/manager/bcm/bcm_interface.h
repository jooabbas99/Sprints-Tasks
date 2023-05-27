/*
 * bcm_interface.h
 *
 * Created: 5/25/2023 8:13:47 PM
 *  Author: Youssef Abbas
 */ 


#ifndef BCM_INTERFACE_H_
#define BCM_INTERFACE_H_

#include "../../i_lib/std_types.h"

// Communication protocol options
typedef enum {
	BCM_PROTOCOL_UART =0,
	BCM_PROTOCOL_SPI  ,
	BCM_PROTOCOL_I2C,
	BCM_MAX_PROTOCOL
} enm_cpo_t;

typedef enum {
	BCM_BUSY_FLAG=0,
	BCM_IDEL_FLAG
}enm_transiver_state_t;


typedef struct {
	uint8 * ptr_data;
	uint16 data_length;
}str_data_packet_t;
typedef struct {
	uint8 * ptr_data;
	uint16 * data_length;
}str_rdata_packet_t;


// BCM instance structure
typedef struct {
	uint8 bcm_instance_id;        // BCM instance ID
	enm_cpo_t protocol;               // Communication protocol (e.g., UART, SPI, I2C)
	void* protocolInstance;         // Pointer to the specific protocol instance
	
	
} str_bcm_instance_t;



// System status enumeration
typedef enum {
	BCM_OK = 0,                     // Operation successful
	BCM_INVALID_INSTANCE,           // Invalid BCM instance ID
	BCM_ALREADY_INITIALIZED,        // BCM instance already initialized
	BCM_NOT_INITIALIZED,            // BCM instance not initialized
	BCM_INVALID_PROTOCOL,            // Invalid communication protocol
	BCM_INVALID_PARAMETER
} enu_system_status_t;

// Initialize the BCM module
enu_system_status_t bcm_init(str_bcm_instance_t* ptr_str_bcm_instance);

// Deinitialize the BCM module
enu_system_status_t bcm_deinit(str_bcm_instance_t* ptr_str_bcm_instance);

// Send a single byte of data over a specific BCM instance
enu_system_status_t bcm_send(str_bcm_instance_t* ptr_str_bcm_instance, uint8 *data);

// Send multiple bytes of data over a specific BCM instance
enu_system_status_t bcm_send_n(str_bcm_instance_t* ptr_str_bcm_instance, uint8* data, uint16 length) ;
// Recive multiple bytes of data over a specific BCM instance
enu_system_status_t bcm_recive_n(str_bcm_instance_t* ptr_str_bcm_instance, uint8* data, uint16 *length);
// Dispatcher function to execute periodic actions and notify events
enu_system_status_t bcm_dispatcher(str_bcm_instance_t* ptr_str_bcm_instance,enm_transiver_state_t * state);


#endif /* BCM_INTERFACE_H_ */