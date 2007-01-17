begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Derived from hp300 version by Mike Hibler, this version by William  * Jolitz uses a recursive map [a pde points to the page directory] to  * map the page tables using the pagetables themselves. This is done to  * reduce the impact on kernel virtual memory for lots of sparse address  * space, and to reduce the cost of memory to each process.  *  *      from: hp300: @(#)pmap.h 7.2 (Berkeley) 12/16/90  *      from: @(#)pmap.h        7.4 (Berkeley) 5/12/91  * 	from: FreeBSD: src/sys/i386/include/pmap.h,v 1.70 2000/11/30  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/cpuconf.h>
end_include

begin_comment
comment|/*  * Pte related macros  */
end_comment

begin_define
define|#
directive|define
name|PTE_NOCACHE
value|0
end_define

begin_define
define|#
directive|define
name|PTE_CACHE
value|1
end_define

begin_define
define|#
directive|define
name|PTE_PAGETABLE
value|2
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

begin_define
define|#
directive|define
name|PDESIZE
value|sizeof(pd_entry_t)
end_define

begin_comment
comment|/* for assembly files */
end_comment

begin_define
define|#
directive|define
name|PTESIZE
value|sizeof(pt_entry_t)
end_define

begin_comment
comment|/* for assembly files */
end_comment

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
value|pmap_extract(pmap_kernel(), (vm_offset_t)(va))
end_define

begin_define
define|#
directive|define
name|pmap_kextract
parameter_list|(
name|va
parameter_list|)
value|pmap_extract(pmap_kernel(), (vm_offset_t)(va))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pmap_page_is_mapped
parameter_list|(
name|m
parameter_list|)
value|(!TAILQ_EMPTY(&(m)->md.pv_list))
end_define

begin_comment
comment|/*  * Pmap stuff  */
end_comment

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
name|pvh_attrs
decl_stmt|;
name|u_int
name|uro_mappings
decl_stmt|;
name|u_int
name|urw_mappings
decl_stmt|;
union|union
block|{
name|u_short
name|s_mappings
index|[
literal|2
index|]
decl_stmt|;
comment|/* Assume kernel count<= 65535 */
name|u_int
name|i_mappings
decl_stmt|;
block|}
name|k_u
union|;
define|#
directive|define
name|kro_mappings
value|k_u.s_mappings[0]
define|#
directive|define
name|krw_mappings
value|k_u.s_mappings[1]
define|#
directive|define
name|k_mappings
value|k_u.i_mappings
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

begin_define
define|#
directive|define
name|VM_MDPAGE_INIT
parameter_list|(
name|pg
parameter_list|)
define|\
value|do {									\ 	TAILQ_INIT(&pg->pv_list);					\ 	mtx_init(&(pg)->md_page.pvh_mtx, "MDPAGE Mutex", NULL, MTX_DEV);\ 	(pg)->mdpage.pvh_attrs = 0;					\ 	(pg)->mdpage.uro_mappings = 0;					\ 	(pg)->mdpage.urw_mappings = 0;					\ 	(pg)->mdpage.k_mappings = 0;					\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_struct_decl
struct_decl|struct
name|l1_ttable
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|l2_dtable
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The number of L2 descriptor tables which can be tracked by an l2_dtable.  * A bucket size of 16 provides for 16MB of contiguous virtual address  * space per l2_dtable. Most processes will, therefore, require only two or  * three of these to map their whole working set.  */
end_comment

begin_define
define|#
directive|define
name|L2_BUCKET_LOG2
value|4
end_define

begin_define
define|#
directive|define
name|L2_BUCKET_SIZE
value|(1<< L2_BUCKET_LOG2)
end_define

begin_comment
comment|/*  * Given the above "L2-descriptors-per-l2_dtable" constant, the number  * of l2_dtable structures required to track all possible page descriptors  * mappable by an L1 translation table is given by the following constants:  */
end_comment

begin_define
define|#
directive|define
name|L2_LOG2
value|((32 - L1_S_SHIFT) - L2_BUCKET_LOG2)
end_define

begin_define
define|#
directive|define
name|L2_SIZE
value|(1<< L2_LOG2)
end_define

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|mtx
name|pm_mtx
decl_stmt|;
name|u_int8_t
name|pm_domain
decl_stmt|;
name|struct
name|l1_ttable
modifier|*
name|pm_l1
decl_stmt|;
name|struct
name|l2_dtable
modifier|*
name|pm_l2
index|[
name|L2_SIZE
index|]
decl_stmt|;
name|pd_entry_t
modifier|*
name|pm_pdir
decl_stmt|;
comment|/* KVA of page directory */
name|int
name|pm_count
decl_stmt|;
comment|/* reference count */
name|int
name|pm_active
decl_stmt|;
comment|/* active on cpus */
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statictics */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_entry
argument_list|)
name|pm_pvlist
expr_stmt|;
comment|/* list of mappings in pmap */
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
name|pmap_t
name|kernel_pmap
decl_stmt|;
end_decl_stmt

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
name|int
name|pv_flags
decl_stmt|;
comment|/* flags (wired, etc...) */
block|}
typedef|*
name|pv_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PV_ENTRY_NULL
value|((pv_entry_t) 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|boolean_t
name|pmap_get_pde_pte
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
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

begin_comment
comment|/*  * virtual address to page table entry and  * to physical address. Likewise for alternate address space.  * Note: these work recursively, thus vtopte of a pte will give  * the corresponding pde that in turn maps it.  */
end_comment

begin_comment
comment|/*  * The current top of kernel VM.  */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|pmap_curmaxkvaddr
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|pmap_set_pcb_pagedir
parameter_list|(
name|pmap_t
parameter_list|,
name|struct
name|pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Virtual address to page table entry */
end_comment

begin_function
specifier|static
name|__inline
name|pt_entry_t
modifier|*
name|vtopte
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
block|{
name|pd_entry_t
modifier|*
name|pdep
decl_stmt|;
name|pt_entry_t
modifier|*
name|ptep
decl_stmt|;
if|if
condition|(
name|pmap_get_pde_pte
argument_list|(
name|pmap_kernel
argument_list|()
argument_list|,
name|va
argument_list|,
operator|&
name|pdep
argument_list|,
operator|&
name|ptep
argument_list|)
operator|==
name|FALSE
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
return|return
operator|(
name|ptep
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|vm_offset_t
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

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|struct
name|pv_addr
modifier|*
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
name|pmap_kenter_nocache
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
name|pmap_kenter_user
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
name|vm_page_t
name|pmap_use_pt
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_debug
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_map_section
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_link_l2pt
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|struct
name|pv_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_size_t
name|pmap_map_chunk
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_map_entry
parameter_list|(
name|vm_offset_t
name|l1pt
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|vm_offset_t
name|pa
parameter_list|,
name|int
name|prot
parameter_list|,
name|int
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmap_fault_fixup
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Definitions for MMU domains  */
end_comment

begin_define
define|#
directive|define
name|PMAP_DOMAINS
value|15
end_define

begin_comment
comment|/* 15 'user' domains (0-14) */
end_comment

begin_define
define|#
directive|define
name|PMAP_DOMAIN_KERNEL
value|15
end_define

begin_comment
comment|/* The kernel uses domain #15 */
end_comment

begin_comment
comment|/*  * The new pmap ensures that page-tables are always mapping Write-Thru.  * Thus, on some platforms we can run fast and loose and avoid syncing PTEs  * on every change.  *  * Unfortunately, not all CPUs have a write-through cache mode.  So we  * define PMAP_NEEDS_PTE_SYNC for C code to conditionally do PTE syncs,  * and if there is the chance for PTE syncs to be needed, we define  * PMAP_INCLUDE_PTE_SYNC so e.g. assembly code can include (and run)  * the code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pmap_needs_pte_sync
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These macros define the various bit masks in the PTE.  *  * We use these macros since we use different bits on different processor  * models.  */
end_comment

begin_define
define|#
directive|define
name|L1_S_PROT_U
value|(L1_S_AP(AP_U))
end_define

begin_define
define|#
directive|define
name|L1_S_PROT_W
value|(L1_S_AP(AP_W))
end_define

begin_define
define|#
directive|define
name|L1_S_PROT_MASK
value|(L1_S_PROT_U|L1_S_PROT_W)
end_define

begin_define
define|#
directive|define
name|L1_S_CACHE_MASK_generic
value|(L1_S_B|L1_S_C)
end_define

begin_define
define|#
directive|define
name|L1_S_CACHE_MASK_xscale
value|(L1_S_B|L1_S_C|L1_S_XSCALE_TEX(TEX_XSCALE_X))
end_define

begin_define
define|#
directive|define
name|L2_L_PROT_U
value|(L2_AP(AP_U))
end_define

begin_define
define|#
directive|define
name|L2_L_PROT_W
value|(L2_AP(AP_W))
end_define

begin_define
define|#
directive|define
name|L2_L_PROT_MASK
value|(L2_L_PROT_U|L2_L_PROT_W)
end_define

begin_define
define|#
directive|define
name|L2_L_CACHE_MASK_generic
value|(L2_B|L2_C)
end_define

begin_define
define|#
directive|define
name|L2_L_CACHE_MASK_xscale
value|(L2_B|L2_C|L2_XSCALE_L_TEX(TEX_XSCALE_X))
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_U_generic
value|(L2_AP(AP_U))
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_W_generic
value|(L2_AP(AP_W))
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_MASK_generic
value|(L2_S_PROT_U|L2_S_PROT_W)
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_U_xscale
value|(L2_AP0(AP_U))
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_W_xscale
value|(L2_AP0(AP_W))
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_MASK_xscale
value|(L2_S_PROT_U|L2_S_PROT_W)
end_define

begin_define
define|#
directive|define
name|L2_S_CACHE_MASK_generic
value|(L2_B|L2_C)
end_define

begin_define
define|#
directive|define
name|L2_S_CACHE_MASK_xscale
value|(L2_B|L2_C|L2_XSCALE_T_TEX(TEX_XSCALE_X))
end_define

begin_define
define|#
directive|define
name|L1_S_PROTO_generic
value|(L1_TYPE_S | L1_S_IMP)
end_define

begin_define
define|#
directive|define
name|L1_S_PROTO_xscale
value|(L1_TYPE_S)
end_define

begin_define
define|#
directive|define
name|L1_C_PROTO_generic
value|(L1_TYPE_C | L1_C_IMP2)
end_define

begin_define
define|#
directive|define
name|L1_C_PROTO_xscale
value|(L1_TYPE_C)
end_define

begin_define
define|#
directive|define
name|L2_L_PROTO
value|(L2_TYPE_L)
end_define

begin_define
define|#
directive|define
name|L2_S_PROTO_generic
value|(L2_TYPE_S)
end_define

begin_define
define|#
directive|define
name|L2_S_PROTO_xscale
value|(L2_TYPE_XSCALE_XS)
end_define

begin_comment
comment|/*  * User-visible names for the ones that vary with MMU class.  */
end_comment

begin_if
if|#
directive|if
name|ARM_NMMUS
operator|>
literal|1
end_if

begin_comment
comment|/* More than one MMU class configured; use variables. */
end_comment

begin_define
define|#
directive|define
name|L2_S_PROT_U
value|pte_l2_s_prot_u
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_W
value|pte_l2_s_prot_w
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_MASK
value|pte_l2_s_prot_mask
end_define

begin_define
define|#
directive|define
name|L1_S_CACHE_MASK
value|pte_l1_s_cache_mask
end_define

begin_define
define|#
directive|define
name|L2_L_CACHE_MASK
value|pte_l2_l_cache_mask
end_define

begin_define
define|#
directive|define
name|L2_S_CACHE_MASK
value|pte_l2_s_cache_mask
end_define

begin_define
define|#
directive|define
name|L1_S_PROTO
value|pte_l1_s_proto
end_define

begin_define
define|#
directive|define
name|L1_C_PROTO
value|pte_l1_c_proto
end_define

begin_define
define|#
directive|define
name|L2_S_PROTO
value|pte_l2_s_proto
end_define

begin_elif
elif|#
directive|elif
operator|(
name|ARM_MMU_GENERIC
operator|+
name|ARM_MMU_SA1
operator|)
operator|!=
literal|0
end_elif

begin_define
define|#
directive|define
name|L2_S_PROT_U
value|L2_S_PROT_U_generic
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_W
value|L2_S_PROT_W_generic
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_MASK
value|L2_S_PROT_MASK_generic
end_define

begin_define
define|#
directive|define
name|L1_S_CACHE_MASK
value|L1_S_CACHE_MASK_generic
end_define

begin_define
define|#
directive|define
name|L2_L_CACHE_MASK
value|L2_L_CACHE_MASK_generic
end_define

begin_define
define|#
directive|define
name|L2_S_CACHE_MASK
value|L2_S_CACHE_MASK_generic
end_define

begin_define
define|#
directive|define
name|L1_S_PROTO
value|L1_S_PROTO_generic
end_define

begin_define
define|#
directive|define
name|L1_C_PROTO
value|L1_C_PROTO_generic
end_define

begin_define
define|#
directive|define
name|L2_S_PROTO
value|L2_S_PROTO_generic
end_define

begin_elif
elif|#
directive|elif
name|ARM_MMU_XSCALE
operator|==
literal|1
end_elif

begin_define
define|#
directive|define
name|L2_S_PROT_U
value|L2_S_PROT_U_xscale
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_W
value|L2_S_PROT_W_xscale
end_define

begin_define
define|#
directive|define
name|L2_S_PROT_MASK
value|L2_S_PROT_MASK_xscale
end_define

begin_define
define|#
directive|define
name|L1_S_CACHE_MASK
value|L1_S_CACHE_MASK_xscale
end_define

begin_define
define|#
directive|define
name|L2_L_CACHE_MASK
value|L2_L_CACHE_MASK_xscale
end_define

begin_define
define|#
directive|define
name|L2_S_CACHE_MASK
value|L2_S_CACHE_MASK_xscale
end_define

begin_define
define|#
directive|define
name|L1_S_PROTO
value|L1_S_PROTO_xscale
end_define

begin_define
define|#
directive|define
name|L1_C_PROTO
value|L1_C_PROTO_xscale
end_define

begin_define
define|#
directive|define
name|L2_S_PROTO
value|L2_S_PROTO_xscale
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_NMMUS> 1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SKYEYE_WORKAROUNDS
end_ifdef

begin_define
define|#
directive|define
name|PMAP_NEEDS_PTE_SYNC
value|1
end_define

begin_define
define|#
directive|define
name|PMAP_INCLUDE_PTE_SYNC
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|ARM_MMU_SA1
operator|==
literal|1
operator|)
operator|&&
operator|(
name|ARM_NMMUS
operator|==
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|PMAP_NEEDS_PTE_SYNC
value|1
end_define

begin_define
define|#
directive|define
name|PMAP_INCLUDE_PTE_SYNC
end_define

begin_elif
elif|#
directive|elif
operator|(
name|ARM_MMU_SA1
operator|==
literal|0
operator|)
end_elif

begin_define
define|#
directive|define
name|PMAP_NEEDS_PTE_SYNC
value|0
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
comment|/*  * These macros return various bits based on kernel/user and protection.  * Note that the compiler will usually fold these at compile time.  */
end_comment

begin_define
define|#
directive|define
name|L1_S_PROT
parameter_list|(
name|ku
parameter_list|,
name|pr
parameter_list|)
value|((((ku) == PTE_USER) ? L1_S_PROT_U : 0) | \ 				 (((pr)& VM_PROT_WRITE) ? L1_S_PROT_W : 0))
end_define

begin_define
define|#
directive|define
name|L2_L_PROT
parameter_list|(
name|ku
parameter_list|,
name|pr
parameter_list|)
value|((((ku) == PTE_USER) ? L2_L_PROT_U : 0) | \ 				 (((pr)& VM_PROT_WRITE) ? L2_L_PROT_W : 0))
end_define

begin_define
define|#
directive|define
name|L2_S_PROT
parameter_list|(
name|ku
parameter_list|,
name|pr
parameter_list|)
value|((((ku) == PTE_USER) ? L2_S_PROT_U : 0) | \ 				 (((pr)& VM_PROT_WRITE) ? L2_S_PROT_W : 0))
end_define

begin_comment
comment|/*  * Macros to test if a mapping is mappable with an L1 Section mapping  * or an L2 Large Page mapping.  */
end_comment

begin_define
define|#
directive|define
name|L1_S_MAPPABLE_P
parameter_list|(
name|va
parameter_list|,
name|pa
parameter_list|,
name|size
parameter_list|)
define|\
value|((((va) | (pa))& L1_S_OFFSET) == 0&& (size)>= L1_S_SIZE)
end_define

begin_define
define|#
directive|define
name|L2_L_MAPPABLE_P
parameter_list|(
name|va
parameter_list|,
name|pa
parameter_list|,
name|size
parameter_list|)
define|\
value|((((va) | (pa))& L2_L_OFFSET) == 0&& (size)>= L2_L_SIZE)
end_define

begin_comment
comment|/*  * Provide a fallback in case we were not able to determine it at  * compile-time.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PMAP_NEEDS_PTE_SYNC
end_ifndef

begin_define
define|#
directive|define
name|PMAP_NEEDS_PTE_SYNC
value|pmap_needs_pte_sync
end_define

begin_define
define|#
directive|define
name|PMAP_INCLUDE_PTE_SYNC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PTE_SYNC
parameter_list|(
name|pte
parameter_list|)
define|\
value|do {									\ 	if (PMAP_NEEDS_PTE_SYNC)					\ 		cpu_dcache_wb_range((vm_offset_t)(pte), sizeof(pt_entry_t));\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PTE_SYNC_RANGE
parameter_list|(
name|pte
parameter_list|,
name|cnt
parameter_list|)
define|\
value|do {									\ 	if (PMAP_NEEDS_PTE_SYNC) {					\ 		cpu_dcache_wb_range((vm_offset_t)(pte),			\ 		    (cnt)<< 2);
comment|/* * sizeof(pt_entry_t) */
value|\ 	}								\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l1_s_cache_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l1_s_cache_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_l_cache_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_l_cache_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_s_cache_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_s_cache_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l1_s_cache_mode_pt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_l_cache_mode_pt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_s_cache_mode_pt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_s_prot_u
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_s_prot_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_s_prot_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l1_s_proto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l1_c_proto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|pte_l2_s_proto
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|pmap_copy_page_func
function_decl|)
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|pmap_zero_page_func
function_decl|)
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|ARM_MMU_GENERIC
operator|+
name|ARM_MMU_SA1
operator|)
operator|!=
literal|0
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_81342
argument_list|)
end_if

begin_function_decl
name|void
name|pmap_copy_page_generic
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_zero_page_generic
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_pte_init_generic
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM8
argument_list|)
end_if

begin_function_decl
name|void
name|pmap_pte_init_arm8
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
end_if

begin_function_decl
name|void
name|pmap_pte_init_arm9
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
comment|/* CPU_ARM9 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM10
argument_list|)
end_if

begin_function_decl
name|void
name|pmap_pte_init_arm10
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
comment|/* CPU_ARM10 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (ARM_MMU_GENERIC + ARM_MMU_SA1) != 0 */
end_comment

begin_if
if|#
directive|if
comment|/* ARM_MMU_SA1 == */
literal|1
end_if

begin_function_decl
name|void
name|pmap_pte_init_sa1
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
comment|/* ARM_MMU_SA1 == 1 */
end_comment

begin_if
if|#
directive|if
name|ARM_MMU_XSCALE
operator|==
literal|1
end_if

begin_function_decl
name|void
name|pmap_copy_page_xscale
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_zero_page_xscale
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_pte_init_xscale
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_setup_minidata
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_use_minicache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_MMU_XSCALE == 1 */
end_comment

begin_define
define|#
directive|define
name|PTE_KERNEL
value|0
end_define

begin_define
define|#
directive|define
name|PTE_USER
value|1
end_define

begin_define
define|#
directive|define
name|l1pte_valid
parameter_list|(
name|pde
parameter_list|)
value|((pde) != 0)
end_define

begin_define
define|#
directive|define
name|l1pte_section_p
parameter_list|(
name|pde
parameter_list|)
value|(((pde)& L1_TYPE_MASK) == L1_TYPE_S)
end_define

begin_define
define|#
directive|define
name|l1pte_page_p
parameter_list|(
name|pde
parameter_list|)
value|(((pde)& L1_TYPE_MASK) == L1_TYPE_C)
end_define

begin_define
define|#
directive|define
name|l1pte_fpage_p
parameter_list|(
name|pde
parameter_list|)
value|(((pde)& L1_TYPE_MASK) == L1_TYPE_F)
end_define

begin_define
define|#
directive|define
name|l2pte_index
parameter_list|(
name|v
parameter_list|)
value|(((v)& L2_ADDR_BITS)>> L2_S_SHIFT)
end_define

begin_define
define|#
directive|define
name|l2pte_valid
parameter_list|(
name|pte
parameter_list|)
value|((pte) != 0)
end_define

begin_define
define|#
directive|define
name|l2pte_pa
parameter_list|(
name|pte
parameter_list|)
value|((pte)& L2_S_FRAME)
end_define

begin_define
define|#
directive|define
name|l2pte_minidata
parameter_list|(
name|pte
parameter_list|)
value|(((pte)& \ 				 (L2_B | L2_C | L2_XSCALE_T_TEX(TEX_XSCALE_X)))\ 				 == (L2_C | L2_XSCALE_T_TEX(TEX_XSCALE_X)))
end_define

begin_comment
comment|/* L1 and L2 page table macros */
end_comment

begin_define
define|#
directive|define
name|pmap_pde_v
parameter_list|(
name|pde
parameter_list|)
value|l1pte_valid(*(pde))
end_define

begin_define
define|#
directive|define
name|pmap_pde_section
parameter_list|(
name|pde
parameter_list|)
value|l1pte_section_p(*(pde))
end_define

begin_define
define|#
directive|define
name|pmap_pde_page
parameter_list|(
name|pde
parameter_list|)
value|l1pte_page_p(*(pde))
end_define

begin_define
define|#
directive|define
name|pmap_pde_fpage
parameter_list|(
name|pde
parameter_list|)
value|l1pte_fpage_p(*(pde))
end_define

begin_define
define|#
directive|define
name|pmap_pte_v
parameter_list|(
name|pte
parameter_list|)
value|l2pte_valid(*(pte))
end_define

begin_define
define|#
directive|define
name|pmap_pte_pa
parameter_list|(
name|pte
parameter_list|)
value|l2pte_pa(*(pte))
end_define

begin_comment
comment|/*  * Flags that indicate attributes of pages or mappings of pages.  *  * The PVF_MOD and PVF_REF flags are stored in the mdpage for each  * page.  PVF_WIRED, PVF_WRITE, and PVF_NC are kept in individual  * pv_entry's for each page.  They live in the same "namespace" so  * that we can clear multiple attributes at a time.  *  * Note the "non-cacheable" flag generally means the page has  * multiple mappings in a given address space.  */
end_comment

begin_define
define|#
directive|define
name|PVF_MOD
value|0x01
end_define

begin_comment
comment|/* page is modified */
end_comment

begin_define
define|#
directive|define
name|PVF_REF
value|0x02
end_define

begin_comment
comment|/* page is referenced */
end_comment

begin_define
define|#
directive|define
name|PVF_WIRED
value|0x04
end_define

begin_comment
comment|/* mapping is wired */
end_comment

begin_define
define|#
directive|define
name|PVF_WRITE
value|0x08
end_define

begin_comment
comment|/* mapping is writable */
end_comment

begin_define
define|#
directive|define
name|PVF_EXEC
value|0x10
end_define

begin_comment
comment|/* mapping is executable */
end_comment

begin_define
define|#
directive|define
name|PVF_UNC
value|0x20
end_define

begin_comment
comment|/* mapping is 'user' non-cacheable */
end_comment

begin_define
define|#
directive|define
name|PVF_KNC
value|0x40
end_define

begin_comment
comment|/* mapping is 'kernel' non-cacheable */
end_comment

begin_define
define|#
directive|define
name|PVF_NC
value|(PVF_UNC|PVF_KNC)
end_define

begin_function_decl
name|void
name|vector_page_setprot
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_update
parameter_list|(
name|pmap_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This structure is used by machine-dependent code to describe  * static mappings of devices, created at bootstrap time.  */
end_comment

begin_struct
struct|struct
name|pmap_devmap
block|{
name|vm_offset_t
name|pd_va
decl_stmt|;
comment|/* virtual address */
name|vm_paddr_t
name|pd_pa
decl_stmt|;
comment|/* physical address */
name|vm_size_t
name|pd_size
decl_stmt|;
comment|/* size of region */
name|vm_prot_t
name|pd_prot
decl_stmt|;
comment|/* protection code */
name|int
name|pd_cache
decl_stmt|;
comment|/* cache attributes */
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|struct
name|pmap_devmap
modifier|*
name|pmap_devmap_find_pa
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|pmap_devmap
modifier|*
name|pmap_devmap_find_va
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_devmap_bootstrap
parameter_list|(
name|vm_offset_t
parameter_list|,
specifier|const
name|struct
name|pmap_devmap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_devmap_register
parameter_list|(
specifier|const
name|struct
name|pmap_devmap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SECTION_CACHE
value|0x1
end_define

begin_define
define|#
directive|define
name|SECTION_PT
value|0x2
end_define

begin_function_decl
name|void
name|pmap_kenter_section
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_tmppt
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pmap_postinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_USE_SMALL_ALLOC
end_ifdef

begin_function_decl
name|void
name|arm_add_smallalloc_pages
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|arm_ptovirt
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_init_smallalloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|arm_small_page
block|{
name|void
modifier|*
name|addr
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|arm_small_page
argument_list|)
name|pg_list
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARM_NOCACHE_KVA_SIZE
value|0x1000000
end_define

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|arm_nocache_startaddr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|arm_remap_nocache
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_unmap_nocache
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|dump_avail
index|[]
decl_stmt|;
end_decl_stmt

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

