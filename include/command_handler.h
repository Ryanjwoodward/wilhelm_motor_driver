//?--------------------------------------------------------------------------------------------------------------------
//? AUTHOR      |   Ryan Woodward
//? PROJECT     |   Wilhelm
//? COMPANY     |   Rampart
//?--------------------------------------- -----------------------------------------------------------------------------
//? DESCRIPTION | "command_handler" is where custom drive sequences are defined
//?             | - 'test_sequence' is called during the initial startup of wilhelm to verify functionality
//?             | - ''
//?--------------------------------------------------------------------------------------------------------------------
#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <stdint.h>

//?--------------------------------------------------------------------------------------------------------------------
//?         MACROS, TYPEDEFS, & VARIABLES
//?--------------------------------------------------------------------------------------------------------------------
#define MAX_CMD_LENGTH      32

typedef enum
{
    CMD_NON,
    CMD_FWD,
    CMD_REV,
    CMD_LHT,
    CMD_RHT,
    CMD_STP,
    CMD_INV
} command_type_t;

typedef struct
{
    command_type_t type;
    int speed;
}command_t;

//?--------------------------------------------------------------------------------------------------------------------
//?         FUNCTION DEFINITION
//?--------------------------------------------------------------------------------------------------------------------
void cmd_handler_reset();
int handler_feed_char(uint8_t ch, command_t *out_cmd);
void execute_command(command_t *command);

#endif
