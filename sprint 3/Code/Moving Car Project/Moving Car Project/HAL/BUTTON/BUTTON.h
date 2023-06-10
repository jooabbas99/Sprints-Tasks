/*
 * button.h
 *
 * Created: 4/6/2023 10:29:47 PM
 *  Author: Youssef Abbas
 */ 

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

/*============= FILE INCLUSION =============*/
#include "../../MCAL/DIO/DIO.h"

/************************************************************************/
/*                               BUTTON TYPEDEF                         */
/************************************************************************/


// EN_BTN_STATUS_t value of the button is it pressed or not 
typedef enum {
	BTN_DISABLE = 0,
	BTN_ACTIVE=1
} EN_BTN_STATUS_t;

typedef enum {
	BTN_OK=0,
	BTN_ERROR,
	BTN_ERROR_DIO
} EN_BTN_ERROR_t;

// EN_BTN_MODE_t is to determine if button mode is in pull_up mode pull_down mode
typedef enum {
	BTN_PULL_DOWN = 0,
	BTN_PULL_UP
}EN_BTN_MODE_t ;

// ST_BUTTON_t this to define button data type
typedef struct {
	st_DIO_config dio;
	EN_BTN_MODE_t mode;
}ST_BUTTON_t;


/************************************************************************/
/*                           Function Prototypes                        */
/************************************************************************/

/*
		BUTTON_init:
			the aim duty for this function is to define btn and its ports in DIO driver 
			-inputs : *ST_BUTTON_t 
			- return : EN_BTN_ERROR_t with error status
*/
EN_BTN_ERROR_t BTN_init(ST_BUTTON_t * btn);

/*
		BUTTON_status:
			return BTN_ACTIVE when the button is pressed  
			-inputs : *ST_BUTTON_t , *uint8_t pointer value
			- return : EN_BTN_ERROR_t with *uint8_t pointer value
*/
EN_BTN_ERROR_t BTN_status(ST_BUTTON_t * btn,uint8 *status);



#endif /* HAL_BUTTON_BUTTON_H_ */
