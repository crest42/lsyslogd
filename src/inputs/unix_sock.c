#ifdef FEATURE_INPUT_UNIX_SOCK
#include "../../include/lsyslogd.h"
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>


static int fd = -1;

static int syslog_unix_sock_read(char *buf, int len)
{
    return recvfrom(fd, buf, len, 0, NULL, NULL);
}

static int syslog_unix_sock_init(char *opt) {
    printf("init syslog unix domain sockets\n");
    fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (fd < 0)
    {
        perror("socket() failed");
        return 1;
    }

    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, "/dev/log", sizeof(addr.sun_path) - 1);
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
			perror("bind failed");
	}
    chmod("/dev/log", 0666);
    return 0;
}

syslog_input_t unix_sock_input = {._read = syslog_unix_sock_read, ._init = syslog_unix_sock_init};

#else
typedef int dont_be_pendantic;
#endif //FEATURE_INPUT_UNIX_SOCK
