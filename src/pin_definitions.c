#include "../include/util/pin_definitions.h"

// -----------------------------------------------------------------------------
//      LED
// -----------------------------------------------------------------------------
const uint LED_BUILT_IN = 25;

// -----------------------------------------------------------------------------
//      MOTORS
// -----------------------------------------------------------------------------
const uint MOTOR1_ENABLE = 13;
const uint MOTOR1_DIR_A  = 11;
const uint MOTOR1_DIR_B  = 12;
uint MOTOR1_SLICE_NUM    = 0;

const uint MOTOR2_ENABLE = 9;
const uint MOTOR2_DIR_A  = 6;
const uint MOTOR2_DIR_B  = 7;
uint MOTOR2_SLICE_NUM    = 0;

// -----------------------------------------------------------------------------
//      UART
// -----------------------------------------------------------------------------
const uint UART_TX_PIN = 0;
const uint UART_RX_PIN = 1;     // Most Pico boards: TX=0, RX=1

int UART_IRQ = 0;

ring_buffer_t uart_buffer;
