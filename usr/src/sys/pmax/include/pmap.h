begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)pmap.h	7.6 (Berkeley) %G%  */
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
comment|/*  * TLB hash table values.  * SHIFT2 should shift virtual address bit 22 to the high bit of the index.  *			address:	index:  *	USRTEXT		0x00400000	10xxxxxxx  *	USRDATA		0x10000000	00xxxxxxx  *	USRSTACK	0x7FFFFFFF	11xxxxxxx  * This gives 1/2 the table to data, 1/4 for text and 1/4 for stack.  * Note: the current process has its hash table mapped at PMAP_HASH_UADDR.  *	the kernel's hash table is mapped at PMAP_HASH_KADDR.  *	The size of the hash table is known in locore.s.  * The wired entries in the TLB will contain the following:  *	UPAGES			(for curproc)  *	PMAP_HASH_UPAGES	(for curproc)  *	PMAP_HASH_KPAGES	(for kernel)  * The kernel doesn't actually use a pmap_hash_t, the pm_hash field is NULL and  * all the PTE entries are stored in a single array at PMAP_HASH_KADDR.  * If we need more KPAGES that the TLB has wired entries, then we can switch  * to a global pointer for the kernel TLB table.  * If we try to use a hash table for the kernel, wired TLB entries become a  * problem.  * Note: PMAP_HASH_UPAGES should be a multiple of MACH pages (see pmap_enter()).  */
end_comment

begin_define
define|#
directive|define
name|PMAP_HASH_UPAGES
value|1
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_KPAGES
value|5
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_UADDR
value|(UADDR - PMAP_HASH_UPAGES * NBPG)
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_KADDR
value|(UADDR - (PMAP_HASH_UPAGES + PMAP_HASH_KPAGES) * NBPG)
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_NUM_ENTRIES
value|256
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_SIZE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_SHIFT1
value|12
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_SHIFT2
value|21
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_MASK1
value|0x07f
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_MASK2
value|0x080
end_define

begin_define
define|#
directive|define
name|PMAP_HASH_SIZE
value|(PMAP_HASH_NUM_ENTRIES*sizeof(struct pmap_hash))
end_define

begin_comment
comment|/* compute pointer to pmap hash table */
end_comment

begin_define
define|#
directive|define
name|PMAP_HASH
parameter_list|(
name|va
parameter_list|)
define|\
value|((((va)>> PMAP_HASH_SHIFT1)& PMAP_HASH_MASK1) | \ 	 (((va)>> PMAP_HASH_SHIFT2)& PMAP_HASH_MASK2))
end_define

begin_comment
comment|/*  * A TLB hash entry.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pmap_hash
block|{
struct|struct
block|{
name|u_int
name|low
decl_stmt|;
comment|/* The TLB low register value. */
name|u_int
name|high
decl_stmt|;
comment|/* The TLB high register value. */
block|}
name|pmh_pte
index|[
literal|2
index|]
struct|;
block|}
typedef|*
name|pmap_hash_t
typedef|;
end_typedef

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
name|pm_flags
decl_stmt|;
comment|/* see below */
name|int
name|pm_tlbpid
decl_stmt|;
comment|/* address space tag */
name|pmap_hash_t
name|pm_hash
decl_stmt|;
comment|/* TLB cache */
name|unsigned
name|pm_hash_ptes
index|[
name|PMAP_HASH_UPAGES
index|]
decl_stmt|;
block|}
typedef|*
name|pmap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PM_MODIFIED
value|1
end_define

begin_comment
comment|/* flush tlbpid before resume() */
end_comment

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

