begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vm.h	2.1	1/5/80	*/
end_comment

begin_comment
comment|/*  * Machine dependent constants  */
end_comment

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
end_comment

begin_define
define|#
directive|define
name|NBPG
value|512
end_define

begin_comment
comment|/* number of bytes per page */
end_comment

begin_define
define|#
directive|define
name|PGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NBPG) */
end_comment

begin_define
define|#
directive|define
name|NPTEPG
value|(NBPG/(sizeof (struct pte)))
end_define

begin_comment
comment|/* number of ptes per page */
end_comment

begin_define
define|#
directive|define
name|PGOFSET
value|(NBPG-1)
end_define

begin_comment
comment|/* byte offset into page */
end_comment

begin_define
define|#
directive|define
name|CLOFSET
value|(CLSIZE*NBPG-1)
end_define

begin_comment
comment|/* for clusters, like PGOFSET */
end_comment

begin_define
define|#
directive|define
name|USRSTACK
value|0x80000000
end_define

begin_comment
comment|/* Start of user stack */
end_comment

begin_define
define|#
directive|define
name|P1TOP
value|0x200000
end_define

begin_comment
comment|/* boundary between P0 and P1 regions */
end_comment

begin_define
define|#
directive|define
name|AST
value|0x04000000
end_define

begin_comment
comment|/* ast level */
end_comment

begin_comment
comment|/*  * Virtual memory related constants  *  * note: USRPTSIZE is well known in locore.s  */
end_comment

begin_define
define|#
directive|define
name|MAXTSIZ
value|(4*2048)
end_define

begin_comment
comment|/* max virtual text size in clicks */
end_comment

begin_define
define|#
directive|define
name|MAXDSIZ
value|(4*2048)
end_define

begin_comment
comment|/* max virtual data size in clicks */
end_comment

begin_define
define|#
directive|define
name|MAXSSIZ
value|(1024)
end_define

begin_comment
comment|/* max virtual stack size in clicks */
end_comment

begin_define
define|#
directive|define
name|USRPTSIZE
value|(8*NPTEPG)
end_define

begin_comment
comment|/* max number of pages of page tables 					   for resident processes, this is 					   known in locore.s */
end_comment

begin_comment
comment|/*  * Page clustering macros.  *   * dirtycl(pte)			is the page cluster dirty?  * anycl(pte,fld)		does any pte in the cluster has fld set?  * zapcl(pte,fld) = val		set all fields fld in the cluster to val  * distcl(pte)			distribute high bits to cluster; note that  *				distcl copies everything but pg_pfnum,  *				INCLUDING pg_m!!!  *  * In all cases, pte must be the low pte in the cluster, even if  * the segment grows backwards (e.g. the stack).  */
end_comment

begin_define
define|#
directive|define
name|H
parameter_list|(
name|pte
parameter_list|)
value|((struct hpte *)(pte))
end_define

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|dirtycl
parameter_list|(
name|pte
parameter_list|)
value|dirty(pte)
end_define

begin_define
define|#
directive|define
name|anycl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|((pte)->fld)
end_define

begin_define
define|#
directive|define
name|zapcl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|(pte)->fld
end_define

begin_define
define|#
directive|define
name|distcl
parameter_list|(
name|pte
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|dirtycl
parameter_list|(
name|pte
parameter_list|)
value|(dirty(pte) || dirty((pte)+1))
end_define

begin_define
define|#
directive|define
name|anycl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|((pte)->fld || (((pte)+1)->fld))
end_define

begin_define
define|#
directive|define
name|zapcl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|(pte)[1].fld = (pte)[0].fld
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|dirtycl
parameter_list|(
name|pte
parameter_list|)
define|\
value|(dirty(pte) || dirty((pte)+1) || dirty((pte)+2) || dirty((pte)+3))
end_define

begin_define
define|#
directive|define
name|anycl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
define|\
value|((pte)->fld || (((pte)+1)->fld) || (((pte)+2)->fld) || (((pte)+3)->fld))
end_define

begin_define
define|#
directive|define
name|zapcl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
define|\
value|(pte)[3].fld = (pte)[2].fld = (pte)[1].fld = (pte)[0].fld
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|distcl
end_ifndef

begin_define
define|#
directive|define
name|distcl
parameter_list|(
name|pte
parameter_list|)
value|zapcl(H(pte),pg_high)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Tunable performance parameters  *  * These may vary per-cpu due to configuration as well as the flavor of  * the local job mix.  MAXPGIO in particular is dependent on the number  * of disk drives and controllers available locally.  */
end_comment

begin_define
define|#
directive|define
name|LOOPSIZ
value|((maxfree - firstfree) / CLSIZE)
end_define

begin_comment
comment|/* loop circumference */
end_comment

begin_define
define|#
directive|define
name|LOTSFREE
value|((maxfree - firstfree) / 8)
end_define

begin_comment
comment|/* very high mark to freeze scans */
end_comment

begin_define
define|#
directive|define
name|DESFREE
value|64
end_define

begin_comment
comment|/* minimum desirable free memory */
end_comment

begin_define
define|#
directive|define
name|MINFREE
value|32
end_define

begin_comment
comment|/* water mark to run swap daemon */
end_comment

begin_define
define|#
directive|define
name|MAXSLP
value|20
end_define

begin_comment
comment|/* max blocked time (in seconds) allowed 					   before being very swappable */
end_comment

begin_comment
comment|/* SLOWSCAN AND FASTSCAN SHOULD BE MADE DEPENDENT ON LOOPSIZ */
end_comment

begin_define
define|#
directive|define
name|SLOWSCAN
value|30
end_define

begin_comment
comment|/* seconds per loop when memory easy */
end_comment

begin_define
define|#
directive|define
name|FASTSCAN
value|20
end_define

begin_comment
comment|/* seconds per loop when memory tight */
end_comment

begin_define
define|#
directive|define
name|SAFERSS
value|32
end_define

begin_comment
comment|/* nominal ``small'' resident set size 					   protected against replacement */
end_comment

begin_define
define|#
directive|define
name|MAXPGIO
value|40
end_define

begin_comment
comment|/* max desired paging i/o per second, 					   if exceeded, and freemem< desfree 					   then we try to swap someone out */
end_comment

begin_comment
comment|/*  * Virtual memory related conversion macros  */
end_comment

begin_comment
comment|/* Core clicks to number of pages of page tables needed to map that much */
end_comment

begin_define
define|#
directive|define
name|ctopt
parameter_list|(
name|x
parameter_list|)
value|(((x)+NPTEPG-1)/NPTEPG)
end_define

begin_comment
comment|/* Virtual page numbers to text|data|stack segment page numbers and back */
end_comment

begin_define
define|#
directive|define
name|vtotp
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((int)(v))
end_define

begin_define
define|#
directive|define
name|vtodp
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((int)((v) - (p)->p_tsize))
end_define

begin_define
define|#
directive|define
name|vtosp
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((int)(btop(USRSTACK) - 1 - (v)))
end_define

begin_define
define|#
directive|define
name|tptov
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((unsigned)(i))
end_define

begin_define
define|#
directive|define
name|dptov
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((unsigned)((p)->p_tsize + (i)))
end_define

begin_define
define|#
directive|define
name|sptov
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((unsigned)(btop(USRSTACK) - 1 - (i)))
end_define

begin_comment
comment|/* Tell whether virtual page numbers are in text|data|stack segment */
end_comment

begin_define
define|#
directive|define
name|isassv
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((v)& P1TOP)
end_define

begin_define
define|#
directive|define
name|isatsv
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((v)< (p)->p_tsize)
end_define

begin_define
define|#
directive|define
name|isadsv
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((v)>= (p)->p_tsize&& !isassv(p, v))
end_define

begin_comment
comment|/* Tell whether pte's are text|data|stack */
end_comment

begin_define
define|#
directive|define
name|isaspte
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|((pte)> sptopte(p, (p)->p_ssize))
end_define

begin_define
define|#
directive|define
name|isatpte
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|((pte)< dptopte(p, 0))
end_define

begin_define
define|#
directive|define
name|isadpte
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|(!isaspte(p, pte)&& !isatpte(p, pte))
end_define

begin_comment
comment|/* Text|data|stack pte's to segment page numbers and back */
end_comment

begin_define
define|#
directive|define
name|ptetotp
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|((pte) - (p)->p_p0br)
end_define

begin_define
define|#
directive|define
name|ptetodp
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|((pte) - ((p)->p_p0br + (p)->p_tsize))
end_define

begin_define
define|#
directive|define
name|ptetosp
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|(((p)->p_p0br + (p)->p_szpt*NPTEPG - 1) - (pte))
end_define

begin_define
define|#
directive|define
name|tptopte
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((p)->p_p0br + (i))
end_define

begin_define
define|#
directive|define
name|dptopte
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((p)->p_p0br + (p)->p_tsize + (i))
end_define

begin_define
define|#
directive|define
name|sptopte
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|(((p)->p_p0br + (p)->p_szpt*NPTEPG - 1) - (i))
end_define

begin_comment
comment|/* Bytes to pages without rounding, and back */
end_comment

begin_define
define|#
directive|define
name|btop
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x))>> PGSHIFT)
end_define

begin_define
define|#
directive|define
name|ptob
parameter_list|(
name|x
parameter_list|)
value|((caddr_t)((x)<< PGSHIFT))
end_define

begin_comment
comment|/* Turn virtual addresses into kernel map indices */
end_comment

begin_define
define|#
directive|define
name|kmxtob
parameter_list|(
name|a
parameter_list|)
value|(usrpt + (a) * NPTEPG)
end_define

begin_define
define|#
directive|define
name|btokmx
parameter_list|(
name|b
parameter_list|)
value|(((b) - usrpt) / NPTEPG)
end_define

begin_comment
comment|/* Average new into old with aging factor time */
end_comment

begin_define
define|#
directive|define
name|ave
parameter_list|(
name|smooth
parameter_list|,
name|cnt
parameter_list|,
name|time
parameter_list|)
define|\
value|smooth = ((time - 1) * (smooth) + (cnt)) / (time)
end_define

begin_comment
comment|/*  * Virtual memory related instrumentation  */
end_comment

begin_struct
struct|struct
name|vmmeter
block|{
name|unsigned
name|v_swpin
decl_stmt|;
comment|/* swapins */
name|unsigned
name|v_swpout
decl_stmt|;
comment|/* swapouts */
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
name|unsigned
name|v_swtch
decl_stmt|;
comment|/* context switches */
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
name|short
name|t_vm
decl_stmt|;
comment|/* total virtual memory */
name|short
name|t_avm
decl_stmt|;
comment|/* active virtual memory */
name|short
name|t_rm
decl_stmt|;
comment|/* total real memory in use */
name|short
name|t_arm
decl_stmt|;
comment|/* active real memory */
name|short
name|t_vmtxt
decl_stmt|;
comment|/* virtual memory used by text */
name|short
name|t_avmtxt
decl_stmt|;
comment|/* active virtual memory used by text */
name|short
name|t_rmtxt
decl_stmt|;
comment|/* real memory used by text */
name|short
name|t_armtxt
decl_stmt|;
comment|/* active real memory used by text */
name|short
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

begin_struct
struct|struct
name|forkstat
block|{
name|int
name|cntfork
decl_stmt|;
name|int
name|cntvfork
decl_stmt|;
name|int
name|sizfork
decl_stmt|;
name|int
name|sizvfork
decl_stmt|;
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
name|forkstat
name|forkstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|swptstat
block|{
name|int
name|pteasy
decl_stmt|;
comment|/* easy pt swaps */
name|int
name|ptexpand
decl_stmt|;
comment|/* pt expansion swaps */
name|int
name|ptshrink
decl_stmt|;
comment|/* pt shrinking swaps */
name|int
name|ptpack
decl_stmt|;
comment|/* pt swaps involving spte copying */
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
name|swptstat
name|swptstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|freemem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remaining blocks of free memory */
end_comment

begin_decl_stmt
name|int
name|avefree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* moving average of remaining free blocks */
end_comment

begin_decl_stmt
name|int
name|deficit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* estimate of needs of new swapped in procs */
end_comment

begin_decl_stmt
name|int
name|nscan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of scans in last second */
end_comment

begin_decl_stmt
name|int
name|multprog
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current multiprogramming degree */
end_comment

begin_decl_stmt
name|int
name|desscan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* desired pages scanned per second */
end_comment

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

begin_comment
comment|/* writable copies of tunables */
end_comment

begin_decl_stmt
name|int
name|maxpgio
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max paging i/o per sec before start swaps */
end_comment

begin_decl_stmt
name|int
name|maxslp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max sleep time before very swappable */
end_comment

begin_decl_stmt
name|int
name|lotsfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max free before clock freezes */
end_comment

begin_decl_stmt
name|int
name|minfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum free pages before swapping begins */
end_comment

begin_decl_stmt
name|int
name|desfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no of pages to try to keep free via daemon */
end_comment

begin_decl_stmt
name|int
name|saferss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no pages not to steal; decays with slptime */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

