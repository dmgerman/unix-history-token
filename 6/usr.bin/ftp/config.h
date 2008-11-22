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
comment|/* $Id: config.h.in,v 1.24 2000/09/18 00:40:12 lukem Exp $ */
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
comment|/* Define if the closedir function returns void instead of int.  */
end_comment

begin_comment
comment|/* #undef CLOSEDIR_VOID */
end_comment

begin_comment
comment|/* Define if the `getpgrp' function takes no argument.  */
end_comment

begin_define
define|#
directive|define
name|GETPGRP_VOID
value|1
end_define

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
comment|/* Define if you have the fparseln function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FPARSELN
value|1
end_define

begin_comment
comment|/* Define if you have the fseeko function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSEEKO
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
comment|/* Define if you have the gethostbyname2 function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME2
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
comment|/* Define if you have the getpassphrase function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETPASSPHRASE */
end_comment

begin_comment
comment|/* Define if you have the getpgrp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPGRP
value|1
end_define

begin_comment
comment|/* Define if you have the glob function.  */
end_comment

begin_define
define|#
directive|define
name|USE_GLOB_H
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
comment|/* Define if you have the issetugid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISSETUGID
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
comment|/* Define if you have the poll function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL
value|1
end_define

begin_comment
comment|/* Define if you have the select function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_comment
comment|/* Define if you have the setprogname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPROGNAME
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
comment|/* Define if you have the strtoll function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOLL
value|1
end_define

begin_comment
comment|/* Define if you have the strunvis function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUNVIS
value|1
end_define

begin_comment
comment|/* Define if you have the strvis function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRVIS
value|1
end_define

begin_comment
comment|/* Define if you have the timegm function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEGM
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
comment|/* Define if you have the<poll.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<regex.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGEX_H
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
comment|/* Define if you have the<sys/poll.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_POLL_H
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
comment|/* Define if you have the<util.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_UTIL_H */
end_comment

begin_comment
comment|/* Define if you have the<vis.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VIS_H
value|1
end_define

begin_comment
comment|/* Define if you have the nsl library (-lnsl).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNSL */
end_comment

begin_comment
comment|/* Define if you have the socket library (-lsocket).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

begin_comment
comment|/* Define if you have the tinfo library (-ltinfo).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBTINFO
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
comment|/* Define if your compiler supports `long long' */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
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
comment|/* Define if sa_family_t exists in<sys/socket.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_FAMILY_T
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
comment|/* Define if GLOB_BRACE exists in<glob.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_GLOB_BRACE
value|1
end_define

begin_comment
comment|/* Define if h_errno exists in<netdb.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_ERRNO_D
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
comment|/* Define if getpass() is declared in<stdlib.h> or<unistd.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPASS_D
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
comment|/* Define if pclose() is declared in<stdio.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_PCLOSE_D
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
comment|/* Define if strptime() is declared in<time.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRPTIME_D
value|1
end_define

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

end_unit

