begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: pmap.h,v 1.17 2000/03/30 16:18:24 jdolecek Exp $  * $FreeBSD$  */
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

begin_comment
comment|/*  * Segment registers  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|u_int
name|sr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_define
define|#
directive|define
name|SR_TYPE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SR_SUKEY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SR_PRKEY
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SR_VSID
value|0x00ffffff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|pv_entry
block|{
name|struct
name|pv_entry
modifier|*
name|pv_next
decl_stmt|;
comment|/* Linked list of mappings */
name|int
name|pv_idx
decl_stmt|;
comment|/* Index into ptable */
name|vm_offset_t
name|pv_va
decl_stmt|;
comment|/* virtual address of mapping */
block|}
struct|;
end_struct

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

begin_comment
comment|/*  * Pmap stuff  */
end_comment

begin_struct
struct|struct
name|pmap
block|{
name|sr_t
name|pm_sr
index|[
literal|16
index|]
decl_stmt|;
comment|/* segments used in this pmap */
name|int
name|pm_refs
decl_stmt|;
comment|/* ref count */
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statistics */
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

begin_typedef
typedef|typedef
name|struct
name|pv_entry
modifier|*
name|pv_entry_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|pmap_clear_modify
parameter_list|(
name|pg
parameter_list|)
value|(ptemodify((pg), PTE_CHG, 0))
end_define

begin_define
define|#
directive|define
name|pmap_clear_reference
parameter_list|(
name|pg
parameter_list|)
value|(ptemodify((pg), PTE_REF, 0))
end_define

begin_define
define|#
directive|define
name|pmap_is_modified
parameter_list|(
name|pg
parameter_list|)
value|(ptebits((pg), PTE_CHG))
end_define

begin_define
define|#
directive|define
name|pmap_is_referenced
parameter_list|(
name|pg
parameter_list|)
value|(ptebits((pg), PTE_REF))
end_define

begin_define
define|#
directive|define
name|pmap_unwire
parameter_list|(
name|pm
parameter_list|,
name|va
parameter_list|)
end_define

begin_define
define|#
directive|define
name|pmap_phys_address
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|pmap_resident_count
parameter_list|(
name|pmap
parameter_list|)
value|((pmap)->pm_stats.resident_count)
end_define

begin_decl_stmt
specifier|extern
name|pmap_t
name|kernel_pmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|avail_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|avail_start
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|pmap_bootstrap
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|pmap_mapdev
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|,
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_setavailmem
name|__P
argument_list|(
operator|(
name|u_int
name|kernelstart
operator|,
name|u_int
name|kernelend
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|pmap_steal_memory
name|__P
argument_list|(
operator|(
name|vm_size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|ptemodify
name|__P
argument_list|(
operator|(
expr|struct
name|vm_page
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ptebits
name|__P
argument_list|(
operator|(
expr|struct
name|vm_page
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|PMAP_NEED_PROCWR
end_define

begin_endif
unit|void pmap_procwr __P((struct proc *, vaddr_t, size_t));
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Alternate mapping hooks for pool pages.  Avoids thrashing the TLB.  *  * Note: This won't work if we have more memory than can be direct-mapped  * VA==PA all at once.  But pmap_copy_page() and pmap_zero_page() will have  * this problem, too.  */
end_comment

begin_define
define|#
directive|define
name|PMAP_MAP_POOLPAGE
parameter_list|(
name|pa
parameter_list|)
value|(pa)
end_define

begin_define
define|#
directive|define
name|PMAP_UNMAP_POOLPAGE
parameter_list|(
name|pa
parameter_list|)
value|(pa)
end_define

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
name|pte_t
name|PTmap
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|vtopte
parameter_list|(
name|x
parameter_list|)
value|(PTmap + powerpc_btop(x))
end_define

begin_function
specifier|static
name|__inline
name|vm_offset_t
name|pmap_kextract
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
block|{
comment|/* XXX: coming soon... */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

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
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PMAP_H_ */
end_comment

end_unit

