pokemon: pokemon.c \
	stack.o btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokecards.o pokemon_ascii.o pokemon_baked_hashed_names.o
	$(LINK.c) -g -o $@ $^

test: test.c stack.o pokemon_tables.o pokecards.o
	$(LINK.c) -g -o $@ $^

%.o: %.c %.h
	$(COMPILE.c) -g -o $@ $(filter %.c,$^)

.PHONY: clean

clean:
	$(RM) *.o pokemon test
