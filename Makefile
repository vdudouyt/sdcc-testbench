SDCC=sdcc
SOURCES=$(wildcard *.c)

.PHONY: all clean

all: $(SOURCES:.c=.rel)
	@echo "---------------- Benchmarking results ----------------"
	@perl -ne 'print "$$ARGV: ", hex($$1), "\n" if /^A CODE size ([0-9A-Z]+)/' *.rel

clean:
	rm -f *.asm *.lst *.rel *.sym

%.rel: %.c
	$(SDCC) -mstm8 -c $(CFLAGS) $<
