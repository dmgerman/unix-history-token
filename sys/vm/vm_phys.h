begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2006 Rice University  * Copyright (c) 2007 Alan L. Cox<alc@cs.rice.edu>  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Alan L. Cox,  * Olivier Crameri, Peter Druschel, Sitaram Iyer, and Juan Navarro.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY  * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Physical memory system definitions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_PHYS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VM_PHYS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Domains must be dense (non-sparse) and zero-based. */
end_comment

begin_struct
struct|struct
name|mem_affinity
block|{
name|vm_paddr_t
name|start
decl_stmt|;
name|vm_paddr_t
name|end
decl_stmt|;
name|int
name|domain
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|mem_affinity
modifier|*
name|mem_affinity
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The following functions are only to be used by the virtual memory system.  */
end_comment

begin_function_decl
name|void
name|vm_phys_add_page
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_phys_alloc_contig
parameter_list|(
name|u_long
name|npages
parameter_list|,
name|vm_paddr_t
name|low
parameter_list|,
name|vm_paddr_t
name|high
parameter_list|,
name|u_long
name|alignment
parameter_list|,
name|u_long
name|boundary
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_phys_alloc_freelist_pages
parameter_list|(
name|int
name|flind
parameter_list|,
name|int
name|pool
parameter_list|,
name|int
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_phys_alloc_pages
parameter_list|(
name|int
name|pool
parameter_list|,
name|int
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_phys_free_contig
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|u_long
name|npages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_phys_fictitious_reg_range
parameter_list|(
name|vm_paddr_t
name|start
parameter_list|,
name|vm_paddr_t
name|end
parameter_list|,
name|vm_memattr_t
name|memattr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_phys_fictitious_unreg_range
parameter_list|(
name|vm_paddr_t
name|start
parameter_list|,
name|vm_paddr_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_phys_fictitious_to_vm_page
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_phys_free_pages
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|int
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_phys_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_phys_set_pool
parameter_list|(
name|int
name|pool
parameter_list|,
name|vm_page_t
name|m
parameter_list|,
name|int
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_phys_unfree_page
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_phys_zero_pages_idle
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VM_PHYS_H_ */
end_comment

end_unit

