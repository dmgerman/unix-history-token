begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * %sccs.include.redist.c%  *  *	@(#)pmap.h	7.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Derived from hp300 version by Mike Hibler, this version by William  * Jolitz uses a recursive map [a pde points to the page directory] to  * map the page tables using the pagetables themselves. This is done to  * reduce the impact on kernel virtual memory for lots of sparse address  * space, and to reduce the cost of memory to each process.  *  * from hp300:	@(#)pmap.h	7.2 (Berkeley) 12/16/90  */
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
value|1
end_define

begin_comment
comment|/*  * 386 page table entry and page table directory  * W.Jolitz, 8/89  */
end_comment

begin_struct
struct|struct
name|pde
block|{
name|unsigned
name|int
name|pd_v
range|:
literal|1
decl_stmt|,
comment|/* valid bit */
name|pd_prot
range|:
literal|2
decl_stmt|,
comment|/* access control */
name|pd_mbz1
range|:
literal|2
decl_stmt|,
comment|/* reserved, must be zero */
name|pd_u
range|:
literal|1
decl_stmt|,
comment|/* hardware maintained 'used' bit */
range|:
literal|1
decl_stmt|,
comment|/* not used */
name|pd_mbz2
range|:
literal|2
decl_stmt|,
comment|/* reserved, must be zero */
range|:
literal|3
decl_stmt|,
comment|/* reserved for software */
name|pd_pfnum
range|:
literal|20
decl_stmt|;
comment|/* physical page frame number of pte's*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PD_MASK
value|0xffc00000
end_define

begin_comment
comment|/* page directory address bits */
end_comment

begin_define
define|#
directive|define
name|PT_MASK
value|0x003ff000
end_define

begin_comment
comment|/* page table address bits */
end_comment

begin_define
define|#
directive|define
name|PD_SHIFT
value|22
end_define

begin_comment
comment|/* page directory address shift */
end_comment

begin_define
define|#
directive|define
name|PG_SHIFT
value|12
end_define

begin_comment
comment|/* page table address shift */
end_comment

begin_struct
struct|struct
name|pte
block|{
name|unsigned
name|int
name|pg_v
range|:
literal|1
decl_stmt|,
comment|/* valid bit */
name|pg_prot
range|:
literal|2
decl_stmt|,
comment|/* access control */
name|pg_mbz1
range|:
literal|2
decl_stmt|,
comment|/* reserved, must be zero */
name|pg_u
range|:
literal|1
decl_stmt|,
comment|/* hardware maintained 'used' bit */
name|pg_m
range|:
literal|1
decl_stmt|,
comment|/* hardware maintained modified bit */
name|pg_mbz2
range|:
literal|2
decl_stmt|,
comment|/* reserved, must be zero */
name|pg_w
range|:
literal|1
decl_stmt|,
comment|/* software, wired down page */
range|:
literal|1
decl_stmt|,
comment|/* software (unused) */
name|pg_nc
range|:
literal|1
decl_stmt|,
comment|/* 'uncacheable page' bit */
name|pg_pfnum
range|:
literal|20
decl_stmt|;
comment|/* physical page frame number */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PG_V
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PG_RO
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PG_RW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PG_u
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|0x00000006
end_define

begin_comment
comment|/* all protection bits . */
end_comment

begin_define
define|#
directive|define
name|PG_W
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PG_N
value|0x00000800
end_define

begin_comment
comment|/* Non-cacheable */
end_comment

begin_define
define|#
directive|define
name|PG_M
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PG_U
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PG_FRAME
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|PG_NOACC
value|0
end_define

begin_define
define|#
directive|define
name|PG_KR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PG_KW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PG_URKR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_URKW
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_UW
value|0x00000006
end_define

begin_comment
comment|/* Garbage for current bastardized pager that assumes a hp300 */
end_comment

begin_define
define|#
directive|define
name|PG_NV
value|0
end_define

begin_define
define|#
directive|define
name|PG_CI
value|0
end_define

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

begin_typedef
typedef|typedef
name|struct
name|pde
name|pd_entry_t
typedef|;
end_typedef

begin_comment
comment|/* page directory entry */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pte
name|pt_entry_t
typedef|;
end_typedef

begin_comment
comment|/* Mach page table entry */
end_comment

begin_comment
comment|/*  * One page directory, shared between  * kernel and user modes.  */
end_comment

begin_define
define|#
directive|define
name|I386_PAGE_SIZE
value|NBPG
end_define

begin_define
define|#
directive|define
name|I386_PDR_SIZE
value|NBPDR
end_define

begin_define
define|#
directive|define
name|I386_KPDES
value|8
end_define

begin_comment
comment|/* KPT page directory size */
end_comment

begin_define
define|#
directive|define
name|I386_UPDES
value|NBPDR/sizeof(struct pde)-8
end_define

begin_comment
comment|/* UPT page directory size */
end_comment

begin_define
define|#
directive|define
name|UPTDI
value|0x3f6
end_define

begin_comment
comment|/* ptd entry for u./kernel&user stack */
end_comment

begin_define
define|#
directive|define
name|PTDPTDI
value|0x3f7
end_define

begin_comment
comment|/* ptd entry that points to ptd! */
end_comment

begin_define
define|#
directive|define
name|KPTDI_FIRST
value|0x3f8
end_define

begin_comment
comment|/* start of kernel virtual pde's */
end_comment

begin_define
define|#
directive|define
name|KPTDI_LAST
value|0x3fA
end_define

begin_comment
comment|/* last of kernel virtual pde's */
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
name|struct
name|pte
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
name|struct
name|pde
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
name|pt_entry_t
modifier|*
name|Sysmap
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
value|(i386_ptob(vtopte(va)->pg_pfnum) | ((int)(va)& PGOFSET))
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
value|(i386_ptob(avtopte(va)->pg_pfnum) | ((int)(va)& PGOFSET))
end_define

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
value|(((va)&PT_MASK)>>PT_SHIFT)
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
value|) {  \ 		(pcbp)->pcb_cr3 = \ 		    pmap_extract(kernel_pmap, (pmapp)->pm_pdir); \ 		if ((pmapp) ==&curproc->p_vmspace->vm_pmap) \ 			load_cr3((pcbp)->pcb_cr3); \ 		(pmapp)->pm_pdchanged = FALSE; \ 	}
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
name|pv_entry_t
name|pv_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* array of entries, one per page */
end_comment

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

begin_define
define|#
directive|define
name|pmap_wired_count
parameter_list|(
name|pmap
parameter_list|)
value|((pmap)->pm_stats.wired_count)
end_define

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

begin_endif
endif|#
directive|endif
endif|_PMAP_MACHINE_
end_endif

end_unit

