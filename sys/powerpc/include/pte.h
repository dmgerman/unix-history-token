begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: pte.h,v 1.2 1998/08/31 14:43:40 tsubai Exp $  * $FreeBSD$  */
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
name|LPTE_AVPN_MASK
value|0xFFFFFFFFFFFFFF80ULL
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
name|LPTE_SWBITS
value|0x0000000000000078ULL
end_define

begin_define
define|#
directive|define
name|LPTE_WIRED
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|LPTE_LOCKED
value|0x0000000000000008ULL
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
value|0x0ffff000UL
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
value|0x00000fffUL
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BOOKE */
end_comment

begin_include
include|#
directive|include
file|<machine/tlb.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_include
include|#
directive|include
file|<machine/tlb.h>
end_include

begin_comment
comment|/*  * The virtual address is:  *  * 4K page size  *   +-----+-----+-----+-------+-------------+-------------+----------------+  *   |  -  |p2d#h|  -  | p2d#l |     dir#    |     pte#    | off in 4K page |  *   +-----+-----+-----+-------+-------------+-------------+----------------+  *    63 62 61 60 59 40 39   30 29    ^    21 20    ^    12 11             0  *                                    |             |  *                                index in 1 page of pointers  *  * 1st level - pointers to page table directory (pp2d)  *  * pp2d consists of PP2D_NENTRIES entries, each being a pointer to  * second level entity, i.e. the page table directory (pdir).  */
end_comment

begin_define
define|#
directive|define
name|HARDWARE_WALKER
end_define

begin_define
define|#
directive|define
name|PP2D_H_H
value|61
end_define

begin_define
define|#
directive|define
name|PP2D_H_L
value|60
end_define

begin_define
define|#
directive|define
name|PP2D_L_H
value|39
end_define

begin_define
define|#
directive|define
name|PP2D_L_L
value|30
end_define

begin_comment
comment|/*>30 would work with no page table pool */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_define
define|#
directive|define
name|PP2D_SIZE
value|(1UL<< PP2D_L_L)
end_define

begin_comment
comment|/* va range mapped by pp2d */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PP2D_SIZE
value|(1<< PP2D_L_L)
end_define

begin_comment
comment|/* va range mapped by pp2d */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PP2D_L_SHIFT
value|PP2D_L_L
end_define

begin_define
define|#
directive|define
name|PP2D_L_NUM
value|(PP2D_L_H-PP2D_L_L+1)
end_define

begin_define
define|#
directive|define
name|PP2D_L_MASK
value|((1<<PP2D_L_NUM)-1)
end_define

begin_define
define|#
directive|define
name|PP2D_H_SHIFT
value|(PP2D_H_L-PP2D_L_NUM)
end_define

begin_define
define|#
directive|define
name|PP2D_H_NUM
value|(PP2D_H_H-PP2D_H_L+1)
end_define

begin_define
define|#
directive|define
name|PP2D_H_MASK
value|(((1<<PP2D_H_NUM)-1)<<PP2D_L_NUM)
end_define

begin_define
define|#
directive|define
name|PP2D_IDX
parameter_list|(
name|va
parameter_list|)
value|(((va>> PP2D_H_SHIFT)& PP2D_H_MASK) | ((va>> PP2D_L_SHIFT)& PP2D_L_MASK))
end_define

begin_define
define|#
directive|define
name|PP2D_NENTRIES
value|(1<<(PP2D_L_NUM+PP2D_H_NUM))
end_define

begin_define
define|#
directive|define
name|PP2D_ENTRY_SHIFT
value|3
end_define

begin_comment
comment|/* log2 (sizeof(struct pte_entry **)) */
end_comment

begin_comment
comment|/*  * 2nd level - page table directory (pdir)  *  * pdir consists of PDIR_NENTRIES entries, each being a pointer to  * second level entity, i.e. the actual page table (ptbl).  */
end_comment

begin_define
define|#
directive|define
name|PDIR_H
value|(PP2D_L_L-1)
end_define

begin_define
define|#
directive|define
name|PDIR_L
value|21
end_define

begin_define
define|#
directive|define
name|PDIR_NUM
value|(PDIR_H-PDIR_L+1)
end_define

begin_define
define|#
directive|define
name|PDIR_SIZE
value|(1<< PDIR_L)
end_define

begin_comment
comment|/* va range mapped by pdir */
end_comment

begin_define
define|#
directive|define
name|PDIR_MASK
value|((1<<PDIR_NUM)-1)
end_define

begin_define
define|#
directive|define
name|PDIR_SHIFT
value|PDIR_L
end_define

begin_define
define|#
directive|define
name|PDIR_NENTRIES
value|(1<<PDIR_NUM)
end_define

begin_define
define|#
directive|define
name|PDIR_IDX
parameter_list|(
name|va
parameter_list|)
value|(((va)>> PDIR_SHIFT)& PDIR_MASK)
end_define

begin_define
define|#
directive|define
name|PDIR_ENTRY_SHIFT
value|3
end_define

begin_comment
comment|/* log2 (sizeof(struct pte_entry *)) */
end_comment

begin_define
define|#
directive|define
name|PDIR_PAGES
value|((PDIR_NENTRIES * (1<<PDIR_ENTRY_SHIFT)) / PAGE_SIZE)
end_define

begin_comment
comment|/*  * 3rd level - page table (ptbl)  *  * Page table covers PTBL_NENTRIES page table entries. Page  * table entry (pte) is 64 bit wide and defines mapping  * for a single page.  */
end_comment

begin_define
define|#
directive|define
name|PTBL_H
value|(PDIR_L-1)
end_define

begin_define
define|#
directive|define
name|PTBL_L
value|PAGE_SHIFT
end_define

begin_define
define|#
directive|define
name|PTBL_NUM
value|(PTBL_H-PTBL_L+1)
end_define

begin_define
define|#
directive|define
name|PTBL_MASK
value|((1<<PTBL_NUM)-1)
end_define

begin_define
define|#
directive|define
name|PTBL_SHIFT
value|PTBL_L
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
name|PTBL_NENTRIES
value|(1<<PTBL_NUM)
end_define

begin_define
define|#
directive|define
name|PTBL_IDX
parameter_list|(
name|va
parameter_list|)
value|((va>> PTBL_SHIFT)& PTBL_MASK)
end_define

begin_define
define|#
directive|define
name|PTBL_ENTRY_SHIFT
value|3
end_define

begin_comment
comment|/* log2 (sizeof (struct pte_entry)) */
end_comment

begin_define
define|#
directive|define
name|PTBL_PAGES
value|((PTBL_NENTRIES * (1<<PTBL_ENTRY_SHIFT)) / PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|KERNEL_LINEAR_MAX
value|0xc000000040000000
end_define

begin_else
else|#
directive|else
end_else

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
value|((PDIR_SIZE - 1)& ~((1<< PAGE_SHIFT) - 1))
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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Page Table Entry definitions and macros.  *  * RPN need only be 32-bit because Book-E has 36-bit addresses, and the smallest  * page size is 4k (12-bit mask), so RPN can really fit into 24 bits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|uint64_t
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BOOKE_E500
argument_list|)
end_if

begin_comment
comment|/* PTE bits assigned to MAS2, MAS3 flags */
end_comment

begin_define
define|#
directive|define
name|PTE_MAS2_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|PTE_W
value|(MAS2_W<< PTE_MAS2_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_I
value|(MAS2_I<< PTE_MAS2_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_M
value|(MAS2_M<< PTE_MAS2_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_G
value|(MAS2_G<< PTE_MAS2_SHIFT)
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
value|2
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

begin_define
define|#
directive|define
name|PTE_PS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PTE_PS_4KB
value|(2<< PTE_PS_SHIFT)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|BOOKE_PPC4XX
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PTE_WL1
value|TLB_WL1
end_define

begin_define
define|#
directive|define
name|PTE_IL2I
value|TLB_IL2I
end_define

begin_define
define|#
directive|define
name|PTE_IL2D
value|TLB_IL2D
end_define

begin_define
define|#
directive|define
name|PTE_W
value|TLB_W
end_define

begin_define
define|#
directive|define
name|PTE_I
value|TLB_I
end_define

begin_define
define|#
directive|define
name|PTE_M
value|TLB_M
end_define

begin_define
define|#
directive|define
name|PTE_G
value|TLB_G
end_define

begin_define
define|#
directive|define
name|PTE_UX
value|TLB_UX
end_define

begin_define
define|#
directive|define
name|PTE_SX
value|TLB_SX
end_define

begin_define
define|#
directive|define
name|PTE_UW
value|TLB_UW
end_define

begin_define
define|#
directive|define
name|PTE_SW
value|TLB_SW
end_define

begin_define
define|#
directive|define
name|PTE_UR
value|TLB_UR
end_define

begin_define
define|#
directive|define
name|PTE_SR
value|TLB_SR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Other PTE flags */
end_comment

begin_define
define|#
directive|define
name|PTE_VALID
value|0x00000001
end_define

begin_comment
comment|/* Valid */
end_comment

begin_define
define|#
directive|define
name|PTE_MODIFIED
value|0x00001000
end_define

begin_comment
comment|/* Modified */
end_comment

begin_define
define|#
directive|define
name|PTE_WIRED
value|0x00002000
end_define

begin_comment
comment|/* Wired */
end_comment

begin_define
define|#
directive|define
name|PTE_MANAGED
value|0x00000002
end_define

begin_comment
comment|/* Managed */
end_comment

begin_define
define|#
directive|define
name|PTE_REFERENCED
value|0x00040000
end_define

begin_comment
comment|/* Referenced */
end_comment

begin_comment
comment|/*  * Page Table Entry definitions and macros.  *  * We use the hardware page table entry format:  *  * 63       24 23 19 18 17 14  13 12 11  8  7  6  5  4  3  2  1  0  * ---------------------------------------------------------------  * ARPN(12:51) WIMGE  R U0:U3 SW0 C  PSIZE UX SX UW SW UR SR SW1 V  * ---------------------------------------------------------------  */
end_comment

begin_comment
comment|/* PTE fields. */
end_comment

begin_define
define|#
directive|define
name|PTE_TSIZE_SHIFT
value|(63-54)
end_define

begin_define
define|#
directive|define
name|PTE_TSIZE_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|PTE_TSIZE_SHIFT_DIRECT
value|(63-55)
end_define

begin_define
define|#
directive|define
name|PTE_TSIZE_MASK_DIRECT
value|0xf
end_define

begin_define
define|#
directive|define
name|PTE_PS_DIRECT
parameter_list|(
name|ps
parameter_list|)
value|(ps<<PTE_TSIZE_SHIFT_DIRECT)
end_define

begin_comment
comment|/* Direct Entry Page Size */
end_comment

begin_define
define|#
directive|define
name|PTE_PS
parameter_list|(
name|ps
parameter_list|)
value|(ps<<PTE_TSIZE_SHIFT)
end_define

begin_comment
comment|/* Page Size */
end_comment

begin_comment
comment|/* Macro argument must of pte_t type. */
end_comment

begin_define
define|#
directive|define
name|PTE_TSIZE
parameter_list|(
name|pte
parameter_list|)
value|(int)((*pte>> PTE_TSIZE_SHIFT)& PTE_TSIZE_MASK)
end_define

begin_define
define|#
directive|define
name|PTE_TSIZE_DIRECT
parameter_list|(
name|pte
parameter_list|)
value|(int)((*pte>> PTE_TSIZE_SHIFT_DIRECT)& PTE_TSIZE_MASK_DIRECT)
end_define

begin_comment
comment|/* Macro argument must of pte_t type. */
end_comment

begin_define
define|#
directive|define
name|PTE_ARPN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PTE_FLAGS_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|PTE_RPN_FROM_PA
parameter_list|(
name|pa
parameter_list|)
value|(((pa)& ~PAGE_MASK)<< PTE_ARPN_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_PA
parameter_list|(
name|pte
parameter_list|)
value|((vm_paddr_t)(*pte>> PTE_ARPN_SHIFT)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|PTE_ISVALID
parameter_list|(
name|pte
parameter_list|)
value|((*pte)& PTE_VALID)
end_define

begin_define
define|#
directive|define
name|PTE_ISWIRED
parameter_list|(
name|pte
parameter_list|)
value|((*pte)& PTE_WIRED)
end_define

begin_define
define|#
directive|define
name|PTE_ISMANAGED
parameter_list|(
name|pte
parameter_list|)
value|((*pte)& PTE_MANAGED)
end_define

begin_define
define|#
directive|define
name|PTE_ISMODIFIED
parameter_list|(
name|pte
parameter_list|)
value|((*pte)& PTE_MODIFIED)
end_define

begin_define
define|#
directive|define
name|PTE_ISREFERENCED
parameter_list|(
name|pte
parameter_list|)
value|((*pte)& PTE_REFERENCED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BOOKE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PTE_H_ */
end_comment

end_unit

