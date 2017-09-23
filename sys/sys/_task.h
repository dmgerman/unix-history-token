begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__TASK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__TASK_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Each task includes a function which is called from  * taskqueue_run().  The first argument is taken from the 'ta_context'  * field of struct task and the second argument is a count of how many  * times the task was enqueued before the call to taskqueue_run().  *  * List of locks	   * (c)	const after init	   * (q)	taskqueue lock  */
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

begin_typedef
typedef|typedef
name|void
name|gtask_fn_t
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
comment|/* (q) link for queue */
name|uint16_t
name|ta_pending
decl_stmt|;
comment|/* (q) count times queued */
name|u_short
name|ta_priority
decl_stmt|;
comment|/* (c) Priority */
name|task_fn_t
modifier|*
name|ta_func
decl_stmt|;
comment|/* (c) task handler */
name|void
modifier|*
name|ta_context
decl_stmt|;
comment|/* (c) argument for handler */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gtask
block|{
name|STAILQ_ENTRY
argument_list|(
argument|gtask
argument_list|)
name|ta_link
expr_stmt|;
comment|/* (q) link for queue */
name|uint16_t
name|ta_flags
decl_stmt|;
comment|/* (q) state flags */
name|u_short
name|ta_priority
decl_stmt|;
comment|/* (c) Priority */
name|gtask_fn_t
modifier|*
name|ta_func
decl_stmt|;
comment|/* (c) task handler */
name|void
modifier|*
name|ta_context
decl_stmt|;
comment|/* (c) argument for handler */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|grouptask
block|{
name|struct
name|gtask
name|gt_task
decl_stmt|;
name|void
modifier|*
name|gt_taskqueue
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|grouptask
argument_list|)
name|gt_list
expr_stmt|;
name|void
modifier|*
name|gt_uniq
decl_stmt|;
define|#
directive|define
name|GROUPTASK_NAMELEN
value|32
name|char
name|gt_name
index|[
name|GROUPTASK_NAMELEN
index|]
decl_stmt|;
name|int16_t
name|gt_irq
decl_stmt|;
name|int16_t
name|gt_cpu
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__TASK_H_ */
end_comment

end_unit

