begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: pte.h,v 1.4 1998/01/28 13:46:25 pefo Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Utah Hdr: pte.h 1.11 89/09/03  *	from: @(#)pte.h 8.1 (Berkeley) 6/10/93  *	JNPR: pte.h,v 1.1.4.1 2007/09/10 06:20:19 girish  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/*  * MIPS hardware page table entry  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_struct
struct|struct
name|pte
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|unsigned
name|int
name|pg_prot
range|:
literal|2
decl_stmt|,
comment|/* SW: access control */
name|pg_pfnum
range|:
literal|24
decl_stmt|,
comment|/* HW: core page frame number or 0 */
name|pg_attr
range|:
literal|3
decl_stmt|,
comment|/* HW: cache attribute */
name|pg_m
range|:
literal|1
decl_stmt|,
comment|/* HW: modified (dirty) bit */
name|pg_v
range|:
literal|1
decl_stmt|,
comment|/* HW: valid bit */
name|pg_g
range|:
literal|1
decl_stmt|;
comment|/* HW: ignore pid bit */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|unsigned
name|int
name|pg_g
range|:
literal|1
decl_stmt|,
comment|/* HW: ignore pid bit */
name|pg_v
range|:
literal|1
decl_stmt|,
comment|/* HW: valid bit */
name|pg_m
range|:
literal|1
decl_stmt|,
comment|/* HW: modified (dirty) bit */
name|pg_attr
range|:
literal|3
decl_stmt|,
comment|/* HW: cache attribute */
name|pg_pfnum
range|:
literal|24
decl_stmt|,
comment|/* HW: core page frame number or 0 */
name|pg_prot
range|:
literal|2
decl_stmt|;
comment|/* SW: access control */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure defining an tlb entry data set.  */
end_comment

begin_struct
struct|struct
name|tlb
block|{
name|int
name|tlb_mask
decl_stmt|;
name|int
name|tlb_hi
decl_stmt|;
name|int
name|tlb_lo0
decl_stmt|;
name|int
name|tlb_lo1
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|unsigned
name|long
name|pt_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pt_entry_t
modifier|*
name|pd_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PDESIZE
value|sizeof(pd_entry_t)
end_define

begin_comment
comment|/* for assembly files */
end_comment

begin_define
define|#
directive|define
name|PTESIZE
value|sizeof(pt_entry_t)
end_define

begin_comment
comment|/* for assembly files */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCORE */
end_comment

begin_define
define|#
directive|define
name|PT_ENTRY_NULL
value|((pt_entry_t *) 0)
end_define

begin_define
define|#
directive|define
name|PTE_WIRED
value|0x80000000
end_define

begin_comment
comment|/* SW */
end_comment

begin_define
define|#
directive|define
name|PTE_W
value|PTE_WIRED
end_define

begin_define
define|#
directive|define
name|PTE_RO
value|0x40000000
end_define

begin_comment
comment|/* SW */
end_comment

begin_define
define|#
directive|define
name|PTE_G
value|0x00000001
end_define

begin_comment
comment|/* HW */
end_comment

begin_define
define|#
directive|define
name|PTE_V
value|0x00000002
end_define

begin_comment
comment|/*#define	PTE_NV		0x00000000       Not Used */
end_comment

begin_define
define|#
directive|define
name|PTE_M
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PTE_RW
value|PTE_M
end_define

begin_define
define|#
directive|define
name|PTE_ODDPG
value|0x00001000
end_define

begin_comment
comment|/*#define	PG_ATTR		0x0000003f  Not Used */
end_comment

begin_define
define|#
directive|define
name|PTE_UNCACHED
value|0x00000010
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SB1
end_ifdef

begin_define
define|#
directive|define
name|PTE_CACHE
value|0x00000028
end_define

begin_comment
comment|/* cacheable coherent */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTE_CACHE
value|0x00000018
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*#define	PG_CACHEMODE	0x00000038 Not Used*/
end_comment

begin_define
define|#
directive|define
name|PTE_ROPAGE
value|(PTE_V | PTE_RO | PTE_CACHE)
end_define

begin_comment
comment|/* Write protected */
end_comment

begin_define
define|#
directive|define
name|PTE_RWPAGE
value|(PTE_V | PTE_M | PTE_CACHE)
end_define

begin_comment
comment|/* Not wr-prot not clean */
end_comment

begin_define
define|#
directive|define
name|PTE_CWPAGE
value|(PTE_V | PTE_CACHE)
end_define

begin_comment
comment|/* Not wr-prot but clean */
end_comment

begin_define
define|#
directive|define
name|PTE_IOPAGE
value|(PTE_G | PTE_V | PTE_M | PTE_UNCACHED)
end_define

begin_define
define|#
directive|define
name|PTE_FRAME
value|0x3fffffc0
end_define

begin_define
define|#
directive|define
name|PTE_HVPN
value|0xffffe000
end_define

begin_comment
comment|/* Hardware page no mask */
end_comment

begin_define
define|#
directive|define
name|PTE_ASID
value|0x000000ff
end_define

begin_comment
comment|/* Address space ID */
end_comment

begin_define
define|#
directive|define
name|PTE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|pfn_is_ext
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3c000000)
end_define

begin_define
define|#
directive|define
name|vad_to_pfn
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x)>> PTE_SHIFT)& PTE_FRAME)
end_define

begin_define
define|#
directive|define
name|vad_to_pfn64
parameter_list|(
name|x
parameter_list|)
value|((quad_t)(x)>> PTE_SHIFT)& PTE_FRAME)
end_define

begin_define
define|#
directive|define
name|pfn_to_vad
parameter_list|(
name|x
parameter_list|)
value|(((x)& PTE_FRAME)<< PTE_SHIFT)
end_define

begin_comment
comment|/* User virtual to pte offset in page table */
end_comment

begin_define
define|#
directive|define
name|vad_to_pte_offset
parameter_list|(
name|adr
parameter_list|)
value|(((adr)>> PGSHIFT)& (NPTEPG -1))
end_define

begin_define
define|#
directive|define
name|mips_pg_v
parameter_list|(
name|entry
parameter_list|)
value|((entry)& PTE_V)
end_define

begin_define
define|#
directive|define
name|mips_pg_wired
parameter_list|(
name|entry
parameter_list|)
value|((entry)& PTE_WIRED)
end_define

begin_define
define|#
directive|define
name|mips_pg_m_bit
parameter_list|()
value|(PTE_M)
end_define

begin_define
define|#
directive|define
name|mips_pg_rw_bit
parameter_list|()
value|(PTE_M)
end_define

begin_define
define|#
directive|define
name|mips_pg_ro_bit
parameter_list|()
value|(PTE_RO)
end_define

begin_define
define|#
directive|define
name|mips_pg_ropage_bit
parameter_list|()
value|(PTE_ROPAGE)
end_define

begin_define
define|#
directive|define
name|mips_pg_rwpage_bit
parameter_list|()
value|(PTE_RWPAGE)
end_define

begin_define
define|#
directive|define
name|mips_pg_cwpage_bit
parameter_list|()
value|(PTE_CWPAGE)
end_define

begin_define
define|#
directive|define
name|mips_pg_global_bit
parameter_list|()
value|(PTE_G)
end_define

begin_define
define|#
directive|define
name|mips_pg_wired_bit
parameter_list|()
value|(PTE_WIRED)
end_define

begin_define
define|#
directive|define
name|mips_tlbpfn_to_paddr
parameter_list|(
name|x
parameter_list|)
value|pfn_to_vad((x))
end_define

begin_define
define|#
directive|define
name|mips_paddr_to_tlbpfn
parameter_list|(
name|x
parameter_list|)
value|vad_to_pfn((x))
end_define

begin_comment
comment|/* These are not used */
end_comment

begin_define
define|#
directive|define
name|PTE_SIZE_4K
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PTE_SIZE_16K
value|0x00006000
end_define

begin_define
define|#
directive|define
name|PTE_SIZE_64K
value|0x0001e000
end_define

begin_define
define|#
directive|define
name|PTE_SIZE_256K
value|0x0007e000
end_define

begin_define
define|#
directive|define
name|PTE_SIZE_1M
value|0x001fe000
end_define

begin_define
define|#
directive|define
name|PTE_SIZE_4M
value|0x007fe000
end_define

begin_define
define|#
directive|define
name|PTE_SIZE_16M
value|0x01ffe000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PTE_H_ */
end_comment

end_unit

