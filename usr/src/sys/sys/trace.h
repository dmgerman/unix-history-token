begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	trace.h	4.3	81/03/03	*/
end_comment

begin_comment
comment|/*  * File system buffer tracing points; all trace<dev, bn>  */
end_comment

begin_define
define|#
directive|define
name|TR_BREAD
value|0
end_define

begin_comment
comment|/* buffer read */
end_comment

begin_define
define|#
directive|define
name|TR_BWRITE
value|1
end_define

begin_comment
comment|/* buffer written */
end_comment

begin_define
define|#
directive|define
name|TR_MISS
value|2
end_define

begin_comment
comment|/* cache miss */
end_comment

begin_define
define|#
directive|define
name|TR_HIT
value|3
end_define

begin_comment
comment|/* cache hit */
end_comment

begin_define
define|#
directive|define
name|TR_RA
value|4
end_define

begin_comment
comment|/* read ahead */
end_comment

begin_define
define|#
directive|define
name|TR_XFOD
value|5
end_define

begin_comment
comment|/* exe fod read */
end_comment

begin_define
define|#
directive|define
name|TR_BRELSE
value|6
end_define

begin_comment
comment|/* brelse */
end_comment

begin_comment
comment|/*  * Memory allocator trace points; all trace the amount of memory involved  */
end_comment

begin_define
define|#
directive|define
name|TR_MALL
value|10
end_define

begin_comment
comment|/* memory allocated */
end_comment

begin_comment
comment|/*  * Paging trace points: all are<vaddr, pid>  */
end_comment

begin_define
define|#
directive|define
name|TR_INTRANS
value|20
end_define

begin_comment
comment|/* page intransit block */
end_comment

begin_define
define|#
directive|define
name|TR_EINTRANS
value|21
end_define

begin_comment
comment|/* page intransit wait done */
end_comment

begin_define
define|#
directive|define
name|TR_FRECLAIM
value|22
end_define

begin_comment
comment|/* reclaim from free list */
end_comment

begin_define
define|#
directive|define
name|TR_RECLAIM
value|23
end_define

begin_comment
comment|/* reclaim from loop */
end_comment

begin_define
define|#
directive|define
name|TR_XSFREC
value|24
end_define

begin_comment
comment|/* reclaim from free list instead of drum */
end_comment

begin_define
define|#
directive|define
name|TR_XIFREC
value|25
end_define

begin_comment
comment|/* reclaim from free list instead of fsys */
end_comment

begin_define
define|#
directive|define
name|TR_WAITMEM
value|26
end_define

begin_comment
comment|/* wait for memory in pagein */
end_comment

begin_define
define|#
directive|define
name|TR_EWAITMEM
value|27
end_define

begin_comment
comment|/* end memory wait in pagein */
end_comment

begin_define
define|#
directive|define
name|TR_ZFOD
value|28
end_define

begin_comment
comment|/* zfod page fault */
end_comment

begin_define
define|#
directive|define
name|TR_EXFOD
value|29
end_define

begin_comment
comment|/* exec fod page fault */
end_comment

begin_define
define|#
directive|define
name|TR_VRFOD
value|30
end_define

begin_comment
comment|/* vread fod page fault */
end_comment

begin_define
define|#
directive|define
name|TR_CACHEFOD
value|31
end_define

begin_comment
comment|/* fod in file system cache */
end_comment

begin_define
define|#
directive|define
name|TR_SWAPIN
value|32
end_define

begin_comment
comment|/* drum page fault */
end_comment

begin_define
define|#
directive|define
name|TR_PGINDONE
value|33
end_define

begin_comment
comment|/* page in done */
end_comment

begin_comment
comment|/*  * System call trace points.  */
end_comment

begin_define
define|#
directive|define
name|TR_VADVISE
value|40
end_define

begin_comment
comment|/* vadvise occurred with<arg, pid> */
end_comment

begin_comment
comment|/*  * This defines the size of the trace flags array.  */
end_comment

begin_define
define|#
directive|define
name|TR_NFLAGS
value|100
end_define

begin_comment
comment|/* generous */
end_comment

begin_define
define|#
directive|define
name|TRCSIZ
value|4096
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_decl_stmt
name|char
name|traceflags
index|[
name|TR_NFLAGS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|traceproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tracebuf
index|[
name|TRCSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|tracex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tracewhich
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|trace
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|if (traceflags[a]) trace1(a,b,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

