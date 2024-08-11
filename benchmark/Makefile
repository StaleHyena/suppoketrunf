CFLAGS := $(CFLAGS) -I..
HYPERFINE := /usr/bin/hyperfine
PROF = $(HYPERFINE) -m 100

targets := linear.p.out btree.p.out result.json
deps := main.c $(addprefix ../,btree.o queue.o utils.o \
	pokemon_tables.o pokemon_dyntables.o \
	pokemon_baked_hashed_names.o)

all: $(targets)

result.json: inputs.gen bench-normal $(HYPERFINE)
	$(PROF) -L algo linear,btree "./bench-normal {algo} < inputs.gen" --export-json $@

%.p.out: inputs.gen bench-profile
	./bench-profile $@ < inputs.gen
	mv gmon.out $@

inputs.gen: ../code_generators/gen_benchmark_inputs.py ../pokemon.csv
	../code_generators/gen_benchmark_inputs.py ../pokemon.csv > inputs.gen

bench-%: $(deps)
	$(LINK.c) -o $@ $^

bench-profile: CFLAGS:=$(CFLAGS) -pg

.PHONY: all clean

clean:
	$(RM) *.o bench-* inputs.gen results.json *.p.out *.p.proc $(targets)
