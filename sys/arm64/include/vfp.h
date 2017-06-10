begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_VFP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_VFP_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|vfpstate
block|{
name|__uint128_t
name|vfp_regs
index|[
literal|32
index|]
decl_stmt|;
name|uint32_t
name|vfp_fpcr
decl_stmt|;
name|uint32_t
name|vfp_fpsr
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

begin_function_decl
name|void
name|vfp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfp_discard
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfp_restore_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfp_save_state
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|fpu_kern_ctx
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Flags for fpu_kern_alloc_ctx(), fpu_kern_enter() and fpu_kern_thread().  */
end_comment

begin_define
define|#
directive|define
name|FPU_KERN_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|FPU_KERN_NOWAIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|FPU_KERN_KTHR
value|0x0002
end_define

begin_function_decl
name|struct
name|fpu_kern_ctx
modifier|*
name|fpu_kern_alloc_ctx
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpu_kern_free_ctx
parameter_list|(
name|struct
name|fpu_kern_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_kern_enter
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpu_kern_ctx
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_kern_leave
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpu_kern_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_kern_thread
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_fpu_kern_thread
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_VFP_H_ */
end_comment

end_unit

