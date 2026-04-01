#include <stdint.h>

/*
 * RCC
 */
#define RCC_BASE 0x40023800UL
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define RCC_APB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x40))

/*
 * GPIOA
*/

#define GPIOA_BASE 0x40020000UL
#define GPIOA_MODER   (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_OSPEEDR (*(volatile uint32_t *)(GPIOA_BASE + 0x08))
#define GPIOA_AFRL    (*(volatile uint32_t *)(GPIOA_BASE + 0x20))

/*
 * USART2
 */
#define USART2_BASE 0x40004400UL
#define USART2_SR   (*(volatile uint32_t *)(USART2_BASE + 0x00))
#define USART2_DR   (*(volatile uint32_t *)(USART2_BASE + 0x04))
#define USART2_BRR  (*(volatile uint32_t *)(USART2_BASE + 0x08))
#define USART2_CR1  (*(volatile uint32_t *)(USART2_BASE + 0x0C))


/* 
 * UART functions
*/
void uart_init(void)
{
    /* Enable clocks */
    RCC_AHB1ENR |= (1 << 0);   // GPIOA
    RCC_APB1ENR |= (1 << 17);  // USART2

    /* PA2 → Alternate Function */
    GPIOA_MODER &= ~(3U << (2 * 2));
    GPIOA_MODER |=  (2U << (2 * 2));

    /* High speed */
    GPIOA_OSPEEDR |= (3U << (2 * 2));

    /* AF7 (USART2) */
    GPIOA_AFRL &= ~(0xF << (4 * 2));
    GPIOA_AFRL |=  (7   << (4 * 2));

    /* Baud = 115200 @ 16 MHz */
    USART2_BRR = 0x8B;

    /* Enable TX + USART */
    USART2_CR1 = (1 << 3) | (1 << 13);
}

/* 
 * Send a single character over UART
*/
void uart_putc(char c)
{
    while (!(USART2_SR & (1 << 7))); // TXE
    USART2_DR = c;
}

/* 
 * Send a null-terminated string over UART
*/
void uart_print(const char *s)
{
    while (*s)
    {
        if (*s == '\n') uart_putc('\r');
        uart_putc(*s++);
    }
}

/* 
 * Override putchar to use our UART implementation
*/
int putchar(int c)
{
    uart_putc((char)c);
    return c;
}
