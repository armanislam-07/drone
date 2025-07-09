#ifndef PWM_H
#define PWM_H


typedef {
PWM_L9110_CW,
PWM_L9110_CCW,
PWM_L9110_STOP
}pwm_e;

void pwm_init(void);
void pwm_duty_cycle(pwm_e pwm, uint8_t percent);