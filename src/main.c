#include "../include/lsyslogd.h"
#include <stdio.h>

int main(int argc, char **argv) {
    printf("Welcome to lsyslogd\n");
    init();
    run();
}