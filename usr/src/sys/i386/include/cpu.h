begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)cpu.h	1.2 (Berkeley) 3/13/87  */
end_comment

begin_comment
comment|/*  * Assorted definitions unique to TAHOE CPU support.  */
end_comment

begin_define
define|#
directive|define
name|uncache
parameter_list|(
name|v
parameter_list|)
value|mtpr(PDCS, (caddr_t)(v))
end_define

begin_define
define|#
directive|define
name|movow
parameter_list|(
name|a
parameter_list|,
name|w
parameter_list|)
value|_movow((u_short *)(a), (u_short)(w))
end_define

begin_define
define|#
directive|define
name|movob
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_movob((u_char *)(a), (u_char)(b))
end_define

begin_define
define|#
directive|define
name|resettodr
parameter_list|()
end_define

begin_comment
comment|/* no todr to set */
end_comment

begin_define
define|#
directive|define
name|MAXCKEY
value|255
end_define

begin_comment
comment|/* maximal allowed code key */
end_comment

begin_define
define|#
directive|define
name|MAXDKEY
value|255
end_define

begin_comment
comment|/* maximal allowed data key */
end_comment

begin_define
define|#
directive|define
name|NCKEY
value|(MAXCKEY+1)
end_define

begin_comment
comment|/* # code keys, including 0 (reserved) */
end_comment

begin_define
define|#
directive|define
name|NDKEY
value|(MAXDKEY+1)
end_define

begin_comment
comment|/* # data keys, including 0 (reserved) */
end_comment

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

begin_decl_stmt
name|char
name|ckey_cache
index|[
name|NCKEY
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 =>'s key i may be in code cache */
end_comment

begin_decl_stmt
name|short
name|ckey_cnt
index|[
name|NCKEY
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* code key reference count */
end_comment

begin_decl_stmt
name|char
name|dkey_cache
index|[
name|NDKEY
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 =>'s key i may be in data cache */
end_comment

begin_decl_stmt
name|short
name|dkey_cnt
index|[
name|NDKEY
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data key reference count */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Statistics maintained for code and  * data cache key allocations algorithms.  */
end_comment

begin_struct
struct|struct
name|keystats
block|{
name|long
name|ks_avail
decl_stmt|;
comment|/* number of keys currently unallocated */
name|long
name|ks_dirty
decl_stmt|;
comment|/* number of keys currently waiting for purge */
name|long
name|ks_allocs
decl_stmt|;
comment|/* number of keys allocated */
name|long
name|ks_allocfree
decl_stmt|;
comment|/* key allocated from free slot */
name|long
name|ks_norefs
decl_stmt|;
comment|/* key marked in use, but refcnt 0 */
name|long
name|ks_taken
decl_stmt|;
comment|/* key taken from single process */
name|long
name|ks_shared
decl_stmt|;
comment|/* key taken from multiple processes */
name|long
name|ks_inval
decl_stmt|;
comment|/* number of times keys exchanged */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|long
modifier|*
name|user_psl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user mode psl for ast's */
end_comment

begin_decl_stmt
name|int
name|intenable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupts enable startup flag */
end_comment

begin_decl_stmt
name|int
name|clk_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock enable startup flag */
end_comment

begin_comment
comment|/*  * Enable realtime clock.  */
end_comment

begin_define
define|#
directive|define
name|enablertclock
parameter_list|()
value|(clk_enable = 1)
end_define

end_unit

