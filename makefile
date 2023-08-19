DEPS := $(wildcard source/*.h)
DEBUG_OBJ := $(patsubst source/%.h,build/debug/%.o,$(DEPS))
RELEASE_OBJ := $(patsubst source/%.h,build/release/%.o,$(DEPS))

all: debug release
debug: build/debug/main
release: build/release/main

build/debug/main: source/main.c $(DEBUG_OBJ)
	gcc -g -o $@ $^
build/debug/%.o: source/%.c $(DEPS)
	gcc -g -o $@ -c $<

build/release/main: source/main.c $(RELEASE_OBJ)
	gcc -o $@ $^
build/release/%.o: source/%.c $(DEPS)
	gcc -o $@ -c $<

clean:
	rm build/debug/* build/release/*

.PHONY: all debug release clean
