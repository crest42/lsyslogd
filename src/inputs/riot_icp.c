
//TODO:REMOVE
#ifndef FEATURE_INPUT_RIOT_IPC
#define FEATURE_INPUT_RIOT_IPC
#endif

#ifdef FEATURE_INPUT_RIOT_IPC
#include "../../include/lsyslogd.h"
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include "msg.h"
#include "thread.h"

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

static kernel_pid_t rcv_pid;
static char rcv_stack[THREAD_STACKSIZE_DEFAULT];
static msg_t rcv_queue[RCV_QUEUE_SIZE];

static int syslog_riot_ipc_read(char *buf, int len)
{
    msg_t msg;
    msg_receive(&msg);
    int min = MIN((uint32_t)len,msg.content.value);
    strncpy(buf,msg.content.ptr,min);
    return min;
}

static int syslog_riot_ipc_init(char *opt) {
    (void)opt;
    rcv_pid = thread_create(rcv_stack, sizeof(rcv_stack),
                            THREAD_PRIORITY_MAIN - 1, 0, syslog_riot_ipc_read, NULL, "syslog_riot_ipc_read");
    msg_init_queue(rcv_queue, RCV_QUEUE_SIZE);
    return 0;
}

syslog_input_t input = {._read = syslog_riot_ipc_read, ._init = syslog_riot_ipc_init};

#endif //FEATURE_INPUT_RIOT_IPC