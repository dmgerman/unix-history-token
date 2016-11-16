begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|pcb
block|{
name|uint64_t
name|pcb_ra
decl_stmt|;
comment|/* Return address */
name|uint64_t
name|pcb_sp
decl_stmt|;
comment|/* Stack pointer */
name|uint64_t
name|pcb_gp
decl_stmt|;
comment|/* Global pointer */
name|uint64_t
name|pcb_tp
decl_stmt|;
comment|/* Thread pointer */
name|uint64_t
name|pcb_t
index|[
literal|7
index|]
decl_stmt|;
comment|/* Temporary registers */
name|uint64_t
name|pcb_s
index|[
literal|12
index|]
decl_stmt|;
comment|/* Saved registers */
name|uint64_t
name|pcb_a
index|[
literal|8
index|]
decl_stmt|;
comment|/* Argument registers */
name|uint64_t
name|pcb_x
index|[
literal|32
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* Floating point registers */
name|uint64_t
name|pcb_fcsr
decl_stmt|;
comment|/* Floating point control reg */
name|uint64_t
name|pcb_fpflags
decl_stmt|;
comment|/* Floating point flags */
define|#
directive|define
name|PCB_FP_STARTED
value|0x1
define|#
directive|define
name|PCB_FP_USERMASK
value|0x1
name|uint64_t
name|pcb_sepc
decl_stmt|;
comment|/* Supervisor exception pc */
name|vm_offset_t
name|pcb_l1addr
decl_stmt|;
comment|/* L1 page tables base address */
name|vm_offset_t
name|pcb_onfault
decl_stmt|;
comment|/* Copyinout fault handler */
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

