begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Peter Wemm.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)pcb.h	5.10 (Berkeley) 5/12/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AMD64_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_AMD64_PCB_H_
end_define

begin_comment
comment|/*  * AMD64 process control block  */
end_comment

begin_include
include|#
directive|include
file|<machine/fpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_struct
struct|struct
name|pcb
block|{
name|register_t
name|pcb_cr3
decl_stmt|;
name|register_t
name|pcb_r15
decl_stmt|;
name|register_t
name|pcb_r14
decl_stmt|;
name|register_t
name|pcb_r13
decl_stmt|;
name|register_t
name|pcb_r12
decl_stmt|;
name|register_t
name|pcb_rbp
decl_stmt|;
name|register_t
name|pcb_rsp
decl_stmt|;
name|register_t
name|pcb_rbx
decl_stmt|;
name|register_t
name|pcb_rip
decl_stmt|;
name|register_t
name|pcb_fsbase
decl_stmt|;
name|register_t
name|pcb_gsbase
decl_stmt|;
name|u_int32_t
name|pcb_ds
decl_stmt|;
name|u_int32_t
name|pcb_es
decl_stmt|;
name|u_int32_t
name|pcb_fs
decl_stmt|;
name|u_int32_t
name|pcb_gs
decl_stmt|;
name|u_int64_t
name|pcb_dr0
decl_stmt|;
name|u_int64_t
name|pcb_dr1
decl_stmt|;
name|u_int64_t
name|pcb_dr2
decl_stmt|;
name|u_int64_t
name|pcb_dr3
decl_stmt|;
name|u_int64_t
name|pcb_dr6
decl_stmt|;
name|u_int64_t
name|pcb_dr7
decl_stmt|;
name|struct
name|savefpu
name|pcb_save
decl_stmt|;
name|u_long
name|pcb_flags
decl_stmt|;
define|#
directive|define
name|PCB_DBREGS
value|0x02
comment|/* process using debug registers */
define|#
directive|define
name|PCB_FPUINITDONE
value|0x08
comment|/* fpu state is initialized */
define|#
directive|define
name|PCB_32BIT
value|0x40
comment|/* process has 32 bit context (segs etc) */
define|#
directive|define
name|PCB_FULLCTX
value|0x80
comment|/* full context restore on sysret */
name|caddr_t
name|pcb_onfault
decl_stmt|;
comment|/* copyin/out fault recovery */
comment|/* 32-bit segment descriptor */
name|struct
name|user_segment_descriptor
modifier|*
name|pcb_gs32p
decl_stmt|;
name|struct
name|user_segment_descriptor
name|pcb_gs32sd
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
name|trapframe
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|makectx
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|struct
name|pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AMD64_PCB_H_ */
end_comment

end_unit

