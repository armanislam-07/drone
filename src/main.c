

#include <stdint.h>

#include "../drivers/registers.h"





void delay(uint32_t time) {
	 volatile uint32_t count;
	    for (uint32_t i = 0; i < time; i++) {
	        count = 18000000; // Tune this as needed
	        while (count--) {
	            __asm__("nop"); // no operation (prevent optimization)
	        }
	    }

    }





int main(void)
{
    RCC_APB2ENR |= RCC_APB2ENR_IOPAEN; //turn on the peripheral clock for gpioa
    RCC_APB1ENR |= RCC_APB1ENR_TIME2EN; //turns on timer2 periperhal



    //PIN 0
    GPIOA->CRL.bit.CNF0= 2; //alternate push pull
    GPIOA->CRL.bit.MODE0 = 3; //50Mhz (go back in testing to see if we need 50Mhz)



    //things to find out | why does changing the arr to 653535 do somethig ( calcluate i think)


    //make sure PA1 is set to low and so its not floating with random signal outputs| moves the propller forward
    GPIOA->CRL.bit.CNF1 = 0;
    GPIOA->CRL.bit.MODE1 = 3;
    GPIOA->ODR.bit.ODR1 = 0;


    TIM2->CCR1 = 25; //duty cycle to 0
    TIM2->PSC = 72-1; //timer clock in MHz 72MHz
    TIM2->ARR = 1000 - 1 ;  //PWM Period 1Mhz
    TIM2->CCMR1_Output.bit.OC1M = 6; // PWM Mode 1
    TIM2->CCMR1_Output.bit.OC1PE = 1; // Output compare preload enable
    TIM2->CCER.bit.CC1E= 1; // Capture/Compare 1 Output Enable
    TIM2->CR1.bit.APRE=1; // auto preload enable
    TIM2->EGR.bit.UG=1; //update generation
    TIM2->CR1.bit.CEN=1; //counter enable


    for(;;){









        //GPIOA->BSSR.bit.BSSR0=1; // BSSR is safer
        //GPIOA->BSSR.bit.BSSR1=0;










    }
}





