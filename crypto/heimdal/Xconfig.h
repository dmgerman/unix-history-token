begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|RCSID
end_ifndef

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|msg
parameter_list|)
define|\
value|static const char *const rcsid[] = { (const char *)rcsid, "@(#)" msg }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MaxHostNameLen
value|(64+4)
end_define

begin_define
define|#
directive|define
name|MaxPathLen
value|(1024+4)
end_define

begin_define
define|#
directive|define
name|AUTHENTICATION
value|1
end_define

begin_define
define|#
directive|define
name|BINDIR
value|"/usr/heimdal/bin"
end_define

begin_define
define|#
directive|define
name|DES_ENCRYPTION
value|1
end_define

begin_define
define|#
directive|define
name|DIAGNOSTICS
value|1
end_define

begin_define
define|#
directive|define
name|ENCRYPTION
value|1
end_define

begin_define
define|#
directive|define
name|ENDIANESS_IN_SYS_PARAM_H
value|1
end_define

begin_define
define|#
directive|define
name|GETHOSTBYNAME_PROTO_COMPATIBLE
value|1
end_define

begin_define
define|#
directive|define
name|GETSERVBYNAME_PROTO_COMPATIBLE
value|1
end_define

begin_define
define|#
directive|define
name|GETSOCKNAME_PROTO_COMPATIBLE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ARPA_FTP_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ARPA_INET_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ARPA_NAMESER_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ARPA_TELNET_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ASPRINTF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ATEXIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CGETENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CHOWN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CRYPT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CURSES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DAEMON
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DB1
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DBM_FIRSTKEY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DBOPEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DLOPEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DN_EXPAND
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_EL_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERRX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERR_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCHOWN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCNTL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FLOCK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FNMATCH
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FNMATCH_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FOUR_VALUED_EL_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FREEADDRINFO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FREEHOSTENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GAI_STRERROR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETDTABLESIZE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETEGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETEUID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETHOSTNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETIFADDRS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETIPNODEBYADDR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETIPNODEBYNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETLOGIN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETNAMEINFO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETOPT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETPROGNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETRLIMIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETSOCKOPT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETUSERSHELL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GLOB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GRP_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_HSTRERROR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_H_ERRLIST
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_H_ERRNO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_H_ERRNO_DECLARATION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_H_NERR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_IFADDRS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_IN6ADDR_LOOPBACK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INET_ATON
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INET_NTOP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INET_PTON
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INITGROUPS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INITSTATE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INNETGR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT16_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT32_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT64_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT8_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_IPV6
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_IRUSEROK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ISSETUGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIBUTIL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LOCALTIME_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LOGOUT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LOGWTMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LSTAT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKTIME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NDBM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NDBM_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NETINET6_IN6_VAR_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_SYSTM_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NETINET_IP_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NETINET_TCP_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NET_IF_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NEW_DB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPENPTY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPENSSL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPTARG_DECLARATION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPTERR_DECLARATION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPTIND_DECLARATION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPTOPT_DECLARATION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PATHS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PTHREAD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RAND
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RANDOM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RCMD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_READLINE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_READV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RECVMSG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RESOLV_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RES_SEARCH
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REVOKE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RPCSVC_YPCLNT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SA_FAMILY_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SECURITY_PAM_MODULES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SENDMSG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETEGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETEUID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETITIMER
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETLOGIN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETPGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETPROCTITLE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETPROGNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETREGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETRESGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETRESUID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETREUID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETSOCKOPT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETSTATE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SGTTY_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGNAL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SOCKET
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SOCKLEN_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SSIZE_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRFTIME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRPTIME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRSEP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRTOK_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_ADDRINFO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_IFADDRS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_IOVEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_MSGHDR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_SA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_STORAGE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_GMTOFF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_ZONE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_WINSIZE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUNVIS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRVIS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRVISX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SWAB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYSCTL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYSLOG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYSLOG_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_CAPABILITY_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_FILIO_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_IOCCOM_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_PROC_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKET_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKIO_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCALL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIMES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TTY_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_UIO_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_UN_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_UTSNAME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TERMCAP_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TERM_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TGETENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEGM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEZONE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEZONE_DECLARATION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TTYNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TTYSLOT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINT16_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINT32_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINT64_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINT8_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UMASK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNSETENV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNVIS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UTMP_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT16_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT32_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT64_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT8_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VASPRINTF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VERR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VERRX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VIS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VIS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VSYSLOG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VWARN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VWARNX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WARN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WARNX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WRITEV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WS_XPIXEL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WS_YPIXEL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_XAUFILENAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_XAUREADAUTH
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_XAUWRITEAUTH
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_YP_GET_DEFAULT_DOMAIN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE__RES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE__RES_DECLARATION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE___ATTRIBUTE__
value|1
end_define

begin_define
define|#
directive|define
name|HAVE___PROGNAME
value|1
end_define

begin_define
define|#
directive|define
name|KRB5
value|1
end_define

begin_define
define|#
directive|define
name|LIBDIR
value|"/usr/heimdal/lib"
end_define

begin_define
define|#
directive|define
name|LIBEXECDIR
value|"/usr/heimdal/libexec"
end_define

begin_define
define|#
directive|define
name|LOCALSTATEDIR
value|"/var/heimdal"
end_define

begin_define
define|#
directive|define
name|NEED_ASNPRINTF_PROTO
value|1
end_define

begin_define
define|#
directive|define
name|NEED_STRNDUP_PROTO
value|1
end_define

begin_define
define|#
directive|define
name|NEED_STRSVIS_PROTO
value|1
end_define

begin_define
define|#
directive|define
name|NEED_SVIS_PROTO
value|1
end_define

begin_define
define|#
directive|define
name|NEED_VASNPRINTF_PROTO
value|1
end_define

begin_define
define|#
directive|define
name|OLD_ENVIRON
value|1
end_define

begin_define
define|#
directive|define
name|OPENLOG_PROTO_COMPATIBLE
value|1
end_define

begin_define
define|#
directive|define
name|OTP
value|1
end_define

begin_define
define|#
directive|define
name|PACKAGE
value|"heimdal"
end_define

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"heimdal-bugs@pdc.kth.se"
end_define

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"Heimdal"
end_define

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"Heimdal 0.4f"
end_define

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"heimdal"
end_define

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"0.4f"
end_define

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|SBINDIR
value|"/usr/heimdal/sbin"
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_define
define|#
directive|define
name|SYSCONFDIR
value|"/etc"
end_define

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_define
define|#
directive|define
name|VERSION
value|"0.4f"
end_define

begin_define
define|#
directive|define
name|VOID_RETSIGTYPE
value|1
end_define

begin_define
define|#
directive|define
name|YYTEXT_POINTER
value|1
end_define

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ENCRYPTION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|AUTHENTICATION
argument_list|)
end_if

begin_define
define|#
directive|define
name|AUTHENTICATION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOGIN_PATH
end_ifndef

begin_define
define|#
directive|define
name|LOGIN_PATH
value|BINDIR "/login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ROKEN_RENAME
end_ifdef

begin_include
include|#
directive|include
file|"roken_rename.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VOID_RETSIGTYPE
end_ifdef

begin_define
define|#
directive|define
name|SIGRETURN
parameter_list|(
name|x
parameter_list|)
value|return
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGRETURN
parameter_list|(
name|x
parameter_list|)
value|return (RETSIGTYPE)(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BROKEN_REALLOC
end_ifdef

begin_define
define|#
directive|define
name|realloc
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|isoc_realloc((X), (Y))
end_define

begin_define
define|#
directive|define
name|isoc_realloc
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|((X) ? realloc((X), (Y)) : malloc(Y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FOUR_VALUED_KRB_PUT_INT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|KRB4
argument_list|)
end_if

begin_define
define|#
directive|define
name|KRB_PUT_INT
parameter_list|(
name|F
parameter_list|,
name|T
parameter_list|,
name|L
parameter_list|,
name|S
parameter_list|)
value|krb_put_int((F), (T), (L), (S))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRB_PUT_INT
parameter_list|(
name|F
parameter_list|,
name|T
parameter_list|,
name|L
parameter_list|,
name|S
parameter_list|)
value|krb_put_int((F), (T), (S))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_KRB_KDCTIMEOFDAY
end_ifndef

begin_define
define|#
directive|define
name|krb_kdctimeofday
parameter_list|(
name|X
parameter_list|)
value|gettimeofday((X), NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_KRB_GET_KDC_TIME_DIFF
end_ifndef

begin_define
define|#
directive|define
name|krb_get_kdc_time_diff
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ENDIANESS_IN_SYS_PARAM_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_AIX
end_if

begin_define
define|#
directive|define
name|_ALL_SOURCE
end_define

begin_struct_decl
struct_decl|struct
name|ether_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_dl
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_in
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|IRIX
operator|==
literal|4
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STDC__
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

