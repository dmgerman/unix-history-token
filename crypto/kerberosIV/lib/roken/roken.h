begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the Kungliga Tekniska  *      Högskolan and its contributors.  *   * 4. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: roken.h,v 1.63 1997/05/28 05:38:09 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ROKEN_H__
end_ifndef

begin_define
define|#
directive|define
name|__ROKEN_H__
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

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
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GRP_H
end_ifdef

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS_H
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
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
name|HAVE_SYS_IOCTL_H
argument_list|)
operator|&&
name|SunOS
operator|!=
literal|4
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

begin_include
include|#
directive|include
file|"protos.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SETSID
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE__SETSID
argument_list|)
end_if

begin_define
define|#
directive|define
name|setsid
value|_setsid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PUTENV
end_ifndef

begin_function_decl
name|int
name|putenv
parameter_list|(
specifier|const
name|char
modifier|*
name|string
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
name|HAVE_SETENV
end_ifndef

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|const
name|char
modifier|*
name|var
parameter_list|,
specifier|const
name|char
modifier|*
name|val
parameter_list|,
name|int
name|rewrite
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
name|HAVE_UNSETENV
end_ifndef

begin_function_decl
name|void
name|unsetenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
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
name|HAVE_GETUSERSHELL
end_ifndef

begin_function_decl
name|char
modifier|*
name|getusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__attribute__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SNPRINTF
end_ifndef

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|sz
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VSNPRINTF
end_ifndef

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|sz
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ASPRINTF
end_ifndef

begin_function_decl
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|ret
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VASPRINTF
end_ifndef

begin_function_decl
name|int
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|ret
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ASNPRINTF
end_ifndef

begin_function_decl
name|int
name|asnprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|ret
parameter_list|,
name|size_t
name|max_sz
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VASNPRINTF
end_ifndef

begin_function_decl
name|int
name|vasnprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|ret
parameter_list|,
name|size_t
name|max_sz
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRDUP
end_ifndef

begin_function_decl
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|old
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
name|HAVE_STRLWR
end_ifndef

begin_function_decl
name|char
modifier|*
name|strlwr
parameter_list|(
name|char
modifier|*
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
name|HAVE_STRNLEN
end_ifndef

begin_function_decl
name|int
name|strnlen
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
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
name|HAVE_STRTOK_R
end_ifndef

begin_function_decl
name|char
modifier|*
name|strtok_r
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|char
modifier|*
modifier|*
name|lasts
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
name|HAVE_STRUPR
end_ifndef

begin_function_decl
name|char
modifier|*
name|strupr
parameter_list|(
name|char
modifier|*
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
name|HAVE_GETDTABLESIZE
end_ifndef

begin_function_decl
name|int
name|getdtablesize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|IRIX
operator|!=
literal|4
end_if

begin_comment
comment|/* fix for compiler bug */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RETSIGTYPE
end_ifdef

begin_typedef
typedef|typedef
name|RETSIGTYPE
function_decl|(
modifier|*
name|SigAction
function_decl|)
parameter_list|(
comment|/* int??? */
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|SigAction
name|signal
parameter_list|(
name|int
name|iSig
parameter_list|,
name|SigAction
name|pAction
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* BSD compatible */
end_comment

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
name|SIG_ERR
end_ifndef

begin_define
define|#
directive|define
name|SIG_ERR
value|((RETSIGTYPE (*)())-1)
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
name|HAVE_STRERROR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|strerror
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|strerror
parameter_list|(
name|int
name|eno
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
name|HAVE_HSTRERROR
end_ifndef

begin_function_decl
name|char
modifier|*
name|hstrerror
parameter_list|(
name|int
name|herr
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
name|HAVE_H_ERRNO_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INET_ATON
end_ifndef

begin_comment
comment|/* Minimal implementation of inet_aton. Doesn't handle hex numbers. */
end_comment

begin_function_decl
name|int
name|inet_aton
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|struct
name|in_addr
modifier|*
name|adr
parameter_list|)
function_decl|;
end_function_decl

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
name|HAVE_GETCWD
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|getcwd
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|size_t
name|size
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
name|HAVE_GETENT
end_ifndef

begin_function_decl
name|int
name|getent
parameter_list|(
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
name|name
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
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_function_decl
name|struct
name|passwd
modifier|*
name|k_getpwnam
parameter_list|(
name|char
modifier|*
name|user
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|k_getpwuid
parameter_list|(
name|uid_t
name|uid
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
name|HAVE_SETEUID
end_ifndef

begin_function_decl
name|int
name|seteuid
parameter_list|(
name|int
name|euid
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
name|HAVE_SETEGID
end_ifndef

begin_function_decl
name|int
name|setegid
parameter_list|(
name|int
name|egid
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
name|HAVE_LSTAT
end_ifndef

begin_function_decl
name|int
name|lstat
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|stat
modifier|*
name|buf
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
name|HAVE_MKSTEMP
end_ifndef

begin_function_decl
name|int
name|mkstemp
parameter_list|(
name|char
modifier|*
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
name|HAVE_INITGROUPS
end_ifndef

begin_function_decl
name|int
name|initgroups
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|gid_t
name|basegid
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
name|HAVE_FCHOWN
end_ifndef

begin_function_decl
name|int
name|fchown
parameter_list|(
name|int
name|fd
parameter_list|,
name|uid_t
name|owner
parameter_list|,
name|gid_t
name|group
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
name|HAVE_CHOWN
end_ifndef

begin_function_decl
name|int
name|chown
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|uid_t
name|owner
parameter_list|,
name|gid_t
name|group
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
name|HAVE_RCMD
end_ifndef

begin_function_decl
name|int
name|rcmd
parameter_list|(
name|char
modifier|*
modifier|*
name|ahost
parameter_list|,
name|unsigned
name|short
name|inport
parameter_list|,
specifier|const
name|char
modifier|*
name|locuser
parameter_list|,
specifier|const
name|char
modifier|*
name|remuser
parameter_list|,
specifier|const
name|char
modifier|*
name|cmd
parameter_list|,
name|int
modifier|*
name|fd2p
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
name|TIME_WITH_SYS_TIME
end_ifdef

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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_TIME_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|time_t
name|tm2time
parameter_list|(
name|struct
name|tm
name|tm
parameter_list|,
name|int
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unix_verify_user
parameter_list|(
name|char
modifier|*
name|user
parameter_list|,
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inaddr2str
parameter_list|(
name|struct
name|in_addr
name|addr
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mini_inetd
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_WINSIZE
end_ifndef

begin_struct
struct|struct
name|winsize
block|{
name|unsigned
name|short
name|ws_row
decl_stmt|,
name|ws_col
decl_stmt|;
name|unsigned
name|short
name|ws_xpixel
decl_stmt|,
name|ws_ypixel
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|get_window_size
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|winsize
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_ifndef
ifndef|#
directive|ifndef
name|SOMAXCONN
end_ifndef

begin_define
define|#
directive|define
name|SOMAXCONN
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSLOG_H
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_comment
comment|/* Misc definitions for old syslogs */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_DAEMON
end_ifndef

begin_define
define|#
directive|define
name|openlog
parameter_list|(
name|id
parameter_list|,
name|option
parameter_list|,
name|facility
parameter_list|)
value|openlog((id),(option))
end_define

begin_define
define|#
directive|define
name|LOG_DAEMON
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_ODELAY
end_ifndef

begin_define
define|#
directive|define
name|LOG_ODELAY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_NDELAY
end_ifndef

begin_define
define|#
directive|define
name|LOG_NDELAY
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_CONS
end_ifndef

begin_define
define|#
directive|define
name|LOG_CONS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_AUTH
end_ifndef

begin_define
define|#
directive|define
name|LOG_AUTH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_AUTHPRIV
end_ifndef

begin_define
define|#
directive|define
name|LOG_AUTHPRIV
value|LOG_AUTH
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
name|HAVE_OPTARG_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_OPTIND_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_OPTERR_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|opterr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___PROGNAME_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|__progname
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|set_progname
parameter_list|(
name|char
modifier|*
name|argv0
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PATHS_H
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEVNULL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
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
comment|/*  __ROKEN_H__ */
end_comment

end_unit

