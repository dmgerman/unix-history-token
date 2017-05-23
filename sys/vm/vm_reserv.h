begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2006 Rice University  * Copyright (c) 2007-2008 Alan L. Cox<alc@cs.rice.edu>  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Alan L. Cox,  * Olivier Crameri, Peter Druschel, Sitaram Iyer, and Juan Navarro.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY  * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Superpage reservation management definitions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_RESERV_H_
end_ifndef

begin_define
define|#
directive|define
name|_VM_RESERV_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
name|VM_NRESERVLEVEL
operator|>
literal|0
end_if

begin_comment
comment|/*  * The following functions are only to be used by the virtual memory system.  */
end_comment

begin_function_decl
name|vm_page_t
name|vm_reserv_alloc_contig
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|vm_pindex_t
name|pindex
parameter_list|,
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
name|vm_paddr_t
name|boundary
parameter_list|,
name|vm_page_t
name|mpred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|vm_reserv_alloc_page
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|vm_pindex_t
name|pindex
parameter_list|,
name|vm_page_t
name|mpred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_reserv_break_all
parameter_list|(
name|vm_object_t
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_reserv_free_page
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_reserv_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|vm_reserv_is_page_free
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_reserv_level
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_reserv_level_iffullpop
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_reserv_reclaim_contig
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
name|vm_paddr_t
name|boundary
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|vm_reserv_reclaim_inactive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_reserv_rename
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|vm_object_t
name|new_object
parameter_list|,
name|vm_object_t
name|old_object
parameter_list|,
name|vm_pindex_t
name|old_object_offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_reserv_size
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|vm_reserv_startup
parameter_list|(
name|vm_offset_t
modifier|*
name|vaddr
parameter_list|,
name|vm_paddr_t
name|end
parameter_list|,
name|vm_paddr_t
name|high_water
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VM_NRESERVLEVEL> 0 */
end_comment

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
comment|/* !_VM_RESERV_H_ */
end_comment

end_unit

