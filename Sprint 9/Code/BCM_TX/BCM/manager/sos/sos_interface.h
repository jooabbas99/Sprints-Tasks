/*
 * sos_interface.h
 *
 * Created: 5/31/2023 6:16:05 PM
 *  Author: Youssef Abbas
 */ 


#ifndef SOS_INTERFACE_H_
#define SOS_INTERFACE_H_
#include "../../i_lib/std_types.h"

// Data structures
typedef struct {
	uint8 interval;
	void (*taskFunc)(void);
	uint8 priority;
	uint8 counter;
}sos_task_t;


// Function prototypes
void sos_init(void);
void sos_deinit(void);
enu_system_status_t sos_create_task(uint8_t interval, void (*taskFunc)(void), uint8_t priority);
enu_system_status_t sos_delete_task(void (*taskFunc)(void));
enu_system_status_t sos_modify_task(void (*taskFunc)(void), uint8_t newInterval, uint8_t newPriority);
void sos_run(void);
void sos_disable(void);
void task1(void);
void task2(void);

#endif /* SOS_INTERFACE_H_ */