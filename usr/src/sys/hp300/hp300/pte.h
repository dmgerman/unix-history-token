begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: pte.h 1.11 89/09/03$  *  *	@(#)pte.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * HP300 page table entry  *  * There are two major kinds of pte's: those which have ever existed (and are  * thus either now in core or on the swap device), and those which have  * never existed, but which will be filled on demand at first reference.  * There is a structure describing each.  There is also an ancillary  * structure used in page clustering.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|ste
block|{
name|unsigned
name|int
name|sg_pfnum
range|:
literal|20
decl_stmt|,
comment|/* page table frame number */
range|:
literal|8
decl_stmt|,
comment|/* reserved at 0 */
range|:
literal|1
decl_stmt|,
comment|/* reserved at 1 */
name|sg_prot
range|:
literal|1
decl_stmt|,
comment|/* write protect bit */
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
decl_stmt|,
comment|/* page frame number or 0 */
range|:
literal|3
decl_stmt|,
name|pg_fod
range|:
literal|1
decl_stmt|,
comment|/* is fill on demand (=0) */
range|:
literal|1
decl_stmt|,
comment|/* reserved at zero */
name|pg_ci
range|:
literal|1
decl_stmt|,
comment|/* cache inhibit bit */
range|:
literal|1
decl_stmt|,
comment|/* reserved at zero */
name|pg_m
range|:
literal|1
decl_stmt|,
comment|/* hardware modified (dirty) bit */
name|pg_u
range|:
literal|1
decl_stmt|,
comment|/* hardware used (reference) bit */
name|pg_prot
range|:
literal|1
decl_stmt|,
comment|/* write protect bit */
name|pg_v
range|:
literal|2
decl_stmt|;
comment|/* valid bit */
block|}
struct|;
end_struct

begin_comment
comment|/* not used */
end_comment

begin_struct
struct|struct
name|hpte
block|{
name|unsigned
name|int
name|pg_pfnum
range|:
literal|20
decl_stmt|,
name|pg_high
range|:
literal|12
decl_stmt|;
comment|/* special for clustering */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpte
block|{
name|unsigned
name|int
name|pg_blkno
range|:
literal|22
decl_stmt|,
comment|/* file system block number */
name|pg_fileno
range|:
literal|1
decl_stmt|,
comment|/* file mapped from or TEXT or ZERO */
name|pg_fod
range|:
literal|1
decl_stmt|,
comment|/* is fill on demand (=1) */
range|:
literal|6
decl_stmt|,
name|pg_v
range|:
literal|2
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SG_V
value|0x00000002
end_define

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
name|PG_FOD
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
name|PG_PFNUM
parameter_list|(
name|x
parameter_list|)
value|(((x)& PG_FRAME)>> PGSHIFT)
end_define

begin_comment
comment|/*  * Pseudo protections.  * Note that PG_URKW is not defined intuitively, but it is currently only  * used in vgetu() to initialize the u-area PTEs in the process address  * space.  Since the kernel never accesses the u-area thru these we are ok.  */
end_comment

begin_define
define|#
directive|define
name|PG_KW
value|PG_RW
end_define

begin_define
define|#
directive|define
name|PG_URKR
value|PG_RO
end_define

begin_define
define|#
directive|define
name|PG_URKW
value|PG_RO
end_define

begin_define
define|#
directive|define
name|PG_UW
value|PG_RW
end_define

begin_define
define|#
directive|define
name|PG_FZERO
value|0
end_define

begin_define
define|#
directive|define
name|PG_FTEXT
value|1
end_define

begin_define
define|#
directive|define
name|PG_FMAX
value|(PG_FTEXT)
end_define

begin_comment
comment|/*  * Pte related macros  */
end_comment

begin_define
define|#
directive|define
name|dirty
parameter_list|(
name|pte
parameter_list|)
value|((pte)->pg_m)
end_define

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
value|(&Sysmap[((unsigned)(va)&~ KERNBASE)>> PGSHIFT])
end_define

begin_define
define|#
directive|define
name|ptetokv
parameter_list|(
name|pt
parameter_list|)
value|((((struct pte *)(pt) - Sysmap)<< PGSHIFT) | KERNBASE)
end_define

begin_define
define|#
directive|define
name|kvtophys
parameter_list|(
name|x
parameter_list|)
value|((kvtopte(x)->pg_pfnum<< PGSHIFT) | ((int)(x)& PGOFSET))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_comment
comment|/* utilities defined in locore.s */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Sysmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Usrptmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|usrpt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Swapmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Forkmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Xswapmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Xswap2map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Pushmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Vfmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|mmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|msgbufmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|kmempt
index|[]
decl_stmt|,
name|ekmempt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ste
name|Sysseg
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(KERNEL)&& !defined(LOCORE) */
end_comment

end_unit

