//?--------------------------------------------------------------------------------------------------------------------
//? AUTHOR      |   Ryan Woodward
//? PROJECT     |   Wilhelm
//? COMPANY     |   Rampart LLC
//? DATE        |   November 24, 2025
//?--------------------------------------------------------------------------------------------------------------------
#include "pico/stdlib.h"

//? Rampart Defined Files
#include "../include/motor_control.h"
#include "../include/util/uart_comm.h"
#include "../include/command_handler.h"

//?--------------------------------------------------------------------------------------------------------------------
//?     ENTRY POINT
//?--------------------------------------------------------------------------------------------------------------------
int main()
{
    init_motors();
    init_uart();

    while(1)
    {
        uart_loop();
        tight_loop_contents();
    }

    return 0;
}
