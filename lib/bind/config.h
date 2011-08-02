begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated from configure.in by autoheader.  */
end_comment

begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2008  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: acconfig.h,v 1.44.18.7 2008-12-01 23:45:56 tbox Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_comment
comment|/***  *** This file is not to be included by any public header files, because  *** it does not get installed.  ***/
end_comment

begin_comment
comment|/** define on DEC OSF to enable 4.4BSD style sa_len support */
end_comment

begin_comment
comment|/* #undef _SOCKADDR_LEN */
end_comment

begin_comment
comment|/** define if your system needs pthread_init() before using pthreads */
end_comment

begin_comment
comment|/* #undef NEED_PTHREAD_INIT */
end_comment

begin_comment
comment|/** define if your system has sigwait() */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGWAIT
value|1
end_define

begin_comment
comment|/** define if sigwait() is the UnixWare flavor */
end_comment

begin_comment
comment|/* #undef HAVE_UNIXWARE_SIGWAIT */
end_comment

begin_comment
comment|/** define on Solaris to get sigwait() to work using pthreads semantics */
end_comment

begin_comment
comment|/* #undef _POSIX_PTHREAD_SEMANTICS */
end_comment

begin_comment
comment|/** define if LinuxThreads is in use */
end_comment

begin_comment
comment|/* #undef HAVE_LINUXTHREADS */
end_comment

begin_comment
comment|/** define if sysconf() is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/** define if sysctlbyname() is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCTLBYNAME
value|1
end_define

begin_comment
comment|/** define if catgets() is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_CATGETS
value|1
end_define

begin_comment
comment|/** define if getifaddrs() exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIFADDRS
value|1
end_define

begin_comment
comment|/** define if you have the NET_RT_IFLIST sysctl variable and sys/sysctl.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_IFLIST_SYSCTL
value|1
end_define

begin_comment
comment|/** define if tzset() is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_TZSET
value|1
end_define

begin_comment
comment|/** define if struct addrinfo exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_ADDRINFO
value|1
end_define

begin_comment
comment|/** define if getaddrinfo() exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/** define if gai_strerror() exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAISTRERROR
value|1
end_define

begin_comment
comment|/** define if arc4random() exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARC4RANDOM
value|1
end_define

begin_comment
comment|/**  * define if pthread_setconcurrency() should be called to tell the  * OS how many threads we might want to run.  */
end_comment

begin_comment
comment|/* #undef CALL_PTHREAD_SETCONCURRENCY */
end_comment

begin_comment
comment|/** define if IPv6 is not disabled */
end_comment

begin_comment
comment|/* #undef WANT_IPV6 */
end_comment

begin_comment
comment|/** define if flockfile() is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOCKFILE
value|1
end_define

begin_comment
comment|/** define if getc_unlocked() is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCUNLOCKED
value|1
end_define

begin_comment
comment|/** Shut up warnings about sputaux in stdio.h on BSD/OS pre-4.1 */
end_comment

begin_comment
comment|/* #undef SHUTUP_SPUTAUX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SHUTUP_SPUTAUX
end_ifdef

begin_struct_decl
struct_decl|struct
name|__sFILE
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|__inline
name|int
name|__sputaux
parameter_list|(
name|int
name|_c
parameter_list|,
name|struct
name|__sFILE
modifier|*
name|_p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Shut up warnings about missing sigwait prototype on BSD/OS 4.0* */
end_comment

begin_comment
comment|/* #undef SHUTUP_SIGWAIT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SHUTUP_SIGWAIT
end_ifdef

begin_function_decl
name|int
name|sigwait
parameter_list|(
specifier|const
name|unsigned
name|int
modifier|*
name|set
parameter_list|,
name|int
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Shut up warnings from gcc -Wcast-qual on BSD/OS 4.1. */
end_comment

begin_comment
comment|/* #undef SHUTUP_STDARG_CAST */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SHUTUP_STDARG_CAST
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/** Grr.  Must be included *every time*. */
end_comment

begin_comment
comment|/**  * The silly continuation line is to keep configure from  * commenting out the #undef.  */
end_comment

begin_undef
undef|#
directive|undef
undef|\
name|va_start
end_undef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|last
parameter_list|)
define|\
value|do { \ 		union { const void *konst; long *var; } _u; \ 		_u.konst =&(last); \ 		ap = (va_list)(_u.var + __va_words(__typeof(last))); \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** SHUTUP_STDARG_CAST&& __GNUC__ */
end_comment

begin_comment
comment|/** define if the system has a random number generating device */
end_comment

begin_define
define|#
directive|define
name|PATH_RANDOMDEV
value|"/dev/random"
end_define

begin_comment
comment|/** define if pthread_attr_getstacksize() is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_ATTR_GETSTACKSIZE
value|1
end_define

begin_comment
comment|/** define if pthread_attr_setstacksize() is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_ATTR_SETSTACKSIZE
value|1
end_define

begin_comment
comment|/** define if you have strerror in the C library. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/** Define if you are running under Compaq TruCluster. */
end_comment

begin_comment
comment|/* #undef HAVE_TRUCLUSTER */
end_comment

begin_comment
comment|/* Define if OpenSSL includes DSA support */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_DSA
value|1
end_define

begin_comment
comment|/* Define to the length type used by the socket API (socklen_t, size_t, int). */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKADDR_LEN_T
value|socklen_t
end_define

begin_comment
comment|/* Define if threads need PTHREAD_SCOPE_SYSTEM */
end_comment

begin_comment
comment|/* #undef NEED_PTHREAD_SCOPE_SYSTEM */
end_comment

begin_comment
comment|/* Define if recvmsg() does not meet all of the BSD socket API specifications.    */
end_comment

begin_comment
comment|/* #undef BROKEN_RECVMSG */
end_comment

begin_comment
comment|/* Define if you cannot bind() before connect() for TCP sockets. */
end_comment

begin_comment
comment|/* #undef BROKEN_TCP_BIND_BEFORE_CONNECT */
end_comment

begin_comment
comment|/* Solaris hack to get select_large_fdset. */
end_comment

begin_comment
comment|/* #undef FD_SETSIZE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `capset' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CAPSET */
end_comment

begin_comment
comment|/* Define to 1 if you have the `chroot' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHROOT
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
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
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
comment|/* Define to 1 if you have the `c' library (-lc). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBC */
end_comment

begin_comment
comment|/* Define to 1 if you have the `c_r' library (-lc_r). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBC_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the `nsl' library (-lnsl). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNSL */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pthread' library (-lpthread). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBPTHREAD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `scf' library (-lscf). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSCF */
end_comment

begin_comment
comment|/* Define to 1 if you have the `socket' library (-lsocket). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

begin_comment
comment|/* Define to 1 if you have the `thr' library (-lthr). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBTHR */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linux/capability.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_CAPABILITY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<locale.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
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
comment|/* Define to 1 if you have the `nanosleep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NANOSLEEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<net/if6.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NET_IF6_H */
end_comment

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
comment|/* Define to 1 if you have the<sys/capability.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CAPABILITY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/devpoll.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DEVPOLL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/dyntune.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DYNTUNE_H */
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
comment|/* Define to 1 if you have the<sys/prctl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PRCTL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/select.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sockio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKIO_H
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
comment|/* Define to 1 if you have the<sys/sysctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCTL_H
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
comment|/* Define to 1 if you have the<sys/un.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UN_H
value|1
end_define

begin_comment
comment|/* Define if running under Compaq TruCluster */
end_comment

begin_comment
comment|/* #undef HAVE_TRUCLUSTER */
end_comment

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
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment

begin_define
define|#
directive|define
name|LT_OBJDIR
value|".libs/"
end_define

begin_comment
comment|/* Defined if extern char *optarg is not declared. */
end_comment

begin_comment
comment|/* #undef NEED_OPTARG */
end_comment

begin_comment
comment|/* Define if connect does not honour the permission on the UNIX domain socket.    */
end_comment

begin_comment
comment|/* #undef NEED_SECURE_DIRECTORY */
end_comment

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|""
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|""
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|""
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|""
end_define

begin_comment
comment|/* Sets which flag to pass to open/fcntl to make non-blocking    (O_NDELAY/O_NONBLOCK). */
end_comment

begin_define
define|#
directive|define
name|PORT_NONBLOCK
value|O_NONBLOCK
end_define

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
comment|/* Defined if you need to use ioctl(FIONBIO) instead a fcntl call to make    non-blocking. */
end_comment

begin_comment
comment|/* #undef USE_FIONBIO_IOCTL */
end_comment

begin_comment
comment|/* define if idnkit support is to be included. */
end_comment

begin_comment
comment|/* #undef WITH_IDN */
end_comment

begin_comment
comment|/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most    significant byte first (like Motorola and SPARC, unlike Intel and VAX). */
end_comment

begin_if
if|#
directive|if
name|defined
name|__BIG_ENDIAN__
end_if

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
value|1
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
name|__LITTLE_ENDIAN__
end_elif

begin_comment
comment|/* # undef WORDS_BIGENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_define
define|#
directive|define
name|inline
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef ssize_t */
end_comment

begin_comment
comment|/* Define to `unsigned long' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef uintptr_t */
end_comment

begin_comment
comment|/* Define to empty if the keyword `volatile' does not work. Warning: valid    code using `volatile' can become incorrect without. Disable with care. */
end_comment

begin_comment
comment|/* #undef volatile */
end_comment

end_unit

