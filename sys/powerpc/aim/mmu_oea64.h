begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2010 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_AIM_MMU_OEA64_H
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_AIM_MMU_OEA64_H
end_define

begin_include
include|#
directive|include
file|<machine/mmuvar.h>
end_include

begin_decl_stmt
specifier|extern
name|mmu_def_t
name|oea64_mmu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Helper routines  */
end_comment

begin_comment
comment|/* Allocate physical memory for use in moea64_bootstrap. */
end_comment

begin_function_decl
name|vm_offset_t
name|moea64_bootstrap_alloc
parameter_list|(
name|vm_size_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set an LPTE structure to match the contents of a PVO */
end_comment

begin_function_decl
name|void
name|moea64_pte_from_pvo
parameter_list|(
specifier|const
name|struct
name|pvo_entry
modifier|*
name|pvo
parameter_list|,
name|struct
name|lpte
modifier|*
name|lpte
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Flags  */
end_comment

begin_define
define|#
directive|define
name|MOEA64_PTE_PROT_UPDATE
value|1
end_define

begin_define
define|#
directive|define
name|MOEA64_PTE_INVALIDATE
value|2
end_define

begin_comment
comment|/*  * Bootstrap subroutines  *  * An MMU_BOOTSTRAP() implementation looks like this:  *   moea64_early_bootstrap();  *   Allocate Page Table  *   moea64_mid_bootstrap();  *   Add mappings for MMU resources  *   moea64_late_bootstrap();  */
end_comment

begin_function_decl
name|void
name|moea64_early_bootstrap
parameter_list|(
name|mmu_t
name|mmup
parameter_list|,
name|vm_offset_t
name|kernelstart
parameter_list|,
name|vm_offset_t
name|kernelend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|moea64_mid_bootstrap
parameter_list|(
name|mmu_t
name|mmup
parameter_list|,
name|vm_offset_t
name|kernelstart
parameter_list|,
name|vm_offset_t
name|kernelend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|moea64_late_bootstrap
parameter_list|(
name|mmu_t
name|mmup
parameter_list|,
name|vm_offset_t
name|kernelstart
parameter_list|,
name|vm_offset_t
name|kernelend
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Statistics  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|moea64_pte_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|moea64_pte_overflow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * State variables  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|moea64_large_page_shift
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|moea64_large_page_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|moea64_pteg_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|moea64_pteg_mask
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_AIM_MMU_OEA64_H */
end_comment

end_unit

