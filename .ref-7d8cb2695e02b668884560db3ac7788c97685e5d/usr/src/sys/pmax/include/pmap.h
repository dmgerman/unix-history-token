begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)pmap.h	7.8 (Berkeley) %G%  */
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

begin_comment
comment|/*  * The user address space is 2Gb (0x0 - 0x80000000).  * User programs are laid out in memory as follows:  *			address  *	USRTEXT		0x00001000  *	USRDATA		USRTEXT + text_size  *	USRSTACK	0x7FFFFFFF  *  * The user address space is mapped using a two level structure where  * virtual address bits 30..22 are used to index into a segment table which  * points to a page worth of PTEs (4096 page can hold 1024 PTEs).  * Bits 21..12 are then used to index a PTE which describes a page within   * a segment.  *  * The wired entries in the TLB will contain the following:  *	0-1	(UPAGES)	for curproc user struct and kernel stack.  *  * Note: The kernel doesn't use the same data structures as user programs.  * All the PTE entries are stored in a single array in Sysmap which is  * dynamically allocated at boot time.  */
end_comment

begin_define
define|#
directive|define
name|pmax_trunc_seg
parameter_list|(
name|x
parameter_list|)
value|((vm_offset_t)(x)& ~SEGOFSET)
end_define

begin_define
define|#
directive|define
name|pmax_round_seg
parameter_list|(
name|x
parameter_list|)
value|(((vm_offset_t)(x) + SEGOFSET)& ~SEGOFSET)
end_define

begin_define
define|#
directive|define
name|pmap_segmap
parameter_list|(
name|m
parameter_list|,
name|v
parameter_list|)
value|((m)->pm_segtab->seg_tab[((v)>> SEGSHIFT)])
end_define

begin_define
define|#
directive|define
name|PMAP_SEGTABSIZE
value|512
end_define

begin_union_decl
union_decl|union
name|pt_entry
union_decl|;
end_union_decl

begin_struct
struct|struct
name|segtab
block|{
name|union
name|pt_entry
modifier|*
name|seg_tab
index|[
name|PMAP_SEGTABSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Machine dependent pmap structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pmap
block|{
name|int
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
name|int
name|pm_tlbpid
decl_stmt|;
comment|/* address space tag */
name|u_int
name|pm_tlbgen
decl_stmt|;
comment|/* TLB PID generation number */
name|struct
name|segtab
modifier|*
name|pm_segtab
decl_stmt|;
comment|/* pointers to pages of PTEs */
block|}
typedef|*
name|pmap_t
typedef|;
end_typedef

begin_comment
comment|/*  * Defines for pmap_attributes[phys_mach_page];  */
end_comment

begin_define
define|#
directive|define
name|PMAP_ATTR_MOD
value|0x01
end_define

begin_comment
comment|/* page has been modified */
end_comment

begin_define
define|#
directive|define
name|PMAP_ATTR_REF
value|0x02
end_define

begin_comment
comment|/* page has been referenced */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pmap_attributes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reference and modify bits */
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
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PMAP_MACHINE_ */
end_comment

end_unit

