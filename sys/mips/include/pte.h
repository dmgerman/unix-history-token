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

begin_comment
comment|/* pt_entry_t is 32 bit for now, has to be made 64 bit for n64 */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
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
comment|/*  * PFN for EntryLo register.  Upper bits are 0, which is to say that  * bit 29 is the last hardware bit;  Bits 30 and upwards (EntryLo is  * 64 bit though it can be referred to in 32-bits providing 2 software  * bits safely.  We use it as 64 bits to get many software bits, and  * god knows what else.) are unacknowledged by hardware.  They may be  * written as anything, but otherwise they have as much meaning as  * other 0 fields.  */
end_comment

begin_define
define|#
directive|define
name|TLBLO_SWBITS_SHIFT
value|(30)
end_define

begin_define
define|#
directive|define
name|TLBLO_SWBITS_MASK
value|(0x3U<< TLBLO_SWBITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLBLO_PFN_SHIFT
value|(6)
end_define

begin_define
define|#
directive|define
name|TLBLO_PFN_MASK
value|(0x3FFFFFC0)
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
comment|/*  * VM flags managed in software:  * 	RO:	Read only.  Never set PTE_D on this page, and don't  * 		listen to requests to write to it.  * 	W:	Wired.  ???  */
end_comment

begin_define
define|#
directive|define
name|PTE_RO
value|(0x01<< TLBLO_SWBITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PTE_W
value|(0x02<< TLBLO_SWBITS_SHIFT)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PTE_H_ */
end_comment

end_unit

