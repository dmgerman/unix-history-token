begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TASKQUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TASKQUEUE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_task.h>
end_include

begin_include
include|#
directive|include
file|<sys/_callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
end_include

begin_struct_decl
struct_decl|struct
name|taskqueue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|taskqgroup
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|timeout_task
block|{
name|struct
name|taskqueue
modifier|*
name|q
decl_stmt|;
name|struct
name|task
name|t
decl_stmt|;
name|struct
name|callout
name|c
decl_stmt|;
name|int
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|taskqueue_callback_type
block|{
name|TASKQUEUE_CALLBACK_TYPE_INIT
block|,
name|TASKQUEUE_CALLBACK_TYPE_SHUTDOWN
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|TASKQUEUE_CALLBACK_TYPE_MIN
value|TASKQUEUE_CALLBACK_TYPE_INIT
end_define

begin_define
define|#
directive|define
name|TASKQUEUE_CALLBACK_TYPE_MAX
value|TASKQUEUE_CALLBACK_TYPE_SHUTDOWN
end_define

begin_define
define|#
directive|define
name|TASKQUEUE_NUM_CALLBACKS
value|TASKQUEUE_CALLBACK_TYPE_MAX + 1
end_define

begin_define
define|#
directive|define
name|TASKQUEUE_NAMELEN
value|32
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|taskqueue_callback_fn
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * A notification callback function which is called from  * taskqueue_enqueue().  The context argument is given in the call to  * taskqueue_create().  This function would normally be used to allow the  * queue to arrange to run itself later (e.g., by scheduling a software  * interrupt or waking a kernel thread).  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|taskqueue_enqueue_fn
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|taskqueue
modifier|*
name|taskqueue_create
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|mflags
parameter_list|,
name|taskqueue_enqueue_fn
name|enqueue
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqueue_start_threads
parameter_list|(
name|struct
name|taskqueue
modifier|*
modifier|*
name|tqp
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|pri
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|taskqueue_start_threads_cpuset
parameter_list|(
name|struct
name|taskqueue
modifier|*
modifier|*
name|tqp
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|pri
parameter_list|,
name|cpuset_t
modifier|*
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|5
operator|,
function_decl|6
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|taskqueue_enqueue
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|task
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqueue_enqueue_timeout
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|timeout_task
modifier|*
name|timeout_task
parameter_list|,
name|int
name|ticks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqueue_enqueue_timeout_sbt
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|timeout_task
modifier|*
name|timeout_task
parameter_list|,
name|sbintime_t
name|sbt
parameter_list|,
name|sbintime_t
name|pr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqueue_poll_is_busy
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|task
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqueue_cancel
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|task
modifier|*
name|task
parameter_list|,
name|u_int
modifier|*
name|pendp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqueue_cancel_timeout
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|timeout_task
modifier|*
name|timeout_task
parameter_list|,
name|u_int
modifier|*
name|pendp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqueue_drain
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|task
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqueue_drain_timeout
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|timeout_task
modifier|*
name|timeout_task
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqueue_drain_all
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqueue_free
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqueue_run
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqueue_block
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqueue_unblock
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqueue_member
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
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
name|taskqueue_set_callback
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|enum
name|taskqueue_callback_type
name|cb_type
parameter_list|,
name|taskqueue_callback_fn
name|callback
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TASK_INITIALIZER
parameter_list|(
name|priority
parameter_list|,
name|func
parameter_list|,
name|context
parameter_list|)
define|\
value|{ .ta_pending = 0,				\ 	  .ta_priority = (priority),			\ 	  .ta_func = (func),				\ 	  .ta_context = (context) }
end_define

begin_comment
comment|/*  * Functions for dedicated thread taskqueues  */
end_comment

begin_function_decl
name|void
name|taskqueue_thread_loop
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqueue_thread_enqueue
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialise a task structure.  */
end_comment

begin_define
define|#
directive|define
name|TASK_INIT
parameter_list|(
name|task
parameter_list|,
name|priority
parameter_list|,
name|func
parameter_list|,
name|context
parameter_list|)
value|do {	\ 	(task)->ta_pending = 0;				\ 	(task)->ta_priority = (priority);		\ 	(task)->ta_func = (func);			\ 	(task)->ta_context = (context);			\ } while (0)
end_define

begin_function_decl
name|void
name|_timeout_task_init
parameter_list|(
name|struct
name|taskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|timeout_task
modifier|*
name|timeout_task
parameter_list|,
name|int
name|priority
parameter_list|,
name|task_fn_t
name|func
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TIMEOUT_TASK_INIT
parameter_list|(
name|queue
parameter_list|,
name|timeout_task
parameter_list|,
name|priority
parameter_list|,
name|func
parameter_list|,
name|context
parameter_list|)
define|\
value|_timeout_task_init(queue, timeout_task, priority, func, context);
end_define

begin_comment
comment|/*  * Declare a reference to a taskqueue.  */
end_comment

begin_define
define|#
directive|define
name|TASKQUEUE_DECLARE
parameter_list|(
name|name
parameter_list|)
define|\
value|extern struct taskqueue *taskqueue_##name
end_define

begin_comment
comment|/*  * Define and initialise a global taskqueue that uses sleep mutexes.  */
end_comment

begin_define
define|#
directive|define
name|TASKQUEUE_DEFINE
parameter_list|(
name|name
parameter_list|,
name|enqueue
parameter_list|,
name|context
parameter_list|,
name|init
parameter_list|)
define|\ 									\
value|struct taskqueue *taskqueue_##name;					\ 									\ static void								\ taskqueue_define_##name(void *arg)					\ {									\ 	taskqueue_##name =						\ 	    taskqueue_create(#name, M_WAITOK, (enqueue), (context));	\ 	init;								\ }									\ 									\ SYSINIT(taskqueue_##name, SI_SUB_INIT_IF, SI_ORDER_SECOND,		\ 	taskqueue_define_##name, NULL);					\ 									\ struct __hack
end_define

begin_define
define|#
directive|define
name|TASKQUEUE_DEFINE_THREAD
parameter_list|(
name|name
parameter_list|)
define|\
value|TASKQUEUE_DEFINE(name, taskqueue_thread_enqueue,&taskqueue_##name,	\ 	taskqueue_start_threads(&taskqueue_##name, 1, PWAIT,		\ 	"%s taskq", #name))
end_define

begin_comment
comment|/*  * Define and initialise a global taskqueue that uses spin mutexes.  */
end_comment

begin_define
define|#
directive|define
name|TASKQUEUE_FAST_DEFINE
parameter_list|(
name|name
parameter_list|,
name|enqueue
parameter_list|,
name|context
parameter_list|,
name|init
parameter_list|)
define|\ 									\
value|struct taskqueue *taskqueue_##name;					\ 									\ static void								\ taskqueue_define_##name(void *arg)					\ {									\ 	taskqueue_##name =						\ 	    taskqueue_create_fast(#name, M_WAITOK, (enqueue),		\ 	    (context));							\ 	init;								\ }									\ 									\ SYSINIT(taskqueue_##name, SI_SUB_INIT_IF, SI_ORDER_SECOND,		\ 	taskqueue_define_##name, NULL);					\ 									\ struct __hack
end_define

begin_define
define|#
directive|define
name|TASKQUEUE_FAST_DEFINE_THREAD
parameter_list|(
name|name
parameter_list|)
define|\
value|TASKQUEUE_FAST_DEFINE(name, taskqueue_thread_enqueue,			\&taskqueue_##name, taskqueue_start_threads(&taskqueue_##name	\ 	1, PWAIT, "%s taskq", #name))
end_define

begin_comment
comment|/*  * These queues are serviced by software interrupt handlers.  To enqueue  * a task, call taskqueue_enqueue(taskqueue_swi,&task) or  * taskqueue_enqueue(taskqueue_swi_giant,&task).  */
end_comment

begin_expr_stmt
name|TASKQUEUE_DECLARE
argument_list|(
name|swi_giant
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TASKQUEUE_DECLARE
argument_list|(
name|swi
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This queue is serviced by a kernel thread.  To enqueue a task, call  * taskqueue_enqueue(taskqueue_thread,&task).  */
end_comment

begin_expr_stmt
name|TASKQUEUE_DECLARE
argument_list|(
name|thread
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Queue for swi handlers dispatched from fast interrupt handlers.  * These are necessarily different from the above because the queue  * must be locked with spinlocks since sleep mutex's cannot be used  * from a fast interrupt handler context.  */
end_comment

begin_expr_stmt
name|TASKQUEUE_DECLARE
argument_list|(
name|fast
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|struct
name|taskqueue
modifier|*
name|taskqueue_create_fast
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|mflags
parameter_list|,
name|taskqueue_enqueue_fn
name|enqueue
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TASKQUEUE_H_ */
end_comment

end_unit

