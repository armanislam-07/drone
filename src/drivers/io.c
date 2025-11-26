#include "io.h"
#include "registers.h"

void setpin(GPIO_T *GPIOx, int8_t pin_number, GPIO_MODE mode, GPIO_CNF cnf)
{
    volatile uint32_t *config_reg; // the * is to dereference the pointer and tells us to go directly at the register value
    uint8_t shift;

    if (pin_number < 8)
    {
        config_reg = &GPIOx->CRL.reg;
        shift = pin_number * 4; // there are 4 bits at each pin
    }
    else if (pin_number < 16)
    {
        config_reg = &GPIOx->CRH.reg;
        shift = (pin_number - 8) * 4;
    }
    else
    {
        return; // if given illegal pin escape function
    }

    *config_reg &= ~(15 << shift); // 15 = 1111 so bascailyl were are clearing from the shfit value onward bc its 4 bits per pin

    uint32_t value = ((cnf & 0b11) << 2) | (mode & 0b11); // explaining the 0b11 -> makes sure not illegal values
    *config_reg |= (value << shift);
}
/*
Pins for the motors are A0 A1 | A10 A4 | A6 B0 | A7 C1
*/
void ioinit(void)
{
    RCC_APB2ENR |= RCC_APB2ENR_IOPAEN; //peripheral clock for gpioa
    RCC_APB2ENR |= RCC_APB2ENR_TIME1EN;
    RCC_APB1ENR |= RCC_APB1ENR_TIME2EN; //turns on timer2 periperhal
    RCC_APB1ENR |= RCC_APB1ENR_TIME3EN;
    RCC_APB1ENR |= RCC_APB1ENR_TIME4EN;

    RCC_APB1ENR |= RCC_APB1ENR_I2C1EN; // I2c clock 1
    RCC_APB2ENR |= RCC_APB2ENR_IOPBEN; // peripeheral for gpiob
    RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;
    RCC_APB2ENR |= RCC_APB2ENR_AFIOEN;

    setpin(GPIOA, 0, GPIO_AFPUSHPULL, GPIO_OUTPUT_50MHZ);
    setpin(GPIOA, 1, GPIO_GPPUSHPULL, GPIO_OUTPUT_10MHZ);
    GPIOA->ODR.bit.ODR1 = 0;

    setpin(GPIOA, 10, GPIO_AFPUSHPULL, GPIO_OUTPUT_50MHZ);
    setpin(GPIOA, 4, GPIO_GPPUSHPULL, GPIO_OUTPUT_10MHZ);
    GPIOA->ODR.bit.ODR3 = 0;

    setpin(GPIOA, 6, GPIO_AFPUSHPULL, GPIO_OUTPUT_50MHZ);
    setpin(GPIOB, 0, GPIO_GPPUSHPULL, GPIO_OUTPUT_10MHZ);
    GPIOC->ODR.bit.ODR7 = 0;

    setpin(GPIOA, 7, GPIO_AFPUSHPULL, GPIO_OUTPUT_50MHZ);
    setpin(GPIOC, 1, GPIO_GPPUSHPULL, GPIO_OUTPUT_10MHZ);
    GPIOB->ODR.bit.ODR4 = 0;
}
