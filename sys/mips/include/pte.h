begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2010 Juli Mallett<jmallett@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|_LOCORE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_comment
comment|/*  PHYSADDR_64_BIT */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|pt_entry_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|uint32_t
name|pt_entry_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|pt_entry_t
modifier|*
name|pd_entry_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * TLB and PTE management.  Most things operate within the context of  * EntryLo0,1, and begin with TLBLO_.  Things which work with EntryHi  * start with TLBHI_.  PTE bits begin with PTE_.  *  * Note that we use the same size VM and TLB pages.  */
end_comment

begin_define
define|#
directive|define
name|TLB_PAGE_SHIFT
value|(PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLB_PAGE_SIZE
value|(1<< TLB_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLB_PAGE_MASK
value|(TLB_PAGE_SIZE - 1)
end_define

begin_comment
comment|/*  * TLB PageMask register.  Has mask bits set above the default, 4K, page mask.  */
end_comment

begin_define
define|#
directive|define
name|TLBMASK_SHIFT
value|(13)
end_define

begin_define
define|#
directive|define
name|TLBMASK_MASK
value|((PAGE_MASK>> TLBMASK_SHIFT)<< TLBMASK_SHIFT)
end_define

begin_comment
comment|/*  * FreeBSD/mips page-table entries take a near-identical format to MIPS TLB  * entries, each consisting of two 32-bit or 64-bit values ("EntryHi" and  * "EntryLo").  MIPS4k and MIPS64 both define certain bits in TLB entries as  * reserved, and these must be zero-filled by software.  We overload these  * bits in PTE entries to hold  PTE_ flags such as RO, W, and MANAGED.  * However, we must mask these out when writing to TLB entries to ensure that  * they do not become visible to hardware -- especially on MIPS64r2 which has  * an extended physical memory space.  *  * When using n64 and n32, shift software-defined bits into the MIPS64r2  * reserved range, which runs from bit 55 ... 63.  In other configurations  * (32-bit MIPS4k and compatible), shift them out to bits 29 ... 31.  *  * NOTE: This means that for 32-bit use of CP0, we aren't able to set the top  * bit of PFN to a non-zero value, as software is using it!  This physical  * memory size limit may not be sufficiently enforced elsewhere.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_comment
comment|/*  PHYSADDR_64_BIT */
end_comment

begin_define
define|#
directive|define
name|TLBLO_SWBITS_SHIFT
value|(55)
end_define

begin_define
define|#
directive|define
name|TLBLO_SWBITS_CLEAR_SHIFT
value|(9)
end_define

begin_define
define|#
directive|define
name|TLBLO_PFN_MASK
value|0x3FFFFFFC0ULL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TLBLO_SWBITS_SHIFT
value|(29)
end_define

begin_define
define|#
directive|define
name|TLBLO_SWBITS_CLEAR_SHIFT
value|(3)
end_define

begin_define
define|#
directive|define
name|TLBLO_PFN_MASK
value|(0x1FFFFFC0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TLBLO_PFN_SHIFT
value|(6)
end_define

begin_define
define|#
directive|define
name|TLBLO_SWBITS_MASK
value|((pt_entry_t)0x7<< TLBLO_SWBITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLBLO_PA_TO_PFN
parameter_list|(
name|pa
parameter_list|)
value|((((pa)>> TLB_PAGE_SHIFT)<< TLBLO_PFN_SHIFT)& TLBLO_PFN_MASK)
end_define

begin_define
define|#
directive|define
name|TLBLO_PFN_TO_PA
parameter_list|(
name|pfn
parameter_list|)
value|((vm_paddr_t)((pfn)>> TLBLO_PFN_SHIFT)<< TLB_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLBLO_PTE_TO_PFN
parameter_list|(
name|pte
parameter_list|)
value|((pte)& TLBLO_PFN_MASK)
end_define

begin_define
define|#
directive|define
name|TLBLO_PTE_TO_PA
parameter_list|(
name|pte
parameter_list|)
value|(TLBLO_PFN_TO_PA(TLBLO_PTE_TO_PFN((pte))))
end_define

begin_comment
comment|/*  * XXX This comment is not correct for anything more modern than R4K.  *  * VPN for EntryHi register.  Upper two bits select user, supervisor,  * or kernel.  Bits 61 to 40 copy bit 63.  VPN2 is bits 39 and down to  * as low as 13, down to PAGE_SHIFT, to index 2 TLB pages*.  From bit 12  * to bit 8 there is a 5-bit 0 field.  Low byte is ASID.  *  * XXX This comment is not correct for FreeBSD.  * Note that in FreeBSD, we map 2 TLB pages is equal to 1 VM page.  */
end_comment

begin_define
define|#
directive|define
name|TLBHI_ASID_MASK
value|(0xff)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|TLBHI_R_SHIFT
value|62
end_define

begin_define
define|#
directive|define
name|TLBHI_R_USER
value|(0x00UL<< TLBHI_R_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLBHI_R_SUPERVISOR
value|(0x01UL<< TLBHI_R_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLBHI_R_KERNEL
value|(0x03UL<< TLBHI_R_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLBHI_R_MASK
value|(0x03UL<< TLBHI_R_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLBHI_VA_R
parameter_list|(
name|va
parameter_list|)
value|((va)& TLBHI_R_MASK)
end_define

begin_define
define|#
directive|define
name|TLBHI_FILL_SHIFT
value|40
end_define

begin_define
define|#
directive|define
name|TLBHI_VPN2_SHIFT
value|(TLB_PAGE_SHIFT + 1)
end_define

begin_define
define|#
directive|define
name|TLBHI_VPN2_MASK
value|(((~((1UL<< TLBHI_VPN2_SHIFT) - 1))<< (63 - TLBHI_FILL_SHIFT))>> (63 - TLBHI_FILL_SHIFT))
end_define

begin_define
define|#
directive|define
name|TLBHI_VA_TO_VPN2
parameter_list|(
name|va
parameter_list|)
value|((va)& TLBHI_VPN2_MASK)
end_define

begin_define
define|#
directive|define
name|TLBHI_ENTRY
parameter_list|(
name|va
parameter_list|,
name|asid
parameter_list|)
value|((TLBHI_VA_R((va)))
comment|/* Region. */
value|| \ 				 (TLBHI_VA_TO_VPN2((va)))
comment|/* VPN2. */
value|| \ 				 ((asid)& TLBHI_ASID_MASK))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined(__mips_n64) */
end_comment

begin_define
define|#
directive|define
name|TLBHI_PAGE_MASK
value|(2 * PAGE_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|TLBHI_ENTRY
parameter_list|(
name|va
parameter_list|,
name|asid
parameter_list|)
value|(((va)& ~TLBHI_PAGE_MASK) | ((asid)& TLBHI_ASID_MASK))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__mips_n64) */
end_comment

begin_comment
comment|/*  * TLB flags managed in hardware:  * 	C:	Cache attribute.  * 	D:	Dirty bit.  This means a page is writable.  It is not  * 		set at first, and a write is trapped, and the dirty  * 		bit is set.  See also PTE_RO.  * 	V:	Valid bit.  Obvious, isn't it?  * 	G:	Global bit.  This means that this mapping is present  * 		in EVERY address space, and to ignore the ASID when  * 		it is matched.  */
end_comment

begin_define
define|#
directive|define
name|PTE_C
parameter_list|(
name|attr
parameter_list|)
value|((attr& 0x07)<< 3)
end_define

begin_define
define|#
directive|define
name|PTE_C_UNCACHED
value|(PTE_C(MIPS_CCA_UNCACHED))
end_define

begin_define
define|#
directive|define
name|PTE_C_CACHE
value|(PTE_C(MIPS_CCA_CACHED))
end_define

begin_define
define|#
directive|define
name|PTE_D
value|0x04
end_define

begin_define
define|#
directive|define
name|PTE_V
value|0x02
end_define

begin_define
define|#
directive|define
name|PTE_G
value|0x01
end_define

begin_comment
comment|/*  * VM flags managed in software:  * 	RO:	Read only.  Never set PTE_D on this page, and don't  * 		listen to requests to write to it.  * 	W:	Wired.  ???  *	MANAGED:Managed.  This PTE maps a managed page.  *  * These bits should not be written into the TLB, so must first be masked out  * explicitly in C, or using CLEAR_PTE_SWBITS() in assembly.  */
end_comment

begin_define
define|#
directive|define
name|PTE_RO
value|((pt_entry_t)0x01<< TLBLO_SWBITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_W
value|((pt_entry_t)0x02<< TLBLO_SWBITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_MANAGED
value|((pt_entry_t)0x04<< TLBLO_SWBITS_SHIFT)
end_define

begin_comment
comment|/*  * PTE management functions for bits defined above.  */
end_comment

begin_define
define|#
directive|define
name|pte_clear
parameter_list|(
name|pte
parameter_list|,
name|bit
parameter_list|)
value|(*(pte)&= ~(bit))
end_define

begin_define
define|#
directive|define
name|pte_set
parameter_list|(
name|pte
parameter_list|,
name|bit
parameter_list|)
value|(*(pte) |= (bit))
end_define

begin_define
define|#
directive|define
name|pte_test
parameter_list|(
name|pte
parameter_list|,
name|bit
parameter_list|)
value|((*(pte)& (bit)) == (bit))
end_define

begin_comment
comment|/* Assembly support for PTE access*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_comment
comment|/*  PHYSADDR_64_BIT */
end_comment

begin_define
define|#
directive|define
name|PTESHIFT
value|3
end_define

begin_define
define|#
directive|define
name|PTE2MASK
value|0xff0
end_define

begin_comment
comment|/* for the 2-page lo0/lo1 */
end_comment

begin_define
define|#
directive|define
name|PTEMASK
value|0xff8
end_define

begin_define
define|#
directive|define
name|PTESIZE
value|8
end_define

begin_define
define|#
directive|define
name|PTE_L
value|ld
end_define

begin_define
define|#
directive|define
name|PTE_MTC0
value|dmtc0
end_define

begin_define
define|#
directive|define
name|CLEAR_PTE_SWBITS
parameter_list|(
name|pr
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTESHIFT
value|2
end_define

begin_define
define|#
directive|define
name|PTE2MASK
value|0xff8
end_define

begin_comment
comment|/* for the 2-page lo0/lo1 */
end_comment

begin_define
define|#
directive|define
name|PTEMASK
value|0xffc
end_define

begin_define
define|#
directive|define
name|PTESIZE
value|4
end_define

begin_define
define|#
directive|define
name|PTE_L
value|lw
end_define

begin_define
define|#
directive|define
name|PTE_MTC0
value|mtc0
end_define

begin_define
define|#
directive|define
name|CLEAR_PTE_SWBITS
parameter_list|(
name|r
parameter_list|)
value|LONG_SLL r, TLBLO_SWBITS_CLEAR_SHIFT; LONG_SRL r, TLBLO_SWBITS_CLEAR_SHIFT
end_define

begin_comment
comment|/* remove swbits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__mips_n64) || defined(__mips_n32) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|PTRSHIFT
value|3
end_define

begin_define
define|#
directive|define
name|PDEPTRMASK
value|0xff8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTRSHIFT
value|2
end_define

begin_define
define|#
directive|define
name|PDEPTRMASK
value|0xffc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PTE_H_ */
end_comment

end_unit

