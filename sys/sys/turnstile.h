begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 John Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TURNSTILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TURNSTILE_H_
end_define

begin_comment
comment|/*  * Turnstile interface.  Non-sleepable locks use a turnstile for the  * queue of threads blocked on them when they are contested.  *  * A thread calls turnstile_lock() to lock the turnstile chain associated  * with a given lock.  A thread calls turnstile_wait() when the lock is  * contested to be put on the queue and block.  If a thread needs to retry  * a lock operation instead of blocking, it should call turnstile_release()  * to unlock the associated turnstile chain lock.  *  * When a lock is released, the thread calls turnstile_lookup() to loop  * up the turnstile associated with the given lock in the hash table.  Then  * it calls either turnstile_signal() or turnstile_broadcast() to mark  * blocked threads for a pending wakeup.  turnstile_signal() marks the  * highest priority blocked thread while turnstile_broadcast() marks all  * blocked threads.  The turnstile_signal() function returns true if the  * turnstile became empty as a result.  After the higher level code finishes  * releasing the lock, turnstile_unpend() must be called to wake up the  * pending thread(s).  *  * When a lock is acquired that already has at least one thread contested  * on it, the new owner of the lock must claim ownership of the turnstile  * via turnstile_claim().  *  * Each thread allocates a turnstile at thread creation via turnstile_alloc()  * and releases it at thread destruction via turnstile_free().  Note that  * a turnstile is not tied to a specific thread and that the turnstile  * released at thread destruction may not be the same turnstile that the  * thread allocated when it was created.  *  * A function can query a turnstile to see if it is empty via  * turnstile_empty().  The highest priority thread blocked on a turnstile  * can be obtained via turnstile_head().  */
end_comment

begin_struct_decl
struct_decl|struct
name|lock_object
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|turnstile
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|init_turnstiles
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|turnstile_adjust
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|turnstile
modifier|*
name|turnstile_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|turnstile_broadcast
parameter_list|(
name|struct
name|turnstile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|turnstile_claim
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|turnstile_empty
parameter_list|(
name|struct
name|turnstile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|turnstile_free
parameter_list|(
name|struct
name|turnstile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|turnstile_head
parameter_list|(
name|struct
name|turnstile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|turnstile_lock
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|turnstile
modifier|*
name|turnstile_lookup
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|turnstile_release
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|turnstile_signal
parameter_list|(
name|struct
name|turnstile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|turnstile_unpend
parameter_list|(
name|struct
name|turnstile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|turnstile_wait
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
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
comment|/* _SYS_TURNSTILE_H_ */
end_comment

end_unit

