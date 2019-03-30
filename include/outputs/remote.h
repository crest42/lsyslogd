#ifndef LSYSLOGD_OUTPUT_REMOTE_H
#define LSYSLOGD_OUTPUT_REMOTE_H

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT (514)
#define SOCK_TYPE (SOCK_DGRAM)
#define SOCK_PROTO (0)

int syslog_output_remote_init(char *opt);
int syslog_output_remote_write(char *buf, int size);

#endif //LSYSLOGD_OUTPUT_REMOTE_H