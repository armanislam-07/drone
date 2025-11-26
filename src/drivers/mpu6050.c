#include "io.h"
#include "registers.h"
#include "i2c.h"

void mpu6050_init(void) {
    i2c_start();
    i2c_write(MPU6050_ADDR | 0); // Write
    i2c_write(PWR_MGMT_1);
    i2c_write(0x00); // Wake up
    i2c_stop();
}

void mpu6050_read_accel(int16_t *ax, int16_t *ay, int16_t *az) {
    i2c_start();
    i2c_write(MPU6050_ADDR);   // write mode
    i2c_write(ACCEL_XOUT_H);   // starting register

    i2c_start();
    i2c_write(MPU6050_ADDR | 1); // read mode

    uint8_t axh = i2c_read_ack();
    uint8_t axl = i2c_read_ack();
    uint8_t ayh = i2c_read_ack();
    uint8_t ayl = i2c_read_ack();
    uint8_t azh = i2c_read_ack();
    uint8_t azl = i2c_read_nack();

    i2c_stop();

    *ax = (axh << 8) | axl;
    *ay = (ayh << 8) | ayl;
    *az = (azh << 8) | azl;
}