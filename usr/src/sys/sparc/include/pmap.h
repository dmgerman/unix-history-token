begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)pmap.h	7.5 (Berkeley) %G%  *  * from: $Header: pmap.h,v 1.11 93/05/25 10:36:09 torek Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC_PMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC_PMAP_H_
end_define

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_comment
comment|/*  * Pmap structure.  *  * The pmap structure really comes in two variants, one---a single  * instance---for kernel virtual memory and the other---up to nproc  * instances---for user virtual memory.  Unfortunately, we have to mash  * both into the same structure.  Fortunately, they are almost the same.  *  * The kernel begins at 0xf8000000 and runs to 0xffffffff (although  * some of this is not actually used).  Kernel space, including DVMA  * space (for now?), is mapped identically into all user contexts.  * There is no point in duplicating this mapping in each user process  * so they do not appear in the user structures.  *  * User space begins at 0x00000000 and runs through 0x1fffffff,  * then has a `hole', then resumes at 0xe0000000 and runs until it  * hits the kernel space at 0xf8000000.  This can be mapped  * contiguously by ignorning the top two bits and pretending the  * space goes from 0 to 37ffffff.  Typically the lower range is  * used for text+data and the upper for stack, but the code here  * makes no such distinction.  *  * Since each virtual segment covers 256 kbytes, the user space  * requires 3584 segments, while the kernel (including DVMA) requires  * only 512 segments.  *  * The segment map entry for virtual segment vseg is offset in  * pmap->pm_rsegmap by 0 if pmap is not the kernel pmap, or by  * NUSEG if it is.  We keep a pointer called pmap->pm_segmap  * pre-offset by this value.  pmap->pm_segmap thus contains the  * values to be loaded into the user portion of the hardware segment  * map so as to reach the proper PMEGs within the MMU.  The kernel  * mappings are `set early' and are always valid in every context  * (every change is always propagated immediately).  *  * The PMEGs within the MMU are loaded `on demand'; when a PMEG is  * taken away from context `c', the pmap for context c has its  * corresponding pm_segmap[vseg] entry marked invalid (the MMU segment  * map entry is also made invalid at the same time).  Thus  * pm_segmap[vseg] is the `invalid pmeg' number (127 or 511) whenever  * the corresponding PTEs are not actually in the MMU.  On the other  * hand, pm_pte[vseg] is NULL only if no pages in that virtual segment  * are in core; otherwise it points to a copy of the 32 or 64 PTEs that  * must be loaded in the MMU in order to reach those pages.  * pm_npte[vseg] counts the number of valid pages in each vseg.  *  * XXX performance: faster to count valid bits?  *  * The kernel pmap cannot malloc() PTEs since malloc() will sometimes  * allocate a new virtual segment.  Since kernel mappings are never  * `stolen' out of the the MMU, we just keep all its PTEs there, and  * have no software copies.  Its mmu entries are nonetheless kept on lists  * so that the code that fiddles with mmu lists has something to fiddle.  */
end_comment

begin_define
define|#
directive|define
name|NKSEG
value|((int)((-(unsigned)KERNBASE) / NBPSG))
end_define

begin_comment
comment|/* i.e., 512 */
end_comment

begin_define
define|#
directive|define
name|NUSEG
value|(4096 - NKSEG)
end_define

begin_comment
comment|/* i.e., 3584 */
end_comment

begin_comment
comment|/* data appearing in both user and kernel pmaps */
end_comment

begin_struct
struct|struct
name|pmap_common
block|{
name|union
name|ctxinfo
modifier|*
name|pmc_ctx
decl_stmt|;
comment|/* current context, if any */
name|int
name|pmc_ctxnum
decl_stmt|;
comment|/* current context's number */
if|#
directive|if
name|NCPUS
operator|>
literal|1
name|simple_lock_data_t
name|pmc_lock
decl_stmt|;
comment|/* spinlock */
endif|#
directive|endif
name|int
name|pmc_refcount
decl_stmt|;
comment|/* just what it says */
name|struct
name|mmuentry
modifier|*
name|pmc_mmuforw
decl_stmt|;
comment|/* pmap pmeg chain */
name|struct
name|mmuentry
modifier|*
modifier|*
name|pmc_mmuback
decl_stmt|;
comment|/* (two way street) */
name|pmeg_t
modifier|*
name|pmc_segmap
decl_stmt|;
comment|/* points to pm_rsegmap per above */
name|u_char
modifier|*
name|pmc_npte
decl_stmt|;
comment|/* points to pm_rnpte */
name|int
modifier|*
modifier|*
name|pmc_pte
decl_stmt|;
comment|/* points to pm_rpte */
block|}
struct|;
end_struct

begin_comment
comment|/* data appearing only in user pmaps */
end_comment

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|pmap_common
name|pmc
decl_stmt|;
name|pmeg_t
name|pm_rsegmap
index|[
name|NUSEG
index|]
decl_stmt|;
comment|/* segment map */
name|u_char
name|pm_rnpte
index|[
name|NUSEG
index|]
decl_stmt|;
comment|/* number of valid PTEs per seg */
name|int
modifier|*
name|pm_rpte
index|[
name|NUSEG
index|]
decl_stmt|;
comment|/* points to PTEs for valid segments */
block|}
struct|;
end_struct

begin_comment
comment|/* data appearing only in the kernel pmap */
end_comment

begin_struct
struct|struct
name|kpmap
block|{
name|struct
name|pmap_common
name|pmc
decl_stmt|;
name|pmeg_t
name|pm_rsegmap
index|[
name|NKSEG
index|]
decl_stmt|;
comment|/* segment map */
name|u_char
name|pm_rnpte
index|[
name|NKSEG
index|]
decl_stmt|;
comment|/* number of valid PTEs per kseg */
name|int
modifier|*
name|pm_rpte
index|[
name|NKSEG
index|]
decl_stmt|;
comment|/* always NULL */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pm_ctx
value|pmc.pmc_ctx
end_define

begin_define
define|#
directive|define
name|pm_ctxnum
value|pmc.pmc_ctxnum
end_define

begin_define
define|#
directive|define
name|pm_lock
value|pmc.pmc_lock
end_define

begin_define
define|#
directive|define
name|pm_refcount
value|pmc.pmc_refcount
end_define

begin_define
define|#
directive|define
name|pm_mmuforw
value|pmc.pmc_mmuforw
end_define

begin_define
define|#
directive|define
name|pm_mmuback
value|pmc.pmc_mmuback
end_define

begin_define
define|#
directive|define
name|pm_segmap
value|pmc.pmc_segmap
end_define

begin_define
define|#
directive|define
name|pm_npte
value|pmc.pmc_npte
end_define

begin_define
define|#
directive|define
name|pm_pte
value|pmc.pmc_pte
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|pmap
modifier|*
name|pmap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PMAP_NULL
value|((pmap_t)0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|kpmap
name|kernel_pmap_store
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|kernel_pmap
value|((struct pmap *)(&kernel_pmap_store))
end_define

begin_define
define|#
directive|define
name|PMAP_ACTIVATE
parameter_list|(
name|pmap
parameter_list|,
name|pcb
parameter_list|,
name|iscurproc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PMAP_DEACTIVATE
parameter_list|(
name|pmap
parameter_list|,
name|pcb
parameter_list|)
end_define

begin_comment
comment|/*  * Since PTEs also contain type bits, we have to have some way  * to tell pmap_enter `this is an IO page' or `this is not to  * be cached'.  Since physical addresses are always aligned, we  * can do this with the low order bits.  *  * The ordering below is important: PMAP_PGTYPE<< PG_TNC must give  * exactly the PG_NC and PG_TYPE bits.  */
end_comment

begin_define
define|#
directive|define
name|PMAP_OBIO
value|1
end_define

begin_comment
comment|/* tells pmap_enter to use PG_OBIO */
end_comment

begin_define
define|#
directive|define
name|PMAP_VME16
value|2
end_define

begin_comment
comment|/* etc */
end_comment

begin_define
define|#
directive|define
name|PMAP_VME32
value|3
end_define

begin_comment
comment|/* etc */
end_comment

begin_define
define|#
directive|define
name|PMAP_NC
value|4
end_define

begin_comment
comment|/* tells pmap_enter to set PG_NC */
end_comment

begin_define
define|#
directive|define
name|PMAP_TNC
value|7
end_define

begin_comment
comment|/* mask to get PG_TYPE& PG_NC */
end_comment

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
comment|/* _SPARC_PMAP_H_ */
end_comment

end_unit

