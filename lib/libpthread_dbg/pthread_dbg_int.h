begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 David Xu<davidxu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTHREAD_DBG_INT_H
end_ifndef

begin_define
define|#
directive|define
name|_PTHREAD_DBG_INT_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_struct
struct|struct
name|td_proc
block|{
name|td_proc_callbacks_t
modifier|*
name|cb
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
name|caddr_t
name|libkse_debug_addr
decl_stmt|;
name|caddr_t
name|thread_list_addr
decl_stmt|;
name|caddr_t
name|thread_listgen_addr
decl_stmt|;
name|caddr_t
name|thread_activated_addr
decl_stmt|;
name|caddr_t
name|thread_active_kseq_addr
decl_stmt|;
name|int
name|thread_activated
decl_stmt|;
name|int
name|thread_listgen
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|td_thread
argument_list|)
name|threads
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|td_thread
block|{
name|td_proc_t
modifier|*
name|proc
decl_stmt|;
name|caddr_t
name|addr
decl_stmt|;
name|caddr_t
name|tcb_addr
decl_stmt|;
name|void
modifier|*
name|kthread
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|step
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|td_thread
argument_list|)
name|tle
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|READ
parameter_list|(
name|proc
parameter_list|,
name|addr
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
value|((proc)->cb->proc_read((proc)->arg, (addr), (buf), (size)))
end_define

begin_define
define|#
directive|define
name|READ_STRING
parameter_list|(
name|proc
parameter_list|,
name|addr
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
value|((proc)->cb->proc_read((proc)->arg, (addr), (buf), (size)))
end_define

begin_define
define|#
directive|define
name|WRITE
parameter_list|(
name|proc
parameter_list|,
name|addr
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
value|((proc)->cb->proc_write((proc)->arg, (addr), (buf), (size)))
end_define

begin_define
define|#
directive|define
name|LOOKUP
parameter_list|(
name|proc
parameter_list|,
name|sym
parameter_list|,
name|addr
parameter_list|)
value|((proc)->cb->proc_lookup((proc)->arg, (sym), (addr)))
end_define

begin_define
define|#
directive|define
name|GETREGS
parameter_list|(
name|proc
parameter_list|,
name|regset
parameter_list|,
name|lwp
parameter_list|,
name|buf
parameter_list|)
value|((proc)->cb->proc_getregs((proc)->arg, (regset), (lwp), (buf)))
end_define

begin_define
define|#
directive|define
name|SETREGS
parameter_list|(
name|proc
parameter_list|,
name|regset
parameter_list|,
name|lwp
parameter_list|,
name|buf
parameter_list|)
value|((proc)->cb->proc_setregs((proc)->arg, (regset), (lwp), (buf)))
end_define

begin_define
define|#
directive|define
name|SSTEP
parameter_list|(
name|proc
parameter_list|,
name|lwp
parameter_list|,
name|on
parameter_list|)
value|((proc)->cb->proc_sstep((proc)->arg, (lwp), (on)))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

