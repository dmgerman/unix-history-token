begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2013-2014 Vincenzo Maffione  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_NETMAP_MBQ_H__
end_ifndef

begin_define
define|#
directive|define
name|_NET_NETMAP_MBQ_H__
end_define

begin_comment
comment|/*  * These function implement an mbuf tailq with an optional lock.  * The base functions act ONLY ON THE QUEUE, whereas the "safe"  * variants (mbq_safe_*) also handle the lock.  */
end_comment

begin_comment
comment|/* XXX probably rely on a previous definition of SPINLOCK_T */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_define
define|#
directive|define
name|SPINLOCK_T
value|safe_spinlock_t
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SPINLOCK_T
value|win_spinlock_t
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPINLOCK_T
value|struct mtx
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A FIFO queue of mbufs with an optional lock. */
end_comment

begin_struct
struct|struct
name|mbq
block|{
name|struct
name|mbuf
modifier|*
name|head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tail
decl_stmt|;
name|int
name|count
decl_stmt|;
name|SPINLOCK_T
name|lock
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* We should clarify whether init can be used while  * holding a lock, and whether mbq_safe_destroy() is a NOP.  */
end_comment

begin_function_decl
name|void
name|mbq_init
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbq_fini
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbq_enqueue
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|mbq_dequeue
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbq_purge
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|struct
name|mbuf
modifier|*
name|mbq_peek
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
block|{
return|return
name|q
operator|->
name|head
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mbq_lock
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
block|{
name|mtx_lock_spin
argument_list|(
operator|&
name|q
operator|->
name|lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mbq_unlock
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
block|{
name|mtx_unlock_spin
argument_list|(
operator|&
name|q
operator|->
name|lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|mbq_safe_init
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbq_safe_fini
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbq_safe_enqueue
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|mbq_safe_dequeue
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbq_safe_purge
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|mbq_len
parameter_list|(
name|struct
name|mbq
modifier|*
name|q
parameter_list|)
block|{
return|return
name|q
operator|->
name|count
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_NETMAP_MBQ_H_ */
end_comment

end_unit

