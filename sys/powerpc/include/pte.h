begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: pte.h,v 1.2 1998/08/31 14:43:40 tsubai Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PTE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PTE_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AIM
argument_list|)
end_if

begin_comment
comment|/*  * Page Table Entries  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/* 32-bit PTE */
end_comment

begin_struct
struct|struct
name|pte
block|{
name|u_int32_t
name|pte_hi
decl_stmt|;
name|u_int32_t
name|pte_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pteg
block|{
name|struct
name|pte
name|pt
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* 64-bit (long) PTE */
end_comment

begin_struct
struct|struct
name|lpte
block|{
name|u_int64_t
name|pte_hi
decl_stmt|;
name|u_int64_t
name|pte_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lpteg
block|{
name|struct
name|lpte
name|pt
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_comment
comment|/* 32-bit PTE definitions */
end_comment

begin_comment
comment|/* High word: */
end_comment

begin_define
define|#
directive|define
name|PTE_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PTE_VSID_SHFT
value|7
end_define

begin_define
define|#
directive|define
name|PTE_HID
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PTE_API
value|0x0000003f
end_define

begin_comment
comment|/* Low word: */
end_comment

begin_define
define|#
directive|define
name|PTE_RPGN
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|PTE_REF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PTE_CHG
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PTE_WIMG
value|0x00000078
end_define

begin_define
define|#
directive|define
name|PTE_W
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PTE_I
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PTE_M
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PTE_G
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PTE_PP
value|0x00000003
end_define

begin_define
define|#
directive|define
name|PTE_SO
value|0x00000000
end_define

begin_comment
comment|/* Super. Only       (U: XX, S: RW) */
end_comment

begin_define
define|#
directive|define
name|PTE_SW
value|0x00000001
end_define

begin_comment
comment|/* Super. Write-Only (U: RO, S: RW) */
end_comment

begin_define
define|#
directive|define
name|PTE_BW
value|0x00000002
end_define

begin_comment
comment|/* Supervisor        (U: RW, S: RW) */
end_comment

begin_define
define|#
directive|define
name|PTE_BR
value|0x00000003
end_define

begin_comment
comment|/* Both Read Only    (U: RO, S: RO) */
end_comment

begin_define
define|#
directive|define
name|PTE_RW
value|PTE_BW
end_define

begin_define
define|#
directive|define
name|PTE_RO
value|PTE_BR
end_define

begin_define
define|#
directive|define
name|PTE_EXEC
value|0x00000200
end_define

begin_comment
comment|/* pseudo bit in attrs; page is exec */
end_comment

begin_comment
comment|/* 64-bit PTE definitions */
end_comment

begin_comment
comment|/* High quadword: */
end_comment

begin_define
define|#
directive|define
name|LPTE_VSID_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|LPTE_API
value|0x0000000000000F80ULL
end_define

begin_define
define|#
directive|define
name|LPTE_BIG
value|0x0000000000000004ULL
end_define

begin_comment
comment|/* 4kb/16Mb page */
end_comment

begin_define
define|#
directive|define
name|LPTE_HID
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|LPTE_VALID
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* Low quadword: */
end_comment

begin_define
define|#
directive|define
name|EXTEND_PTE
parameter_list|(
name|x
parameter_list|)
value|UINT64_C(x)
end_define

begin_comment
comment|/* make constants 64-bit */
end_comment

begin_define
define|#
directive|define
name|LPTE_RPGN
value|0xfffffffffffff000ULL
end_define

begin_define
define|#
directive|define
name|LPTE_REF
value|EXTEND_PTE( PTE_REF )
end_define

begin_define
define|#
directive|define
name|LPTE_CHG
value|EXTEND_PTE( PTE_CHG )
end_define

begin_define
define|#
directive|define
name|LPTE_WIMG
value|EXTEND_PTE( PTE_WIMG )
end_define

begin_define
define|#
directive|define
name|LPTE_W
value|EXTEND_PTE( PTE_W )
end_define

begin_define
define|#
directive|define
name|LPTE_I
value|EXTEND_PTE( PTE_I )
end_define

begin_define
define|#
directive|define
name|LPTE_M
value|EXTEND_PTE( PTE_M )
end_define

begin_define
define|#
directive|define
name|LPTE_G
value|EXTEND_PTE( PTE_G )
end_define

begin_define
define|#
directive|define
name|LPTE_NOEXEC
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|LPTE_PP
value|EXTEND_PTE( PTE_PP )
end_define

begin_define
define|#
directive|define
name|LPTE_SO
value|EXTEND_PTE( PTE_SO )
end_define

begin_comment
comment|/* Super. Only */
end_comment

begin_define
define|#
directive|define
name|LPTE_SW
value|EXTEND_PTE( PTE_SW )
end_define

begin_comment
comment|/* Super. Write-Only */
end_comment

begin_define
define|#
directive|define
name|LPTE_BW
value|EXTEND_PTE( PTE_BW )
end_define

begin_comment
comment|/* Supervisor */
end_comment

begin_define
define|#
directive|define
name|LPTE_BR
value|EXTEND_PTE( PTE_BR )
end_define

begin_comment
comment|/* Both Read Only */
end_comment

begin_define
define|#
directive|define
name|LPTE_RW
value|LPTE_BW
end_define

begin_define
define|#
directive|define
name|LPTE_RO
value|LPTE_BR
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|pte
name|pte_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lpte
name|lpte_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_comment
comment|/*  * Extract bits from address  */
end_comment

begin_define
define|#
directive|define
name|ADDR_SR_SHFT
value|28
end_define

begin_define
define|#
directive|define
name|ADDR_PIDX
value|0x0ffff000
end_define

begin_define
define|#
directive|define
name|ADDR_PIDX_SHFT
value|12
end_define

begin_define
define|#
directive|define
name|ADDR_API_SHFT
value|22
end_define

begin_define
define|#
directive|define
name|ADDR_API_SHFT64
value|16
end_define

begin_define
define|#
directive|define
name|ADDR_POFF
value|0x00000fff
end_define

begin_comment
comment|/*  * Bits in DSISR:  */
end_comment

begin_define
define|#
directive|define
name|DSISR_DIRECT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DSISR_NOTFOUND
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DSISR_PROTECT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DSISR_INVRX
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DSISR_STORE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DSISR_DABR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DSISR_SEGMENT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DSISR_EAR
value|0x00100000
end_define

begin_comment
comment|/*  * Bits in SRR1 on ISI:  */
end_comment

begin_define
define|#
directive|define
name|ISSRR1_NOTFOUND
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ISSRR1_DIRECT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ISSRR1_PROTECT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ISSRR1_SEGMENT
value|0x00200000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_function_decl
specifier|extern
name|u_int
name|dsisr
parameter_list|(
name|void
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
comment|/* LOCORE */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/tlb.h>
end_include

begin_comment
comment|/*  * 1st level - page table directory (pdir)  *  * pdir consists of 1024 entries, each being a pointer to  * second level entity, i.e. the actual page table (ptbl).  */
end_comment

begin_define
define|#
directive|define
name|PDIR_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|PDIR_SIZE
value|(1<< PDIR_SHIFT)
end_define

begin_comment
comment|/* va range mapped by pdir */
end_comment

begin_define
define|#
directive|define
name|PDIR_MASK
value|(~(PDIR_SIZE - 1))
end_define

begin_define
define|#
directive|define
name|PDIR_NENTRIES
value|1024
end_define

begin_comment
comment|/* number of page tables in pdir */
end_comment

begin_comment
comment|/* Returns pdir entry number for given va */
end_comment

begin_define
define|#
directive|define
name|PDIR_IDX
parameter_list|(
name|va
parameter_list|)
value|((va)>> PDIR_SHIFT)
end_define

begin_define
define|#
directive|define
name|PDIR_ENTRY_SHIFT
value|2
end_define

begin_comment
comment|/* entry size is 2^2 = 4 bytes */
end_comment

begin_comment
comment|/*  * 2nd level - page table (ptbl)  *  * Page table covers 1024 page table entries. Page  * table entry (pte) is 32 bit wide and defines mapping  * for a single page.  */
end_comment

begin_define
define|#
directive|define
name|PTBL_SHIFT
value|PAGE_SHIFT
end_define

begin_define
define|#
directive|define
name|PTBL_SIZE
value|PAGE_SIZE
end_define

begin_comment
comment|/* va range mapped by ptbl entry */
end_comment

begin_define
define|#
directive|define
name|PTBL_MASK
value|((PDIR_SIZE - 1)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|PTBL_NENTRIES
value|1024
end_define

begin_comment
comment|/* number of pages mapped by ptbl */
end_comment

begin_comment
comment|/* Returns ptbl entry number for given va */
end_comment

begin_define
define|#
directive|define
name|PTBL_IDX
parameter_list|(
name|va
parameter_list|)
value|(((va)& PTBL_MASK)>> PTBL_SHIFT)
end_define

begin_comment
comment|/* Size of ptbl in pages, 1024 entries, each sizeof(struct pte_entry). */
end_comment

begin_define
define|#
directive|define
name|PTBL_PAGES
value|2
end_define

begin_define
define|#
directive|define
name|PTBL_ENTRY_SHIFT
value|3
end_define

begin_comment
comment|/* entry size is 2^3 = 8 bytes */
end_comment

begin_comment
comment|/*  * Flags for pte_remove() routine.  */
end_comment

begin_define
define|#
directive|define
name|PTBL_HOLD
value|0x00000001
end_define

begin_comment
comment|/* do not unhold ptbl pages */
end_comment

begin_define
define|#
directive|define
name|PTBL_UNHOLD
value|0x00000002
end_define

begin_comment
comment|/* unhold and attempt to free ptbl pages */
end_comment

begin_define
define|#
directive|define
name|PTBL_HOLD_FLAG
parameter_list|(
name|pmap
parameter_list|)
value|(((pmap) == kernel_pmap) ? PTBL_HOLD : PTBL_UNHOLD)
end_define

begin_comment
comment|/*  * Page Table Entry definitions and macros.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|pte
block|{
name|vm_offset_t
name|rpn
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pte
name|pte_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RPN mask, TLB0 4K pages */
end_comment

begin_define
define|#
directive|define
name|PTE_PA_MASK
value|PAGE_MASK
end_define

begin_comment
comment|/* PTE bits assigned to MAS2, MAS3 flags */
end_comment

begin_define
define|#
directive|define
name|PTE_W
value|MAS2_W
end_define

begin_define
define|#
directive|define
name|PTE_I
value|MAS2_I
end_define

begin_define
define|#
directive|define
name|PTE_M
value|MAS2_M
end_define

begin_define
define|#
directive|define
name|PTE_G
value|MAS2_G
end_define

begin_define
define|#
directive|define
name|PTE_MAS2_MASK
value|(MAS2_G | MAS2_M | MAS2_I | MAS2_W)
end_define

begin_define
define|#
directive|define
name|PTE_MAS3_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PTE_UX
value|(MAS3_UX<< PTE_MAS3_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_SX
value|(MAS3_SX<< PTE_MAS3_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_UW
value|(MAS3_UW<< PTE_MAS3_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_SW
value|(MAS3_SW<< PTE_MAS3_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_UR
value|(MAS3_UR<< PTE_MAS3_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_SR
value|(MAS3_SR<< PTE_MAS3_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_MAS3_MASK
value|((MAS3_UX | MAS3_SX | MAS3_UW	\ 			| MAS3_SW | MAS3_UR | MAS3_SR)<< PTE_MAS3_SHIFT)
end_define

begin_comment
comment|/* Other PTE flags */
end_comment

begin_define
define|#
directive|define
name|PTE_VALID
value|0x80000000
end_define

begin_comment
comment|/* Valid */
end_comment

begin_define
define|#
directive|define
name|PTE_MODIFIED
value|0x40000000
end_define

begin_comment
comment|/* Modified */
end_comment

begin_define
define|#
directive|define
name|PTE_WIRED
value|0x20000000
end_define

begin_comment
comment|/* Wired */
end_comment

begin_define
define|#
directive|define
name|PTE_MANAGED
value|0x10000000
end_define

begin_comment
comment|/* Managed */
end_comment

begin_define
define|#
directive|define
name|PTE_FAKE
value|0x08000000
end_define

begin_comment
comment|/* Ficticious */
end_comment

begin_define
define|#
directive|define
name|PTE_REFERENCED
value|0x04000000
end_define

begin_comment
comment|/* Referenced */
end_comment

begin_comment
comment|/* Macro argument must of pte_t type. */
end_comment

begin_define
define|#
directive|define
name|PTE_PA
parameter_list|(
name|pte
parameter_list|)
value|((pte)->rpn& ~PTE_PA_MASK)
end_define

begin_define
define|#
directive|define
name|PTE_ISVALID
parameter_list|(
name|pte
parameter_list|)
value|((pte)->flags& PTE_VALID)
end_define

begin_define
define|#
directive|define
name|PTE_ISWIRED
parameter_list|(
name|pte
parameter_list|)
value|((pte)->flags& PTE_WIRED)
end_define

begin_define
define|#
directive|define
name|PTE_ISMANAGED
parameter_list|(
name|pte
parameter_list|)
value|((pte)->flags& PTE_MANAGED)
end_define

begin_define
define|#
directive|define
name|PTE_ISFAKE
parameter_list|(
name|pte
parameter_list|)
value|((pte)->flags& PTE_FAKE)
end_define

begin_define
define|#
directive|define
name|PTE_ISMODIFIED
parameter_list|(
name|pte
parameter_list|)
value|((pte)->flags& PTE_MODIFIED)
end_define

begin_define
define|#
directive|define
name|PTE_ISREFERENCED
parameter_list|(
name|pte
parameter_list|)
value|((pte)->flags& PTE_REFERENCED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #elif defined(E500) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PTE_H_ */
end_comment

end_unit

