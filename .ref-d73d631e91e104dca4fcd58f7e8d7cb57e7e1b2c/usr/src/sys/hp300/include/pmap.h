begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * The CMU software License Agreement specifies the terms and conditions  * for use and redistribution.  *  *	@(#)pmap.h	7.2 (Berkeley) %G%  */
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

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<hp300/include/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_statistics.h>
end_include

begin_comment
comment|/*  * HP300 hardware segment/page table entries  */
end_comment

begin_struct
struct|struct
name|ste
block|{
name|unsigned
name|int
name|sg_pfnum
range|:
literal|20
decl_stmt|;
comment|/* page table frame number */
name|unsigned
name|int
range|:
literal|8
decl_stmt|;
comment|/* reserved at 0 */
name|unsigned
name|int
range|:
literal|1
decl_stmt|;
comment|/* reserved at 1 */
name|unsigned
name|int
name|sg_prot
range|:
literal|1
decl_stmt|;
comment|/* write protect bit */
name|unsigned
name|int
name|sg_v
range|:
literal|2
decl_stmt|;
comment|/* valid bits */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pte
block|{
name|unsigned
name|int
name|pg_pfnum
range|:
literal|20
decl_stmt|;
comment|/* page frame number or 0 */
name|unsigned
name|int
range|:
literal|3
decl_stmt|;
name|unsigned
name|int
name|pg_w
range|:
literal|1
decl_stmt|;
comment|/* is wired */
name|unsigned
name|int
range|:
literal|1
decl_stmt|;
comment|/* reserved at zero */
name|unsigned
name|int
name|pg_ci
range|:
literal|1
decl_stmt|;
comment|/* cache inhibit bit */
name|unsigned
name|int
range|:
literal|1
decl_stmt|;
comment|/* reserved at zero */
name|unsigned
name|int
name|pg_m
range|:
literal|1
decl_stmt|;
comment|/* hardware modified (dirty) bit */
name|unsigned
name|int
name|pg_u
range|:
literal|1
decl_stmt|;
comment|/* hardware used (reference) bit */
name|unsigned
name|int
name|pg_prot
range|:
literal|1
decl_stmt|;
comment|/* write protect bit */
name|unsigned
name|int
name|pg_v
range|:
literal|2
decl_stmt|;
comment|/* valid bit */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ste
name|st_entry_t
typedef|;
end_typedef

begin_comment
comment|/* segment table entry */
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

begin_define
define|#
directive|define
name|PT_ENTRY_NULL
value|((pt_entry_t *) 0)
end_define

begin_define
define|#
directive|define
name|ST_ENTRY_NULL
value|((st_entry_t *) 0)
end_define

begin_define
define|#
directive|define
name|SG_V
value|0x00000002
end_define

begin_comment
comment|/* segment is valid */
end_comment

begin_define
define|#
directive|define
name|SG_NV
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SG_PROT
value|0x00000004
end_define

begin_comment
comment|/* access protection mask */
end_comment

begin_define
define|#
directive|define
name|SG_RO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SG_RW
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SG_FRAME
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|SG_IMASK
value|0xffc00000
end_define

begin_define
define|#
directive|define
name|SG_PMASK
value|0x003ff000
end_define

begin_define
define|#
directive|define
name|SG_ISHIFT
value|22
end_define

begin_define
define|#
directive|define
name|SG_PSHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PG_V
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PG_NV
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_U
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PG_M
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PG_W
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PG_RO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_RW
value|0x00000000
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
name|PG_CI
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PG_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PG_PFNUM
parameter_list|(
name|x
parameter_list|)
value|(((x)& PG_FRAME)>> PG_SHIFT)
end_define

begin_define
define|#
directive|define
name|HP_PAGE_SIZE
value|NBPG
end_define

begin_define
define|#
directive|define
name|HP_SEG_SIZE
value|NBSEG
end_define

begin_define
define|#
directive|define
name|HP_STSIZE
value|HP_PAGE_SIZE
end_define

begin_comment
comment|/* segment table size */
end_comment

begin_define
define|#
directive|define
name|HP_MAX_PTSIZE
value|HP_SEG_SIZE
end_define

begin_comment
comment|/* max size of UPT */
end_comment

begin_define
define|#
directive|define
name|HP_MAX_KPTSIZE
value|0x100000
end_define

begin_comment
comment|/* max memory to allocate to KPT */
end_comment

begin_define
define|#
directive|define
name|HP_PTBASE
value|0x10000000
end_define

begin_comment
comment|/* UPT map base address */
end_comment

begin_define
define|#
directive|define
name|HP_PTMAXSIZE
value|0x70000000
end_define

begin_comment
comment|/* UPT map maximum size */
end_comment

begin_comment
comment|/*  * Kernel virtual address to page table entry and to physical address.  */
end_comment

begin_define
define|#
directive|define
name|kvtopte
parameter_list|(
name|va
parameter_list|)
define|\
value|(&Sysmap[((unsigned)(va) - VM_MIN_KERNEL_ADDRESS)>> PGSHIFT])
end_define

begin_define
define|#
directive|define
name|ptetokv
parameter_list|(
name|pt
parameter_list|)
define|\
value|((((pt_entry_t *)(pt) - Sysmap)<< PGSHIFT) + VM_MIN_KERNEL_ADDRESS)
end_define

begin_define
define|#
directive|define
name|kvtophys
parameter_list|(
name|va
parameter_list|)
define|\
value|((kvtopte(va)->pg_pfnum<< PGSHIFT) | ((int)(va)& PGOFSET))
end_define

begin_comment
comment|/*  * Pmap stuff  */
end_comment

begin_define
define|#
directive|define
name|PMAP_NULL
value|((pmap_t) 0)
end_define

begin_struct
struct|struct
name|pmap
block|{
name|pt_entry_t
modifier|*
name|pm_ptab
decl_stmt|;
comment|/* KVA of page table */
name|st_entry_t
modifier|*
name|pm_stab
decl_stmt|;
comment|/* KVA of segment table */
name|boolean_t
name|pm_stchanged
decl_stmt|;
comment|/* ST changed */
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
name|pmap_t
name|kernel_pmap
decl_stmt|;
end_decl_stmt

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
value|if ((pmapp) != PMAP_NULL&& (pmapp)->pm_stchanged) { \ 		(pcbp)->pcb_ustp = \ 		    hp300_btop(pmap_extract(kernel_pmap, (pmapp)->pm_stab)); \ 		if ((pmapp) == u.u_procp->p_map->pmap) \ 			loadustp((pcbp)->pcb_ustp); \ 		(pmapp)->pm_stchanged = FALSE; \ 	}
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
name|st_entry_t
modifier|*
name|pv_ptste
decl_stmt|;
comment|/* non-zero if VA maps a PT page */
name|pmap_t
name|pv_ptpmap
decl_stmt|;
comment|/* if pv_ptste, pmap for PT page */
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

begin_decl_stmt
specifier|extern
name|pt_entry_t
modifier|*
name|Sysmap
decl_stmt|;
end_decl_stmt

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

