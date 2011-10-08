begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* tnftp_config.h.  Generated from tnftp_config.h.in by configure.  */
end_comment

begin_comment
comment|/* tnftp_config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Define to 1 if the `closedir' function returns void instead of `int'. */
end_comment

begin_comment
comment|/* #undef CLOSEDIR_VOID */
end_comment

begin_comment
comment|/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP    systems. This function is required for `alloca.c' support on those systems.    */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define to 1 if using `alloca.c'. */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to 1 if the `getpgrp' function requires zero arguments. */
end_comment

begin_define
define|#
directive|define
name|GETPGRP_VOID
value|1
end_define

begin_comment
comment|/* Define to 1 if `TIOCGWINSZ' requires<sys/ioctl.h>. */
end_comment

begin_comment
comment|/* #undef GWINSZ_IN_SYS_IOCTL */
end_comment

begin_comment
comment|/* Define to 1 if you have `alloca', as a function or macro. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define to 1 if you have<alloca.h> and it should be used (not on Ultrix).    */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<arpa/ftp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_FTP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<arpa/inet.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_INET_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<arpa/nameser.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_NAMESER_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `AF_INET6', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_AF_INET6
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `AI_NUMERICHOST', and to 0 if    you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_AI_NUMERICHOST
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `dirname', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_DIRNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `fclose', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FCLOSE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `getpass', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETPASS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `h_errno', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_H_ERRNO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `NS_IN6ADDRSZ', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_NS_IN6ADDRSZ
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `optarg', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_OPTARG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `optind', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_OPTIND
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `pclose', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_PCLOSE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strptime', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRPTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dirent.h> header file, and it defines `DIR'.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `dirname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `err' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<err.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fgetln' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FGETLN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSEEKO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getaddrinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getcwd' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gethostbyaddr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYADDR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gethostbyname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gethostbyname2' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME2
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gethostname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getnameinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETNAMEINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpass' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPASS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpassphrase' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPASSPHRASE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getpgrp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPGRP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gettimeofday' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `inet_ntop' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_NTOP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `inet_pton' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_PTON
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `in_port_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IN_PORT_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `isascii' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISASCII
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<libgen.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBGEN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `long double'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_DOUBLE
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `long long int'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG_INT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<malloc.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `memchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `memmove' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `memset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mkstemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ndir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netdb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/in.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/in_systm.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_SYSTM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/ip.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<paths.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PATHS_H
value|1
end_define

begin_comment
comment|/* Define if we have poll() and it is not emulated. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_comment
comment|/* Define if `long long' is supported and *printf() supports %lld or %qd to    print them. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRINTF_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if *printf() uses %qd to print `long long' (otherwise uses %lld). */
end_comment

begin_comment
comment|/* #undef HAVE_PRINTF_QD */
end_comment

begin_comment
comment|/* Define to 1 if you have the<pwd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `realpath' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REALPATH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `regcomp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGCOMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<regex.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGEX_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<resolv.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESOLV_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `sa_family_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_FAMILY_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `select' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<setjmp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETJMP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setlocale' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setprogname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPROGNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<signal.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGNAL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sl_init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SL_INIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `snprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `socket' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKET
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `socklen_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKLEN_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stddef.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strcasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strcoll' function and it is properly defined.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCOLL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strcspn' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCSPN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strncasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strpbrk' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRPBRK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strptime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRPTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strrchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRRCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strsep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strstr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtol' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtoll' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOLL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtoul' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct addrinfo'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_ADDRINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if `struct dirent' is a member of `d_namlen'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_DIRENT_D_NAMLEN
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct pollfd'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_POLLFD
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct sockaddr_in6'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_IN6
value|1
end_define

begin_comment
comment|/* Define to 1 if `struct sockaddr_in' is a member of `sin_len'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_IN_SIN_LEN
value|1
end_define

begin_comment
comment|/* Define to 1 if `struct sockaddr' is a member of `sa_len'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_SA_LEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strunvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUNVIS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRVIS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/dir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ioctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ndir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_POLL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/socket.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKET_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/syslimits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSLIMITS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/wait.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termcap.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMCAP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `timegm' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEGM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `usleep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_USLEEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `utime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `utimes' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIMES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<utime.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `vfork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFORK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<vfork.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<vis.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VIS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if `fork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if `vfork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_VFORK
value|1
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"tnftp"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"lukem@NetBSD.org"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"tnftp"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"tnftp 20100108"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"tnftp"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"20100108"
end_define

begin_comment
comment|/* Define as the return type of signal handlers (`int' or `void'). */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at runtime. 	STACK_DIRECTION> 0 => grows toward higher addresses 	STACK_DIRECTION< 0 => grows toward lower addresses 	STACK_DIRECTION = 0 => direction of growth unknown */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define to 1 if the `S_IS*' macros in<sys/stat.h> do not work properly. */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define to 1 if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to 1 if your<sys/time.h> declares `struct tm'. */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define if using (Dante) SOCKS5 proxy. */
end_comment

begin_comment
comment|/* #undef USE_SOCKS */
end_comment

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"20100108"
end_define

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
end_comment

begin_comment
comment|/* #undef _LARGEFILE_SOURCE */
end_comment

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* Define for Solaris 2.5.1 so the uint32_t typedef from<sys/synch.h>,<pthread.h>, or<semaphore.h> is not used. If the typedef were allowed, the    #define below would cause a syntax error. */
end_comment

begin_comment
comment|/* #undef _UINT32_T */
end_comment

begin_comment
comment|/* Define to `long int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type of width exactly 32 bits if    such a type exists and the standard includes do not define it. */
end_comment

begin_comment
comment|/* #undef uint32_t */
end_comment

begin_comment
comment|/* Define as `fork' if `vfork' does not work. */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Define if using IPv6 support. */
end_comment

begin_comment
comment|/* Commented out so this can be selected fromt he Makefile -gavin */
end_comment

begin_comment
comment|/* #define USE_INET6 1 */
end_comment

begin_define
define|#
directive|define
name|USE_GLOB_H
value|1
end_define

end_unit

