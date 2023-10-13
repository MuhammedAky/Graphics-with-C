# Makefile

# Compiler settings
CC = gcc
CFLAGS = -std=c99 -o

# target file
all: main.c
	$(CC) $(CFLAGS) test.exe main.c
	./test.exe
	@$(MAKE) run_converter  # "make run_converter" komutunu otomatik olarak çağırın

# run python script
run_converter: converter.py
	python converter.py

# clean
clean:
	rm -f test.exe

.DEFAULT_GOAL := all