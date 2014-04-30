
#include "rcopter.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

	motor_setup();
	printf("Calibrating Sub1...\n");
	motor_calibrate(MOTOR_PIN_SUB1);
	printf("Calibrating Sub2...\n");
	motor_calibrate(MOTOR_PIN_SUB2);
	printf("Calibrating Sub3...\n");
	motor_calibrate(MOTOR_PIN_SUB3);
	printf("Calibrating Main...\n");
	motor_calibrate(MOTOR_PIN_MAIN);
	
	printf("Ready!\n");
	
	controlloop();

	printf("Cleaning up and unitializing\n");
	motor_cleanup();

}


void controlloop()
{
	char buf[16];

	while(1){
		scanf("%s", buf); 

		if(strcmp(buf,  "quit") == 0){
			return;
		}
		else{
			float val = (float)atof(buf);
			printf("Setting throttle to %.2f\n", val);
			motor_throttle(MOTOR_PIN_SUB1, val);
			motor_throttle(MOTOR_PIN_SUB2, val);
			motor_throttle(MOTOR_PIN_SUB3, val);
			motor_throttle(MOTOR_PIN_MAIN, val);
		}

	}
}
