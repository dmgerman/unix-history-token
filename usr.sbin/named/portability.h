begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* defs.h - include or define things that aren't present on all systems  * vixie@decwrl 26dec92 [new]  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * ++Copyright++  * -  * Copyright (c)  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/* XXX:	this file has become a hopeless morass, and will be redone someday. */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|TIME_H_INCLUDED
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|TIME_H_INCLUDED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYSV
end_define

begin_define
define|#
directive|define
name|SVR3
end_define

begin_define
define|#
directive|define
name|_SYSV3
end_define

begin_define
define|#
directive|define
name|NEED_STRTOUL
end_define

begin_define
define|#
directive|define
name|NEED_FTRUNCATE
end_define

begin_define
define|#
directive|define
name|USE_POSIX
end_define

begin_include
include|#
directive|include
file|<sys/bsdtypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/sioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/stream.h>
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__convex__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_define
define|#
directive|define
name|NEED_PUTENV
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
name|_CRAY
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|writev
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__writev(a,b,c)
end_define

begin_define
define|#
directive|define
name|setitimer
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__setitimer(a,b,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is defined in the Makefile for ISC compiles. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ISC
argument_list|)
end_if

begin_define
define|#
directive|define
name|ftruncate
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ftruncate(a,b)
end_define

begin_define
define|#
directive|define
name|USE_MEMCPY
end_define

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCO UNIX defines only this unique symbol, apparently. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|M_UNIX
argument_list|)
end_if

begin_comment
comment|/* XXX - why is this POSIX_SOURCE instead of _POSIX_SOURCE? */
end_comment

begin_undef
undef|#
directive|undef
name|POSIX_SOURCE
end_undef

begin_define
define|#
directive|define
name|POSIX_SIGNALS
end_define

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|0
end_define

begin_define
define|#
directive|define
name|writev
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__writev(a,b,c)
end_define

begin_define
define|#
directive|define
name|ftruncate
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ftruncate(a,b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NeXT
end_ifdef

begin_define
define|#
directive|define
name|NEED_PUTENV
end_define

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
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD
value|43
end_define

begin_define
define|#
directive|define
name|vfork
value|fork
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
name|SUNOS4
argument_list|)
end_if

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AUX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

begin_define
define|#
directive|define
name|NEED_STRERROR
end_define

begin_define
define|#
directive|define
name|NEED_STRTOUL
end_define

begin_define
define|#
directive|define
name|SIG_FN
value|void
end_define

begin_define
define|#
directive|define
name|USE_MEMCPY
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
name|SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SYSV
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSV
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
name|_POSIX_SOURCE
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|__ultrix
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|USE_POSIX
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
name|__ultrix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD
value|42
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
name|host_mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|SYSTYPE_BSD43
argument_list|)
end_if

begin_define
define|#
directive|define
name|RISCOS_BSD
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
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|__ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|__osf__
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
name|BSD
operator|>=
literal|199306
operator|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_define
define|#
directive|define
name|HAVE_SETVBUF
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
name|SYSV
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SVR4
argument_list|)
end_if

begin_define
define|#
directive|define
name|vfork
value|fork
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
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|SVR4
argument_list|)
end_if

begin_define
define|#
directive|define
name|NETREAD_BROKEN
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
name|BSD
operator|>=
literal|199006
operator|&&
operator|!
name|defined
argument_list|(
name|i386
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|RISCOS_BSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_DAEMON
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
name|BSD
argument_list|)
operator|||
operator|(
name|BSD
operator|<=
literal|199006
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_INETADDR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NEED_INETATON
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
name|__hpux
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|select
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
value|select(a, (int *)b, (int *)c, (int *)d, e)
end_define

begin_define
define|#
directive|define
name|ctime
parameter_list|(
name|x
parameter_list|)
value|ctime((const time_t *)x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__STDC__*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYSV
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_define
define|#
directive|define
name|setlinebuf
parameter_list|(
name|x
parameter_list|)
value|setvbuf(x, NULL, _IOLBF, BUFSIZ)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIGWINCH
argument_list|)
end_if

begin_comment
comment|/*pre 9.0*/
end_comment

begin_define
define|#
directive|define
name|SIGWINCH
value|SIGWINDOW
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
comment|/*SYSV*/
end_comment

begin_comment
comment|/* XXX: better autodetection of the need for "struct linger" would be nice */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|struct	linger { 	int	l_onoff;
comment|/* option on/off */
end_comment

begin_comment
unit|int	l_linger;
comment|/* linger time */
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__hpux*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SEQUENT_
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_define
define|#
directive|define
name|USE_POSIX
end_define

begin_define
define|#
directive|define
name|NEED_GETTIMEOFDAY
end_define

begin_define
define|#
directive|define
name|_TIMEZONE
value|timezoneBSD
end_define

begin_struct
struct|struct
name|timezoneBSD
block|{
name|int
name|tz_minuteswest
decl_stmt|;
name|int
name|tz_dsttime
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

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
name|_TIMEZONE
end_ifndef

begin_define
define|#
directive|define
name|_TIMEZONE
value|timezone
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
name|USE_POSIX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NEED_STRTOUL
end_define

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NeXT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DMALLOC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|,
modifier|*
name|calloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
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

begin_decl_stmt
specifier|extern
name|int
name|getdtablesize
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SHORT_FNAMES
end_ifdef

begin_decl_stmt
specifier|extern
name|long
name|pathconf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|path
operator|,
name|int
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*USE_POSIX*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UINT_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|UINT_MAX
value|4294967295u
end_define

begin_comment
comment|/* max value of an "u_int" */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UINT_MAX
value|((unsigned)4294967295)
end_define

begin_comment
comment|/* max value of an "u_int" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ULONG_MAX
value|UINT_MAX
end_define

begin_comment
comment|/* max decimal value of a "u_long" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT_MAX
value|2147483647
end_define

begin_comment
comment|/* max decimal value of an "int" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RAND_MAX
end_ifndef

begin_define
define|#
directive|define
name|RAND_MAX
value|0x7fffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN_LOOPBACKNET
end_ifndef

begin_define
define|#
directive|define
name|IN_LOOPBACKNET
value|127
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INADDR_NONE
end_ifndef

begin_define
define|#
directive|define
name|INADDR_NONE
value|0xffffffff
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
name|apollo
argument_list|)
end_if

begin_comment
comment|/* Defined in /usr/include/netinet/in.h but doesn't work */
end_comment

begin_undef
undef|#
directive|undef
name|IP_OPTIONS
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
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|const
argument_list|)
end_if

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/*constant*/
end_comment

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
name|__convex__
argument_list|)
operator|&&
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
literal|199103
operator|)
operator|)
end_if

begin_decl_stmt
name|int
name|strcasecmp
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* is USE_POSIX the right thing to use here? */
end_comment

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
operator|<=
literal|43
operator|)
operator|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__convex__
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|USE_POSIX
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NCR
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|syslog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ctime
name|__P
argument_list|(
operator|(
specifier|const
name|time_t
operator|*
name|clock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|close
argument_list|()
decl_stmt|,
name|setitimer
argument_list|()
decl_stmt|,
name|recv
argument_list|()
decl_stmt|,
name|sendto
argument_list|()
decl_stmt|,
name|sigsetmask
argument_list|()
decl_stmt|,
name|atoi
argument_list|()
decl_stmt|,
name|getpid
argument_list|()
decl_stmt|,
name|fork
argument_list|()
decl_stmt|,
name|read
argument_list|()
decl_stmt|,
name|ioctl
argument_list|()
decl_stmt|,
name|setsockopt
argument_list|()
decl_stmt|,
name|socket
argument_list|()
decl_stmt|,
name|bind
argument_list|()
decl_stmt|;
end_decl_stmt

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
name|bcopy
argument_list|)
end_if

begin_comment
comment|/* some machines have their own macros for this */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_POSIX
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sequent
argument_list|)
operator|)
end_if

begin_comment
comment|/* use ANSI C3.159-1989 (``ANSI C'') functions if possible;  * ideally we would change the code to use them and then  * define them in terms of bcopy et al if !defined(__STDC__)  * but that's more work.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_MEMCPY
argument_list|)
end_if

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy(b,a,c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memmove(b,a,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset(a,0,b)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcmp(a,b,c)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bzero
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bcmp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bcopy */
end_comment

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
literal|43
operator|)
operator|||
name|defined
argument_list|(
name|RISCOS_BSD
argument_list|)
operator|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|USE_POSIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|apollo
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sequent
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|M_UNIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_STRERROR
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NCR
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_PUTENV
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
name|SUNOS4
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_STRERROR
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun386
argument_list|)
end_if

begin_define
define|#
directive|define
name|pid_t
value|int
end_define

begin_define
define|#
directive|define
name|NEED_STRCASECMP
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
literal|43
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|NEED_MKSTEMP
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ultrix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|apollo
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_STRCASECMP
end_define

begin_define
define|#
directive|define
name|NEED_MKTEMP
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SVR4
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_STRPBRK
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_POSIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|POSIX_SIGNALS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Attempt to configure for type of function returned by signal-catching  * functions (which signal and sigvec.sv_handler take a pointer to).  * This can guess for BSD; otherwise, define SIG_FN externally.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_FN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_if
if|#
directive|if
operator|(
name|BSD
operator|>=
literal|199006
operator|)
operator|||
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|||
name|defined
argument_list|(
name|sun
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|apollo
argument_list|)
operator|||
name|defined
argument_list|(
name|POSIX_SIGNALS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIG_FN
value|void
end_define

begin_comment
comment|/* signal-catching functions return void */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIG_FN
value|int
end_define

begin_comment
comment|/* signal-catching functions return int */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*BSD*/
end_comment

begin_define
define|#
directive|define
name|SIG_FN
value|void
end_define

begin_comment
comment|/* signal-catching functions return void */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*BSD*/
end_comment

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
name|ntohl
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|htonl
argument_list|)
operator|&&
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|<=
literal|43
operator|)
end_if

begin_comment
comment|/* if these aren't null macros in netinet/in.h, extern them here. */
end_comment

begin_decl_stmt
specifier|extern
name|u_short
name|htons
argument_list|()
decl_stmt|,
name|ntohs
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|htonl
argument_list|()
decl_stmt|,
name|ntohl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_POSIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sgi
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__convex__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ultrix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_AUX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PORT_NONBLOCK
value|O_NONBLOCK
end_define

begin_define
define|#
directive|define
name|PORT_WOULDBLK
value|EAGAIN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PORT_NONBLOCK
value|O_NDELAY
end_define

begin_define
define|#
directive|define
name|PORT_WOULDBLK
value|EWOULDBLOCK
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
name|USE_POSIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_SETSID
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
name|USE_POSIX
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|SYSV
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_WAITPID
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
name|USE_POSIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|waitpid
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(wait3(y,z,(struct rusage *)NULL))
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
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|sun386
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WIFSIGNALED
end_undef

begin_undef
undef|#
directive|undef
name|WTERMSIG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeXT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sequent
argument_list|)
end_if

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|x
parameter_list|)
value|((x).w_retcode)
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|x
parameter_list|)
value|((x).w_termsig)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sequent */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WIFEXITED
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|x
parameter_list|)
value|(!(x& 0177))
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
name|WEXITSTATUS
argument_list|)
end_if

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|x
parameter_list|)
value|(x>> 8)
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
name|WIFSIGNALED
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|x
parameter_list|)
value|((x& 0177)&& ((x& 0377) != 0177))
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
name|WTERMSIG
argument_list|)
end_if

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|x
parameter_list|)
value|(x& 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFMT
end_ifndef

begin_define
define|#
directive|define
name|S_IFMT
value|0170000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFDIR
end_ifndef

begin_define
define|#
directive|define
name|S_IFDIR
value|0040000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFMT
end_ifndef

begin_define
define|#
directive|define
name|S_IFMT
value|0170000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFREG
end_ifndef

begin_define
define|#
directive|define
name|S_IFREG
value|0100000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISFIFO
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFMT
end_ifndef

begin_define
define|#
directive|define
name|S_IFMT
value|0170000
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

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFIFO)
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
name|NEED_STRTOUL
argument_list|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|__ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|||
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|)
end_if

begin_undef
undef|#
directive|undef
name|NEED_STRTOUL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|__osf__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAYBE_HESIOD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SET
end_ifndef

begin_define
define|#
directive|define
name|NFDBITS
value|32
end_define

begin_define
define|#
directive|define
name|FD_SETSIZE
value|32
end_define

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS] |= (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]&= ~(1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]& (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|bzero((char *)(p), sizeof(*(p)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x> y) ?y :x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x> y) ?x :y)
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
name|PATH_MAX
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_PATH_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|PATH_MAX
value|_POSIX_PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MAXPATHLEN
argument_list|)
end_if

begin_define
define|#
directive|define
name|PATH_MAX
value|MAXPATHLEN
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|||
name|defined
argument_list|(
name|__convex__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* May be set in the Makefile. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETRUSAGE
argument_list|)
end_if

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
comment|/*  *  Because Convex has true library function feof() which is  *  patently wrong (it test bit _IOREAD) we need feof() as  *  a macro.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__convex__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|feof
argument_list|)
end_if

begin_define
define|#
directive|define
name|feof
parameter_list|(
name|p
parameter_list|)
value|((p)->_flag&_IOEOF)
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
name|M_UNIX
argument_list|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_define
define|#
directive|define
name|SPURIOUS_ECONNREFUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Assume that a system has fchmod() unless something above says otherwise.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_FCHMOD
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Prototype the functions we'll be supplying.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_PUTENV
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|putenv
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETTIMEOFDAY
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|gettimeofday
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|,
expr|struct
name|_TIMEZONE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

