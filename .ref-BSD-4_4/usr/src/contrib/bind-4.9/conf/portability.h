begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* defs.h - include or define things that aren't present on all systems  * vixie@decwrl 26dec92 [new]  *  * $Id: portability.h,v 1.1 1993/06/01 00:45:28 vixie Exp vixie $  */
end_comment

begin_comment
comment|/*  * ++Copyright++  * -  * Copyright (c)  Regents of the University of California.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__sgi
end_ifdef

begin_define
define|#
directive|define
name|BSD
value|43
end_define

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

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

begin_comment
comment|/* primative but it will do for now */
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
name|USE_WAIT3
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
name|ultrix
argument_list|)
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
end_if

begin_define
define|#
directive|define
name|USE_UTIME
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
name|defined
argument_list|(
name|_POSIX_SOURCE
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

begin_comment
comment|/*POSIX*/
end_comment

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|DMALLOC
end_ifndef

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

begin_comment
comment|/*POSIX*/
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
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|syslog
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

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
operator|!
name|defined
argument_list|(
name|BSD
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
name|int
name|strcasecmp
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

begin_decl_stmt
specifier|extern
name|void
name|bcopy
argument_list|()
decl_stmt|,
name|bzero
argument_list|()
decl_stmt|;
end_decl_stmt

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
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
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
operator|&&
operator|!
name|defined
argument_list|(
name|ultrix
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
name|NEED_STRTOUL
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
comment|/* BSD */
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
comment|/* BSD */
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
name|_POSIX_SOURCE
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
name|_POSIX_SOURCE
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
name|__osf__
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
operator|>
literal|43
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|RISCOS_BSD
argument_list|)
operator|)
end_if

begin_typedef
typedef|typedef
name|int
name|WAIT_T
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|union
name|wait
name|WAIT_T
typedef|;
end_typedef

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
name|WEXITSTATUS
argument_list|)
operator|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|WTERMSIG
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|x
parameter_list|)
value|(x).w_retcode
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|x
parameter_list|)
value|(x).w_termsig
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

