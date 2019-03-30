#ifndef LSYSLOGD_OUTPUT_FILE_H
#define LSYSLOGD_OUTPUT_FILE_H

#define FILE_MODE "a"

int syslog_output_file_init(char *opt);
int syslog_output_file_write(char *buf, int size);

#endif //LSYSLOGD_OUTPUT_FILE_H