#include <stdio.h>
#include "../include/lsyslogd.h"

extern syslog_input_t unix_sock_input;

int main (int argc, char **argv){
    lsyslogd_init(&unix_sock_input);
    lsyslogd_run();
}