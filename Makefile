CFLAGS := $(CFLAGS) -I. -fno-omit-frame-pointer
CURL := $(shell which curl)

csv_url := https://raw.githubusercontent.com/lgreski/pokemonData/master/Pokemon.csv
csv := pokemon.csv
exe := pokemon
targets := $(exe)

all: release

$(exe): pokemon.c pokemon.h \
	stack.o btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokecards.o pokemon_ascii.o game.o \
	pokemon_baked_hashed_names.o btree_fuzzy_search.o
	$(LINK.c) -o $@ $(filter-out %.h,$^)

test: test.c pokemon.h \
	stack.o btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokecards.o pokemon_ascii.o \
	pokemon_baked_hashed_names.o btree_fuzzy_search.o
	$(LINK.c) -o $@ $(filter-out %.h,$^)

release: CFLAGS := $(CFLAGS) -O3
release: $(targets)

debug: CFLAGS := $(CFLAGS) -DDEBUG -O0 -g
debug: $(targets)

profile: CFLAGS := $(CFLAGS) -O3 -p -g
profile: $(targets)

$(csv): $(CURL)
	$(CURL) $(csv_url) | sed "1s/^/#/" > $@

pokemon.h: code_generators/csv_to_macrolist.py $(csv)
	$< $(csv) > $@

pokemon_baked_hashed_names.c: code_generators/bake_hashtable.py $(csv)
	$< $(csv) > $@

%.o: %.c %.h
	$(COMPILE.c) -o $@ $(filter %.c,$^)

.PHONY: all clean

clean:
	$(RM) *.o pokemon_baked_hashed_names.c pokemon.h $(targets)
