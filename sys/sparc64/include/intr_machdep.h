begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INTR_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INTR_MACHDEP_H_
end_define

begin_define
define|#
directive|define
name|NPIL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|NIV
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IQ_SIZE
value|(NPIL * 2)
end_define

begin_define
define|#
directive|define
name|IQ_MASK
value|(IQ_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|IQE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IV_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|PIL_TICK
value|14
end_define

begin_typedef
typedef|typedef
name|void
name|ih_func_t
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|iv_func_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|intr_handler
block|{
name|ih_func_t
modifier|*
name|ih_func
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iqe
block|{
name|u_int
name|iqe_tag
decl_stmt|;
name|u_int
name|iqe_pri
decl_stmt|;
name|u_long
name|iqe_vec
decl_stmt|;
name|iv_func_t
modifier|*
name|iqe_func
decl_stmt|;
name|void
modifier|*
name|iqe_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|intr_queue
block|{
name|struct
name|iqe
name|iq_queue
index|[
name|IQ_SIZE
index|]
decl_stmt|;
comment|/* must be first */
name|u_long
name|iq_head
decl_stmt|;
name|u_long
name|iq_tail
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|intr_vector
block|{
name|iv_func_t
modifier|*
name|iv_func
decl_stmt|;
comment|/* must be first */
name|void
modifier|*
name|iv_arg
decl_stmt|;
name|u_int
name|iv_pri
decl_stmt|;
name|u_int
name|iv_pad
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|intr_handler
name|intr_handlers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intr_queue
name|intr_queues
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intr_vector
name|intr_vectors
index|[]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|void
name|intr_dispatch
parameter_list|(
name|int
name|level
parameter_list|,
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
block|{
name|intr_handlers
index|[
name|level
index|]
operator|.
name|ih_func
argument_list|(
name|tf
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|intr_setup
parameter_list|(
name|int
name|level
parameter_list|,
name|ih_func_t
modifier|*
name|ihf
parameter_list|,
name|int
name|pri
parameter_list|,
name|iv_func_t
modifier|*
name|ivf
parameter_list|,
name|void
modifier|*
name|iva
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ih_func_t
name|intr_dequeue
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

