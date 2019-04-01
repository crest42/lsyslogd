#define FEATURE_OUTPUT_STDOUT
#ifdef FEATURE_OUTPUT_STDOUT
#include <stdio.h>
int syslog_output_stdout_init(char *opt) {
    (void)opt;
    return 0;
}

int syslog_output_stdout_write(char *buf, int size) {
    (void)size;
    printf("%s\n", buf);
    return 0;
}

#endif //FEATURE_OUTPUT_STDOUT
