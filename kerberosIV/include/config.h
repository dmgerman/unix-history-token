begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include/config.h.  Hand tweaked by MarkM.  */
end_comment

begin_comment
comment|/* include/config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* include/config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|KRB4
value|1
end_define

begin_comment
comment|/* Define if using alloca.c.  */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.    This function is required for alloca.c support on those systems.  */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define if you have alloca, as a function or macro.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix).  */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define if you have a working `mmap' system call.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define if your struct stat has st_blksize.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (int or void).  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.  STACK_DIRECTION> 0 => grows toward higher addresses  STACK_DIRECTION< 0 => grows toward lower addresses  STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if `sys_siglist' is declared by<signal.h>.  */
end_comment

begin_define
define|#
directive|define
name|SYS_SIGLIST_DECLARED
value|1
end_define

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* Define if your processor stores words with the most significant    byte first (like Motorola and SPARC, unlike Intel and VAX).  */
end_comment

begin_comment
comment|/* #undef WORDS_BIGENDIAN */
end_comment

begin_comment
comment|/* Define if the X Window System is missing or not being used.  */
end_comment

begin_define
define|#
directive|define
name|X_DISPLAY_MISSING
value|1
end_define

begin_comment
comment|/* Define if you have the XauFileName function.  */
end_comment

begin_comment
comment|/* #undef HAVE_XAUFILENAME */
end_comment

begin_comment
comment|/* Define if you have the XauReadAuth function.  */
end_comment

begin_comment
comment|/* #undef HAVE_XAUREADAUTH */
end_comment

begin_comment
comment|/* Define if you have the XauWriteAuth function.  */
end_comment

begin_comment
comment|/* #undef HAVE_XAUWRITEAUTH */
end_comment

begin_comment
comment|/* Define if you have the _getpty function.  */
end_comment

begin_comment
comment|/* #undef HAVE__GETPTY */
end_comment

begin_comment
comment|/* Define if you have the _scrsize function.  */
end_comment

begin_comment
comment|/* #undef HAVE__SCRSIZE */
end_comment

begin_comment
comment|/* Define if you have the _setsid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE__SETSID
value|1
end_define

begin_comment
comment|/* Define if you have the _stricmp function.  */
end_comment

begin_comment
comment|/* #undef HAVE__STRICMP */
end_comment

begin_comment
comment|/* Define if you have the asnprintf function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ASNPRINTF */
end_comment

begin_comment
comment|/* Define if you have the asprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ASPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the atexit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
value|1
end_define

begin_comment
comment|/* Define if you have the cap_set_proc function.  */
end_comment

begin_comment
comment|/* #undef HAVE_CAP_SET_PROC */
end_comment

begin_comment
comment|/* Define if you have the cgetent function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CGETENT
value|1
end_define

begin_comment
comment|/* Define if you have the chown function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHOWN
value|1
end_define

begin_comment
comment|/* Define if you have the chroot function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHROOT
value|1
end_define

begin_comment
comment|/* Define if you have the copyhostent function.  */
end_comment

begin_comment
comment|/* #undef HAVE_COPYHOSTENT */
end_comment

begin_comment
comment|/* Define if you have the crypt function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CRYPT
value|1
end_define

begin_comment
comment|/* Define if you have the daemon function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DAEMON
value|1
end_define

begin_comment
comment|/* Define if you have the dlopen function.  */
end_comment

begin_comment
comment|/* #undef HAVE_DLOPEN */
end_comment

begin_comment
comment|/* Define if you have the dn_expand function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DN_EXPAND
value|1
end_define

begin_comment
comment|/* Define if you have the el_init function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_EL_INIT
value|1
end_define

begin_comment
comment|/* Define if you have the err function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR
value|1
end_define

begin_comment
comment|/* Define if you have the errx function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRX
value|1
end_define

begin_comment
comment|/* Define if you have the fattach function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FATTACH */
end_comment

begin_comment
comment|/* Define if you have the fchmod function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|1
end_define

begin_comment
comment|/* Define if you have the fchown function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHOWN
value|1
end_define

begin_comment
comment|/* Define if you have the fcntl function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL
value|1
end_define

begin_comment
comment|/* Define if you have the flock function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOCK
value|1
end_define

begin_comment
comment|/* Define if you have the fnmatch function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FNMATCH
value|1
end_define

begin_comment
comment|/* Define if you have the forkpty function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FORKPTY
value|1
end_define

begin_comment
comment|/* Define if you have the freehostent function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FREEHOSTENT
value|1
end_define

begin_comment
comment|/* Define if you have the frevoke function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FREVOKE */
end_comment

begin_comment
comment|/* Define if you have the getattr function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETATTR */
end_comment

begin_comment
comment|/* Define if you have the getcwd function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define if you have the getdtablesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETDTABLESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the getegid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEGID
value|1
end_define

begin_comment
comment|/* Define if you have the geteuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEUID
value|1
end_define

begin_comment
comment|/* Define if you have the getgid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGID
value|1
end_define

begin_comment
comment|/* Define if you have the gethostbyname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME
value|1
end_define

begin_comment
comment|/* Define if you have the gethostname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTNAME
value|1
end_define

begin_comment
comment|/* Define if you have the getipnodebyaddr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIPNODEBYADDR
value|1
end_define

begin_comment
comment|/* Define if you have the getipnodebyname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIPNODEBYNAME
value|1
end_define

begin_comment
comment|/* Define if you have the getlogin function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETLOGIN
value|1
end_define

begin_comment
comment|/* Define if you have the getmsg function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETMSG */
end_comment

begin_comment
comment|/* Define if you have the getopt function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT
value|1
end_define

begin_comment
comment|/* Define if you have the getpagesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the getpriority function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPRIORITY
value|1
end_define

begin_comment
comment|/* Define if you have the getpwnam_r function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETPWNAM_R */
end_comment

begin_comment
comment|/* Define if you have the getrlimit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRLIMIT
value|1
end_define

begin_comment
comment|/* Define if you have the getservbyname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETSERVBYNAME
value|1
end_define

begin_comment
comment|/* Define if you have the getsockopt function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETSOCKOPT
value|1
end_define

begin_comment
comment|/* Define if you have the getspnam function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETSPNAM */
end_comment

begin_comment
comment|/* Define if you have the gettimeofday function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define if you have the gettosbyname function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETTOSBYNAME */
end_comment

begin_comment
comment|/* Define if you have the getudbnam function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETUDBNAM */
end_comment

begin_comment
comment|/* Define if you have the getuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_comment
comment|/* Define if you have the getusershell function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUSERSHELL
value|1
end_define

begin_comment
comment|/* Define if you have the grantpt function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GRANTPT */
end_comment

begin_comment
comment|/* Define if you have the hstrerror function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_HSTRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the inet_aton function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_ATON
value|1
end_define

begin_comment
comment|/* Define if you have the inet_ntop function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_NTOP
value|1
end_define

begin_comment
comment|/* Define if you have the inet_pton function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_PTON
value|1
end_define

begin_comment
comment|/* Define if you have the initgroups function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INITGROUPS
value|1
end_define

begin_comment
comment|/* Define if you have the innetgr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INNETGR
value|1
end_define

begin_comment
comment|/* Define if you have the iruserok function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_IRUSEROK
value|1
end_define

begin_comment
comment|/* Define if you have the logout function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOGOUT
value|1
end_define

begin_comment
comment|/* Define if you have the logwtmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOGWTMP
value|1
end_define

begin_comment
comment|/* Define if you have the lstat function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LSTAT
value|1
end_define

begin_comment
comment|/* Define if you have the memmove function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define if you have the mkstemp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define if you have the mktime function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKTIME
value|1
end_define

begin_comment
comment|/* Define if you have the odm_initialize function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ODM_INITIALIZE */
end_comment

begin_comment
comment|/* Define if you have the on_exit function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ON_EXIT */
end_comment

begin_comment
comment|/* Define if you have the parsetos function.  */
end_comment

begin_comment
comment|/* #undef HAVE_PARSETOS */
end_comment

begin_comment
comment|/* Define if you have the ptsname function.  */
end_comment

begin_comment
comment|/* #undef HAVE_PTSNAME */
end_comment

begin_comment
comment|/* Define if you have the putenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define if you have the rand function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RAND
value|1
end_define

begin_comment
comment|/* Define if you have the random function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RANDOM
value|1
end_define

begin_comment
comment|/* Define if you have the rcmd function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RCMD
value|1
end_define

begin_comment
comment|/* Define if you have the readline function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINE
value|1
end_define

begin_comment
comment|/* Define if you have the readv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_READV
value|1
end_define

begin_comment
comment|/* Define if you have the recvmsg function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RECVMSG
value|1
end_define

begin_comment
comment|/* Define if you have the res_search function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RES_SEARCH
value|1
end_define

begin_comment
comment|/* Define if you have the revoke function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_REVOKE
value|1
end_define

begin_comment
comment|/* Define if you have the sa_family_t function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_FAMILY_T
value|1
end_define

begin_comment
comment|/* Define if you have the sendmsg function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SENDMSG
value|1
end_define

begin_comment
comment|/* Define if you have the setegid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETEGID
value|1
end_define

begin_comment
comment|/* Define if you have the setenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if you have the seteuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETEUID
value|1
end_define

begin_comment
comment|/* Define if you have the setitimer function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETITIMER
value|1
end_define

begin_comment
comment|/* Define if you have the setlim function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SETLIM */
end_comment

begin_comment
comment|/* Define if you have the setlogin function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOGIN
value|1
end_define

begin_comment
comment|/* Define if you have the setpcred function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SETPCRED */
end_comment

begin_comment
comment|/* Define if you have the setpgid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPGID
value|1
end_define

begin_comment
comment|/* Define if you have the setpriority function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPRIORITY
value|1
end_define

begin_comment
comment|/* Define if you have the setproctitle function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPROCTITLE
value|1
end_define

begin_comment
comment|/* Define if you have the setregid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETREGID
value|1
end_define

begin_comment
comment|/* Define if you have the setresgid function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SETRESGID */
end_comment

begin_comment
comment|/* Define if you have the setresuid function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SETRESUID */
end_comment

begin_comment
comment|/* Define if you have the setreuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETREUID
value|1
end_define

begin_comment
comment|/* Define if you have the setsid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_comment
comment|/* Define if you have the setsockopt function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSOCKOPT
value|1
end_define

begin_comment
comment|/* Define if you have the setutent function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SETUTENT */
end_comment

begin_comment
comment|/* Define if you have the sgi_getcapabilitybyname function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SGI_GETCAPABILITYBYNAME */
end_comment

begin_comment
comment|/* Define if you have the sigaction function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define if you have the socket function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKET
value|1
end_define

begin_comment
comment|/* Define if you have the strcasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the strdup function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define if you have the strerror function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the strftime function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRFTIME
value|1
end_define

begin_comment
comment|/* Define if you have the strlcat function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_comment
comment|/* Define if you have the strlcpy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define if you have the strlwr function.  */
end_comment

begin_comment
comment|/* #undef HAVE_STRLWR */
end_comment

begin_comment
comment|/* Define if you have the strncasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the strndup function.  */
end_comment

begin_comment
comment|/* #undef HAVE_STRNDUP */
end_comment

begin_comment
comment|/* Define if you have the strnlen function.  */
end_comment

begin_comment
comment|/* #undef HAVE_STRNLEN */
end_comment

begin_comment
comment|/* Define if you have the strptime function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRPTIME
value|1
end_define

begin_comment
comment|/* Define if you have the strsep function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSEP
value|1
end_define

begin_comment
comment|/* Define if you have the strtok_r function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOK_R
value|1
end_define

begin_comment
comment|/* Define if you have the struct_sockaddr_storage function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_STORAGE
value|1
end_define

begin_comment
comment|/* Define if you have the strupr function.  */
end_comment

begin_comment
comment|/* #undef HAVE_STRUPR */
end_comment

begin_comment
comment|/* Define if you have the swab function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SWAB
value|1
end_define

begin_comment
comment|/* Define if you have the sysconf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define if you have the sysctl function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCTL
value|1
end_define

begin_comment
comment|/* Define if you have the syslog function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSLOG
value|1
end_define

begin_comment
comment|/* Define if you have the tgetent function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TGETENT
value|1
end_define

begin_comment
comment|/* Define if you have the ttyname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TTYNAME
value|1
end_define

begin_comment
comment|/* Define if you have the ttyslot function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TTYSLOT
value|1
end_define

begin_comment
comment|/* Define if you have the ulimit function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ULIMIT */
end_comment

begin_comment
comment|/* Define if you have the uname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNAME
value|1
end_define

begin_comment
comment|/* Define if you have the unlockpt function.  */
end_comment

begin_comment
comment|/* #undef HAVE_UNLOCKPT */
end_comment

begin_comment
comment|/* Define if you have the unsetenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSETENV
value|1
end_define

begin_comment
comment|/* Define if you have the vasnprintf function.  */
end_comment

begin_comment
comment|/* #undef HAVE_VASNPRINTF */
end_comment

begin_comment
comment|/* Define if you have the vasprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VASPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the verr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VERR
value|1
end_define

begin_comment
comment|/* Define if you have the verrx function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VERRX
value|1
end_define

begin_comment
comment|/* Define if you have the vhangup function.  */
end_comment

begin_comment
comment|/* #undef HAVE_VHANGUP */
end_comment

begin_comment
comment|/* Define if you have the vsnprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the vsyslog function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSYSLOG
value|1
end_define

begin_comment
comment|/* Define if you have the vwarn function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VWARN
value|1
end_define

begin_comment
comment|/* Define if you have the vwarnx function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VWARNX
value|1
end_define

begin_comment
comment|/* Define if you have the warn function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WARN
value|1
end_define

begin_comment
comment|/* Define if you have the warnx function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WARNX
value|1
end_define

begin_comment
comment|/* Define if you have the writev function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WRITEV
value|1
end_define

begin_comment
comment|/* Define if you have the yp_get_default_domain function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_YP_GET_DEFAULT_DOMAIN
value|1
end_define

begin_comment
comment|/* Define if you have the<arpa/ftp.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_FTP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<arpa/inet.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_INET_H
value|1
end_define

begin_comment
comment|/* Define if you have the<arpa/nameser.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_NAMESER_H
value|1
end_define

begin_comment
comment|/* Define if you have the<arpa/telnet.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_TELNET_H
value|1
end_define

begin_comment
comment|/* Define if you have the<bsd/bsd.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_BSD_BSD_H */
end_comment

begin_comment
comment|/* Define if you have the<bsdsetjmp.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_BSDSETJMP_H */
end_comment

begin_comment
comment|/* Define if you have the<capability.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_CAPABILITY_H */
end_comment

begin_comment
comment|/* Define if you have the<crypt.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_CRYPT_H */
end_comment

begin_comment
comment|/* Define if you have the<curses.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CURSES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<db.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<dbm.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_DBM_H */
end_comment

begin_comment
comment|/* Define if you have the<dirent.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<err.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR_H
value|1
end_define

begin_comment
comment|/* Define if you have the<errno.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<fnmatch.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FNMATCH_H
value|1
end_define

begin_comment
comment|/* Define if you have the<grp.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GRP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<inttypes.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<io.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_IO_H */
end_comment

begin_comment
comment|/* Define if you have the<lastlog.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LASTLOG_H */
end_comment

begin_comment
comment|/* Define if you have the<libutil.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBUTIL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<limits.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<login.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LOGIN_H */
end_comment

begin_comment
comment|/* Define if you have the<maillock.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MAILLOCK_H */
end_comment

begin_comment
comment|/* Define if you have the<ndbm.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NDBM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<net/if.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<net/if_tun.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_TUN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<net/if_var.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_VAR_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netdb.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/in.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/in6_machtypes.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IN6_MACHTYPES_H */
end_comment

begin_comment
comment|/* Define if you have the<netinet/in_systm.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_SYSTM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/ip.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/tcp.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_TCP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<paths.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PATHS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<pty.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_PTY_H */
end_comment

begin_comment
comment|/* Define if you have the<pwd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_comment
comment|/* Define if you have the<resolv.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESOLV_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpcsvc/dbm.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_RPCSVC_DBM_H */
end_comment

begin_comment
comment|/* Define if you have the<rpcsvc/ypclnt.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPCSVC_YPCLNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sac.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SAC_H */
end_comment

begin_comment
comment|/* Define if you have the<security/pam_modules.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SECURITY_PAM_MODULES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<shadow.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SHADOW_H */
end_comment

begin_comment
comment|/* Define if you have the<siad.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SIAD_H */
end_comment

begin_comment
comment|/* Define if you have the<signal.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGNAL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<standards.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_STANDARDS_H */
end_comment

begin_comment
comment|/* Define if you have the<stropts.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_STROPTS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/bitypes.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_BITYPES_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/capability.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CAPABILITY_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/category.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CATEGORY_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/filio.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ioccom.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCCOM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ioctl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/locking.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_LOCKING_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/mman.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/proc.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PROC_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/pty.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTY_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ptyio.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTYIO_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ptyvar.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTYVAR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/resource.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/select.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/socket.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKET_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/sockio.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stat.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/str_tty.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STR_TTY_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/stream.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STREAM_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/stropts.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STROPTS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/strtty.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STRTTY_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/syscall.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCALL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/sysctl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/termio.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TERMIO_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/timeb.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/times.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/tty.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TTY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/uio.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/un.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/utsname.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UTSNAME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/wait.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<syslog.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSLOG_H
value|1
end_define

begin_comment
comment|/* Define if you have the<term.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<termcap.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMCAP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<termio.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_TERMIO_H */
end_comment

begin_comment
comment|/* Define if you have the<termios.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<tmpdir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_TMPDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<ttyent.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TTYENT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<udb.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_UDB_H */
end_comment

begin_comment
comment|/* Define if you have the<ulimit.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_ULIMIT_H */
end_comment

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the<userpw.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_USERPW_H */
end_comment

begin_comment
comment|/* Define if you have the<usersec.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_USERSEC_H */
end_comment

begin_comment
comment|/* Define if you have the<util.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_UTIL_H */
end_comment

begin_comment
comment|/* Define if you have the<utime.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<utmp.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTMP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<utmpx.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_UTMPX_H */
end_comment

begin_comment
comment|/* Define if you have the<wait.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_WAIT_H */
end_comment

begin_comment
comment|/* Define if you have the X11 library (-lX11).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBX11 */
end_comment

begin_comment
comment|/* Define if you have the Xau library (-lXau).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBXAU */
end_comment

begin_comment
comment|/* Define if you have the c_r library (-lc_r).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBC_R */
end_comment

begin_comment
comment|/* Define if you have the cfg library (-lcfg).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBCFG */
end_comment

begin_comment
comment|/* Define if you have the crypt library (-lcrypt).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBCRYPT
value|1
end_define

begin_comment
comment|/* Define if you have the curses library (-lcurses).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBCURSES */
end_comment

begin_comment
comment|/* Define if you have the dl library (-ldl).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBDL */
end_comment

begin_comment
comment|/* Define if you have the edit library (-ledit).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBEDIT
value|1
end_define

begin_comment
comment|/* Define if you have the ncurses library (-lncurses).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNCURSES */
end_comment

begin_comment
comment|/* Define if you have the nsl library (-lnsl).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNSL */
end_comment

begin_comment
comment|/* Define if you have the odm library (-lodm).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBODM */
end_comment

begin_comment
comment|/* Define if you have the readline library (-lreadline).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBREADLINE
value|1
end_define

begin_comment
comment|/* Define if you have the resolv library (-lresolv).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBRESOLV */
end_comment

begin_comment
comment|/* Define if you have the s library (-ls).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBS */
end_comment

begin_comment
comment|/* Define if you have the socket library (-lsocket).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

begin_comment
comment|/* Define if you have the syslog library (-lsyslog).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSYSLOG */
end_comment

begin_comment
comment|/* Define if you have the termcap library (-ltermcap).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBTERMCAP
value|1
end_define

begin_comment
comment|/* Define if you have the util library (-lutil).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBUTIL
value|1
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"krb4"
end_define

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"1.0"
end_define

begin_comment
comment|/* Define to what version of SunOS you are running. */
end_comment

begin_comment
comment|/* #undef SunOS */
end_comment

begin_comment
comment|/* Define if you have the socks package. */
end_comment

begin_comment
comment|/* #undef SOCKS */
end_comment

begin_comment
comment|/* Define to enable old kdestroy behavior. */
end_comment

begin_comment
comment|/* #undef LEGACY_KDESTROY */
end_comment

begin_comment
comment|/* Define if you want to match subdomains. */
end_comment

begin_comment
comment|/* #undef MATCH_SUBDOMAINS */
end_comment

begin_comment
comment|/* Define this to be the directory where the  	dictionary for cracklib resides. */
end_comment

begin_comment
comment|/* #undef DICTPATH */
end_comment

begin_comment
comment|/* Define this to the path of the mail spool directory. */
end_comment

begin_comment
comment|/* #undef KRB4_MAILDIR */
end_comment

begin_comment
comment|/* Define this to the kerberos database directory. */
end_comment

begin_comment
comment|/* #undef DB_DIR */
end_comment

begin_comment
comment|/* Define to enable new master key code. */
end_comment

begin_comment
comment|/* #undef RANDOM_MKEY */
end_comment

begin_comment
comment|/* Define this to the location of the master key. */
end_comment

begin_comment
comment|/* #undef MKEYFILE */
end_comment

begin_comment
comment|/* Define to enable basic OSF C2 support. */
end_comment

begin_comment
comment|/* #undef HAVE_OSFC2 */
end_comment

begin_comment
comment|/* Define if you don't want to use mmap. */
end_comment

begin_comment
comment|/* #undef NO_MMAP */
end_comment

begin_comment
comment|/* Define if you don't wan't support for AFS. */
end_comment

begin_comment
comment|/* #undef NO_AFS */
end_comment

begin_comment
comment|/* Set this to the type of des-quad-cheksum to use. */
end_comment

begin_define
define|#
directive|define
name|DES_QUAD_DEFAULT
value|DES_QUAD_GUESS
end_define

begin_comment
comment|/* Define if you have the readline package. */
end_comment

begin_comment
comment|/* #undef READLINE */
end_comment

begin_comment
comment|/* Define if you have the hesiod package. */
end_comment

begin_comment
comment|/* #undef HESIOD */
end_comment

begin_comment
comment|/* define if your compiler has __attribute__ */
end_comment

begin_define
define|#
directive|define
name|HAVE___ATTRIBUTE__
value|1
end_define

begin_comment
comment|/* Huh? */
end_comment

begin_comment
comment|/* #undef HAVE_STRANGE_INT8_T */
end_comment

begin_comment
comment|/* Define if NDBM really is DB (creates files ending in .db). */
end_comment

begin_define
define|#
directive|define
name|HAVE_NEW_DB
value|1
end_define

begin_comment
comment|/* Define if you have NDBM (and not DBM) */
end_comment

begin_define
define|#
directive|define
name|NDBM
value|1
end_define

begin_comment
comment|/* define if you have a working snprintf */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_comment
comment|/* define if the system is missing a prototype for snprintf() */
end_comment

begin_comment
comment|/* #undef NEED_SNPRINTF_PROTO */
end_comment

begin_comment
comment|/* define if you have a glob() that groks  	GLOB_BRACE, GLOB_NOCHECK, GLOB_QUOTE, and GLOB_TILDE */
end_comment

begin_define
define|#
directive|define
name|HAVE_GLOB
value|1
end_define

begin_comment
comment|/* define if the system is missing a prototype for glob() */
end_comment

begin_comment
comment|/* #undef NEED_GLOB_PROTO */
end_comment

begin_comment
comment|/* Define if getpwnam_r has POSIX flavour. */
end_comment

begin_comment
comment|/* #undef POSIX_GETPWNAM_R */
end_comment

begin_comment
comment|/* Define if getlogin has POSIX flavour (and not BSD). */
end_comment

begin_comment
comment|/* #undef POSIX_GETLOGIN */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for hstrerror() */
end_comment

begin_comment
comment|/* #undef NEED_HSTRERROR_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for gethostname() */
end_comment

begin_comment
comment|/* #undef NEED_GETHOSTNAME_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for mkstemp() */
end_comment

begin_comment
comment|/* #undef NEED_MKSTEMP_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for inet_aton() */
end_comment

begin_comment
comment|/* #undef NEED_INET_ATON_PROTO */
end_comment

begin_comment
comment|/* Define if realloc(NULL, X) doesn't work. */
end_comment

begin_comment
comment|/* #undef BROKEN_REALLOC */
end_comment

begin_comment
comment|/* Define if getcwd is broken (like in SunOS 4). */
end_comment

begin_comment
comment|/* #undef BROKEN_GETCWD */
end_comment

begin_comment
comment|/* define if prototype of gethostbyname is compatible with 	struct hostent *gethostbyname(const char *) */
end_comment

begin_define
define|#
directive|define
name|GETHOSTBYNAME_PROTO_COMPATIBLE
value|1
end_define

begin_comment
comment|/* define if prototype of gethostbyaddr is compatible with 	struct hostent *gethostbyaddr(const void *, size_t, int) */
end_comment

begin_comment
comment|/* #undef GETHOSTBYADDR_PROTO_COMPATIBLE */
end_comment

begin_comment
comment|/* define if prototype of getservbyname is compatible with 	struct servent *getservbyname(const char *, const char *) */
end_comment

begin_define
define|#
directive|define
name|GETSERVBYNAME_PROTO_COMPATIBLE
value|1
end_define

begin_comment
comment|/* define if prototype of openlog is compatible with 	void openlog(const char *, int, int) */
end_comment

begin_define
define|#
directive|define
name|OPENLOG_PROTO_COMPATIBLE
value|1
end_define

begin_comment
comment|/* define if the system is missing a prototype for crypt() */
end_comment

begin_comment
comment|/* #undef NEED_CRYPT_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for fclose() */
end_comment

begin_comment
comment|/* #undef NEED_FCLOSE_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for strtok_r() */
end_comment

begin_comment
comment|/* #undef NEED_STRTOK_R_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for strsep() */
end_comment

begin_comment
comment|/* #undef NEED_STRSEP_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for getusershell() */
end_comment

begin_comment
comment|/* #undef NEED_GETUSERSHELL_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for utime() */
end_comment

begin_comment
comment|/* #undef NEED_UTIME_PROTO */
end_comment

begin_comment
comment|/* define if you have h_errno */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_ERRNO
value|1
end_define

begin_comment
comment|/* define if your system declares h_errno */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_ERRNO_DECLARATION
value|1
end_define

begin_comment
comment|/* define if you have h_errlist */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_ERRLIST
value|1
end_define

begin_comment
comment|/* define if your system declares h_errlist */
end_comment

begin_comment
comment|/* #undef HAVE_H_ERRLIST_DECLARATION */
end_comment

begin_comment
comment|/* define if you have h_nerr */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_NERR
value|1
end_define

begin_comment
comment|/* define if your system declares h_nerr */
end_comment

begin_comment
comment|/* #undef HAVE_H_NERR_DECLARATION */
end_comment

begin_comment
comment|/* define if you have __progname */
end_comment

begin_define
define|#
directive|define
name|HAVE___PROGNAME
value|1
end_define

begin_comment
comment|/* define if your system declares __progname */
end_comment

begin_comment
comment|/* #undef HAVE___PROGNAME_DECLARATION */
end_comment

begin_comment
comment|/* define if your system declares optarg */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTARG_DECLARATION
value|1
end_define

begin_comment
comment|/* define if your system declares optind */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTIND_DECLARATION
value|1
end_define

begin_comment
comment|/* define if your system declares opterr */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTERR_DECLARATION
value|1
end_define

begin_comment
comment|/* define if your system declares optopt */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTOPT_DECLARATION
value|1
end_define

begin_comment
comment|/* define if your system declares environ */
end_comment

begin_comment
comment|/* #undef HAVE_ENVIRON_DECLARATION */
end_comment

begin_comment
comment|/* Define if RETSIGTYPE == void. */
end_comment

begin_define
define|#
directive|define
name|VOID_RETSIGTYPE
value|1
end_define

begin_comment
comment|/* Define if struct utmp has field ut_addr. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_ADDR */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_host. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_UTMP_UT_HOST
value|1
end_define

begin_comment
comment|/* Define if struct utmp has field ut_id. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_ID */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_pid. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_PID */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_type. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_TYPE */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_user. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_USER */
end_comment

begin_comment
comment|/* Define if struct utmpx has field ut_exit. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMPX_UT_EXIT */
end_comment

begin_comment
comment|/* Define if struct utmpx has field ut_syslen. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMPX_UT_SYSLEN */
end_comment

begin_comment
comment|/* Define if struct tm has field tm_gmtoff. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_GMTOFF
value|1
end_define

begin_comment
comment|/* Define if struct tm has field tm_zone. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_ZONE
value|1
end_define

begin_comment
comment|/* define if you have timezone */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEZONE
value|1
end_define

begin_comment
comment|/* define if your system declares timezone */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEZONE_DECLARATION
value|1
end_define

begin_comment
comment|/* define if you have struct spwd */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_SPWD */
end_comment

begin_comment
comment|/* define if struct winsize is declared in sys/termios.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_WINSIZE
value|1
end_define

begin_comment
comment|/* define if struct winsize has ws_xpixel */
end_comment

begin_define
define|#
directive|define
name|HAVE_WS_XPIXEL
value|1
end_define

begin_comment
comment|/* define if struct winsize has ws_ypixel */
end_comment

begin_define
define|#
directive|define
name|HAVE_WS_YPIXEL
value|1
end_define

begin_comment
comment|/* Define this to what the type ssize_t should be. */
end_comment

begin_comment
comment|/* #undef ssize_t */
end_comment

begin_comment
comment|/* Define if struct sockaddr has field sa_len. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_SA_LEN
value|1
end_define

begin_comment
comment|/* Define if SIAENTITY has field ouid. */
end_comment

begin_comment
comment|/* #undef HAVE_SIAENTITY_OUID */
end_comment

begin_comment
comment|/* Define if you have a working getmsg. */
end_comment

begin_comment
comment|/* #undef HAVE_GETMSG */
end_comment

begin_comment
comment|/* Define if el_init takes four arguments. */
end_comment

begin_comment
comment|/* #undef HAVE_FOUR_VALUED_EL_INIT */
end_comment

begin_comment
comment|/* Define if you have a readline function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINE
value|1
end_define

begin_comment
comment|/* Define if you have working stream ptys. */
end_comment

begin_comment
comment|/* #undef STREAMSPTY */
end_comment

begin_comment
comment|/* Define if /bin/ls has a `-A' flag. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LS_A
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
name|HAVE_U_INT8_T
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

begin_comment
comment|/* This for compat with heimdal (or something) */
end_comment

begin_define
define|#
directive|define
name|KRB_PUT_INT
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|,
name|l
parameter_list|,
name|s
parameter_list|)
value|krb_put_int((f), (t), (l), (s))
end_define

begin_define
define|#
directive|define
name|HAVE_KRB_ENABLE_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_KRB_DISABLE_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_KRB_GET_OUR_IP_FOR_REALM
value|1
end_define

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|msg
parameter_list|)
define|\
value|static
comment|/**/
value|const char *const rcsid[] = { (char *)rcsid, "\100(#)" msg }
end_define

begin_comment
comment|/*  * Set ORGANIZATION to be the desired organization string printed  * by the 'kinit' program.  It may have spaces.  */
end_comment

begin_define
define|#
directive|define
name|ORGANIZATION
value|"FreeBSD Inc."
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|BINDIR
value|"/usr/bin"
end_define

begin_define
define|#
directive|define
name|LIBDIR
value|"/usr/lib"
end_define

begin_define
define|#
directive|define
name|LIBEXECDIR
value|"/usr/libexec"
end_define

begin_define
define|#
directive|define
name|SBINDIR
value|"/usr/sbin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|KRB_CNF_FILES
value|{ "/etc/krb.conf",   "/etc/kerberosIV/krb.conf", 0}
end_define

begin_define
define|#
directive|define
name|KRB_RLM_FILES
value|{ "/etc/krb.realms", "/etc/kerberosIV/krb.realms", 0}
end_define

begin_define
define|#
directive|define
name|KRB_EQUIV
value|"/etc/krb.equiv"
end_define

begin_define
define|#
directive|define
name|KEYFILE
value|"/etc/srvtab"
end_define

begin_define
define|#
directive|define
name|KRBDIR
value|"/var/kerberos"
end_define

begin_define
define|#
directive|define
name|DBM_FILE
value|KRBDIR "/principal"
end_define

begin_define
define|#
directive|define
name|DEFAULT_ACL_DIR
value|KRBDIR
end_define

begin_define
define|#
directive|define
name|KRBLOG
value|"/var/log/kerberos.log"
end_define

begin_comment
comment|/* master server  */
end_comment

begin_define
define|#
directive|define
name|KRBSLAVELOG
value|"/var/log/kerberos_slave.log"
end_define

begin_comment
comment|/* slave server  */
end_comment

begin_define
define|#
directive|define
name|KADM_SYSLOG
value|"/var/log/admin_server.syslog"
end_define

begin_define
define|#
directive|define
name|K_LOGFIL
value|"/var/log/kpropd.log"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Maximum values on all known systems */
end_comment

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

begin_comment
comment|/* ftp stuff -------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|KERBEROS
end_define

begin_comment
comment|/* telnet stuff ----------------------------------------------- */
end_comment

begin_comment
comment|/* define this for OTP support */
end_comment

begin_comment
comment|/* #undef OTP */
end_comment

begin_comment
comment|/* define this if you have kerberos 4 */
end_comment

begin_define
define|#
directive|define
name|KRB4
value|1
end_define

begin_comment
comment|/* define this if you want encryption */
end_comment

begin_define
define|#
directive|define
name|ENCRYPTION
value|1
end_define

begin_comment
comment|/* define this if you want authentication */
end_comment

begin_define
define|#
directive|define
name|AUTHENTICATION
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

begin_comment
comment|/* Set this if you want des encryption */
end_comment

begin_define
define|#
directive|define
name|DES_ENCRYPTION
value|1
end_define

begin_comment
comment|/* Set this to the default system lead string for telnetd   * can contain %-escapes: %s=sysname, %m=machine, %r=os-release  * %v=os-version, %t=tty, %h=hostname, %d=date and time  */
end_comment

begin_comment
comment|/* #undef USE_IM */
end_comment

begin_comment
comment|/* define this if you want diagnostics in telnetd */
end_comment

begin_define
define|#
directive|define
name|DIAGNOSTICS
value|1
end_define

begin_comment
comment|/* define this if you want support for broken ENV_{VALUE,VAR} systems  */
end_comment

begin_comment
comment|/* #undef ENV_HACK */
end_comment

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OLD_ENVIRON
value|1
end_define

begin_comment
comment|/* Used with login -p */
end_comment

begin_comment
comment|/* #undef LOGIN_ARGS */
end_comment

begin_comment
comment|/* set this to a sensible login */
end_comment

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

begin_comment
comment|/* ------------------------------------------------------------ */
end_comment

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

begin_comment
comment|/* Temporary fixes for krb_{rd,mk}_safe */
end_comment

begin_define
define|#
directive|define
name|DES_QUAD_GUESS
value|0
end_define

begin_define
define|#
directive|define
name|DES_QUAD_NEW
value|1
end_define

begin_define
define|#
directive|define
name|DES_QUAD_OLD
value|2
end_define

begin_comment
comment|/*  * All these are system-specific defines that I would rather not have at all.  */
end_comment

begin_comment
comment|/*  * AIX braindamage!  */
end_comment

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

begin_comment
comment|/* XXX this is gross, but kills about a gazillion warnings */
end_comment

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
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|sgi
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SYSTYPE_SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|_SYSTYPE_SVR4
argument_list|)
end_if

begin_define
define|#
directive|define
name|IRIX
value|5
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IRIX
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX 4 braindamage */
end_comment

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

begin_comment
comment|/*  * Defining this enables lots of useful (and used) extensions on  * glibc-based systems such as Linux  */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_comment
comment|/* some strange OS/2 stuff.  From<d96-mst@nada.kth.se> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

begin_define
define|#
directive|define
name|_EMX_TCPIP
end_define

begin_define
define|#
directive|define
name|MAIL_USE_SYSTEM_LOCK
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

end_unit

