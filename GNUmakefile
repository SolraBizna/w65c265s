all: bin/loadertest.hex bin/stomp_low_memory.hex

obj/%.o: src/%.658 $(wildcard include/*.inc)
	@mkdir -p obj
	wla-65816 -o $@ $<

bin/%.prog: obj/%.o
	@mkdir -p bin
	echo "[objects]" > src/$*.link
	for f in $^; do echo $$f >> src/$*.link; done
	wlalink -b -d -S src/$*.link $@

bin/%.hex: bin/%.prog bin/mks28
	bin/mks28 < $< > $@ || (rm -f $@; false)

bin/mks28: src/mks28.c
	@mkdir -p bin
	cc -O $< -o $@

# If you want to create a new program, <progname>, add bin/<progname>.hex to
# the "all" rule at the top of the file. If <progname> requires more than one
# object file, add a line like the following to the makefile:
#
# bin/<progname>.prog: obj/<progname>.o obj/someotherobject.o obj/another.o
#
# You can list as many objects as you like, but <progname>.o MUST be the first
# one in the list.

clean:
	rm -rf bin obj src/*.link
