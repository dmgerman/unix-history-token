begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<machine/pte.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|pmap_kextract((vm_offset_t)(va))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pmap_page_get_memattr
parameter_list|(
name|m
parameter_list|)
value|((m)->md.pv_memattr)
end_define

begin_define
define|#
directive|define
name|pmap_page_is_write_mapped
parameter_list|(
name|m
parameter_list|)
value|(((m)->aflags& PGA_WRITEABLE) != 0)
end_define

begin_function_decl
name|void
name|pmap_page_set_memattr
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|vm_memattr_t
name|ma
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Pmap stuff  */
end_comment

begin_struct
struct|struct
name|md_page
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_entry
argument_list|)
name|pv_list
expr_stmt|;
name|int
name|pv_gen
decl_stmt|;
name|vm_memattr_t
name|pv_memattr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure is used to hold a virtual<->physical address  * association and is used mostly by bootstrap code  */
end_comment

begin_struct
struct|struct
name|pv_addr
block|{
name|SLIST_ENTRY
argument_list|(
argument|pv_addr
argument_list|)
name|pv_list
expr_stmt|;
name|vm_offset_t
name|pv_va
decl_stmt|;
name|vm_paddr_t
name|pv_pa
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|mtx
name|pm_mtx
decl_stmt|;
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statictics */
name|pd_entry_t
modifier|*
name|pm_l0
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_chunk
argument_list|)
name|pm_pvchunk
expr_stmt|;
comment|/* list of mappings in pmap */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|pv_entry
block|{
name|vm_offset_t
name|pv_va
decl_stmt|;
comment|/* virtual address for mapping */
name|TAILQ_ENTRY
argument_list|(
argument|pv_entry
argument_list|)
name|pv_next
expr_stmt|;
block|}
typedef|*
name|pv_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * pv_entries are allocated in chunks per-process.  This avoids the  * need to track per-pmap assignments.  */
end_comment

begin_define
define|#
directive|define
name|_NPCM
value|3
end_define

begin_define
define|#
directive|define
name|_NPCPV
value|168
end_define

begin_struct
struct|struct
name|pv_chunk
block|{
name|struct
name|pmap
modifier|*
name|pc_pmap
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pv_chunk
argument_list|)
name|pc_list
expr_stmt|;
name|uint64_t
name|pc_map
index|[
name|_NPCM
index|]
decl_stmt|;
comment|/* bitmap; 1 = free */
name|TAILQ_ENTRY
argument_list|(
argument|pv_chunk
argument_list|)
name|pc_lru
expr_stmt|;
name|struct
name|pv_entry
name|pc_pventry
index|[
name|_NPCPV
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pmap
modifier|*
name|pmap_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_define
define|#
directive|define
name|pmap_kernel
parameter_list|()
value|kernel_pmap
end_define

begin_define
define|#
directive|define
name|PMAP_ASSERT_LOCKED
parameter_list|(
name|pmap
parameter_list|)
define|\
value|mtx_assert(&(pmap)->pm_mtx, MA_OWNED)
end_define

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
name|PMAP_OWNED
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

begin_define
define|#
directive|define
name|PHYS_AVAIL_SIZE
value|32
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
name|vm_paddr_t
name|dump_avail
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

begin_comment
comment|/*  * Macros to test if a mapping is mappable with an L1 Section mapping  * or an L2 Large Page mapping.  */
end_comment

begin_define
define|#
directive|define
name|L1_MAPPABLE_P
parameter_list|(
name|va
parameter_list|,
name|pa
parameter_list|,
name|size
parameter_list|)
define|\
value|((((va) | (pa))& L1_OFFSET) == 0&& (size)>= L1_SIZE)
end_define

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kenter_device
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_paddr_t
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
name|pmap_kremove
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kremove_device
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pmap_mapdev
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pmap_mapbios
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_unmapdev
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_unmapbios
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|pmap_map_io_transient
parameter_list|(
name|vm_page_t
modifier|*
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_unmap_io_transient
parameter_list|(
name|vm_page_t
modifier|*
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pmap_get_tables
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|pd_entry_t
modifier|*
modifier|*
parameter_list|,
name|pd_entry_t
modifier|*
modifier|*
parameter_list|,
name|pd_entry_t
modifier|*
modifier|*
parameter_list|,
name|pt_entry_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmap_fault
parameter_list|(
name|pmap_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pmap_page_is_mapped
parameter_list|(
name|m
parameter_list|)
value|(!TAILQ_EMPTY(&(m)->md.pv_list))
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
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PMAP_H_ */
end_comment

end_unit

