
#include <stdint.h>
//gpioa peripheral base 0x4001 0800
//apb2enr register for ioapen 0x40000000UL +

//output mode alternative function push pull value is 10



#define RCC_APB2ENR *((uint32_t * )0x40021018)
#define RCC_APB2ENR_IOPAEN 1<<2




#define GPIOA ((GPIO_T *)0x40010800)



void delay(uint32_t time) {
	uint32_t count =0;
		while ( count< time){
			count++;
		}

    }

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
	//change crl

	RCC_APB2ENR |= RCC_APB2ENR_IOPAEN; //turn on the peripheral clock for gpioa

	//set cnf to alternative push pull 
	//set mode to output mode max speed 2MHZ pg 171 in documetnion idk about circuits so go back and change if neccessary for more power
	GPIOA->CRL.bit.CNF0= 0;
	GPIOA->CRL.bit.MODE0 = 2;
	GPIOA->CRL.bit.CNF1= 0;
	GPIOA->CRL.bit.MODE1= 2;



	for(;;){
		//set bssr to pin 0 and pin 1 
		GPIOA->ODR.bit.ODR0=1;
		GPIOA->ODR.bit.ODR1=0;

		//delay (1000);
		//GPIOA->ODR.bit.ODR0=0;
			//	GPIOA->ODR.bit.ODR1=0;

	}
}
