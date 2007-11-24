begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1993-2002  *      Juergen Weigert (jnweiger@immd4.informatik.uni-erlangen.de)  *      Michael Schroeder (mlschroe@immd4.informatik.uni-erlangen.de)  * Copyright (c) 1987 Oliver Laumann  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program (see the file COPYING); if not, write to the  * Free Software Foundation, Inc.,  * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA  *  ****************************************************************  * $Id: os.h,v 1.10 1994/05/31 12:32:22 mlschroe Exp $ FAU  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* In strict ANSI mode, HP-UX machines define __hpux but not hpux */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|hpux
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
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|__386BSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|_CX_UX
argument_list|)
operator|||
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __bsdi__ || __386BSD__ || _CX_UX || hpux || _IBMR2 || linux */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ENAMETOOLONG
end_ifdef

begin_undef
undef|#
directive|undef
name|ENAMETOOLONG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENOTEMPTY
end_ifdef

begin_undef
undef|#
directive|undef
name|ENOTEMPTY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/bsdtypes.h>
end_include

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|getpgrp
value|__getpgrp
end_define

begin_define
define|#
directive|define
name|exit
value|__exit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_undef
undef|#
directive|undef
name|getpgrp
end_undef

begin_undef
undef|#
directive|undef
name|exit
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_comment
comment|/* all done in<errno.h> */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* linux */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRERROR
end_ifndef

begin_comment
comment|/* No macros, please */
end_comment

begin_undef
undef|#
directive|undef
name|strerror
end_undef

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
name|SYSV
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|NEWSOS
end_ifdef

begin_define
define|#
directive|define
name|strlen
value|___strlen___
end_define

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_undef
undef|#
directive|undef
name|strlen
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NEWSOS */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEWSOS */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYSV */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|NEWSOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|strlen
value|___strlen___
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_undef
undef|#
directive|undef
name|strlen
end_undef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NEWSOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_function_decl
specifier|extern
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SVR4 */
end_comment

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
comment|/* SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USEVARARGS
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|VA_LIST
parameter_list|(
name|var
parameter_list|)
value|va_list var;
end_define

begin_define
define|#
directive|define
name|VA_DOTS
value|...
end_define

begin_define
define|#
directive|define
name|VA_DECL
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|ap
parameter_list|,
name|fmt
parameter_list|)
value|va_start(ap, fmt)
end_define

begin_define
define|#
directive|define
name|VA_ARGS
parameter_list|(
name|ap
parameter_list|)
value|ap
end_define

begin_define
define|#
directive|define
name|VA_END
parameter_list|(
name|ap
parameter_list|)
value|va_end(ap)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_define
define|#
directive|define
name|VA_LIST
parameter_list|(
name|var
parameter_list|)
value|va_list var;
end_define

begin_define
define|#
directive|define
name|VA_DOTS
value|va_alist
end_define

begin_define
define|#
directive|define
name|VA_DECL
value|va_dcl
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|ap
parameter_list|,
name|fmt
parameter_list|)
value|va_start(ap)
end_define

begin_define
define|#
directive|define
name|VA_ARGS
parameter_list|(
name|ap
parameter_list|)
value|ap
end_define

begin_define
define|#
directive|define
name|VA_END
parameter_list|(
name|ap
parameter_list|)
value|va_end(ap)
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
name|VA_LIST
parameter_list|(
name|var
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VA_DOTS
value|p1, p2, p3, p4, p5, p6
end_define

begin_define
define|#
directive|define
name|VA_DECL
value|unsigned long VA_DOTS;
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|ap
parameter_list|,
name|fmt
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VA_ARGS
parameter_list|(
name|ap
parameter_list|)
value|VA_DOTS
end_define

begin_define
define|#
directive|define
name|VA_END
parameter_list|(
name|ap
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|vsnprintf
end_undef

begin_define
define|#
directive|define
name|vsnprintf
value|xsnprintf
end_define

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
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|B43
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ISC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|pyr
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_CX_UX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|M_UNIX
end_ifdef

begin_comment
comment|/* SCO */
end_comment

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptem.h>
end_include

begin_define
define|#
directive|define
name|ftruncate
parameter_list|(
name|fd
parameter_list|,
name|s
parameter_list|)
value|chsize(fd, s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|poi
parameter_list|,
name|len
parameter_list|)
value|memset(poi,0,len)
end_define

begin_define
define|#
directive|define
name|bcmp
value|memcmp
end_define

begin_define
define|#
directive|define
name|killpg
parameter_list|(
name|pgrp
parameter_list|,
name|sig
parameter_list|)
value|kill( -(pgrp), sig)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETCWD
end_ifndef

begin_define
define|#
directive|define
name|getcwd
parameter_list|(
name|b
parameter_list|,
name|l
parameter_list|)
value|getwd(b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USEBCOPY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|USEMEMMOVE
end_ifdef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|len
parameter_list|)
value|memmove(d,s,len)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|USEMEMCPY
end_ifdef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|len
parameter_list|)
value|memcpy(d,s,len)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NEED_OWN_BCOPY
end_define

begin_define
define|#
directive|define
name|bcopy
value|xbcopy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_define
define|#
directive|define
name|setreuid
parameter_list|(
name|ruid
parameter_list|,
name|euid
parameter_list|)
value|setresuid(ruid, euid, -1)
end_define

begin_define
define|#
directive|define
name|setregid
parameter_list|(
name|rgid
parameter_list|,
name|egid
parameter_list|)
value|setresgid(rgid, egid, -1)
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
name|HAVE_SETEUID
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_SETREUID
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_SETEUID
end_define

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
name|HAVE__EXIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_exit
argument_list|)
end_if

begin_define
define|#
directive|define
name|_exit
parameter_list|(
name|x
parameter_list|)
value|exit(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UTIMES
end_ifndef

begin_define
define|#
directive|define
name|utimes
value|utime
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BUILTIN_TELNET
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_LOCALE
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|HAVE_SETLOCALE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_STRFTIME
argument_list|)
operator|)
end_if

begin_undef
undef|#
directive|undef
name|USE_LOCALE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************  *    terminal handling  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_include
include|#
directive|include
file|<bsdtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hpux */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCCS
end_ifdef

begin_define
define|#
directive|define
name|MAXCC
value|NCCS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXCC
value|256
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
comment|/* POSIX */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|NCC
end_ifdef

begin_define
define|#
directive|define
name|MAXCC
value|NCC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXCC
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CYTERMIO
end_ifdef

begin_include
include|#
directive|include
file|<cytermio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TERMIO */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VDISABLE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_VDISABLE
end_ifdef

begin_define
define|#
directive|define
name|VDISABLE
value|_POSIX_VDISABLE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VDISABLE
value|0377
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VDISABLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !VDISABLE */
end_comment

begin_comment
comment|/* on sgi, regardless of the stream head's read mode (RNORM/RMSGN/RMSGD)  * TIOCPKT mode causes data loss if our buffer is too small (IOSIZE)  * to hold the whole packet at first read().  * (Marc Boucher)  *  * matthew green:  * TIOCPKT is broken on dgux 5.4.1 generic AViiON mc88100  *  * Joe Traister: On AIX4, programs like irc won't work if screen  * uses TIOCPKT (select fails to return on pty read).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|DGUX
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|TIOCPKT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* linux ncurses is broken, we have to use our own tputs */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|linux
argument_list|)
operator|&&
name|defined
argument_list|(
name|TERMINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|tputs
value|xtputs
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Alexandre Oliva: SVR4 style ptys don't work with osf */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__osf__
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_SVR4_PTYS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************  *   utmp handling  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GETUTENT
end_ifdef

begin_typedef
typedef|typedef
name|char
modifier|*
name|slot_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|slot_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UTMPOK
argument_list|)
operator|||
name|defined
argument_list|(
name|BUGGYGETLOGIN
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DGUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_include
include|#
directive|include
file|<utmpx.h>
end_include

begin_define
define|#
directive|define
name|UTMPFILE
value|UTMPX_FILE
end_define

begin_define
define|#
directive|define
name|utmp
value|utmpx
end_define

begin_define
define|#
directive|define
name|getutent
value|getutxent
end_define

begin_define
define|#
directive|define
name|getutid
value|getutxid
end_define

begin_define
define|#
directive|define
name|getutline
value|getutxline
end_define

begin_define
define|#
directive|define
name|pututline
value|pututxline
end_define

begin_define
define|#
directive|define
name|setutent
value|setutxent
end_define

begin_define
define|#
directive|define
name|endutent
value|endutxent
end_define

begin_define
define|#
directive|define
name|ut_time
value|ut_xtime
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SVR4 */
end_comment

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_comment
comment|/*      * We don't have GETUTENT, so we dig into utmp ourselves.     * But we save the permanent filedescriptor and     * open utmp just when we need to.      * This code supports an unsorted utmp. jw.     */
end_comment

begin_define
define|#
directive|define
name|UTNOKEEP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTMPFILE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|UTMP_FILE
end_ifdef

begin_define
define|#
directive|define
name|UTMPFILE
value|UTMP_FILE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_UTMP
end_ifdef

begin_define
define|#
directive|define
name|UTMPFILE
value|_PATH_UTMP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UTMPFILE
value|"/etc/utmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_UTMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTMPOK || BUGGYGETLOGIN */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UTMPOK
argument_list|)
operator|&&
name|defined
argument_list|(
name|USRLIMIT
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|USRLIMIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LOGOUTOK
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOGINDEFAULT
end_ifndef

begin_define
define|#
directive|define
name|LOGINDEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|LOGINDEFAULT
end_ifdef

begin_undef
undef|#
directive|undef
name|LOGINDEFAULT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOGINDEFAULT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************  *    file stuff  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|X_OK
end_ifndef

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|W_OK
end_ifndef

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFIFO
end_ifndef

begin_define
define|#
directive|define
name|S_IFIFO
value|0010000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IREAD
end_ifndef

begin_define
define|#
directive|define
name|S_IREAD
value|0000400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWRITE
end_ifndef

begin_define
define|#
directive|define
name|S_IWRITE
value|0000200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IEXEC
end_ifndef

begin_define
define|#
directive|define
name|S_IEXEC
value|0000100
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
name|S_IFIFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFMT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFIFO)
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
name|S_IFSOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFMT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISSOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFSOCK)
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
name|S_IFCHR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFMT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISCHR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFCHR)
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
name|S_IFDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFMT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFDIR)
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
name|S_IFLNK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFMT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISLNK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFLNK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SunOS 4.1.3: `man 2V open' has only one line that mentions O_NOBLOCK:  *  *     O_NONBLOCK     Same as O_NDELAY above.  *  * on the very same SunOS 4.1.3, I traced the open system call and found  * that an open("/dev/ttyy08", O_RDWR|O_NONBLOCK|O_NOCTTY) was blocked,  * whereas open("/dev/ttyy08", O_RDWR|O_NDELAY  |O_NOCTTY) went through.  *  * For this simple reason I now favour O_NDELAY. jw. 4.5.95  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SVR4
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|O_NONBLOCK
end_undef

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
name|O_NONBLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|O_NDELAY
argument_list|)
end_if

begin_define
define|#
directive|define
name|O_NONBLOCK
value|O_NDELAY
end_define

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
name|FNBLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|FNONBLOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|FNBLOCK
value|FNONBLOCK
end_define

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
name|FNBLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|FNDELAY
argument_list|)
end_if

begin_define
define|#
directive|define
name|FNBLOCK
value|FNDELAY
end_define

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
name|FNBLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|O_NONBLOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|FNBLOCK
value|O_NONBLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|POSIX
end_ifndef

begin_undef
undef|#
directive|undef
name|mkfifo
end_undef

begin_define
define|#
directive|define
name|mkfifo
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|mknod(n,S_IFIFO|(m),0)
end_define

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
name|HAVE_LSTAT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lstat
argument_list|)
end_if

begin_define
define|#
directive|define
name|lstat
value|stat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************  *    signal handling  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIGVOID
end_ifdef

begin_define
define|#
directive|define
name|SIGRETURN
end_define

begin_define
define|#
directive|define
name|sigret_t
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGRETURN
value|return 0;
end_define

begin_define
define|#
directive|define
name|sigret_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Geeeee, reverse it? */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SVR4
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|&&
name|defined
argument_list|(
name|ISC
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|__386BSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|||
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGHASARG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIGHASARG
end_ifdef

begin_define
define|#
directive|define
name|SIGPROTOARG
value|(int)
end_define

begin_define
define|#
directive|define
name|SIGDEFARG
value|(sigsig) int sigsig;
end_define

begin_define
define|#
directive|define
name|SIGARG
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGPROTOARG
value|(void)
end_define

begin_define
define|#
directive|define
name|SIGDEFARG
value|()
end_define

begin_define
define|#
directive|define
name|SIGARG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGCHLD
end_ifndef

begin_define
define|#
directive|define
name|SIGCHLD
value|SIGCLD
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
name|POSIX
argument_list|)
operator|||
name|defined
argument_list|(
name|hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|signal
value|xsignal
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|USESIGSET
end_ifdef

begin_define
define|#
directive|define
name|signal
value|sigset
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USESIGSET */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* used in screen.c and attacher.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NSIG
end_ifndef

begin_comment
comment|/* kbeal needs these w/o SYSV */
end_comment

begin_define
define|#
directive|define
name|NSIG
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NSIG */
end_comment

begin_comment
comment|/*****************************************************************  *    Wait stuff  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|sysV68
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|M_XENIX
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|M_UNIX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WTERMSIG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BSDWAIT
end_ifndef

begin_comment
comment|/* if wait is NOT a union: */
end_comment

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|status
parameter_list|)
value|(status& 0177)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|status
parameter_list|)
value|status.w_T.w_Termsig
end_define

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
name|WSTOPSIG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BSDWAIT
end_ifndef

begin_comment
comment|/* if wait is NOT a union: */
end_comment

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|status
parameter_list|)
value|((status>> 8)& 0377)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|status
parameter_list|)
value|status.w_S.w_Stopsig
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
comment|/* NET-2 uses WCOREDUMP */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WCOREDUMP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WIFCORESIG
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIFCORESIG
parameter_list|(
name|status
parameter_list|)
value|WCOREDUMP(status)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFCORESIG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BSDWAIT
end_ifndef

begin_comment
comment|/* if wait is NOT a union: */
end_comment

begin_define
define|#
directive|define
name|WIFCORESIG
parameter_list|(
name|status
parameter_list|)
value|(status& 0200)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WIFCORESIG
parameter_list|(
name|status
parameter_list|)
value|status.w_T.w_Coredump
end_define

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
name|WEXITSTATUS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BSDWAIT
end_ifndef

begin_comment
comment|/* if wait is NOT a union: */
end_comment

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|status
parameter_list|)
value|((status>> 8)& 0377)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|status
parameter_list|)
value|status.w_T.w_Retcode
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
comment|/*****************************************************************  *    select stuff  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|M_XENIX
argument_list|)
operator|||
name|defined
argument_list|(
name|M_UNIX
argument_list|)
operator|||
name|defined
argument_list|(
name|_SEQUENT_
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_comment
comment|/* for timeval + FD... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SunOS 3.5 - Tom Schmidt - Micron Semiconductor, Inc - 27-Jul-93  * tschmidt@vax.micron.com  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SET
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|SUNOS3
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|fd_set
block|{
name|int
name|fds_bits
index|[
literal|1
index|]
decl_stmt|;
block|}
name|fd_set
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|fd
parameter_list|)
value|((fd)->fds_bits[0] = 0)
end_define

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|b
parameter_list|,
name|fd
parameter_list|)
value|((fd)->fds_bits[0] |= 1<< (b))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|b
parameter_list|,
name|fd
parameter_list|)
value|((fd)->fds_bits[0]& 1<< (b))
end_define

begin_define
define|#
directive|define
name|FD_SETSIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************  *    user defineable stuff  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TERMCAP_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|TERMCAP_BUFSIZE
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * you may try to vary this value. Use low values if your (VMS) system  * tends to choke when pasting. Use high values if you want to test  * how many characters your pty's can buffer.  */
end_comment

begin_define
define|#
directive|define
name|IOSIZE
value|4096
end_define

end_unit

