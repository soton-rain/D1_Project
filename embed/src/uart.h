#ifndef UART_H
#define UART_H

#include "ring_buff.h"

#define UART_BAUD 9600
#define UART_PRESCALE (F_CPU / (UART_BAUD * 16L) - 1)
#define UART_BUFFER_SIZE 16

typedef enum { NIL, SET, GET, CONN, TEST } command_t;
typedef enum { UNKNOWN_VAR, SPT, VOLT, PWM } variable_command_t;
uint8_t uart_command_char[5];
uint8_t uart_variable_char[4];

volatile command_t uart_command;

void init_uart0();

int uart_get(uint8_t *data);
int uart_put(uint8_t *data);
int uart_put_array(uint8_t *data, int count);
void uart_put_ch(char ch);

#endif