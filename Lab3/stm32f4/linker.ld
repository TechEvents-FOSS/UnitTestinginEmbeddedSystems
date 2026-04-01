ENTRY(Reset_Handler)

/* ===== Memory Regions ===== */

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1M
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Initial stack pointer (top of RAM) */
_estack = ORIGIN(RAM) + LENGTH(RAM);

/* ===== Sections ===== */

SECTIONS
{
    /* ==== Interrupt Vector Table ==== */

    .isr_vector :
    {
        KEEP(*(.isr_vector))
    } > FLASH


    /* ==== Code + Read-Only Data ==== */

    .text :
    {
        *(.text*)
        *(.rodata*)
        KEEP(*(.init))
        KEEP(*(.fini))
    } > FLASH


    /* ==== ARM Exception Tables (required by GCC) ==== */

    .ARM.extab :
    {
        *(.ARM.extab*)
    } > FLASH

    .ARM.exidx :
    {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } > FLASH


    /* Mark end of FLASH content */
    _etext = .;


    /* ==== Initialized Data (in RAM, loaded from FLASH) ==== */

    .data : AT (_etext)
    {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > RAM


    /* ==== Uninitialized Data ==== */

    .bss :
    {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > RAM


    /* ==== Heap / End of RAM data ==== */

    . = ALIGN(8);
    end = .;
    _end = .;


    /* Stack grows downward from _estack */
}