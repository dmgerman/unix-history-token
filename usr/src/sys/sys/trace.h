begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)trace.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * File system buffer tracing points; all trace<pack(dev, size), bn>  */
end_comment

begin_define
define|#
directive|define
name|TR_BREADHIT
value|0
end_define

begin_comment
comment|/* buffer read found in cache */
end_comment

begin_define
define|#
directive|define
name|TR_BREADMISS
value|1
end_define

begin_comment
comment|/* buffer read not in cache */
end_comment

begin_define
define|#
directive|define
name|TR_BWRITE
value|2
end_define

begin_comment
comment|/* buffer written */
end_comment

begin_define
define|#
directive|define
name|TR_BREADHITRA
value|3
end_define

begin_comment
comment|/* buffer read-ahead found in cache */
end_comment

begin_define
define|#
directive|define
name|TR_BREADMISSRA
value|4
end_define

begin_comment
comment|/* buffer read-ahead not in cache */
end_comment

begin_define
define|#
directive|define
name|TR_XFODMISS
value|5
end_define

begin_comment
comment|/* exe fod read */
end_comment

begin_define
define|#
directive|define
name|TR_XFODHIT
value|6
end_define

begin_comment
comment|/* exe fod read */
end_comment

begin_define
define|#
directive|define
name|TR_BRELSE
value|7
end_define

begin_comment
comment|/* brelse */
end_comment

begin_define
define|#
directive|define
name|TR_BREALLOC
value|8
end_define

begin_comment
comment|/* expand/contract a buffer */
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

begin_define
define|#
directive|define
name|TR_SWAPIO
value|34
end_define

begin_comment
comment|/* swap i/o request arrives */
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
comment|/*  * Miscellaneous  */
end_comment

begin_define
define|#
directive|define
name|TR_STAMP
value|45
end_define

begin_comment
comment|/* user said vtrace(VTR_STAMP, value); */
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

begin_comment
comment|/*  * Specifications of the vtrace() system call, which takes one argument.  */
end_comment

begin_define
define|#
directive|define
name|VTRACE
value|64+51
end_define

begin_define
define|#
directive|define
name|VTR_DISABLE
value|0
end_define

begin_comment
comment|/* set a trace flag to 0 */
end_comment

begin_define
define|#
directive|define
name|VTR_ENABLE
value|1
end_define

begin_comment
comment|/* set a trace flag to 1 */
end_comment

begin_define
define|#
directive|define
name|VTR_VALUE
value|2
end_define

begin_comment
comment|/* return value of a trace flag */
end_comment

begin_define
define|#
directive|define
name|VTR_UALARM
value|3
end_define

begin_comment
comment|/* set alarm to go off (sig 16) */
end_comment

begin_comment
comment|/* in specified number of hz */
end_comment

begin_define
define|#
directive|define
name|VTR_STAMP
value|4
end_define

begin_comment
comment|/* user specified stamp */
end_comment

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
name|pack
parameter_list|(
name|v
parameter_list|,
name|b
parameter_list|)
value|(((v)->v_mount->m_stat.f_fsid[0])<<16)|(b)
end_define

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|trace
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|b
parameter_list|)
value|;
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

