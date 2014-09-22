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

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_struct
struct|struct
name|pcb
block|{
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
name|register_t
name|pcb_kgsbase
decl_stmt|;
name|register_t
name|pcb_cr0
decl_stmt|;
name|register_t
name|pcb_cr2
decl_stmt|;
name|register_t
name|pcb_cr3
decl_stmt|;
name|register_t
name|pcb_cr4
decl_stmt|;
name|register_t
name|pcb_dr0
decl_stmt|;
name|register_t
name|pcb_dr1
decl_stmt|;
name|register_t
name|pcb_dr2
decl_stmt|;
name|register_t
name|pcb_dr3
decl_stmt|;
name|register_t
name|pcb_dr6
decl_stmt|;
name|register_t
name|pcb_dr7
decl_stmt|;
name|struct
name|region_descriptor
name|pcb_gdt
decl_stmt|;
name|struct
name|region_descriptor
name|pcb_idt
decl_stmt|;
name|struct
name|region_descriptor
name|pcb_ldt
decl_stmt|;
name|uint16_t
name|pcb_tr
decl_stmt|;
name|u_int
name|pcb_flags
decl_stmt|;
define|#
directive|define
name|PCB_FULL_IRET
value|0x01
comment|/* full iret is required */
define|#
directive|define
name|PCB_DBREGS
value|0x02
comment|/* process using debug registers */
define|#
directive|define
name|PCB_KERNFPU
value|0x04
comment|/* kernel uses fpu */
define|#
directive|define
name|PCB_FPUINITDONE
value|0x08
comment|/* fpu state is initialized */
define|#
directive|define
name|PCB_USERFPUINITDONE
value|0x10
comment|/* fpu user state is initialized */
define|#
directive|define
name|PCB_32BIT
value|0x40
comment|/* process has 32 bit context (segs etc) */
name|uint16_t
name|pcb_initial_fpucw
decl_stmt|;
comment|/* copyin/out fault recovery */
name|caddr_t
name|pcb_onfault
decl_stmt|;
comment|/* 32-bit segment descriptor */
name|struct
name|user_segment_descriptor
name|pcb_gs32sd
decl_stmt|;
comment|/* local tss, with i/o bitmap; NULL for common */
name|struct
name|amd64tss
modifier|*
name|pcb_tssp
decl_stmt|;
comment|/* model specific registers */
name|register_t
name|pcb_efer
decl_stmt|;
name|register_t
name|pcb_star
decl_stmt|;
name|register_t
name|pcb_lstar
decl_stmt|;
name|register_t
name|pcb_cstar
decl_stmt|;
name|register_t
name|pcb_sfmask
decl_stmt|;
name|struct
name|savefpu
modifier|*
name|pcb_save
decl_stmt|;
name|uint64_t
name|pcb_pad
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Per-CPU state saved during suspend and resume. */
end_comment

begin_struct
struct|struct
name|susppcb
block|{
name|struct
name|pcb
name|sp_pcb
decl_stmt|;
comment|/* fpu context for suspend/resume */
name|void
modifier|*
name|sp_fpususpend
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * The pcb_flags is only modified by current thread, or by other threads  * when current thread is stopped.  However, current thread may change it  * from the interrupt context in cpu_switch(), or in the trap handler.  * When we read-modify-write pcb_flags from C sources, compiler may generate  * code that is not atomic regarding the interrupt handler.  If a trap or  * interrupt happens and any flag is modified from the handler, it can be  * clobbered with the cached value later.  Therefore, we implement setting  * and clearing flags with single-instruction functions, which do not race  * with possible modification of the flags from the trap or interrupt context,  * because traps and interrupts are executed only on instruction boundary.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|set_pcb_flags
parameter_list|(
name|struct
name|pcb
modifier|*
name|pcb
parameter_list|,
specifier|const
name|u_int
name|flags
parameter_list|)
block|{
asm|__asm __volatile("orl %1,%0"
block|:
literal|"=m"
operator|(
name|pcb
operator|->
name|pcb_flags
operator|)
operator|:
literal|"ir"
operator|(
name|flags
operator|)
operator|,
literal|"m"
operator|(
name|pcb
operator|->
name|pcb_flags
operator|)
operator|:
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|clear_pcb_flags
parameter_list|(
name|struct
name|pcb
modifier|*
name|pcb
parameter_list|,
specifier|const
name|u_int
name|flags
parameter_list|)
block|{
asm|__asm __volatile("andl %1,%0"
block|:
literal|"=m"
operator|(
name|pcb
operator|->
name|pcb_flags
operator|)
operator|:
literal|"ir"
operator|(
operator|~
name|flags
operator|)
operator|,
literal|"m"
operator|(
name|pcb
operator|->
name|pcb_flags
operator|)
operator|:
literal|"cc"
block|)
function|;
end_function

begin_expr_stmt
unit|}  void
name|makectx
argument_list|(
expr|struct
name|trapframe
operator|*
argument_list|,
expr|struct
name|pcb
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|savectx
argument_list|(
expr|struct
name|pcb
operator|*
argument_list|)
name|__returns_twice
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|resumectx
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

