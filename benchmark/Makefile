CFLAGS := $(CFLAGS) -I..
HYPERFINE := /usr/bin/hyperfine
BENCHMARK = $(HYPERFINE) -m 100
PROF := /usr/bin/gprof
DOT := /usr/bin/dot

targets := result.json \
	linear.all.png btree.all.png \
	linear.exact.png btree.exact.png
deps := main.c $(addprefix ../,btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokemon_baked_hashed_names.o btree_fuzzy_search.o)
csv := ../pokemon.csv

all: $(targets)

result.json: bench-normal \
	linear.all.gen btree.all.gen \
	linear.exact.gen btree.exact.gen \
	$(HYPERFINE)
	$(BENCHMARK) -L algo linear,btree -L data exact,all "./bench-normal {algo} < {algo}.{data}.gen" --export-json $@

%.p.out: %.gen bench-profile
	./bench-profile $* < $<
	mv gmon.out $@

%.prof: bench-profile %.out 
	$(PROF) $< $*.out > $@

%.dot: %.prof
	(. bin/activate; gprof2dot -n 0 -e 0 > $@ < $^; deactivate)

%.png: %.p.dot
	$(DOT) -Tpng -o $@ < $<
 
%.all.gen: ../code_generators/gen_benchmark_inputs.py $(csv)
	$< $(csv) > $@

%.exact.gen: ../code_generators/gen_benchmark_inputs.py ../pokemon.csv
	$< $(csv) exact > $@

bench-%: $(deps)
	$(LINK.c) -o $@ $^

bench-normal: CFLAGS:=$(CFLAGS) -O3
bench-profile: CFLAGS:=$(CFLAGS) -O3 -pg

.PHONY: all clean
.NOTINTERMEDIATE:

clean:
	$(RM) *.o bench-* *.gen results.json *.p.out *.dot *.prof *.png $(targets)
