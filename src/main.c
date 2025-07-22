

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
    //remember startup code ( system clock initalize )(write it in c )


        //set the pin to output input ( gpioA pin 0 pin 1 )
//apb2enr to ioapen turn on (clock )


    RCC_APB2ENR |= RCC_APB2ENR_IOPAEN; //turn on the peripheral clock for gpioa
    RCC_APB1ENR |= RCC_APB1ENR_TIME2EN; //turns on timer2 periperhal
                                        //change the cr1 register
                                        //output compare mode to pwm
                                        //enable the counter
                                        //set output to the compare mode 1
                                        //setup the frequency for the timer + resolution


    //set cnf to alternative push pull (af1 and make sure its set to that to output it )
    //set mode to output mode max speed 2MHZ pg 171 in documetnion idk about circuits so go back and change if neccessary for more power
    GPIOA->CRL.bit.CNF0= 2;
    GPIOA->CRL.bit.MODE0 = 3;

   // GPIOA->CRL.bit.CNF1 = 0;
    //GPIOA->CRL.bit.MODE1 = 3;
  //  GPIOA->ODR.bit.ODR1 = 0;


    //things to find out | why does changing the arr to 653535 do somethig ( calcluate i think)
    //why does settings PA1 Low work


    //GPIOA->CRL.bit.CNF1= 2;
    //GPIOA->CRL.bit.MODE1= 3;
        //changes are i put gpioa to alternative function push pull find out how the others work toommroowo
    // pins 0 and 1 are going to use tim2ch1 and time2ch2
//when doing pwm you are going to select alterant function on
    TIM2->CCR1 = 0;
    TIM2->PSC = 72-1;
    TIM2->ARR = 1000 - 1 ;
    TIM2->CCMR1_Output.bit.OC1M = 6;
    TIM2->CCMR1_Output.bit.OC1PE = 1;
    TIM2->CCER.bit.CC1E= 1;
    TIM2->CR1.bit.APRE=1;
    TIM2->EGR.bit.UG=1;
    TIM2->CR1.bit.CEN=1;



    for(;;){


        //lets connect pin 0 to pwm



    	TIM2->CCR1 = 0; //pwm
    	TIM2->EGR.bit.UG = 1;//updates the regsiters
    	TIM2->CCR1 = 300; //pwm
    	TIM2->EGR.bit.UG = 1;



        //GPIOA->BSSR.bit.BSSR0=1; // apparently bssr is safer so
        //GPIOA->BSSR.bit.BSSR1=0;










    }
}





