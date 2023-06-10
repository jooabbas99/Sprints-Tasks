/*
 * std_tpes.h
 *
 * Created: 6/6/2023 11:38:26 AM
 *  Author: Youssef Abbas
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char uint8;          /* 1-BYTE UNSIGNED DATA (0 - 255)                */
typedef signed char   sint8;          /* 1-BYTE SIGNED DATA   (0 - 127) or (-1 - -128) */

typedef unsigned short int  uint16;   /* 2-BYTES UNSIGNED DATA   */
typedef signed short int    sint16;   /* 2-BYTES SIGNED DATA     */

typedef unsigned long int  uint32;     /* 4-BYTES UNSIGNED DATA  */
typedef signed long int    sint32;     /* 4-BYTES SIGNED DATA    */


typedef float  float32;                 /* 4-BYTES FLOATING DATA */
typedef double double64;                /* 8-BYTES FLOATING DATA */

typedef uint8	bool;

#define TRUE	1
#define FALSE	0

#endif /* STD_TPES_H_ */