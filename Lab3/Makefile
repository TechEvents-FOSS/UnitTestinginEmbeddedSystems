TARGET = Lab3
CC = arm-none-eabi-gcc

CFLAGS = -mcpu=cortex-m4 -mthumb \
         -O0 -g \
         -ffreestanding -fno-builtin\
         -Isrc -Iunity -Istm32f4 \
         -Wall -Wextra

LDFLAGS = -T stm32f4/linker.ld \
          -nostartfiles \
          -Wl,--gc-sections

SRC = \
 stm32f4/startup.c \
 stm32f4/uart.c \
 src/checksum.c \
 src/test_checksum.c \
 src/syscalls.c \
 unity/unity.c

all:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET).elf

clean:
	rm -f *.elf

run: all
	renode --disable-xwt renode/stm32.resc