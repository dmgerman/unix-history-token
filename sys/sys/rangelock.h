begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Konstantin Belousov<kib@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RANGELOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RANGELOCK_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|RL_LOCK_READ
value|0x0001
end_define

begin_define
define|#
directive|define
name|RL_LOCK_WRITE
value|0x0002
end_define

begin_define
define|#
directive|define
name|RL_LOCK_TYPE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|RL_LOCK_GRANTED
value|0x0004
end_define

begin_struct_decl
struct_decl|struct
name|rl_q_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The structure representing the range lock.  Caller may request  * read or write access to the range of bytes. Access is granted if  * all existing lock owners are compatible with the request. Two lock  * owners are compatible if their ranges do not overlap, or both  * owners are for read.  *  * Access to the structure itself is synchronized with the externally  * supplied mutex.  *  * rl_waiters is the queue containing in order (a) granted write lock  * requests, (b) granted read lock requests, and (c) in order of arrival,  * lock requests which cannot be granted yet.  *  * rl_currdep is the first lock request that cannot be granted now due  * to the preceding requests conflicting with it (i.e., it points to  * position (c) in the list above).  */
end_comment

begin_struct
struct|struct
name|rangelock
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|rl_q_entry
argument_list|)
name|rl_waiters
expr_stmt|;
name|struct
name|rl_q_entry
modifier|*
name|rl_currdep
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|mtx
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|rangelock_init
parameter_list|(
name|struct
name|rangelock
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rangelock_destroy
parameter_list|(
name|struct
name|rangelock
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rangelock_unlock
parameter_list|(
name|struct
name|rangelock
modifier|*
name|lock
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|struct
name|mtx
modifier|*
name|ilk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rangelock_unlock_range
parameter_list|(
name|struct
name|rangelock
modifier|*
name|lock
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|off_t
name|start
parameter_list|,
name|off_t
name|end
parameter_list|,
name|struct
name|mtx
modifier|*
name|ilk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rangelock_rlock
parameter_list|(
name|struct
name|rangelock
modifier|*
name|lock
parameter_list|,
name|off_t
name|start
parameter_list|,
name|off_t
name|end
parameter_list|,
name|struct
name|mtx
modifier|*
name|ilk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rangelock_wlock
parameter_list|(
name|struct
name|rangelock
modifier|*
name|lock
parameter_list|,
name|off_t
name|start
parameter_list|,
name|off_t
name|end
parameter_list|,
name|struct
name|mtx
modifier|*
name|ilk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rlqentry_free
parameter_list|(
name|struct
name|rl_q_entry
modifier|*
name|rlqe
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_RANGELOCK_H */
end_comment

end_unit

