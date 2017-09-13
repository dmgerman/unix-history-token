begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Jeffrey Roberson<jeff@freebsd.org>  * Copyright (c) 2016 Matthew Macy<mmacy@nextbsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_GTASKQUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_GTASKQUEUE_H_
end_define

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

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

begin_struct_decl
struct_decl|struct
name|gtaskqueue
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|gtaskqueue_enqueue_fn
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Taskqueue groups.  Manages dynamic thread groups and irq binding for  * device and other tasks.  */
end_comment

begin_function_decl
name|void
name|gtaskqueue_block
parameter_list|(
name|struct
name|gtaskqueue
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gtaskqueue_unblock
parameter_list|(
name|struct
name|gtaskqueue
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gtaskqueue_cancel
parameter_list|(
name|struct
name|gtaskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|gtask
modifier|*
name|gtask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gtaskqueue_drain
parameter_list|(
name|struct
name|gtaskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|gtask
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gtaskqueue_drain_all
parameter_list|(
name|struct
name|gtaskqueue
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|grouptaskqueue_enqueue
parameter_list|(
name|struct
name|gtaskqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|gtask
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqgroup_attach
parameter_list|(
name|struct
name|taskqgroup
modifier|*
name|qgroup
parameter_list|,
name|struct
name|grouptask
modifier|*
name|grptask
parameter_list|,
name|void
modifier|*
name|uniq
parameter_list|,
name|int
name|irq
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqgroup_attach_cpu
parameter_list|(
name|struct
name|taskqgroup
modifier|*
name|qgroup
parameter_list|,
name|struct
name|grouptask
modifier|*
name|grptask
parameter_list|,
name|void
modifier|*
name|uniq
parameter_list|,
name|int
name|cpu
parameter_list|,
name|int
name|irq
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqgroup_detach
parameter_list|(
name|struct
name|taskqgroup
modifier|*
name|qgroup
parameter_list|,
name|struct
name|grouptask
modifier|*
name|gtask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|taskqgroup
modifier|*
name|taskqgroup_create
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqgroup_destroy
parameter_list|(
name|struct
name|taskqgroup
modifier|*
name|qgroup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqgroup_adjust
parameter_list|(
name|struct
name|taskqgroup
modifier|*
name|qgroup
parameter_list|,
name|int
name|cnt
parameter_list|,
name|int
name|stride
parameter_list|,
name|bool
name|ithread
parameter_list|,
name|int
name|pri
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|taskqgroup_adjust_once
parameter_list|(
name|struct
name|taskqgroup
modifier|*
name|qgroup
parameter_list|,
name|int
name|cnt
parameter_list|,
name|int
name|stride
parameter_list|,
name|bool
name|ithread
parameter_list|,
name|int
name|pri
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|taskqgroup_set_adjust
parameter_list|(
name|struct
name|taskqgroup
modifier|*
name|qgroup
parameter_list|,
name|void
function_decl|(
modifier|*
name|adjust_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TASK_ENQUEUED
value|0x1
end_define

begin_define
define|#
directive|define
name|TASK_SKIP_WAKEUP
value|0x2
end_define

begin_define
define|#
directive|define
name|GTASK_INIT
parameter_list|(
name|task
parameter_list|,
name|flags
parameter_list|,
name|priority
parameter_list|,
name|func
parameter_list|,
name|context
parameter_list|)
value|do {	\ 	(task)->ta_flags = flags;				\ 	(task)->ta_priority = (priority);		\ 	(task)->ta_func = (func);			\ 	(task)->ta_context = (context);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|GROUPTASK_INIT
parameter_list|(
name|gtask
parameter_list|,
name|priority
parameter_list|,
name|func
parameter_list|,
name|context
parameter_list|)
define|\
value|GTASK_INIT(&(gtask)->gt_task, TASK_SKIP_WAKEUP, priority, func, context)
end_define

begin_define
define|#
directive|define
name|GROUPTASK_ENQUEUE
parameter_list|(
name|gtask
parameter_list|)
define|\
value|grouptaskqueue_enqueue((gtask)->gt_taskqueue,&(gtask)->gt_task)
end_define

begin_define
define|#
directive|define
name|TASKQGROUP_DECLARE
parameter_list|(
name|name
parameter_list|)
define|\
value|extern struct taskqgroup *qgroup_##name
end_define

begin_define
define|#
directive|define
name|TASKQGROUP_DEFINE
parameter_list|(
name|name
parameter_list|,
name|cnt
parameter_list|,
name|stride
parameter_list|,
name|intr
parameter_list|,
name|pri
parameter_list|)
define|\ 									\
value|struct taskqgroup *qgroup_##name;					\ 									\ static void								\ taskqgroup_adjust_##name(void *arg)					\ {									\ 	int max = (intr) ? 1 : (cnt);					\ 	if (arg != NULL) {						\ 		uintptr_t maxcpu = (uintptr_t) arg;				\ 		max = maxcpu;						\ 	}								\ 									\ 	taskqgroup_adjust_once(qgroup_##name, max, (stride), (intr), (pri)); \ }									\ 									\ SYSINIT(taskqgroup_adj_##name, SI_SUB_SMP, SI_ORDER_ANY,		\ 	taskqgroup_adjust_##name, NULL);				\ 									\ static void								\ taskqgroup_define_##name(void *arg)					\ {									\ 	qgroup_##name = taskqgroup_create(#name);			\ 	taskqgroup_set_adjust(qgroup_##name, taskqgroup_adjust_##name); \ }									\ SYSINIT(taskqgroup_##name, SI_SUB_TASKQ, SI_ORDER_FIRST,		\ 	taskqgroup_define_##name, NULL)
end_define

begin_expr_stmt
name|TASKQGROUP_DECLARE
argument_list|(
name|net
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TASKQGROUP_DECLARE
argument_list|(
name|softirq
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_GTASKQUEUE_H_ */
end_comment

end_unit

