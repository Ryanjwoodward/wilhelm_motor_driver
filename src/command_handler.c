//?--------------------------------------------------------------------------------------------------------------------
//? AUTHOR      |   Ryan Woodward
//? PROJECT     |   Wilhelm
//? COMPANY     |   Rampart LLC
//? DATE        |   November 24, 2025
//?--------------------------------------------------------------------------------------------------------------------
//? DESCRIPTION | "command_handler.c"
//?             |
//?--------------------------------------------------------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>

//? Rampart Defined Files
#include "../include/command_handler.h"
#include "../include/motor_control.h"

//?--------------------------------------------------------------------------------------------------------------------
//?         MACROS, TYPEDEFS, & VARIABLES
//?--------------------------------------------------------------------------------------------------------------------
static char buffer[MAX_CMD_LENGTH];
static int idx = 0;

//?--------------------------------------------------------------------------------------------------------------------
//?         FUNCTION DEFINITIONS
//?--------------------------------------------------------------------------------------------------------------------
void cmd_handler_reset()
{
    idx = 0;
    memset(buffer, 0, MAX_CMD_LENGTH);
}

// Return: 0 = no command yet, 1 = command ready
int handler_feed_char(uint8_t c, command_t *out_cmd)
{

    if (c == '\r') return 0;   // ignore CR

    if (c == '\n') {
        buffer[idx] = '\0';

        // Parse
        if (strncmp(buffer, "STOP", 4) == 0) {
            out_cmd->type = CMD_STP;
            out_cmd->speed = 0;
        }
        else if (buffer[0] == 'F') {
            out_cmd->type = CMD_FWD;
            out_cmd->speed = atoi(&buffer[1]);
        }
        else if (buffer[0] == 'B') {
            out_cmd->type = CMD_REV;
            out_cmd->speed = atoi(&buffer[1]);
        }
        else if (buffer[0] == 'L') {
            out_cmd->type = CMD_LHT;
            out_cmd->speed = atoi(&buffer[1]);
        }
        else if (buffer[0] == 'R') {
            out_cmd->type = CMD_RHT;
            out_cmd->speed = atoi(&buffer[1]);
        }
        else {
            out_cmd->type = CMD_INV;
            out_cmd->speed = 0;
        }

        cmd_handler_reset();
        return 1;
    }

    if (idx < MAX_CMD_LENGTH - 1) {
        buffer[idx++] = c;
    }

    return 0;
}

void execute_command(command_t *command)
{
    int speed = command->speed;

    switch(command->type)
    {
        case CMD_FWD:
            fwd_control(speed);
            break;

        case CMD_REV:
            rev_control(speed);
        break;

        case CMD_LHT:
            lht_control();
        break;

        case CMD_RHT:
            rht_control();
            break;

        case CMD_STP:
            stp_control();
            break;

        default:
            // Buzz a buzzer
    }
}
