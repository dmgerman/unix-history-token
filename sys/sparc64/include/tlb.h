begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|TLB_DIRECT_ADDRESS_BITS
value|(43)
end_define

begin_define
define|#
directive|define
name|TLB_DIRECT_PAGE_BITS
value|(PAGE_SHIFT_4M)
end_define

begin_define
define|#
directive|define
name|TLB_DIRECT_ADDRESS_MASK
value|((1UL<< TLB_DIRECT_ADDRESS_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|TLB_DIRECT_PAGE_MASK
value|((1UL<< TLB_DIRECT_PAGE_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|TLB_PHYS_TO_DIRECT
parameter_list|(
name|pa
parameter_list|)
define|\
value|((pa) | VM_MIN_DIRECT_ADDRESS)
end_define

begin_define
define|#
directive|define
name|TLB_DIRECT_TO_PHYS
parameter_list|(
name|va
parameter_list|)
define|\
value|((va)& TLB_DIRECT_ADDRESS_MASK)
end_define

begin_define
define|#
directive|define
name|TLB_DIRECT_TO_TTE_MASK
define|\
value|(TD_V | TD_4M | (TLB_DIRECT_ADDRESS_MASK - TLB_DIRECT_PAGE_MASK))
end_define

begin_define
define|#
directive|define
name|TLB_DAR_SLOT_SHIFT
value|(3)
end_define

begin_define
define|#
directive|define
name|TLB_DAR_SLOT
parameter_list|(
name|slot
parameter_list|)
value|((slot)<< TLB_DAR_SLOT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TAR_VPN_SHIFT
value|(13)
end_define

begin_define
define|#
directive|define
name|TAR_CTX_MASK
value|((1<< TAR_VPN_SHIFT) - 1)
end_define

begin_define
define|#
directive|define
name|TLB_TAR_VA
parameter_list|(
name|va
parameter_list|)
value|((va)& ~TAR_CTX_MASK)
end_define

begin_define
define|#
directive|define
name|TLB_TAR_CTX
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)& TAR_CTX_MASK)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_ID_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_ID_PRIMARY
value|(0)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_ID_SECONDARY
value|(1)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_ID_NUCLEUS
value|(2)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_TYPE_SHIFT
value|(6)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_TYPE_PAGE
value|(0)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_TYPE_CONTEXT
value|(1)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_VA
parameter_list|(
name|va
parameter_list|)
value|((va)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_ID
parameter_list|(
name|id
parameter_list|)
value|((id)<< TLB_DEMAP_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_TYPE
parameter_list|(
name|type
parameter_list|)
value|((type)<< TLB_DEMAP_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_PAGE
value|(TLB_DEMAP_TYPE(TLB_DEMAP_TYPE_PAGE))
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_CONTEXT
value|(TLB_DEMAP_TYPE(TLB_DEMAP_TYPE_CONTEXT))
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_PRIMARY
value|(TLB_DEMAP_ID(TLB_DEMAP_ID_PRIMARY))
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_SECONDARY
value|(TLB_DEMAP_ID(TLB_DEMAP_ID_SECONDARY))
end_define

begin_define
define|#
directive|define
name|TLB_DEMAP_NUCLEUS
value|(TLB_DEMAP_ID(TLB_DEMAP_ID_NUCLEUS))
end_define

begin_define
define|#
directive|define
name|TLB_CTX_KERNEL
value|(0)
end_define

begin_define
define|#
directive|define
name|TLB_CTX_USER_MIN
value|(1)
end_define

begin_define
define|#
directive|define
name|TLB_CTX_USER_MAX
value|(8192)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_ASI_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_FT_SHIFT
value|(7)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_E_SHIFT
value|(6)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_CT_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_PR_SHIFT
value|(3)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_W_SHIFT
value|(2)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_OW_SHIFT
value|(1)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_FV_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_ASI_SIZE
value|(8)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_FT_SIZE
value|(6)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_CT_SIZE
value|(2)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_GET_ASI
parameter_list|(
name|sfsr
parameter_list|)
define|\
value|(((sfsr)>> MMU_SFSR_ASI_SHIFT)& ((1UL<< MMU_SFSR_ASI_SIZE) - 1))
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_W
value|(1UL<< MMU_SFSR_W_SHIFT)
end_define

begin_define
define|#
directive|define
name|MMU_SFSR_FV
value|(1UL<< MMU_SFSR_FV_SHIFT)
end_define

begin_typedef
typedef|typedef
name|void
name|tlb_flush_user_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tlb_entry
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|kernel_tlb_slots
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tlb_entry
modifier|*
name|kernel_tlbs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|tlb_context_demap
parameter_list|(
name|struct
name|pmap
modifier|*
name|pm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb_page_demap
parameter_list|(
name|struct
name|pmap
modifier|*
name|pm
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb_range_demap
parameter_list|(
name|struct
name|pmap
modifier|*
name|pm
parameter_list|,
name|vm_offset_t
name|start
parameter_list|,
name|vm_offset_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|tlb_flush_user_t
name|cheetah_tlb_flush_user
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tlb_flush_user_t
name|spitfire_tlb_flush_user
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tlb_flush_user_t
modifier|*
name|tlb_flush_user
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TLB_H_ */
end_comment

end_unit

