CC ?= gcc
AR ?= ar
CFLAGS = -std=c11 -O2 -Wall -Wextra -ffreestanding -fno-builtin -Iinclude

.PHONY: all clean
all: build/libbosl.a

build:
	mkdir -p build

build/bosl.o: src/bosl.c include/bosl/bosl.h | build
	$(CC) $(CFLAGS) -c src/bosl.c -o $@

build/libbosl.a: build/bosl.o
	$(AR) rcs $@ $<

clean:
	rm -rf build
