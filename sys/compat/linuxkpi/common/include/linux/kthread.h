begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_KTHREAD_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_KTHREAD_H_
end_define

begin_include
include|#
directive|include
file|<linux/sched.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_define
define|#
directive|define
name|kthread_run
parameter_list|(
name|fn
parameter_list|,
name|data
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|({				\ 	struct task_struct *__task;					\ 	struct thread *__td;						\ 									\ 	if (kthread_add(linux_kthread_fn, NULL, NULL,&__td,		\ 	    RFSTOPPED, 0, fmt, ## __VA_ARGS__))				\ 		__task = NULL;						\ 	else								\ 		__task = linux_kthread_setup_and_run(__td, fn, data);	\ 	__task;								\ })
end_define

begin_function_decl
name|int
name|linux_kthread_stop
parameter_list|(
name|struct
name|task_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|linux_kthread_should_stop_task
parameter_list|(
name|struct
name|task_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|linux_kthread_should_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_kthread_park
parameter_list|(
name|struct
name|task_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_kthread_parkme
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|linux_kthread_should_park
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_kthread_unpark
parameter_list|(
name|struct
name|task_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_kthread_fn
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|task_struct
modifier|*
name|linux_kthread_setup_and_run
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|linux_task_fn_t
modifier|*
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_in_atomic
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|kthread_stop
parameter_list|(
name|task
parameter_list|)
value|linux_kthread_stop(task)
end_define

begin_define
define|#
directive|define
name|kthread_should_stop
parameter_list|()
value|linux_kthread_should_stop()
end_define

begin_define
define|#
directive|define
name|kthread_should_stop_task
parameter_list|(
name|task
parameter_list|)
value|linux_kthread_should_stop_task(task)
end_define

begin_define
define|#
directive|define
name|kthread_park
parameter_list|(
name|task
parameter_list|)
value|linux_kthread_park(task)
end_define

begin_define
define|#
directive|define
name|kthread_parkme
parameter_list|()
value|linux_kthread_parkme()
end_define

begin_define
define|#
directive|define
name|kthread_should_park
parameter_list|()
value|linux_kthread_should_park()
end_define

begin_define
define|#
directive|define
name|kthread_unpark
parameter_list|(
name|task
parameter_list|)
value|linux_kthread_unpark(task)
end_define

begin_define
define|#
directive|define
name|in_atomic
parameter_list|()
value|linux_in_atomic()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_KTHREAD_H_ */
end_comment

end_unit

