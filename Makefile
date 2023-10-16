# Compiler settings
CC = gcc
CFLAGS = -std=c99 -o

# target file
all: test.c craftix.c
	$(CC) $(CFLAGS) test.exe craftix.c test.c
	./test.exe
	@$(MAKE) run_converter

# run python script
run_converter: converter.py
	python converter.py

# clean
clean:
	rm -f test.exe

.DEFAULT_GOAL := all