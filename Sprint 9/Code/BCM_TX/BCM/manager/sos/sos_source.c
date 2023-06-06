/*
 * sos_source.c
 *
 * Created: 5/31/2023 6:15:47 PM
 *  Author: Youssef Abbas
 */ 




// Global variables
sos_task_t taskList[MAX_TASKS];
uint8_t taskCount = 0;
volatile bool sosRunning = false;



// Function to initialize the SOS
void sos_init(void) {
	sos_deinit();
	// Initialize any other necessary variables or hardware

	// Configure Timer1 for time-triggered scheduling
	TCCR1B |= (1 << WGM12); // CTC mode
	OCR1A = 250; // Set compare value for 1ms interrupt
	TIMSK |= (1 << OCIE1A); // Enable compare interrupt

	sei(); // Enable global interrupts

	printf("SOS initialized\n");
}

// Function to deinitialize the SOS
void sos_deinit(void) {
	sos_disable();
	// Reset any variables or hardware to their default state
	taskCount = 0;
	printf("SOS deinitialized\n");
}

// Function to create a new task and add it to the SOS database
enu_system_status_t sos_create_task(uint8_t interval, void (*taskFunc)(void), uint8_t priority) {
	if (taskCount >= MAX_TASKS) {
		return SOS_STATUS_MAX_TASKS_REACHED;
	}

	sos_task_t task;
	task.interval = interval;
	task.taskFunc = taskFunc;
	task.priority = priority;
	task.counter = 0;

	taskList[taskCount++] = task;

	return SOS_STATUS_SUCCESS;
}

// Function to delete an existing task from the SOS database
enu_system_status_t sos_delete_task(void (*taskFunc)(void)) {
	for (uint8_t i = 0; i < taskCount; i++) {
		if (taskList[i].taskFunc == taskFunc) {
			for (uint8_t j = i; j < taskCount - 1; j++) {
				taskList[j] = taskList[j + 1];
			}
			taskCount--;
			return SOS_STATUS_SUCCESS;
		}
	}

	return SOS_STATUS_TASK_NOT_FOUND;
}

// Function to modify existing task parameters in the SOS database
enu_system_status_t sos_modify_task(void (*taskFunc)(void), uint8_t newInterval, uint8_t newPriority) {
	for (uint8_t i = 0; i < taskCount; i++) {
		if (taskList[i].taskFunc == taskFunc) {
			taskList[i].interval = newInterval;
			taskList[i].priority = newPriority;
			return SOS_STATUS_SUCCESS;
		}
	}

	return SOS_STATUS_TASK_NOT_FOUND;
}

// Function to run the small scheduler
void sos_run(void) {
	if (sosRunning) {
		printf("SOS is already running\n");
		return;
	}
	sosRunning = true;
	printf("SOS running\n");

	while (sosRunning) {
		for (uint8_t priority = 1; priority <= 255; priority++) {
			for (uint8_t i = 0; i < taskCount; i++) {
				sos_task_t *task = &taskList[i];
				if (task->priority == priority) {
					task->counter++;
					if (task->counter >= task->interval) {
						task->counter = 0;
						task->taskFunc();
					}
				}
			}
		}
	}
}

// Function to stop the scheduler
void sos_disable(void) {
	sosRunning = false;
	printf("SOS disabled\n");
}