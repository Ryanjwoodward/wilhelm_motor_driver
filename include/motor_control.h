//?--------------------------------------------------------------------------------------------------------------------
//? AUTHOR      |   Ryan Woodward
//? PROJECT     |   Wilhelm
//? COMPANY     |   Rampart
//?--------------------------------------------------------------------------------------------------------------------
//? DESCRIPTION | "motor_control" defines general API methods for typical movement of a tank
//?             | fwd is forward control
//?             | rev is reverse control
//?             | lht is left hand turn
//?             | rht is right hand turn
//?             | stp is stop
//?             | "motor_control.h" is also used to setup the GPIO pins for the motors
//?--------------------------------------------------------------------------------------------------------------------
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

//?--------------------------------------------------------------------------------------------------------------------
//?         FUNCTION DECLARATIONS
//?--------------------------------------------------------------------------------------------------------------------
int init_motors();
int fwd_control(int speed);
int rev_control(int speed);
int lht_control();
int rht_control();
int stp_control();

#endif
