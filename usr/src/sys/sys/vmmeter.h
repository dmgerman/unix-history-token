begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmmeter.h	4.1	%G%	*/
end_comment

begin_comment
comment|/*  * Virtual memory related instrumentation  *  * NB: THE OFFSETS IN THE vmmeter STRUCTURE ARE KNOWN IN vm.m.  */
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
name|v_dfree
decl_stmt|;
comment|/* pages freed by daemon */
define|#
directive|define
name|v_last
value|v_dfree
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

end_unit

