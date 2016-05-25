begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2016 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|TASK_SHOULD_STOP
value|1
end_define

begin_define
define|#
directive|define
name|TASK_STOPPED
value|2
end_define

begin_comment
comment|/*  * A task_struct is only provided for threads created by kthread() and  * file operation callbacks.  *  * Using these routines outside the above mentioned contexts will  * cause panics because no task_struct is assigned and td_retval[1] is  * overwritten by syscalls.  */
end_comment

begin_struct
struct|struct
name|task_struct
block|{
name|struct
name|thread
modifier|*
name|task_thread
decl_stmt|;
name|int
function_decl|(
modifier|*
name|task_fn
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
modifier|*
name|task_data
decl_stmt|;
name|int
name|task_ret
decl_stmt|;
name|int
name|state
decl_stmt|;
name|int
name|should_stop
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|current
value|task_struct_get(curthread)
end_define

begin_define
define|#
directive|define
name|task_struct_get
parameter_list|(
name|x
parameter_list|)
value|((struct task_struct *)(uintptr_t)(x)->td_retval[1])
end_define

begin_define
define|#
directive|define
name|task_struct_fill
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do {		\   	(y)->task_thread = (x);			\ 	(y)->comm = (x)->td_name;		\ 	(y)->pid = (x)->td_tid;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|task_struct_set
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x)->td_retval[1] = (uintptr_t)(y)
end_define

begin_comment
comment|/* ensure the task_struct pointer fits into the td_retval[1] field */
end_comment

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
operator|(
operator|(
expr|struct
name|thread
operator|*
operator|)
literal|0
operator|)
operator|->
name|td_retval
index|[
literal|1
index|]
argument_list|)
operator|>=
sizeof|sizeof
argument_list|(
name|uintptr_t
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_SCHED_H_ */
end_comment

end_unit

