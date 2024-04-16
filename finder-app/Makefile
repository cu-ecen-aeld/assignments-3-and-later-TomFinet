OUT=writer
SRC=$(OUT).c
APPS=$(wildcard *.out)
CC=gcc

ifdef CROSS_COMPILE
	CC=aarch64-none-linux-gnu-gcc
endif

build:
	$(CC) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT) $(APPS)
