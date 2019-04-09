#ifndef LSYSLOGD_H
#define LSYSLOGD_H

#define SYSLOG_NILVALUE "-"
#define MAX_APP_NAME (32)
#define HOSTNAME_MAX_LEN (255) //https://tools.ietf.org/html/rfc1034
#define MAX_OUTPUTS (4)

typedef int (*syslog_read_f)(char *, int);
typedef int (*syslog_write_f)(char *, int);
typedef int (*syslog_init_f)(char *);

typedef struct syslog_input {
    syslog_init_f _init;
    syslog_read_f _read;
} syslog_input_t;

typedef struct syslog_ouput {
    syslog_init_f _init;
    syslog_write_f _write;
} syslog_ouput_t;

int lsyslogd_init(syslog_input_t *input,char *opt);
int lsyslogd_run(void);
#endif //LSYSLOGD_H
