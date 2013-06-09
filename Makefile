
UNIT_COST_SRC = $(wildcard unitsPerMinute/*.c)
UNIT_COST_HDR = $(wildcard common/*.h) $(wildcard unitsPerMinute/*.h)

CFLAGS = -O3 -Wall -Werror -iquote common
CC = gcc

all: unitsPerMinute.exe



unitsPerMinute.exe: $(UNIT_COST_SRC) $(UNIT_COST_HDR)
	$(CC) -o unitsPerMinute.exe $(CFLAGS) $(UNIT_COST_SRC) $(LDFLAGS)

run: unitsPerMinute.exe
	./unitsPerMinute.exe

clean:
	rm unitsPerMinute.exe

.PHONY: clean run

