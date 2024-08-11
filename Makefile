CFLAGS := $(CFLAGS) -I. -pg

targets := pokemon
csv := pokemon.csv

all: $(targets)
pokemon: pokemon.c pokemon.h \
	stack.o btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokecards.o pokemon_ascii.o pokemon_baked_hashed_names.o
	$(LINK.c) -o $@ $(filter-out %.h,$^)

test: test.c stack.o pokemon_tables.o pokecards.o
	$(LINK.c) -o $@ $^

pokemon.h: code_generators/csv_to_macrolist.py $(csv)
	$< $(csv) > $@

pokemon_baked_hashed_names.c: code_generators/bake_hashtable.py $(csv)
	$< $(csv) > $@

%.o: %.c %.h
	$(COMPILE.c) -o $@ $(filter %.c,$^)

.PHONY: all clean

clean:
	$(RM) *.o pokemon_baked_hashed_names.c pokemon.h $(targets)
