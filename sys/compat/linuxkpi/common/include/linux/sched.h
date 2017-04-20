begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_SCHED_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_SCHED_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sched.h>
end_include

begin_include
include|#
directive|include
file|<sys/sleepqueue.h>
end_include

begin_include
include|#
directive|include
file|<linux/list.h>
end_include

begin_include
include|#
directive|include
file|<linux/compat.h>
end_include

begin_include
include|#
directive|include
file|<linux/completion.h>
end_include

begin_include
include|#
directive|include
file|<linux/pid.h>
end_include

begin_include
include|#
directive|include
file|<linux/slab.h>
end_include

begin_include
include|#
directive|include
file|<linux/mm_types.h>
end_include

begin_include
include|#
directive|include
file|<linux/string.h>
end_include

begin_include
include|#
directive|include
file|<linux/bitmap.h>
end_include

begin_include
include|#
directive|include
file|<asm/atomic.h>
end_include

begin_define
define|#
directive|define
name|MAX_SCHEDULE_TIMEOUT
value|LONG_MAX
end_define

begin_define
define|#
directive|define
name|TASK_RUNNING
value|0
end_define

begin_define
define|#
directive|define
name|TASK_INTERRUPTIBLE
value|1
end_define

begin_define
define|#
directive|define
name|TASK_UNINTERRUPTIBLE
value|2
end_define

begin_define
define|#
directive|define
name|TASK_DEAD
value|64
end_define

begin_define
define|#
directive|define
name|TASK_WAKEKILL
value|128
end_define

begin_define
define|#
directive|define
name|TASK_WAKING
value|256
end_define

begin_struct
struct|struct
name|task_struct
block|{
name|struct
name|thread
modifier|*
name|task_thread
decl_stmt|;
name|struct
name|mm_struct
modifier|*
name|mm
decl_stmt|;
name|linux_task_fn_t
modifier|*
name|task_fn
decl_stmt|;
name|void
modifier|*
name|task_data
decl_stmt|;
name|int
name|task_ret
decl_stmt|;
name|atomic_t
name|usage
decl_stmt|;
name|int
name|state
decl_stmt|;
name|atomic_t
name|kthread_flags
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
comment|/* BSD thread ID */
specifier|const
name|char
modifier|*
name|comm
decl_stmt|;
name|void
modifier|*
name|bsd_ioctl_data
decl_stmt|;
name|unsigned
name|bsd_ioctl_len
decl_stmt|;
name|struct
name|completion
name|parked
decl_stmt|;
name|struct
name|completion
name|exited
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|task_struct
argument_list|)
name|rcu_entry
expr_stmt|;
name|int
name|rcu_recurse
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|current
value|({ \ 	struct thread *__td = curthread; \ 	linux_set_current(__td); \ 	((struct task_struct *)__td->td_lkpi_task); \ })
end_define

begin_define
define|#
directive|define
name|task_pid_group_leader
parameter_list|(
name|task
parameter_list|)
value|(task)->task_thread->td_proc->p_pid
end_define

begin_define
define|#
directive|define
name|task_pid
parameter_list|(
name|task
parameter_list|)
value|((task)->pid)
end_define

begin_define
define|#
directive|define
name|task_pid_nr
parameter_list|(
name|task
parameter_list|)
value|((task)->pid)
end_define

begin_define
define|#
directive|define
name|get_pid
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|put_pid
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|current_euid
parameter_list|()
value|(curthread->td_ucred->cr_uid)
end_define

begin_define
define|#
directive|define
name|set_current_state
parameter_list|(
name|x
parameter_list|)
define|\
value|atomic_store_rel_int((volatile int *)&current->state, (x))
end_define

begin_define
define|#
directive|define
name|__set_current_state
parameter_list|(
name|x
parameter_list|)
value|current->state = (x)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|get_task_struct
parameter_list|(
name|struct
name|task_struct
modifier|*
name|task
parameter_list|)
block|{
name|atomic_inc
argument_list|(
operator|&
name|task
operator|->
name|usage
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|put_task_struct
parameter_list|(
name|struct
name|task_struct
modifier|*
name|task
parameter_list|)
block|{
if|if
condition|(
name|atomic_dec_and_test
argument_list|(
operator|&
name|task
operator|->
name|usage
argument_list|)
condition|)
name|linux_free_current
argument_list|(
name|task
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|schedule
parameter_list|()
define|\
value|do {									\ 	void *c;							\ 									\ 	if (cold || SCHEDULER_STOPPED())				\ 		break;							\ 	c = curthread;							\ 	sleepq_lock(c);							\ 	if (current->state == TASK_INTERRUPTIBLE ||			\ 	    current->state == TASK_UNINTERRUPTIBLE) {			\ 		sleepq_add(c, NULL, "task", SLEEPQ_SLEEP, 0);		\ 		sleepq_wait(c, 0);					\ 	} else {							\ 		sleepq_release(c);					\ 		sched_relinquish(curthread);				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|wake_up_process
parameter_list|(
name|x
parameter_list|)
define|\
value|do {									\ 	int wakeup_swapper;						\ 	void *c;							\ 									\ 	c = (x)->task_thread;						\ 	sleepq_lock(c);							\ 	(x)->state = TASK_RUNNING;					\ 	wakeup_swapper = sleepq_signal(c, SLEEPQ_SLEEP, 0, 0);		\ 	sleepq_release(c);						\ 	if (wakeup_swapper)						\ 		kick_proc0();						\ } while (0)
end_define

begin_define
define|#
directive|define
name|cond_resched
parameter_list|()
value|if (!cold)	sched_relinquish(curthread)
end_define

begin_define
define|#
directive|define
name|sched_yield
parameter_list|()
value|sched_relinquish(curthread)
end_define

begin_function
specifier|static
specifier|inline
name|long
name|schedule_timeout
parameter_list|(
name|signed
name|long
name|timeout
parameter_list|)
block|{
if|if
condition|(
name|timeout
operator|<
literal|0
condition|)
return|return
literal|0
return|;
name|pause
argument_list|(
literal|"lstim"
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|need_resched
parameter_list|()
value|(curthread->td_flags& TDF_NEEDRESCHED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_SCHED_H_ */
end_comment

end_unit

