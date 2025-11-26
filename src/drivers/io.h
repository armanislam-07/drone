#ifndef IO_H
#define IO_H

#include <stdint.h>
#include "registers.h"

typedef enum{
    GPIO_INPUT = 0,
    GPIO_OUTPUT_10MHZ = 1,
    GPIO_OUTPUT_2MHZ = 2,
    GPIO_OUTPUT_50MHZ = 3
} GPIO_MODE;


typedef enum{
    GPIO_GPPUSHPULL = 0, 
    GPIO_GPOPENDRAIN = 1, 
    GPIO_AFPUSHPULL = 2, 
    GPIO_AFOPENDRAIN = 3, 
    GPIO_ANALOG = 0,
    GPIO_FLOATINGRESETSTATE = 1,
    GPIO_INPUTPULLUPDOWN = 2
}GPIO_CNF; 

void setpin( GPIO_T *GPIOx, int8_t pin_number , GPIO_MODE mode, GPIO_CNF cnf);
void ioinit(void);

#endif