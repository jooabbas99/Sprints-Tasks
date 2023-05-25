/*
 * std_types.c
 *
 * Created: 5/25/2023 11:18:22 AM
 *  Author: Youssef Abbas
 */ 


typedef unsigned char uint8;          /* 1-BYTE UNSIGNED DATA (0 - 255)                */
typedef signed char   sint8;          /* 1-BYTE SIGNED DATA   (0 - 127) or (-1 - -128) */

typedef unsigned short int  uint16;   /* 2-BYTES UNSIGNED DATA   */
typedef signed short int    sint16;   /* 2-BYTES SIGNED DATA     */

typedef unsigned long int  uint32;     /* 4-BYTES UNSIGNED DATA  */
typedef signed long int    sint32;     /* 4-BYTES SIGNED DATA    */


typedef float  float32;                 /* 4-BYTES FLOATING DATA */
typedef double double64;                /* 8-BYTES FLOATING DATA */

#define NULL_PTR (uint8_t*)0x0