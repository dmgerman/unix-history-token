begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Derived from hp300 version by Mike Hibler, this version by William  * Jolitz uses a recursive map [a pde points to the page directory] to  * map the page tables using the pagetables themselves. This is done to  * reduce the impact on kernel virtual memory for lots of sparse address  * space, and to reduce the cost of memory to each process.  *  *	from: hp300: @(#)pmap.h	7.2 (Berkeley) 12/16/90  *	from: @(#)pmap.h	7.4 (Berkeley) 5/12/91  *	from: i386 pmap.h,v 1.54 1997/11/20 19:30:35 bde Exp  * $FreeBSD$  */
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

begin_comment
comment|/*  * Define meanings for a few software bits in the pte  */
end_comment

begin_define
define|#
directive|define
name|PG_V
value|ALPHA_PTE_VALID
end_define

begin_define
define|#
directive|define
name|PG_FOR
value|ALPHA_PTE_FAULT_ON_READ
end_define

begin_define
define|#
directive|define
name|PG_FOW
value|ALPHA_PTE_FAULT_ON_WRITE
end_define

begin_define
define|#
directive|define
name|PG_FOE
value|ALPHA_PTE_FAULT_ON_EXECUTE
end_define

begin_define
define|#
directive|define
name|PG_ASM
value|ALPHA_PTE_ASM
end_define

begin_define
define|#
directive|define
name|PG_GH
value|ALPHA_PTE_GRANULARITY
end_define

begin_define
define|#
directive|define
name|PG_KRE
value|ALPHA_PTE_KR
end_define

begin_define
define|#
directive|define
name|PG_URE
value|ALPHA_PTE_UR
end_define

begin_define
define|#
directive|define
name|PG_KWE
value|ALPHA_PTE_KW
end_define

begin_define
define|#
directive|define
name|PG_UWE
value|ALPHA_PTE_UW
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|ALPHA_PTE_PROT
end_define

begin_define
define|#
directive|define
name|PG_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|PG_W
value|0x00010000
end_define

begin_comment
comment|/* software wired */
end_comment

begin_define
define|#
directive|define
name|PG_MANAGED
value|0x00020000
end_define

begin_comment
comment|/* software managed */
end_comment

begin_comment
comment|/*  * Pte related macros  */
end_comment

begin_define
define|#
directive|define
name|VADDR
parameter_list|(
name|l1
parameter_list|,
name|l2
parameter_list|,
name|l3
parameter_list|)
value|(((l1)<< ALPHA_L1SHIFT)	\ 				 + ((l2)<< ALPHA_L2SHIFT)	\ 				 + ((l3)<< ALPHA_L3SHIFT)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NKPT
end_ifndef

begin_define
define|#
directive|define
name|NKPT
value|9
end_define

begin_comment
comment|/* initial number of kernel page tables */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NKLEV2MAPS
value|255
end_define

begin_comment
comment|/* max number of lev2 page tables */
end_comment

begin_define
define|#
directive|define
name|NKLEV3MAPS
value|(NKLEV2MAPS<< ALPHA_PTSHIFT)
end_define

begin_comment
comment|/* max number of lev3 page tables */
end_comment

begin_comment
comment|/*  * The *PTDI values control the layout of virtual memory  *  * XXX This works for now, but I am not real happy with it, I'll fix it  * right after I fix locore.s and the magic 28K hole  *  * SMP_PRIVPAGES: The per-cpu address space is 0xff80000 -> 0xffbfffff  */
end_comment

begin_define
define|#
directive|define
name|PTLEV1I
value|(NPTEPG-1)
end_define

begin_comment
comment|/* Lev0 entry that points to Lev0 */
end_comment

begin_define
define|#
directive|define
name|K0SEGLEV1I
value|(NPTEPG/2)
end_define

begin_define
define|#
directive|define
name|K1SEGLEV1I
value|(K0SEGLEV1I+(NPTEPG/4))
end_define

begin_define
define|#
directive|define
name|NUSERLEV2MAPS
value|(NPTEPG/2)
end_define

begin_define
define|#
directive|define
name|NUSERLEV3MAPS
value|(NUSERLEV2MAPS<< ALPHA_PTSHIFT)
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

begin_typedef
typedef|typedef
name|alpha_pt_entry_t
name|pt_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PTESIZE
value|sizeof(pt_entry_t)
end_define

begin_comment
comment|/* for assembly files */
end_comment

begin_comment
comment|/*  * Address of current address space page table maps  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|PTmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lev3 page tables */
end_comment

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|PTlev2
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lev2 page tables */
end_comment

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|PTlev1
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lev1 page table */
end_comment

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|PTlev1pte
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pte that maps lev1 page table */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * virtual address to page table entry and  * to physical address.  * Note: this work recursively, thus vtopte of a pte will give  * the corresponding lev1 that in turn maps it.  */
end_comment

begin_define
define|#
directive|define
name|vtopte
parameter_list|(
name|va
parameter_list|)
value|(PTmap + (alpha_btop(va) \& ((1<< 3*ALPHA_PTSHIFT)-1)))
end_define

begin_comment
comment|/*  *	Routine:	pmap_kextract  *	Function:  *		Extract the physical page address associated  *		kernel virtual address.  */
end_comment

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
name|vm_offset_t
name|pa
decl_stmt|;
if|if
condition|(
name|va
operator|>=
name|ALPHA_K0SEG_BASE
operator|&&
name|va
operator|<=
name|ALPHA_K0SEG_END
condition|)
name|pa
operator|=
name|ALPHA_K0SEG_TO_PHYS
argument_list|(
name|va
argument_list|)
expr_stmt|;
else|else
name|pa
operator|=
name|alpha_ptob
argument_list|(
name|ALPHA_PTE_TO_PFN
argument_list|(
operator|*
name|vtopte
argument_list|(
name|va
argument_list|)
argument_list|)
argument_list|)
operator||
operator|(
name|va
operator|&
name|PAGE_MASK
operator|)
expr_stmt|;
return|return
name|pa
return|;
block|}
end_function

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
name|vm_offset_t
name|alpha_XXX_dmamap_or
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|vm_offset_t
name|alpha_XXX_dmamap
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
block|{
return|return
operator|(
name|pmap_kextract
argument_list|(
name|va
argument_list|)
operator||
name|alpha_XXX_dmamap_or
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

begin_struct
struct|struct
name|pmap
block|{
name|pt_entry_t
modifier|*
name|pm_lev1
decl_stmt|;
comment|/* KVA of lev0map */
name|vm_object_t
name|pm_pteobj
decl_stmt|;
comment|/* Container for pte's */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_entry
argument_list|)
name|pm_pvlist
expr_stmt|;
comment|/* list of mappings in pmap */
name|int
name|pm_count
decl_stmt|;
comment|/* reference count */
name|int
name|pm_flags
decl_stmt|;
comment|/* pmap flags */
name|int
name|pm_active
decl_stmt|;
comment|/* active flag */
name|int
name|pm_asn
decl_stmt|;
comment|/* address space number */
name|u_int
name|pm_asngen
decl_stmt|;
comment|/* generation number of pm_asn */
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pmap_resident_count
parameter_list|(
name|pmap
parameter_list|)
value|(pmap)->pm_stats.resident_count
end_define

begin_define
define|#
directive|define
name|PM_FLAG_LOCKED
value|0x1
end_define

begin_define
define|#
directive|define
name|PM_FLAG_WANTED
value|0x2
end_define

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

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|PV_CI
value|0x01
end_define

begin_comment
comment|/* all entries must be cache inhibited */
end_comment

begin_define
define|#
directive|define
name|PV_PTPAGE
value|0x02
end_define

begin_comment
comment|/* entry maps a page table page */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|caddr_t
name|CADDR1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
modifier|*
name|CMAP1
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
name|clean_eva
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|clean_sva
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
name|void
name|pmap_bootstrap
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_setdevram
name|__P
argument_list|(
operator|(
name|unsigned
name|long
name|long
name|basea
operator|,
name|vm_offset_t
name|sizea
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pmap_uses_prom_console
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pmap_t
name|pmap_kernel
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
name|unsigned
modifier|*
name|pmap_pte
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_page_t
name|pmap_use_pt
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_set_opt
name|__P
argument_list|(
operator|(
name|unsigned
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pmap_set_opt_bsp
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
name|pmap_deactivate
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
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

