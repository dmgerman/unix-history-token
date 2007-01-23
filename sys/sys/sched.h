begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996, 1997  *      HD Associates, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by HD Associates, Inc  *      and Jukka Antero Ukkonen.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCHED_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCHED_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|class
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
comment|/*  * Threads are switched in and out, block on resources, have temporary  * priorities inherited from their procs, and use up cpu time.  */
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
name|sched_lend_user_prio
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|u_char
name|pri
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
name|sched_unlend_user_prio
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|u_char
name|pri
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_user_prio
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

begin_function_decl
name|void
name|sched_tick
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_relinquish
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|sched_choose
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_idletd
parameter_list|(
name|void
modifier|*
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
comment|/* sched_add arguments (formerly setrunqueue) */
end_comment

begin_define
define|#
directive|define
name|SRQ_BORING
value|0x0000
end_define

begin_comment
comment|/* No special circumstances. */
end_comment

begin_define
define|#
directive|define
name|SRQ_YIELDING
value|0x0001
end_define

begin_comment
comment|/* We are yielding (from mi_switch). */
end_comment

begin_define
define|#
directive|define
name|SRQ_OURSELF
value|0x0002
end_define

begin_comment
comment|/* It is ourself (from mi_switch). */
end_comment

begin_define
define|#
directive|define
name|SRQ_INTR
value|0x0004
end_define

begin_comment
comment|/* It is probably urgent. */
end_comment

begin_define
define|#
directive|define
name|SRQ_PREEMPTED
value|0x0008
end_define

begin_comment
comment|/* has been preempted.. be kind */
end_comment

begin_define
define|#
directive|define
name|SRQ_BORROWING
value|0x0010
end_define

begin_comment
comment|/* Priority updated due to prio_lend */
end_comment

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
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sched_set_concurrency
parameter_list|(
name|struct
name|proc
modifier|*
name|p
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
comment|/* _KERNEL */
end_comment

begin_comment
comment|/* POSIX 1003.1b Process Scheduling */
end_comment

begin_comment
comment|/*  * POSIX scheduling policies  */
end_comment

begin_define
define|#
directive|define
name|SCHED_FIFO
value|1
end_define

begin_define
define|#
directive|define
name|SCHED_OTHER
value|2
end_define

begin_define
define|#
directive|define
name|SCHED_RR
value|3
end_define

begin_struct
struct|struct
name|sched_param
block|{
name|int
name|sched_priority
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * POSIX scheduling declarations for userland.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_PID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__pid_t
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|int
name|sched_get_priority_max
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_get_priority_min
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_getparam
parameter_list|(
name|pid_t
parameter_list|,
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_getscheduler
parameter_list|(
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_rr_get_interval
parameter_list|(
name|pid_t
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_setparam
parameter_list|(
name|pid_t
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_setscheduler
parameter_list|(
name|pid_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SCHED_H_ */
end_comment

end_unit

