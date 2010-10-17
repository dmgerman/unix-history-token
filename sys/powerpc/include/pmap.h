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
file|<machine/tlb.h>
end_include

begin_struct
struct|struct
name|pmap_md
block|{
name|u_int
name|md_index
decl_stmt|;
name|vm_paddr_t
name|md_paddr
decl_stmt|;
name|vm_offset_t
name|md_vaddr
decl_stmt|;
name|vm_size_t
name|md_size
decl_stmt|;
block|}
struct|;
end_struct

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

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|mtx
name|pm_mtx
decl_stmt|;
name|u_int
name|pm_sr
index|[
literal|16
index|]
decl_stmt|;
name|u_int
name|pm_active
decl_stmt|;
name|u_int
name|pm_context
decl_stmt|;
name|struct
name|pmap
modifier|*
name|pmap_phys
decl_stmt|;
name|struct
name|pmap_statistics
name|pm_stats
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
name|LIST_ENTRY
argument_list|(
argument|pvo_entry
argument_list|)
name|pvo_olink
expr_stmt|;
comment|/* Link to overflow entry */
union|union
block|{
name|struct
name|pte
name|pte
decl_stmt|;
comment|/* 32 bit PTE */
name|struct
name|lpte
name|lpte
decl_stmt|;
comment|/* 64 bit PTE */
block|}
name|pvo_pte
union|;
name|pmap_t
name|pvo_pmap
decl_stmt|;
comment|/* Owning pmap */
name|vm_offset_t
name|pvo_vaddr
decl_stmt|;
comment|/* VA of entry */
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

begin_struct
struct|struct
name|md_page
block|{
name|u_int64_t
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

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|pmap
block|{
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
name|u_int
name|pm_active
decl_stmt|;
comment|/* active on cpus */
name|int
name|pm_refs
decl_stmt|;
comment|/* ref count */
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statistics */
comment|/* Page table directory, array of pointers to page tables. */
name|pte_t
modifier|*
name|pm_pdir
index|[
name|PDIR_NENTRIES
index|]
decl_stmt|;
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

begin_typedef
typedef|typedef
name|struct
name|pmap
modifier|*
name|pmap_t
typedef|;
end_typedef

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
name|vm_offset_t
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
name|vm_offset_t
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
name|vm_offset_t
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
name|vm_offset_t
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
name|vm_offset_t
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
value|128
end_define

begin_decl_stmt
specifier|extern
name|vm_offset_t
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
specifier|extern
name|vm_offset_t
name|pmap_dumpsys_map
parameter_list|(
name|struct
name|pmap_md
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pmap_dumpsys_unmap
parameter_list|(
name|struct
name|pmap_md
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|pmap_md
modifier|*
name|pmap_scan_md
parameter_list|(
name|struct
name|pmap_md
modifier|*
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

