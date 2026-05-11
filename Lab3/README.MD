# Running STM32 Binary on Renode
* This Lab example uses STM32F4 Discovery kit based example.
* You can run any firmware built for STM32F407 MCU.
* Once you build your project, update the below instruction under renode/stm32.resc to load new binary file:
```
    sysbus LoadELF @Lab3.elf
```

# Build and run
* You can use Makefile in this folder to build and run
* To Build:
```sh
make all
```

* To run Renode simulator:
```sh
make run
```

* To see Renode GUI terminal for logs and output: 
```
renode renode/stm32.resc
```

---

# STM32 Build & Coverage Configuration Report
This document outlines the flags and tools used to compile, simulate, and audit the `Lab3.elf` project.

## 1. Compiler Flags (CFLAGS)
The `CFLAGS` define how the C source code is translated into machine instructions for the target microcontroller.

| Flag | Category | Description |
| :--- | :--- | :--- |
| `-mcpu=cortex-m4` | **Architecture** | Target the ARM Cortex-M4 processor and its specific instruction set. |
| `-mthumb` | **Architecture** | Use the Thumb-2 instruction set (required for Cortex-M). |
| `-O0` | **Optimization** | Disable optimizations. Ensures assembly matches C source 1-to-1 for accurate debugging and coverage. |
| `-g` | **Debugging** | Include debug symbols for mapping memory addresses back to source code lines. |
| `-ffreestanding` | **Environment** | Standard libraries may not be available; assumes no OS environment. |
| `-fno-builtin` | **Environment** | Prevents compiler from replacing your functions with internal optimized versions. |
| `-I<dir>` | **Search Path** | Adds `./src`, `./unity`, and `./stm32f4` to the header include search path. |
| `-Wall -Wextra` | **Quality** | Enables almost all compiler warnings to catch potential bugs early. |

---

## 2. Linker Flags (LDFLAGS)
The `LDFLAGS` define how object files are joined and where they are placed in the chip's memory.

| Flag | Description |
| :--- | :--- |
| `-T stm32f4/linker.ld` | Uses the Linker Script to define the memory map (Flash vs. RAM boundaries). |
| `-nostartfiles` | Excludes standard C startup files; uses the project's custom `startup.c` instead. |
| `-Wl,--gc-sections` | Tells the linker to "Garbage Collect" (remove) unused functions to save Flash space. |

---

## 3. Automated Coverage Reporting
To view coverage results both in the terminal and on the GitHub Actions summary page, the following `Makefile` target is used.

### Makefile Target
```makefile
coverage:
	@# Run the Renode tracer reader and pipe output to AWK
	@python3 /opt/renode/tools/execution_tracer/execution_tracer_reader.py \
		coverage ./coverage/trace.bin \
		--binary Lab3.elf \
		--sources ./src/checksum.c | \
		awk -F',' '/DA:/ {found++; if($$2>0) hit++} END { \
			percent = (found > 0) ? (hit/found)*100 : 0; \
			msg = sprintf("\nTotal Coverage: %.2f%% (%d/%d lines hit)\n", percent, hit, found); \
			print msg; \
			if (ENVIRON["GITHUB_STEP_SUMMARY"] != "") { \
				printf "### 📊 Coverage Report\n- **Status:** %s\n- **Percentage:** %.2f%%\n- **Details:** %d out of %d lines executed\n", \
				(percent == 100 ? "✅ Pass" : "⚠️ Partial"), percent, hit, found >> ENVIRON["GITHUB_STEP_SUMMARY"]; \
			} \
		}'