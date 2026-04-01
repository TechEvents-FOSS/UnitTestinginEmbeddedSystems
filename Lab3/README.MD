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