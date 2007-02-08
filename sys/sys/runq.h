begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder<jake@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RUNQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_RUNQ_H_
end_define

begin_include
include|#
directive|include
file|<machine/runq.h>
end_include

begin_struct_decl
struct_decl|struct
name|td_sched
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Run queue parameters.  */
end_comment

begin_define
define|#
directive|define
name|RQ_NQS
value|(64)
end_define

begin_comment
comment|/* Number of run queues. */
end_comment

begin_define
define|#
directive|define
name|RQ_PPQ
value|(4)
end_define

begin_comment
comment|/* Priorities per queue. */
end_comment

begin_comment
comment|/*  * Head of run queues.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|rqhead
argument_list|,
name|td_sched
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Bit array which maintains the status of a run queue.  When a queue is  * non-empty the bit corresponding to the queue number will be set.  */
end_comment

begin_struct
struct|struct
name|rqbits
block|{
name|rqb_word_t
name|rqb_bits
index|[
name|RQB_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Run queue structure.  Contains an array of run queues on which processes  * are placed, and a structure to maintain the status of each queue.  */
end_comment

begin_struct
struct|struct
name|runq
block|{
name|struct
name|rqbits
name|rq_status
decl_stmt|;
name|struct
name|rqhead
name|rq_queues
index|[
name|RQ_NQS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|runq_add
parameter_list|(
name|struct
name|runq
modifier|*
parameter_list|,
name|struct
name|td_sched
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|runq_add_pri
parameter_list|(
name|struct
name|runq
modifier|*
parameter_list|,
name|struct
name|td_sched
modifier|*
parameter_list|,
name|u_char
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|runq_check
parameter_list|(
name|struct
name|runq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|td_sched
modifier|*
name|runq_choose
parameter_list|(
name|struct
name|runq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|td_sched
modifier|*
name|runq_choose_from
parameter_list|(
name|struct
name|runq
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|runq_init
parameter_list|(
name|struct
name|runq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|runq_remove
parameter_list|(
name|struct
name|runq
modifier|*
parameter_list|,
name|struct
name|td_sched
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|runq_remove_idx
parameter_list|(
name|struct
name|runq
modifier|*
parameter_list|,
name|struct
name|td_sched
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

