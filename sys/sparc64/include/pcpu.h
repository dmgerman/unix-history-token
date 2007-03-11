begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/include/globaldata.h,v 1.27 2001/04/27  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCPU_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/asmacros.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_define
define|#
directive|define
name|ALT_STACK_SIZE
value|128
end_define

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Inside the kernel, the globally reserved register g7 is used to  * point at the globaldata structure.  */
end_comment

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|struct	intr_request pc_irpool[IR_FREE];			\ 	struct	intr_request *pc_irhead;				\ 	struct	intr_request **pc_irtail;				\ 	struct	intr_request *pc_irfree;				\ 	struct 	pmap *pc_pmap;						\ 	vm_offset_t pc_addr;						\ 	u_long	pc_tickref;						\ 	u_long	pc_tickadj;						\ 	u_int 	pc_mid;							\ 	u_int	pc_node;						\ 	u_int	pc_tlb_ctx;						\ 	u_int	pc_tlb_ctx_max;						\ 	u_int	pc_tlb_ctx_min
end_define

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pcpu
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|register
name|struct
name|pcb
modifier|*
name|curpcb
name|__asm__
argument_list|(
name|__XSTRING
argument_list|(
name|PCB_REG
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|pcpu
modifier|*
name|pcpup
name|__asm__
argument_list|(
name|__XSTRING
argument_list|(
name|PCPU_REG
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|member
parameter_list|)
value|(pcpup->pc_ ## member)
end_define

begin_comment
comment|/*  * XXX The implementation of this operation should be made atomic  * with respect to preemption.  */
end_comment

begin_define
define|#
directive|define
name|PCPU_LAZY_INC
parameter_list|(
name|member
parameter_list|)
value|(++pcpup->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_PTR
parameter_list|(
name|member
parameter_list|)
value|(&pcpup->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|member
parameter_list|,
name|value
parameter_list|)
value|(pcpup->pc_ ## member = (value))
end_define

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
comment|/* !_MACHINE_PCPU_H_ */
end_comment

end_unit

