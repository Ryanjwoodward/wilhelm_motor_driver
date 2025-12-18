//?--------------------------------------------------------------------------------------------------------------------
//? AUTHOR      |   Ryan Woodward
//? PROJECT     |   Wilhelm
//? COMPANY     |   Rampart
//?--------------------------------------- -----------------------------------------------------------------------------
//? DESCRIPTION | "ring_buffer.h"
//?             |
//?--------------------------------------------------------------------------------------------------------------------
#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

//?--------------------------------------------------------------------------------------------------------------------
//?         MACROS, TYPEDEFS, & VARIABLES
//?--------------------------------------------------------------------------------------------------------------------
#define RING_BUFFER_SIZE    256

typedef struct
{
    volatile uint8_t data[RING_BUFFER_SIZE];
    volatile uint8_t head;
    volatile uint8_t tail;
} ring_buffer_t;

//?--------------------------------------------------------------------------------------------------------------------
//?         FUNCTION DECLARATION
//?--------------------------------------------------------------------------------------------------------------------
void ring_buffer_init(ring_buffer_t *buffer);
int ring_buffer_push(ring_buffer_t *buffer, uint8_t byte);
int ring_buffer_pop(ring_buffer_t *buffer, uint8_t *byte);
int ring_buffer_has_data(ring_buffer_t *buffer);

#endif
