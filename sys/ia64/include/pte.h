begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|PTE_PRESENT
value|0x0000000000000001
end_define

begin_define
define|#
directive|define
name|PTE__RV1_
value|0x0000000000000002
end_define

begin_define
define|#
directive|define
name|PTE_MA_MASK
value|0x000000000000001C
end_define

begin_define
define|#
directive|define
name|PTE_MA_WB
value|0x0000000000000000
end_define

begin_define
define|#
directive|define
name|PTE_MA_UC
value|0x0000000000000010
end_define

begin_define
define|#
directive|define
name|PTE_MA_UCE
value|0x0000000000000014
end_define

begin_define
define|#
directive|define
name|PTE_MA_WC
value|0x0000000000000018
end_define

begin_define
define|#
directive|define
name|PTE_MA_NATPAGE
value|0x000000000000001C
end_define

begin_define
define|#
directive|define
name|PTE_ACCESSED
value|0x0000000000000020
end_define

begin_define
define|#
directive|define
name|PTE_DIRTY
value|0x0000000000000040
end_define

begin_define
define|#
directive|define
name|PTE_PL_MASK
value|0x0000000000000180
end_define

begin_define
define|#
directive|define
name|PTE_PL_KERN
value|0x0000000000000000
end_define

begin_define
define|#
directive|define
name|PTE_PL_USER
value|0x0000000000000180
end_define

begin_define
define|#
directive|define
name|PTE_AR_MASK
value|0x0000000000000E00
end_define

begin_define
define|#
directive|define
name|PTE_AR_R
value|0x0000000000000000
end_define

begin_define
define|#
directive|define
name|PTE_AR_RX
value|0x0000000000000200
end_define

begin_define
define|#
directive|define
name|PTE_AR_RW
value|0x0000000000000400
end_define

begin_define
define|#
directive|define
name|PTE_AR_RWX
value|0x0000000000000600
end_define

begin_define
define|#
directive|define
name|PTE_AR_R_RW
value|0x0000000000000800
end_define

begin_define
define|#
directive|define
name|PTE_AR_RX_RWX
value|0x0000000000000A00
end_define

begin_define
define|#
directive|define
name|PTE_AR_RWX_RW
value|0x0000000000000C00
end_define

begin_define
define|#
directive|define
name|PTE_AR_X_RX
value|0x0000000000000E00
end_define

begin_define
define|#
directive|define
name|PTE_PPN_MASK
value|0x0003FFFFFFFFF000
end_define

begin_define
define|#
directive|define
name|PTE__RV2_
value|0x000C000000000000
end_define

begin_define
define|#
directive|define
name|PTE_ED
value|0x0010000000000000
end_define

begin_define
define|#
directive|define
name|PTE_IG_MASK
value|0xFFE0000000000000
end_define

begin_define
define|#
directive|define
name|PTE_WIRED
value|0x0020000000000000
end_define

begin_define
define|#
directive|define
name|PTE_MANAGED
value|0x0040000000000000
end_define

begin_define
define|#
directive|define
name|PTE_PROT_MASK
value|0x0700000000000000
end_define

begin_define
define|#
directive|define
name|ITIR__RV1_
value|0x0000000000000003
end_define

begin_define
define|#
directive|define
name|ITIR_PS_MASK
value|0x00000000000000FC
end_define

begin_define
define|#
directive|define
name|ITIR_KEY_MASK
value|0x00000000FFFFFF00
end_define

begin_define
define|#
directive|define
name|ITIR__RV2_
value|0xFFFFFFFF00000000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|uint64_t
name|pt_entry_t
typedef|;
end_typedef

begin_function
specifier|static
name|__inline
name|pt_entry_t
name|pte_atomic_clear
parameter_list|(
name|pt_entry_t
modifier|*
name|ptep
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
return|return
operator|(
name|atomic_clear_64
argument_list|(
name|ptep
argument_list|,
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|pt_entry_t
name|pte_atomic_set
parameter_list|(
name|pt_entry_t
modifier|*
name|ptep
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
return|return
operator|(
name|atomic_set_64
argument_list|(
name|ptep
argument_list|,
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * A long-format VHPT entry.  */
end_comment

begin_struct
struct|struct
name|ia64_lpte
block|{
name|pt_entry_t
name|pte
decl_stmt|;
name|uint64_t
name|itir
decl_stmt|;
name|uint64_t
name|tag
decl_stmt|;
comment|/* includes ti */
name|uint64_t
name|chain
decl_stmt|;
comment|/* pa of collision chain */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Layout of rr[x].  */
end_comment

begin_struct
struct|struct
name|ia64_rr
block|{
name|uint64_t
name|rr_ve
range|:
literal|1
decl_stmt|;
comment|/* bit 0 */
name|uint64_t
name|__rv1__
range|:
literal|1
decl_stmt|;
comment|/* bit 1 */
name|uint64_t
name|rr_ps
range|:
literal|6
decl_stmt|;
comment|/* bits 2..7 */
name|uint64_t
name|rr_rid
range|:
literal|24
decl_stmt|;
comment|/* bits 8..31 */
name|uint64_t
name|__rv2__
range|:
literal|32
decl_stmt|;
comment|/* bits 32..63 */
block|}
struct|;
end_struct

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
comment|/* !_MACHINE_PTE_H_ */
end_comment

end_unit

