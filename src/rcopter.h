#ifndef RCOPTER_H_
#define RCOPTER_H_


#include "pwm.h"


#define PULSE_INC_US PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT
#define SUBCYCLE_TIME_US SUBCYCLE_TIME_US_DEFAULT


#define MOTOR_PWM_MAX_THROTTLE (2000 / PULSE_INC_US) // 2ms
#define MOTOR_PWM_MIN_THROTTLE (1000 / PULSE_INC_US) // 1ms



#define MOTOR_PIN_SUB1 11
#define MOTOR_PIN_SUB2 9
#define MOTOR_PIN_SUB3 10
#define MOTOR_PIN_MAIN 22



void motor_setup();

void motor_cleanup();

void motor_calibrate(int m);
void motor_throttle(int m, float t);

#endif /* RCOPTER_H_ */
