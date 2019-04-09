#define FEATURE_OUTPUT_FILE
#ifdef FEATURE_OUTPUT_FILE
#include "outputs/file.h"
#include <stdio.h>
#include <assert.h>

static FILE *fp = NULL;

int syslog_output_file_init(char *opt)
{
    if(!opt) {
        return -1;
    }
    fp = fopen(opt, FILE_MODE);
    if(!fp) {
        return -1;
    }
    return 0;
}

int syslog_output_file_write(char *buf, int size) {
    if(!fp) {
        printf("Error init first\n");
    }
    int ret = fwrite(buf,1,size, fp);
    if(ret > 1) {
        fwrite("\n",1,1, fp);
        fflush(fp);
    }
    return ret;
}

#endif //FEATURE_OUTPUT_FILE