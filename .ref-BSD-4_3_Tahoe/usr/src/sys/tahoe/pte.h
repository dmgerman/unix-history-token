begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pte.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * Tahoe page table entry  *  * There are two major kinds of pte's: those which have ever existed (and are  * thus either now in core or on the swap device), and those which have  * never existed, but which will be filled on demand at first reference.  * There is a structure describing each.  There is also an ancillary  * structure used in page clustering.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

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
literal|4
decl_stmt|,
comment|/* access control */
name|pg_fod
range|:
literal|1
decl_stmt|,
comment|/* is fill on demand (=0) */
range|:
literal|1
decl_stmt|,
comment|/* must write back to swap (unused) */
name|pg_nc
range|:
literal|1
decl_stmt|,
comment|/* 'uncacheable page' bit */
name|pg_m
range|:
literal|1
decl_stmt|,
comment|/* hardware maintained modified bit */
name|pg_u
range|:
literal|1
decl_stmt|,
comment|/* hardware maintained 'used' bit */
name|pg_pfnum
range|:
literal|22
decl_stmt|;
comment|/* core page frame number or 0 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hpte
block|{
name|unsigned
name|int
name|pg_high
range|:
literal|10
decl_stmt|,
comment|/* special for clustering */
name|pg_pfnum
range|:
literal|22
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpte
block|{
name|unsigned
name|int
name|pg_v
range|:
literal|1
decl_stmt|,
name|pg_prot
range|:
literal|4
decl_stmt|,
name|pg_fod
range|:
literal|1
decl_stmt|,
comment|/* is fill on demand (=1) */
range|:
literal|1
decl_stmt|,
name|pg_fileno
range|:
literal|1
decl_stmt|,
comment|/* file mapped from or TEXT or ZERO */
name|pg_blkno
range|:
literal|24
decl_stmt|;
comment|/* file system block number */
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
name|PG_V
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|0x78000000
end_define

begin_comment
comment|/* all protection bits  (dorit). */
end_comment

begin_define
define|#
directive|define
name|PG_FOD
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PG_SWAPM
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PG_N
value|0x01000000
end_define

begin_comment
comment|/* Non-cacheable */
end_comment

begin_define
define|#
directive|define
name|PG_M
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PG_U
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PG_PFNUM
value|0x003fffff
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
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PG_KW
value|0x60000000
end_define

begin_define
define|#
directive|define
name|PG_URKR
value|0x50000000
end_define

begin_define
define|#
directive|define
name|PG_URKW
value|0x70000000
end_define

begin_define
define|#
directive|define
name|PG_UW
value|0x78000000
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
value|(&Sysmap[((int)(va)&~ KERNBASE)>> PGSHIFT])
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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

