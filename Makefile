PHONY = all test
.DEFAULT_GOAL := all
WFLAGS := -Wall -Wextra -Werror
INCLUDES := -I./include/
all:
	$(CC) $(INCLUDES) -DFEATURE_INPUT_UNIX_SOCK src/*.c src/outputs/*.c src/inputs/*.c -o lsyslogd

fresh: clean dep all

clean:
	rm -rf lsyslogd test

test: clean all
	$(CC) tests/*.c -o test
	./test
