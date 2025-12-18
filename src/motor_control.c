//?--------------------------------------------------------------------------------------------------------------------
//? AUTHOR      |   Ryan Woodward
//? PROJECT     |   Wilhelm
//? COMPANY     |   Rampart
//?--------------------------------------------------------------------------------------------------------------------
//? DESCRIPTION | "motor_control.c" defines the implementation for the general abstraction layer of wilhelm tank
//?             |
//?--------------------------------------------------------------------------------------------------------------------
#include "pico/stdlib.h"
#include "hardware/pwm.h"

//? Rampart Defined Files
#include "../include/util/pin_definitions.h"

//?--------------------------------------------------------------------------------------------------------------------
//?     CONTSTANTS, MACROS, and GLOBALS
//?--------------------------------------------------------------------------------------------------------------------
int init_motors()
{
    stdio_init_all();

    //? MOTOR 1
    gpio_init(MOTOR1_DIR_A);
    gpio_init(MOTOR1_DIR_B);

    gpio_set_function(MOTOR1_DIR_A, GPIO_FUNC_SIO);
    gpio_set_function(MOTOR1_DIR_B, GPIO_FUNC_SIO);

    gpio_set_dir(MOTOR1_DIR_A, GPIO_OUT);
    gpio_set_dir(MOTOR1_DIR_B, GPIO_OUT);

    //? MOTOR 2
    gpio_init(MOTOR2_DIR_A);
    gpio_init(MOTOR2_DIR_B);

    gpio_set_function(MOTOR2_DIR_A, GPIO_FUNC_SIO);
    gpio_set_function(MOTOR2_DIR_B, GPIO_FUNC_SIO);

    gpio_set_dir(MOTOR2_DIR_A, GPIO_OUT);
    gpio_set_dir(MOTOR2_DIR_B, GPIO_OUT);

    //? Set GPIOs on ENABLE pins to PWM
    gpio_set_function(MOTOR1_ENABLE, GPIO_FUNC_PWM);
    gpio_set_function(MOTOR2_ENABLE, GPIO_FUNC_PWM);

    MOTOR1_SLICE_NUM = pwm_gpio_to_slice_num(MOTOR1_ENABLE);
    MOTOR2_SLICE_NUM = pwm_gpio_to_slice_num(MOTOR2_ENABLE);

    pwm_set_wrap(MOTOR1_SLICE_NUM, 100);
    pwm_set_wrap(MOTOR2_SLICE_NUM, 100);

    pwm_set_enabled(MOTOR1_SLICE_NUM, true);
    pwm_set_enabled(MOTOR2_SLICE_NUM, true);

    return 0;
}


int fwd_control(int speed)
{
    gpio_put(MOTOR1_DIR_A, 1);
    gpio_put(MOTOR1_DIR_B, 0);
    pwm_set_gpio_level(MOTOR1_ENABLE, speed);

    gpio_put(MOTOR2_DIR_A, 1);
    gpio_put(MOTOR2_DIR_B, 0);
    pwm_set_gpio_level(MOTOR2_ENABLE, speed);

    return 0;
}

int rev_control(int speed)
{
    gpio_put(MOTOR1_DIR_A, 0);
    gpio_put(MOTOR1_DIR_B, 1);
    pwm_set_gpio_level(MOTOR1_ENABLE, speed);

    gpio_put(MOTOR2_DIR_A, 0);
    gpio_put(MOTOR2_DIR_B, 1);
    pwm_set_gpio_level(MOTOR2_ENABLE, speed);

    return 0;
}

int lht_control()
{
    gpio_put(MOTOR1_DIR_A, 0);
    gpio_put(MOTOR1_DIR_B, 1);
    pwm_set_gpio_level(MOTOR1_ENABLE, 75);

    gpio_put(MOTOR2_DIR_A, 1);
    gpio_put(MOTOR2_DIR_B, 0);
    pwm_set_gpio_level(MOTOR2_ENABLE, 75);

    return 0;
}

int rht_control()
{
    gpio_put(MOTOR1_DIR_A, 1);
    gpio_put(MOTOR1_DIR_B, 0);
    pwm_set_gpio_level(MOTOR1_ENABLE, 75);

    gpio_put(MOTOR2_DIR_A, 0);
    gpio_put(MOTOR2_DIR_B, 1);
    pwm_set_gpio_level(MOTOR2_ENABLE, 75);

    return 0;
}

int stp_control()
{
    pwm_set_gpio_level(MOTOR1_ENABLE, 0);
    pwm_set_gpio_level(MOTOR2_ENABLE, 0);
    return 0;
}
