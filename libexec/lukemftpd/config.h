begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* $Id: config.h.in,v 1.15 2001/04/28 07:11:46 lukem Exp $ */
end_comment

begin_comment
comment|/* Define if the closedir function returns void instead of int.  */
end_comment

begin_comment
comment|/* #undef CLOSEDIR_VOID */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define if your C compiler doesn't accept -c and -o together.  */
end_comment

begin_comment
comment|/* #undef NO_MINUS_C_MINUS_O */
end_comment

begin_comment
comment|/* Define if your Fortran 77 compiler doesn't accept -c and -o together. */
end_comment

begin_comment
comment|/* #undef F77_NO_MINUS_C_MINUS_O */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to the type of arg1 for select(). */
end_comment

begin_comment
comment|/* #undef SELECT_TYPE_ARG1 */
end_comment

begin_comment
comment|/* Define to the type of args 2, 3 and 4 for select(). */
end_comment

begin_comment
comment|/* #undef SELECT_TYPE_ARG234 */
end_comment

begin_comment
comment|/* Define to the type of arg5 for select(). */
end_comment

begin_comment
comment|/* #undef SELECT_TYPE_ARG5 */
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
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define if the closedir function returns void instead of int.  */
end_comment

begin_comment
comment|/* #undef VOID_CLOSEDIR */
end_comment

begin_comment
comment|/* The number of bytes in a off_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_OFF_T
value|0
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
comment|/* Define if you have the fgetln function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FGETLN
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
comment|/* Define if you have the fparseln function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FPARSELN
value|1
end_define

begin_comment
comment|/* Define if you have the fts_open function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTS_OPEN
value|1
end_define

begin_comment
comment|/* Define if you have the getaddrinfo function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/* Define if you have the getgrouplist function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGROUPLIST
value|1
end_define

begin_comment
comment|/* Define if you have the getnameinfo function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETNAMEINFO
value|1
end_define

begin_comment
comment|/* Define if you have the getspnam function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETSPNAM */
end_comment

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
comment|/* Define if you have the inet_net_pton function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_NET_PTON
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
comment|/* Define if you have the lockf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCKF
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
comment|/* Define if you have the setlogin function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOGIN
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
comment|/* Define if you have the sl_init function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SL_INIT
value|1
end_define

begin_comment
comment|/* Define if you have the snprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
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
comment|/* Define if you have the strmode function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRMODE
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
comment|/* Define if you have the strtoll function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOLL
value|1
end_define

begin_comment
comment|/* Define if you have the user_from_uid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_USER_FROM_UID
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
comment|/* Define if you have the vfork function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFORK
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
comment|/* Define if you have the<arpa/nameser.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_NAMESER_H
value|1
end_define

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
comment|/* Define if you have the<fts.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTS_H
value|1
end_define

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
comment|/* Define if you have the<sys/dir.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_DIR_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/sysmacros.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SYSMACROS_H */
end_comment

begin_comment
comment|/* Define if you have the<util.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_UTIL_H */
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
comment|/* Define if you have the skey library (-lskey).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSKEY */
end_comment

begin_comment
comment|/* Define if you have the socket library (-lsocket).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

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
comment|/* Define if your compiler supports `long long' */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if *printf() uses %qd to print `long long' (otherwise uses %lld) */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRINTF_QD
value|1
end_define

begin_comment
comment|/* Define if in_port_t exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_IN_PORT_T
value|1
end_define

begin_comment
comment|/* Define if struct sockaddr.sa_len exists (implies sockaddr_in.sin_len, etc) */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKADDR_SA_LEN
value|1
end_define

begin_comment
comment|/* Define if socklen_t exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKLEN_T
value|1
end_define

begin_comment
comment|/* Define if AF_INET6 exists in<sys/socket.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_AF_INET6
value|1
end_define

begin_comment
comment|/* Define if `struct sockaddr_in6' exists in<netinet/in.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKADDR_IN6
value|1
end_define

begin_comment
comment|/* Define if `struct addrinfo' exists in<netdb.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_ADDRINFO
value|1
end_define

begin_comment
comment|/*  * Define if<netdb.h> contains AI_NUMERICHOST et al.  * Systems which only implement RFC2133 will need this.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RFC2553_NETDB
value|1
end_define

begin_comment
comment|/* Define if `struct direct' has a d_namlen element */
end_comment

begin_define
define|#
directive|define
name|HAVE_D_NAMLEN
value|1
end_define

begin_comment
comment|/* Define if struct passwd.pw_expire exists. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PW_EXPIRE
value|1
end_define

begin_comment
comment|/* Define if GLOB_BRACE, gl_path and gl_match exist in<glob.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_GLOB
value|1
end_define

begin_comment
comment|/* Define if crypt() is declared in<unistd.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_CRYPT_D
value|1
end_define

begin_comment
comment|/* Define if fclose() is declared in<stdio.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCLOSE_D
value|1
end_define

begin_comment
comment|/* Define if optarg is declared in<stdlib.h> or<unistd.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTARG_D
value|1
end_define

begin_comment
comment|/* Define if optind is declared in<stdlib.h> or<unistd.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTIND_D
value|1
end_define

begin_comment
comment|/* Define if optreset exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTRESET
value|1
end_define

begin_comment
comment|/* Define if pclose() is declared in<stdio.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_PCLOSE_D
value|1
end_define

begin_comment
comment|/* Define if getusershell() is declared in<unistd.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUSERSHELL_D
value|1
end_define

begin_comment
comment|/* Define if `long long' is supported and sizeof(off_t)>= 8 */
end_comment

begin_define
define|#
directive|define
name|HAVE_QUAD_SUPPORT
value|1
end_define

begin_comment
comment|/* Define if not using in-built /bin/ls code */
end_comment

begin_comment
comment|/* #undef NO_INTERNAL_LS */
end_comment

begin_comment
comment|/* Define if using S/Key */
end_comment

begin_comment
comment|/* #undef SKEY */
end_comment

begin_comment
comment|/*  * Define this if compiling with SOCKS (the firewall traversal library).  * Also, you must define connect, getsockname, bind, accept, listen, and  * select to their R-versions.  */
end_comment

begin_comment
comment|/* #undef	SOCKS */
end_comment

begin_comment
comment|/* #undef	SOCKS4 */
end_comment

begin_comment
comment|/* #undef	SOCKS5 */
end_comment

begin_comment
comment|/* #undef	connect */
end_comment

begin_comment
comment|/* #undef	getsockname */
end_comment

begin_comment
comment|/* #undef	bind */
end_comment

begin_comment
comment|/* #undef	accept */
end_comment

begin_comment
comment|/* #undef	listen */
end_comment

begin_comment
comment|/* #undef	select */
end_comment

begin_comment
comment|/* #undef	dup */
end_comment

begin_comment
comment|/* #undef	dup2 */
end_comment

begin_comment
comment|/* #undef	fclose */
end_comment

begin_comment
comment|/* #undef	gethostbyname */
end_comment

begin_comment
comment|/* #undef	getpeername */
end_comment

begin_comment
comment|/* #undef	read */
end_comment

begin_comment
comment|/* #undef	recv */
end_comment

begin_comment
comment|/* #undef	recvfrom */
end_comment

begin_comment
comment|/* #undef	rresvport */
end_comment

begin_comment
comment|/* #undef	send */
end_comment

begin_comment
comment|/* #undef	sendto */
end_comment

begin_comment
comment|/* #undef	shutdown */
end_comment

begin_comment
comment|/* #undef	write */
end_comment

begin_comment
comment|/* Define if you have the<arpa/ftp.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTP_NAMES
value|1
end_define

end_unit

