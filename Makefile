PHONY = all test
.DEFAULT_GOAL := all
WFLAGS := -Wall -Wextra -Werror
INCLUDES := -I./include/

LSYSLOGD_FEATURES := -DLSYSLOGD_FEATURE_INPUT_UNIX_SOCK
LSYSLOGD_FEATURES += -DLSYSLOGD_FEATURE_OUTPUT_STDOUT
LSYSLOGD_FEATURES += -DLSYSLOGD_FEATURE_OUTPUT_FILE
LSYSLOGD_FEATURES += -DLSYSLOGD_FEATURE_OUTPUT_REMOTE
all:
	$(CC) $(INCLUDES) $(LSYSLOGD_FEATURES) src/*.c src/outputs/*.c src/inputs/*.c -o lsyslogd

fresh: clean dep all

clean:
	rm -rf lsyslogd test

test: clean all
	$(CC) tests/*.c -o test
	./test
