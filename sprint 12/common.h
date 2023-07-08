/**
 ** @file                   common.h
 ** @brief                  This is header file for common macros used 
 ** @author                 Hazem Ashraf
 ** @date                   Jun 15, 2023
 ** @version                0.1
 */

/*----------------------------------------------------------/
/- INCLUDES -----------------------------------------------/
/----------------------------------------------------------*/

#include "stdint.h"

/*----------------------------------------------------------/
/- MACROS --------------------------------------------------/
/----------------------------------------------------------*/

#define SUCCESS (0)
#define ERROR (-1)
#define INVALID_INPUT (-2)
#define NULL ((void*)0)
#ifndef TRUE
#define TRUE (1)
#endif

#ifndef FALSE
#define FALSE (0)
#endif

/*----------------------------------------------------------/
/- TYPE DEFINITIONS ----------------------------------------/
/----------------------------------------------------------*/
typedef unsigned char boolean;



/*----------------------------------------------------------/
/- BIT MAINPULATION ----------------------------------------/
/----------------------------------------------------------*/

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1UL<<BIT))

/* Clear a certain bit in any register */
#define CLR_BIT(REG,BIT) (REG&=(~(1UL<<BIT)))

/* get value of a certain bit in any register */
#define GET_BIT_STATUS(REGISTER,BIT_NUMBER)		(0UL != ((REGISTER) & (1UL << (BIT_NUMBER))))
