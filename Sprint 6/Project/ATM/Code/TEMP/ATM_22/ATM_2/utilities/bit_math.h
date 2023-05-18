//
// Created by Youssef Abbas on 25/04/2023.
//

#ifndef ATMEGA32A_BIT_MATH_H
#define ATMEGA32A_BIT_MATH_H

// MACROS FOR BIT MANIBULATION

#define BIT_MASK        0x01

#define CLEAR_BIT(REG, BIT_POSN)            (REG &= (~(BIT_MASK << BIT_POSN)))  /*clear a specific bit in reg*/
#define SET_BIT(REG, BIT_POSN)              (REG |= (BIT_MASK << BIT_POSN))     /*set a specific bit in reg*/
#define TOGGLE_BIT(REG, BIT_POSN)           (REG ^= (BIT_MASK << BIT_POSN))     /*toggle specific bit in reg*/
#define READ_BIT(REG, BIT_POSN)             (((REG >> BIT_POSN) & BIT_MASK))    /*read a specific bit in reg*/

#endif //ATMEGA32A_BIT_MATH_H
