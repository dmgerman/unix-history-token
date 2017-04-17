begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * Copyright (c) Peter Wemm<peter@netplex.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/slb.h>
end_include

begin_include
include|#
directive|include
file|<machine/tlb.h>
end_include

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pvo_entry
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|CPUSAVE_LEN
value|9
end_define

begin_define
define|#
directive|define
name|PCPU_MD_COMMON_FIELDS
define|\
value|int		pc_inside_intr;					\ 	struct pmap	*pc_curpmap;
comment|/* current pmap */
value|\ 	struct thread	*pc_fputhread;
comment|/* current fpu user */
value|\ 	struct thread	*pc_vecthread;
comment|/* current vec user */
value|\ 	uintptr_t	pc_hwref;					\ 	uint32_t	pc_pir;						\ 	int		pc_bsp;						\ 	volatile int	pc_awake;					\ 	uint32_t	pc_ipimask;					\ 	register_t	pc_tempsave[CPUSAVE_LEN];			\ 	register_t	pc_disisave[CPUSAVE_LEN];			\ 	register_t	pc_dbsave[CPUSAVE_LEN];				\ 	void		*pc_restore;
end_define

begin_define
define|#
directive|define
name|PCPU_MD_AIM32_FIELDS
define|\
value|vm_offset_t	pc_qmap_addr;					\ 	struct pvo_entry *pc_qmap_pvo;					\ 	struct mtx	pc_qmap_lock;					\ 	char		__pad[128]
end_define

begin_define
define|#
directive|define
name|PCPU_MD_AIM64_FIELDS
define|\
value|struct slb	pc_slb[64];					\ 	struct slb	**pc_userslb;					\ 	register_t	pc_slbsave[18];					\ 	uint8_t		pc_slbstack[1024];				\ 	vm_offset_t	pc_qmap_addr;					\ 	struct pvo_entry *pc_qmap_pvo;					\ 	struct mtx	pc_qmap_lock;					\ 	char		__pad[1345]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|PCPU_MD_AIM_FIELDS
value|PCPU_MD_AIM64_FIELDS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCPU_MD_AIM_FIELDS
value|PCPU_MD_AIM32_FIELDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BOOKE_CRITSAVE_LEN
value|(CPUSAVE_LEN + 2)
end_define

begin_define
define|#
directive|define
name|BOOKE_TLB_MAXNEST
value|3
end_define

begin_define
define|#
directive|define
name|BOOKE_TLB_SAVELEN
value|16
end_define

begin_define
define|#
directive|define
name|BOOKE_TLBSAVE_LEN
value|(BOOKE_TLB_SAVELEN * BOOKE_TLB_MAXNEST)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|BOOKE_PCPU_PAD
value|901
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BOOKE_PCPU_PAD
value|429
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCPU_MD_BOOKE_FIELDS
define|\
value|register_t	pc_booke_critsave[BOOKE_CRITSAVE_LEN];		\ 	register_t	pc_booke_mchksave[CPUSAVE_LEN];			\ 	register_t	pc_booke_tlbsave[BOOKE_TLBSAVE_LEN];		\ 	register_t	pc_booke_tlb_level;				\ 	vm_offset_t	pc_qmap_addr;					\ 	uintptr_t	*pc_booke_tlb_lock;				\ 	int		pc_tid_next;					\ 	char		__pad[BOOKE_PCPU_PAD]
end_define

begin_comment
comment|/* Definitions for register offsets within the exception tmp save areas */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_R27
value|0
end_define

begin_comment
comment|/* where r27 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_R28
value|1
end_define

begin_comment
comment|/* where r28 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_R29
value|2
end_define

begin_comment
comment|/* where r29 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_R30
value|3
end_define

begin_comment
comment|/* where r30 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_R31
value|4
end_define

begin_comment
comment|/* where r31 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_AIM_DAR
value|5
end_define

begin_comment
comment|/* where SPR_DAR gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_AIM_DSISR
value|6
end_define

begin_comment
comment|/* where SPR_DSISR gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_BOOKE_DEAR
value|5
end_define

begin_comment
comment|/* where SPR_DEAR gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_BOOKE_ESR
value|6
end_define

begin_comment
comment|/* where SPR_ESR gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_SRR0
value|7
end_define

begin_comment
comment|/* where SRR0 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_SRR1
value|8
end_define

begin_comment
comment|/* where SRR1 gets saved */
end_comment

begin_define
define|#
directive|define
name|BOOKE_CRITSAVE_SRR0
value|9
end_define

begin_comment
comment|/* where real SRR0 gets saved (critical) */
end_comment

begin_define
define|#
directive|define
name|BOOKE_CRITSAVE_SRR1
value|10
end_define

begin_comment
comment|/* where real SRR0 gets saved (critical) */
end_comment

begin_comment
comment|/* Book-E TLBSAVE is more elaborate */
end_comment

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_LR
value|0
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_CR
value|1
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_SRR0
value|2
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_SRR1
value|3
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R20
value|4
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R21
value|5
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R22
value|6
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R23
value|7
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R24
value|8
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R25
value|9
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R26
value|10
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R27
value|11
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R28
value|12
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R29
value|13
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R30
value|14
end_define

begin_define
define|#
directive|define
name|TLBSAVE_BOOKE_R31
value|15
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AIM
end_ifdef

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|PCPU_MD_COMMON_FIELDS	\ 	PCPU_MD_AIM_FIELDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BOOKE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|PCPU_MD_COMMON_FIELDS	\ 	PCPU_MD_BOOKE_FIELDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Catch-all for ports (e.g. lsof, used by gtop)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCPU_MD_FIELDS
end_ifndef

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|int		pc_md_placeholder[32]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|pcpup
value|(get_pcpu())
end_define

begin_expr_stmt
specifier|static
name|__inline
name|__pure2
expr|struct
name|thread
operator|*
name|__curthread
argument_list|(
argument|void
argument_list|)
block|{ 	struct
name|thread
operator|*
name|td
block|;
ifdef|#
directive|ifdef
name|__powerpc64__
asm|__asm __volatile("mr %0,13" : "=r"(td));
else|#
directive|else
asm|__asm __volatile("mr %0,2" : "=r"(td));
endif|#
directive|endif
return|return
operator|(
name|td
operator|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|curthread
value|(__curthread())
end_define

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
name|PCPU_ADD
parameter_list|(
name|member
parameter_list|,
name|value
parameter_list|)
value|(pcpup->pc_ ## member += (value))
end_define

begin_define
define|#
directive|define
name|PCPU_INC
parameter_list|(
name|member
parameter_list|)
value|PCPU_ADD(member, 1)
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

