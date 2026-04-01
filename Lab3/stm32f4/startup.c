#include <stdint.h>

/* ===== Linker Symbols ===== */
extern uint32_t _estack;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

/*
 * Reset Handler
 */
void Reset_Handler(void)
{
    uint32_t *src = &_etext;
    uint32_t *dst = &_sdata;

    /* Copy .data from FLASH to RAM */
    while (dst < &_edata)
        *dst++ = *src++;

    /* Zero .bss */
    for (dst = &_sbss; dst < &_ebss; )
        *dst++ = 0;

    main();

    while (1);
}

/*
 * Default Handler
 */
void Default_Handler(void)
{
    while (1);
}

/* Weak aliases for interrupts */
void NMI_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));

/*
 * Interrupt Vector Table
 */
__attribute__((section(".isr_vector")))
const void *vector_table[] =
{
    &_estack,           // Initial stack pointer
    Reset_Handler,      // Reset
    NMI_Handler,        // NMI Handler
    HardFault_Handler,  // Hard Fault Handler
    MemManage_Handler,  // Memory Management Fault Handler
    BusFault_Handler,   // Bus Fault Handler
    UsageFault_Handler  // Usage Fault Handler
};