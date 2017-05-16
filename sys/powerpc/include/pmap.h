begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2006 Semihalf, Marian Balakowicz<m8@semihalf.com>  * All rights reserved.  *  * Adapted for Freescale's e500 core CPUs.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: $NetBSD: pmap.h,v 1.17 2000/03/30 16:18:24 jdolecek Exp $  */
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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/tree.h>
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

begin_include
include|#
directive|include
file|<machine/sr.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<machine/slb.h>
end_include

begin_include
include|#
directive|include
file|<machine/tlb.h>
end_include

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|pmap
modifier|*
name|pmap_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AIM
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NPMAPS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NPMAPS
value|32768
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NPMAPS) */
end_comment

begin_struct_decl
struct_decl|struct
name|slbtnode
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|pvo_entry
block|{
name|LIST_ENTRY
argument_list|(
argument|pvo_entry
argument_list|)
name|pvo_vlink
expr_stmt|;
comment|/* Link to common virt page */
ifndef|#
directive|ifndef
name|__powerpc64__
name|LIST_ENTRY
argument_list|(
argument|pvo_entry
argument_list|)
name|pvo_olink
expr_stmt|;
comment|/* Link to overflow entry */
endif|#
directive|endif
name|RB_ENTRY
argument_list|(
argument|pvo_entry
argument_list|)
name|pvo_plink
expr_stmt|;
comment|/* Link to pmap entries */
struct|struct
block|{
ifndef|#
directive|ifndef
name|__powerpc64__
comment|/* 32-bit fields */
name|struct
name|pte
name|pte
decl_stmt|;
endif|#
directive|endif
comment|/* 64-bit fields */
name|uintptr_t
name|slot
decl_stmt|;
name|vm_paddr_t
name|pa
decl_stmt|;
name|vm_prot_t
name|prot
decl_stmt|;
block|}
name|pvo_pte
struct|;
name|pmap_t
name|pvo_pmap
decl_stmt|;
comment|/* Owning pmap */
name|vm_offset_t
name|pvo_vaddr
decl_stmt|;
comment|/* VA of entry */
name|uint64_t
name|pvo_vpn
decl_stmt|;
comment|/* Virtual page number */
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|pvo_head
argument_list|,
name|pvo_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|pvo_tree
argument_list|,
name|pvo_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|pvo_vaddr_compare
parameter_list|(
name|struct
name|pvo_entry
modifier|*
parameter_list|,
name|struct
name|pvo_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|RB_PROTOTYPE
argument_list|(
name|pvo_tree
argument_list|,
name|pvo_entry
argument_list|,
name|pvo_plink
argument_list|,
name|pvo_vaddr_compare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Used by 32-bit PMAP */
end_comment

begin_define
define|#
directive|define
name|PVO_PTEGIDX_MASK
value|0x007UL
end_define

begin_comment
comment|/* which PTEG slot */
end_comment

begin_define
define|#
directive|define
name|PVO_PTEGIDX_VALID
value|0x008UL
end_define

begin_comment
comment|/* slot is valid */
end_comment

begin_comment
comment|/* Used by 64-bit PMAP */
end_comment

begin_define
define|#
directive|define
name|PVO_HID
value|0x008UL
end_define

begin_comment
comment|/* PVO entry in alternate hash*/
end_comment

begin_comment
comment|/* Used by both */
end_comment

begin_define
define|#
directive|define
name|PVO_WIRED
value|0x010UL
end_define

begin_comment
comment|/* PVO entry is wired */
end_comment

begin_define
define|#
directive|define
name|PVO_MANAGED
value|0x020UL
end_define

begin_comment
comment|/* PVO entry is managed */
end_comment

begin_define
define|#
directive|define
name|PVO_BOOTSTRAP
value|0x080UL
end_define

begin_comment
comment|/* PVO entry allocated during 						   bootstrap */
end_comment

begin_define
define|#
directive|define
name|PVO_DEAD
value|0x100UL
end_define

begin_comment
comment|/* waiting to be deleted */
end_comment

begin_define
define|#
directive|define
name|PVO_LARGE
value|0x200UL
end_define

begin_comment
comment|/* large page */
end_comment

begin_define
define|#
directive|define
name|PVO_VADDR
parameter_list|(
name|pvo
parameter_list|)
value|((pvo)->pvo_vaddr& ~ADDR_POFF)
end_define

begin_define
define|#
directive|define
name|PVO_PTEGIDX_GET
parameter_list|(
name|pvo
parameter_list|)
value|((pvo)->pvo_vaddr& PVO_PTEGIDX_MASK)
end_define

begin_define
define|#
directive|define
name|PVO_PTEGIDX_ISSET
parameter_list|(
name|pvo
parameter_list|)
value|((pvo)->pvo_vaddr& PVO_PTEGIDX_VALID)
end_define

begin_define
define|#
directive|define
name|PVO_PTEGIDX_CLR
parameter_list|(
name|pvo
parameter_list|)
define|\
value|((void)((pvo)->pvo_vaddr&= ~(PVO_PTEGIDX_VALID|PVO_PTEGIDX_MASK)))
end_define

begin_define
define|#
directive|define
name|PVO_PTEGIDX_SET
parameter_list|(
name|pvo
parameter_list|,
name|i
parameter_list|)
define|\
value|((void)((pvo)->pvo_vaddr |= (i)|PVO_PTEGIDX_VALID))
end_define

begin_define
define|#
directive|define
name|PVO_VSID
parameter_list|(
name|pvo
parameter_list|)
value|((pvo)->pvo_vpn>> 16)
end_define

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
name|struct
name|mtx
name|pm_mtx
decl_stmt|;
ifdef|#
directive|ifdef
name|__powerpc64__
name|struct
name|slbtnode
modifier|*
name|pm_slb_tree_root
decl_stmt|;
name|struct
name|slb
modifier|*
modifier|*
name|pm_slb
decl_stmt|;
name|int
name|pm_slb_len
decl_stmt|;
else|#
directive|else
name|register_t
name|pm_sr
index|[
literal|16
index|]
decl_stmt|;
endif|#
directive|endif
name|cpuset_t
name|pm_active
decl_stmt|;
name|struct
name|pmap
modifier|*
name|pmap_phys
decl_stmt|;
name|struct
name|pvo_tree
name|pmap_pvo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|md_page
block|{
specifier|volatile
name|int32_t
name|mdpg_attrs
decl_stmt|;
name|vm_memattr_t
name|mdpg_cache_attrs
decl_stmt|;
name|struct
name|pvo_head
name|mdpg_pvoh
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pmap_page_get_memattr
parameter_list|(
name|m
parameter_list|)
value|((m)->md.mdpg_cache_attrs)
end_define

begin_define
define|#
directive|define
name|pmap_page_is_mapped
parameter_list|(
name|m
parameter_list|)
value|(!LIST_EMPTY(&(m)->md.mdpg_pvoh))
end_define

begin_comment
comment|/*  * Return the VSID corresponding to a given virtual address.  * If no VSID is currently defined, it will allocate one, and add  * it to a free slot if available.  *  * NB: The PMAP MUST be locked already.  */
end_comment

begin_function_decl
name|uint64_t
name|va_to_vsid
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lock-free, non-allocating lookup routines */
end_comment

begin_function_decl
name|uint64_t
name|kernel_va_to_slbv
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|slb
modifier|*
name|user_va_to_slb_entry
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|allocate_user_vsid
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|uint64_t
name|esid
parameter_list|,
name|int
name|large
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_vsid
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|uint64_t
name|esid
parameter_list|,
name|int
name|large
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slb_insert_user
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|struct
name|slb
modifier|*
name|slb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slb_insert_kernel
parameter_list|(
name|uint64_t
name|slbe
parameter_list|,
name|uint64_t
name|slbv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|slbtnode
modifier|*
name|slb_alloc_tree
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slb_free_tree
parameter_list|(
name|pmap_t
name|pm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|slb
modifier|*
modifier|*
name|slb_alloc_user_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slb_free_user_cache
parameter_list|(
name|struct
name|slb
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|BOOKE
argument_list|)
end_elif

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statistics */
name|struct
name|mtx
name|pm_mtx
decl_stmt|;
comment|/* pmap mutex */
name|tlbtid_t
name|pm_tid
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* TID to identify this pmap entries in TLB */
name|cpuset_t
name|pm_active
decl_stmt|;
comment|/* active on cpus */
ifdef|#
directive|ifdef
name|__powerpc64__
comment|/* Page table directory, array of pointers to page directories. */
name|pte_t
modifier|*
modifier|*
name|pm_pp2d
index|[
name|PP2D_NENTRIES
index|]
decl_stmt|;
comment|/* List of allocated pdir bufs (pdir kva regions). */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ptbl_buf
argument_list|)
name|pm_pdir_list
expr_stmt|;
else|#
directive|else
comment|/* Page table directory, array of pointers to page tables. */
name|pte_t
modifier|*
name|pm_pdir
index|[
name|PDIR_NENTRIES
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* List of allocated ptbl bufs (ptbl kva regions). */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ptbl_buf
argument_list|)
name|pm_ptbl_list
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
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
name|pv_link
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pv_entry
modifier|*
name|pv_entry_t
typedef|;
end_typedef

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
name|pv_tracked
decl_stmt|;
block|}
struct|;
end_struct

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Common pmap members between AIM and BOOKE.  * libkvm needs pm_stats at the same location between both, as it doesn't define  * AIM nor BOOKE, and is expected to work across all.  */
end_comment

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statistics */
name|struct
name|mtx
name|pm_mtx
decl_stmt|;
comment|/* pmap mutex */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIM */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
value|mtx_init(&(pmap)->pm_mtx, \ 				    (pmap == kernel_pmap) ? "kernelpmap" : \ 				    "pmap", NULL, MTX_DEF)
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
name|pmap_page_is_write_mapped
parameter_list|(
name|m
parameter_list|)
value|(((m)->aflags& PGA_WRITEABLE) != 0)
end_define

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
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
name|pmap_kenter_attr
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_memattr_t
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
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pmap_mapdev_attr
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_memattr_t
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
name|pmap_page_set_memattr
parameter_list|(
name|vm_page_t
parameter_list|,
name|vm_memattr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmap_change_attr
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_memattr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_deactivate
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|pmap_kextract
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmap_dev_direct_mapped
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|pmap_mmu_install
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|prio
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

begin_define
define|#
directive|define
name|PHYS_AVAIL_SZ
value|256
end_define

begin_comment
comment|/* Allows up to 16GB Ram on pSeries with 				 * logical memory block size of 64MB. 				 * For more Ram increase the lmb or this value. 				 */
end_comment

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|phys_avail
index|[
name|PHYS_AVAIL_SZ
index|]
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
name|vm_offset_t
name|msgbuf_phys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pmap_bootstrapped
decl_stmt|;
end_decl_stmt

begin_function_decl
name|vm_offset_t
name|pmap_early_io_map
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_early_io_unmap
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_track_page
parameter_list|(
name|pmap_t
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PMAP_H_ */
end_comment

end_unit

