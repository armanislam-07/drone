#ifndef I2C_H
#define I2C_H

#include <stdint.h>
#include "registers.h"




void i2c_init(void);

void i2c_start( void) ;

void i2c_stop ( void ) ;

void i2c_write ( uint8_t data);

void i2c_read_acknowledge(void) ;

void i2c_read_nacknowledge(void);

void i2c_read_registers(void);

#endif