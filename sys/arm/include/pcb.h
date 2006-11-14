begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pcb.h,v 1.10 2003/10/13 21:46:39 scw Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Matt Thomas<matt@3am-software.com>.  * Copyright (c) 1994 Mark Brinicombe.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the RiscBSD team.  * 4. The name "RiscBSD" nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY RISCBSD ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL RISCBSD OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/fp.h>
end_include

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|pcb_arm32
block|{
name|vm_offset_t
name|pcb32_pagedir
decl_stmt|;
comment|/* PT hooks */
name|uint32_t
modifier|*
name|pcb32_pl1vec
decl_stmt|;
comment|/* PTR to vector_base L1 entry*/
name|uint32_t
name|pcb32_l1vec
decl_stmt|;
comment|/* Value to stuff on ctx sw */
name|u_int
name|pcb32_dacr
decl_stmt|;
comment|/* Domain Access Control Reg */
comment|/* 	 * WARNING! 	 * cpuswitch.S relies on pcb32_r8 being quad-aligned in struct pcb 	 * (due to the use of "strd" when compiled for XSCALE) 	 */
name|u_int
name|pcb32_r8
decl_stmt|;
comment|/* used */
name|u_int
name|pcb32_r9
decl_stmt|;
comment|/* used */
name|u_int
name|pcb32_r10
decl_stmt|;
comment|/* used */
name|u_int
name|pcb32_r11
decl_stmt|;
comment|/* used */
name|u_int
name|pcb32_r12
decl_stmt|;
comment|/* used */
name|u_int
name|pcb32_sp
decl_stmt|;
comment|/* used */
name|u_int
name|pcb32_lr
decl_stmt|;
name|u_int
name|pcb32_pc
decl_stmt|;
name|u_int
name|pcb32_und_sp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pcb_pagedir
value|un_32.pcb32_pagedir
end_define

begin_define
define|#
directive|define
name|pcb_pl1vec
value|un_32.pcb32_pl1vec
end_define

begin_define
define|#
directive|define
name|pcb_l1vec
value|un_32.pcb32_l1vec
end_define

begin_define
define|#
directive|define
name|pcb_dacr
value|un_32.pcb32_dacr
end_define

begin_define
define|#
directive|define
name|pcb_cstate
value|un_32.pcb32_cstate
end_define

begin_comment
comment|/*  * WARNING!  * See warning for struct pcb_arm32, above, before changing struct pcb!  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|u_int
name|pcb_flags
decl_stmt|;
define|#
directive|define
name|PCB_OWNFPU
value|0x00000001
define|#
directive|define
name|PCB_NOALIGNFLT
value|0x00000002
name|caddr_t
name|pcb_onfault
decl_stmt|;
comment|/* On fault handler */
name|struct
name|pcb_arm32
name|un_32
decl_stmt|;
name|struct
name|fpe_sp_state
name|pcb_fpstate
decl_stmt|;
comment|/* Floating Point state */
block|}
struct|;
end_struct

begin_comment
comment|/*  * No additional data for core dumps.  */
end_comment

begin_struct
struct|struct
name|md_coredump
block|{
name|int
name|md_empty
decl_stmt|;
block|}
struct|;
end_struct

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|savectx
parameter_list|(
name|struct
name|pcb
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
comment|/* !_MACHINE_PCB_H_ */
end_comment

end_unit

