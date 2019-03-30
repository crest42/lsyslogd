#include "../include/lsyslogd.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define FEATURE_OUTPUT_FILE
#define FEATURE_OUTPUT_REMOTE
#define FEATURE_OUTPUT_STDOUT
#define FEATURE_READ_DEV_LOG

#ifdef FEATURE_OUTPUT_FILE
#include "../include/outputs/file.h"
#endif

#ifdef FEATURE_OUTPUT_REMOTE
#include "../include/outputs/remote.h"
#endif

#ifdef FEATURE_OUTPUT_STDOUT
#include "../include/outputs/stdout.h"

#endif

char log_buf[1024];

extern syslog_input_t input;
syslog_ouput_t outputs[MAX_OUTPUTS];
int curr = 0;

static int add_output(syslog_init_f _init, syslog_write_f _write) {
    printf("add output %d\n", curr);
    assert(curr < MAX_OUTPUTS);
    outputs[curr]._init = _init;
    outputs[curr]._write = _write;
    curr++;
    return curr;
}

int init(void) {
    memset(outputs, 0, sizeof(outputs));
    #ifdef FEATURE_OUTPUT_FILE
    add_output(syslog_output_file_init, syslog_output_file_write);
    syslog_output_file_init("./a.out");
    #endif
    #ifdef FEATURE_OUTPUT_REMOTE
    add_output(syslog_output_remote_init, syslog_output_remote_write);
    syslog_output_remote_init("fe80::8a18:5a0f:45b7:1739%wlo0");
    #endif
    #ifdef FEATURE_OUTPUT_STDOUT
    add_output(syslog_output_stdout_init, syslog_output_stdout_write);
    syslog_output_stdout_init(NULL);
    #endif
    return 0;
}

int run(void) {
    input._init(NULL);

    printf("startup complete looping\n");
    while (1)
    {
        int read = input._read(log_buf, sizeof(log_buf));
        if(read < 0) {
            printf("Error on read input %d\n", read);
            return read;
        }
        for (int i = 0; i<curr;i++) {
            outputs[i]._write(log_buf, read);
        }
    }
}