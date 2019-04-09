#include "lsyslogd.h"
#include <string.h>
#ifdef LSYSLOGD_FEATURE_OUTPUT_FILE
#include "outputs/file.h"
#endif

#ifdef LSYSLOGD_FEATURE_OUTPUT_REMOTE
#include "outputs/remote.h"
#endif

#ifdef LSYSLOGD_FEATURE_OUTPUT_STDOUT
#include "outputs/stdout.h"

#endif

char log_buf[1024];

syslog_input_t *input;
syslog_ouput_t outputs[MAX_OUTPUTS];
int curr = 0;

static syslog_input_t *register_input(syslog_input_t *i) {
    input = i;
    return input;
}

int lsyslogd_register_output(syslog_init_f _init, syslog_write_f _write) {
    if(curr < MAX_OUTPUTS) {
        outputs[curr]._init = _init;
        outputs[curr]._write = _write;
        curr++;
        return curr;
    }
    return -1;
}

int lsyslogd_init(syslog_input_t *input, char *opt) {
    register_input(input);
    input->_init(opt);
    memset(outputs, 0, sizeof(outputs));

    #ifdef LSYSLOGD_FEATURE_OUTPUT_STDOUT
    lsyslogd_register_output(syslog_output_stdout_init, syslog_output_stdout_write);
    syslog_output_stdout_init(NULL);
    #endif

    return 0;
}

int lsyslogd_run(void) {
    while (1)
    {
        int read = input->_read(log_buf, sizeof(log_buf));
        log_buf[read] = 0;
        if(read < 0) {
            return read;
        }
        for (int i = 0; i<curr;i++) {
            outputs[i]._write(log_buf,read);
        }
    }
}
