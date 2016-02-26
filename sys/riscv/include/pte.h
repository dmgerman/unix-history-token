begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner  * Copyright (c) 2015 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_typedef
typedef|typedef
name|uint64_t
name|pn_t
typedef|;
end_typedef

begin_comment
comment|/* page number */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Level 0 table, 512GiB per entry */
end_comment

begin_define
define|#
directive|define
name|L0_SHIFT
value|39
end_define

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
name|Ln_ENTRIES
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|Ln_ADDR_MASK
value|(Ln_ENTRIES - 1)
end_define

begin_comment
comment|/* Bits 9:7 are reserved for software */
end_comment

begin_define
define|#
directive|define
name|PTE_SW_MANAGED
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PTE_SW_WIRED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PTE_DIRTY
value|(1<< 6)
end_define

begin_comment
comment|/* Virtual page is written */
end_comment

begin_define
define|#
directive|define
name|PTE_REF
value|(1<< 5)
end_define

begin_comment
comment|/* Virtual page is referenced */
end_comment

begin_define
define|#
directive|define
name|PTE_VALID
value|(1<< 0)
end_define

begin_comment
comment|/* Virtual page is valid */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_S
value|1
end_define

begin_define
define|#
directive|define
name|PTE_TYPE_M
value|(0xf<< PTE_TYPE_S)
end_define

begin_define
define|#
directive|define
name|PTE_TYPE_PTR
value|0
end_define

begin_define
define|#
directive|define
name|PTE_TYPE_PTR_G
value|1
end_define

begin_define
define|#
directive|define
name|PTE_TYPE_SROURX
value|2
end_define

begin_comment
comment|/* Supervisor read-only, user read-execute page. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SRWURWX
value|3
end_define

begin_comment
comment|/* Supervisor read-write, user read-write-execute page. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SURO
value|4
end_define

begin_comment
comment|/* Supervisor and user read-only page. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SURW
value|5
end_define

begin_comment
comment|/* Supervisor and user read-write page. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SURX
value|6
end_define

begin_comment
comment|/* Supervisor and user read-execute page. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SURWX
value|7
end_define

begin_comment
comment|/* Supervisor and User Read Write Execute */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SRO
value|8
end_define

begin_comment
comment|/* Supervisor read-only page. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SRW
value|9
end_define

begin_comment
comment|/* Supervisor read-write page. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SRX
value|10
end_define

begin_comment
comment|/* Supervisor read-execute page. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SRWX
value|11
end_define

begin_comment
comment|/* Supervisor read-write-execute page. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SRO_G
value|12
end_define

begin_comment
comment|/* Supervisor read-only page--global mapping. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SRW_G
value|13
end_define

begin_comment
comment|/* Supervisor read-write page--global mapping. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SRX_G
value|14
end_define

begin_comment
comment|/* Supervisor read-execute page--global mapping. */
end_comment

begin_define
define|#
directive|define
name|PTE_TYPE_SRWX_G
value|15
end_define

begin_comment
comment|/* Supervisor Read Write Execute Global */
end_comment

begin_define
define|#
directive|define
name|PTE_PPN0_S
value|10
end_define

begin_define
define|#
directive|define
name|PTE_PPN1_S
value|19
end_define

begin_define
define|#
directive|define
name|PTE_PPN2_S
value|28
end_define

begin_define
define|#
directive|define
name|PTE_PPN3_S
value|37
end_define

begin_define
define|#
directive|define
name|PTE_SIZE
value|8
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

