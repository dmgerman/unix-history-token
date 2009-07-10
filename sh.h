begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /p/tcsh/cvsroot/tcsh/sh.h,v 3.146 2006/07/03 22:59:01 mitr Exp $ */
end_comment

begin_comment
comment|/*  * sh.h: Catch it all globals and includes file!  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_sh
end_ifndef

begin_define
define|#
directive|define
name|_h_sh
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ICONV
end_ifdef

begin_include
include|#
directive|include
file|<iconv.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_INTTYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STDINT_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_INTTYPES_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WINNT_NATIVE
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|intptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXTERN
end_ifndef

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !EXTERN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WINNT_NATIVE
end_ifdef

begin_define
define|#
directive|define
name|IZERO
value|= 0
end_define

begin_define
define|#
directive|define
name|IZERO_STRUCT
value|= {0}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINNT_NATIVE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXTERN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IZERO
end_ifndef

begin_define
define|#
directive|define
name|IZERO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IZERO_STRUCT
end_ifndef

begin_define
define|#
directive|define
name|IZERO_STRUCT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IZERO_STRUCT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINNT_NATIVE
end_ifndef

begin_define
define|#
directive|define
name|INIT_ZERO
end_define

begin_define
define|#
directive|define
name|INIT_ZERO_STRUCT
end_define

begin_define
define|#
directive|define
name|force_read
value|xread
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!WINNT_NATIVE */
end_comment

begin_comment
comment|/*  * Sanity  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|POSIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|POSIX
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
name|POSIXJOBS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSDJOBS
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSDJOBS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SHORT_STRINGS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WIDE_STRINGS
end_ifdef

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_typedef
typedef|typedef
name|wchar_t
name|Char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uChar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|wint_t
name|eChar
typedef|;
end_typedef

begin_comment
comment|/* Can contain any Char value or CHAR_ERR */
end_comment

begin_define
define|#
directive|define
name|CHAR_ERR
value|WEOF
end_define

begin_comment
comment|/* Pretty please, use bit 31... */
end_comment

begin_define
define|#
directive|define
name|normal_mbtowc
parameter_list|(
name|PWC
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|rt_mbtowc(PWC, S, N)
end_define

begin_define
define|#
directive|define
name|reset_mbtowc
parameter_list|()
value|mbtowc(NULL, NULL, 0)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|short
name|Char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uChar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|eChar
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CHAR_ERR
value|(-1)
end_define

begin_define
define|#
directive|define
name|normal_mbtowc
parameter_list|(
name|PWC
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|((void)(N), *(PWC) = (unsigned char)*(S), 1)
end_define

begin_define
define|#
directive|define
name|reset_mbtowc
parameter_list|()
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SAVE
parameter_list|(
name|a
parameter_list|)
value|(Strsave(str2short(a)))
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
name|Char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uChar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|eChar
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CHAR_ERR
value|(-1)
end_define

begin_define
define|#
directive|define
name|normal_mbtowc
parameter_list|(
name|PWC
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|((void)(N), *(PWC) = (unsigned char)*(S), 1)
end_define

begin_define
define|#
directive|define
name|reset_mbtowc
parameter_list|()
value|((void)0)
end_define

begin_define
define|#
directive|define
name|SAVE
parameter_list|(
name|a
parameter_list|)
value|(strsave(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Elide unused argument warnings */
end_comment

begin_define
define|#
directive|define
name|USE
parameter_list|(
name|a
parameter_list|)
value|(void) (a)
end_define

begin_comment
comment|/*  * Return true if the path is absolute  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WINNT_NATIVE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ABSOLUTEP
parameter_list|(
name|p
parameter_list|)
value|((p)[0] == '/' || \     (Isalpha((p)[0])&& (p)[1] == ':'))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ABSOLUTEP
parameter_list|(
name|p
parameter_list|)
value|((p)[0] == '/' || \     (Isalpha((p)[0])&& (p)[1] == ':'&& \      ((p)[2] == '\0' || (p)[2] == '/')))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !WINNT_NATIVE&& !__CYGWIN__ */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTEP
parameter_list|(
name|p
parameter_list|)
value|(*(p) == '/')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINNT_NATIVE || __CYGWIN__ */
end_comment

begin_comment
comment|/*  * Fundamental definitions which may vary from system to system.  *  *	BUFSIZE		The i/o buffering size; also limits word size  *	MAILINTVL	How often to mailcheck; more often is more expensive  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZE
end_ifdef

begin_if
if|#
directive|if
name|BUFSIZE
operator|<
literal|4096
end_if

begin_undef
undef|#
directive|undef
name|BUFSIZE
end_undef

begin_define
define|#
directive|define
name|BUFSIZE
value|4096
end_define

begin_comment
comment|/* buffer size should be no less than this */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUFSIZE
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BUFSIZE */
end_comment

begin_define
define|#
directive|define
name|FORKSLEEP
value|10
end_define

begin_comment
comment|/* delay loop on non-interactive fork failure */
end_comment

begin_define
define|#
directive|define
name|MAILINTVL
value|600
end_define

begin_comment
comment|/* 10 minutes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INBUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|INBUFSIZE
value|2*BUFSIZE
end_define

begin_comment
comment|/* Num input characters on the command line */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INBUFSIZE */
end_comment

begin_comment
comment|/*  * What our builtin echo looks like  */
end_comment

begin_define
define|#
directive|define
name|NONE_ECHO
value|0
end_define

begin_define
define|#
directive|define
name|BSD_ECHO
value|1
end_define

begin_define
define|#
directive|define
name|SYSV_ECHO
value|2
end_define

begin_define
define|#
directive|define
name|BOTH_ECHO
value|(BSD_ECHO|SYSV_ECHO)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ECHO_STYLE
end_ifndef

begin_if
if|#
directive|if
name|SYSVREL
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|ECHO_STYLE
value|SYSV_ECHO
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYSVREL == 0 */
end_comment

begin_define
define|#
directive|define
name|ECHO_STYLE
value|BSD_ECHO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSVREL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECHO_STYLE */
end_comment

begin_comment
comment|/*  * The shell moves std in/out/diag and the old std input away from units  * 0, 1, and 2 so that it is easy to set up these standards for invoked  * commands.  */
end_comment

begin_define
define|#
directive|define
name|FSAFE
value|5
end_define

begin_comment
comment|/* We keep the first 5 descriptors untouched */
end_comment

begin_define
define|#
directive|define
name|FSHTTY
value|15
end_define

begin_comment
comment|/* /dev/tty when manip pgrps */
end_comment

begin_define
define|#
directive|define
name|FSHIN
value|16
end_define

begin_comment
comment|/* Preferred desc for shell input */
end_comment

begin_define
define|#
directive|define
name|FSHOUT
value|17
end_define

begin_comment
comment|/* ... shell output */
end_comment

begin_define
define|#
directive|define
name|FSHDIAG
value|18
end_define

begin_comment
comment|/* ... shell diagnostics */
end_comment

begin_define
define|#
directive|define
name|FOLDSTD
value|19
end_define

begin_comment
comment|/* ... old std input */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_define
define|#
directive|define
name|xexit
parameter_list|(
name|n
parameter_list|)
value|done(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|cray
end_ifdef

begin_define
define|#
directive|define
name|word
value|word_t
end_define

begin_comment
comment|/* sys/types.h defines word.. bad move! */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|cray
end_ifdef

begin_undef
undef|#
directive|undef
name|word
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * Path separator in environment variables  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATHSEP
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__EMX__
argument_list|)
operator|||
name|defined
argument_list|(
name|WINNT_NATIVE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PATHSEP
value|';'
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* unix */
end_comment

begin_define
define|#
directive|define
name|PATHSEP
value|':'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMX__ || WINNT_NATIVE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !PATHSEP */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__HP_CXD_SPP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/cnx_stat.h>
end_include

begin_define
define|#
directive|define
name|stat
value|stat64
end_define

begin_define
define|#
directive|define
name|fstat
value|fstat64
end_define

begin_define
define|#
directive|define
name|lstat
value|lstat64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HP_CXD_SPP&& !__hpux */
end_comment

begin_comment
comment|/*  * This macro compares the st_dev field of struct stat. On aix on ibmESA  * st_dev is a structure, so comparison does not work.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_DEV_COMPARE
end_ifndef

begin_define
define|#
directive|define
name|DEV_DEV_COMPARE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) == (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_DEV_COMPARE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_include
include|#
directive|include
file|<sys/procstats.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SEQUENT_ */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|||
name|SYSVREL
operator|>
literal|0
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|WINNT_NATIVE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (POSIX || SYSVREL> 0)&& !WINNT_NATIVE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NLS
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NLS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MINIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_VMS_POSIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WINNT_NATIVE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MVS__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MINIX&& !_VMS_POSIX&& !WINNT_NATIVE&& !__MVS__ */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSDTIMES
argument_list|)
operator|||
name|defined
argument_list|(
name|BSDLIMIT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_if
if|#
directive|if
name|SYSVREL
operator|>
literal|3
operator|&&
operator|!
name|defined
argument_list|(
name|SCO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sgi
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SNI
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|&&
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MVS__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"/usr/ucbinclude/sys/resource.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|convex
end_ifdef

begin_define
define|#
directive|define
name|sysrusage
value|cvxrusage
end_define

begin_include
include|#
directive|include
file|<sys/sysinfo.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sysrusage
value|rusage
end_define

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* convex */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSVREL>3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSDTIMES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINNT_NATIVE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|POSIX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIO
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SGTTY */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TERMIO */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* POSIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UWIN
end_ifndef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UWIN */
end_comment

begin_if
if|#
directive|if
name|SYSVREL
operator|>
literal|3
end_if

begin_undef
undef|#
directive|undef
name|TIOCGLTC
end_undef

begin_comment
comment|/* we don't need those, since POSIX has them */
end_comment

begin_undef
undef|#
directive|undef
name|TIOCSLTC
end_undef

begin_undef
undef|#
directive|undef
name|CSWTCH
end_undef

begin_define
define|#
directive|define
name|CSWTCH
value|_POSIX_VDISABLE
end_define

begin_comment
comment|/* So job control works */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSVREL> 3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINNT_NATIVE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sonyrisc
end_ifdef

begin_include
include|#
directive|include
file|<sys/ttold.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sonyrisc */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WINNT_NATIVE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/*  * the gcc+protoize version of<stdlib.h>  * redefines malloc(), so we define the following  * to avoid it.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSMALLOC
argument_list|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|||
name|defined
argument_list|(
name|sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|_OSD_POSIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_FIX_MALLOC
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* glibc */
end_comment

begin_define
define|#
directive|define
name|_GNU_STDLIB_H
end_define

begin_define
define|#
directive|define
name|malloc
value|__malloc
end_define

begin_define
define|#
directive|define
name|free
value|__free
end_define

begin_define
define|#
directive|define
name|calloc
value|__calloc
end_define

begin_define
define|#
directive|define
name|realloc
value|__realloc
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_undef
undef|#
directive|undef
name|malloc
end_undef

begin_undef
undef|#
directive|undef
name|free
end_undef

begin_undef
undef|#
directive|undef
name|calloc
end_undef

begin_undef
undef|#
directive|undef
name|realloc
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* glibc || sgi */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX&& !WINNT_NATIVE */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
name|SYSVREL
operator|>
literal|0
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
operator|||
name|defined
argument_list|(
name|_MINIX
argument_list|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|pyr
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|stellar
argument_list|)
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MINIX
end_ifdef

begin_define
define|#
directive|define
name|HZ
value|CLOCKS_PER_SEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MINIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !pyr&& !stellar */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSVREL> 0 ||  _IBMR2 */
end_comment

begin_comment
comment|/* In the following ifdef the DECOSF1 has been commented so that later  * versions of DECOSF1 will get TIOCGWINSZ. This might break older versions...  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
operator|(
name|defined
argument_list|(
name|SUNOS4
argument_list|)
operator|||
name|defined
argument_list|(
name|_MINIX
argument_list|)
comment|/* || defined(DECOSF1) */
operator|)
operator|&&
name|defined
argument_list|(
name|TERMIO
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_VMS_POSIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WINNT_NATIVE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

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
operator|(
name|defined
argument_list|(
name|__DGUX__
argument_list|)
operator|&&
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|DGUX
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|CSWTCH
end_undef

begin_define
define|#
directive|define
name|CSWTCH
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|FIOCLEX
argument_list|)
operator|&&
name|defined
argument_list|(
name|SUNOS4
argument_list|)
operator|)
operator|||
operator|(
operator|(
name|SYSVREL
operator|==
literal|4
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SEQUENT_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SCO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SX
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MVS__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (!FIOCLEX&& SUNOS4) || (SYSVREL == 4&& !_SEQUENT_&& !SCO&& !_SX ) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MINIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|supermax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WINNT_NATIVE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|IRIS4D
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MINIX&& !supermax&& !WINNT_NATIVE&& !defined(IRIS4D) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|O_RDONLY
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|O_NDELAY
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_LARGEFILE
end_ifndef

begin_define
define|#
directive|define
name|O_LARGEFILE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DIRENT_H
end_ifdef

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NDIR_H
end_ifdef

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_DIRENT_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_DIRENT_D_INO
end_ifndef

begin_define
define|#
directive|define
name|d_ino
value|d_fileno
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
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|OREO
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* So the fgetpwent() prototypes work */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hpux || sgi || OREO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINNT_NATIVE
end_ifndef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINNT_NATIVE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SHADOW_H
end_ifdef

begin_include
include|#
directive|include
file|<shadow.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SHADOW_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AUTH_H
end_ifdef

begin_include
include|#
directive|include
file|<auth.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AUTH_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|POSIX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_define
define|#
directive|define
name|strchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|index(a, b)
end_define

begin_define
define|#
directive|define
name|strrchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|rindex(a, b)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_comment
comment|/*  * IRIX-5.0 has<sys/cdefs.h>, but most system include files do not  * include it yet, so we include it here  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sgi
argument_list|)
operator|&&
name|SYSVREL
operator|>
literal|3
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sgi&& SYSVREL> 3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REMOTEHOST
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ISC
end_ifdef

begin_undef
undef|#
directive|undef
name|MAXHOSTNAMELEN
end_undef

begin_comment
comment|/* Busted headers? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_SS_SIZE
argument_list|)
operator|||
name|defined
argument_list|(
name|_SS_MAXSIZE
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|HAVE_STRUCT_SOCKADDR_STORAGE_SS_FAMILY
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_comment
comment|/* Damnit, where is getnameinfo() folks? */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sgi
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CYGWIN__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sgi */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __APPLE__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_comment
comment|/* For struct iovec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REMOTEHOST */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PURIFY
end_ifdef

begin_comment
comment|/* exit normally, allowing purify to trace leaks */
end_comment

begin_define
define|#
directive|define
name|_exit
value|exit
end_define

begin_typedef
typedef|typedef
name|int
name|pret_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !PURIFY */
end_comment

begin_comment
comment|/*  * If your compiler complains, then you can either  * throw it away and get gcc or, use the following define  * and get rid of the typedef.  * [The 4.2/3BSD vax compiler does not like that]  * Both MULTIFLOW and PCC compilers exhbit this bug.  -- sterling@netcom.com  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|uts
argument_list|)
operator|||
name|defined
argument_list|(
name|MULTIFLOW
argument_list|)
operator|||
name|defined
argument_list|(
name|PCC
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|pret_t
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !((vax || uts || MULTIFLOW || PCC)&& !__GNUC__) */
end_comment

begin_typedef
typedef|typedef
name|void
name|pret_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (vax || uts || MULTIFLOW || PCC)&& !__GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PURIFY */
end_comment

begin_comment
comment|/*  * ASCII vs. EBCDIC  */
end_comment

begin_if
if|#
directive|if
literal|'Z'
operator|-
literal|'A'
operator|==
literal|25
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|IS_ASCII
end_ifndef

begin_define
define|#
directive|define
name|IS_ASCII
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sh.types.h"
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_GETPGRP
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|GETPGRP_VOID
end_ifndef

begin_function_decl
specifier|extern
name|pid_t
name|getpgrp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|pid_t
name|getpgrp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_typedef
typedef|typedef
name|ptr_t
name|memalign_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|am_char
decl_stmt|,
modifier|*
name|am_char_p
decl_stmt|;
name|short
name|am_short
decl_stmt|,
modifier|*
name|am_short_p
decl_stmt|;
name|int
name|am_int
decl_stmt|,
modifier|*
name|am_int_p
decl_stmt|;
name|long
name|am_long
decl_stmt|,
modifier|*
name|am_long_p
decl_stmt|;
name|float
name|am_float
decl_stmt|,
modifier|*
name|am_float_p
decl_stmt|;
name|double
name|am_double
decl_stmt|,
modifier|*
name|am_double_p
decl_stmt|;
block|}
typedef|*
name|memalign_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|malloc
value|lint_malloc
end_define

begin_define
define|#
directive|define
name|free
value|lint_free
end_define

begin_define
define|#
directive|define
name|realloc
value|lint_realloc
end_define

begin_define
define|#
directive|define
name|calloc
value|lint_calloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSMALLOC
end_ifdef

begin_define
define|#
directive|define
name|xmalloc
parameter_list|(
name|i
parameter_list|)
value|smalloc(i)
end_define

begin_define
define|#
directive|define
name|xrealloc
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|srealloc(p, i)
end_define

begin_define
define|#
directive|define
name|xcalloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|scalloc(n, s)
end_define

begin_define
define|#
directive|define
name|xfree
value|sfree
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xmalloc
parameter_list|(
name|i
parameter_list|)
value|malloc(i)
end_define

begin_define
define|#
directive|define
name|xrealloc
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|realloc(p, i)
end_define

begin_define
define|#
directive|define
name|xcalloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|calloc(n, s)
end_define

begin_define
define|#
directive|define
name|xfree
value|free
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSMALLOC */
end_comment

begin_include
include|#
directive|include
file|"sh.char.h"
end_include

begin_include
include|#
directive|include
file|"sh.err.h"
end_include

begin_include
include|#
directive|include
file|"sh.dir.h"
end_include

begin_include
include|#
directive|include
file|"sh.proc.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_comment
comment|/*  * C shell  *  * Bill Joy, UC Berkeley  * October, 1978; May 1980  *  * Jim Kulp, IIASA, Laxenburg Austria  * April, 1980  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HESIOD
end_ifdef

begin_include
include|#
directive|include
file|<hesiod.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HESIOD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REMOTEHOST
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REMOTEHOST */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_NAME_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|(HOST_NAME_MAX + 1)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SCO
argument_list|)
operator|&&
operator|(
name|SYSVREL
operator|>
literal|3
operator|)
end_elif

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|256
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
comment|/* MAXHOSTNAMELEN */
end_comment

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(Strcmp(a, b) == 0)
end_define

begin_comment
comment|/* globone() flags */
end_comment

begin_define
define|#
directive|define
name|G_ERROR
value|0
end_define

begin_comment
comment|/* default action: error if multiple words */
end_comment

begin_define
define|#
directive|define
name|G_IGNORE
value|1
end_define

begin_comment
comment|/* ignore the rest of the words		   */
end_comment

begin_define
define|#
directive|define
name|G_APPEND
value|2
end_define

begin_comment
comment|/* make a sentence by cat'ing the words    */
end_comment

begin_comment
comment|/*  * Global flags  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|chkstop
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warned of stopped jobs... allow exit */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|FIOCLEX
argument_list|)
operator|&&
name|defined
argument_list|(
name|FIONCLEX
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|F_SETFD
argument_list|)
end_if

begin_define
define|#
directive|define
name|CLOSE_ON_EXEC
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXTERN
name|int
name|didcch
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have closed unused fd's for child */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (FIOCLEX&& FIONCLEX) || F_SETFD */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|didfds
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have setup i/o fd's for child */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|doneinp
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EOF indicator after reset from readc */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|exiterr
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exit if error or non-zero exit status */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|child
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Child shell ... errors cause exit */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|haderr
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reset was because of an error */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|intty
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input is a tty */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|intact
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We are interactive... therefore prompt */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|justpr
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Just print because of :p hist mod */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|loginsh
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We are a loginsh -> .login/.logout */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|neednote
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Need to pnotify() */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|noexec
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't execute, just syntax check */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|pjobs
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* want to print jobs if interrupted */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|setintr
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set interrupts on/off -> Wait intr... */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|havhash
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* path hashing is available */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|editing
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* doing filename expansion and line editing */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|noediting
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial $term defaulted to noedit */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|bslash_quote
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PWP: tcsh-style quoting?  (in sh.c) */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|isoutatty
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is SHOUT a tty */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|isdiagatty
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is SHDIAG a tty */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|is1atty
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is file descriptor 1 a tty (didfds mode) */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|is2atty
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is file descriptor 2 a tty (didfds mode) */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|arun
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Currently running multi-line-aliases */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|implicit_cd
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* implicit cd enabled?(1=enabled,2=verbose) */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|inheredoc
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Currently parsing a heredoc */
end_comment

begin_comment
comment|/* We received a window change event */
end_comment

begin_decl_stmt
name|EXTERN
specifier|volatile
name|sig_atomic_t
name|windowchg
name|IZERO
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KANJI
argument_list|)
operator|&&
name|defined
argument_list|(
name|SHORT_STRINGS
argument_list|)
operator|&&
name|defined
argument_list|(
name|DSPMBYTE
argument_list|)
end_if

begin_decl_stmt
name|EXTERN
name|int
name|dspmbyte_ls
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Global i/o info  */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|arginp
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Argument input for sh -c and internal `xx` */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|onelflg
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2 -> need line for -t, 1 -> exit on read */
end_comment

begin_decl_stmt
specifier|extern
name|Char
modifier|*
name|ffile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of shell file for $0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dolzero
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if $?0 should return true... */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|seterr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error message from scanner/parser */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error from C library routines */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|exitset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp name for<< shell files in /tmp, for xfree() */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|shtemp
name|IZERO
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BSDTIMES
end_ifdef

begin_decl_stmt
name|EXTERN
name|struct
name|timeval
name|time0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Time at which the shell started */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|sysrusage
name|ru0
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_decl_stmt
name|EXTERN
name|timeval_t
name|time0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time at which shell started */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|process_stats
name|ru0
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _SEQUENT_ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POSIX
end_ifndef

begin_decl_stmt
name|EXTERN
name|time_t
name|time0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time at which shell started */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* POSIX */
end_comment

begin_decl_stmt
name|EXTERN
name|clock_t
name|time0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time at which shell started */
end_comment

begin_decl_stmt
name|EXTERN
name|clock_t
name|clk_tck
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|tms
name|shtimes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shell and child times for process timing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SEQUENT_ */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|seconds0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSDTIMES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HZ
end_ifndef

begin_define
define|#
directive|define
name|HZ
value|100
end_define

begin_comment
comment|/* for division into seconds */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Miscellany  */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|doldol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character pid for $$ */
end_comment

begin_decl_stmt
name|EXTERN
name|pid_t
name|backpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of the last background job */
end_comment

begin_comment
comment|/*  * Ideally these should be uid_t, gid_t, pid_t. I cannot do that right now  * cause pid's could be unsigned and that would break our -1 flag, and   * uid_t and gid_t are not defined in all the systems so I would have to  * make special cases for them. In the future...  */
end_comment

begin_decl_stmt
name|EXTERN
name|uid_t
name|uid
decl_stmt|,
name|euid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Invokers real and effective */
end_comment

begin_decl_stmt
name|EXTERN
name|gid_t
name|gid
decl_stmt|,
name|egid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* User and group ids */
end_comment

begin_decl_stmt
name|EXTERN
name|pid_t
name|opgrp
decl_stmt|,
comment|/* Initial pgrp and tty pgrp */
name|shpgrp
decl_stmt|,
comment|/* Pgrp of shell */
name|tpgrp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal process group */
end_comment

begin_comment
comment|/* If tpgrp is -1, leave tty alone! */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|Prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The actual printed prompt or NULL */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|RPrompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Right-hand side prompt or NULL */
end_comment

begin_comment
comment|/*  * To be able to redirect i/o for builtins easily, the shell moves the i/o  * descriptors it uses away from 0,1,2.  * Ideally these should be in units which are closed across exec's  * (this saves work) but for version 6, this is not usually possible.  * The desired initial values for these descriptors are defined in  * sh.local.h.  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|SHIN
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current shell input (script) */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|SHOUT
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Shell output */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|SHDIAG
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Diagnostic output... shell errs go here */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OLDSTD
name|IZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Old standard input (def for cmds) */
end_comment

begin_if
if|#
directive|if
name|SYSVREL
operator|==
literal|4
operator|&&
name|defined
argument_list|(
name|_UTS
argument_list|)
end_if

begin_comment
comment|/*   * From: fadden@uts.amdahl.com (Andy McFadden)  * we need sigsetjmp for UTS4, but not UTS2.1  */
end_comment

begin_define
define|#
directive|define
name|SIGSETJMP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Error control  *  * Errors in scanning and parsing set up an error message to be printed  * at the end and complete.  Other errors always cause a reset.  * Because of source commands and .cshrc we need nested error catches.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIGSETJMP
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|sigjmp_buf
name|j
decl_stmt|;
block|}
name|jmp_buf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|setexit
parameter_list|()
value|sigsetjmp(reslab.j)
end_define

begin_define
define|#
directive|define
name|_reset
parameter_list|()
value|siglongjmp(reslab.j, 1)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|jmp_buf
name|j
decl_stmt|;
block|}
name|jmp_buf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|setexit
parameter_list|()
value|setjmp(reslab.j)
end_define

begin_define
define|#
directive|define
name|_reset
parameter_list|()
value|longjmp(reslab.j, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getexit
parameter_list|(
name|a
parameter_list|)
value|(void) ((a) = reslab)
end_define

begin_define
define|#
directive|define
name|resexit
parameter_list|(
name|a
parameter_list|)
value|(void) (reslab = (a))
end_define

begin_define
define|#
directive|define
name|cpybin
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(void) ((a) = (b))
end_define

begin_decl_stmt
specifier|extern
name|jmp_buf_t
name|reslab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|gointr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Label for an onintr transfer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sigaction
name|parintr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parents interrupt catch */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sigaction
name|parterm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parents terminate catch */
end_comment

begin_comment
comment|/*  * Lexical definitions.  *  * All lexical space is allocated dynamically.  * The eighth/sixteenth bit of characters is used to prevent recognition,  * and eventually stripped.  */
end_comment

begin_define
define|#
directive|define
name|META
value|0200
end_define

begin_define
define|#
directive|define
name|ASCII
value|0177
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIDE_STRINGS
end_ifdef

begin_comment
comment|/* Implies SHORT_STRINGS */
end_comment

begin_comment
comment|/* 31st char bit used for 'ing (not 32nd, we want all values nonnegative) */
end_comment

begin_define
define|#
directive|define
name|QUOTE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TRIM
value|0x3FFFFFFF
end_define

begin_comment
comment|/* Mask to strip quote bit */
end_comment

begin_define
define|#
directive|define
name|UNDER
value|0x20000000
end_define

begin_comment
comment|/* Underline flag */
end_comment

begin_define
define|#
directive|define
name|BOLD
value|0x10000000
end_define

begin_comment
comment|/* Bold flag */
end_comment

begin_define
define|#
directive|define
name|STANDOUT
value|0x08000000
end_define

begin_comment
comment|/* Standout flag */
end_comment

begin_define
define|#
directive|define
name|LITERAL
value|0x04000000
end_define

begin_comment
comment|/* Literal character flag */
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTES
value|0x3C000000
end_define

begin_comment
comment|/* The bits used for attributes */
end_comment

begin_define
define|#
directive|define
name|INVALID_BYTE
value|0x00200000
end_define

begin_comment
comment|/* Invalid character on input */
end_comment

begin_define
define|#
directive|define
name|CHAR
value|0x003FFFFF
end_define

begin_comment
comment|/* Mask to mask out the character */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SHORT_STRINGS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|QUOTE
value|((Char)	0100000)
end_define

begin_comment
comment|/* 16nth char bit used for 'ing */
end_comment

begin_define
define|#
directive|define
name|TRIM
value|0073777
end_define

begin_comment
comment|/* Mask to strip quote/lit bit */
end_comment

begin_define
define|#
directive|define
name|UNDER
value|0040000
end_define

begin_comment
comment|/* Underline flag */
end_comment

begin_define
define|#
directive|define
name|BOLD
value|0020000
end_define

begin_comment
comment|/* Bold flag */
end_comment

begin_define
define|#
directive|define
name|STANDOUT
value|0010000
end_define

begin_comment
comment|/* Standout flag */
end_comment

begin_define
define|#
directive|define
name|LITERAL
value|0004000
end_define

begin_comment
comment|/* Literal character flag */
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTES
value|0074000
end_define

begin_comment
comment|/* The bits used for attributes */
end_comment

begin_define
define|#
directive|define
name|INVALID_BYTE
value|0
end_define

begin_define
define|#
directive|define
name|CHAR
value|0000377
end_define

begin_comment
comment|/* Mask to mask out the character */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QUOTE
value|((Char)	0200)
end_define

begin_comment
comment|/* Eighth char bit used for 'ing */
end_comment

begin_define
define|#
directive|define
name|TRIM
value|0177
end_define

begin_comment
comment|/* Mask to strip quote bit */
end_comment

begin_define
define|#
directive|define
name|UNDER
value|0000000
end_define

begin_comment
comment|/* No extra bits to do both */
end_comment

begin_define
define|#
directive|define
name|BOLD
value|0000000
end_define

begin_comment
comment|/* Bold flag */
end_comment

begin_define
define|#
directive|define
name|STANDOUT
value|META
end_define

begin_comment
comment|/* Standout flag */
end_comment

begin_define
define|#
directive|define
name|LITERAL
value|0000000
end_define

begin_comment
comment|/* Literal character flag */
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTES
value|0200
end_define

begin_comment
comment|/* The bits used for attributes */
end_comment

begin_define
define|#
directive|define
name|INVALID_BYTE
value|0
end_define

begin_define
define|#
directive|define
name|CHAR
value|0000177
end_define

begin_comment
comment|/* Mask to mask out the character */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHAR_DBWIDTH
value|(LITERAL|(LITERAL-1))
end_define

begin_decl_stmt
name|EXTERN
name|int
name|AsciiOnly
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If set only 7 bits expected in characters */
end_comment

begin_comment
comment|/*  * Each level of input has a buffered input structure.  * There are one or more blocks of buffered input for each level,  * exactly one if the input is seekable and tell is available.  * In other cases, the shell buffers enough blocks to keep all loops  * in the buffer.  *  * If (WIDE_STRINGS&& cantell), fbobp is always a byte offset, but  * (fseekp - fbobp) and (feobp - fbobp) are character offsets (usable for  * fbuf indexing).  *  * If (!cantell), all offsets are character offsets; if (!WIDE_STRINGS), there  * is no difference between byte and character offsets.  */
end_comment

begin_macro
name|EXTERN
end_macro

begin_struct
struct|struct
name|Bin
block|{
name|off_t
name|Bfseekp
decl_stmt|;
comment|/* Seek pointer, generally != lseek() value */
name|off_t
name|Bfbobp
decl_stmt|;
comment|/* Seekp of beginning of buffers */
name|off_t
name|Bfeobp
decl_stmt|;
comment|/* Seekp of end of buffers */
name|int
name|Bfblocks
decl_stmt|;
comment|/* Number of buffer blocks */
name|Char
modifier|*
modifier|*
name|Bfbuf
decl_stmt|;
comment|/* The array of buffer blocks */
ifdef|#
directive|ifdef
name|WIDE_STRINGS
comment|/* Number of bytes in each character if (cantell) */
name|unsigned
name|char
name|Bfclens
index|[
name|BUFSIZE
operator|+
literal|1
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|B
struct|;
end_struct

begin_comment
comment|/*  * This structure allows us to seek inside aliases  */
end_comment

begin_struct
struct|struct
name|Ain
block|{
name|int
name|type
decl_stmt|;
define|#
directive|define
name|TCSH_I_SEEK
value|0
comment|/* Invalid seek */
define|#
directive|define
name|TCSH_A_SEEK
value|1
comment|/* Alias seek */
define|#
directive|define
name|TCSH_F_SEEK
value|2
comment|/* File seek */
define|#
directive|define
name|TCSH_E_SEEK
value|3
comment|/* Eval seek */
union|union
block|{
name|off_t
name|_f_seek
decl_stmt|;
comment|/* A byte offset if (cantell) */
name|Char
modifier|*
name|_c_seek
decl_stmt|;
block|}
name|fc
union|;
define|#
directive|define
name|f_seek
value|fc._f_seek
define|#
directive|define
name|c_seek
value|fc._c_seek
name|Char
modifier|*
modifier|*
name|a_seek
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|aret
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type of last char returned */
end_comment

begin_define
define|#
directive|define
name|SEEKEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)->type == (b)->type&& \ 		      (a)->f_seek == (b)->f_seek&& \ 		      (a)->a_seek == (b)->a_seek)
end_define

begin_define
define|#
directive|define
name|fseekp
value|B.Bfseekp
end_define

begin_define
define|#
directive|define
name|fbobp
value|B.Bfbobp
end_define

begin_define
define|#
directive|define
name|feobp
value|B.Bfeobp
end_define

begin_define
define|#
directive|define
name|fblocks
value|B.Bfblocks
end_define

begin_define
define|#
directive|define
name|fbuf
value|B.Bfbuf
end_define

begin_define
define|#
directive|define
name|fclens
value|B.Bfclens
end_define

begin_comment
comment|/*  * The shell finds commands in loops by reseeking the input  * For whiles, in particular, it reseeks to the beginning of the  * line the while was on; hence the while placement restrictions.  */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|Ain
name|lineloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|cantell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is current source tellable ? */
end_comment

begin_comment
comment|/*  * Input lines are parsed into doubly linked circular  * lists of words of the following form.  */
end_comment

begin_struct
struct|struct
name|wordent
block|{
name|Char
modifier|*
name|word
decl_stmt|;
name|struct
name|wordent
modifier|*
name|prev
decl_stmt|;
name|struct
name|wordent
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * During word building, both in the initial lexical phase and  * when expanding $ variable substitutions, expansion by `!' and `$'  * must be inhibited when reading ahead in routines which are themselves  * processing `!' and `$' expansion or after characters such as `\' or in  * quotations.  The following flags are passed to the getC routines  * telling them which of these substitutions are appropriate for the  * next character to be returned.  */
end_comment

begin_define
define|#
directive|define
name|DODOL
value|1
end_define

begin_define
define|#
directive|define
name|DOEXCL
value|2
end_define

begin_define
define|#
directive|define
name|DOALL
value|DODOL|DOEXCL
end_define

begin_comment
comment|/*  * Labuf implements a general buffer for lookahead during lexical operations.  * Text which is to be placed in the input stream can be stuck here.  * We stick parsed ahead $ constructs during initial input,  * process id's from `$$', and modified variable values (from qualifiers  * during expansion in sh.dol.c) here.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Strbuf
name|labuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|size_t
name|lap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* N/A if == labuf.len, index into labuf.s otherwise */
end_comment

begin_comment
comment|/*  * Parser structure  *  * Each command is parsed to a tree of command structures and  * flags are set bottom up during this process, to be propagated down  * as needed during the semantics/exeuction pass (sh.sem.c).  */
end_comment

begin_struct
struct|struct
name|command
block|{
name|unsigned
name|char
name|t_dtyp
decl_stmt|;
comment|/* Type of node 		 */
define|#
directive|define
name|NODE_COMMAND
value|1
comment|/* t_dcom<t_dlef>t_drit	 */
define|#
directive|define
name|NODE_PAREN
value|2
comment|/* ( t_dspr )<t_dlef>t_drit	 */
define|#
directive|define
name|NODE_PIPE
value|3
comment|/* t_dlef | t_drit		 */
define|#
directive|define
name|NODE_LIST
value|4
comment|/* t_dlef ; t_drit		 */
define|#
directive|define
name|NODE_OR
value|5
comment|/* t_dlef || t_drit		 */
define|#
directive|define
name|NODE_AND
value|6
comment|/* t_dlef&& t_drit		 */
name|unsigned
name|char
name|t_nice
decl_stmt|;
comment|/* Nice value			 */
ifdef|#
directive|ifdef
name|apollo
name|unsigned
name|char
name|t_systype
decl_stmt|;
comment|/* System environment		 */
endif|#
directive|endif
name|unsigned
name|long
name|t_dflg
decl_stmt|;
comment|/* Flags, e.g. F_AMPERSAND|... 	 */
comment|/* save these when re-doing 	 */
ifndef|#
directive|ifndef
name|apollo
define|#
directive|define
name|F_SAVE
value|(F_NICE|F_TIME|F_NOHUP|F_HUP)
else|#
directive|else
define|#
directive|define
name|F_SAVE
value|(F_NICE|F_TIME|F_NOHUP||F_HUP|F_VER)
endif|#
directive|endif
define|#
directive|define
name|F_AMPERSAND
value|(1<<0)
comment|/* executes in background	 */
define|#
directive|define
name|F_APPEND
value|(1<<1)
comment|/* output is redirected>>	 */
define|#
directive|define
name|F_PIPEIN
value|(1<<2)
comment|/* input is a pipe		 */
define|#
directive|define
name|F_PIPEOUT
value|(1<<3)
comment|/* output is a pipe		 */
define|#
directive|define
name|F_NOFORK
value|(1<<4)
comment|/* don't fork, last ()ized cmd	 */
define|#
directive|define
name|F_NOINTERRUPT
value|(1<<5)
comment|/* should be immune from intr's */
comment|/* spare */
define|#
directive|define
name|F_STDERR
value|(1<<7)
comment|/* redirect unit 2 with unit 1	 */
define|#
directive|define
name|F_OVERWRITE
value|(1<<8)
comment|/* output was !			 */
define|#
directive|define
name|F_READ
value|(1<<9)
comment|/* input redirection is<<	 */
define|#
directive|define
name|F_REPEAT
value|(1<<10)
comment|/* reexec aft if, repeat,...	 */
define|#
directive|define
name|F_NICE
value|(1<<11)
comment|/* t_nice is meaningful 	 */
define|#
directive|define
name|F_NOHUP
value|(1<<12)
comment|/* nohup this command 		 */
define|#
directive|define
name|F_TIME
value|(1<<13)
comment|/* time this command 		 */
define|#
directive|define
name|F_BACKQ
value|(1<<14)
comment|/* command is in ``		 */
define|#
directive|define
name|F_HUP
value|(1<<15)
comment|/* hup this command		 */
ifdef|#
directive|ifdef
name|apollo
define|#
directive|define
name|F_VER
value|(1<<16)
comment|/* execute command under SYSTYPE */
endif|#
directive|endif
union|union
block|{
name|Char
modifier|*
name|T_dlef
decl_stmt|;
comment|/* Input redirect word 		 */
name|struct
name|command
modifier|*
name|T_dcar
decl_stmt|;
comment|/* Left part of list/pipe 	 */
block|}
name|L
union|;
union|union
block|{
name|Char
modifier|*
name|T_drit
decl_stmt|;
comment|/* Output redirect word 	 */
name|struct
name|command
modifier|*
name|T_dcdr
decl_stmt|;
comment|/* Right part of list/pipe 	 */
block|}
name|R
union|;
define|#
directive|define
name|t_dlef
value|L.T_dlef
define|#
directive|define
name|t_dcar
value|L.T_dcar
define|#
directive|define
name|t_drit
value|R.T_drit
define|#
directive|define
name|t_dcdr
value|R.T_dcdr
name|Char
modifier|*
modifier|*
name|t_dcom
decl_stmt|;
comment|/* Command/argument vector 	 */
name|struct
name|command
modifier|*
name|t_dspr
decl_stmt|;
comment|/* Pointer to ()'d subtree 	 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The keywords for the parser  */
end_comment

begin_define
define|#
directive|define
name|TC_BREAK
value|0
end_define

begin_define
define|#
directive|define
name|TC_BRKSW
value|1
end_define

begin_define
define|#
directive|define
name|TC_CASE
value|2
end_define

begin_define
define|#
directive|define
name|TC_DEFAULT
value|3
end_define

begin_define
define|#
directive|define
name|TC_ELSE
value|4
end_define

begin_define
define|#
directive|define
name|TC_END
value|5
end_define

begin_define
define|#
directive|define
name|TC_ENDIF
value|6
end_define

begin_define
define|#
directive|define
name|TC_ENDSW
value|7
end_define

begin_define
define|#
directive|define
name|TC_EXIT
value|8
end_define

begin_define
define|#
directive|define
name|TC_FOREACH
value|9
end_define

begin_define
define|#
directive|define
name|TC_GOTO
value|10
end_define

begin_define
define|#
directive|define
name|TC_IF
value|11
end_define

begin_define
define|#
directive|define
name|TC_LABEL
value|12
end_define

begin_define
define|#
directive|define
name|TC_LET
value|13
end_define

begin_define
define|#
directive|define
name|TC_SET
value|14
end_define

begin_define
define|#
directive|define
name|TC_SWITCH
value|15
end_define

begin_define
define|#
directive|define
name|TC_TEST
value|16
end_define

begin_define
define|#
directive|define
name|TC_THEN
value|17
end_define

begin_define
define|#
directive|define
name|TC_WHILE
value|18
end_define

begin_comment
comment|/*  * These are declared here because they want to be  * initialized in sh.init.c (to allow them to be made readonly)  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|/* Avoid hpux ansi mode spurious warnings */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bfunc_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bfunc_t
function_decl|)
parameter_list|(
name|Char
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hpux&& __STDC__&& !__GNUC__ */
end_comment

begin_struct
specifier|extern
specifier|const
struct|struct
name|biltins
block|{
specifier|const
name|char
modifier|*
name|bname
decl_stmt|;
name|bfunc_t
name|bfunct
decl_stmt|;
name|int
name|minargs
decl_stmt|,
name|maxargs
decl_stmt|;
block|}
name|bfunc
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|nbfunc
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|WINNT_NATIVE
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|biltins
name|nt_bfunc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nt_nbfunc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINNT_NATIVE*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bequiet
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|srch
block|{
specifier|const
name|char
modifier|*
name|s_name
decl_stmt|;
name|int
name|s_value
decl_stmt|;
block|}
name|srchn
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|nsrchn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structure defining the existing while/foreach loops at this  * source level.  Loops are implemented by seeking back in the  * input.  For foreach (fe), the word list is attached here.  */
end_comment

begin_macro
name|EXTERN
end_macro

begin_struct
struct|struct
name|whyle
block|{
name|struct
name|Ain
name|w_start
decl_stmt|;
comment|/* Point to restart loop */
name|struct
name|Ain
name|w_end
decl_stmt|;
comment|/* End of loop (0 if unknown) */
name|Char
modifier|*
modifier|*
name|w_fe
decl_stmt|,
modifier|*
modifier|*
name|w_fe0
decl_stmt|;
comment|/* Current/initial wordlist for fe */
name|Char
modifier|*
name|w_fename
decl_stmt|;
comment|/* Name for fe */
name|struct
name|whyle
modifier|*
name|w_next
decl_stmt|;
comment|/* Next (more outer) loop */
block|}
modifier|*
name|whyles
struct|;
end_struct

begin_comment
comment|/*  * Variable structure  *  * Aliases and variables are stored in AVL balanced binary trees.  */
end_comment

begin_macro
name|EXTERN
end_macro

begin_struct
struct|struct
name|varent
block|{
name|Char
modifier|*
modifier|*
name|vec
decl_stmt|;
comment|/* Array of words which is the value */
name|Char
modifier|*
name|v_name
decl_stmt|;
comment|/* Name of variable/alias */
name|int
name|v_flags
decl_stmt|;
comment|/* Flags */
define|#
directive|define
name|VAR_ALL
value|-1
define|#
directive|define
name|VAR_READONLY
value|1
define|#
directive|define
name|VAR_READWRITE
value|2
define|#
directive|define
name|VAR_NOGLOB
value|4
define|#
directive|define
name|VAR_FIRST
value|32
define|#
directive|define
name|VAR_LAST
value|64
name|struct
name|varent
modifier|*
name|v_link
index|[
literal|3
index|]
decl_stmt|;
comment|/* The links, see below */
name|int
name|v_bal
decl_stmt|;
comment|/* Balance factor */
block|}
name|shvhed
name|IZERO_STRUCT
struct|,
name|aliases
name|IZERO_STRUCT
struct|;
end_struct

begin_define
define|#
directive|define
name|v_left
value|v_link[0]
end_define

begin_define
define|#
directive|define
name|v_right
value|v_link[1]
end_define

begin_define
define|#
directive|define
name|v_parent
value|v_link[2]
end_define

begin_define
define|#
directive|define
name|adrof
parameter_list|(
name|v
parameter_list|)
value|adrof1(v,&shvhed)
end_define

begin_define
define|#
directive|define
name|varval
parameter_list|(
name|v
parameter_list|)
value|value1(v,&shvhed)
end_define

begin_comment
comment|/*  * The following are for interfacing redo substitution in  * aliases to the lexical routines.  */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|wordent
modifier|*
name|alhistp
name|IZERO_STRUCT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Argument list (first) */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|wordent
modifier|*
name|alhistt
name|IZERO_STRUCT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Node after last in arg list */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
modifier|*
name|alvec
name|IZERO_STRUCT
decl_stmt|,
modifier|*
name|alvecp
name|IZERO_STRUCT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The (remnants of) alias vector */
end_comment

begin_comment
comment|/*  * Filename/command name expansion variables  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__CYGWIN__
end_ifdef

begin_undef
undef|#
directive|undef
name|MAXPATHLEN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CYGWIN__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXPATHLEN
value|2048
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
comment|/* MAXPATHLEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVENOLIMIT
end_ifndef

begin_comment
comment|/*  * resource limits  */
end_comment

begin_struct
specifier|extern
struct|struct
name|limits
block|{
name|int
name|limconst
decl_stmt|;
specifier|const
name|char
modifier|*
name|limname
decl_stmt|;
name|int
name|limdiv
decl_stmt|;
specifier|const
name|char
modifier|*
name|limscale
decl_stmt|;
block|}
name|limits
index|[]
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVENOLIMIT */
end_comment

begin_comment
comment|/*  * History list  *  * Each history list entry contains an embedded wordlist  * from the scanner, a number for the event, and a reference count  * to aid in discarding old entries.  *  * Essentially "invisible" entries are put on the history list  * when history substitution includes modifiers, and thrown away  * at the next discarding since their event numbers are very negative.  */
end_comment

begin_macro
name|EXTERN
end_macro

begin_struct
struct|struct
name|Hist
block|{
name|struct
name|wordent
name|Hlex
decl_stmt|;
name|int
name|Hnum
decl_stmt|;
name|int
name|Href
decl_stmt|;
name|time_t
name|Htime
decl_stmt|;
name|Char
modifier|*
name|histline
decl_stmt|;
name|struct
name|Hist
modifier|*
name|Hnext
decl_stmt|;
block|}
name|Histlist
name|IZERO_STRUCT
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|wordent
name|paraml
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current lexical word list */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|eventno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Next events number */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|lastev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last event reference (default) */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|HIST
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* history invocation character */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|HISTSUB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* auto-substitute character */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|PRCH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prompt symbol for regular users */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|PRCHROOT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prompt symbol for root */
end_comment

begin_comment
comment|/*  * For operating systems with single case filenames (OS/2)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CASE_INSENSITIVE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WIDE_STRINGS
end_ifdef

begin_define
define|#
directive|define
name|samecase
parameter_list|(
name|x
parameter_list|)
value|(towlower(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|samecase
parameter_list|(
name|x
parameter_list|)
value|(isupper((unsigned char)(x)) ? \ 		       tolower((unsigned char)(x)) : (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|samecase
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CASE_INSENSITIVE */
end_comment

begin_comment
comment|/*  * strings.h:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHORT_STRINGS
end_ifndef

begin_define
define|#
directive|define
name|Strchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strchr(a, b)
end_define

begin_define
define|#
directive|define
name|Strrchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strrchr(a, b)
end_define

begin_define
define|#
directive|define
name|Strcat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcat(a, b)
end_define

begin_define
define|#
directive|define
name|Strncat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|strncat(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strcpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcpy(a, b)
end_define

begin_define
define|#
directive|define
name|Strncpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|strncpy(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strlen
parameter_list|(
name|a
parameter_list|)
value|strlen(a)
end_define

begin_define
define|#
directive|define
name|Strcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcmp(a, b)
end_define

begin_define
define|#
directive|define
name|Strncmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|strncmp(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strcasecmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcasecmp(a, b)
end_define

begin_define
define|#
directive|define
name|Strspl
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strspl(a, b)
end_define

begin_define
define|#
directive|define
name|Strnsave
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strnsave(a, b)
end_define

begin_define
define|#
directive|define
name|Strsave
parameter_list|(
name|a
parameter_list|)
value|strsave(a)
end_define

begin_define
define|#
directive|define
name|Strend
parameter_list|(
name|a
parameter_list|)
value|strend(a)
end_define

begin_define
define|#
directive|define
name|Strstr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strstr(a, b)
end_define

begin_define
define|#
directive|define
name|str2short
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|blk2short
parameter_list|(
name|a
parameter_list|)
value|saveblk(a)
end_define

begin_define
define|#
directive|define
name|short2blk
parameter_list|(
name|a
parameter_list|)
value|saveblk(a)
end_define

begin_define
define|#
directive|define
name|short2str
parameter_list|(
name|a
parameter_list|)
value|caching_strip(a)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|WIDE_STRINGS
end_ifdef

begin_define
define|#
directive|define
name|Strchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|wcschr(a, b)
end_define

begin_define
define|#
directive|define
name|Strrchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|wcsrchr(a, b)
end_define

begin_define
define|#
directive|define
name|Strcat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|wcscat(a, b)
end_define

begin_define
define|#
directive|define
name|Strncat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|wcsncat(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strcpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|wcscpy(a, b)
end_define

begin_define
define|#
directive|define
name|Strncpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|wcsncpy(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strlen
parameter_list|(
name|a
parameter_list|)
value|wcslen(a)
end_define

begin_define
define|#
directive|define
name|Strcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|wcscmp(a, b)
end_define

begin_define
define|#
directive|define
name|Strncmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|wcsncmp(a, b, c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Strchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strchr(a, b)
end_define

begin_define
define|#
directive|define
name|Strrchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strrchr(a, b)
end_define

begin_define
define|#
directive|define
name|Strcat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strcat(a, b)
end_define

begin_define
define|#
directive|define
name|Strncat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|s_strncat(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strcpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strcpy(a, b)
end_define

begin_define
define|#
directive|define
name|Strncpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|s_strncpy(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strlen
parameter_list|(
name|a
parameter_list|)
value|s_strlen(a)
end_define

begin_define
define|#
directive|define
name|Strcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strcmp(a, b)
end_define

begin_define
define|#
directive|define
name|Strncmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|s_strncmp(a, b, c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Strcasecmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strcasecmp(a, b)
end_define

begin_define
define|#
directive|define
name|Strspl
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strspl(a, b)
end_define

begin_define
define|#
directive|define
name|Strnsave
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strnsave(a, b)
end_define

begin_define
define|#
directive|define
name|Strsave
parameter_list|(
name|a
parameter_list|)
value|s_strsave(a)
end_define

begin_define
define|#
directive|define
name|Strend
parameter_list|(
name|a
parameter_list|)
value|s_strend(a)
end_define

begin_define
define|#
directive|define
name|Strstr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strstr(a, b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * setname is a macro to save space (see sh.err.c)  */
end_comment

begin_decl_stmt
name|EXTERN
specifier|const
name|char
modifier|*
name|bname
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|setname
parameter_list|(
name|a
parameter_list|)
value|(bname = (a))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VFORK
end_ifdef

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|Vsav
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|Vdp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|Vexpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|Vt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VFORK */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
modifier|*
name|evalvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|evalp
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|mesg
block|{
specifier|const
name|char
modifier|*
name|iname
decl_stmt|;
comment|/* name from /usr/include */
specifier|const
name|char
modifier|*
name|pname
decl_stmt|;
comment|/* print name */
block|}
name|mesg
index|[]
struct|;
end_struct

begin_comment
comment|/* word_chars is set by default to WORD_CHARS but can be overridden by    the worchars variable--if unset, reverts to WORD_CHARS */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|word_chars
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|WORD_CHARS
value|"*?_-.[]~="
end_define

begin_comment
comment|/* default chars besides alnums in words */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|STR_SHELLPATH
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_BSHELL
end_ifdef

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|STR_BSHELL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|STR_WORD_CHARS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
modifier|*
name|STR_environ
name|IZERO
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dont_free
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell free that we are in danger if we free */
end_comment

begin_decl_stmt
specifier|extern
name|Char
modifier|*
name|INVPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Char
modifier|*
modifier|*
name|INVPPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcsh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xlate_cr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|output_raw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lbuffed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|Htime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|numeof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|insource
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|linbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|linp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nsig
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VFORK
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|use_fork
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|tellwhat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|NoNLSRebind
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_ENVIRON
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tc.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WINNT_NATIVE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NLS_CATALOGS
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_include
include|#
directive|include
file|<localeinfo.h>
end_include

begin_comment
comment|/* Has this changed ? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<features.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS4
end_ifdef

begin_comment
comment|/* Who stole my nl_types.h? :-(      * All this stuff is in the man pages, but nowhere else?     * This does not link right now...     */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|nl_catd
typedef|;
end_typedef

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|catgets
parameter_list|(
name|nl_catd
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nl_catd
name|catopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|catclose
parameter_list|(
name|nl_catd
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__uxps__
end_ifdef

begin_define
define|#
directive|define
name|gettxt
value|gettxt_ds
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<nl_types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__uxps__
end_ifdef

begin_undef
undef|#
directive|undef
name|gettxt
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MCLoadBySet
end_ifndef

begin_define
define|#
directive|define
name|MCLoadBySet
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXTERN
name|nl_catd
name|catd
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ICONV
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_NL_LANGINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|CGETS
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|iconv_catgets(catd, b, c, d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CGETS
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|xcatgets(catd, b, c, d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CSAVS
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|strsave(CGETS(b, c, d))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CGETS
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|d
end_define

begin_define
define|#
directive|define
name|CSAVS
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WINNT_NATIVE */
end_comment

begin_define
define|#
directive|define
name|CGETS
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|nt_cgets( b, c, d)
end_define

begin_define
define|#
directive|define
name|CSAVS
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|strsave(CGETS(b, c, d))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINNT_NATIVE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FILEC
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|filec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILEC */
end_comment

begin_include
include|#
directive|include
file|"sh.decls.h"
end_include

begin_comment
comment|/*  * Since on some machines characters are unsigned, and the signed  * keyword is not universally implemented, we treat all characters  * as unsigned and sign extend them where we need.  */
end_comment

begin_define
define|#
directive|define
name|SIGN_EXTEND_CHAR
parameter_list|(
name|a
parameter_list|)
value|(((a)& 0x80) ? ((a) | ~0x7f) : (a))
end_define

begin_comment
comment|/*  * explanation for use by the "--help" option  */
end_comment

begin_define
define|#
directive|define
name|HELP_STRING
value|"\ -b file		batch mode, read and execute commands from `file' \n\ -c command	run `command' from next argument \n\ -d		load directory stack from `~/.cshdirs' \n\ -Dname[=value]	define environment variable `name' to `value' (DomainOS only) \n\ -e		exit on any error \n\ -f		start faster by ignoring the start-up file \n\ -F		use fork() instead of vfork() when spawning (ConvexOS only) \n\ -i		interactive, even when input is not from a terminal \n\ -l		act as a login shell, must be the only option specified \n\ -m		load the start-up file, whether or not owned by effective user \n\ -n file		no execute mode, just check syntax of the following `file' \n\ -q		accept SIGQUIT for running under a debugger \n\ -s		read commands from standard input \n\ -t		read one line from standard input \n\ -v		echo commands after history substitution \n\ -V		like -v but including commands read from the start-up file \n\ -x		echo commands immediately before execution \n\ -X		like -x but including commands read from the start-up file \n\ --help		print this message and exit \n\ --version	print the version shell variable and exit \n\ \nSee the tcsh(1) manual page for detailed information.\n"
end_define

begin_include
include|#
directive|include
file|"tc.nls.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_sh */
end_comment

end_unit

