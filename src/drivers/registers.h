#ifndef REGISTERS_H
#define REGISTERS_H


#include <stdint.h>




//timer
#define TIM1 ((TIM_T*) 0x40012c00)
#define TIM1_BDTR  (*(volatile uint32_t*)(0x40012C44))

#define TIM2 ((TIM_T*) 0x40000000)
#define TIM3 ((TIM_T*)0x40000400)
#define TIM4 ((TIM_T*)0x40000800)

//RCC
#define RCC_APB1ENR *((uint32_t * ) 0x4002101c)
#define RCC_APB1ENR_TIME2EN 1<<0
#define RCC_APB1ENR_TIME3EN 1<<1
#define RCC_APB1ENR_TIME4EN 1<<2

#define RCC_APB2ENR *((uint32_t * )0x40021018)
#define RCC_APB2ENR_IOPAEN 1<<2
#define RCC_APB2ENR_IOPBEN 1<<3
#define RCC_APB2ENR_IOPCEN 1<<4
#define RCC_APB2ENR_AFIOEN 1<<0
#define RCC_APB2ENR_TIME1EN 1<<11
#define RCC_APB1ENR_I2C1EN 1<<21
#define RCC_APB1ENR_I2C1EN 1<<17
 
//mpu 6050
#define MPU6050_ADDR     0x68 << 1  
#define PWR_MGMT_1       0x6B
#define ACCEL_XOUT_H     0x3B

//i2c
#define I2C1 ((I2C_T *)0x40005400)
#define I2C_CR1_SWRST (1 << 15)
#define I2C_CR1_PECEN (1 << 23)
#define I2C_CR1_PE   (1 << 0)
#define I2C_CR1_START   (1 << 8)
#define I2C_CR1_STOP   (1 << 9)
#define I2C_SR1_TXE   (1 << 7)
#define I2C_CR1_ACK   (1 << 10)
#define I2C_SR1_RXNE   (1 << 6)
#define I2C_SR1_SB   (1 << 0)

//GPIO
#define GPIOA ((GPIO_T *)0x40010800)
#define GPIOB ((GPIO_T *)0x40010c00)
#define GPIOC ((GPIO_T *)0x40011000)

//i2c
typedef struct {
    volatile uint32_t CR1;  
    volatile uint32_t CR2;
    volatile uint32_t OAR1;  
    volatile uint32_t OAR2;
    volatile uint32_t DR;  
    volatile uint32_t SR1;
    volatile uint32_t SR2;  
    volatile uint32_t CCR;
    volatile uint32_t TRISE;  
    


}I2C_T;



//timer Structure (Note that not all bit values are named due to them being UNUSED) ( add volatile)
typedef struct{
    union{
        uint32_t reg;
        struct{
            volatile uint32_t CEN:1;
            volatile uint32_t before: 6;


            volatile uint32_t APRE:1;
            volatile uint32_t after:8;




        }bit;






    } CR1;
    uint32_t CR2;
    uint32_t SMCR;
    uint32_t DIER;
    uint32_t SR;
    union{
    uint32_t reg;
    struct{
        volatile uint32_t UG:1;
        volatile uint32_t rest:15;








    }bit;


    }EGR;
    union{
        uint32_t reg;
        struct{
            volatile uint32_t CC1S:2;
            volatile uint32_t OC1FE:1;
            volatile uint32_t OC1PE:1;
            volatile uint32_t OC1M:3;
            volatile uint32_t OC1CE:1;
            volatile uint32_t CC2S:2;
            volatile uint32_t IC2PSC:2;
            volatile uint32_t IC2F:4;






        }bit;



    }CCMR1_Output;
    uint32_t CCMR2_Output;
    union{
        uint32_t reg;
        struct{
            volatile uint32_t CC1E:1;
            volatile uint32_t rest:15; //not labeling the rest of the registers  bc i dont need to


        }bit;






    } CCER;
    uint32_t CNT;
    uint32_t PSC;
    uint32_t ARR;
    uint32_t RCR;
    uint32_t CCR1;
    uint32_t CCR2;
    uint32_t CCR3;
    uint32_t CCR4;
    uint32_t DCR;
    uint32_t DMAR;
}TIM_T;

//GPIO Structure (Note that not all bit values are named due to them being UNUSED)
typedef struct
{


   union{
       uint32_t reg;
       struct {
        volatile uint32_t MODE0:2;
        volatile uint32_t CNF0:2;
        volatile uint32_t MODE1:2;
        volatile uint32_t CNF1:2;
        volatile uint32_t MODE2:2;
        volatile uint32_t CNF2:2;
        volatile uint32_t MODE3:2;
        volatile uint32_t CNF3:2;
        volatile uint32_t MODE4:2;
        volatile uint32_t CNF4:2;
        volatile uint32_t MODE5:2;
        volatile uint32_t CNF5:2;
        volatile uint32_t MODE6:2;
        volatile uint32_t CNF6:2;
        volatile uint32_t MODE7:2;
        volatile uint32_t CNF7:2;
       }bit;
   }CRL;
   union{
    uint32_t reg;
       struct {
        volatile uint32_t MODE8:2;
        volatile uint32_t CNF8:2;
        volatile uint32_t MODE9:2;
        volatile uint32_t CNF9:2;
        volatile uint32_t MODE10:2;
        volatile uint32_t CNF10:2;
        volatile uint32_t MODE11:2;
        volatile uint32_t CNF11:2;
        volatile uint32_t MODE12:2;
        volatile uint32_t CNF12:2;
        volatile uint32_t MODE13:2;
        volatile uint32_t CNF13:2;
        volatile uint32_t MODE14:2;
        volatile uint32_t CNF14:2;
        volatile uint32_t MODE15:2;
        volatile uint32_t CNF15:2;
       }bit;



   } CRH;
   uint32_t IDR;
   union{
        uint32_t reg;
        struct
        {
        volatile uint32_t ODR0  :1;
        volatile uint32_t ODR1  :1;
        volatile uint32_t ODR2  :1;
        volatile uint32_t ODR3  :1;
        volatile uint32_t ODR4  :1;
        volatile uint32_t ODR5  :1;
        volatile uint32_t ODR6  :1;
        volatile uint32_t ODR7  :1;
        volatile uint32_t ODR8  :1;
        volatile uint32_t ODR9  :1;
        volatile uint32_t ODR10 :1;
        volatile uint32_t ODR11 :1;
        volatile uint32_t ODR12 :1;
        volatile uint32_t ODR13 :1;
        volatile uint32_t ODR14 :1;
        volatile uint32_t ODR15 :1;
        }bit;





   } ODR;
   union{
      uint32_t reg;
      struct{ //documentation doesnt go from 0-32 it goes from 0-15 twice but its easier to understand like this
          volatile uint32_t BSSR0  :1;
              volatile uint32_t BSSR1  :1;
              volatile uint32_t BSSR2  :1;
              volatile uint32_t BSSR3  :1;
              volatile uint32_t BSSR4  :1;
              volatile uint32_t BSSR5  :1;
              volatile uint32_t BSSR6  :1;
              volatile uint32_t BSSR7  :1;
              volatile uint32_t BSSR8  :1;
              volatile uint32_t BSSR9  :1;
              volatile uint32_t BSSR10 :1;
              volatile uint32_t BSSR11 :1;
              volatile uint32_t BSSR12 :1;
              volatile uint32_t BSSR13 :1;
              volatile uint32_t BSSR14 :1;
              volatile uint32_t BSSR15 :1;
              volatile uint32_t BSSR16 :1;
              volatile uint32_t BSSR17 :1;
              volatile uint32_t BSSR18 :1;
              volatile uint32_t BSSR19 :1;
              volatile uint32_t BSSR20 :1;
              volatile uint32_t BSSR21 :1;
              volatile uint32_t BSSR22 :1;
              volatile uint32_t BSSR23 :1;
              volatile uint32_t BSSR24 :1;
              volatile uint32_t BSSR25 :1;
              volatile uint32_t BSSR26 :1;
              volatile uint32_t BSSR27 :1;
              volatile uint32_t BSSR28 :1;
              volatile uint32_t BSSR29 :1;
              volatile uint32_t BSSR30 :1;
              volatile uint32_t BSSR31 :1;


      }bit;




   }BSSR;
   uint32_t BRR;
   uint32_t LCKR;
} GPIO_T;


#endif 