# lsyslogd
Lightweight Syslog Daemon

lsyslogd is not rfc5424 compatible and is not aimed to be. There is no plan of implementing TLS supprt as rfc5424 requires.

Since this implementation is aimed to run on embedded systems (and the RIOT OS in specific) there are a few design criterias:

- Work in a single Thread
- Small and Lightweight
- UDP Only
- Configurable POSIX sockets
- Configurable syslog msg inputs
- Custom input for RIOT IPC
- Use static memory
- v6 only
