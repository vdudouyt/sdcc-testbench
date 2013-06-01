SDCC=sdcc
OBJECTS=cvu_vinb.rel galois_lfsr.rel get_tile.rel huffman_iterative.rel huffman_recursive.rel init_loop.rel insertion_sort.rel memcpy_compression.rel memtovmemcpy.rel play_music.rel sdcc-divulong.rel sdcc-mullong.rel set_screen_mode.rel set_sprite_x.rel z88dk-mktime.rel

.PHONY: all clean

all: $(OBJECTS)
	@echo "---------------- Benchmarking results ----------------"
	@perl -ne 'print "$$ARGV: ", hex($$1), "\n" if /^A CODE size ([0-9A-Z]+)/' *.rel

clean:
	rm -f $(OBJECTS)

%.rel: %.c
	$(SDCC) -mstm8 -c $(CFLAGS) $<
