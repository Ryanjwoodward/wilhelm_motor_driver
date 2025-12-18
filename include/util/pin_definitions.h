//?--------------------------------------------------------------------------------------------------------------------
//? AUTHOR      |   Ryan Woodward
//? PROJECT     |   Wilhelm
//? COMPANY     |   Rampart
//?--------------------------------------------------------------------------------------------------------------------
#ifndef PIN_DEFINITIONS_H
#define PIN_DEFINITIONS_H

#include "pico/types.h"
#include "ring_buffer.h"

// -----------------------------------------------------------------------------
// LED
// -----------------------------------------------------------------------------
extern const uint LED_BUILT_IN;

// -----------------------------------------------------------------------------
// MOTOR 1
// -----------------------------------------------------------------------------
extern const uint MOTOR1_ENABLE;
extern const uint MOTOR1_DIR_A;
extern const uint MOTOR1_DIR_B;
extern uint MOTOR1_SLICE_NUM;

// -----------------------------------------------------------------------------
// MOTOR 2
// -----------------------------------------------------------------------------
extern const uint MOTOR2_ENABLE;
extern const uint MOTOR2_DIR_A;
extern const uint MOTOR2_DIR_B;
extern uint MOTOR2_SLICE_NUM;

// -----------------------------------------------------------------------------
// UART
// -----------------------------------------------------------------------------
#define UART_ID         uart0
#define UART_BAUD_RATE  115200

extern const uint UART_TX_PIN;
extern const uint UART_RX_PIN;

extern int UART_IRQ;

// Global shared ring buffer
extern ring_buffer_t uart_buffer;

#endif // PIN_DEFINITIONS_H
