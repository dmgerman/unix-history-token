begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2014 Svatopluk Kraus<onwahe@gmail.com>  * Copyright 2014 Michal Meloun<meloun@miracle.cz>  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The ARM version of this file was more or less based on the i386 version,  * which has the following provenance...  *  * Derived from hp300 version by Mike Hibler, this version by William  * Jolitz uses a recursive map [a pde points to the page directory] to  * map the page tables using the pagetables themselves. This is done to  * reduce the impact on kernel virtual memory for lots of sparse address  * space, and to reduce the cost of memory to each process.  *  *      from: hp300: @(#)pmap.h 7.2 (Berkeley) 12/16/90  *      from: @(#)pmap.h        7.4 (Berkeley) 5/12/91  * 	from: FreeBSD: src/sys/i386/include/pmap.h,v 1.70 2000/11/30  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PMAP_V6_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PMAP_V6_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
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

begin_typedef
typedef|typedef
name|uint32_t
name|pt1_entry_t
typedef|;
end_typedef

begin_comment
comment|/* L1 table entry */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|pt2_entry_t
typedef|;
end_typedef

begin_comment
comment|/* L2 table entry */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ttb_entry_t
typedef|;
end_typedef

begin_comment
comment|/* TTB entry */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|PMAP_PTE_NOCACHE
end_define

begin_comment
comment|// Use uncached page tables
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  (1) During pmap bootstrap, physical pages for L2 page tables are  *      allocated in advance which are used for KVA continuous mapping  *      starting from KERNBASE. This makes things more simple.  *  (2) During vm subsystem initialization, only vm subsystem itself can  *      allocate physical memory safely. As pmap_map() is called during  *      this initialization, we must be prepared for that and have some  *      preallocated physical pages for L2 page tables.  *  *  Note that some more pages for L2 page tables are preallocated too  *  for mappings laying above VM_MAX_KERNEL_ADDRESS.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NKPT2PG
end_ifndef

begin_comment
comment|/*  *  The optimal way is to define this in board configuration as  *  definition here must be safe enough. It means really big.  *  *  1 GB KVA<=> 256 kernel L2 page table pages  *  *  From real platforms:  *	1 GB physical memory<=> 10 pages is enough  *	2 GB physical memory<=> 21 pages is enough  */
end_comment

begin_define
define|#
directive|define
name|NKPT2PG
value|32
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
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Pmap stuff  */
end_comment

begin_struct_decl
struct_decl|struct
name|pv_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pv_chunk
struct_decl|;
end_struct_decl

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
name|uint16_t
name|pt2_wirecount
index|[
literal|4
index|]
decl_stmt|;
name|vm_memattr_t
name|pat_mode
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
name|pt1_entry_t
modifier|*
name|pm_pt1
decl_stmt|;
comment|/* KVA of pt1 */
name|pt2_entry_t
modifier|*
name|pm_pt2tab
decl_stmt|;
comment|/* KVA of pt2 pages table */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_chunk
argument_list|)
name|pm_pvchunk
expr_stmt|;
comment|/* list of mappings in pmap */
name|cpuset_t
name|pm_active
decl_stmt|;
comment|/* active on cpus */
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statictics */
name|LIST_ENTRY
argument_list|(
argument|pmap
argument_list|)
name|pm_list
expr_stmt|;
comment|/* List of all pmaps */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For each vm_page_t, there is a list of all currently valid virtual  * mappings of that page.  An entry is a pv_entry_t, the list is pv_list.  */
end_comment

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
value|11
end_define

begin_define
define|#
directive|define
name|_NPCPV
value|336
end_define

begin_struct
struct|struct
name|pv_chunk
block|{
name|pmap_t
name|pc_pmap
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pv_chunk
argument_list|)
name|pc_list
expr_stmt|;
name|uint32_t
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|ttb_entry_t
name|pmap_kern_ttb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TTB for kernel pmap */
end_comment

begin_define
define|#
directive|define
name|pmap_page_get_memattr
parameter_list|(
name|m
parameter_list|)
value|((m)->md.pat_mode)
end_define

begin_comment
comment|/*  * Only the following functions or macros may be used before pmap_bootstrap()  * is called: pmap_kenter(), pmap_kextract(), pmap_kremove(), vtophys(), and  * vtopte2().  */
end_comment

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kenter
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_paddr_t
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
name|boolean_t
name|pmap_page_is_mapped
parameter_list|(
name|vm_page_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_tlb_flush
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_tlb_flush_range
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|pmap_dump_kextract
parameter_list|(
name|vm_offset_t
parameter_list|,
name|pt2_entry_t
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
name|vm_offset_t
parameter_list|,
name|uint32_t
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_set_tex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reinit_mmu
parameter_list|(
name|ttb_entry_t
name|ttb
parameter_list|,
name|u_int
name|aux_clr
parameter_list|,
name|u_int
name|aux_set
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Pre-bootstrap epoch functions set.  */
end_comment

begin_function_decl
name|void
name|pmap_bootstrap_prepare
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|pmap_preboot_get_pages
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_preboot_map_pages
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|pmap_preboot_reserve_pages
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|pmap_preboot_get_vpages
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_preboot_map_attr
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_memattr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_remap_vm_attr
parameter_list|(
name|vm_memattr_t
name|old_attr
parameter_list|,
name|vm_memattr_t
name|new_attr
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
comment|/* !_MACHINE_PMAP_V6_H_ */
end_comment

end_unit

