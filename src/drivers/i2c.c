
#include "i2c.h"
#include "io.h"
#include "registers.h"


void i2c_init(void){

/*






pb 8 scl
pn 9 sda


*/
RCC_APB1ENR |= RCC_APB1ENR_I2C1EN; //enabke the i2c1 clock 
RCC_APB2ENR |= RCC_APB2ENR_AFIOEN;
RCC_APB2ENR |= RCC_APB2ENR_IOPBEN;
setpin(GPIOB, 8 ,GPIO_AFOPENDRAIN, GPIO_OUTPUT_50MHZ);
setpin(GPIOB, 9 ,GPIO_AFOPENDRAIN, GPIO_OUTPUT_50MHZ);

I2C1->CR1 |= I2C_CR1_SWRST;
I2C1->CR1 &= I2C_CR1_SWRST;

I2C1->CR2 = 36;
I2C1->CCR = 180;        
I2C1->TRISE = 37;       

I2C1->CR1 |= I2C_CR1_PE;

}

void i2c_start(void) {
    I2C1->CR1 |= I2C_CR1_START;
    while(!(I2C1->SR1 & I2C_SR1_SB));
}

void i2c_stop(void) {
    I2C1->CR1 |= I2C_CR1_STOP;
}

void i2c_write(uint8_t data) {
    I2C1->DR = data;
    while(!(I2C1->SR1 & I2C_SR1_TXE));
}

uint8_t i2c_read_ack(void) {
    I2C1->CR1 |= I2C_CR1_ACK;
    while(!(I2C1->SR1 & I2C_SR1_RXNE));
    return I2C1->DR;
}

uint8_t i2c_read_nack(void) {
    I2C1->CR1 &= ~I2C_CR1_ACK;
    while(!(I2C1->SR1 & I2C_SR1_RXNE));
    return I2C1->DR;
}