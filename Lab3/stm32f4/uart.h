#ifndef UART_H
#define UART_H

#include <stdint.h>


/**
 * @brief Initialize UART peripheral
 *
 * Configure GPIO, baud rate, and enable TX.
 * Implementation may vary by board.
 */
void uart_init(void);

/**
 * @brief Send one character
 */
void uart_putc(char c);

/**
 * @brief Send null-terminated string
 */
void uart_print(const char *s);

/**
 * @brief Override putchar to use our UART implementation
 */
int putchar(int c);


#endif /* UART_H */