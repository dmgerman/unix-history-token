begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Derived from hp300 version by Mike Hibler, this version by William  * Jolitz uses a recursive map [a pde points to the page directory] to  * map the page tables using the pagetables themselves. This is done to  * reduce the impact on kernel virtual memory for lots of sparse address  * space, and to reduce the cost of memory to each process.  *  *	from: hp300: @(#)pmap.h	7.2 (Berkeley) 12/16/90  *	from: @(#)pmap.h	7.4 (Berkeley) 5/12/91  * $FreeBSD$  */
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

begin_typedef
typedef|typedef
name|unsigned
name|int
modifier|*
name|pd_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
modifier|*
name|pt_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * NKPDE controls the virtual space of the kernel, what ever is left, minus  * the alternate page table area is given to the user (NUPDE)  */
end_comment

begin_comment
comment|/*  * NKPDE controls the virtual space of the kernel, what ever is left is  * given to the user (NUPDE)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NKPT
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|NKPT
value|26
end_define

begin_comment
comment|/* actual number of kernel page tables */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NKPT
value|9
end_define

begin_comment
comment|/* actual number of kernel page tables */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NKPDE
end_ifndef

begin_define
define|#
directive|define
name|NKPDE
value|63
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
name|NUPDE
value|(NPTEPG-NKPDE)
end_define

begin_comment
comment|/* number of user pde's */
end_comment

begin_comment
comment|/*  * The *PTDI values control the layout of virtual memory  *  * XXX This works for now, but I am not real happy with it, I'll fix it  * right after I fix locore.s and the magic 28K hole  */
end_comment

begin_define
define|#
directive|define
name|APTDPTDI
value|(NPTEPG-1)
end_define

begin_comment
comment|/* alt ptd entry that points to APTD */
end_comment

begin_define
define|#
directive|define
name|KPTDI
value|(APTDPTDI-NKPDE)
end_define

begin_comment
comment|/* start of kernel virtual pde's */
end_comment

begin_define
define|#
directive|define
name|PTDPTDI
value|(KPTDI-1)
end_define

begin_comment
comment|/* ptd entry that points to ptd! */
end_comment

begin_define
define|#
directive|define
name|KSTKPTDI
value|(PTDPTDI-1)
end_define

begin_comment
comment|/* ptd entry for u./kernel&user stack */
end_comment

begin_define
define|#
directive|define
name|KSTKPTEOFF
value|(NBPG/sizeof(pd_entry_t)-UPAGES)
end_define

begin_comment
comment|/* pte entry for kernel stack */
end_comment

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

begin_comment
comment|/*  * Address of current and alternate address space page table maps  * and directories.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|PTmap
index|[]
decl_stmt|,
name|APTmap
index|[]
decl_stmt|,
name|Upte
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pd_entry_t
name|PTD
index|[]
decl_stmt|,
name|APTD
index|[]
decl_stmt|,
name|PTDpde
decl_stmt|,
name|APTDpde
decl_stmt|,
name|Upde
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|IdlePTD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical address of "Idle" state directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * virtual address to page table entry and  * to physical address. Likewise for alternate address space.  * Note: these work recursively, thus vtopte of a pte will give  * the corresponding pde that in turn maps it.  */
end_comment

begin_define
define|#
directive|define
name|vtopte
parameter_list|(
name|va
parameter_list|)
value|(PTmap + i386_btop(va))
end_define

begin_define
define|#
directive|define
name|kvtopte
parameter_list|(
name|va
parameter_list|)
value|vtopte(va)
end_define

begin_define
define|#
directive|define
name|ptetov
parameter_list|(
name|pt
parameter_list|)
value|(i386_ptob(pt - PTmap))
end_define

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|(((int) (*vtopte(va))&PG_FRAME) | ((int)(va)& PGOFSET))
end_define

begin_define
define|#
directive|define
name|ispt
parameter_list|(
name|va
parameter_list|)
value|((va)>= UPT_MIN_ADDRESS&& (va)<= KPT_MAX_ADDRESS)
end_define

begin_define
define|#
directive|define
name|avtopte
parameter_list|(
name|va
parameter_list|)
value|(APTmap + i386_btop(va))
end_define

begin_define
define|#
directive|define
name|ptetoav
parameter_list|(
name|pt
parameter_list|)
value|(i386_ptob(pt - APTmap))
end_define

begin_define
define|#
directive|define
name|avtophys
parameter_list|(
name|va
parameter_list|)
value|(((int) (*avtopte(va))&PG_FRAME) | ((int)(va)& PGOFSET))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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
init|=
operator|*
operator|(
name|int
operator|*
operator|)
name|vtopte
argument_list|(
name|va
argument_list|)
decl_stmt|;
name|pa
operator|=
operator|(
name|pa
operator|&
name|PG_FRAME
operator|)
operator||
operator|(
name|va
operator|&
operator|~
name|PG_FRAME
operator|)
expr_stmt|;
return|return
name|pa
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * macros to generate page directory/table indicies  */
end_comment

begin_define
define|#
directive|define
name|pdei
parameter_list|(
name|va
parameter_list|)
value|(((va)&PD_MASK)>>PD_SHIFT)
end_define

begin_define
define|#
directive|define
name|ptei
parameter_list|(
name|va
parameter_list|)
value|(((va)&PT_MASK)>>PG_SHIFT)
end_define

begin_comment
comment|/*  * Pmap stuff  */
end_comment

begin_struct
struct|struct
name|pmap
block|{
name|pd_entry_t
modifier|*
name|pm_pdir
decl_stmt|;
comment|/* KVA of page directory */
name|boolean_t
name|pm_pdchanged
decl_stmt|;
comment|/* pdir changed */
name|short
name|pm_dref
decl_stmt|;
comment|/* page directory ref count */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
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
comment|/*  * Macros for speed  */
end_comment

begin_define
define|#
directive|define
name|PMAP_ACTIVATE
parameter_list|(
name|pmapp
parameter_list|,
name|pcbp
parameter_list|)
define|\
value|if ((pmapp) != NULL
comment|/*&& (pmapp)->pm_pdchanged */
value|) {  \ 		(pcbp)->pcb_cr3 = \ 		    pmap_extract(kernel_pmap, (vm_offset_t)(pmapp)->pm_pdir); \ 		if ((pmapp) ==&curproc->p_vmspace->vm_pmap) \ 			load_cr3((pcbp)->pcb_cr3); \ 		(pmapp)->pm_pdchanged = FALSE; \ 	}
end_define

begin_define
define|#
directive|define
name|PMAP_DEACTIVATE
parameter_list|(
name|pmapp
parameter_list|,
name|pcbp
parameter_list|)
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
name|pmap_t
name|pv_pmap
decl_stmt|;
comment|/* pmap where mapping lies */
name|vm_offset_t
name|pv_va
decl_stmt|;
comment|/* virtual address for mapping */
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
name|KERNEL
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
name|phys_avail
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pv_entry_t
name|pv_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* array of entries, one per page */
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

begin_define
define|#
directive|define
name|pa_index
parameter_list|(
name|pa
parameter_list|)
value|atop(pa - vm_first_phys)
end_define

begin_define
define|#
directive|define
name|pa_to_pvh
parameter_list|(
name|pa
parameter_list|)
value|(&pv_table[pa_index(pa)])
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

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|pmap_activate
name|__P
argument_list|(
operator|(
name|pmap_t
operator|,
expr|struct
name|pcb
operator|*
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
name|boolean_t
name|pmap_page_exists
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
name|pt_entry_t
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_page_t
name|pmap_pte_vm_page
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
name|pmap_growkernel
name|__P
argument_list|(
operator|(
name|vm_offset_t
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
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
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
name|pmap_unuse_pt
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PMAP_H_ */
end_comment

end_unit

