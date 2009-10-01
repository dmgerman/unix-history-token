begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Derived from hp300 version by Mike Hibler, this version by William  * Jolitz uses a recursive map [a pde points to the page directory] to  * map the page tables using the pagetables themselves. This is done to  * reduce the impact on kernel virtual memory for lots of sparse address  * space, and to reduce the cost of memory to each process.  *  *	from: hp300: @(#)pmap.h 7.2 (Berkeley) 12/16/90  *	from: @(#)pmap.h	7.4 (Berkeley) 5/12/91  *	from: src/sys/i386/include/pmap.h,v 1.65.2.2 2000/11/30 01:54:42 peter  *	JNPR: pmap.h,v 1.7.2.1 2007/09/10 07:44:12 girish  *      $FreeBSD$  */
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
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_define
define|#
directive|define
name|VADDR
parameter_list|(
name|pdi
parameter_list|,
name|pti
parameter_list|)
value|((vm_offset_t)(((pdi)<<PDRSHIFT)|((pti)<<PAGE_SHIFT)))
end_define

begin_define
define|#
directive|define
name|NKPT
value|120
end_define

begin_comment
comment|/* actual number of kernel page tables */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NKPDE
end_ifndef

begin_define
define|#
directive|define
name|NKPDE
value|255
end_define

begin_comment
comment|/* addressable number of page tables/pde's */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KPTDI
value|(VM_MIN_KERNEL_ADDRESS>> SEGSHIFT)
end_define

begin_define
define|#
directive|define
name|NUSERPGTBLS
value|(VM_MAXUSER_ADDRESS>> SEGSHIFT)
end_define

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

begin_comment
comment|/*  * Pmap stuff  */
end_comment

begin_struct_decl
struct_decl|struct
name|pv_entry
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|md_page
block|{
name|int
name|pv_list_count
decl_stmt|;
name|int
name|pv_flags
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

begin_define
define|#
directive|define
name|PV_TABLE_MOD
value|0x01
end_define

begin_comment
comment|/* modified */
end_comment

begin_define
define|#
directive|define
name|PV_TABLE_REF
value|0x02
end_define

begin_comment
comment|/* referenced */
end_comment

begin_define
define|#
directive|define
name|ASID_BITS
value|8
end_define

begin_define
define|#
directive|define
name|ASIDGEN_BITS
value|(32 - ASID_BITS)
end_define

begin_define
define|#
directive|define
name|ASIDGEN_MASK
value|((1<< ASIDGEN_BITS) - 1)
end_define

begin_struct
struct|struct
name|pmap
block|{
name|pd_entry_t
modifier|*
name|pm_segtab
decl_stmt|;
comment|/* KVA of segment table */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_entry
argument_list|)
name|pm_pvlist
expr_stmt|;
comment|/* list of mappings in 						 * pmap */
name|int
name|pm_active
decl_stmt|;
comment|/* active on cpus */
struct|struct
block|{
name|u_int32_t
name|asid
range|:
name|ASID_BITS
decl_stmt|;
comment|/* TLB address space tag */
name|u_int32_t
name|gen
range|:
name|ASIDGEN_BITS
decl_stmt|;
comment|/* its generation number */
block|}
name|pm_asid
index|[
name|MAXSMPCPU
index|]
struct|;
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statistics */
name|struct
name|vm_page
modifier|*
name|pm_ptphint
decl_stmt|;
comment|/* pmap ptp hint */
name|struct
name|mtx
name|pm_mtx
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

begin_function_decl
name|pt_entry_t
modifier|*
name|pmap_pte
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pd_entry_t
name|pmap_segmap
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
name|vm_offset_t
name|pmap_kextract
parameter_list|(
name|vm_offset_t
name|va
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
value|pmap_kextract(((vm_offset_t) (va)))
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
value|mtx_init(&(pmap)->pm_mtx, "pmap", \ 				    NULL, MTX_DEF)
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

begin_define
define|#
directive|define
name|PMAP_LGMEM_LOCK_INIT
parameter_list|(
name|sysmap
parameter_list|)
value|mtx_init(&(sysmap)->lock, "pmap-lgmem", \ 				    "per-cpu-map", (MTX_DEF| MTX_DUPOK))
end_define

begin_define
define|#
directive|define
name|PMAP_LGMEM_LOCK
parameter_list|(
name|sysmap
parameter_list|)
value|mtx_lock(&(sysmap)->lock)
end_define

begin_define
define|#
directive|define
name|PMAP_LGMEM_UNLOCK
parameter_list|(
name|sysmap
parameter_list|)
value|mtx_unlock(&(sysmap)->lock)
end_define

begin_define
define|#
directive|define
name|PMAP_LGMEM_DESTROY
parameter_list|(
name|sysmap
parameter_list|)
value|mtx_destroy(&(sysmap)->lock)
end_define

begin_comment
comment|/*  * For each vm_page_t, there is a list of all currently valid virtual  * mappings of that page.  An entry is a pv_entry_t, the list is pv_table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pv_entry
block|{
name|pmap_t
name|pv_pmap
decl_stmt|;
comment|/* pmap where mapping lies */
name|vm_offset_t
name|pv_va
decl_stmt|;
comment|/* virtual address for mapping */
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
name|vm_page_t
name|pv_ptem
decl_stmt|;
comment|/* VM page for pte */
name|boolean_t
name|pv_wired
decl_stmt|;
comment|/* whether this entry is wired */
block|}
typedef|*
name|pv_entry_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DIAGNOSTIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|PMAP_DIAGNOSTIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|phys_avail
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ptvmmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* poor name! */
end_comment

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
name|pd_entry_t
modifier|*
name|segbase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|mips_wired_tlb_physmem_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|mips_wired_tlb_physmem_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|need_wired_tlb_page_pool
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pmap_page_get_memattr
parameter_list|(
name|m
parameter_list|)
value|VM_MEMATTR_DEFAULT
end_define

begin_define
define|#
directive|define
name|pmap_page_is_mapped
parameter_list|(
name|m
parameter_list|)
value|(!TAILQ_EMPTY(&(m)->md.pv_list))
end_define

begin_define
define|#
directive|define
name|pmap_page_set_memattr
parameter_list|(
name|m
parameter_list|,
name|ma
parameter_list|)
value|(void)0
end_define

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|(
name|void
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
name|pmap_unmapdev
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|pmap_steal_memory
parameter_list|(
name|vm_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_set_modified
parameter_list|(
name|vm_offset_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|page_is_managed
parameter_list|(
name|vm_offset_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_page_is_free
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kenter
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kremove
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pmap_kenter_temporary
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kenter_temporary_free
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmap_compute_pages_to_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_update_page
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|pt_entry_t
name|pte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_flush_pvcache
parameter_list|(
name|vm_page_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * floating virtual pages (FPAGES)  *  * These are the reserved virtual memory areas which can be  * mapped to any physical memory.  */
end_comment

begin_define
define|#
directive|define
name|FPAGES
value|2
end_define

begin_define
define|#
directive|define
name|FPAGES_SHARED
value|2
end_define

begin_define
define|#
directive|define
name|FSPACE
value|((FPAGES * MAXCPU + FPAGES_SHARED)  * PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|PMAP_FPAGE1
value|0x00
end_define

begin_comment
comment|/* Used by pmap_zero_page& 					 * pmap_copy_page */
end_comment

begin_define
define|#
directive|define
name|PMAP_FPAGE2
value|0x01
end_define

begin_comment
comment|/* Used by pmap_copy_page */
end_comment

begin_define
define|#
directive|define
name|PMAP_FPAGE3
value|0x00
end_define

begin_comment
comment|/* Used by pmap_zero_page_idle */
end_comment

begin_define
define|#
directive|define
name|PMAP_FPAGE_KENTER_TEMP
value|0x01
end_define

begin_comment
comment|/* Used by coredump */
end_comment

begin_struct
struct|struct
name|fpage
block|{
name|vm_offset_t
name|kva
decl_stmt|;
name|u_int
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sysmaps
block|{
name|struct
name|mtx
name|lock
decl_stmt|;
name|struct
name|fpage
name|fp
index|[
name|FPAGES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|vm_offset_t
name|pmap_map_fpage
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|struct
name|fpage
modifier|*
name|fp
parameter_list|,
name|boolean_t
name|check_unmaped
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_unmap_fpage
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|struct
name|fpage
modifier|*
name|fp
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

