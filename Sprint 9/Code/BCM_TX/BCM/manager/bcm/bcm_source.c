/*
 * bcm_source.c
 *
 * Created: 5/25/2023 8:14:00 PM
 *  Author: Youssef Abbas
 */ 
#include "bcm_interface.h"

#include "bcm_conf.h"
#include "../../mcal/uart/uart_interface.h"
// BCM instance array
static str_bcm_instance_t bcm_instances[NUM_BCM_INSTANCES] = {0};
static str_data_packet_t pakets[NUM_BCM_INSTANCES] = {0};
static str_rdata_packet_t pakets_recive[NUM_BCM_INSTANCES] = {0};
static enm_transiver_state_t enm_transiver_state[NUM_BCM_INSTANCES] = {1};


void uart_tx_callback(void){
	static uint8 counter = 0;
	uint8 temp = 0;
	
	if(counter == 0){
		temp = (uint8)(pakets[BCM_PROTOCOL_UART].data_length>>8);
		uart_write(&temp);
		counter ++;
		} else if (counter < (pakets[BCM_PROTOCOL_UART].data_length-1))
		{
			temp = (pakets[BCM_PROTOCOL_UART].ptr_data)[counter-1];
			uart_write(&temp);
			counter ++;
		if (counter >= pakets[BCM_PROTOCOL_UART].data_length-1)
		{
			counter = 0;
			uart_udrei_disable();
			enm_transiver_state[BCM_PROTOCOL_UART] = BCM_IDEL_FLAG;
		}
		}
// 		else{
// 			counter = 0;
// 			uart_udrei_disable();
// 			enm_transiver_state[BCM_PROTOCOL_UART] = BCM_IDEL_FLAG;
// 	}
}
void uart_rx_callback(void){
	static uint8 counter = 0;
	uint8 temp = 0;
	
	if(counter < 2){
		uart_read(&temp);
		*(pakets_recive[BCM_PROTOCOL_UART].data_length)|=((uint16)temp)<< (counter*8);
		counter ++;
	} else if (counter < *(pakets_recive[BCM_PROTOCOL_UART].data_length ))
	{
		uart_read(&temp);
		((pakets_recive[BCM_PROTOCOL_UART].ptr_data)[counter - LENGTH_BYTE_SIZE]) = temp;
		counter ++;
		// last byte
		if (counter >= *(pakets_recive[BCM_PROTOCOL_UART].data_length))
		{
			counter = 0;
			uart_rxci_disable();
			*(pakets_recive[BCM_PROTOCOL_UART].data_length) -= LENGTH_BYTE_SIZE;
			enm_transiver_state[BCM_PROTOCOL_UART] = BCM_IDEL_FLAG;
		}
	}
}

// Initialize the BCM module
enu_system_status_t bcm_init(str_bcm_instance_t* ptr_str_bcm_instance) {
	if (ptr_str_bcm_instance == NULL || ptr_str_bcm_instance->protocol >= NUM_BCM_INSTANCES) {
		return BCM_INVALID_INSTANCE;
	}
	
	if (bcm_instances[ptr_str_bcm_instance->bcm_instance_id].protocol != 0) {
		return BCM_ALREADY_INITIALIZED;
	}
	
	switch (ptr_str_bcm_instance->protocol) {
		case BCM_PROTOCOL_UART:
			// Initialize UART protocol instance
			uart_init((uart_config_t*)ptr_str_bcm_instance->protocolInstance);
			break;
		
		case BCM_PROTOCOL_SPI:
		// Initialize SPI protocol instance
		// Example: spi_init(ptr_str_bcm_instance->protocolInstance);
		break;
		
		case BCM_PROTOCOL_I2C:
		// Initialize I2C protocol instance
		// Example: i2c_init(ptr_str_bcm_instance->protocolInstance);
		break;
		
		default:
		return BCM_INVALID_PROTOCOL;
	}
	
	// Store the BCM instance information
	bcm_instances[ptr_str_bcm_instance->bcm_instance_id] = *ptr_str_bcm_instance;
	
	return BCM_OK;
}

// Deinitialize the BCM module
enu_system_status_t bcm_deinit(str_bcm_instance_t* ptr_str_bcm_instance) {
	if (ptr_str_bcm_instance == NULL || ptr_str_bcm_instance->bcm_instance_id >= NUM_BCM_INSTANCES) {
		return BCM_INVALID_INSTANCE;
	}
	
	if (bcm_instances[ptr_str_bcm_instance->bcm_instance_id].protocol == 0) {
		return BCM_NOT_INITIALIZED;
	}
	
	// Perform protocol-specific deinitialization
	// Example: uart_deinit(bcm_instances[ptr_str_bcm_instance->bcm_instance_id].protocolInstance);
	
	// Clear the BCM instance information
	bcm_instances[ptr_str_bcm_instance->bcm_instance_id].bcm_instance_id = 0;
	bcm_instances[ptr_str_bcm_instance->bcm_instance_id].protocol = BCM_MAX_PROTOCOL;
	bcm_instances[ptr_str_bcm_instance->bcm_instance_id].protocolInstance = NULL;
	
	return BCM_OK;
}

// Send a single byte of data over a specific BCM instance
enu_system_status_t bcm_send(str_bcm_instance_t* ptr_str_bcm_instance, uint8 *data) {
	if (ptr_str_bcm_instance == NULL || ptr_str_bcm_instance->bcm_instance_id >= NUM_BCM_INSTANCES) {
		return BCM_INVALID_INSTANCE;
	}
	
	if (bcm_instances[ptr_str_bcm_instance->bcm_instance_id].protocol >= BCM_MAX_PROTOCOL) {
		return BCM_NOT_INITIALIZED;
	}
	
	// Perform protocol-specific send operation
	uint8 temp = 0;
	switch (ptr_str_bcm_instance->protocol) {
		case BCM_PROTOCOL_UART:
			enm_transiver_state[BCM_PROTOCOL_UART] = BCM_BUSY_FLAG;
		
			// add 2 byte of the length + 1 data
			pakets[BCM_PROTOCOL_UART].data_length = (LENGTH_BYTE_SIZE + DATA_BYTE_SIZE) ;
			pakets[BCM_PROTOCOL_UART].ptr_data = data;
			// send data length 
			temp = (uint8)pakets[BCM_PROTOCOL_UART].data_length;
			uart_write(&temp);
			uart_write_INT(uart_tx_callback);
		break;
			
		case BCM_PROTOCOL_SPI:
		
		break;
			
		case BCM_PROTOCOL_I2C:

		break;
			
		default:
		return BCM_INVALID_PROTOCOL;
	}
	return BCM_OK;
}

// Send multiple bytes of data over a specific BCM instance
enu_system_status_t bcm_send_n(str_bcm_instance_t* ptr_str_bcm_instance, uint8* data, uint16 length) {
	if (ptr_str_bcm_instance == NULL || ptr_str_bcm_instance->bcm_instance_id >= NUM_BCM_INSTANCES) {
		return BCM_INVALID_INSTANCE;
	}
	
	if (bcm_instances[ptr_str_bcm_instance->bcm_instance_id].protocol >= BCM_MAX_PROTOCOL) {
		return BCM_NOT_INITIALIZED;
	}
	
	if (data == NULL || length == 0) {
		return BCM_INVALID_PARAMETER;
	}
	
	// Perform protocol-specific send operation
	uint8 temp = 0;
	switch (ptr_str_bcm_instance->protocol) {
		case BCM_PROTOCOL_UART:
			enm_transiver_state[BCM_PROTOCOL_UART] = BCM_BUSY_FLAG;
			// add 2 byte of the length
			pakets[BCM_PROTOCOL_UART].data_length = (length + LENGTH_BYTE_SIZE);
			pakets[BCM_PROTOCOL_UART].ptr_data = data;
			// send data length
			temp = (uint8)pakets[BCM_PROTOCOL_UART].data_length;
			uart_write(&temp);
			uart_write_INT(uart_tx_callback);
		break;
		
		case BCM_PROTOCOL_SPI:
		
		break;
		
		case BCM_PROTOCOL_I2C:

		break;
		
		default:
		return BCM_INVALID_PROTOCOL;
	}
	
	return BCM_OK;
}


enu_system_status_t bcm_recive_n(str_bcm_instance_t* ptr_str_bcm_instance, uint8* data, uint16 *length) {
	if (ptr_str_bcm_instance == NULL || ptr_str_bcm_instance->bcm_instance_id >= NUM_BCM_INSTANCES) {
		return BCM_INVALID_INSTANCE;
	}
	
	if (bcm_instances[ptr_str_bcm_instance->bcm_instance_id].protocol >= BCM_MAX_PROTOCOL) {
		return BCM_NOT_INITIALIZED;
	}
	
	// Perform protocol-specific send operation
	uint8 temp = 0;
	switch (ptr_str_bcm_instance->protocol) {
		case BCM_PROTOCOL_UART:
		enm_transiver_state[BCM_PROTOCOL_UART] = BCM_BUSY_FLAG;
		// add 2 byte of the length
		*length = 0;
		pakets_recive[BCM_PROTOCOL_UART].data_length = length ;
		pakets_recive[BCM_PROTOCOL_UART].ptr_data = data;

		uart_read_INT(uart_rx_callback);
		break;
		
		case BCM_PROTOCOL_SPI:
		
		break;
		
		case BCM_PROTOCOL_I2C:

		break;
		
		default:
		return BCM_INVALID_PROTOCOL;
	}
	
	return BCM_OK;
}

// Dispatcher function to execute periodic actions and notify events
enu_system_status_t bcm_dispatcher(str_bcm_instance_t* ptr_str_bcm_instance,enm_transiver_state_t * state) {
	if (ptr_str_bcm_instance == NULL || ptr_str_bcm_instance->bcm_instance_id >= NUM_BCM_INSTANCES) {
		return BCM_INVALID_INSTANCE;
	}
	
	if (bcm_instances[ptr_str_bcm_instance->bcm_instance_id].protocol  >= BCM_MAX_PROTOCOL) {
		return BCM_NOT_INITIALIZED;
	}
	
	// Perform protocol-specific periodic actions and event notification
	switch (ptr_str_bcm_instance->protocol) {
		case BCM_PROTOCOL_UART:
			*state = enm_transiver_state[BCM_PROTOCOL_UART];
		// add 2 byte of the lengt
		break;
		
		case BCM_PROTOCOL_SPI:
			*state = enm_transiver_state[BCM_PROTOCOL_SPI];
		break;
		
		case BCM_PROTOCOL_I2C:
			*state = enm_transiver_state[BCM_PROTOCOL_I2C];
		break;
		
		default:
		return BCM_INVALID_PROTOCOL;
	}
	
	return BCM_OK;
}