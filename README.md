R-Copter
======================

Overview
--------
Note: This code is still in its initial stages of development and few features are implemented yet.
A C based driver application for controlling a Y-quadcopter (see [this blog](http://du2014-grp940-06.blogspot.com/) for more details on the hardware design). It is currently designed to run on the Raspberry Pi. The target functionality of this code is as follows:

* Send variable throttle PWM signals to 4 motor ESCs 
* Read orientation information from a 9DOF IMU
* Linear translation calculations based on orientation and acceleration data
* PID controller for achieving target rotations and translations
* Path following
* UDP server for sending/receiving data/commands from arbitrary controllers

Running/Building
----------------
Compile using "make"
Run from "bin/rcopter" on the Raspberry Pi

