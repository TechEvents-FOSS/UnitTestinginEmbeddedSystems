#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H

/* Redirect Unity output to UART */

#define UNITY_OUTPUT_CHAR(a) uart_putc(a)
#define UNITY_OUTPUT_FLUSH()
#define UNITY_PRINT_EOL() uart_print("\r\n")

#endif /* UNITY_CONFIG_H */