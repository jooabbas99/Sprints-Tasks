/*
 * bit_math.h
 *
 * Created: 6/6/2023 11:38:12 AM
 *  Author: Youssef Abbas
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/*macro to check if a bit is set*/
#define BIT_IS_SET(byte,bit_num) (byte & (1<<bit_num))

/*macro to check if bit is cleared*/
#define BIT_IS_CLEAR(byte,bit_num) (!(byte & (1<<bit_num)))
#define BIT_MASK        0x01

#define CLEAR_BIT(REG, BIT_POSN)            (REG &= (~(BIT_MASK << BIT_POSN)))  /*clear a specific bit in reg*/
#define SET_BIT(REG, BIT_POSN)              (REG |= (BIT_MASK << BIT_POSN))     /*set a specific bit in reg*/
#define TOGGLE_BIT(REG, BIT_POSN)           (REG ^= (BIT_MASK << BIT_POSN))     /*toggle specific bit in reg*/
#define READ_BIT(REG, BIT_POSN)             (((REG >> BIT_POSN) & BIT_MASK))    /*read a specific bit in reg*/

#define GET_ARR_SIZE(arr)	(sizeof(arr)/sizeof(arr[0]))
#endif /* BIT_MATH_H_ */