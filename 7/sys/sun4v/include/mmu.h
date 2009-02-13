begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MMU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MMU_H_
end_define

begin_define
define|#
directive|define
name|FAST_IMMU_MISS_TT
value|0x64
end_define

begin_define
define|#
directive|define
name|FAST_DMMU_MISS_TT
value|0x68
end_define

begin_define
define|#
directive|define
name|FAST_PROT_TT
value|0x6c
end_define

begin_comment
comment|/*  * Constants defining alternate spaces  * and register layouts within them,  * and a few other interesting assembly constants.  */
end_comment

begin_comment
comment|/*  * vaddr offsets of various registers  */
end_comment

begin_define
define|#
directive|define
name|MMU_PCONTEXT
value|0x08
end_define

begin_comment
comment|/* primary context number */
end_comment

begin_define
define|#
directive|define
name|MMU_SCONTEXT
value|0x10
end_define

begin_comment
comment|/* secondary context number */
end_comment

begin_comment
comment|/*  * Pseudo Synchronous Fault Status Register Layout  *  * IMMU and DMMU maintain their own pseudo SFSR Register  *  * +------------------------------------------------+  * |       Reserved       |   Context   |     FT    |  * +----------------------|-------------------------+  *  63                  32 31         16 15         0  *  */
end_comment

begin_define
define|#
directive|define
name|SFSR_FT
value|0x0000FFFF
end_define

begin_comment
comment|/* fault type mask */
end_comment

begin_define
define|#
directive|define
name|SFSR_CTX
value|0xFFFF0000
end_define

begin_comment
comment|/* fault context mask */
end_comment

begin_comment
comment|/*  * Definition of FT (Fault Type) bit field of sfsr.  */
end_comment

begin_define
define|#
directive|define
name|FT_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|FT_PRIV
value|MMFSA_F_PRIV
end_define

begin_comment
comment|/* privilege violation */
end_comment

begin_define
define|#
directive|define
name|FT_SPEC_LD
value|MMFSA_F_SOPG
end_define

begin_comment
comment|/* speculative ld to e page */
end_comment

begin_define
define|#
directive|define
name|FT_ATOMIC_NC
value|MMFSA_F_NCATM
end_define

begin_comment
comment|/* atomic to nc page */
end_comment

begin_define
define|#
directive|define
name|FT_ILL_ALT
value|MMFSA_F_INVASI
end_define

begin_comment
comment|/* illegal lda/sta */
end_comment

begin_define
define|#
directive|define
name|FT_NFO
value|MMFSA_F_NFO
end_define

begin_comment
comment|/* normal access to nfo page */
end_comment

begin_define
define|#
directive|define
name|FT_RANGE
value|MMFSA_F_INVVA
end_define

begin_comment
comment|/* dmmu or immu address out of range */
end_comment

begin_define
define|#
directive|define
name|FT_NEW_FMISS
value|MMFSA_F_FMISS
end_define

begin_comment
comment|/* fast miss */
end_comment

begin_define
define|#
directive|define
name|FT_NEW_FPROT
value|MMFSA_F_FPROT
end_define

begin_comment
comment|/* fast protection */
end_comment

begin_define
define|#
directive|define
name|FT_NEW_MISS
value|MMFSA_F_MISS
end_define

begin_comment
comment|/* mmu miss */
end_comment

begin_define
define|#
directive|define
name|FT_NEW_INVRA
value|MMFSA_F_INVRA
end_define

begin_comment
comment|/* invalid RA */
end_comment

begin_define
define|#
directive|define
name|FT_NEW_PROT
value|MMFSA_F_PROT
end_define

begin_comment
comment|/* protection violation */
end_comment

begin_define
define|#
directive|define
name|FT_NEW_PRVACT
value|MMFSA_F_PRVACT
end_define

begin_comment
comment|/* privileged action */
end_comment

begin_define
define|#
directive|define
name|FT_NEW_WPT
value|MMFSA_F_WPT
end_define

begin_comment
comment|/* watchpoint hit */
end_comment

begin_define
define|#
directive|define
name|FT_NEW_UNALIGN
value|MMFSA_F_UNALIGN
end_define

begin_comment
comment|/* unaligned access */
end_comment

begin_define
define|#
directive|define
name|FT_NEW_INVPGSZ
value|MMFSA_F_INVPGSZ
end_define

begin_comment
comment|/* invalid page size */
end_comment

begin_define
define|#
directive|define
name|SFSR_FT_SHIFT
value|0
end_define

begin_comment
comment|/* amt. to shift right to get flt type */
end_comment

begin_define
define|#
directive|define
name|SFSR_CTX_SHIFT
value|16
end_define

begin_comment
comment|/* to shift right to get context */
end_comment

begin_define
define|#
directive|define
name|X_FAULT_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& SFSR_FT)>> SFSR_FT_SHIFT)
end_define

begin_define
define|#
directive|define
name|X_FAULT_CTX
parameter_list|(
name|x
parameter_list|)
value|(((x)& SFSR_CTX)>> SFSR_CTX_SHIFT)
end_define

begin_comment
comment|/*  * MMU TAG TARGET register Layout  *  * +-----+---------+------+-------------------------+  * | 000 | context |  --  | virtual address [63:22] |  * +-----+---------+------+-------------------------+  *  63 61 60	 48 47	42 41			   0  */
end_comment

begin_define
define|#
directive|define
name|TTARGET_CTX_SHIFT
value|48
end_define

begin_define
define|#
directive|define
name|TTARGET_VA_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|TTARGET_VA_BITS
value|42
end_define

begin_define
define|#
directive|define
name|TTARGET_VA_MASK
value|((1UL<< TTARGET_VA_BITS) - 1)
end_define

begin_comment
comment|/*  * MMU PRIMARY/SECONDARY CONTEXT register  */
end_comment

begin_define
define|#
directive|define
name|CTXREG_CTX_MASK
value|0x1FFF
end_define

begin_comment
comment|/*  * The kernel always runs in KCONTEXT, and no user mappings  * are ever valid in it (so any user access pagefaults).  */
end_comment

begin_define
define|#
directive|define
name|KCONTEXT
value|0
end_define

begin_define
define|#
directive|define
name|CTX_OTHER_SHIFT
value|16
end_define

begin_comment
comment|/*  * FLUSH_ADDR is used in the flush instruction to guarantee stores to mmu  * registers complete.  It is selected so it won't miss in the tlb.  */
end_comment

begin_define
define|#
directive|define
name|FLUSH_ADDR
value|(KERNBASE + 2 * PAGE_SIZE_4M)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MMU_H_ */
end_comment

end_unit

