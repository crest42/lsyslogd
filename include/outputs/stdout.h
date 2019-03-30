#ifndef LSYSLOGD_OUTPUT_STDOUT_H
#define LSYSLOGD_OUTPUT_STDOUT_H

int syslog_output_stdout_init(char *opt);
int syslog_output_stdout_write(char *buf, int size);

#endif //LSYSLOGD_OUTPUT_FILE_H