#ifndef PUSH_BUTTON_H
#define	PUSH_BUTTON_H

/* section : includes*/
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../STD_LIBRARIES/STD_TYPES.h"
#include "../../STD_LIBRARIES/bit_math.h"


/* section : Macro Declaration*/


/* section : Macro Functions Declarations*/

/* section : Data Types Declarations*/
typedef enum {
    BUTTON_RELEASED=0,
    BUTTON_PRESSED

}btn_enu_btn_state_t;

typedef enum{
    BUTTON_ACTIVE_LOW=0,
    BUTTON_ACTIVE_HIGH
}btn_enu__btn_active_t;

typedef struct{
    dio_enu_portx_t port_name;
    dio_enu_pinx_t pin;
    btn_enu_btn_state_t button_state;
    btn_enu__btn_active_t button_active;
}button_str_btn_config_t;

/*typedef struct{
	pin_INT_config_t pin_INT_config;
}button_INT_t;*/

typedef enum{
    BTN_NOT_OK=0,
    BTN_OK,
    BTN_NULL_PTR
}brn_enu_return_state_t;

/* section : Function Declaration*/

brn_enu_return_state_t button_initialization(const button_str_btn_config_t* ptr_str_btn_config);
brn_enu_return_state_t button_read_state( button_str_btn_config_t* ptr_str_btn_config, btn_enu_btn_state_t *ptr_enu_btn_state);

#endif	/* PUSH_BUTTON_H */
