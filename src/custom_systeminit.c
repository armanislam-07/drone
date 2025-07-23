#include <stdint.h>


//RCC
#define RCC_BASE ((RCC_T * ) 0x40021000) 
#define FLASH_ACR (*(volatile uint32_t *)0x40022000)

//RCC Struc | //check if this is the right format since typedef wouldnt maek sensebc its onyl one rcc
typedef struct{
    union{
        uint32_t reg;
        struct{
            uint32_t before:16;
            uint32_t HSEON:1;
            uint32_t HSERDY:1; 
            uint32_t after: 6;
            uint32_t PLLON:1;
            uint32_t PLLRDY:1;
            uint32_t afterafter:6;



        }bit;


    } CR;
    union{
        uint32_t reg;
        struct{
            uint32_t SW:2;
            uint32_t SWS:2;
            uint32_t HPRE:4;
            uint32_t PPRE1:3;
            uint32_t PPRE2:3;
            uint32_t ADC_PRE:2;
            uint32_t PLLSRC:1;
            uint32_t PLLXTPRE:1;
            uint32_t PLLMUL:4;
            uint32_t OTGFSPRE:1;
            uint32_t res:1;
            uint32_t MCO:3;
            uint32_t reserved:3;


        }bit;



    } CFGR;
    uint32_t CIR;
    uint32_t APB2RSTR;
    uint32_t APB1RSTR;
    uint32_t AHBENR;
    uint32_t APB2ENR;
    uint32_t APB1ENR;
    uint32_t BDCR;
    uint32_t CSR;
}RCC_T;

 

// system_stm32f1xx.h
void SystemInit(void){
//turn on hse 
RCC_BASE->CR.bit.HSEON = 1;

//wait until HSERDY shows its enabled 
while(!(RCC_BASE->CR.bit.HSERDY));
FLASH_ACR |= 0x2;

RCC_BASE->CFGR.bit.PLLSRC = 1;
RCC_BASE->CFGR.bit.PLLMUL = 7 ; //?
RCC_BASE->CR.bit.PLLON = 1; 

while(!(RCC_BASE->CR.bit.PLLRDY));
RCC_BASE->CFGR.bit.SW = 2;
while(RCC_BASE->CFGR.bit.SWS != 0b10);
}