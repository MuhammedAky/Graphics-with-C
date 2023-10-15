# Compiler settings
CC = gcc
CFLAGS = -std=c99 -o

# target file
all: main.exe
	$(CC) $(CFLAGS) main.exe main.c
	./main.exe
	@$(MAKE) run_converter

# run python script
run_converter: converter.py
	python converter.py

# clean
clean:
	rm -f main.exe

.DEFAULT_GOAL := all
