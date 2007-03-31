begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)pmap.h	8.1 (Berkeley) 6/11/93  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Avadis Tevanian, Jr.  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Machine address mapping definitions -- machine-independent  *	section.  [For machine-dependent section, see "machine/pmap.h".]  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PMAP_VM_
end_ifndef

begin_define
define|#
directive|define
name|_PMAP_VM_
end_define

begin_comment
comment|/*  * Each machine dependent implementation is expected to  * keep certain statistics.  They may do this anyway they  * so choose, but are expected to return the statistics  * in the following structure.  */
end_comment

begin_struct
struct|struct
name|pmap_statistics
block|{
name|long
name|resident_count
decl_stmt|;
comment|/* # of pages mapped (total) */
name|long
name|wired_count
decl_stmt|;
comment|/* # of pages wired */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pmap_statistics
modifier|*
name|pmap_statistics_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Updates to kernel_vm_end are synchronized by the kernel_map's system mutex.  */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|kernel_vm_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pmap_pagedaemon_waken
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pmap_change_wiring
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_clear_modify
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_clear_reference
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_copy
parameter_list|(
name|pmap_t
parameter_list|,
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_copy_page
parameter_list|(
name|vm_page_t
parameter_list|,
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_enter
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_page_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|pmap_enter_quick
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|vm_page_t
name|m
parameter_list|,
name|vm_prot_t
name|prot
parameter_list|,
name|vm_page_t
name|mpte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_enter_object
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|start
parameter_list|,
name|vm_offset_t
name|end
parameter_list|,
name|vm_page_t
name|m_start
parameter_list|,
name|vm_prot_t
name|prot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|pmap_extract
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_page_t
name|pmap_extract_and_hold
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|vm_prot_t
name|prot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_growkernel
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|pmap_is_modified
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|pmap_is_prefaultable
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|pmap_ts_referenced
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|pmap_map
parameter_list|(
name|vm_offset_t
modifier|*
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_object_init_pt
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|addr
parameter_list|,
name|vm_object_t
name|object
parameter_list|,
name|vm_pindex_t
name|pindex
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|pmap_page_exists_quick
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_page_init
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_page_protect
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|vm_prot_t
name|prot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_pinit
parameter_list|(
name|pmap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_pinit0
parameter_list|(
name|pmap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_protect
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_prot_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_qenter
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_page_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_qremove
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_release
parameter_list|(
name|pmap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_remove
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_remove_all
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_remove_pages
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_zero_page
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_zero_page_area
parameter_list|(
name|vm_page_t
parameter_list|,
name|int
name|off
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_zero_page_idle
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmap_mincore
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_activate
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|pmap_addr_hint
parameter_list|(
name|vm_object_t
name|obj
parameter_list|,
name|vm_offset_t
name|addr
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_init2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pmap_resident_count
parameter_list|(
name|pm
parameter_list|)
value|((pm)->pm_stats.resident_count)
end_define

begin_define
define|#
directive|define
name|pmap_wired_count
parameter_list|(
name|pm
parameter_list|)
value|((pm)->pm_stats.wired_count)
end_define

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
comment|/* _PMAP_VM_ */
end_comment

end_unit

