begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2006-2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TLB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TLB_H_
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
comment|/*  PowerPC E500 MAS registers */
end_comment

begin_define
define|#
directive|define
name|MAS0_TLBSEL
parameter_list|(
name|x
parameter_list|)
value|((x<< 28)& 0x10000000)
end_define

begin_define
define|#
directive|define
name|MAS0_ESEL
parameter_list|(
name|x
parameter_list|)
value|((x<< 16)& 0x000F0000)
end_define

begin_define
define|#
directive|define
name|MAS0_TLBSEL1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MAS0_TLBSEL0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MAS0_ESEL_TLB1MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|MAS0_ESEL_TLB0MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|MAS0_ESEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MAS0_NV_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|MAS0_NV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MAS1_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MAS1_IPROT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MAS1_TID_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|MAS1_TID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MAS1_TS_MASK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MAS1_TS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MAS1_TSIZE_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|MAS1_TSIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_4K
value|1
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_16K
value|2
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_64K
value|3
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_256K
value|4
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_1M
value|5
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_4M
value|6
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_16M
value|7
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_64M
value|8
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_256M
value|9
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_1G
value|10
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_4G
value|11
end_define

begin_define
define|#
directive|define
name|MAS2_EPN_MASK
value|0xFFFFF000
end_define

begin_define
define|#
directive|define
name|MAS2_EPN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MAS2_X0
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MAS2_X1
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MAS2_W
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MAS2_I
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MAS2_M
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MAS2_G
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MAS2_E
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MAS3_RPN
value|0xFFFFF000
end_define

begin_define
define|#
directive|define
name|MAS3_RPN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MAS3_U0
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MAS3_U1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MAS3_U2
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MAS3_U3
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MAS3_UX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MAS3_SX
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MAS3_UW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MAS3_SW
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MAS3_UR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MAS3_SR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MAS4_TLBSELD1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MAS4_TLBSELD0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MAS4_TIDSELD_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|MAS4_TIDSELD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MAS4_TSIZED_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|MAS4_TSIZED_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MAS4_X0D
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MAS4_X1D
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MAS4_WD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MAS4_ID
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MAS4_MD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MAS4_GD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MAS4_ED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MAS6_SPID0_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|MAS6_SPID0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MAS6_SAS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MAS1_GETTID
parameter_list|(
name|mas1
parameter_list|)
value|(((mas1)& MAS1_TID_MASK)>> MAS1_TID_SHIFT)
end_define

begin_define
define|#
directive|define
name|MAS2_TLB0_ENTRY_IDX_MASK
value|0x0007f000
end_define

begin_define
define|#
directive|define
name|MAS2_TLB0_ENTRY_IDX_SHIFT
value|12
end_define

begin_comment
comment|/*  * Maximum number of TLB1 entries used for a permanent mapping of kernel  * region (kernel image plus statically allocated data).  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_REGION_MAX_TLB_ENTRIES
value|4
end_define

begin_define
define|#
directive|define
name|_TLB_ENTRY_IO
value|(MAS2_I | MAS2_G)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|_TLB_ENTRY_MEM
value|(MAS2_M)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_TLB_ENTRY_MEM
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
name|tlb_entry
block|{
name|vm_paddr_t
name|phys
decl_stmt|;
name|vm_offset_t
name|virt
decl_stmt|;
name|vm_size_t
name|size
decl_stmt|;
name|uint32_t
name|mas1
decl_stmt|;
name|uint32_t
name|mas2
decl_stmt|;
name|uint32_t
name|mas3
decl_stmt|;
block|}
name|tlb_entry_t
typedef|;
end_typedef

begin_function_decl
name|void
name|tlb0_print_tlbentries
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb1_inval_entry
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb1_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb1_print_entries
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb1_print_tlbentries
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|BOOKE_PPC4XX
argument_list|)
end_elif

begin_comment
comment|/* TLB Words */
end_comment

begin_define
define|#
directive|define
name|TLB_PAGEID
value|0
end_define

begin_define
define|#
directive|define
name|TLB_XLAT
value|1
end_define

begin_define
define|#
directive|define
name|TLB_ATTRIB
value|2
end_define

begin_comment
comment|/* Page identification fields */
end_comment

begin_define
define|#
directive|define
name|TLB_EPN_MASK
value|(0xFFFFFC00>> 0)
end_define

begin_define
define|#
directive|define
name|TLB_VALID
value|(0x80000000>> 22)
end_define

begin_define
define|#
directive|define
name|TLB_TS
value|(0x80000000>> 23)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_1K
value|(0x00000000>> 24)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_MASK
value|(0xF0000000>> 24)
end_define

begin_comment
comment|/* Translation fields */
end_comment

begin_define
define|#
directive|define
name|TLB_RPN_MASK
value|(0xFFFFFC00>> 0)
end_define

begin_define
define|#
directive|define
name|TLB_ERPN_MASK
value|(0xF0000000>> 28)
end_define

begin_comment
comment|/* Storage attribute and access control fields */
end_comment

begin_define
define|#
directive|define
name|TLB_WL1
value|(0x80000000>> 11)
end_define

begin_define
define|#
directive|define
name|TLB_IL1I
value|(0x80000000>> 12)
end_define

begin_define
define|#
directive|define
name|TLB_IL1D
value|(0x80000000>> 13)
end_define

begin_define
define|#
directive|define
name|TLB_IL2I
value|(0x80000000>> 14)
end_define

begin_define
define|#
directive|define
name|TLB_IL2D
value|(0x80000000>> 15)
end_define

begin_define
define|#
directive|define
name|TLB_U0
value|(0x80000000>> 16)
end_define

begin_define
define|#
directive|define
name|TLB_U1
value|(0x80000000>> 17)
end_define

begin_define
define|#
directive|define
name|TLB_U2
value|(0x80000000>> 18)
end_define

begin_define
define|#
directive|define
name|TLB_U3
value|(0x80000000>> 19)
end_define

begin_define
define|#
directive|define
name|TLB_W
value|(0x80000000>> 20)
end_define

begin_define
define|#
directive|define
name|TLB_I
value|(0x80000000>> 21)
end_define

begin_define
define|#
directive|define
name|TLB_M
value|(0x80000000>> 22)
end_define

begin_define
define|#
directive|define
name|TLB_G
value|(0x80000000>> 23)
end_define

begin_define
define|#
directive|define
name|TLB_E
value|(0x80000000>> 24)
end_define

begin_define
define|#
directive|define
name|TLB_UX
value|(0x80000000>> 26)
end_define

begin_define
define|#
directive|define
name|TLB_UW
value|(0x80000000>> 27)
end_define

begin_define
define|#
directive|define
name|TLB_UR
value|(0x80000000>> 28)
end_define

begin_define
define|#
directive|define
name|TLB_SX
value|(0x80000000>> 29)
end_define

begin_define
define|#
directive|define
name|TLB_SW
value|(0x80000000>> 30)
end_define

begin_define
define|#
directive|define
name|TLB_SR
value|(0x80000000>> 31)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_4K
value|(0x10000000>> 24)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_16K
value|(0x20000000>> 24)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_64K
value|(0x30000000>> 24)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_256K
value|(0x40000000>> 24)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_1M
value|(0x50000000>> 24)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_16M
value|(0x70000000>> 24)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_256M
value|(0x90000000>> 24)
end_define

begin_define
define|#
directive|define
name|TLB_SIZE_1G
value|(0xA0000000>> 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BOOKE_E500 */
end_comment

begin_define
define|#
directive|define
name|TID_KERNEL
value|0
end_define

begin_comment
comment|/* TLB TID to use for kernel (shared) translations */
end_comment

begin_define
define|#
directive|define
name|TID_KRESERVED
value|1
end_define

begin_comment
comment|/* Number of TIDs reserved for kernel */
end_comment

begin_define
define|#
directive|define
name|TID_URESERVED
value|0
end_define

begin_comment
comment|/* Number of TIDs reserved for user */
end_comment

begin_define
define|#
directive|define
name|TID_MIN
value|(TID_KRESERVED + TID_URESERVED)
end_define

begin_define
define|#
directive|define
name|TID_MAX
value|255
end_define

begin_define
define|#
directive|define
name|TID_NONE
value|-1
end_define

begin_define
define|#
directive|define
name|TLB_UNLOCKED
value|0
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
name|tlbtid_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|tlb_lock
parameter_list|(
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb_unlock
parameter_list|(
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _MACHINE_TLB_H_ */
end_comment

end_unit

