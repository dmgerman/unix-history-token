begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if on AIX 3.    System headers sometimes define this.    We just want to avoid a redefinition error message.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_comment
comment|/* #undef _ALL_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Define if you have<sys/wait.h> that is POSIX.1 compatible.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if on MINIX.  */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define if the system does not provide POSIX.1 features except    with this defined.  */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
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
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.  STACK_DIRECTION> 0 => grows toward higher addresses  STACK_DIRECTION< 0 => grows toward lower addresses  STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define if you want the FTP daemon to support anonymous logins. */
end_comment

begin_comment
comment|/* #undef DOANONYMOUS */
end_comment

begin_comment
comment|/* The default value of the PATH environment variable */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PATH
value|"/usr/bin:/bin:/usr/sbin:/sbin:/usr/X11R6/bin"
end_define

begin_comment
comment|/* Defined if the file /etc/default/login exists     (and, presumably, should be looked at by login) */
end_comment

begin_comment
comment|/* #undef HAVE_ETC_DEFAULT_LOGIN */
end_comment

begin_comment
comment|/* Defined to the name of a file that contains a list of files whose    permissions and ownerships should be changed on login. */
end_comment

begin_comment
comment|/* #undef HAVE_LOGIN_PERMFILE */
end_comment

begin_comment
comment|/* Defined to the name of a file that contains a list of environment    values that should be set on login. */
end_comment

begin_comment
comment|/* #undef HAVE_LOGIN_ENVFILE */
end_comment

begin_comment
comment|/* Defined if the file /etc/securetty exists    (and, presumably, should be looked at by login) */
end_comment

begin_comment
comment|/* #undef HAVE_SECURETTY */
end_comment

begin_comment
comment|/* Defined if the file /etc/shadow exists    (and, presumably, should be looked at for shadow passwords) */
end_comment

begin_comment
comment|/* #undef HAVE_ETC_SHADOW */
end_comment

begin_comment
comment|/* The path to the access file, if we're going to use it */
end_comment

begin_comment
comment|/* #undef PATH_ACCESS_FILE */
end_comment

begin_comment
comment|/* The path to the mail spool, if we know it */
end_comment

begin_define
define|#
directive|define
name|PATH_MAIL
value|"/var/mail"
end_define

begin_comment
comment|/* The path to the utmp file, if we know it */
end_comment

begin_define
define|#
directive|define
name|PATH_UTMP_AC
value|"/var/run/utmp"
end_define

begin_comment
comment|/* The path to the wtmp file, if we know it */
end_comment

begin_define
define|#
directive|define
name|PATH_WTMP_AC
value|"/var/log/wtmp"
end_define

begin_comment
comment|/* The path to the wtmpx file, if we know it */
end_comment

begin_comment
comment|/* #undef PATH_WTMPX_AC */
end_comment

begin_comment
comment|/* Defined if the system's profile (/etc/profile) displays    the motd file */
end_comment

begin_comment
comment|/* #undef HAVE_MOTD_IN_PROFILE */
end_comment

begin_comment
comment|/* Defined if the system's profile (/etc/profile) informs the    user of new mail */
end_comment

begin_comment
comment|/* #undef HAVE_MAILCHECK_IN_PROFILE */
end_comment

begin_comment
comment|/* Define if you have a nonstandard gettimeofday() that takes one argument    instead of two. */
end_comment

begin_comment
comment|/* #undef HAVE_ONE_ARG_GETTIMEOFDAY */
end_comment

begin_comment
comment|/* Define if the system has the getenv function */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETENV
value|1
end_define

begin_comment
comment|/* Define if the system has the setenv function */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if the system has the /var/adm/sulog file */
end_comment

begin_comment
comment|/* #undef HAVE_SULOG */
end_comment

begin_comment
comment|/* Define if the system has the unsetenv function */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSETENV
value|1
end_define

begin_comment
comment|/* Define if the compiler can handle ANSI-style argument lists */
end_comment

begin_define
define|#
directive|define
name|HAVE_ANSIDECL
value|1
end_define

begin_comment
comment|/* Define if the compiler can handle ANSI-style prototypes */
end_comment

begin_define
define|#
directive|define
name|HAVE_ANSIPROTO
value|1
end_define

begin_comment
comment|/* Define if the system has an ANSI-style printf (returns int instead of char *) */
end_comment

begin_define
define|#
directive|define
name|HAVE_ANSISPRINTF
value|1
end_define

begin_comment
comment|/* Define if the compiler can handle ANSI-style variable argument lists */
end_comment

begin_define
define|#
directive|define
name|HAVE_ANSISTDARG
value|1
end_define

begin_comment
comment|/* Define if the compiler can handle void argument lists to functions */
end_comment

begin_define
define|#
directive|define
name|HAVE_VOIDARG
value|1
end_define

begin_comment
comment|/* Define if the compiler can handle void return "values" from functions */
end_comment

begin_define
define|#
directive|define
name|HAVE_VOIDRET
value|1
end_define

begin_comment
comment|/* Define if the compiler can handle void pointers to our liking */
end_comment

begin_define
define|#
directive|define
name|HAVE_VOIDPTR
value|1
end_define

begin_comment
comment|/* Define if the /bin/ls command seems to support the -g flag */
end_comment

begin_comment
comment|/* #undef HAVE_LS_G_FLAG */
end_comment

begin_comment
comment|/* Define if there is a ut_pid field in struct utmp */
end_comment

begin_comment
comment|/* #undef HAVE_UT_PID */
end_comment

begin_comment
comment|/* Define if there is a ut_type field in struct utmp */
end_comment

begin_comment
comment|/* #undef HAVE_UT_TYPE */
end_comment

begin_comment
comment|/* Define if there is a ut_name field in struct utmp */
end_comment

begin_define
define|#
directive|define
name|HAVE_UT_NAME
value|1
end_define

begin_comment
comment|/* Define if there is a ut_host field in struct utmp */
end_comment

begin_define
define|#
directive|define
name|HAVE_UT_HOST
value|1
end_define

begin_comment
comment|/* Define if the system has getutline() */
end_comment

begin_comment
comment|/* #undef HAVE_GETUTLINE */
end_comment

begin_comment
comment|/* Defined if the system has SunOS C2 security shadow passwords */
end_comment

begin_comment
comment|/* #undef HAVE_SUNOS_C2_SHADOW */
end_comment

begin_comment
comment|/* Defined if you want to disable utmp support */
end_comment

begin_comment
comment|/* #undef DISABLE_UTMP */
end_comment

begin_comment
comment|/* Defined if you want to allow users to override the insecure checks */
end_comment

begin_comment
comment|/* #undef INSECURE_OVERRIDE */
end_comment

begin_comment
comment|/* Defined to the default hash value, always defined */
end_comment

begin_define
define|#
directive|define
name|MDX
value|5
end_define

begin_comment
comment|/* Defined if new-style prompts are to be used */
end_comment

begin_define
define|#
directive|define
name|NEW_PROMPTS
value|1
end_define

begin_comment
comment|/* Defined to the path of the OPIE lock directory */
end_comment

begin_define
define|#
directive|define
name|OPIE_LOCK_DIR
value|"/etc/opielocks"
end_define

begin_comment
comment|/* Defined if users are to be asked to re-type secret pass phrases */
end_comment

begin_comment
comment|/* #undef RETYPE */
end_comment

begin_comment
comment|/* Defined if su should not switch to disabled accounts */
end_comment

begin_comment
comment|/* #undef SU_STAR_CHECK */
end_comment

begin_comment
comment|/* Defined if user locking is to be used */
end_comment

begin_define
define|#
directive|define
name|USER_LOCKING
value|1
end_define

begin_comment
comment|/* Define if you have the bcopy function.  */
end_comment

begin_comment
comment|/* #undef HAVE_BCOPY */
end_comment

begin_comment
comment|/* Define if you have the bzero function.  */
end_comment

begin_comment
comment|/* #undef HAVE_BZERO */
end_comment

begin_comment
comment|/* Define if you have the endspent function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ENDSPENT */
end_comment

begin_comment
comment|/* Define if you have the fpurge function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FPURGE
value|1
end_define

begin_comment
comment|/* Define if you have the getdtablesize function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETDTABLESIZE */
end_comment

begin_comment
comment|/* Define if you have the getgroups function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
value|1
end_define

begin_comment
comment|/* Define if you have the gethostname function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETHOSTNAME */
end_comment

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
comment|/* Define if you have the getttynam function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTTYNAM
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
comment|/* Define if you have the getutxline function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETUTXLINE */
end_comment

begin_comment
comment|/* Define if you have the getwd function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETWD */
end_comment

begin_comment
comment|/* Define if you have the index function.  */
end_comment

begin_comment
comment|/* #undef HAVE_INDEX */
end_comment

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
comment|/* Define if you have the on_exit function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ON_EXIT */
end_comment

begin_comment
comment|/* Define if you have the pututxline function.  */
end_comment

begin_comment
comment|/* #undef HAVE_PUTUTXLINE */
end_comment

begin_comment
comment|/* Define if you have the rindex function.  */
end_comment

begin_comment
comment|/* #undef HAVE_RINDEX */
end_comment

begin_comment
comment|/* Define if you have the setgroups function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETGROUPS
value|1
end_define

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
comment|/* Define if you have the setpriority function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPRIORITY
value|1
end_define

begin_comment
comment|/* Define if you have the setregid function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SETREGID */
end_comment

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

begin_comment
comment|/* #undef HAVE_SETREUID */
end_comment

begin_comment
comment|/* Define if you have the setvbuf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETVBUF
value|1
end_define

begin_comment
comment|/* Define if you have the sigaddset function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGADDSET
value|1
end_define

begin_comment
comment|/* Define if you have the sigblock function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SIGBLOCK */
end_comment

begin_comment
comment|/* Define if you have the sigemptyset function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGEMPTYSET
value|1
end_define

begin_comment
comment|/* Define if you have the sigsetmask function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SIGSETMASK */
end_comment

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
comment|/* Define if you have the strncasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the strstr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
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
comment|/* Define if you have the usleep function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_USLEEP
value|1
end_define

begin_comment
comment|/* Define if you have the<crypt.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_CRYPT_H */
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
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<lastlog.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LASTLOG_H */
end_comment

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
comment|/* Define if you have the<ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

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
comment|/* Define if you have the<pwd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_comment
comment|/* Define if you have the<shadow.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SHADOW_H */
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
comment|/* Define if you have the<stdlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/dir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
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
comment|/* Define if you have the<sys/ioctl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

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
comment|/* Define if you have the<sys/select.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/signal.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGNAL_H
value|1
end_define

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
comment|/* Define if you have the<sys/utsname.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UTSNAME_H
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
comment|/* Define if you have the<termios.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

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
comment|/* Define if you have the<utmpx.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_UTMPX_H */
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
comment|/* Define if you have the nsl library (-lnsl).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNSL */
end_comment

begin_comment
comment|/* Define if you have the posix library (-lposix).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBPOSIX */
end_comment

begin_comment
comment|/* Define if you have the socket library (-lsocket).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

end_unit

