/*
 * motor.h
 *
 * Created: 4/13/2023 12:52:43 PM
 *  Author: Youssef Abbas
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "DCmotor.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER2_PWM/Timer2_PWM.h"

// EN_DCM_DIR_t is to determine the direction of the motor
typedef enum {
	DCM_CL_DIR = 0,
	DCM_ACL_DIR,
	
}EN_DCM_DIR_t ;

// ST_DCM_t this to define motor data type
typedef struct {
	st_DIO_config pin_1;
	st_DIO_config pin_2;
	EN_DCM_DIR_t direction;
	
}ST_DCM_t;

typedef enum {
	DCM_OK=0,
	DCM_ERROR,
	DCM_ERROR_DIO
} EN_DCM_ERROR_t;


/************************************************************************/
/*                           Function Prototypes                        */
/************************************************************************/

/*
		DCM_init:
			the aim of this function is to define dc motor configration and its ports in DIO driver 
			-inputs : *ST_DCM_t 
			- return : EN_DCM_ERROR_t with error status
*/
EN_DCM_ERROR_t DCM_init(ST_DCM_t * dcm);

EN_DCM_ERROR_t DCM_start(ST_DCM_t * dcm,uint8 speed);
EN_DCM_ERROR_t DCM_stop(ST_DCM_t * dcm);
#endif /* DCMOTOR_H_ */
