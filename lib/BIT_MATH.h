#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var, BIT)    (*(var) |=  (1U << (BIT)))
#define CLR_BIT(var, BIT)    (*(var) &= ~(1U << (BIT)))
#define TOGGLE_BIT(var, BIT) (*(var) ^=  (1U << (BIT)))
#define GET_BIT(var, BIT)    (((*(var)) >> (BIT)) & 1U)

#endif
