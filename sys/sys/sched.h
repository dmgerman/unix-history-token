begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SCHED_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SCHED_H_
end_define

begin_comment
comment|/*  * General scheduling info.  *  * sched_load:  *	Total runnable non-ithread threads in the system.  *  * sched_runnable:  *	Runnable threads for this processor.  */
end_comment

begin_function_decl
name|int
name|sched_load
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_rr_interval
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_runnable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * Proc related scheduling hooks.  */
end_comment

begin_function_decl
name|void
name|sched_exit
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|thread
modifier|*
name|childtd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_fork
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|thread
modifier|*
name|childtd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * KSE Groups contain scheduling priority information.  They record the  * behavior of groups of KSEs and threads.  */
end_comment

begin_function_decl
name|void
name|sched_class
parameter_list|(
name|struct
name|ksegrp
modifier|*
name|kg
parameter_list|,
name|int
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_exit_ksegrp
parameter_list|(
name|struct
name|ksegrp
modifier|*
name|kg
parameter_list|,
name|struct
name|thread
modifier|*
name|childtd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_fork_ksegrp
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|ksegrp
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_nice
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|nice
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Threads are switched in and out, block on resources, have temporary  * priorities inherited from their ksegs, and use up cpu time.  */
end_comment

begin_function_decl
name|void
name|sched_exit_thread
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|thread
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_fork_thread
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|thread
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|fixpt_t
name|sched_pctcpu
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_prio
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|u_char
name|prio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_lend_prio
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|u_char
name|prio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_sleep
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_switch
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|thread
modifier|*
name|newtd
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_unlend_prio
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|u_char
name|prio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_userret
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_wakeup
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Threads are moved on and off of run queues  */
end_comment

begin_function_decl
name|void
name|sched_add
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_clock
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_rem
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Binding makes cpu affinity permanent while pinning is used to temporarily  * hold a thread on a particular CPU.  */
end_comment

begin_function_decl
name|void
name|sched_bind
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|sched_pin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_unbind
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|sched_unpin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_is_bound
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These procedures tell the process data structure allocation code how  * many bytes to actually allocate.  */
end_comment

begin_function_decl
name|int
name|sched_sizeof_ksegrp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_sizeof_proc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_sizeof_thread
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|sched_pin
parameter_list|(
name|void
parameter_list|)
block|{
name|curthread
operator|->
name|td_pinned
operator|++
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|sched_unpin
parameter_list|(
name|void
parameter_list|)
block|{
name|curthread
operator|->
name|td_pinned
operator|--
expr_stmt|;
block|}
end_function

begin_comment
comment|/* temporarily here */
end_comment

begin_function_decl
name|void
name|schedinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_init_concurrency
parameter_list|(
name|struct
name|ksegrp
modifier|*
name|kg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_set_concurrency
parameter_list|(
name|struct
name|ksegrp
modifier|*
name|kg
parameter_list|,
name|int
name|cuncurrency
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_schedinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_newproc
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ksegrp
modifier|*
name|kg
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_thread_exit
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_newthread
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SCHED_H_ */
end_comment

end_unit

