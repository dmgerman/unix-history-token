begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner  * Copyright (c) 2014-2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|uint64_t
name|pd_entry_t
typedef|;
end_typedef

begin_comment
comment|/* page directory entry */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|pt_entry_t
typedef|;
end_typedef

begin_comment
comment|/* page table entry */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Block and Page attributes */
end_comment

begin_comment
comment|/* TODO: Add the upper attributes */
end_comment

begin_define
define|#
directive|define
name|ATTR_MASK_H
value|UINT64_C(0xfff0000000000000)
end_define

begin_define
define|#
directive|define
name|ATTR_MASK_L
value|UINT64_C(0x0000000000000fff)
end_define

begin_define
define|#
directive|define
name|ATTR_MASK
value|(ATTR_MASK_H | ATTR_MASK_L)
end_define

begin_comment
comment|/* Bits 58:55 are reserved for software */
end_comment

begin_define
define|#
directive|define
name|ATTR_SW_MANAGED
value|(1UL<< 56)
end_define

begin_define
define|#
directive|define
name|ATTR_SW_WIRED
value|(1UL<< 55)
end_define

begin_define
define|#
directive|define
name|ATTR_UXN
value|(1UL<< 54)
end_define

begin_define
define|#
directive|define
name|ATTR_PXN
value|(1UL<< 53)
end_define

begin_define
define|#
directive|define
name|ATTR_XN
value|(ATTR_PXN | ATTR_UXN)
end_define

begin_define
define|#
directive|define
name|ATTR_CONTIGUOUS
value|(1UL<< 52)
end_define

begin_define
define|#
directive|define
name|ATTR_DBM
value|(1UL<< 51)
end_define

begin_define
define|#
directive|define
name|ATTR_nG
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|ATTR_AF
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|ATTR_SH
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|ATTR_SH_MASK
value|ATTR_SH(3)
end_define

begin_define
define|#
directive|define
name|ATTR_SH_NS
value|0
end_define

begin_comment
comment|/* Non-shareable */
end_comment

begin_define
define|#
directive|define
name|ATTR_SH_OS
value|2
end_define

begin_comment
comment|/* Outer-shareable */
end_comment

begin_define
define|#
directive|define
name|ATTR_SH_IS
value|3
end_define

begin_comment
comment|/* Inner-shareable */
end_comment

begin_define
define|#
directive|define
name|ATTR_AP_RW_BIT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATTR_AP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|ATTR_AP_MASK
value|ATTR_AP(3)
end_define

begin_define
define|#
directive|define
name|ATTR_AP_RW
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|ATTR_AP_RO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATTR_AP_USER
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATTR_NS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATTR_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 2)
end_define

begin_define
define|#
directive|define
name|ATTR_IDX_MASK
value|(7<< 2)
end_define

begin_define
define|#
directive|define
name|ATTR_DEFAULT
value|(ATTR_AF | ATTR_SH(ATTR_SH_IS))
end_define

begin_define
define|#
directive|define
name|ATTR_DESCR_MASK
value|3
end_define

begin_comment
comment|/* Level 0 table, 512GiB per entry */
end_comment

begin_define
define|#
directive|define
name|L0_SHIFT
value|39
end_define

begin_define
define|#
directive|define
name|L0_SIZE
value|(1ul<< L0_SHIFT)
end_define

begin_define
define|#
directive|define
name|L0_OFFSET
value|(L0_SIZE - 1ul)
end_define

begin_define
define|#
directive|define
name|L0_INVAL
value|0x0
end_define

begin_comment
comment|/* An invalid address */
end_comment

begin_comment
comment|/* 0x1 Level 0 doesn't support block translation */
end_comment

begin_comment
comment|/* 0x2 also marks an invalid address */
end_comment

begin_define
define|#
directive|define
name|L0_TABLE
value|0x3
end_define

begin_comment
comment|/* A next-level table */
end_comment

begin_comment
comment|/* Level 1 table, 1GiB per entry */
end_comment

begin_define
define|#
directive|define
name|L1_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|L1_SIZE
value|(1<< L1_SHIFT)
end_define

begin_define
define|#
directive|define
name|L1_OFFSET
value|(L1_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|L1_INVAL
value|L0_INVAL
end_define

begin_define
define|#
directive|define
name|L1_BLOCK
value|0x1
end_define

begin_define
define|#
directive|define
name|L1_TABLE
value|L0_TABLE
end_define

begin_comment
comment|/* Level 2 table, 2MiB per entry */
end_comment

begin_define
define|#
directive|define
name|L2_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|L2_SIZE
value|(1<< L2_SHIFT)
end_define

begin_define
define|#
directive|define
name|L2_OFFSET
value|(L2_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|L2_INVAL
value|L1_INVAL
end_define

begin_define
define|#
directive|define
name|L2_BLOCK
value|L1_BLOCK
end_define

begin_define
define|#
directive|define
name|L2_TABLE
value|L1_TABLE
end_define

begin_define
define|#
directive|define
name|L2_BLOCK_MASK
value|UINT64_C(0xffffffe00000)
end_define

begin_comment
comment|/* Level 3 table, 4KiB per entry */
end_comment

begin_define
define|#
directive|define
name|L3_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|L3_SIZE
value|(1<< L3_SHIFT)
end_define

begin_define
define|#
directive|define
name|L3_OFFSET
value|(L3_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|L3_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|L3_INVAL
value|0x0
end_define

begin_comment
comment|/* 0x1 is reserved */
end_comment

begin_comment
comment|/* 0x2 also marks an invalid address */
end_comment

begin_define
define|#
directive|define
name|L3_PAGE
value|0x3
end_define

begin_define
define|#
directive|define
name|L0_ENTRIES_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|L0_ENTRIES
value|(1<< L0_ENTRIES_SHIFT)
end_define

begin_define
define|#
directive|define
name|L0_ADDR_MASK
value|(L0_ENTRIES - 1)
end_define

begin_define
define|#
directive|define
name|Ln_ENTRIES_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|Ln_ENTRIES
value|(1<< Ln_ENTRIES_SHIFT)
end_define

begin_define
define|#
directive|define
name|Ln_ADDR_MASK
value|(Ln_ENTRIES - 1)
end_define

begin_define
define|#
directive|define
name|Ln_TABLE_MASK
value|((1<< 12) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PTE_H_ */
end_comment

begin_comment
comment|/* End of pte.h */
end_comment

end_unit

