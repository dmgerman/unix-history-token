begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Sys.h  * See the README for details.  */
end_comment

begin_comment
comment|/*  $RCSfile: sys.h,v $  *  $Revision: 14020.13 $  *  $Date: 93/06/21 06:42:11 $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sun
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|sun
end_ifndef

begin_define
define|#
directive|define
name|sun
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

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SunOverride
argument_list|)
end_if

begin_comment
comment|/* If you choke here, but you know what you're doing, just 	 * define SunOverride. 	 */
end_comment

begin_expr_stmt
operator|^
operator|^
operator|^
literal|"You need to use an ANSI C compiler.  Try using gcc or acc."
operator|^
operator|^
operator|^
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Solaris
comment|/* not predefined. */
ifndef|#
directive|ifndef
name|SYSV
define|#
directive|define
name|SYSV
value|1
endif|#
directive|endif
define|#
directive|define
name|System
value|"Solaris"
else|#
directive|else
define|#
directive|define
name|System
value|"SunOS"
ifndef|#
directive|ifndef
name|RINDEX
define|#
directive|define
name|RINDEX
value|1
endif|#
directive|endif
endif|#
directive|endif
comment|/* not Solaris */
ifndef|#
directive|ifndef
name|TERMIOS
define|#
directive|define
name|TERMIOS
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAS_DOMAINNAME
define|#
directive|define
name|HAS_DOMAINNAME
value|1
endif|#
directive|endif
endif|#
directive|endif
comment|/* sun */
ifdef|#
directive|ifdef
name|__sgi
ifndef|#
directive|ifndef
name|sgi
define|#
directive|define
name|sgi
value|1
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sgi
define|#
directive|define
name|System
value|"IRIX"
ifndef|#
directive|ifndef
name|SYSV
define|#
directive|define
name|SYSV
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HERROR
define|#
directive|define
name|HERROR
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|U_WAIT
define|#
directive|define
name|U_WAIT
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|STRICT_PROTOS
define|#
directive|define
name|STRICT_PROTOS
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|TERMIOS
define|#
directive|define
name|TERMIOS
value|1
endif|#
directive|endif
endif|#
directive|endif
comment|/* sgi */
ifdef|#
directive|ifdef
name|AIX
define|#
directive|define
name|System
value|"AIX 2.2.1"
define|#
directive|define
name|BSD_INCLUDES
define|#
directive|define
name|SYSV
define|#
directive|define
name|NO_STDLIB
define|#
directive|define
name|NO_UTIME_H
define|#
directive|define
name|NO_STRFTIME
define|#
directive|define
name|NO_STRSTR
define|#
directive|define
name|NO_MKTIME
endif|#
directive|endif
comment|/* AIX */
ifdef|#
directive|ifdef
name|_AIX
define|#
directive|define
name|System
value|"AIX 3.x"
define|#
directive|define
name|SYSSELECTH
value|1
define|#
directive|define
name|TERMIOS
value|1
endif|#
directive|endif
comment|/* _AIX */
ifdef|#
directive|ifdef
name|__QNX__
define|#
directive|define
name|QNX
define|#
directive|define
name|System
value|"QNX 4.21 (POSIX)"
define|#
directive|define
name|SYSSELECTH
define|#
directive|define
name|TERMIOS
define|#
directive|define
name|_POSIX_SOURCE
define|#
directive|define
name|GETCWDSIZET
define|#
directive|define
name|STRICT_PROTOS
define|#
directive|define
name|RINDEX
define|#
directive|define
name|NO_CURSES_H
define|#
directive|define
name|unlink
value|remove
define|#
directive|define
name|bcopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|memcpy((d),(s),(l))
define|#
directive|define
name|bzero
parameter_list|(
name|cp
parameter_list|,
name|l
parameter_list|)
value|memset((cp),0,(l))
define|#
directive|define
name|NO_SYSPARAM
include|#
directive|include
file|<limits.h>
define|#
directive|define
name|NCARGS
value|_POSIX_ARG_MAX
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SCOXNX
define|#
directive|define
name|System
value|"SCO Xenix"
define|#
directive|define
name|LAI_TCP
define|#
directive|define
name|NO_UTIMEH
define|#
directive|define
name|NO_MKTIME
define|#
directive|define
name|NO_STRFTIME
define|#
directive|define
name|NO_STRSTR
define|#
directive|define
name|NO_RENAME
define|#
directive|define
name|LINGER
comment|/* else SCO bug causes incomplete transfers */
define|#
directive|define
name|SYSV
value|1
endif|#
directive|endif
comment|/* SCOXNX */
ifdef|#
directive|ifdef
name|SCO322
define|#
directive|define
name|System
value|"SCO Unix 3.2v2"
define|#
directive|define
name|BOTCHED_FOPEN_RW
define|#
directive|define
name|NO_RENAME
comment|/* it exists, but it corrupts filesystems */
define|#
directive|define
name|BROKEN_MEMCPY
value|1
define|#
directive|define
name|SYSV
value|1
endif|#
directive|endif
comment|/* SCO322 */
ifdef|#
directive|ifdef
name|SCO324
define|#
directive|define
name|System
value|"SCO Unix 3.2v4"
ifndef|#
directive|ifndef
name|SYSV
define|#
directive|define
name|SYSV
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|BROKEN_MEMCPY
define|#
directive|define
name|BROKEN_MEMCPY
value|1
endif|#
directive|endif
endif|#
directive|endif
comment|/* SCO324 */
ifdef|#
directive|ifdef
name|linux
define|#
directive|define
name|System
value|"Linux"
ifndef|#
directive|ifndef
name|HAS_DOMAINNAME
define|#
directive|define
name|HAS_DOMAINNAME
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|TERMIOS
define|#
directive|define
name|TERMIOS
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SYSV
define|#
directive|define
name|SYSV
value|1
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ISC
define|#
directive|define
name|System
value|"Interactive Unix"
ifndef|#
directive|ifndef
name|SYSV
define|#
directive|define
name|SYSV
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|BROKEN_MEMCPY
define|#
directive|define
name|BROKEN_MEMCPY
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NET_ERRNO_H
define|#
directive|define
name|NET_ERRNO_H
value|1
endif|#
directive|endif
endif|#
directive|endif
comment|/* ISC */
ifdef|#
directive|ifdef
name|aux
define|#
directive|define
name|System
value|"A/UX"
ifndef|#
directive|ifndef
name|BROKEN_MEMCPY
define|#
directive|define
name|BROKEN_MEMCPY
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SYSV
define|#
directive|define
name|SYSV
value|1
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NeXT
define|#
directive|define
name|System
value|"NeXTStep"
ifndef|#
directive|ifndef
name|RINDEX
define|#
directive|define
name|RINDEX
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|BSD
define|#
directive|define
name|BSD
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_UNISTDH
define|#
directive|define
name|NO_UNISTDH
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_UTIMEH
define|#
directive|define
name|NO_UTIMEH
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAS_DOMAINNAME
define|#
directive|define
name|HAS_DOMAINNAME
value|1
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|pyr
define|#
directive|define
name|System
value|"OSx"
ifndef|#
directive|ifndef
name|BSD
define|#
directive|define
name|BSD
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SGTTYB
define|#
directive|define
name|SGTTYB
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_STDLIBH
define|#
directive|define
name|NO_STDLIBH
value|1
endif|#
directive|endif
specifier|extern
name|int
name|errno
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pyr */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DYNIXPTX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DYNIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|DYNIXPTX
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
name|DYNIXPTX
end_if

begin_define
define|#
directive|define
name|System
value|"Dynix/PTX"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV
end_ifndef

begin_define
define|#
directive|define
name|SYSV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRY_NOREPLY
end_ifndef

begin_define
define|#
directive|define
name|TRY_NOREPLY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gettimeofday
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|get_process_stats(a, getpid(), 0, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNIXPTX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNIX
end_ifdef

begin_define
define|#
directive|define
name|System
value|"Dynix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SGTTYB
end_ifndef

begin_define
define|#
directive|define
name|SGTTYB
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UTIMEH
end_ifndef

begin_define
define|#
directive|define
name|NO_UTIMEH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STDLIBH
end_ifndef

begin_define
define|#
directive|define
name|NO_STDLIBH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VARARGS
end_ifndef

begin_define
define|#
directive|define
name|NO_VARARGS
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

begin_comment
comment|/* DYNIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_define
define|#
directive|define
name|System
value|"Ultrix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_GETPWUID
end_ifndef

begin_define
define|#
directive|define
name|USE_GETPWUID
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CONST
end_ifndef

begin_define
define|#
directive|define
name|NO_CONST
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ultrix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX
end_ifndef

begin_define
define|#
directive|define
name|HPUX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Select
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|select((a), (int *)(b), (c), (d), (e))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX
end_ifdef

begin_define
define|#
directive|define
name|System
value|"HP-UX"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_HPUX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_HPUX_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GETCWDSIZET
end_ifndef

begin_define
define|#
directive|define
name|GETCWDSIZET
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYSV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SINIX
end_ifdef

begin_define
define|#
directive|define
name|System
value|"SINIX"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV
end_ifndef

begin_define
define|#
directive|define
name|SYSV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* You may need to add -lresolv, -lport, -lcurses to MORELIBS in Makefile. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BULL
end_ifdef

begin_comment
comment|/* added 23nov92 for Bull DPX/2 */
end_comment

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|_XOPEN_SOURCE
end_define

begin_define
define|#
directive|define
name|_BULL_SOURCE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV
end_ifndef

begin_define
define|#
directive|define
name|SYSV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bull
end_define

begin_define
define|#
directive|define
name|System
value|"Bull DPX/2 BOS"
end_define

begin_define
define|#
directive|define
name|SYSSELECTH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BULL */
end_comment

begin_comment
comment|/* added 23nov92 for Bull DPX/2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__dgux
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DGUX
end_ifndef

begin_define
define|#
directive|define
name|DGUX
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

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_DGUX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_DGUX_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GETCWDSIZET
value|1
end_define

begin_define
define|#
directive|define
name|BAD_INETADDR
value|1
end_define

begin_define
define|#
directive|define
name|SYSV
value|1
end_define

begin_define
define|#
directive|define
name|System
value|"DG/UX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
value|43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NO_UTIMEH
value|1
end_define

begin_define
define|#
directive|define
name|System
value|"Apollo"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__Besta__
end_ifdef

begin_define
define|#
directive|define
name|SYSV
value|1
end_define

begin_define
define|#
directive|define
name|SYSSELECTH
value|1
end_define

begin_define
define|#
directive|define
name|NO_UNISTDH
value|1
end_define

begin_define
define|#
directive|define
name|NO_STDLIBH
value|1
end_define

begin_define
define|#
directive|define
name|NO_UTIMEH
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BROKEN_MEMCPY
end_ifndef

begin_define
define|#
directive|define
name|BROKEN_MEMCPY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__osf__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha
end_ifdef

begin_comment
comment|/* DEC OSF/1 */
end_comment

begin_define
define|#
directive|define
name|GETCWDSIZET
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

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYSV
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV
end_ifndef

begin_define
define|#
directive|define
name|SYSV
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

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV
end_ifndef

begin_define
define|#
directive|define
name|SYSV
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

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
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

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|System
end_ifndef

begin_define
define|#
directive|define
name|System
value|"System V.4"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV
end_ifndef

begin_define
define|#
directive|define
name|SYSV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VOID
end_ifndef

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HERROR
end_ifndef

begin_define
define|#
directive|define
name|HERROR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TERMH
end_ifdef

begin_define
define|#
directive|define
name|TERMH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Gettimeofday
end_ifndef

begin_define
define|#
directive|define
name|Gettimeofday
value|gettimeofday
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
comment|/* SVR4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|RINDEX
end_ifndef

begin_define
define|#
directive|define
name|RINDEX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|memcpy((d),(s),(l))
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|cp
parameter_list|,
name|l
parameter_list|)
value|memset((cp),0,(l))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_GETCWD
end_ifndef

begin_define
define|#
directive|define
name|HAS_GETCWD
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

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_define
define|#
directive|define
name|System
value|"BSDi"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYSSELECTH
end_ifndef

begin_define
define|#
directive|define
name|SYSSELECTH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GETCWDSIZET
end_ifndef

begin_define
define|#
directive|define
name|GETCWDSIZET
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HERROR
end_ifndef

begin_define
define|#
directive|define
name|HERROR
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

begin_comment
comment|/* BSDi */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|System
value|"FreeBSD"
end_define

begin_define
define|#
directive|define
name|GZCAT
value|"/usr/bin/gzcat"
end_define

begin_define
define|#
directive|define
name|HAS_DOMAINNAME
value|1
end_define

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

begin_comment
comment|/* this two for BSD definition */
end_comment

begin_comment
comment|/* to avoid redefinition of it to 1 */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD__
operator|>
literal|1
end_if

begin_define
define|#
directive|define
name|SYSSELECTH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HERROR
value|1
end_define

begin_define
define|#
directive|define
name|TERMIOS
value|1
end_define

begin_define
define|#
directive|define
name|HAS_GETCWD
value|1
end_define

begin_define
define|#
directive|define
name|U_WAIT
value|1
end_define

begin_define
define|#
directive|define
name|NO_CONST
value|1
end_define

begin_comment
comment|/* avoid prototype conflict */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|SYSDIRH
end_ifndef

begin_define
define|#
directive|define
name|SYSDIRH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SGTTYB
end_ifndef

begin_define
define|#
directive|define
name|SGTTYB
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

begin_comment
comment|/*  * Generic pointer type, e.g. as returned by malloc().  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PTRTYPE
end_ifndef

begin_define
define|#
directive|define
name|PTRTYPE
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Free
end_ifndef

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|a
parameter_list|)
value|free((PTRTYPE *)(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Some systems besides System V don't use rindex/index (like SunOS).  * Add -DRINDEX to your SDEFS line if you need to.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RINDEX
end_ifdef

begin_comment
comment|/* or #include<strings.h> if you have it. */
end_comment

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RINDEX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKS
end_ifdef

begin_define
define|#
directive|define
name|Getsockname
parameter_list|(
name|d
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
value|Rgetsockname((d), (struct sockaddr *)(a), (l))
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|Getsockname
parameter_list|(
name|d
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
value|getsockname((d), (void *)(a), (l))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Getsockname
parameter_list|(
name|d
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
value|getsockname((d), (struct sockaddr *)(a), (l))
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
name|Select
end_ifndef

begin_define
define|#
directive|define
name|Select
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|select((a), (b), (c), (d), (e))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Connect
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4
end_ifndef

begin_define
define|#
directive|define
name|Connect
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(connect((a), (struct sockaddr *)(b), (int)(c)))
end_define

begin_define
define|#
directive|define
name|Bind
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bind((a), (struct sockaddr *)(b), (int)(c)))
end_define

begin_define
define|#
directive|define
name|Accept
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(accept((a), (struct sockaddr *)(b), (int *)(c)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SVR4 */
end_comment

begin_define
define|#
directive|define
name|Connect
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(connect((a), (caddr_t)(b), (int)(c)))
end_define

begin_define
define|#
directive|define
name|Bind
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bind((a), (caddr_t)(b), (int)(c)))
end_define

begin_define
define|#
directive|define
name|Accept
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(accept((a), (caddr_t)(b), (int *)(c)))
end_define

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
comment|/* Connect */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Gettimeofday
end_ifndef

begin_define
define|#
directive|define
name|Gettimeofday
parameter_list|(
name|a
parameter_list|)
value|gettimeofday(a, (struct timezone *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Gettimeofday */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GETPASS
end_ifdef

begin_define
define|#
directive|define
name|Getpass
value|getpass
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable connections through firewall gateways */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GATEWAY
end_ifndef

begin_define
define|#
directive|define
name|GATEWAY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_define
define|#
directive|define
name|TERMIOS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include frequently used headers: */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYSPARAM
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STDLIBH
end_ifndef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|PTRTYPE
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PTRTYPE
modifier|*
name|calloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PTRTYPE
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|(
name|PTRTYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PTRTYPE
modifier|*
name|realloc
parameter_list|(
name|PTRTYPE
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NO_CONST
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|atoi
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|atoi
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_STDLIBH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UNISTDH
end_ifndef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|getlogin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NO_CONST
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_UNISTDH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_STD_PROTOS
end_ifdef

begin_function_decl
specifier|extern
name|int
name|_filbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_flsbuf
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fflush
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fgetc
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fputc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fputs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|perror
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rewind
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sscanf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vfprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rename
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|struct
name|timezone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|mktime
parameter_list|(
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strftime
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|(
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tolower
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|toupper
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|bcopy
end_ifndef

begin_function_decl
specifier|extern
name|void
name|bcopy
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bzero
end_ifndef

begin_function_decl
specifier|extern
name|void
name|bzero
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKS
end_ifdef

begin_function_decl
specifier|extern
name|int
name|Raccept
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Rbind
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Rconnect
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Rlisten
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Rgetsockname
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|accept
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bind
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|connect
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|listen
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getsockname
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|gethostname
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|getdomainname
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|Select
end_ifndef

begin_function_decl
specifier|extern
name|int
name|select
parameter_list|(
name|int
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|send
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setsockopt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shutdown
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|socket
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_STD_PROTOS */
end_comment

begin_comment
comment|/* This malloc stuff is mostly for our own use. */
end_comment

begin_define
define|#
directive|define
name|LIBC_MALLOC
value|0
end_define

begin_define
define|#
directive|define
name|FAST_MALLOC
value|1
end_define

begin_define
define|#
directive|define
name|DEBUG_MALLOC
value|2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LIBMALLOC
end_ifdef

begin_if
if|#
directive|if
name|LIBMALLOC
operator|!=
name|LIBC_MALLOC
end_if

begin_comment
comment|/* Make sure you use -I to use the malloc.h of choice. */
end_comment

begin_include
include|#
directive|include
file|<malloc.h>
end_include

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
name|LIBMALLOC
value|LIBC_MALLOC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End of personal malloc junk. */
end_comment

begin_comment
comment|/* eof sys.h */
end_comment

end_unit

