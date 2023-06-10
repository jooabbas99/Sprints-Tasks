/*
 * bit_manibulation.h
 *
 * Created: 4/6/2023 9:18:21 PM
 *  Author: youss
 */ 


#ifndef BIT_MANIBULATION_H_
#define BIT_MANIBULATION_H_



#define BIT_MASK        0x01

#define CLEAR_BIT(REG, BIT_POSN)            (REG &= (~(BIT_MASK << BIT_POSN)))  /*clear a specific bit in reg*/
#define SET_BIT(REG, BIT_POSN)              (REG |= (BIT_MASK << BIT_POSN))     /*set a specific bit in reg*/
#define TOGGLE_BIT(REG, BIT_POSN)           (REG ^= (BIT_MASK << BIT_POSN))     /*toggle specific bit in reg*/
#define READ_BIT(REG, BIT_POSN)             (((REG >> BIT_POSN) & BIT_MASK))    /*read a specific bit in reg*/






#endif /* BIT_MANIBULATION_H_ */