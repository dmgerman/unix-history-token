begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1991, 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: hp300/include/pmap.h	7.11 (Berkeley) 12/27/92  *  *	@(#)pmap.h	7.5 (Berkeley) %G%  */
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

begin_define
define|#
directive|define
name|LUNA_PAGE_SIZE
value|NBPG
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUNA2
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUNA_SEG_SIZE
value|(mmutype == MMU_68040 ? 0x40000 : NBSEG)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LUNA_SEG_SIZE
value|NBSEG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|luna_trunc_seg
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x))& ~(LUNA_SEG_SIZE-1))
end_define

begin_define
define|#
directive|define
name|luna_round_seg
parameter_list|(
name|x
parameter_list|)
value|luna_trunc_seg((unsigned)(x) + LUNA_SEG_SIZE-1)
end_define

begin_comment
comment|/*  * Pmap stuff  */
end_comment

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|pte
modifier|*
name|pm_ptab
decl_stmt|;
comment|/* KVA of page table */
name|struct
name|ste
modifier|*
name|pm_stab
decl_stmt|;
comment|/* KVA of segment table */
name|int
name|pm_stchanged
decl_stmt|;
comment|/* ST changed */
name|int
name|pm_stfree
decl_stmt|;
comment|/* 040: free lev2 blocks */
name|struct
name|ste
modifier|*
name|pm_stpa
decl_stmt|;
comment|/* 040: ST phys addr */
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
name|kernel_pmap
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
value|((pm) == kernel_pmap || (pm) == curproc->p_vmspace->vm_map.pmap)
end_define

begin_comment
comment|/*  * On the 040 we keep track of which level 2 blocks are already in use  * with the pm_stfree mask.  Bits are arranged from LSB (block 0) to MSB  * (block 31).  For convenience, the level 1 table is considered to be  * block 0.  *  * MAX[KU]L2SIZE control how many pages of level 2 descriptors are allowed.  * for the kernel and users.  8 implies only the initial "segment table"  * page is used.  WARNING: don't change MAXUL2SIZE unless you can allocate  * physically contiguous pages for the ST in pmap.c!  */
end_comment

begin_define
define|#
directive|define
name|MAXKL2SIZE
value|16
end_define

begin_define
define|#
directive|define
name|MAXUL2SIZE
value|8
end_define

begin_define
define|#
directive|define
name|l2tobm
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_define
define|#
directive|define
name|bmtol2
parameter_list|(
name|n
parameter_list|)
value|(ffs(n) - 1)
end_define

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
parameter_list|,
name|iscurproc
parameter_list|)
define|\
value|if ((pmapp) != NULL&& (pmapp)->pm_stchanged) { \ 		(pcbp)->pcb_ustp = luna_btop((vm_offset_t)(pmapp)->pm_stpa); \ 		if (iscurproc) \ 			loadustp((pcbp)->pcb_ustp); \ 		(pmapp)->pm_stchanged = FALSE; \ 	}
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
name|struct
name|ste
modifier|*
name|pv_ptste
decl_stmt|;
comment|/* non-zero if VA maps a PT page */
name|struct
name|pmap
modifier|*
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
name|PV_CI
value|0x01
end_define

begin_comment
comment|/* header: all entries are cache inhibited */
end_comment

begin_define
define|#
directive|define
name|PV_PTPAGE
value|0x02
end_define

begin_comment
comment|/* header: entry maps a page table page */
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

begin_decl_stmt
specifier|extern
name|struct
name|pte
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

begin_comment
comment|/*  * definitions LUNA IO space mapping  */
end_comment

begin_struct
struct|struct
name|physmap
block|{
name|int
name|pm_phys
decl_stmt|;
name|int
name|pm_size
decl_stmt|;
name|int
name|pm_cache
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|_PMAP_MACHINE_
end_endif

end_unit

