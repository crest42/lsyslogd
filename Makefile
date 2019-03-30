PHONY = all test
.DEFAULT_GOAL := all
WFLAGS := -Wall -Wextra -Werror

all:
	$(CC) src/*.c src/outputs/*.c src/inputs/*.c -o bin/lsyslogd

fresh: clean dep all

clean:
	rm -rf bin/*

test: clean all
	$(CC) tests/*.c -o bin/test
	./bin/test
