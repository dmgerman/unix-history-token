begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2001 by Thomas Moestl<tmm@FreeBSD.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FP_H_
end_define

begin_comment
comment|/* A block of 8 double-precision (16 single-precision) FP registers. */
end_comment

begin_struct
struct|struct
name|fpblock
block|{
name|u_long
name|fpq_l
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpstate
block|{
name|struct
name|fpblock
name|fp_fb
index|[
literal|4
index|]
decl_stmt|;
name|u_long
name|fp_fsr
decl_stmt|;
name|u_long
name|fp_fprs
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|fp_init_thread
parameter_list|(
name|struct
name|pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fp_enable_thread
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fp_exception_other
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Note: The pointers passed to the next two functions must be aligned on  * 64 byte boundaries.  */
end_comment

begin_function_decl
name|void
name|savefpctx
parameter_list|(
name|struct
name|fpstate
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|restorefpctx
parameter_list|(
name|struct
name|fpstate
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_FP_H_ */
end_comment

end_unit

