begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_WORKQUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_WORKQUEUE_H_
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/timer.h>
end_include

begin_include
include|#
directive|include
file|<linux/slab.h>
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_define
define|#
directive|define
name|WORK_CPU_UNBOUND
value|MAXCPU
end_define

begin_define
define|#
directive|define
name|WQ_UNBOUND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|WQ_HIGHPRI
value|(1<< 1)
end_define

begin_struct_decl
struct_decl|struct
name|work_struct
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|work_func_t
function_decl|)
parameter_list|(
name|struct
name|work_struct
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|work_exec
block|{
name|TAILQ_ENTRY
argument_list|(
argument|work_exec
argument_list|)
name|entry
expr_stmt|;
name|struct
name|work_struct
modifier|*
name|target
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|workqueue_struct
block|{
name|struct
name|taskqueue
modifier|*
name|taskqueue
decl_stmt|;
name|struct
name|mtx
name|exec_mtx
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|work_exec
argument_list|)
name|exec_head
expr_stmt|;
name|atomic_t
name|draining
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WQ_EXEC_LOCK
parameter_list|(
name|wq
parameter_list|)
value|mtx_lock(&(wq)->exec_mtx)
end_define

begin_define
define|#
directive|define
name|WQ_EXEC_UNLOCK
parameter_list|(
name|wq
parameter_list|)
value|mtx_unlock(&(wq)->exec_mtx)
end_define

begin_struct
struct|struct
name|work_struct
block|{
name|struct
name|task
name|work_task
decl_stmt|;
name|struct
name|workqueue_struct
modifier|*
name|work_queue
decl_stmt|;
name|work_func_t
name|func
decl_stmt|;
name|atomic_t
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DECLARE_WORK
parameter_list|(
name|name
parameter_list|,
name|fn
parameter_list|)
define|\
value|struct work_struct name;					\ 	static void name##_init(void *arg)				\ 	{								\ 		INIT_WORK(&name, fn);					\ 	}								\ 	SYSINIT(name, SI_SUB_LOCK, SI_ORDER_SECOND, name##_init, NULL)
end_define

begin_struct
struct|struct
name|delayed_work
block|{
name|struct
name|work_struct
name|work
decl_stmt|;
struct|struct
block|{
name|struct
name|callout
name|callout
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|int
name|expires
decl_stmt|;
block|}
name|timer
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DECLARE_DELAYED_WORK
parameter_list|(
name|name
parameter_list|,
name|fn
parameter_list|)
define|\
value|struct delayed_work name;					\ 	static void name##_init(void *arg)				\ 	{								\ 		linux_init_delayed_work(&name, fn);			\ 	}								\ 	SYSINIT(name, SI_SUB_LOCK, SI_ORDER_SECOND, name##_init, NULL)
end_define

begin_function
specifier|static
specifier|inline
name|struct
name|delayed_work
modifier|*
name|to_delayed_work
parameter_list|(
name|struct
name|work_struct
modifier|*
name|work
parameter_list|)
block|{
return|return
operator|(
name|container_of
argument_list|(
name|work
argument_list|,
expr|struct
name|delayed_work
argument_list|,
name|work
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|INIT_WORK
parameter_list|(
name|work
parameter_list|,
name|fn
parameter_list|)
define|\
value|do {									\ 	(work)->func = (fn);						\ 	(work)->work_queue = NULL;					\ 	atomic_set(&(work)->state, 0);					\ 	TASK_INIT(&(work)->work_task, 0, linux_work_fn, (work));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|INIT_WORK_ONSTACK
parameter_list|(
name|work
parameter_list|,
name|fn
parameter_list|)
define|\
value|INIT_WORK(work, fn)
end_define

begin_define
define|#
directive|define
name|INIT_DELAYED_WORK
parameter_list|(
name|dwork
parameter_list|,
name|fn
parameter_list|)
define|\
value|linux_init_delayed_work(dwork, fn)
end_define

begin_define
define|#
directive|define
name|INIT_DEFERRABLE_WORK
parameter_list|(
name|dwork
parameter_list|,
name|fn
parameter_list|)
define|\
value|INIT_DELAYED_WORK(dwork, fn)
end_define

begin_define
define|#
directive|define
name|flush_scheduled_work
parameter_list|()
define|\
value|taskqueue_drain_all(system_wq->taskqueue)
end_define

begin_define
define|#
directive|define
name|queue_work
parameter_list|(
name|wq
parameter_list|,
name|work
parameter_list|)
define|\
value|linux_queue_work_on(WORK_CPU_UNBOUND, wq, work)
end_define

begin_define
define|#
directive|define
name|schedule_work
parameter_list|(
name|work
parameter_list|)
define|\
value|linux_queue_work_on(WORK_CPU_UNBOUND, system_wq, work)
end_define

begin_define
define|#
directive|define
name|queue_delayed_work
parameter_list|(
name|wq
parameter_list|,
name|dwork
parameter_list|,
name|delay
parameter_list|)
define|\
value|linux_queue_delayed_work_on(WORK_CPU_UNBOUND, wq, dwork, delay)
end_define

begin_define
define|#
directive|define
name|schedule_delayed_work_on
parameter_list|(
name|cpu
parameter_list|,
name|dwork
parameter_list|,
name|delay
parameter_list|)
define|\
value|linux_queue_delayed_work_on(cpu, system_wq, dwork, delay)
end_define

begin_define
define|#
directive|define
name|queue_work_on
parameter_list|(
name|cpu
parameter_list|,
name|wq
parameter_list|,
name|work
parameter_list|)
define|\
value|linux_queue_work_on(cpu, wq, work)
end_define

begin_define
define|#
directive|define
name|schedule_delayed_work
parameter_list|(
name|dwork
parameter_list|,
name|delay
parameter_list|)
define|\
value|linux_queue_delayed_work_on(WORK_CPU_UNBOUND, system_wq, dwork, delay)
end_define

begin_define
define|#
directive|define
name|queue_delayed_work_on
parameter_list|(
name|cpu
parameter_list|,
name|wq
parameter_list|,
name|dwork
parameter_list|,
name|delay
parameter_list|)
define|\
value|linux_queue_delayed_work_on(cpu, wq, dwork, delay)
end_define

begin_define
define|#
directive|define
name|create_singlethread_workqueue
parameter_list|(
name|name
parameter_list|)
define|\
value|linux_create_workqueue_common(name, 1)
end_define

begin_define
define|#
directive|define
name|create_workqueue
parameter_list|(
name|name
parameter_list|)
define|\
value|linux_create_workqueue_common(name, mp_ncpus)
end_define

begin_define
define|#
directive|define
name|alloc_ordered_workqueue
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|)
define|\
value|linux_create_workqueue_common(name, 1)
end_define

begin_define
define|#
directive|define
name|alloc_workqueue
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|max_active
parameter_list|)
define|\
value|linux_create_workqueue_common(name, max_active)
end_define

begin_define
define|#
directive|define
name|flush_workqueue
parameter_list|(
name|wq
parameter_list|)
define|\
value|taskqueue_drain_all((wq)->taskqueue)
end_define

begin_define
define|#
directive|define
name|drain_workqueue
parameter_list|(
name|wq
parameter_list|)
value|do {		\ 	atomic_inc(&(wq)->draining);		\ 	taskqueue_drain_all((wq)->taskqueue);	\ 	atomic_dec(&(wq)->draining);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|mod_delayed_work
parameter_list|(
name|wq
parameter_list|,
name|dwork
parameter_list|,
name|delay
parameter_list|)
value|({		\ 	bool __retval;					\ 	__retval = linux_cancel_delayed_work(dwork);	\ 	linux_queue_delayed_work_on(WORK_CPU_UNBOUND,	\ 	    wq, dwork, delay);				\ 	__retval;					\ })
end_define

begin_define
define|#
directive|define
name|delayed_work_pending
parameter_list|(
name|dwork
parameter_list|)
define|\
value|linux_work_pending(&(dwork)->work)
end_define

begin_define
define|#
directive|define
name|cancel_delayed_work
parameter_list|(
name|dwork
parameter_list|)
define|\
value|linux_cancel_delayed_work(dwork)
end_define

begin_define
define|#
directive|define
name|cancel_work_sync
parameter_list|(
name|work
parameter_list|)
define|\
value|linux_cancel_work_sync(work)
end_define

begin_define
define|#
directive|define
name|cancel_delayed_work_sync
parameter_list|(
name|dwork
parameter_list|)
define|\
value|linux_cancel_delayed_work_sync(dwork)
end_define

begin_define
define|#
directive|define
name|flush_work
parameter_list|(
name|work
parameter_list|)
define|\
value|linux_flush_work(work)
end_define

begin_define
define|#
directive|define
name|flush_delayed_work
parameter_list|(
name|dwork
parameter_list|)
define|\
value|linux_flush_delayed_work(dwork)
end_define

begin_define
define|#
directive|define
name|work_pending
parameter_list|(
name|work
parameter_list|)
define|\
value|linux_work_pending(work)
end_define

begin_define
define|#
directive|define
name|work_busy
parameter_list|(
name|work
parameter_list|)
define|\
value|linux_work_busy(work)
end_define

begin_define
define|#
directive|define
name|destroy_work_on_stack
parameter_list|(
name|work
parameter_list|)
define|\
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|destroy_delayed_work_on_stack
parameter_list|(
name|dwork
parameter_list|)
define|\
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|destroy_workqueue
parameter_list|(
name|wq
parameter_list|)
define|\
value|linux_destroy_workqueue(wq)
end_define

begin_comment
comment|/* prototypes */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|workqueue_struct
modifier|*
name|system_wq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|workqueue_struct
modifier|*
name|system_long_wq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|workqueue_struct
modifier|*
name|system_unbound_wq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|workqueue_struct
modifier|*
name|system_power_efficient_wq
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|linux_init_delayed_work
parameter_list|(
name|struct
name|delayed_work
modifier|*
parameter_list|,
name|work_func_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linux_work_fn
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linux_delayed_work_fn
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|workqueue_struct
modifier|*
name|linux_create_workqueue_common
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linux_destroy_workqueue
parameter_list|(
name|struct
name|workqueue_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|linux_queue_work_on
parameter_list|(
name|int
name|cpu
parameter_list|,
name|struct
name|workqueue_struct
modifier|*
parameter_list|,
name|struct
name|work_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|linux_queue_delayed_work_on
parameter_list|(
name|int
name|cpu
parameter_list|,
name|struct
name|workqueue_struct
modifier|*
parameter_list|,
name|struct
name|delayed_work
modifier|*
parameter_list|,
name|unsigned
name|delay
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|linux_cancel_delayed_work
parameter_list|(
name|struct
name|delayed_work
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|linux_cancel_work_sync
parameter_list|(
name|struct
name|work_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|linux_cancel_delayed_work_sync
parameter_list|(
name|struct
name|delayed_work
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|linux_flush_work
parameter_list|(
name|struct
name|work_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|linux_flush_delayed_work
parameter_list|(
name|struct
name|delayed_work
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|linux_work_pending
parameter_list|(
name|struct
name|work_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|linux_work_busy
parameter_list|(
name|struct
name|work_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_WORKQUEUE_H_ */
end_comment

end_unit

