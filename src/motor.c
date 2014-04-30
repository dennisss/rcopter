#include "rcopter.h"

#include <unistd.h>

#define DMA_CHANNEL 0

void motor_setup()
{
	setup(PULSE_INC_US, DELAY_VIA_PWM);
	init_channel(DMA_CHANNEL, SUBCYCLE_TIME_US);
}

void motor_cleanup()
{
	shutdown();
}

void motor_calibrate(int m)
{
	motor_throttle(m, 1.0);
	sleep(2);
	motor_throttle(m, 0.0);
	sleep(2);
}

void motor_throttle(int m, float t)
{
	if(t > 1.0){
		t = 1.0;
	}
	else if(t < 0.0){
		t = 0.0;
	} 

	int width = (MOTOR_PWM_MAX_THROTTLE - MOTOR_PWM_MIN_THROTTLE)*t + MOTOR_PWM_MIN_THROTTLE;

	clear_channel_gpio(DMA_CHANNEL, m);
	add_channel_pulse(DMA_CHANNEL, m, 0, width);
}
