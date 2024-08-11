CFLAGS := $(CFLAGS) -I. -pg

targets := pokemon benchmark/bench

all: $(targets)
pokemon: pokemon.c \
	stack.o btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokecards.o pokemon_ascii.o pokemon_baked_hashed_names.o
	$(LINK.c) -o $@ $^

test: test.c stack.o pokemon_tables.o pokecards.o
	$(LINK.c) -o $@ $^

benchmark/bench: benchmark/benchmark.c \
	btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokemon_baked_hashed_names.o
	$(LINK.c) -o $@ $^

%.o: %.c %.h
	$(COMPILE.c) -o $@ $(filter %.c,$^)

.PHONY: all clean

clean:
	$(RM) *.o $(targets)
