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
file|<machine/vfp.h>
end_include

begin_comment
comment|/*  * WARNING!  * Keep pcb_regs first for faster access in switch.S  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|struct
name|switchframe
name|pcb_regs
decl_stmt|;
comment|/* CPU state */
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
name|vm_offset_t
name|pcb_pagedir
decl_stmt|;
comment|/* TTB0 value */
comment|/* 	 * XXX: 	 * Variables pcb_pl1vec, pcb_l1vec, pcb_dacr are used solely 	 * by old PMAP. Keep them here for PCB binary compatibility 	 * between old and new PMAP. 	 */
name|uint32_t
modifier|*
name|pcb_pl1vec
decl_stmt|;
comment|/* PTR to vector_base L1 entry*/
name|uint32_t
name|pcb_l1vec
decl_stmt|;
comment|/* Value to stuff on ctx sw */
name|u_int
name|pcb_dacr
decl_stmt|;
comment|/* Domain Access Control Reg */
name|struct
name|vfp_state
name|pcb_vfpstate
decl_stmt|;
comment|/* VP/NEON state */
name|u_int
name|pcb_vfpcpu
decl_stmt|;
comment|/* VP/NEON last cpu */
block|}
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_comment
comment|/* 		 * We need the PCB to be aligned on 8 bytes, as we may 		 * access it using ldrd/strd, and ARM ABI require it 		 * to by aligned on 8 bytes. 		 */
end_comment

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

begin_decl_stmt
name|void
name|savectx
argument_list|(
expr|struct
name|pcb
operator|*
argument_list|)
name|__returns_twice
decl_stmt|;
end_decl_stmt

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

