begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 1993,1994 by Paul Vixie  * All rights reserved  *  * Distribute freely, except: don't remove my name from the source or  * documentation (don't take credit for my work), mark your changes (don't  * get me blamed for your possible bugs), don't alter or remove this  * notice.  May be sold if buildable source is provided to buyer.  No  * warrantee of any kind, express or implied, is included with this  * software; use at your own risk, responsibility for damages (if any) to  * anyone resulting from the use of this software rests entirely with the  * user.  *  * Send bug reports, bug fixes, enhancements, requests, flames, etc., and  * I'll try to keep a version up to date.  I can be reached as follows:  * Paul Vixie<paul@vix.com>          uunet!decwrl!vixie!paul  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|const
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
name|defined
argument_list|(
name|UNIXPC
argument_list|)
operator|||
name|defined
argument_list|(
name|unixpc
argument_list|)
end_if

begin_define
define|#
directive|define
name|UNIXPC
value|1
end_define

begin_define
define|#
directive|define
name|ATT
value|1
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
name|_hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|HPUX
value|1
end_define

begin_define
define|#
directive|define
name|seteuid
parameter_list|(
name|e
parameter_list|)
value|setresuid(-1,e,-1)
end_define

begin_define
define|#
directive|define
name|setreuid
parameter_list|(
name|r
parameter_list|,
name|e
parameter_list|)
value|setresuid(r,e,-1)
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
name|_IBMR2
argument_list|)
end_if

begin_define
define|#
directive|define
name|AIX
value|1
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
name|__convex__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONVEX
value|1
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
name|sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|_sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_define
define|#
directive|define
name|IRIX
value|1
end_define

begin_comment
comment|/* IRIX 4 hdrs are broken: one cannot #include both<stdio.h>  * and<stdlib.h> because they disagree on system(), perror().  * Therefore we must zap the "const" keyword BEFORE including  * either of them.  */
end_comment

begin_define
define|#
directive|define
name|const
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
name|_UNICOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|UNICOS
value|1
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

begin_if
if|#
directive|if
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|||
name|defined
argument_list|(
name|__linux
argument_list|)
operator|||
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|AIX
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|HPUX
argument_list|)
operator|||
name|defined
argument_list|(
name|CONVEX
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD
value|198902
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
comment|/*****************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HPUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONVEX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__linux
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_VFORK
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
name|BSD
argument_list|)
operator|||
operator|(
name|BSD
operator|<
literal|198902
operator|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__linux
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|IRIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HPUX
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_STRCASECMP
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
name|BSD
argument_list|)
operator|||
operator|(
name|BSD
operator|<
literal|198911
operator|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__linux
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|IRIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UNICOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HPUX
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_STRDUP
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
name|BSD
argument_list|)
operator|||
operator|(
name|BSD
operator|<
literal|198911
operator|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_STRERROR
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
name|HPUX
argument_list|)
operator|||
name|defined
argument_list|(
name|AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|UNIXPC
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_FLOCK
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

begin_define
define|#
directive|define
name|NEED_SETSID
end_define

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
name|POSIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__linux
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_GETDTABLESIZE
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

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SAVED_IDS
end_ifdef

begin_define
define|#
directive|define
name|HAVE_SAVED_UIDS
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
operator|!
name|defined
argument_list|(
name|ATT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__linux
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|IRIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UNICOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_SIGCHLD
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
name|AIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UNICOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYS_TIME_H
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYS_TIME_H
value|0
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
name|BSD
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
name|USE_UTIMES
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
name|AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|HPUX
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_SETENV
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
name|UNICOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXPC
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_FCHOWN
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
name|UNICOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXPC
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_FCHMOD
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

