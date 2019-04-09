#include <stdio.h>
#include "lsyslogd.h"
#include "outputs/remote.h"
#include "outputs/file.h"

extern syslog_input_t unix_sock_input;

int main (int argc, char **argv){
    lsyslogd_init(&unix_sock_input,"/dev/log");
    lsyslogd_register_output(syslog_output_remote_init,syslog_output_remote_write);
    syslog_output_remote_init("::1");
    lsyslogd_register_output(syslog_output_file_init,syslog_output_file_write);
    syslog_output_file_init("./a.out");
    lsyslogd_run();
}
