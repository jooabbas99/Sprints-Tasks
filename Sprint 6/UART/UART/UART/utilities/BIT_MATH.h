/*
 * BIT_MATH.h
 *
 * Created: 5/1/2023 6:52:01 PM
 *  Author: Youssef Abbas
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_



#define BIT_MASK							0x01

#define CLEAR_BIT(REG, BIT_POSN)            (REG &= (~(BIT_MASK << BIT_POSN)))  /*clear a specific bit in reg*/
#define SET_BIT(REG, BIT_POSN)              (REG |= (BIT_MASK << BIT_POSN))     /*set a specific bit in reg*/
#define TOGGLE_BIT(REG, BIT_POSN)           (REG ^= (BIT_MASK << BIT_POSN))     /*toggle specific bit in reg*/
#define READ_BIT(REG, BIT_POSN)             (((REG >> BIT_POSN) & BIT_MASK))    /*read a specific bit in reg*/

#endif /* BIT_MATH_H_ */