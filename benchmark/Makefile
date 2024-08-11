CFLAGS := $(CFLAGS) -I..
HYPERFINE := /usr/bin/hyperfine
BENCHMARK = $(HYPERFINE) -m 100
PROF := /usr/bin/gprof
DOT := /usr/bin/dot

targets := linear.all.p.out btree.all.p.out linear.exact.p.out btree.exact.p.out result.json linear.all.png btree.all.png linear.exact.png btree.exact.png
deps := main.c $(addprefix ../,btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokemon_baked_hashed_names.o btree_fuzzy_search.o)
csv := ../pokemon.csv

all: $(targets)

result.json: inputs.gen bench-normal $(HYPERFINE)
	$(BENCHMARK) -L algo linear,btree -L data exact,all "./bench-normal {algo} < inputs.{data}.gen" --export-json $@

%.all.p.out: inputs.all.gen bench-profile
	./bench-profile $* < inputs.all.gen
	mv gmon.out $@

%.all.p.dot: bench-profile %.all.p.out
	(. bin/activate; $(PROF) $< $*.all.p.out | gprof2dot -n 0 -e 0 > $@; deactivate)

%.exact.p.out: inputs.exact.gen bench-profile
	./bench-profile $* < inputs.exact.gen
	mv gmon.out $@

%.exact.p.dot: bench-profile %.exact.p.out
	(. bin/activate; $(PROF) $< $*.exact.p.out | gprof2dot -n 0 -e 0 > $@; deactivate)

%.all.png: %.all.p.dot
	$(DOT) -Tpng -o $@ < $<

%.exact.png: %.exact.p.dot
	$(DOT) -Tpng -o $@ < $<
 
inputs.all.gen: ../code_generators/gen_benchmark_inputs.py $(csv)
	$< $(csv) > $@

inputs.exact.gen: ../code_generators/gen_benchmark_inputs.py ../pokemon.csv
	$< $(csv) exact > $@

bench-%: $(deps)
	$(LINK.c) -o $@ $^

bench-normal: CFLAGS:=$(CFLAGS) -O3
bench-profile: CFLAGS:=$(CFLAGS) -O3 -pg

.PHONY: all clean

clean:
	$(RM) *.o bench-* inputs.*.gen results.json *.p.out *.p.dot *.png $(targets)
