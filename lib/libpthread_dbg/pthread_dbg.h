begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 David Xu<davidxu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTHREAD_DBG_H
end_ifndef

begin_define
define|#
directive|define
name|_PTHREAD_DBG_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|td_proc
name|td_proc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|td_thread
name|td_thread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|td_proc_callbacks
block|{
name|int
function_decl|(
modifier|*
name|proc_read
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|proc_readstring
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|proc_write
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|proc_lookup
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|char
modifier|*
name|sym
parameter_list|,
name|caddr_t
modifier|*
name|addr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|proc_regsize
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|regset
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|proc_getregs
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|regset
parameter_list|,
name|void
modifier|*
name|lwp
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|proc_setregs
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|regset
parameter_list|,
name|void
modifier|*
name|lwp
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|proc_sstep
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
name|lwp
parameter_list|,
name|int
name|onoff
parameter_list|)
function_decl|;
block|}
name|td_proc_callbacks_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|td_thread_info
block|{
name|caddr_t
name|thread_addr
decl_stmt|;
comment|/* Address of data structure */
name|int
name|thread_state
decl_stmt|;
comment|/* TD_STATE_*; see below */
name|int
name|thread_type
decl_stmt|;
comment|/* TD_TYPE_*; see below */
name|int
name|thread_scope
decl_stmt|;
comment|/* TD_SCOPE_*; see below */
name|long
name|thread_id
decl_stmt|;
name|stack_t
name|thread_stack
decl_stmt|;
name|caddr_t
name|thread_joiner
decl_stmt|;
name|caddr_t
name|thread_tls
decl_stmt|;
name|int
name|thread_tlscount
decl_stmt|;
name|int
name|thread_errno
decl_stmt|;
name|sigset_t
name|thread_sigmask
decl_stmt|;
name|sigset_t
name|thread_sigpend
decl_stmt|;
name|stack_t
name|thread_sigstk
decl_stmt|;
name|char
name|thread_base_priority
decl_stmt|;
name|char
name|thread_inherited_priority
decl_stmt|;
name|char
name|thread_active_priority
decl_stmt|;
name|int
name|thread_cancelflags
decl_stmt|;
comment|/* TD_CANCEL_*; see below */
name|caddr_t
name|thread_retval
decl_stmt|;
name|long
name|pad
index|[
literal|32
index|]
decl_stmt|;
block|}
name|td_thread_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TD_STATE_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|TD_STATE_RUNNING
value|1
end_define

begin_define
define|#
directive|define
name|TD_STATE_LOCKWAIT
value|2
end_define

begin_define
define|#
directive|define
name|TD_STATE_MUTEXWAIT
value|3
end_define

begin_define
define|#
directive|define
name|TD_STATE_CONDWAIT
value|4
end_define

begin_define
define|#
directive|define
name|TD_STATE_SLEEPING
value|5
end_define

begin_define
define|#
directive|define
name|TD_STATE_SIGSUSPEND
value|6
end_define

begin_define
define|#
directive|define
name|TD_STATE_SIGWAIT
value|7
end_define

begin_define
define|#
directive|define
name|TD_STATE_JOIN
value|8
end_define

begin_define
define|#
directive|define
name|TD_STATE_SUSPENDED
value|9
end_define

begin_define
define|#
directive|define
name|TD_STATE_DEAD
value|10
end_define

begin_define
define|#
directive|define
name|TD_STATE_DEADLOCK
value|11
end_define

begin_define
define|#
directive|define
name|TD_TYPE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|TD_TYPE_UPCALL
value|1
end_define

begin_define
define|#
directive|define
name|TD_SCOPE_PROCESS
value|0
end_define

begin_define
define|#
directive|define
name|TD_SCOPE_SYSTEM
value|1
end_define

begin_define
define|#
directive|define
name|TD_CANCEL_DISABLED
value|1
end_define

begin_define
define|#
directive|define
name|TD_CANCEL_ASYNCHRONOUS
value|2
end_define

begin_define
define|#
directive|define
name|TD_CANCEL_AT_POINT
value|4
end_define

begin_define
define|#
directive|define
name|TD_CANCEL_CANCELLING
value|8
end_define

begin_define
define|#
directive|define
name|TD_CANCEL_NEEDED
value|10
end_define

begin_comment
comment|/* Error return codes */
end_comment

begin_define
define|#
directive|define
name|TD_ERR_OK
value|0
end_define

begin_define
define|#
directive|define
name|TD_ERR_ERR
value|1
end_define

begin_comment
comment|/* Generic error */
end_comment

begin_define
define|#
directive|define
name|TD_ERR_NOSYM
value|2
end_define

begin_comment
comment|/* Symbol not found (proc_lookup) */
end_comment

begin_define
define|#
directive|define
name|TD_ERR_NOOBJ
value|3
end_define

begin_comment
comment|/* No object matched the request */
end_comment

begin_define
define|#
directive|define
name|TD_ERR_BADTHREAD
value|4
end_define

begin_comment
comment|/* Thread structure damaged */
end_comment

begin_define
define|#
directive|define
name|TD_ERR_INUSE
value|5
end_define

begin_comment
comment|/* The process is already being debugged */
end_comment

begin_define
define|#
directive|define
name|TD_ERR_NOLIB
value|6
end_define

begin_comment
comment|/* The process is not using libpthread */
end_comment

begin_define
define|#
directive|define
name|TD_ERR_NOMEM
value|7
end_define

begin_comment
comment|/* malloc() failed */
end_comment

begin_define
define|#
directive|define
name|TD_ERR_IO
value|8
end_define

begin_comment
comment|/* A callback failed to read or write */
end_comment

begin_define
define|#
directive|define
name|TD_ERR_INVAL
value|9
end_define

begin_comment
comment|/* Invalid parameter */
end_comment

begin_comment
comment|/* Make a connection to a threaded process */
end_comment

begin_function_decl
name|int
name|td_open
parameter_list|(
name|td_proc_callbacks_t
modifier|*
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|td_proc_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Release proc object */
end_comment

begin_function_decl
name|int
name|td_close
parameter_list|(
name|td_proc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Iterate over the threads in the process */
end_comment

begin_function_decl
name|int
name|td_thr_iter
parameter_list|(
name|td_proc_t
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|td_thread_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check if threaded mode is activated */
end_comment

begin_function_decl
name|int
name|td_activated
parameter_list|(
name|td_proc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get information on a thread */
end_comment

begin_function_decl
name|int
name|td_thr_info
parameter_list|(
name|td_thread_t
modifier|*
parameter_list|,
name|td_thread_info_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get name of a thread */
end_comment

begin_function_decl
name|int
name|td_thr_getname
parameter_list|(
name|td_thread_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get registers set of a thread */
end_comment

begin_function_decl
name|int
name|td_thr_getregs
parameter_list|(
name|td_thread_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set registers set of a thread */
end_comment

begin_function_decl
name|int
name|td_thr_setregs
parameter_list|(
name|td_thread_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set/clear single step status */
end_comment

begin_function_decl
name|int
name|td_thr_sstep
parameter_list|(
name|td_thread_t
modifier|*
parameter_list|,
name|int
name|step
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map error code to error message */
end_comment

begin_function_decl
name|char
modifier|*
name|td_err_string
parameter_list|(
name|int
name|errcode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

