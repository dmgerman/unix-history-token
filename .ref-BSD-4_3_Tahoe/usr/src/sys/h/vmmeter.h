begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vmmeter.h	7.2 (Berkeley) 10/13/86  */
end_comment

begin_comment
comment|/*  * Virtual memory related instrumentation  */
end_comment

begin_struct
struct|struct
name|vmmeter
block|{
define|#
directive|define
name|v_first
value|v_swtch
name|unsigned
name|v_swtch
decl_stmt|;
comment|/* context switches */
name|unsigned
name|v_trap
decl_stmt|;
comment|/* calls to trap */
name|unsigned
name|v_syscall
decl_stmt|;
comment|/* calls to syscall() */
name|unsigned
name|v_intr
decl_stmt|;
comment|/* device interrupts */
name|unsigned
name|v_soft
decl_stmt|;
comment|/* software interrupts */
name|unsigned
name|v_pdma
decl_stmt|;
comment|/* pseudo-dma interrupts */
name|unsigned
name|v_pswpin
decl_stmt|;
comment|/* pages swapped in */
name|unsigned
name|v_pswpout
decl_stmt|;
comment|/* pages swapped out */
name|unsigned
name|v_pgin
decl_stmt|;
comment|/* pageins */
name|unsigned
name|v_pgout
decl_stmt|;
comment|/* pageouts */
name|unsigned
name|v_pgpgin
decl_stmt|;
comment|/* pages paged in */
name|unsigned
name|v_pgpgout
decl_stmt|;
comment|/* pages paged out */
name|unsigned
name|v_intrans
decl_stmt|;
comment|/* intransit blocking page faults */
name|unsigned
name|v_pgrec
decl_stmt|;
comment|/* total page reclaims */
name|unsigned
name|v_xsfrec
decl_stmt|;
comment|/* found in free list rather than on swapdev */
name|unsigned
name|v_xifrec
decl_stmt|;
comment|/* found in free list rather than in filsys */
name|unsigned
name|v_exfod
decl_stmt|;
comment|/* pages filled on demand from executables */
name|unsigned
name|v_zfod
decl_stmt|;
comment|/* pages zero filled on demand */
name|unsigned
name|v_vrfod
decl_stmt|;
comment|/* fills of pages mapped by vread() */
name|unsigned
name|v_nexfod
decl_stmt|;
comment|/* number of exfod's created */
name|unsigned
name|v_nzfod
decl_stmt|;
comment|/* number of zfod's created */
name|unsigned
name|v_nvrfod
decl_stmt|;
comment|/* number of vrfod's created */
name|unsigned
name|v_pgfrec
decl_stmt|;
comment|/* page reclaims from free list */
name|unsigned
name|v_faults
decl_stmt|;
comment|/* total faults taken */
name|unsigned
name|v_scan
decl_stmt|;
comment|/* scans in page out daemon */
name|unsigned
name|v_rev
decl_stmt|;
comment|/* revolutions of the hand */
name|unsigned
name|v_seqfree
decl_stmt|;
comment|/* pages taken from sequential programs */
name|unsigned
name|v_dfree
decl_stmt|;
comment|/* pages freed by daemon */
name|unsigned
name|v_fastpgrec
decl_stmt|;
comment|/* fast reclaims in locore */
ifdef|#
directive|ifdef
name|tahoe
name|unsigned
name|v_fpe
decl_stmt|;
comment|/* floating point emulation traps */
name|unsigned
name|v_align
decl_stmt|;
comment|/* alignment emulation traps */
endif|#
directive|endif
define|#
directive|define
name|v_last
value|v_fastpgrec
name|unsigned
name|v_swpin
decl_stmt|;
comment|/* swapins */
name|unsigned
name|v_swpout
decl_stmt|;
comment|/* swapouts */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|vmmeter
name|cnt
decl_stmt|,
name|rate
decl_stmt|,
name|sum
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* systemwide totals computed every five seconds */
end_comment

begin_struct
struct|struct
name|vmtotal
block|{
name|short
name|t_rq
decl_stmt|;
comment|/* length of the run queue */
name|short
name|t_dw
decl_stmt|;
comment|/* jobs in ``disk wait'' (neg priority) */
name|short
name|t_pw
decl_stmt|;
comment|/* jobs in page wait */
name|short
name|t_sl
decl_stmt|;
comment|/* jobs sleeping in core */
name|short
name|t_sw
decl_stmt|;
comment|/* swapped out runnable/short block jobs */
name|long
name|t_vm
decl_stmt|;
comment|/* total virtual memory */
name|long
name|t_avm
decl_stmt|;
comment|/* active virtual memory */
name|long
name|t_rm
decl_stmt|;
comment|/* total real memory in use */
name|long
name|t_arm
decl_stmt|;
comment|/* active real memory */
name|long
name|t_vmtxt
decl_stmt|;
comment|/* virtual memory used by text */
name|long
name|t_avmtxt
decl_stmt|;
comment|/* active virtual memory used by text */
name|long
name|t_rmtxt
decl_stmt|;
comment|/* real memory used by text */
name|long
name|t_armtxt
decl_stmt|;
comment|/* active real memory used by text */
name|long
name|t_free
decl_stmt|;
comment|/* free memory pages */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|vmtotal
name|total
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Optional instrumentation.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PGINPROF
end_ifdef

begin_define
define|#
directive|define
name|NDMON
value|128
end_define

begin_define
define|#
directive|define
name|NSMON
value|128
end_define

begin_define
define|#
directive|define
name|DRES
value|20
end_define

begin_define
define|#
directive|define
name|SRES
value|5
end_define

begin_define
define|#
directive|define
name|PMONMIN
value|20
end_define

begin_define
define|#
directive|define
name|PRES
value|50
end_define

begin_define
define|#
directive|define
name|NPMON
value|64
end_define

begin_define
define|#
directive|define
name|RMONMIN
value|130
end_define

begin_define
define|#
directive|define
name|RRES
value|5
end_define

begin_define
define|#
directive|define
name|NRMON
value|64
end_define

begin_comment
comment|/* data and stack size distribution counters */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|dmon
index|[
name|NDMON
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|smon
index|[
name|NSMON
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page in time distribution counters */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|pmon
index|[
name|NPMON
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reclaim time distribution counters */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|rmon
index|[
name|NRMON
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pmonmin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pres
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rmonmin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rres
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|rectime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accumulator for reclaim times */
end_comment

begin_decl_stmt
name|unsigned
name|pgintime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accumulator for page in times */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

