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

.PHONY: all clean run coverage

all:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET).elf

clean:
	rm -f *.elf coverage/trace.*

run: clean all
	touch coverage/trace.bin
	renode --disable-xwt renode/stm32.resc

coverage: run
	@python3 /opt/renode/tools/execution_tracer/execution_tracer_reader.py \
		coverage ./coverage/trace.bin \
		--binary Lab3.elf \
		--sources ./src/checksum.c | \
		awk -F',' '/DA:/ {found++; if($$2>0) hit++} END \
		{printf "\nTotal Coverage: %.2f%% (%d/%d lines hit)\n", (hit/found)*100, hit, found}'
