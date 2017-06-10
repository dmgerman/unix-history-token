begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCB_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<machine/vfp.h>
end_include

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|PCB_LR
value|30
end_define

begin_struct
struct|struct
name|pcb
block|{
name|uint64_t
name|pcb_x
index|[
literal|31
index|]
decl_stmt|;
name|uint64_t
name|pcb_pc
decl_stmt|;
comment|/* These two need to be in order as we access them together */
name|uint64_t
name|pcb_sp
decl_stmt|;
name|uint64_t
name|pcb_tpidr_el0
decl_stmt|;
name|uint64_t
name|pcb_tpidrro_el0
decl_stmt|;
name|vm_offset_t
name|pcb_l0addr
decl_stmt|;
comment|/* Fault handler, the error value is passed in x0 */
name|vm_offset_t
name|pcb_onfault
decl_stmt|;
name|u_int
name|pcb_flags
decl_stmt|;
define|#
directive|define
name|PCB_SINGLE_STEP_SHIFT
value|0
define|#
directive|define
name|PCB_SINGLE_STEP
value|(1<< PCB_SINGLE_STEP_SHIFT)
name|struct
name|vfpstate
modifier|*
name|pcb_fpusaved
decl_stmt|;
name|int
name|pcb_fpflags
decl_stmt|;
define|#
directive|define
name|PCB_FP_STARTED
value|0x01
define|#
directive|define
name|PCB_FP_KERN
value|0x02
comment|/* The bits passed to userspace in get_fpcontext */
define|#
directive|define
name|PCB_FP_USERMASK
value|(PCB_FP_STARTED)
name|u_int
name|pcb_vfpcpu
decl_stmt|;
comment|/* Last cpu this thread ran VFP code */
comment|/* 	 * The userspace VFP state. The pcb_fpusaved pointer will point to 	 * this unless the kernel has allocated a VFP context. 	 * Place last to simplify the asm to access the rest if the struct. 	 */
name|struct
name|vfpstate
name|pcb_fpustate
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|makectx
parameter_list|(
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|,
name|struct
name|pcb
modifier|*
name|pcb
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|savectx
argument_list|(
expr|struct
name|pcb
operator|*
name|pcb
argument_list|)
name|__returns_twice
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* !_MACHINE_PCB_H_ */
end_comment

end_unit

