/*
 * motor.h
 *
 * Created: 4/13/2023 12:52:43 PM
 *  Author: Youssef Abbas
 */ 

#include "DCmotor.h"
EN_DCM_ERROR_t DCM_init(ST_DCM_t * dcm){
	if(DIO_Init(&(dcm->pin_1)) != DIO_SUCCESS){
		return DCM_ERROR_DIO;
	}
	if(DIO_Init(&(dcm->pin_2)) != DIO_SUCCESS){
		return DCM_ERROR_DIO;
	}
	PWM_Timer2_Init();
	return DCM_OK;
}

EN_DCM_ERROR_t DCM_start(ST_DCM_t * dcm,uint8 speed){
	PWM_Timer2_Start(speed);
	switch(dcm->direction){
		case DCM_CL_DIR:
			dcm->pin_1.port_value = DIO_LOW ;
			dcm->pin_2.port_value = DIO_HIGH ;
			DIO_WritePin(&(dcm->pin_1));
			DIO_WritePin(&(dcm->pin_2));
			return DCM_OK;
			break;
		case DCM_ACL_DIR:
			dcm->pin_1.port_value = DIO_HIGH ;
			dcm->pin_2.port_value =DIO_LOW  ;
			DIO_WritePin(&(dcm->pin_1));
			DIO_WritePin(&(dcm->pin_2));
			return DCM_OK;
			break;
		default:
			dcm->pin_1.port_value = DIO_LOW ;
			dcm->pin_2.port_value =DIO_LOW  ;
			DIO_WritePin(&(dcm->pin_1));
			DIO_WritePin(&(dcm->pin_2));
			return DCM_ERROR;
			break;
			
	}
	
}

EN_DCM_ERROR_t DCM_stop(ST_DCM_t * dcm){
	PWM_Timer2_Stop();
	dcm->pin_1.port_value = DIO_LOW ;
	dcm->pin_2.port_value =DIO_LOW  ;
	DIO_WritePin(&(dcm->pin_1));
	DIO_WritePin(&(dcm->pin_2));
}


