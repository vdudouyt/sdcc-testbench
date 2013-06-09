SDCC=sdcc
SOURCES=$(wildcard *.c)

.PHONY: all clean

all: $(SOURCES:.c=.rel)
	@echo "---------------- Benchmarking results ----------------"
	@perl -ne 'print "$$ARGV: ", hex($$1), "\n" if /^A CODE size ([0-9A-Z]+)/' *.rel >results.txt
	@echo -n "total: " >>results.txt
	@grep -o '[0-9]*$$' results.txt | paste -sd+ | bc >>results.txt
	@cat results.txt

clean:
	rm -f *.asm *.lst *.rel *.sym results.txt

%.rel: %.c
	$(SDCC) -mstm8 -c $(CFLAGS) $<
