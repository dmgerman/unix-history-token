begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pte.h	3.1	%H%	*/
end_comment

begin_comment
comment|/*  * VAX page table entry  *  * There are two major kinds of pte's: those which have ever existed (and are  * thus either now in core or on the swap device), and those which have  * never existed, but which will be filled on demand at first reference.  * There is a structure describing each.  There is also an ancillary  * structure used in page clustering.  */
end_comment

begin_struct
struct|struct
name|pte
block|{
name|unsigned
name|int
name|pg_pfnum
range|:
literal|21
decl_stmt|,
comment|/* core page frame number or 0 */
range|:
literal|2
decl_stmt|,
name|pg_vreadm
range|:
literal|1
decl_stmt|,
comment|/* modified since vread (or with _m) */
name|pg_swapm
range|:
literal|1
decl_stmt|,
comment|/* have to write back to swap */
name|pg_fod
range|:
literal|1
decl_stmt|,
comment|/* is fill on demand (=0) */
name|pg_m
range|:
literal|1
decl_stmt|,
comment|/* hardware maintained modified bit */
name|pg_prot
range|:
literal|4
decl_stmt|,
comment|/* access control */
name|pg_v
range|:
literal|1
decl_stmt|;
comment|/* valid bit */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hpte
block|{
name|unsigned
name|int
name|pg_pfnum
range|:
literal|21
decl_stmt|,
range|:
literal|2
decl_stmt|,
name|pg_high
range|:
literal|9
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
literal|20
decl_stmt|,
comment|/* file system block number */
name|pg_fileno
range|:
literal|5
decl_stmt|,
comment|/* file mapped from or TEXT or ZERO */
name|pg_fod
range|:
literal|1
decl_stmt|,
comment|/* is fill on demand (=1) */
range|:
literal|1
decl_stmt|,
name|pg_prot
range|:
literal|4
decl_stmt|,
name|pg_v
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|PG_M
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PG_VREADM
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PG_PFNUM
value|0x001fffff
end_define

begin_define
define|#
directive|define
name|PG_FZERO
value|(NOFILE)
end_define

begin_define
define|#
directive|define
name|PG_FTEXT
value|(NOFILE+1)
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
name|PG_KW
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PG_KR
value|0x18000000
end_define

begin_define
define|#
directive|define
name|PG_UW
value|0x20000000
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
name|PG_URKR
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
value|((pte)->pg_fod == 0&& (pte)->pg_pfnum&& \ 			    ((pte)->pg_m || (pte)->pg_swapm))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|struct
name|pte
modifier|*
name|vtopte
parameter_list|()
function_decl|;
end_function_decl

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
name|mcrmap
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

