begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: acconfig.h,v 1.35.2.4.2.10 2004/12/04 06:50:02 marka Exp $ */
end_comment

begin_comment
comment|/***  *** This file is not to be included by any public header files, because  *** it does not get installed.  ***/
end_comment

begin_expr_stmt
unit|@
name|TOP
expr|@
comment|/* define to `int' if<sys/types.h> doesn't define.  */
undef|#
directive|undef
name|ssize_t
comment|/* define on DEC OSF to enable 4.4BSD style sa_len support */
undef|#
directive|undef
name|_SOCKADDR_LEN
comment|/* define if your system needs pthread_init() before using pthreads */
undef|#
directive|undef
name|NEED_PTHREAD_INIT
comment|/* define if your system has sigwait() */
undef|#
directive|undef
name|HAVE_SIGWAIT
comment|/* define if sigwait() is the UnixWare flavor */
undef|#
directive|undef
name|HAVE_UNIXWARE_SIGWAIT
comment|/* define on Solaris to get sigwait() to work using pthreads semantics */
undef|#
directive|undef
name|_POSIX_PTHREAD_SEMANTICS
comment|/* define if LinuxThreads is in use */
undef|#
directive|undef
name|HAVE_LINUXTHREADS
comment|/* define if sysconf() is available */
undef|#
directive|undef
name|HAVE_SYSCONF
comment|/* define if sysctlbyname() is available */
undef|#
directive|undef
name|HAVE_SYSCTLBYNAME
comment|/* define if catgets() is available */
undef|#
directive|undef
name|HAVE_CATGETS
comment|/* define if getifaddrs() exists */
undef|#
directive|undef
name|HAVE_GETIFADDRS
comment|/* define if you have the NET_RT_IFLIST sysctl variable and sys/sysctl.h */
undef|#
directive|undef
name|HAVE_IFLIST_SYSCTL
comment|/* define if chroot() is available */
undef|#
directive|undef
name|HAVE_CHROOT
comment|/* define if tzset() is available */
undef|#
directive|undef
name|HAVE_TZSET
comment|/* define if struct addrinfo exists */
undef|#
directive|undef
name|HAVE_ADDRINFO
comment|/* define if getaddrinfo() exists */
undef|#
directive|undef
name|HAVE_GETADDRINFO
comment|/* define if gai_strerror() exists */
undef|#
directive|undef
name|HAVE_GAISTRERROR
comment|/* define if arc4random() exists */
undef|#
directive|undef
name|HAVE_ARC4RANDOM
comment|/* define if pthread_setconcurrency() should be called to tell the  * OS how many threads we might want to run.  */
undef|#
directive|undef
name|CALL_PTHREAD_SETCONCURRENCY
comment|/* define if IPv6 is not disabled */
undef|#
directive|undef
name|WANT_IPV6
comment|/* define if flockfile() is available */
undef|#
directive|undef
name|HAVE_FLOCKFILE
comment|/* define if getc_unlocked() is available */
undef|#
directive|undef
name|HAVE_GETCUNLOCKED
comment|/* Shut up warnings about sputaux in stdio.h on BSD/OS pre-4.1 */
undef|#
directive|undef
name|SHUTUP_SPUTAUX
ifdef|#
directive|ifdef
name|SHUTUP_SPUTAUX
expr|struct
name|__sFILE
expr_stmt|;
end_expr_stmt

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
comment|/* Shut up warnings about missing sigwait prototype on BSD/OS 4.0* */
end_comment

begin_undef
undef|#
directive|undef
name|SHUTUP_SIGWAIT
end_undef

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
comment|/* Shut up warnings from gcc -Wcast-qual on BSD/OS 4.1. */
end_comment

begin_undef
undef|#
directive|undef
name|SHUTUP_STDARG_CAST
end_undef

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
comment|/* Grr.  Must be included *every time*. */
end_comment

begin_comment
comment|/*  * The silly continuation line is to keep configure from  * commenting out the #undef.  */
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
comment|/* SHUTUP_STDARG_CAST&& __GNUC__ */
end_comment

begin_comment
comment|/* define if the system has a random number generating device */
end_comment

begin_undef
undef|#
directive|undef
name|PATH_RANDOMDEV
end_undef

begin_comment
comment|/* define if pthread_attr_getstacksize() is available */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PTHREAD_ATTR_GETSTACKSIZE
end_undef

begin_comment
comment|/* define if pthread_attr_setstacksize() is available */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PTHREAD_ATTR_SETSTACKSIZE
end_undef

begin_comment
comment|/* define if you have strerror in the C library. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRERROR
end_undef

begin_comment
comment|/* Define if you are running under Compaq TruCluster. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TRUCLUSTER
end_undef

begin_comment
comment|/* Define if OpenSSL includes DSA support */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_OPENSSL_DSA
end_undef

begin_comment
comment|/* Define to the length type used by the socket API (socklen_t, size_t, int). */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_SOCKADDR_LEN_T
end_undef

begin_comment
comment|/* Define if threads need PTHREAD_SCOPE_SYSTEM */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_PTHREAD_SCOPE_SYSTEM
end_undef

end_unit

