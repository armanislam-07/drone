



#include "pwm.h"
#include "registers.h"

//pwm -> duty cycle , timer clock , pwm mode , pwm period , 

void pwm_motorinit( uint8_t dutycyc_percent){
    TIM2->CCR1 = dutycyc_percent; //duty cycle to 0
    TIM2->PSC = 72-1; //timer clock in MHz 72MHz
    TIM2->ARR = 1000 - 1 ;  //PWM Period 1Mhz
    TIM2->CCMR1_Output.bit.OC1M = 6; // PWM Mode 1
    TIM2->CCMR1_Output.bit.OC1PE = 1; // Output compare preload enable
    TIM2->CCER.bit.CC1E= 1; // Capture/Compare 1 Output Enable
    TIM2->CR1.bit.APRE=1; // auto preload enable
    TIM2->EGR.bit.UG=1; //update generation
    TIM2->CR1.bit.CEN=1; //counter enable


    /*
    PSC is timer clock in MHZ
    ARR is PWM Period

    fPWM = (fTIMER)/ (PSC +1 ) * (ARR+1)
    
    
    
    
    for 20KHZ PWM and 72 MHz | ARR = 49

    
        CCR
    0%	0
    25%	12
    50%	25
    75%	37
    100% 49
    */


    TIM2->PSC = 72-1;
    TIM2->ARR = 49 ;

    TIM2->CCMR1_Output.reg &= ~0xFF;
    TIM2->CCMR1_Output.reg |= (6 << 4) | (1 << 3);
    TIM2->CCER.reg |= (1<<0);
    TIM2->CCR1 = 25;
    TIM2->CR1.reg |= 1;


    TIM1->PSC = 72-1;
    TIM1->ARR = 49 ;

    TIM1->CCMR2_Output &= ~0xFF;
    TIM1->CCMR2_Output|= (6 << 4) | (1 << 3);
    TIM1->CCER.reg |= (1<<8);
    TIM1->CCR3 =25;
    TIM1_BDTR |= (1 << 15);
    TIM1->CR1.reg |= 1;



    TIM3->PSC = 72-1;
    TIM3->ARR = 49 ;

    TIM3->CCMR1_Output.reg &= ~0xFF;
    TIM3->CCMR1_Output.reg |= (6 << 4) | (1 << 3);

    TIM3->CCMR1_Output.reg |= (6<<12) | (1<<11);
    TIM3->CCER.reg |= (1<<0) | (1<<4);
    TIM3->CCR1 = 25;
    TIM3->CCR2 =25 ;
    TIM3->CR1.reg |= 1;


}
