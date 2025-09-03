
#include "i2c.h"
#include "io.h"
#include "registers.h"


void i2c_init(void){

/*






pb 8 scl
pn 9 sda


*/
RCC_APB1ENR |= RCC_APB1ENR_I2C1EN; //enabke the i2c1 clock 

setpin(GPIOB, 8 ,GPIO_AFOPENDRAIN, GPIO_OUTPUT_50MHZ);

setpin(GPIOB, 9 ,GPIO_AFOPENDRAIN, GPIO_OUTPUT_50MHZ);



 

}