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
name|IRSR_BUSY
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PIL_MAX
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IV_MAX
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IV_NAMLEN
value|1024
end_define

begin_define
define|#
directive|define
name|IR_FREE
value|(PIL_MAX * 2)
end_define

begin_define
define|#
directive|define
name|IH_SHIFT
value|PTR_SHIFT
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
name|PIL_LOW
value|1
end_define

begin_comment
comment|/* stray interrupts */
end_comment

begin_define
define|#
directive|define
name|PIL_ITHREAD
value|2
end_define

begin_comment
comment|/* interrupts that use ithreads */
end_comment

begin_define
define|#
directive|define
name|PIL_RENDEZVOUS
value|3
end_define

begin_comment
comment|/* smp rendezvous ipi */
end_comment

begin_define
define|#
directive|define
name|PIL_AST
value|4
end_define

begin_comment
comment|/* ast ipi */
end_comment

begin_define
define|#
directive|define
name|PIL_STOP
value|5
end_define

begin_comment
comment|/* stop cpu ipi */
end_comment

begin_define
define|#
directive|define
name|PIL_FAST
value|13
end_define

begin_comment
comment|/* fast interrupts */
end_comment

begin_define
define|#
directive|define
name|PIL_TICK
value|14
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

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

begin_struct_decl
struct_decl|struct
name|ithd
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|intr_request
block|{
name|struct
name|intr_request
modifier|*
name|ir_next
decl_stmt|;
name|iv_func_t
modifier|*
name|ir_func
decl_stmt|;
name|void
modifier|*
name|ir_arg
decl_stmt|;
name|u_int
name|ir_vec
decl_stmt|;
name|u_int
name|ir_pri
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
name|void
modifier|*
name|iv_arg
decl_stmt|;
name|struct
name|intr_event
modifier|*
name|iv_event
decl_stmt|;
name|u_int
name|iv_pri
decl_stmt|;
name|u_int
name|iv_vec
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|ih_func_t
modifier|*
name|intr_handlers
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

begin_function_decl
name|void
name|intr_init1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_init2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inthand_add
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|vec
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inthand_remove
parameter_list|(
name|int
name|vec
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ih_func_t
name|intr_fast
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_INTR_MACHDEP_H_ */
end_comment

end_unit

