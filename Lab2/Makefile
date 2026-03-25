PROJECT = Lab1

SRC = checksum.c test_checksum.c
TEST_SRC = unity.c
INCLUDE += -I.

CC = gcc
CFLAGS += -Wall -Wextra -Werror
COVERAGE_FLAGS += -fprofile-arcs -ftest-coverage


.PHONY: all clean

all: test_checksum

test_checksum: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(PROJECT) $^

clean:
	rm -f $(PROJECT) *.gcda *.gcno *.gcov coverage_checksum.txt *.out

run: test_checksum
	./$(PROJECT)

coverage: $(SRC) $(TEST_SRC)
	$(CC) $(COVERAGE_FLAGS) $(CFLAGS) $(INCLUDE) -o $(PROJECT) $^
	./$(PROJECT)
	if [ -f Lab1-checksum.gcda ]; then mv Lab1-checksum.gcda checksum.gcda; fi
	if [ -f Lab1-checksum.gcno ]; then mv Lab1-checksum.gcno checksum.gcno; fi
	gcov -a checksum.c > coverage_checksum.txt