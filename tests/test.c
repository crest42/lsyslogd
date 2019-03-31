#include <stdio.h>
#include <syslog.h>
#include <string.h>

char buf[1024];
static void
log_some(void)
{
  openlog ("lsyslogd_test", 0, 0);
  for (int i = 0; i < 7;i++) {
      memset(buf, 0, sizeof(buf));
      sprintf(buf, "lsyslogdtest with pri %d", i);
      printf("%s\n", buf);
      syslog(i, buf);
  }
  closelog ();
}
int main(void) {
    printf("Starting test of lsyslogd using posix syslog functions\n");
    log_some();
}
