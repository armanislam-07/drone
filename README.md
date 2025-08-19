# drone

Over summer break and currently I have decieded to work on a project to build a drone( or in brutish terms "flying machine" ) This repository tracks the code of the flying machine as I write all the code from scratch ( including drivers ). So, no arduino. The only things from this project I have not made and am using are the "STM32F103RBTX_FLASH.ld" to flash the code onto the MPU and the startup file "startup_stm32f103rbtx.s" 

In short, this is a project to build a drone/quadcopter from scratch/bare-metal. 

Some limitations of this project currently:
  - Project is NOT intended to be able to control it by RC (although may in the future ) it is to get to know baremetal embedded . It IS intended to have the drone fly (for around 10 seconds then killing the motors) 


Dimensions of the drone: ___x__ __x__ ___x_ __x_ 
Brushed DC motors 
LP9110s 
F103RB microcontroler
DJI Tello Propllers  



Things to be implemented in the future
  1. Asserts and Cases ( safety )
  2. RC CONTROL
  
