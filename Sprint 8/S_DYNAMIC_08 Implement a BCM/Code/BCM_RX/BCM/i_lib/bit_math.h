/*
 * bit_math.c
 *
 * Created: 5/25/2023 11:18:41 AM
 *  Author: Youssef Abbas
 */ 

/*macro to check if a bit is set*/
#define BIT_IS_SET(byte,bit_num) (byte & (1<<bit_num))

/*macro to check if bit is cleared*/
#define BIT_IS_CLEAR(byte,bit_num) (!(byte & (1<<bit_num)))
#define BIT_MASK        0x01

#define CLEAR_BIT(REG, BIT_POSN)            (REG &= (~(BIT_MASK << BIT_POSN)))  /*clear a specific bit in reg*/
#define SET_BIT(REG, BIT_POSN)              (REG |= (BIT_MASK << BIT_POSN))     /*set a specific bit in reg*/
#define TOGGLE_BIT(REG, BIT_POSN)           (REG ^= (BIT_MASK << BIT_POSN))     /*toggle specific bit in reg*/
#define READ_BIT(REG, BIT_POSN)             (((REG >> BIT_POSN) & BIT_MASK))    /*read a specific bit in reg*/
