#ifndef MOVING_CAR_SYSTEM_COMMON_MACROS_H
#define MOVING_CAR_SYSTEM_COMMON_MACROS_H

/**
 * @brief Set a specific bit in the REG register.
 */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/**
 * @brief Clear a specific bit in the REG register.
 */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/**
 * @brief Toggle a specific bit in the REG register.
 */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/**
 * @brief Check if a specific bit is set in the REG register and return true if yes.
 */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/**
 * @brief Check if a specific bit is cleared in the REG register and return true if yes.
 */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/**
* @brief Enables global interrupts, by setting I-bit in status register.
*/
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/**
* @brief Disables global interrupts, by clearing I-bit in status register.
*/
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

#endif //MOVING_CAR_SYSTEM_COMMON_MACROS_H
