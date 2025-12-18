//?--------------------------------------------------------------------------------------------------------------------
//? AUTHOR      |   Ryan Woodward
//? PROJECT     |   Wilhelm
//? COMPANY     |   Rampart
//?--------------------------------------------------------------------------------------------------------------------
//? DESCRIPTION | "ring_buffer"
//?             |
//?--------------------------------------------------------------------------------------------------------------------

//? Rampart Defined Files
#include "../include/util/ring_buffer.h"

//?--------------------------------------------------------------------------------------------------------------------
//?         FUNCTION DECLARATION
//?--------------------------------------------------------------------------------------------------------------------
void ring_buffer_init(ring_buffer_t *buffer)
{
    buffer->head    = 0;
    buffer->tail    = 0;
}

int ring_buffer_push(ring_buffer_t *buffer, uint8_t byte)
{
    uint16_t next = (buffer->head+1) % RING_BUFFER_SIZE;

    if (next == buffer->tail)
    {
        return 1;
    }

    buffer->data[buffer->head]  = byte;
    buffer->head                = next;
    return 0;
}

int ring_buffer_pop(ring_buffer_t *buffer, uint8_t *byte)
{
    if(buffer->head == buffer->tail)
    {
        return 1;
    }

    *byte = buffer->data[buffer->tail];
    buffer->tail = (buffer->tail + 1) % RING_BUFFER_SIZE;
    return 0;
}

int ring_buffer_has_data(ring_buffer_t *buffer)
{
    return buffer->head != buffer->tail;
}
