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

begin_comment
comment|/*  * Page-directory and page-table entires follow this format, with a few  * of the fields not present here and there, depending on a lot of things.  */
end_comment

begin_comment
comment|/* ---- Intel Nomenclature ---- */
end_comment

begin_define
define|#
directive|define
name|PG_V
value|0x001
end_define

begin_comment
comment|/* P	Valid			*/
end_comment

begin_define
define|#
directive|define
name|PG_RW
value|0x002
end_define

begin_comment
comment|/* R/W	Read/Write		*/
end_comment

begin_define
define|#
directive|define
name|PG_U
value|0x004
end_define

begin_comment
comment|/* U/S  User/Supervisor		*/
end_comment

begin_define
define|#
directive|define
name|PG_NC_PWT
value|0x008
end_define

begin_comment
comment|/* PWT	Write through		*/
end_comment

begin_define
define|#
directive|define
name|PG_NC_PCD
value|0x010
end_define

begin_comment
comment|/* PCD	Cache disable		*/
end_comment

begin_define
define|#
directive|define
name|PG_A
value|0x020
end_define

begin_comment
comment|/* A	Accessed		*/
end_comment

begin_define
define|#
directive|define
name|PG_M
value|0x040
end_define

begin_comment
comment|/* D	Dirty			*/
end_comment

begin_define
define|#
directive|define
name|PG_PS
value|0x080
end_define

begin_comment
comment|/* PS	Page size (0=4k,1=4M)	*/
end_comment

begin_define
define|#
directive|define
name|PG_G
value|0x100
end_define

begin_comment
comment|/* G	Global			*/
end_comment

begin_define
define|#
directive|define
name|PG_AVAIL1
value|0x200
end_define

begin_comment
comment|/*    /	Available for system	*/
end_comment

begin_define
define|#
directive|define
name|PG_AVAIL2
value|0x400
end_define

begin_comment
comment|/*<	programmers use		*/
end_comment

begin_define
define|#
directive|define
name|PG_AVAIL3
value|0x800
end_define

begin_comment
comment|/*    \				*/
end_comment

begin_comment
comment|/* Our various interpretations of the above */
end_comment

begin_define
define|#
directive|define
name|PG_W
value|PG_AVAIL1
end_define

begin_comment
comment|/* "Wired" pseudoflag */
end_comment

begin_define
define|#
directive|define
name|PG_MANAGED
value|PG_AVAIL2
end_define

begin_define
define|#
directive|define
name|PG_FRAME
value|(~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|(PG_RW|PG_U)
end_define

begin_comment
comment|/* all protection bits . */
end_comment

begin_define
define|#
directive|define
name|PG_N
value|(PG_NC_PWT|PG_NC_PCD)
end_define

begin_comment
comment|/* Non-cacheable */
end_comment

begin_comment
comment|/*  * Page Protection Exception bits  */
end_comment

begin_define
define|#
directive|define
name|PGEX_P
value|0x01
end_define

begin_comment
comment|/* Protection violation vs. not present */
end_comment

begin_define
define|#
directive|define
name|PGEX_W
value|0x02
end_define

begin_comment
comment|/* during a Write cycle */
end_comment

begin_define
define|#
directive|define
name|PGEX_U
value|0x04
end_define

begin_comment
comment|/* access from User mode (UPL) */
end_comment

begin_comment
comment|/*  * Size of Kernel address space.  This is the number of page table pages  * (4MB each) to use for the kernel.  256 pages == 1 Gigabyte.  * This **MUST** be a multiple of 4 (eg: 252, 256, 260, etc).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KVA_PAGES
end_ifndef

begin_define
define|#
directive|define
name|KVA_PAGES
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Pte related macros  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|NKPT
end_ifndef

begin_define
define|#
directive|define
name|NKPT
value|30
end_define

begin_comment
comment|/* actual number of kernel page tables */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NKPDE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|NKPDE
value|(KVA_PAGES - 2)
end_define

begin_comment
comment|/* addressable number of page tables/pde's */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NKPDE
value|(KVA_PAGES - 1)
end_define

begin_comment
comment|/* addressable number of page tables/pde's */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The *PTDI values control the layout of virtual memory  *  * XXX This works for now, but I am not real happy with it, I'll fix it  * right after I fix locore.s and the magic 28K hole  *  * SMP_PRIVPAGES: The per-cpu address space is 0xff80000 -> 0xffbfffff  */
end_comment

begin_define
define|#
directive|define
name|APTDPTDI
value|(NPDEPG-1)
end_define

begin_comment
comment|/* alt ptd entry that points to APTD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|MPPTDI
value|(APTDPTDI-1)
end_define

begin_comment
comment|/* per cpu ptd entry */
end_comment

begin_define
define|#
directive|define
name|KPTDI
value|(MPPTDI-NKPDE)
end_define

begin_comment
comment|/* start of kernel virtual pde's */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KPTDI
value|(APTDPTDI-NKPDE)
end_define

begin_comment
comment|/* start of kernel virtual pde's */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
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
name|UMAXPTDI
value|(PTDPTDI-1)
end_define

begin_comment
comment|/* ptd entry for user space end */
end_comment

begin_define
define|#
directive|define
name|UMAXPTEOFF
value|(NPTEPG)
end_define

begin_comment
comment|/* pte entry for user space end */
end_comment

begin_comment
comment|/*  * XXX doesn't really belong here I guess...  */
end_comment

begin_define
define|#
directive|define
name|ISA_HOLE_START
value|0xa0000
end_define

begin_define
define|#
directive|define
name|ISA_HOLE_LENGTH
value|(0x100000-ISA_HOLE_START)
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
name|u_int32_t
name|pd_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|pt_entry_t
typedef|;
end_typedef

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
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|PTmap
index|[]
decl_stmt|,
name|APTmap
index|[]
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pd_entry_t
name|PTDpde
decl_stmt|,
name|APTDpde
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pd_entry_t
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
name|avtopte
parameter_list|(
name|va
parameter_list|)
value|(APTmap + i386_btop(va))
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
operator|(
name|pa
operator|=
operator|(
name|vm_offset_t
operator|)
name|PTD
index|[
name|va
operator|>>
name|PDRSHIFT
index|]
operator|)
operator|&
name|PG_PS
condition|)
block|{
name|pa
operator|=
operator|(
name|pa
operator|&
operator|~
operator|(
name|NBPDR
operator|-
literal|1
operator|)
operator|)
operator||
operator|(
name|va
operator|&
operator|(
name|NBPDR
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
block|}
else|else
block|{
name|pa
operator|=
operator|*
operator|(
name|vm_offset_t
operator|*
operator|)
name|vtopte
argument_list|(
name|va
argument_list|)
expr_stmt|;
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
name|PAGE_MASK
operator|)
expr_stmt|;
block|}
return|return
name|pa
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|(((vm_offset_t) (*vtopte(va))&PG_FRAME) | ((vm_offset_t)(va)& PAGE_MASK))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|pmap_kextract(((vm_offset_t) (va)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|avtophys
parameter_list|(
name|va
parameter_list|)
value|(((vm_offset_t) (*avtopte(va))&PG_FRAME) | ((vm_offset_t)(va)& PAGE_MASK))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_struct
struct|struct
name|pmap
block|{
name|pd_entry_t
modifier|*
name|pm_pdir
decl_stmt|;
comment|/* KVA of page directory */
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
name|pm_active
decl_stmt|;
comment|/* active on cpus */
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

begin_define
define|#
directive|define
name|pmap_resident_count
parameter_list|(
name|pmap
parameter_list|)
value|(pmap)->pm_stats.resident_count
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

begin_define
define|#
directive|define
name|NPPROVMTRR
value|8
end_define

begin_define
define|#
directive|define
name|PPRO_VMTRRphysBase0
value|0x200
end_define

begin_define
define|#
directive|define
name|PPRO_VMTRRphysMask0
value|0x201
end_define

begin_struct
struct|struct
name|ppro_vmtrr
block|{
name|u_int64_t
name|base
decl_stmt|,
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ppro_vmtrr
name|PPro_vmtrr
index|[
name|NPPROVMTRR
index|]
decl_stmt|;
end_decl_stmt

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
name|void
name|pmap_unmapdev
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

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_decl_stmt
name|void
name|pmap_set_opt
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

