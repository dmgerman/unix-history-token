begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/* From: NetBSD: pmap.old.h,v 1.16 1998/01/09 19:13:09 thorpej Exp */
end_comment

begin_comment
comment|/*   * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pmap.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PMAP_MACHINE_
end_ifndef

begin_define
define|#
directive|define
name|_PMAP_MACHINE_
end_define

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<machine/lock.h>
end_include

begin_function_decl
specifier|extern
name|vm_offset_t
name|vtophys
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ALPHA_PAGE_SIZE
value|NBPG
end_define

begin_define
define|#
directive|define
name|ALPHA_SEG_SIZE
value|NBSEG
end_define

begin_define
define|#
directive|define
name|alpha_trunc_seg
parameter_list|(
name|x
parameter_list|)
value|(((u_long)(x))& ~(ALPHA_SEG_SIZE-1))
end_define

begin_define
define|#
directive|define
name|alpha_round_seg
parameter_list|(
name|x
parameter_list|)
value|alpha_trunc_seg((u_long)(x) + ALPHA_SEG_SIZE-1)
end_define

begin_typedef
typedef|typedef
name|struct
name|simplelock
name|simple_lock_data_t
typedef|;
end_typedef

begin_comment
comment|/*  * Pmap stuff  */
end_comment

begin_struct
struct|struct
name|pmap
block|{
name|pt_entry_t
modifier|*
name|pm_ptab
decl_stmt|;
comment|/* KVA of page table */
name|pt_entry_t
modifier|*
name|pm_stab
decl_stmt|;
comment|/* KVA of segment table */
name|pt_entry_t
name|pm_stpte
decl_stmt|;
comment|/* PTE mapping STE */
name|short
name|pm_sref
decl_stmt|;
comment|/* segment table ref count */
name|short
name|pm_count
decl_stmt|;
comment|/* pmap reference count */
name|simple_lock_data_t
name|pm_lock
decl_stmt|;
comment|/* lock on pmap */
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statistics */
name|long
name|pm_ptpages
decl_stmt|;
comment|/* more stats: PT pages */
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
name|pmap_kernel
parameter_list|()
value|(&kernel_pmap_store)
end_define

begin_define
define|#
directive|define
name|active_pmap
parameter_list|(
name|pm
parameter_list|)
define|\
value|((pm) == pmap_kernel()	\ 	|| curproc == NULL	\ 	|| (pm) == curproc->p_vmspace->vm_map.pmap)
end_define

begin_define
define|#
directive|define
name|active_user_pmap
parameter_list|(
name|pm
parameter_list|)
define|\
value|(curproc&& \ 	 (pm) != pmap_kernel()&& (pm) == curproc->p_vmspace->vm_map.pmap)
end_define

begin_comment
comment|/*  * For each vm_page_t, there is a list of all currently valid virtual  * mappings of that page.  An entry is a pv_entry_t, the list is pv_table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pv_entry
block|{
name|struct
name|pv_entry
modifier|*
name|pv_next
decl_stmt|;
comment|/* next pv_entry */
name|struct
name|pmap
modifier|*
name|pv_pmap
decl_stmt|;
comment|/* pmap where mapping lies */
name|vm_offset_t
name|pv_va
decl_stmt|;
comment|/* virtual address for mapping */
name|pt_entry_t
modifier|*
name|pv_ptpte
decl_stmt|;
comment|/* non-zero if VA maps a PT page */
name|struct
name|pmap
modifier|*
name|pv_ptpmap
decl_stmt|;
comment|/* if pv_ptpte, pmap for PT page */
name|int
name|pv_flags
decl_stmt|;
comment|/* flags */
block|}
typedef|*
name|pv_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PV_PTPAGE
value|0x01
end_define

begin_comment
comment|/* header: entry maps a page table page */
end_comment

begin_struct
struct|struct
name|pv_page_info
block|{
name|TAILQ_ENTRY
argument_list|(
argument|pv_page
argument_list|)
name|pgi_list
expr_stmt|;
name|struct
name|pv_entry
modifier|*
name|pgi_freelist
decl_stmt|;
name|int
name|pgi_nfree
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NPVPPG
value|((NBPG - sizeof(struct pv_page_info)) / sizeof(struct pv_entry))
end_define

begin_struct
struct|struct
name|pv_page
block|{
name|struct
name|pv_page_info
name|pvp_pgi
decl_stmt|;
name|struct
name|pv_entry
name|pvp_pv
index|[
name|NPVPPG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Physical page attributes.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|pmap_attr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PMAP_ATTR_MOD
value|0x01
end_define

begin_comment
comment|/* modified */
end_comment

begin_define
define|#
directive|define
name|PMAP_ATTR_REF
value|0x02
end_define

begin_comment
comment|/* referenced */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|pmap_resident_count
parameter_list|(
name|pmap
parameter_list|)
value|((pmap)->pm_stats.resident_count)
end_define

begin_define
define|#
directive|define
name|pmap_wired_count
parameter_list|(
name|pmap
parameter_list|)
value|((pmap)->pm_stats.wired_count)
end_define

begin_decl_stmt
specifier|extern
name|pt_entry_t
modifier|*
name|Sysmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|vmmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map for mem, dumps, etc. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MACHINE_NEW_NONCONTIG
argument_list|)
end_if

begin_define
define|#
directive|define
name|PMAP_STEAL_MEMORY
end_define

begin_comment
comment|/* enable pmap_steal_memory() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Machine-specific functions. */
end_comment

begin_decl_stmt
name|void
name|pmap_bootstrap
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|firstaddr
operator|,
name|vm_offset_t
name|ptaddr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_emulate_reference
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|vm_offset_t
name|v
operator|,
name|int
name|user
operator|,
name|int
name|write
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_unmap_prom
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
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
comment|/* _PMAP_MACHINE_ */
end_comment

end_unit

