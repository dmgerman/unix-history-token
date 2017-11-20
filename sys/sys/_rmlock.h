begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007 Stephan Uphoff<ups@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__RMLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__RMLOCK_H_
end_define

begin_comment
comment|/*  * Mostly reader/occasional writer lock.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|rmpriolist
argument_list|,
name|rm_priotracker
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|rm_queue
block|{
name|struct
name|rm_queue
modifier|*
specifier|volatile
name|rmq_next
decl_stmt|;
name|struct
name|rm_queue
modifier|*
specifier|volatile
name|rmq_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmlock
block|{
name|struct
name|lock_object
name|lock_object
decl_stmt|;
specifier|volatile
name|cpuset_t
name|rm_writecpus
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|rm_priotracker
argument_list|)
name|rm_activeReaders
expr_stmt|;
union|union
block|{
name|struct
name|lock_object
name|_rm_wlock_object
decl_stmt|;
name|struct
name|mtx
name|_rm_lock_mtx
decl_stmt|;
name|struct
name|sx
name|_rm_lock_sx
decl_stmt|;
block|}
name|_rm_lock
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rm_wlock_object
value|_rm_lock._rm_wlock_object
end_define

begin_define
define|#
directive|define
name|rm_lock_mtx
value|_rm_lock._rm_lock_mtx
end_define

begin_define
define|#
directive|define
name|rm_lock_sx
value|_rm_lock._rm_lock_sx
end_define

begin_struct
struct|struct
name|rm_priotracker
block|{
name|struct
name|rm_queue
name|rmp_cpuQueue
decl_stmt|;
comment|/* Must be first */
name|struct
name|rmlock
modifier|*
name|rmp_rmlock
decl_stmt|;
name|struct
name|thread
modifier|*
name|rmp_thread
decl_stmt|;
name|int
name|rmp_flags
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|rm_priotracker
argument_list|)
name|rmp_qentry
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__RMLOCK_H_ */
end_comment

end_unit

