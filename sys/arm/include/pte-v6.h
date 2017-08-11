begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2014 Svatopluk Kraus<onwahe@gmail.com>  * Copyright 2014 Michal Meloun<meloun@miracle.cz>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PTE_V6_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PTE_V6_H_
end_define

begin_comment
comment|/*  * Domain Types	for the	Domain Access Control Register.  */
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
comment|/*  * TEX remap registers attributes  */
end_comment

begin_define
define|#
directive|define
name|PRRR_SO
value|0
end_define

begin_comment
comment|/* Strongly ordered memory */
end_comment

begin_define
define|#
directive|define
name|PRRR_DEV
value|1
end_define

begin_comment
comment|/* Device memory */
end_comment

begin_define
define|#
directive|define
name|PRRR_MEM
value|2
end_define

begin_comment
comment|/* Normal memory */
end_comment

begin_define
define|#
directive|define
name|PRRR_DS0
value|(1<< 16)
end_define

begin_comment
comment|/* Shared bit for Device, S = 0 */
end_comment

begin_define
define|#
directive|define
name|PRRR_DS1
value|(1<< 17)
end_define

begin_comment
comment|/* Shared bit for Device, S = 1 */
end_comment

begin_define
define|#
directive|define
name|PRRR_NS0
value|(1<< 18)
end_define

begin_comment
comment|/* Shared bit for Normal, S = 0 */
end_comment

begin_define
define|#
directive|define
name|PRRR_NS1
value|(1<< 19)
end_define

begin_comment
comment|/* Shared bit for Normal, S = 1 */
end_comment

begin_define
define|#
directive|define
name|PRRR_NOS_SHIFT
value|24
end_define

begin_comment
comment|/* base shif for Not Outer Shared bits */
end_comment

begin_define
define|#
directive|define
name|NMRR_NC
value|0
end_define

begin_comment
comment|/* Noncachable*/
end_comment

begin_define
define|#
directive|define
name|NMRR_WB_WA
value|1
end_define

begin_comment
comment|/* Write Back, Write Allocate */
end_comment

begin_define
define|#
directive|define
name|NMRR_WT
value|2
end_define

begin_comment
comment|/* Write Through, Non-Write Allocate */
end_comment

begin_define
define|#
directive|define
name|NMRR_WB
value|3
end_define

begin_comment
comment|/* Write Back, Non-Write Allocate */
end_comment

begin_comment
comment|/*  *  * The ARM MMU is capable of mapping memory in the following chunks:  *  *	16M	Supersections (L1 table)  *  *	1M	Sections (L1 table)  *  *	64K	Large Pages (L2	table)  *  *	4K	Small Pages (L2	table)  *  *  * Coarse Tables can map Large and Small Pages.  * Coarse Tables are 1K in length.  *  * The Translation Table Base register holds the pointer to the  * L1 Table.  The L1 Table is a 16K contiguous chunk of memory  * aligned to a 16K boundary.  Each entry in the L1 Table maps  * 1M of virtual address space, either via a Section mapping or  * via an L2 Table.  *  */
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
name|L1_ENTRIES
value|0x1000
end_define

begin_comment
comment|/*  4K */
end_comment

begin_define
define|#
directive|define
name|L2_TABLE_SIZE
value|0x0400
end_define

begin_comment
comment|/*  1K */
end_comment

begin_define
define|#
directive|define
name|L2_ENTRIES
value|0x0100
end_define

begin_comment
comment|/* 256 */
end_comment

begin_comment
comment|/* ARMv6 super-sections. */
end_comment

begin_define
define|#
directive|define
name|L1_SUP_SIZE
value|0x01000000
end_define

begin_comment
comment|/* 16M */
end_comment

begin_define
define|#
directive|define
name|L1_SUP_OFFSET
value|(L1_SUP_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|L1_SUP_FRAME
value|(~L1_SUP_OFFSET)
end_define

begin_define
define|#
directive|define
name|L1_SUP_SHIFT
value|24
end_define

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

begin_comment
comment|/*  * ARM MMU L1 Descriptors  */
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
name|L1_TYPE_MASK
value|0x03
end_define

begin_comment
comment|/* Mask	of type	bits */
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
name|L1_S_NX
value|0x00000010
end_define

begin_comment
comment|/* not executeable */
end_comment

begin_define
define|#
directive|define
name|L1_S_DOM
parameter_list|(
name|x
parameter_list|)
value|((x)<<	5)
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
name|L1_S_P
value|0x00000200
end_define

begin_comment
comment|/* ECC enable for this section */
end_comment

begin_define
define|#
directive|define
name|L1_S_AP
parameter_list|(
name|x
parameter_list|)
value|((x)<<	10)
end_define

begin_comment
comment|/* access permissions */
end_comment

begin_define
define|#
directive|define
name|L1_S_AP0
value|0x00000400
end_define

begin_comment
comment|/* access permissions bit 0 */
end_comment

begin_define
define|#
directive|define
name|L1_S_AP1
value|0x00000800
end_define

begin_comment
comment|/* access permissions bit 1 */
end_comment

begin_define
define|#
directive|define
name|L1_S_TEX
parameter_list|(
name|x
parameter_list|)
value|((x)<<	12)
end_define

begin_comment
comment|/* type	extension */
end_comment

begin_define
define|#
directive|define
name|L1_S_TEX0
value|0x00001000
end_define

begin_comment
comment|/* type	extension bit 0	*/
end_comment

begin_define
define|#
directive|define
name|L1_S_TEX1
value|0x00002000
end_define

begin_comment
comment|/* type	extension bit 1	*/
end_comment

begin_define
define|#
directive|define
name|L1_S_TEX2
value|0x00004000
end_define

begin_comment
comment|/* type	extension bit 2	*/
end_comment

begin_define
define|#
directive|define
name|L1_S_AP2
value|0x00008000
end_define

begin_comment
comment|/* access permissions bit 2 */
end_comment

begin_define
define|#
directive|define
name|L1_S_SHARED
value|0x00010000
end_define

begin_comment
comment|/* shared */
end_comment

begin_define
define|#
directive|define
name|L1_S_NG
value|0x00020000
end_define

begin_comment
comment|/* not global */
end_comment

begin_define
define|#
directive|define
name|L1_S_SUPERSEC
value|0x00040000
end_define

begin_comment
comment|/* Section is a	super-section. */
end_comment

begin_define
define|#
directive|define
name|L1_S_ADDR_MASK
value|0xfff00000
end_define

begin_comment
comment|/* phys	address	of section */
end_comment

begin_comment
comment|/* L1 Coarse Descriptor	*/
end_comment

begin_define
define|#
directive|define
name|L1_C_DOM
parameter_list|(
name|x
parameter_list|)
value|((x)<<	5)
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
name|L1_C_P
value|0x00000200
end_define

begin_comment
comment|/* ECC enable for this section */
end_comment

begin_define
define|#
directive|define
name|L1_C_ADDR_MASK
value|0xfffffc00
end_define

begin_comment
comment|/* phys	address	of L2 Table */
end_comment

begin_comment
comment|/*  * ARM MMU L2 Descriptors  */
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
comment|/* Large Page  - 64k - not used yet*/
end_comment

begin_define
define|#
directive|define
name|L2_TYPE_S
value|0x02
end_define

begin_comment
comment|/* Small Page  - 4 */
end_comment

begin_define
define|#
directive|define
name|L2_TYPE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|L2_NX
value|0x00000001
end_define

begin_comment
comment|/* Not executable */
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
name|L2_CB_SHIFT
value|2
end_define

begin_comment
comment|/* C,B bit field shift */
end_comment

begin_define
define|#
directive|define
name|L2_AP
parameter_list|(
name|x
parameter_list|)
value|((x)<<	4)
end_define

begin_define
define|#
directive|define
name|L2_AP0
value|0x00000010
end_define

begin_comment
comment|/* access permissions bit 0*/
end_comment

begin_define
define|#
directive|define
name|L2_AP1
value|0x00000020
end_define

begin_comment
comment|/* access permissions bit 1*/
end_comment

begin_define
define|#
directive|define
name|L2_TEX_SHIFT
value|6
end_define

begin_comment
comment|/* type extension field shift */
end_comment

begin_define
define|#
directive|define
name|L2_TEX
parameter_list|(
name|x
parameter_list|)
value|((x)<<	L2_TEX_SHIFT)
end_define

begin_comment
comment|/* type	extension */
end_comment

begin_define
define|#
directive|define
name|L2_TEX0
value|0x00000040
end_define

begin_comment
comment|/* type	extension bit 0	*/
end_comment

begin_define
define|#
directive|define
name|L2_TEX1
value|0x00000080
end_define

begin_comment
comment|/* type	extension bit 1	*/
end_comment

begin_define
define|#
directive|define
name|L2_TEX2
value|0x00000100
end_define

begin_comment
comment|/* type	extension bit 2	*/
end_comment

begin_define
define|#
directive|define
name|L2_AP2
value|0x00000200
end_define

begin_comment
comment|/* access permissions  bit 2*/
end_comment

begin_define
define|#
directive|define
name|L2_SHARED
value|0x00000400
end_define

begin_comment
comment|/* shared */
end_comment

begin_define
define|#
directive|define
name|L2_NG
value|0x00000800
end_define

begin_comment
comment|/* not global */
end_comment

begin_comment
comment|/*  * TEX classes encoding  */
end_comment

begin_define
define|#
directive|define
name|TEX1_CLASS_0
value|(			    0)
end_define

begin_define
define|#
directive|define
name|TEX1_CLASS_1
value|(		       L1_S_B)
end_define

begin_define
define|#
directive|define
name|TEX1_CLASS_2
value|(	      L1_S_C	     )
end_define

begin_define
define|#
directive|define
name|TEX1_CLASS_3
value|(	      L1_S_C | L1_S_B)
end_define

begin_define
define|#
directive|define
name|TEX1_CLASS_4
value|(L1_S_TEX0		     )
end_define

begin_define
define|#
directive|define
name|TEX1_CLASS_5
value|(L1_S_TEX0 |	       L1_S_B)
end_define

begin_define
define|#
directive|define
name|TEX1_CLASS_6
value|(L1_S_TEX0 | L1_S_C	     )
end_define

begin_comment
comment|/* Reserved for	ARM11 */
end_comment

begin_define
define|#
directive|define
name|TEX1_CLASS_7
value|(L1_S_TEX0 | L1_S_C | L1_S_B)
end_define

begin_define
define|#
directive|define
name|TEX2_CLASS_0
value|(		      0)
end_define

begin_define
define|#
directive|define
name|TEX2_CLASS_1
value|(		   L2_B)
end_define

begin_define
define|#
directive|define
name|TEX2_CLASS_2
value|(	    L2_C       )
end_define

begin_define
define|#
directive|define
name|TEX2_CLASS_3
value|(	    L2_C | L2_B)
end_define

begin_define
define|#
directive|define
name|TEX2_CLASS_4
value|(L2_TEX0	       )
end_define

begin_define
define|#
directive|define
name|TEX2_CLASS_5
value|(L2_TEX0 |	   L2_B)
end_define

begin_define
define|#
directive|define
name|TEX2_CLASS_6
value|(L2_TEX0 | L2_C       )
end_define

begin_comment
comment|/* Reserved for	ARM11 */
end_comment

begin_define
define|#
directive|define
name|TEX2_CLASS_7
value|(L2_TEX0 | L2_C | L2_B)
end_define

begin_comment
comment|/* L1 table definitions. */
end_comment

begin_define
define|#
directive|define
name|NB_IN_PT1
value|L1_TABLE_SIZE
end_define

begin_define
define|#
directive|define
name|NPTE1_IN_PT1
value|L1_ENTRIES
end_define

begin_comment
comment|/* L2 table definitions. */
end_comment

begin_define
define|#
directive|define
name|NB_IN_PT2
value|L2_TABLE_SIZE
end_define

begin_define
define|#
directive|define
name|NPTE2_IN_PT2
value|L2_ENTRIES
end_define

begin_comment
comment|/*  * Map memory attributes to TEX	classes  */
end_comment

begin_define
define|#
directive|define
name|PTE2_ATTR_WB_WA
value|TEX2_CLASS_0
end_define

begin_define
define|#
directive|define
name|PTE2_ATTR_NOCACHE
value|TEX2_CLASS_1
end_define

begin_define
define|#
directive|define
name|PTE2_ATTR_DEVICE
value|TEX2_CLASS_2
end_define

begin_define
define|#
directive|define
name|PTE2_ATTR_SO
value|TEX2_CLASS_3
end_define

begin_define
define|#
directive|define
name|PTE2_ATTR_WT
value|TEX2_CLASS_4
end_define

begin_comment
comment|/*  * Software defined bits for L1	descriptors  *  - L1_AP0 is	used as	page accessed bit  *  - L1_AP2 (RO / not RW) is used as page not modified	bit  *  - L1_TEX0 is used as software emulated RO bit  */
end_comment

begin_define
define|#
directive|define
name|PTE1_V
value|L1_TYPE_S
end_define

begin_comment
comment|/* Valid bit */
end_comment

begin_define
define|#
directive|define
name|PTE1_A
value|L1_S_AP0
end_define

begin_comment
comment|/* Accessed - software emulated	*/
end_comment

begin_define
define|#
directive|define
name|PTE1_NM
value|L1_S_AP2
end_define

begin_comment
comment|/* not modified	bit - software emulated 					 * used	as real	write enable bit */
end_comment

begin_define
define|#
directive|define
name|PTE1_M
value|0
end_define

begin_comment
comment|/* Modified (dummy) */
end_comment

begin_define
define|#
directive|define
name|PTE1_S
value|L1_S_SHARED
end_define

begin_comment
comment|/* Shared */
end_comment

begin_define
define|#
directive|define
name|PTE1_NG
value|L1_S_NG
end_define

begin_comment
comment|/* Not global */
end_comment

begin_define
define|#
directive|define
name|PTE1_G
value|0
end_define

begin_comment
comment|/* Global (dummy) */
end_comment

begin_define
define|#
directive|define
name|PTE1_NX
value|L1_S_NX
end_define

begin_comment
comment|/* Not executable */
end_comment

begin_define
define|#
directive|define
name|PTE1_X
value|0
end_define

begin_comment
comment|/* Executable (dummy) */
end_comment

begin_define
define|#
directive|define
name|PTE1_RO
value|L1_S_TEX1
end_define

begin_comment
comment|/* Read	Only */
end_comment

begin_define
define|#
directive|define
name|PTE1_RW
value|0
end_define

begin_comment
comment|/* Read-Write (dummy) */
end_comment

begin_define
define|#
directive|define
name|PTE1_U
value|L1_S_AP1
end_define

begin_comment
comment|/* User	*/
end_comment

begin_define
define|#
directive|define
name|PTE1_NU
value|0
end_define

begin_comment
comment|/* Not user (kernel only) (dummy) */
end_comment

begin_define
define|#
directive|define
name|PTE1_W
value|L1_S_TEX2
end_define

begin_comment
comment|/* Wired */
end_comment

begin_define
define|#
directive|define
name|PTE1_SHIFT
value|L1_S_SHIFT
end_define

begin_define
define|#
directive|define
name|PTE1_SIZE
value|L1_S_SIZE
end_define

begin_define
define|#
directive|define
name|PTE1_OFFSET
value|L1_S_OFFSET
end_define

begin_define
define|#
directive|define
name|PTE1_FRAME
value|L1_S_FRAME
end_define

begin_define
define|#
directive|define
name|PTE1_ATTR_MASK
value|(L1_S_TEX0 | L1_S_C | L1_S_B)
end_define

begin_define
define|#
directive|define
name|PTE1_AP_KR
value|(PTE1_RO | PTE1_NM)
end_define

begin_define
define|#
directive|define
name|PTE1_AP_KRW
value|0
end_define

begin_define
define|#
directive|define
name|PTE1_AP_KRUR
value|(PTE1_RO | PTE1_NM | PTE1_U)
end_define

begin_define
define|#
directive|define
name|PTE1_AP_KRWURW
value|PTE1_U
end_define

begin_comment
comment|/*  * PTE1	descriptors creation macros.  */
end_comment

begin_define
define|#
directive|define
name|PTE1_PA
parameter_list|(
name|pa
parameter_list|)
value|((pa)&	PTE1_FRAME)
end_define

begin_define
define|#
directive|define
name|PTE1_AP_COMMON
value|(PTE1_V	| PTE1_S)
end_define

begin_define
define|#
directive|define
name|PTE1
parameter_list|(
name|pa
parameter_list|,
name|ap
parameter_list|,
name|attr
parameter_list|)
value|(PTE1_PA(pa) | (ap) | (attr) | PTE1_AP_COMMON)
end_define

begin_define
define|#
directive|define
name|PTE1_KERN
parameter_list|(
name|pa
parameter_list|,
name|ap
parameter_list|,
name|attr
parameter_list|)
value|PTE1(pa, (ap) |	PTE1_A | PTE1_G, attr)
end_define

begin_define
define|#
directive|define
name|PTE1_KERN_NG
parameter_list|(
name|pa
parameter_list|,
name|ap
parameter_list|,
name|attr
parameter_list|)
value|PTE1(pa, (ap) |	PTE1_A | PTE1_NG, attr)
end_define

begin_define
define|#
directive|define
name|PTE1_LINK
parameter_list|(
name|pa
parameter_list|)
value|(((pa)& L1_C_ADDR_MASK) | L1_TYPE_C)
end_define

begin_comment
comment|/*  * Software defined bits for L2	descriptors  *  - L2_AP0 is	used as	page accessed bit  *  - L2_AP2 (RO / not RW) is used as page not modified	bit  *  - L2_TEX0 is used as software emulated RO bit  */
end_comment

begin_define
define|#
directive|define
name|PTE2_V
value|L2_TYPE_S
end_define

begin_comment
comment|/* Valid bit */
end_comment

begin_define
define|#
directive|define
name|PTE2_A
value|L2_AP0
end_define

begin_comment
comment|/* Accessed - software emulated	*/
end_comment

begin_define
define|#
directive|define
name|PTE2_NM
value|L2_AP2
end_define

begin_comment
comment|/* not modified	bit - software emulated 					 * used	as real	write enable bit */
end_comment

begin_define
define|#
directive|define
name|PTE2_M
value|0
end_define

begin_comment
comment|/* Modified (dummy) */
end_comment

begin_define
define|#
directive|define
name|PTE2_S
value|L2_SHARED
end_define

begin_comment
comment|/* Shared */
end_comment

begin_define
define|#
directive|define
name|PTE2_NG
value|L2_NG
end_define

begin_comment
comment|/* Not global */
end_comment

begin_define
define|#
directive|define
name|PTE2_G
value|0
end_define

begin_comment
comment|/* Global (dummy) */
end_comment

begin_define
define|#
directive|define
name|PTE2_NX
value|L2_NX
end_define

begin_comment
comment|/* Not executable */
end_comment

begin_define
define|#
directive|define
name|PTE2_X
value|0
end_define

begin_comment
comment|/* Not executable (dummy) */
end_comment

begin_define
define|#
directive|define
name|PTE2_RO
value|L2_TEX1
end_define

begin_comment
comment|/* Read	Only */
end_comment

begin_define
define|#
directive|define
name|PTE2_U
value|L2_AP1
end_define

begin_comment
comment|/* User	*/
end_comment

begin_define
define|#
directive|define
name|PTE2_NU
value|0
end_define

begin_comment
comment|/* Not user (kernel only) (dummy) */
end_comment

begin_define
define|#
directive|define
name|PTE2_W
value|L2_TEX2
end_define

begin_comment
comment|/* Wired */
end_comment

begin_define
define|#
directive|define
name|PTE2_SHIFT
value|L2_S_SHIFT
end_define

begin_define
define|#
directive|define
name|PTE2_SIZE
value|L2_S_SIZE
end_define

begin_define
define|#
directive|define
name|PTE2_OFFSET
value|L2_S_OFFSET
end_define

begin_define
define|#
directive|define
name|PTE2_FRAME
value|L2_S_FRAME
end_define

begin_define
define|#
directive|define
name|PTE2_ATTR_MASK
value|(L2_TEX0 | L2_C | L2_B)
end_define

begin_comment
comment|/* PTE2 attributes to TEX class index: (TEX0 C B)  */
end_comment

begin_define
define|#
directive|define
name|PTE2_ATTR2IDX
parameter_list|(
name|attr
parameter_list|)
define|\
value|((((attr)& (L2_C | L2_B))>> L2_CB_SHIFT) |		\     (((attr)& L2_TEX0)>> (L2_TEX_SHIFT - L2_CB_SHIFT)))
end_define

begin_define
define|#
directive|define
name|PTE2_AP_KR
value|(PTE2_RO | PTE2_NM)
end_define

begin_define
define|#
directive|define
name|PTE2_AP_KRW
value|0
end_define

begin_define
define|#
directive|define
name|PTE2_AP_KRUR
value|(PTE2_RO | PTE2_NM | PTE2_U)
end_define

begin_define
define|#
directive|define
name|PTE2_AP_KRWURW
value|PTE2_U
end_define

begin_comment
comment|/*  * PTE2	descriptors creation macros.  */
end_comment

begin_define
define|#
directive|define
name|PTE2_PA
parameter_list|(
name|pa
parameter_list|)
value|((pa)&	PTE2_FRAME)
end_define

begin_define
define|#
directive|define
name|PTE2_AP_COMMON
value|(PTE2_V	| PTE2_S)
end_define

begin_define
define|#
directive|define
name|PTE2
parameter_list|(
name|pa
parameter_list|,
name|ap
parameter_list|,
name|attr
parameter_list|)
value|(PTE2_PA(pa) | (ap) | (attr) | PTE2_AP_COMMON)
end_define

begin_define
define|#
directive|define
name|PTE2_KERN
parameter_list|(
name|pa
parameter_list|,
name|ap
parameter_list|,
name|attr
parameter_list|)
value|PTE2(pa, (ap) |	PTE2_A | PTE2_G, attr)
end_define

begin_define
define|#
directive|define
name|PTE2_KERN_NG
parameter_list|(
name|pa
parameter_list|,
name|ap
parameter_list|,
name|attr
parameter_list|)
value|PTE2(pa, (ap) |	PTE2_A | PTE2_NG, attr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PTE_V6_H_ */
end_comment

end_unit

