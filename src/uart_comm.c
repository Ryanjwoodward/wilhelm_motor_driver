//?--------------------------------------------------------------------------------------------------------------------
//? AUTHOR      |   Ryan Woodward
//? PROJECT     |   Wilhelm
//? COMPANY     |   Rampart
//?--------------------------------------------------------------------------------------------------------------------
//? DESCRIPTION | "uart_comm.c"
//?             |
//?--------------------------------------------------------------------------------------------------------------------
#include "hardware/uart.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"

//? Rampart Defined Files
#include "../include/util/ring_buffer.h"
#include "../include/util/pin_definitions.h"
#include "../include/command_handler.h"

//?--------------------------------------------------------------------------------------------------------------------
//?         FUNCTION DEFINITIONS
//?--------------------------------------------------------------------------------------------------------------------
void on_uart_rx()
{
    while(uart_is_readable(UART_ID))
    {
        uint8_t chr = uart_getc(UART_ID);
        ring_buffer_push(&uart_buffer, chr);
    }
}

int init_uart()
{
    ring_buffer_init(&uart_buffer);
    uart_init(UART_ID, UART_BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    int UART_IRQ = (UART_ID == uart0) ? UART0_IRQ : UART1_IRQ;
    irq_set_exclusive_handler(UART_IRQ, on_uart_rx);
    irq_set_enabled(UART_IRQ, true);
    uart_set_irq_enables(UART_ID, true, false);
}


void uart_loop(){
    while(ring_buffer_has_data(&uart_buffer))
    {
        uint8_t chr;
        ring_buffer_pop(&uart_buffer, &chr);

        command_t cmd;
        if(handler_feed_char(chr, &cmd))
        {
            execute_command(&cmd);
        }
    }
}
