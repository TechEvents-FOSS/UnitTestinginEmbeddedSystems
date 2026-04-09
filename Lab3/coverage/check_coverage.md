# How to measure code coverage in renode

* Add these lines after **LoadELF** command in **stm32.resc** file:
```
    sysbus.cpu CreateExecutionTracing "tracer" @./coverage/trace.bin PC true
    sysbus.cpu EnableOpcodesCounting true
```

* Also add the below line before quit but after execution of test cases to get details of execution 
```
    sysbus.cpu GetAllOpcodesCounters
```

* Run renode execution tracer
```
    python3 /opt/renode/tools/execution_tracer/execution_tracer_reader.py \
		coverage ./coverage/trace.bin \
		--binary Lab3.elf \
		--sources ./src/checksum.c
```

* The above command will generate information of which lines ran and for how many times.
* Example output:
```
    TN:
    SF:./src/checksum.c
    DA:5,5
    DA:6,5
    DA:7,3
    DA:10,2
    DA:11,2
    DA:13,10
    DA:15,8
    DA:17,2
    DA:18,5
    end_of_record
```
* This is a Address cache which tells which lines ran, how manu times
```
    DA:5,2 means line 5 ran 2 times.
```

* To extract coverage, multiple methods can be tried.
* Save the above output to a coverage.info 
1. Run lcov to get % of coverage
    ```
        lcov --summary coverage/test.info 
    ```
2. Use awk command to extract % of coverage.
    ```
        cat coverage/test.info | awk -F',' '/DA:/ {found++; if($2>0) hit++} END {printf "Coverage: %.2f%% (%d/%d)\n", (hit/found)*100, hit, found}'
    ```

* Both of the above commands give % of coverage of code.