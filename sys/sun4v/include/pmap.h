begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: hp300: @(#)pmap.h 7.2 (Berkeley) 12/16/90  *	from: @(#)pmap.h        7.4 (Berkeley) 5/12/91  *	from: FreeBSD: src/sys/i386/include/pmap.h,v 1.70 2000/11/30  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PMAP_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/cache.h>
end_include

begin_include
include|#
directive|include
file|<machine/hypervisorvar.h>
end_include

begin_define
define|#
directive|define
name|PMAP_CONTEXT_MAX
value|8192
end_define

begin_typedef
typedef|typedef
name|struct
name|pmap
modifier|*
name|pmap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|pmap_cpumask_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|pv_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tte_hash
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|md_page
block|{
name|int
name|pv_list_count
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_entry
argument_list|)
name|pv_list
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmap
block|{
name|uint64_t
name|pm_context
decl_stmt|;
name|uint64_t
name|pm_hashscratch
decl_stmt|;
name|uint64_t
name|pm_tsbscratch
decl_stmt|;
name|vm_paddr_t
name|pm_tsb_ra
decl_stmt|;
name|struct
name|mtx
name|pm_mtx
decl_stmt|;
name|struct
name|tte_hash
modifier|*
name|pm_hash
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_entry
argument_list|)
name|pm_pvlist
expr_stmt|;
comment|/* list of mappings in pmap */
name|struct
name|hv_tsb_info
name|pm_tsb
decl_stmt|;
name|pmap_cpumask_t
name|pm_active
decl_stmt|;
comment|/* mask of cpus currently using pmap */
name|pmap_cpumask_t
name|pm_tlbactive
decl_stmt|;
comment|/* mask of cpus that have used this pmap */
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
name|uint32_t
name|pm_tsb_miss_count
decl_stmt|;
name|uint32_t
name|pm_tsb_cap_miss_count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMAP_LOCK
parameter_list|(
name|pmap
parameter_list|)
value|mtx_lock(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_LOCK_ASSERT
parameter_list|(
name|pmap
parameter_list|,
name|type
parameter_list|)
define|\
value|mtx_assert(&(pmap)->pm_mtx, (type))
end_define

begin_define
define|#
directive|define
name|PMAP_LOCK_DESTROY
parameter_list|(
name|pmap
parameter_list|)
value|mtx_destroy(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_LOCK_INIT
parameter_list|(
name|pmap
parameter_list|)
value|mtx_init(&(pmap)->pm_mtx, "pmap", \ 				    NULL, MTX_DEF | MTX_DUPOK)
end_define

begin_define
define|#
directive|define
name|PMAP_LOCKED
parameter_list|(
name|pmap
parameter_list|)
value|mtx_owned(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_MTX
parameter_list|(
name|pmap
parameter_list|)
value|(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_TRYLOCK
parameter_list|(
name|pmap
parameter_list|)
value|mtx_trylock(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_UNLOCK
parameter_list|(
name|pmap
parameter_list|)
value|mtx_unlock(&(pmap)->pm_mtx)
end_define

begin_comment
comment|/*  * For each vm_page_t, there is a list of all currently valid virtual  * mappings of that page.  An entry is a pv_entry_t, the list is pv_list.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pv_entry
block|{
name|pmap_t
name|pv_pmap
decl_stmt|;
name|vm_offset_t
name|pv_va
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pv_entry
argument_list|)
name|pv_list
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pv_entry
argument_list|)
name|pv_plist
expr_stmt|;
block|}
typedef|*
name|pv_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|pmap_page_is_mapped
parameter_list|(
name|m
parameter_list|)
value|(!TAILQ_EMPTY(&(m)->md.pv_list))
end_define

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|(
name|vm_offset_t
name|ekva
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|pmap_kextract
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_invalidate_page
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|int
name|cleartsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_invalidate_range
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|sva
parameter_list|,
name|vm_offset_t
name|eva
parameter_list|,
name|int
name|cleartsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_invalidate_all
parameter_list|(
name|pmap_t
name|pmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_scrub_pages
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|int64_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_free_contig_pages
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|npages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pmap_alloc_zeroed_contig_pages
parameter_list|(
name|int
name|npages
parameter_list|,
name|uint64_t
name|alignment
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|pmap_kextract((vm_offset_t)(va))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|pmap
name|kernel_pmap_store
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|kernel_pmap
value|(&kernel_pmap_store)
end_define

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|phys_avail
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|virtual_avail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|virtual_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|msgbuf_phys
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|int
name|pmap_track_modified
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
block|{
if|if
condition|(
name|pm
operator|==
name|kernel_pmap
condition|)
return|return
operator|(
operator|(
name|va
operator|<
name|kmi
operator|.
name|clean_sva
operator|)
operator|||
operator|(
name|va
operator|>=
name|kmi
operator|.
name|clean_eva
operator|)
operator|)
return|;
else|else
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PMAP_H_ */
end_comment

end_unit

