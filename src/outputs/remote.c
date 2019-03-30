#define FEATURE_OUTPUT_REMOTE
#ifdef FEATURE_OUTPUT_REMOTE
#include "../../include/outputs/remote.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>

static int fd;
static struct sockaddr_in6 remote;

int syslog_output_remote_init(char *opt) {
    int ret = 0;
    if(!opt) {
        printf("Error no ipv6 host provided\n");
        return -1;
    }
    fd = socket(AF_INET6, SOCK_TYPE, SOCK_PROTO);
    if(fd < 0) {
        perror("Error in socket()");
        return -1;
    }
    memset(&remote, 0, sizeof(remote));
    remote.sin6_family = AF_INET6;
    remote.sin6_port = htons(PORT);
    if ((ret = inet_pton(AF_INET6, opt, &remote.sin6_addr)) != 1)
    {
        printf("error in inet_pton %d\n",ret);
        return -1;
    }
    if(connect(fd, (const struct sockaddr *)&remote, sizeof(remote)) != 0) {
        perror("Error on connect");
        return -1;
    }
    return 0;
}

int syslog_output_remote_write(char *buf, int size) {
    return sendto(fd, buf, size, 0, (const struct sockaddr *)&remote, sizeof(remote));
}

#endif //FEATURE_OUTPUT_REMOTE