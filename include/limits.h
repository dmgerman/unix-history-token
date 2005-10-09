begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)limits.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIMITS_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIMITS_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
end_if

begin_define
define|#
directive|define
name|_POSIX_ARG_MAX
value|4096
end_define

begin_define
define|#
directive|define
name|_POSIX_CHILD_MAX
value|25
end_define

begin_define
define|#
directive|define
name|_POSIX_LINK_MAX
value|8
end_define

begin_define
define|#
directive|define
name|_POSIX_MAX_CANON
value|255
end_define

begin_define
define|#
directive|define
name|_POSIX_MAX_INPUT
value|255
end_define

begin_define
define|#
directive|define
name|_POSIX_NAME_MAX
value|14
end_define

begin_define
define|#
directive|define
name|_POSIX_NGROUPS_MAX
value|8
end_define

begin_define
define|#
directive|define
name|_POSIX_OPEN_MAX
value|20
end_define

begin_define
define|#
directive|define
name|_POSIX_PATH_MAX
value|256
end_define

begin_define
define|#
directive|define
name|_POSIX_PIPE_BUF
value|512
end_define

begin_define
define|#
directive|define
name|_POSIX_SSIZE_MAX
value|32767
end_define

begin_define
define|#
directive|define
name|_POSIX_STREAM_MAX
value|8
end_define

begin_define
define|#
directive|define
name|_POSIX_TZNAME_MAX
value|6
end_define

begin_define
define|#
directive|define
name|BC_BASE_MAX
value|99
end_define

begin_comment
comment|/* max ibase/obase values in bc(1) */
end_comment

begin_define
define|#
directive|define
name|BC_DIM_MAX
value|2048
end_define

begin_comment
comment|/* max array elements in bc(1) */
end_comment

begin_define
define|#
directive|define
name|BC_SCALE_MAX
value|99
end_define

begin_comment
comment|/* max scale value in bc(1) */
end_comment

begin_define
define|#
directive|define
name|BC_STRING_MAX
value|1000
end_define

begin_comment
comment|/* max const string length in bc(1) */
end_comment

begin_define
define|#
directive|define
name|COLL_WEIGHTS_MAX
value|0
end_define

begin_comment
comment|/* max weights for order keyword */
end_comment

begin_define
define|#
directive|define
name|EXPR_NEST_MAX
value|32
end_define

begin_comment
comment|/* max expressions nested in expr(1) */
end_comment

begin_define
define|#
directive|define
name|LINE_MAX
value|2048
end_define

begin_comment
comment|/* max bytes in an input line */
end_comment

begin_define
define|#
directive|define
name|RE_DUP_MAX
value|255
end_define

begin_comment
comment|/* max RE's in interval notation */
end_comment

begin_define
define|#
directive|define
name|_POSIX2_BC_BASE_MAX
value|99
end_define

begin_define
define|#
directive|define
name|_POSIX2_BC_DIM_MAX
value|2048
end_define

begin_define
define|#
directive|define
name|_POSIX2_BC_SCALE_MAX
value|99
end_define

begin_define
define|#
directive|define
name|_POSIX2_BC_STRING_MAX
value|1000
end_define

begin_define
define|#
directive|define
name|_POSIX2_EQUIV_CLASS_MAX
value|2
end_define

begin_define
define|#
directive|define
name|_POSIX2_EXPR_NEST_MAX
value|32
end_define

begin_define
define|#
directive|define
name|_POSIX2_LINE_MAX
value|2048
end_define

begin_define
define|#
directive|define
name|_POSIX2_RE_DUP_MAX
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199309
end_if

begin_define
define|#
directive|define
name|_POSIX_AIO_LISTIO_MAX
value|16
end_define

begin_define
define|#
directive|define
name|_POSIX_AIO_MAX
value|1
end_define

begin_define
define|#
directive|define
name|_POSIX_DELAYTIMER_MAX
value|32
end_define

begin_define
define|#
directive|define
name|_POSIX_MQ_OPEN_MAX
value|8
end_define

begin_define
define|#
directive|define
name|_POSIX_MQ_PRIO_MAX
value|32
end_define

begin_define
define|#
directive|define
name|_POSIX_RTSIG_MAX
value|8
end_define

begin_define
define|#
directive|define
name|_POSIX_SEM_NSEMS_MAX
value|256
end_define

begin_define
define|#
directive|define
name|_POSIX_SEM_VALUE_MAX
value|32767
end_define

begin_define
define|#
directive|define
name|_POSIX_SIGQUEUE_MAX
value|32
end_define

begin_define
define|#
directive|define
name|_POSIX_TIMER_MAX
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199506
end_if

begin_define
define|#
directive|define
name|_POSIX_THREAD_DESTRUCTOR_ITERATIONS
value|4
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_KEYS_MAX
value|128
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_THREADS_MAX
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|_POSIX_HOST_NAME_MAX
value|255
end_define

begin_define
define|#
directive|define
name|_POSIX_LOGIN_NAME_MAX
value|9
end_define

begin_define
define|#
directive|define
name|_POSIX_SS_REPL_MAX
value|4
end_define

begin_define
define|#
directive|define
name|_POSIX_SYMLINK_MAX
value|255
end_define

begin_define
define|#
directive|define
name|_POSIX_SYMLOOP_MAX
value|8
end_define

begin_define
define|#
directive|define
name|_POSIX_TRACE_EVENT_NAME_MAX
value|30
end_define

begin_define
define|#
directive|define
name|_POSIX_TRACE_NAME_MAX
value|8
end_define

begin_define
define|#
directive|define
name|_POSIX_TRACE_SYS_MAX
value|8
end_define

begin_define
define|#
directive|define
name|_POSIX_TRACE_USER_EVENT_MAX
value|32
end_define

begin_define
define|#
directive|define
name|_POSIX_TTY_NAME_MAX
value|9
end_define

begin_define
define|#
directive|define
name|_POSIX2_CHARCLASS_NAME_MAX
value|14
end_define

begin_define
define|#
directive|define
name|_POSIX2_COLL_WEIGHTS_MAX
value|2
end_define

begin_define
define|#
directive|define
name|_POSIX_RE_DUP_MAX
value|_POSIX2_RE_DUP_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|_XOPEN_IOV_MAX
value|16
end_define

begin_define
define|#
directive|define
name|_XOPEN_NAME_MAX
value|255
end_define

begin_define
define|#
directive|define
name|_XOPEN_PATH_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|PASS_MAX
value|128
end_define

begin_comment
comment|/* _PASSWORD_LEN from<pwd.h> */
end_comment

begin_define
define|#
directive|define
name|NL_ARGMAX
value|99
end_define

begin_comment
comment|/* max # of position args for printf */
end_comment

begin_define
define|#
directive|define
name|NL_LANGMAX
value|31
end_define

begin_comment
comment|/* max LANG name length */
end_comment

begin_define
define|#
directive|define
name|NL_MSGMAX
value|32767
end_define

begin_define
define|#
directive|define
name|NL_NMAX
value|1
end_define

begin_define
define|#
directive|define
name|NL_SETMAX
value|255
end_define

begin_define
define|#
directive|define
name|NL_TEXTMAX
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|6
end_define

begin_comment
comment|/* 31-bit UTF-8 */
end_comment

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
end_if

begin_include
include|#
directive|include
file|<sys/syslimits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIMITS_H_ */
end_comment

end_unit

