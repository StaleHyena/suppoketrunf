CFLAGS := $(CFLAGS) -I..
HYPERFINE := /usr/bin/hyperfine
BENCHMARK = $(HYPERFINE) -m 100
PROF := /usr/bin/gprof
DOT := /usr/bin/dot

targets := linear.p.out btree.p.out result.json linear.png btree.png
deps := main.c $(addprefix ../,btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokemon_baked_hashed_names.o)

all: $(targets)

result.json: inputs.gen bench-normal $(HYPERFINE)
	$(BENCHMARK) -L algo linear,btree "./bench-normal {algo} < inputs.gen" --export-json $@

%.p.out: inputs.gen bench-profile
	./bench-profile $@ < inputs.gen
	mv gmon.out $@

%.p.dot: bench-profile %.p.out
	(. bin/activate; $(PROF) $< $*.p.out | gprof2dot -n 0 -e 0 > $@; deactivate)

%.png: %.p.dot
	$(DOT) -Tpng -o $@ < $<
 
inputs.gen: ../code_generators/gen_benchmark_inputs.py ../pokemon.csv
	../code_generators/gen_benchmark_inputs.py ../pokemon.csv > inputs.gen

bench-%: $(deps)
	$(LINK.c) -o $@ $^

bench-normal: CFLAGS:=$(CFLAGS) -O3
bench-profile: CFLAGS:=$(CFLAGS) -O3 -pg

.PHONY: all clean

clean:
	$(RM) *.o bench-* inputs.gen results.json *.p.out *.p.dot *.png $(targets)
