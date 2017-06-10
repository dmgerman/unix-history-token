begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * Copyright (c) 2017 Mark Johnston<markj@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<linux/list.h>
end_include

begin_include
include|#
directive|include
file|<linux/spinlock.h>
end_include

begin_include
include|#
directive|include
file|<asm/atomic.h>
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

begin_define
define|#
directive|define
name|SKIP_SLEEP
parameter_list|()
value|(SCHEDULER_STOPPED() || kdb_active)
end_define

begin_define
define|#
directive|define
name|might_sleep
parameter_list|()
define|\
value|WITNESS_WARN(WARN_GIANTOK | WARN_SLEEPOK, NULL, "might_sleep()")
end_define

begin_struct_decl
struct_decl|struct
name|wait_queue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wait_queue_head
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|wait_queue
name|wait_queue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|wait_queue_head
name|wait_queue_head_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|wait_queue_func_t
parameter_list|(
name|wait_queue_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Many API consumers directly reference these fields and those of  * wait_queue_head.  */
end_comment

begin_struct
struct|struct
name|wait_queue
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* always 0 */
name|void
modifier|*
name|private
decl_stmt|;
name|wait_queue_func_t
modifier|*
name|func
decl_stmt|;
name|struct
name|list_head
name|task_list
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wait_queue_head
block|{
name|spinlock_t
name|lock
decl_stmt|;
name|struct
name|list_head
name|task_list
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This function is referenced by at least one DRM driver, so it may not be  * renamed and furthermore must be the default wait queue callback.  */
end_comment

begin_decl_stmt
specifier|extern
name|wait_queue_func_t
name|autoremove_wake_function
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEFINE_WAIT
parameter_list|(
name|name
parameter_list|)
define|\
value|wait_queue_t name = {						\ 		.private = current,					\ 		.func = autoremove_wake_function,			\ 		.task_list = LINUX_LIST_HEAD_INIT(name.task_list)	\ 	}
end_define

begin_define
define|#
directive|define
name|DECLARE_WAITQUEUE
parameter_list|(
name|name
parameter_list|,
name|task
parameter_list|)
define|\
value|wait_queue_t name = {						\ 		.private = task,					\ 		.task_list = LINUX_LIST_HEAD_INIT(name.task_list)	\ 	}
end_define

begin_define
define|#
directive|define
name|DECLARE_WAIT_QUEUE_HEAD
parameter_list|(
name|name
parameter_list|)
define|\
value|wait_queue_head_t name = {					\ 		.task_list = LINUX_LIST_HEAD_INIT(name.task_list),	\ 	};								\ 	MTX_SYSINIT(name,&(name).lock.m, spin_lock_name("wqhead"), MTX_DEF)
end_define

begin_define
define|#
directive|define
name|init_waitqueue_head
parameter_list|(
name|wqh
parameter_list|)
value|do {					\ 	mtx_init(&(wqh)->lock.m, spin_lock_name("wqhead"),		\ 	    NULL, MTX_DEF | MTX_NEW | MTX_NOWITNESS);			\ 	INIT_LIST_HEAD(&(wqh)->task_list);				\ } while (0)
end_define

begin_function_decl
name|void
name|linux_wake_up
parameter_list|(
name|wait_queue_head_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|wake_up
parameter_list|(
name|wqh
parameter_list|)
define|\
value|linux_wake_up(wqh, TASK_NORMAL, 1, false)
end_define

begin_define
define|#
directive|define
name|wake_up_all
parameter_list|(
name|wqh
parameter_list|)
define|\
value|linux_wake_up(wqh, TASK_NORMAL, 0, false)
end_define

begin_define
define|#
directive|define
name|wake_up_locked
parameter_list|(
name|wqh
parameter_list|)
define|\
value|linux_wake_up(wqh, TASK_NORMAL, 1, true)
end_define

begin_define
define|#
directive|define
name|wake_up_all_locked
parameter_list|(
name|wqh
parameter_list|)
define|\
value|linux_wake_up(wqh, TASK_NORMAL, 0, true)
end_define

begin_define
define|#
directive|define
name|wake_up_interruptible
parameter_list|(
name|wqh
parameter_list|)
define|\
value|linux_wake_up(wqh, TASK_INTERRUPTIBLE, 1, false)
end_define

begin_define
define|#
directive|define
name|wake_up_interruptible_all
parameter_list|(
name|wqh
parameter_list|)
define|\
value|linux_wake_up(wqh, TASK_INTERRUPTIBLE, 0, false)
end_define

begin_function_decl
name|int
name|linux_wait_event_common
parameter_list|(
name|wait_queue_head_t
modifier|*
parameter_list|,
name|wait_queue_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|spinlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns -ERESTARTSYS for a signal, 0 if cond is false after timeout, 1 if  * cond is true after timeout, remaining jiffies (> 0) if cond is true before  * timeout.  */
end_comment

begin_define
define|#
directive|define
name|__wait_event_common
parameter_list|(
name|wqh
parameter_list|,
name|cond
parameter_list|,
name|timeout
parameter_list|,
name|state
parameter_list|,
name|lock
parameter_list|)
value|({	\ 	DEFINE_WAIT(__wq);					\ 	const int __timeout = (timeout)< 1 ? 1 : (timeout);	\ 	int __start = ticks;					\ 	int __ret = 0;						\ 								\ 	for (;;) {						\ 		linux_prepare_to_wait(&(wqh),&__wq, state);	\ 		if (cond) {					\ 			__ret = 1;				\ 			break;					\ 		}						\ 		__ret = linux_wait_event_common(&(wqh),&__wq,	\ 		    __timeout, state, lock);			\ 		if (__ret != 0)					\ 			break;					\ 	}							\ 	linux_finish_wait(&(wqh),&__wq);			\ 	if (__timeout != MAX_SCHEDULE_TIMEOUT) {		\ 		if (__ret == -EWOULDBLOCK)			\ 			__ret = !!(cond);			\ 		else if (__ret != -ERESTARTSYS) {		\ 			__ret = __timeout + __start - ticks;	\
comment|/* range check return value */
value|\ 			if (__ret< 1)				\ 				__ret = 1;			\ 			else if (__ret> __timeout)		\ 				__ret = __timeout;		\ 		}						\ 	}							\ 	__ret;							\ })
end_define

begin_define
define|#
directive|define
name|wait_event
parameter_list|(
name|wqh
parameter_list|,
name|cond
parameter_list|)
value|({					\ 	__wait_event_common(wqh, cond, MAX_SCHEDULE_TIMEOUT,		\ 	    TASK_UNINTERRUPTIBLE, NULL);				\ })
end_define

begin_define
define|#
directive|define
name|wait_event_timeout
parameter_list|(
name|wqh
parameter_list|,
name|cond
parameter_list|,
name|timeout
parameter_list|)
value|({			\ 	__wait_event_common(wqh, cond, timeout, TASK_UNINTERRUPTIBLE,	\ 	    NULL);							\ })
end_define

begin_define
define|#
directive|define
name|wait_event_interruptible
parameter_list|(
name|wqh
parameter_list|,
name|cond
parameter_list|)
value|({				\ 	__wait_event_common(wqh, cond, MAX_SCHEDULE_TIMEOUT,		\ 	    TASK_INTERRUPTIBLE, NULL);					\ })
end_define

begin_define
define|#
directive|define
name|wait_event_interruptible_timeout
parameter_list|(
name|wqh
parameter_list|,
name|cond
parameter_list|,
name|timeout
parameter_list|)
value|({		\ 	__wait_event_common(wqh, cond, timeout, TASK_INTERRUPTIBLE,	\ 	    NULL);							\ })
end_define

begin_comment
comment|/*  * Wait queue is already locked.  */
end_comment

begin_define
define|#
directive|define
name|wait_event_interruptible_locked
parameter_list|(
name|wqh
parameter_list|,
name|cond
parameter_list|)
value|({			\ 	int __ret;							\ 									\ 	spin_unlock(&(wqh).lock);					\ 	__ret = __wait_event_common(wqh, cond, MAX_SCHEDULE_TIMEOUT,	\ 	    TASK_INTERRUPTIBLE, NULL);					\ 	spin_lock(&(wqh).lock);						\ 	__ret;								\ })
end_define

begin_comment
comment|/*  * Hold the (locked) spinlock when testing the cond.  */
end_comment

begin_define
define|#
directive|define
name|wait_event_interruptible_lock_irq
parameter_list|(
name|wqh
parameter_list|,
name|cond
parameter_list|,
name|lock
parameter_list|)
value|({		\ 	__wait_event_common(wqh, cond, MAX_SCHEDULE_TIMEOUT,		\ 	    TASK_INTERRUPTIBLE,&(lock));				\ })
end_define

begin_function
specifier|static
specifier|inline
name|void
name|__add_wait_queue
parameter_list|(
name|wait_queue_head_t
modifier|*
name|wqh
parameter_list|,
name|wait_queue_t
modifier|*
name|wq
parameter_list|)
block|{
name|list_add
argument_list|(
operator|&
name|wq
operator|->
name|task_list
argument_list|,
operator|&
name|wqh
operator|->
name|task_list
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|add_wait_queue
parameter_list|(
name|wait_queue_head_t
modifier|*
name|wqh
parameter_list|,
name|wait_queue_t
modifier|*
name|wq
parameter_list|)
block|{
name|spin_lock
argument_list|(
operator|&
name|wqh
operator|->
name|lock
argument_list|)
expr_stmt|;
name|__add_wait_queue
argument_list|(
name|wqh
argument_list|,
name|wq
argument_list|)
expr_stmt|;
name|spin_unlock
argument_list|(
operator|&
name|wqh
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
name|__add_wait_queue_tail
parameter_list|(
name|wait_queue_head_t
modifier|*
name|wqh
parameter_list|,
name|wait_queue_t
modifier|*
name|wq
parameter_list|)
block|{
name|list_add_tail
argument_list|(
operator|&
name|wq
operator|->
name|task_list
argument_list|,
operator|&
name|wqh
operator|->
name|task_list
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|__remove_wait_queue
parameter_list|(
name|wait_queue_head_t
modifier|*
name|wqh
parameter_list|,
name|wait_queue_t
modifier|*
name|wq
parameter_list|)
block|{
name|list_del
argument_list|(
operator|&
name|wq
operator|->
name|task_list
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|remove_wait_queue
parameter_list|(
name|wait_queue_head_t
modifier|*
name|wqh
parameter_list|,
name|wait_queue_t
modifier|*
name|wq
parameter_list|)
block|{
name|spin_lock
argument_list|(
operator|&
name|wqh
operator|->
name|lock
argument_list|)
expr_stmt|;
name|__remove_wait_queue
argument_list|(
name|wqh
argument_list|,
name|wq
argument_list|)
expr_stmt|;
name|spin_unlock
argument_list|(
operator|&
name|wqh
operator|->
name|lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|bool
name|linux_waitqueue_active
parameter_list|(
name|wait_queue_head_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|waitqueue_active
parameter_list|(
name|wqh
parameter_list|)
value|linux_waitqueue_active(wqh)
end_define

begin_function_decl
name|void
name|linux_prepare_to_wait
parameter_list|(
name|wait_queue_head_t
modifier|*
parameter_list|,
name|wait_queue_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_finish_wait
parameter_list|(
name|wait_queue_head_t
modifier|*
parameter_list|,
name|wait_queue_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|prepare_to_wait
parameter_list|(
name|wqh
parameter_list|,
name|wq
parameter_list|,
name|state
parameter_list|)
value|linux_prepare_to_wait(wqh, wq, state)
end_define

begin_define
define|#
directive|define
name|finish_wait
parameter_list|(
name|wqh
parameter_list|,
name|wq
parameter_list|)
value|linux_finish_wait(wqh, wq)
end_define

begin_function_decl
name|void
name|linux_wake_up_bit
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_wait_on_bit_timeout
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_wake_up_atomic_t
parameter_list|(
name|atomic_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_wait_on_atomic_t
parameter_list|(
name|atomic_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|wake_up_bit
parameter_list|(
name|word
parameter_list|,
name|bit
parameter_list|)
value|linux_wake_up_bit(word, bit)
end_define

begin_define
define|#
directive|define
name|wait_on_bit_timeout
parameter_list|(
name|word
parameter_list|,
name|bit
parameter_list|,
name|state
parameter_list|,
name|timeout
parameter_list|)
define|\
value|linux_wait_on_bit_timeout(word, bit, state, timeout)
end_define

begin_define
define|#
directive|define
name|wake_up_atomic_t
parameter_list|(
name|a
parameter_list|)
value|linux_wake_up_atomic_t(a)
end_define

begin_comment
comment|/*  * All existing callers have a cb that just schedule()s. To avoid adding  * complexity, just emulate that internally. The prototype is different so that  * callers must be manually modified; a cb that does something other than call  * schedule() will require special treatment.  */
end_comment

begin_define
define|#
directive|define
name|wait_on_atomic_t
parameter_list|(
name|a
parameter_list|,
name|state
parameter_list|)
value|linux_wait_on_atomic_t(a, state)
end_define

begin_struct_decl
struct_decl|struct
name|task_struct
struct_decl|;
end_struct_decl

begin_function_decl
name|bool
name|linux_wake_up_state
parameter_list|(
name|struct
name|task_struct
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|wake_up_process
parameter_list|(
name|task
parameter_list|)
value|linux_wake_up_state(task, TASK_NORMAL)
end_define

begin_define
define|#
directive|define
name|wake_up_state
parameter_list|(
name|task
parameter_list|,
name|state
parameter_list|)
value|linux_wake_up_state(task, state)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_WAIT_H_ */
end_comment

end_unit

