

#include <stdint.h>
#include "drivers/registers.h"
#include "drivers/pwm.h"
#include "drivers/io.h"
#include "drivers/i2c.h"
#include "drivers/mpu6050.h"


int main(void)
{
    
    

    


    ioinit();
    pwm_motorinit(29);
    i2c_init();
    mpu6050_init();





  
    while(1){
            

    









    }
}





