/*
 * motor.h
 *
 * Created: 4/13/2023 12:52:43 PM
 *  Author: Youssef Abbas
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_


#include "../../MCAL/DIO/DIO.h"

// EN_DCM_DIR_t is to determine the direction of the motor
typedef enum {
	DCM_CL_DIR = 0,
	DCM_ACL_DIR
}EN_DCM_DIR_t ;

// ST_DCM_t this to define motor data type
typedef struct {
	st_DIO_config dio;
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

/*
		BUTTON_status:
			return BTN_ACTIVE when the button is pressed  
			-inputs : *ST_BUTTON_t , *uint8_t pointer value
			- return : EN_BTN_ERROR_t with *uint8_t pointer value
*/
EN_BTN_ERROR_t DCM_start(ST_DCM_t * dcm,uint8_t speed);

#endif /* MOTOR_H_ */