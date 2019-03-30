//#define FEATURE_INPUT_RIOT_IPC
#ifdef FEATURE_INPUT_RIOT_IPC
#include "../../include/lsyslogd.h"


static int syslog_riot_ipc_read(char *buf, int len)
{
    return 0;
}

static int syslog_riot_ipc_init(char *opt) {
    return 0;
}

syslog_input_t input = {._read = syslog_riot_ipc_read, ._init = syslog_riot_ipc_init};

#endif //FEATURE_INPUT_RIOT_IPC