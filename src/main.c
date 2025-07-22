

#include <stdint.h>
//gpioa peripheral base 0x4001 0800
//apb2enr register for ioapen 0x40000000UL +


//output mode alternative function push pull value is 10






#define RCC_APB2ENR *((uint32_t * )0x40021018)
#define RCC_APB2ENR_IOPAEN 1<<2




#define TIM2 ((TIM_T*) 0x40000000)


#define RCC_APB1ENR *((uint32_t * ) 0x4002101c)
#define RCC_APB1ENR_TIME2EN 1<<0




#define GPIOA ((GPIO_T *)0x40010800)






void delay(uint32_t time) {
	 volatile uint32_t count;
	    for (uint32_t i = 0; i < time; i++) {
	        count = 18000000; // Tune this as needed
	        while (count--) {
	            __asm__("nop"); // no operation (prevent optimization)
	        }
	    }

    }


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
   uint32_t CRH;
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





