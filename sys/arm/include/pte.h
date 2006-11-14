begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pte.h,v 1.1 2001/11/23 17:39:04 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994 Mark Brinicombe.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the RiscBSD team.  * 4. The name "RiscBSD" nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY RISCBSD ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL RISCBSD OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|PDSHIFT
value|20
end_define

begin_comment
comment|/* LOG2(NBPDR) */
end_comment

begin_define
define|#
directive|define
name|NBPD
value|(1<< PDSHIFT)
end_define

begin_comment
comment|/* bytes/page dir */
end_comment

begin_define
define|#
directive|define
name|NPTEPD
value|(NBPD / PAGE_SIZE)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|uint32_t
name|pd_entry_t
typedef|;
end_typedef

begin_comment
comment|/* page directory entry */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
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

begin_define
define|#
directive|define
name|PD_MASK
value|0xfff00000
end_define

begin_comment
comment|/* page directory address bits */
end_comment

begin_define
define|#
directive|define
name|PT_MASK
value|0x000ff000
end_define

begin_comment
comment|/* page table address bits */
end_comment

begin_define
define|#
directive|define
name|PG_FRAME
value|0xfffff000
end_define

begin_comment
comment|/* The PT_SIZE definition is misleading... A page table is only 0x400  * bytes long. But since VM mapping can only be done to 0x1000 a single  * 1KB blocks cannot be steered to a va by itself. Therefore the  * pages tables are allocated in blocks of 4. i.e. if a 1 KB block  * was allocated for a PT then the other 3KB would also get mapped  * whenever the 1KB was mapped.  */
end_comment

begin_define
define|#
directive|define
name|PT_RSIZE
value|0x0400
end_define

begin_comment
comment|/* Real page table size */
end_comment

begin_define
define|#
directive|define
name|PT_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|PD_SIZE
value|0x4000
end_define

begin_comment
comment|/* Page table types and masks */
end_comment

begin_define
define|#
directive|define
name|L1_PAGE
value|0x01
end_define

begin_comment
comment|/* L1 page table mapping */
end_comment

begin_define
define|#
directive|define
name|L1_SECTION
value|0x02
end_define

begin_comment
comment|/* L1 section mapping */
end_comment

begin_define
define|#
directive|define
name|L1_FPAGE
value|0x03
end_define

begin_comment
comment|/* L1 fine page mapping */
end_comment

begin_define
define|#
directive|define
name|L1_MASK
value|0x03
end_define

begin_comment
comment|/* Mask for L1 entry type */
end_comment

begin_define
define|#
directive|define
name|L2_LPAGE
value|0x01
end_define

begin_comment
comment|/* L2 large page (64KB) */
end_comment

begin_define
define|#
directive|define
name|L2_SPAGE
value|0x02
end_define

begin_comment
comment|/* L2 small page (4KB) */
end_comment

begin_define
define|#
directive|define
name|L2_MASK
value|0x03
end_define

begin_comment
comment|/* Mask for L2 entry type */
end_comment

begin_define
define|#
directive|define
name|L2_INVAL
value|0x00
end_define

begin_comment
comment|/* L2 invalid type */
end_comment

begin_comment
comment|/* PTE construction macros */
end_comment

begin_define
define|#
directive|define
name|L2_LPTE
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|,
name|f
parameter_list|)
value|((p) | PT_AP(a) | L2_LPAGE | (f))
end_define

begin_define
define|#
directive|define
name|L2_SPTE
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|,
name|f
parameter_list|)
value|((p) | PT_AP(a) | L2_SPAGE | (f))
end_define

begin_define
define|#
directive|define
name|L2_PTE
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|L2_SPTE((p), (a), PT_CACHEABLE)
end_define

begin_define
define|#
directive|define
name|L2_PTE_NC
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|L2_SPTE((p), (a), PT_B)
end_define

begin_define
define|#
directive|define
name|L2_PTE_NC_NB
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|L2_SPTE((p), (a), 0)
end_define

begin_define
define|#
directive|define
name|L1_SECPTE
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|,
name|f
parameter_list|)
value|((p) | ((a)<< AP_SECTION_SHIFT) | (f) \ 				| L1_SECTION | PT_U)
end_define

begin_define
define|#
directive|define
name|L1_PTE
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x00 | L1_PAGE | PT_U)
end_define

begin_define
define|#
directive|define
name|L1_SEC
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|L1_SECPTE((p), AP_KRW, (c))
end_define

begin_define
define|#
directive|define
name|L1_SEC_SIZE
value|(1<< PDSHIFT)
end_define

begin_define
define|#
directive|define
name|L2_LPAGE_SIZE
value|(NBPG * 16)
end_define

begin_comment
comment|/* Domain types */
end_comment

begin_define
define|#
directive|define
name|DOMAIN_FAULT
value|0x00
end_define

begin_define
define|#
directive|define
name|DOMAIN_CLIENT
value|0x01
end_define

begin_define
define|#
directive|define
name|DOMAIN_RESERVED
value|0x02
end_define

begin_define
define|#
directive|define
name|DOMAIN_MANAGER
value|0x03
end_define

begin_comment
comment|/* L1 and L2 address masks */
end_comment

begin_define
define|#
directive|define
name|L1_ADDR_MASK
value|0xfffffc00
end_define

begin_define
define|#
directive|define
name|L2_ADDR_MASK
value|0xfffff000
end_define

begin_comment
comment|/*  * The ARM MMU architecture was introduced with ARM v3 (previous ARM  * architecture versions used an optional off-CPU memory controller  * to perform address translation).  *  * The ARM MMU consists of a TLB and translation table walking logic.  * There is typically one TLB per memory interface (or, put another  * way, one TLB per software-visible cache).  *  * The ARM MMU is capable of mapping memory in the following chunks:  *  *	1M	Sections (L1 table)  *  *	64K	Large Pages (L2 table)  *  *	4K	Small Pages (L2 table)  *  *	1K	Tiny Pages (L2 table)  *  * There are two types of L2 tables: Coarse Tables and Fine Tables.  * Coarse Tables can map Large and Small Pages.  Fine Tables can  * map Tiny Pages.  *  * Coarse Tables can define 4 Subpages within Large and Small pages.  * Subpages define different permissions for each Subpage within  * a Page.  *  * Coarse Tables are 1K in length.  Fine tables are 4K in length.  *  * The Translation Table Base register holds the pointer to the  * L1 Table.  The L1 Table is a 16K contiguous chunk of memory  * aligned to a 16K boundary.  Each entry in the L1 Table maps  * 1M of virtual address space, either via a Section mapping or  * via an L2 Table.  *  * In addition, the Fast Context Switching Extension (FCSE) is available  * on some ARM v4 and ARM v5 processors.  FCSE is a way of eliminating  * TLB/cache flushes on context switch by use of a smaller address space  * and a "process ID" that modifies the virtual address before being  * presented to the translation logic.  */
end_comment

begin_define
define|#
directive|define
name|L1_S_SIZE
value|0x00100000
end_define

begin_comment
comment|/* 1M */
end_comment

begin_define
define|#
directive|define
name|L1_S_OFFSET
value|(L1_S_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|L1_S_FRAME
value|(~L1_S_OFFSET)
end_define

begin_define
define|#
directive|define
name|L1_S_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|L2_L_SIZE
value|0x00010000
end_define

begin_comment
comment|/* 64K */
end_comment

begin_define
define|#
directive|define
name|L2_L_OFFSET
value|(L2_L_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|L2_L_FRAME
value|(~L2_L_OFFSET)
end_define

begin_define
define|#
directive|define
name|L2_L_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|L2_S_SIZE
value|0x00001000
end_define

begin_comment
comment|/* 4K */
end_comment

begin_define
define|#
directive|define
name|L2_S_OFFSET
value|(L2_S_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|L2_S_FRAME
value|(~L2_S_OFFSET)
end_define

begin_define
define|#
directive|define
name|L2_S_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|L2_T_SIZE
value|0x00000400
end_define

begin_comment
comment|/* 1K */
end_comment

begin_define
define|#
directive|define
name|L2_T_OFFSET
value|(L2_T_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|L2_T_FRAME
value|(~L2_T_OFFSET)
end_define

begin_define
define|#
directive|define
name|L2_T_SHIFT
value|10
end_define

begin_comment
comment|/*  * The NetBSD VM implementation only works on whole pages (4K),  * whereas the ARM MMU's Coarse tables are sized in terms of 1K  * (16K L1 table, 1K L2 table).  *  * So, we allocate L2 tables 4 at a time, thus yielding a 4K L2  * table.  */
end_comment

begin_define
define|#
directive|define
name|L1_ADDR_BITS
value|0xfff00000
end_define

begin_comment
comment|/* L1 PTE address bits */
end_comment

begin_define
define|#
directive|define
name|L2_ADDR_BITS
value|0x000ff000
end_define

begin_comment
comment|/* L2 PTE address bits */
end_comment

begin_define
define|#
directive|define
name|L1_TABLE_SIZE
value|0x4000
end_define

begin_comment
comment|/* 16K */
end_comment

begin_define
define|#
directive|define
name|L2_TABLE_SIZE
value|0x1000
end_define

begin_comment
comment|/* 4K */
end_comment

begin_comment
comment|/*  * The new pmap deals with the 1KB coarse L2 tables by  * allocating them from a pool. Until every port has been converted,  * keep the old L2_TABLE_SIZE define lying around. Converted ports  * should use L2_TABLE_SIZE_REAL until then.  */
end_comment

begin_define
define|#
directive|define
name|L2_TABLE_SIZE_REAL
value|0x400
end_define

begin_comment
comment|/* 1K */
end_comment

begin_comment
comment|/*  * ARM L1 Descriptors  */
end_comment

begin_define
define|#
directive|define
name|L1_TYPE_INV
value|0x00
end_define

begin_comment
comment|/* Invalid (fault) */
end_comment

begin_define
define|#
directive|define
name|L1_TYPE_C
value|0x01
end_define

begin_comment
comment|/* Coarse L2 */
end_comment

begin_define
define|#
directive|define
name|L1_TYPE_S
value|0x02
end_define

begin_comment
comment|/* Section */
end_comment

begin_define
define|#
directive|define
name|L1_TYPE_F
value|0x03
end_define

begin_comment
comment|/* Fine L2 */
end_comment

begin_define
define|#
directive|define
name|L1_TYPE_MASK
value|0x03
end_define

begin_comment
comment|/* mask of type bits */
end_comment

begin_comment
comment|/* L1 Section Descriptor */
end_comment

begin_define
define|#
directive|define
name|L1_S_B
value|0x00000004
end_define

begin_comment
comment|/* bufferable Section */
end_comment

begin_define
define|#
directive|define
name|L1_S_C
value|0x00000008
end_define

begin_comment
comment|/* cacheable Section */
end_comment

begin_define
define|#
directive|define
name|L1_S_IMP
value|0x00000010
end_define

begin_comment
comment|/* implementation defined */
end_comment

begin_define
define|#
directive|define
name|L1_S_DOM
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_comment
comment|/* domain */
end_comment

begin_define
define|#
directive|define
name|L1_S_DOM_MASK
value|L1_S_DOM(0xf)
end_define

begin_define
define|#
directive|define
name|L1_S_AP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
end_define

begin_comment
comment|/* access permissions */
end_comment

begin_define
define|#
directive|define
name|L1_S_ADDR_MASK
value|0xfff00000
end_define

begin_comment
comment|/* phys address of section */
end_comment

begin_define
define|#
directive|define
name|L1_S_XSCALE_P
value|0x00000200
end_define

begin_comment
comment|/* ECC enable for this section */
end_comment

begin_define
define|#
directive|define
name|L1_S_XSCALE_TEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_comment
comment|/* Type Extension */
end_comment

begin_comment
comment|/* L1 Coarse Descriptor */
end_comment

begin_define
define|#
directive|define
name|L1_C_IMP0
value|0x00000004
end_define

begin_comment
comment|/* implementation defined */
end_comment

begin_define
define|#
directive|define
name|L1_C_IMP1
value|0x00000008
end_define

begin_comment
comment|/* implementation defined */
end_comment

begin_define
define|#
directive|define
name|L1_C_IMP2
value|0x00000010
end_define

begin_comment
comment|/* implementation defined */
end_comment

begin_define
define|#
directive|define
name|L1_C_DOM
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_comment
comment|/* domain */
end_comment

begin_define
define|#
directive|define
name|L1_C_DOM_MASK
value|L1_C_DOM(0xf)
end_define

begin_define
define|#
directive|define
name|L1_C_ADDR_MASK
value|0xfffffc00
end_define

begin_comment
comment|/* phys address of L2 Table */
end_comment

begin_define
define|#
directive|define
name|L1_C_XSCALE_P
value|0x00000200
end_define

begin_comment
comment|/* ECC enable for this section */
end_comment

begin_comment
comment|/* L1 Fine Descriptor */
end_comment

begin_define
define|#
directive|define
name|L1_F_IMP0
value|0x00000004
end_define

begin_comment
comment|/* implementation defined */
end_comment

begin_define
define|#
directive|define
name|L1_F_IMP1
value|0x00000008
end_define

begin_comment
comment|/* implementation defined */
end_comment

begin_define
define|#
directive|define
name|L1_F_IMP2
value|0x00000010
end_define

begin_comment
comment|/* implementation defined */
end_comment

begin_define
define|#
directive|define
name|L1_F_DOM
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_comment
comment|/* domain */
end_comment

begin_define
define|#
directive|define
name|L1_F_DOM_MASK
value|L1_F_DOM(0xf)
end_define

begin_define
define|#
directive|define
name|L1_F_ADDR_MASK
value|0xfffff000
end_define

begin_comment
comment|/* phys address of L2 Table */
end_comment

begin_define
define|#
directive|define
name|L1_F_XSCALE_P
value|0x00000200
end_define

begin_comment
comment|/* ECC enable for this section */
end_comment

begin_comment
comment|/*  * ARM L2 Descriptors  */
end_comment

begin_define
define|#
directive|define
name|L2_TYPE_INV
value|0x00
end_define

begin_comment
comment|/* Invalid (fault) */
end_comment

begin_define
define|#
directive|define
name|L2_TYPE_L
value|0x01
end_define

begin_comment
comment|/* Large Page */
end_comment

begin_define
define|#
directive|define
name|L2_TYPE_S
value|0x02
end_define

begin_comment
comment|/* Small Page */
end_comment

begin_define
define|#
directive|define
name|L2_TYPE_T
value|0x03
end_define

begin_comment
comment|/* Tiny Page */
end_comment

begin_define
define|#
directive|define
name|L2_TYPE_MASK
value|0x03
end_define

begin_comment
comment|/* mask of type bits */
end_comment

begin_comment
comment|/* 	 * This L2 Descriptor type is available on XScale processors 	 * when using a Coarse L1 Descriptor.  The Extended Small 	 * Descriptor has the same format as the XScale Tiny Descriptor, 	 * but describes a 4K page, rather than a 1K page. 	 */
end_comment

begin_define
define|#
directive|define
name|L2_TYPE_XSCALE_XS
value|0x03
end_define

begin_comment
comment|/* XScale Extended Small Page */
end_comment

begin_define
define|#
directive|define
name|L2_B
value|0x00000004
end_define

begin_comment
comment|/* Bufferable page */
end_comment

begin_define
define|#
directive|define
name|L2_C
value|0x00000008
end_define

begin_comment
comment|/* Cacheable page */
end_comment

begin_define
define|#
directive|define
name|L2_AP0
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_comment
comment|/* access permissions (sp 0) */
end_comment

begin_define
define|#
directive|define
name|L2_AP1
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_comment
comment|/* access permissions (sp 1) */
end_comment

begin_define
define|#
directive|define
name|L2_AP2
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* access permissions (sp 2) */
end_comment

begin_define
define|#
directive|define
name|L2_AP3
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
end_define

begin_comment
comment|/* access permissions (sp 3) */
end_comment

begin_define
define|#
directive|define
name|L2_AP
parameter_list|(
name|x
parameter_list|)
value|(L2_AP0(x) | L2_AP1(x) | L2_AP2(x) | L2_AP3(x))
end_define

begin_define
define|#
directive|define
name|L2_XSCALE_L_TEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_comment
comment|/* Type Extension */
end_comment

begin_define
define|#
directive|define
name|L2_XSCALE_T_TEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_comment
comment|/* Type Extension */
end_comment

begin_comment
comment|/*  * Access Permissions for L1 and L2 Descriptors.  */
end_comment

begin_define
define|#
directive|define
name|AP_W
value|0x01
end_define

begin_comment
comment|/* writable */
end_comment

begin_define
define|#
directive|define
name|AP_U
value|0x02
end_define

begin_comment
comment|/* user */
end_comment

begin_comment
comment|/*  * Short-hand for common AP_* constants.  *  * Note: These values assume the S (System) bit is set and  * the R (ROM) bit is clear in CP15 register 1.  */
end_comment

begin_define
define|#
directive|define
name|AP_KR
value|0x00
end_define

begin_comment
comment|/* kernel read */
end_comment

begin_define
define|#
directive|define
name|AP_KRW
value|0x01
end_define

begin_comment
comment|/* kernel read/write */
end_comment

begin_define
define|#
directive|define
name|AP_KRWUR
value|0x02
end_define

begin_comment
comment|/* kernel read/write usr read */
end_comment

begin_define
define|#
directive|define
name|AP_KRWURW
value|0x03
end_define

begin_comment
comment|/* kernel read/write usr read/write */
end_comment

begin_comment
comment|/*  * Domain Types for the Domain Access Control Register.  */
end_comment

begin_define
define|#
directive|define
name|DOMAIN_FAULT
value|0x00
end_define

begin_comment
comment|/* no access */
end_comment

begin_define
define|#
directive|define
name|DOMAIN_CLIENT
value|0x01
end_define

begin_comment
comment|/* client */
end_comment

begin_define
define|#
directive|define
name|DOMAIN_RESERVED
value|0x02
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|DOMAIN_MANAGER
value|0x03
end_define

begin_comment
comment|/* manager */
end_comment

begin_comment
comment|/*  * Type Extension bits for XScale processors.  *  * Behavior of C and B when X == 0:  *  * C B  Cacheable  Bufferable  Write Policy  Line Allocate Policy  * 0 0      N          N            -                 -  * 0 1      N          Y            -                 -  * 1 0      Y          Y       Write-through    Read Allocate  * 1 1      Y          Y        Write-back      Read Allocate  *  * Behavior of C and B when X == 1:  * C B  Cacheable  Bufferable  Write Policy  Line Allocate Policy  * 0 0      -          -            -                 -           DO NOT USE  * 0 1      N          Y            -                 -  * 1 0  Mini-Data      -            -                 -  * 1 1      Y          Y        Write-back       R/W Allocate  */
end_comment

begin_define
define|#
directive|define
name|TEX_XSCALE_X
value|0x01
end_define

begin_comment
comment|/* X modifies C and B */
end_comment

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

