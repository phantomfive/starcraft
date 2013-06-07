
UNIT_COST_SRC = $(wildcard unitCost/*.c) $(wildcard unitCost/*.h)
UNIT_COST_HDR = $(wildcard common/*.h)

CFLAGS = -O3 -Wall -Werror -iquote common
CC = gcc

all: unitCost.exe



unitCost.exe: $(UNIT_COST_SRC) $(UNIT_COST_HDR)
	$(CC) -o unitCost.exe $(CFLAGS) $(UNIT_COST_SRC) $(LDFLAGS)

run: unitCost.exe
	./unitCost.exe

clean:
	rm unitCost.exe

.PHONY: clean run

