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
literal|"no user-servicable parts inside"
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

begin_struct_decl
struct_decl|struct
name|taskqueue
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Each task includes a function which is called from  * taskqueue_run().  The first argument is taken from the 'ta_context'  * field of struct task and the second argument is a count of how many  * times the task was enqueued before the call to taskqueue_run().  */
end_comment

begin_typedef
typedef|typedef
name|void
name|task_fn_t
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
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

begin_struct
struct|struct
name|task
block|{
name|STAILQ_ENTRY
argument_list|(
argument|task
argument_list|)
name|ta_link
expr_stmt|;
comment|/* link for queue */
name|int
name|ta_pending
decl_stmt|;
comment|/* count times queued */
name|int
name|ta_priority
decl_stmt|;
comment|/* priority of task in queue */
name|task_fn_t
modifier|*
name|ta_func
decl_stmt|;
comment|/* task handler */
name|void
modifier|*
name|ta_context
decl_stmt|;
comment|/* argument for handler */
block|}
struct|;
end_struct

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
name|struct
name|taskqueue
modifier|*
name|taskqueue_find
parameter_list|(
specifier|const
name|char
modifier|*
name|name
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
comment|/*  * Define and initialise a taskqueue.  */
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
value|struct taskqueue *taskqueue_##name;					\ 									\ static void								\ taskqueue_define_##name(void *arg)					\ {									\ 	taskqueue_##name =						\ 	    taskqueue_create(#name, M_NOWAIT, (enqueue), (context));	\ 	init;								\ }									\ 									\ SYSINIT(taskqueue_##name, SI_SUB_CONFIGURE, SI_ORDER_SECOND,		\ 	taskqueue_define_##name, NULL)					\ 									\ struct __hack
end_define

begin_comment
comment|/*  * This queue is serviced by a software interrupt handler.  To enqueue  * a task, call taskqueue_enqueue(taskqueue_swi,&task).  */
end_comment

begin_expr_stmt
name|TASKQUEUE_DECLARE
argument_list|(
name|swi
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TASKQUEUE_H_ */
end_comment

end_unit

