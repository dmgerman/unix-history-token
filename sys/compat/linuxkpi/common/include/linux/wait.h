begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_WAIT_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_WAIT_H_
end_define

begin_include
include|#
directive|include
file|<linux/compiler.h>
end_include

begin_include
include|#
directive|include
file|<linux/spinlock.h>
end_include

begin_include
include|#
directive|include
file|<linux/sched.h>
end_include

begin_include
include|#
directive|include
file|<linux/list.h>
end_include

begin_include
include|#
directive|include
file|<linux/jiffies.h>
end_include

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
file|<sys/sleepqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{ }
name|wait_queue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|wchan
decl_stmt|;
block|}
name|wait_queue_head_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|init_waitqueue_head
parameter_list|(
name|x
parameter_list|)
define|\
value|do { } while (0)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|__wake_up
parameter_list|(
name|wait_queue_head_t
modifier|*
name|q
parameter_list|,
name|int
name|all
parameter_list|)
block|{
name|int
name|wakeup_swapper
decl_stmt|;
name|void
modifier|*
name|c
decl_stmt|;
name|c
operator|=
operator|&
name|q
operator|->
name|wchan
expr_stmt|;
name|sleepq_lock
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|all
condition|)
name|wakeup_swapper
operator|=
name|sleepq_broadcast
argument_list|(
name|c
argument_list|,
name|SLEEPQ_SLEEP
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|wakeup_swapper
operator|=
name|sleepq_signal
argument_list|(
name|c
argument_list|,
name|SLEEPQ_SLEEP
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sleepq_release
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|wakeup_swapper
condition|)
name|kick_proc0
argument_list|()
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|wake_up
parameter_list|(
name|q
parameter_list|)
value|__wake_up(q, 0)
end_define

begin_define
define|#
directive|define
name|wake_up_nr
parameter_list|(
name|q
parameter_list|,
name|nr
parameter_list|)
value|__wake_up(q, 1)
end_define

begin_define
define|#
directive|define
name|wake_up_all
parameter_list|(
name|q
parameter_list|)
value|__wake_up(q, 1)
end_define

begin_define
define|#
directive|define
name|wake_up_interruptible
parameter_list|(
name|q
parameter_list|)
value|__wake_up(q, 0)
end_define

begin_define
define|#
directive|define
name|wake_up_interruptible_nr
parameter_list|(
name|q
parameter_list|,
name|nr
parameter_list|)
value|__wake_up(q, 1)
end_define

begin_define
define|#
directive|define
name|wake_up_interruptible_all
parameter_list|(
name|q
parameter_list|,
name|nr
parameter_list|)
value|__wake_up(q, 1)
end_define

begin_define
define|#
directive|define
name|wait_event
parameter_list|(
name|q
parameter_list|,
name|cond
parameter_list|)
define|\
value|do {									\ 	void *c =&(q).wchan;						\ 	if (!(cond)) {							\ 		for (;;) {						\ 			if (unlikely(SCHEDULER_STOPPED()))		\ 				break;					\ 			sleepq_lock(c);					\ 			if (cond) {					\ 				sleepq_release(c);			\ 				break;					\ 			}						\ 			sleepq_add(c, NULL, "completion", SLEEPQ_SLEEP, 0); \ 			sleepq_wait(c, 0);				\ 		}							\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|wait_event_interruptible
parameter_list|(
name|q
parameter_list|,
name|cond
parameter_list|)
define|\
value|({									\ 	void *c =&(q).wchan;						\ 	int _error;							\ 									\ 	_error = 0;							\ 	if (!(cond)) {							\ 		for (; _error == 0;) {					\ 			if (unlikely(SCHEDULER_STOPPED()))		\ 				break;					\ 			sleepq_lock(c);					\ 			if (cond) {					\ 				sleepq_release(c);			\ 				break;					\ 			}						\ 			sleepq_add(c, NULL, "completion",		\ 			    SLEEPQ_SLEEP | SLEEPQ_INTERRUPTIBLE, 0);	\ 			if (sleepq_wait_sig(c, 0))			\ 				_error = -ERESTARTSYS;			\ 		}							\ 	}								\ 	-_error;							\ })
end_define

begin_define
define|#
directive|define
name|wait_event_interruptible_timeout
parameter_list|(
name|q
parameter_list|,
name|cond
parameter_list|,
name|timeout
parameter_list|)
define|\
value|({									\ 	void *c =&(q).wchan;						\ 	long end = jiffies + timeout;					\ 	int __ret = 0;	 						\ 	int __rc = 0;							\ 									\ 	if (!(cond)) {							\ 		for (; __rc == 0;) {					\ 			if (unlikely(SCHEDULER_STOPPED()))		\ 				break;					\ 			sleepq_lock(c);					\ 			if (cond) {					\ 				sleepq_release(c);			\ 				__ret = 1;				\ 				break;					\ 			}						\ 			sleepq_add(c, NULL, "completion",		\ 			SLEEPQ_SLEEP | SLEEPQ_INTERRUPTIBLE, 0);	\ 			sleepq_set_timeout(c, linux_timer_jiffies_until(end));\ 			__rc = sleepq_timedwait_sig (c, 0);		\ 			if (__rc != 0) {				\
comment|/* check for timeout or signal. 	\ 				 * 0 if the condition evaluated to false\ 				 * after the timeout elapsed,  1 if the \ 				 * condition evaluated to true after the\ 				 * timeout elapsed.			\ 				 */
value|\ 				if (__rc == EWOULDBLOCK)		\ 					__ret = (cond);			\ 				 else					\ 					__ret = -ERESTARTSYS;		\ 			}						\ 									\ 		}							\ 	} else {							\
comment|/* return remaining jiffies (at least 1) if the 	\ 		 * condition evaluated to true before the timeout	\ 		 * elapsed.						\ 		 */
value|\ 		__ret = (end - jiffies);				\ 		if( __ret< 1 )						\ 			__ret = 1;					\ 	}								\ 	__ret;								\ })
end_define

begin_function
specifier|static
specifier|inline
name|int
name|waitqueue_active
parameter_list|(
name|wait_queue_head_t
modifier|*
name|q
parameter_list|)
block|{
return|return
literal|0
return|;
comment|/* XXX: not really implemented */
block|}
end_function

begin_define
define|#
directive|define
name|DEFINE_WAIT
parameter_list|(
name|name
parameter_list|)
define|\
value|wait_queue_t name = {}
end_define

begin_function
specifier|static
specifier|inline
name|void
name|prepare_to_wait
parameter_list|(
name|wait_queue_head_t
modifier|*
name|q
parameter_list|,
name|wait_queue_t
modifier|*
name|wait
parameter_list|,
name|int
name|state
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|finish_wait
parameter_list|(
name|wait_queue_head_t
modifier|*
name|q
parameter_list|,
name|wait_queue_t
modifier|*
name|wait
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_WAIT_H_ */
end_comment

end_unit

