begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmparam.h	1.2	86/01/05	*/
end_comment

begin_comment
comment|/*  * Machine dependent constants for TAHOE  */
end_comment

begin_comment
comment|/*  * USRTEXT is the start of the user text/data space, while USRSTACK  * is the top (end) of the user stack.  LOWPAGES and HIGHPAGES are  * the number of pages from the beginning of the P0 region to the  * beginning of the text and from the beginning of the P2 region to the  * beginning of the stack respectively.  */
end_comment

begin_define
define|#
directive|define
name|USRTEXT
value|0
end_define

begin_define
define|#
directive|define
name|USRSTACK
value|(0xc0000000-UPAGES*NBPG)
end_define

begin_comment
comment|/* Start of user stack */
end_comment

begin_define
define|#
directive|define
name|BTOPUSRSTACK
value|(0x300000 - UPAGES)
end_define

begin_comment
comment|/* btop(USRSTACK) */
end_comment

begin_define
define|#
directive|define
name|P2PAGES
value|0x100000
end_define

begin_comment
comment|/* number of pages in P2 region */
end_comment

begin_define
define|#
directive|define
name|LOWPAGES
value|0
end_define

begin_define
define|#
directive|define
name|HIGHPAGES
value|UPAGES
end_define

begin_comment
comment|/*  * Virtual memory related constants, all in clicks  */
end_comment

begin_define
define|#
directive|define
name|MAXTSIZ
value|(6*CLSIZE*1024)
end_define

begin_comment
comment|/* max text size */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DFLDSIZ
end_ifndef

begin_define
define|#
directive|define
name|DFLDSIZ
value|(6*1024*1024/NBPG)
end_define

begin_comment
comment|/* initial data size limit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXDSIZ
end_ifndef

begin_define
define|#
directive|define
name|MAXDSIZ
value|(19*1024*1024/NBPG)
end_define

begin_comment
comment|/* max data size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DFLSSIZ
end_ifndef

begin_define
define|#
directive|define
name|DFLSSIZ
value|(512*1024/NBPG)
end_define

begin_comment
comment|/* initial stack size limit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXSSIZ
end_ifndef

begin_define
define|#
directive|define
name|MAXSSIZ
value|MAXDSIZ
end_define

begin_comment
comment|/* max stack size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Default sizes of swap allocation chunks (see dmap.h).  * The actual values may be changed in vminit() based on MAXDSIZ.  * With MAXDSIZ of 16Mb and NDMAP of 38, dmmax will be 1024.  */
end_comment

begin_define
define|#
directive|define
name|DMMIN
value|32
end_define

begin_comment
comment|/* smallest swap allocation */
end_comment

begin_define
define|#
directive|define
name|DMMAX
value|4096
end_define

begin_comment
comment|/* largest potential swap allocation */
end_comment

begin_define
define|#
directive|define
name|DMTEXT
value|1024
end_define

begin_comment
comment|/* swap allocation for text */
end_comment

begin_comment
comment|/*  * Sizes of the system and user portions of the system page table.  */
end_comment

begin_comment
comment|/* SYSPTSIZE IS SILLY; IT SHOULD BE COMPUTED AT BOOT TIME */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|SYSPTSIZE
value|((20+MAXUSERS)*NPTEPG)
end_define

begin_define
define|#
directive|define
name|USRPTSIZE
value|(32*NPTEPG)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSPTSIZE
value|((128*NPTEPG/2)+(MAXUSERS*NPTEPG/16))
end_define

begin_define
define|#
directive|define
name|USRPTSIZE
value|(4*NPTEPG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The size of the clock loop.  */
end_comment

begin_define
define|#
directive|define
name|LOOPPAGES
value|(maxfree - firstfree)
end_define

begin_comment
comment|/*  * The time for a process to be blocked before being very swappable.  * This is a number of seconds which the system takes as being a non-trivial  * amount of real time.  You probably shouldn't change this;  * it is used in subtle ways (fractions and multiples of it are, that is, like  * half of a ``long time'', almost a long time, etc.)  * It is related to human patience and other factors which don't really  * change over time.  */
end_comment

begin_define
define|#
directive|define
name|MAXSLP
value|20
end_define

begin_comment
comment|/*  * A swapped in process is given a small amount of core without being bothered  * by the page replacement algorithm.  Basically this says that if you are  * swapped in you deserve some resources.  We protect the last SAFERSS  * pages against paging and will just swap you out rather than paging you.  * Note that each process has at least UPAGES+CLSIZE pages which are not  * paged anyways (this is currently 8+2=10 pages or 5k bytes), so this  * number just means a swapped in process is given around 25k bytes.  * Just for fun: current memory prices are 4600$ a megabyte on VAX (4/22/81),  * so we loan each swapped in process memory worth 100$, or just admit  * that we don't consider it worthwhile and swap it out to disk which costs  * $30/mb or about $0.75.  */
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

begin_comment
comment|/*  * DISKRPM is used to estimate the number of paging i/o operations  * which one can expect from a single disk controller.  */
end_comment

begin_define
define|#
directive|define
name|DISKRPM
value|60
end_define

begin_comment
comment|/*  * Klustering constants.  Klustering is the gathering  * of pages together for pagein/pageout, while clustering  * is the treatment of hardware page size as though it were  * larger than it really is.  *  * KLMAX gives maximum cluster size in CLSIZE page (cluster-page)  * units.  Note that KLMAX*CLSIZE must be<= DMMIN in dmap.h.  */
end_comment

begin_define
define|#
directive|define
name|KLMAX
value|(32/CLSIZE)
end_define

begin_define
define|#
directive|define
name|KLSEQL
value|(16/CLSIZE)
end_define

begin_comment
comment|/* in klust if vadvise(VA_SEQL) */
end_comment

begin_define
define|#
directive|define
name|KLIN
value|(8/CLSIZE)
end_define

begin_comment
comment|/* default data/stack in klust */
end_comment

begin_define
define|#
directive|define
name|KLTXT
value|(4/CLSIZE)
end_define

begin_comment
comment|/* default text in klust */
end_comment

begin_define
define|#
directive|define
name|KLOUT
value|(32/CLSIZE)
end_define

begin_comment
comment|/*  * KLSDIST is the advance or retard of the fifo reclaim for sequential  * processes data space.  */
end_comment

begin_define
define|#
directive|define
name|KLSDIST
value|3
end_define

begin_comment
comment|/* klusters advance/retard for seq. fifo */
end_comment

begin_comment
comment|/*  * Paging thresholds (see vm_sched.c).  * Strategy of 1/19/85:  *	lotsfree is 512k bytes, but at most 1/4 of memory  *	desfree is 200k bytes, but at most 1/8 of memory  *	minfree is 64k bytes, but at most 1/2 of desfree  */
end_comment

begin_define
define|#
directive|define
name|LOTSFREE
value|(512 * 1024)
end_define

begin_define
define|#
directive|define
name|LOTSFREEFRACT
value|4
end_define

begin_define
define|#
directive|define
name|DESFREE
value|(200 * 1024)
end_define

begin_define
define|#
directive|define
name|DESFREEFRACT
value|8
end_define

begin_define
define|#
directive|define
name|MINFREE
value|(64 * 1024)
end_define

begin_define
define|#
directive|define
name|MINFREEFRACT
value|2
end_define

begin_comment
comment|/*  * There are two clock hands, initially separated by HANDSPREAD bytes  * (but at most all of user memory).  The amount of time to reclaim  * a page once the pageout process examines it increases with this  * distance and decreases as the scan rate rises.  */
end_comment

begin_define
define|#
directive|define
name|HANDSPREAD
value|(2 * 1024 * 1024)
end_define

begin_comment
comment|/*  * The number of times per second to recompute the desired paging rate  * and poke the pagedaemon.  */
end_comment

begin_define
define|#
directive|define
name|RATETOSCHEDPAGING
value|4
end_define

begin_comment
comment|/*  * Believed threshold (in megabytes) for which interleaved  * swapping area is desirable.  */
end_comment

begin_define
define|#
directive|define
name|LOTSOFMEM
value|2
end_define

begin_comment
comment|/*  * BEWARE THIS DEFINITION WORKS ONLY WITH COUNT OF 1  */
end_comment

begin_define
define|#
directive|define
name|mapin
parameter_list|(
name|pte
parameter_list|,
name|v
parameter_list|,
name|pfnum
parameter_list|,
name|count
parameter_list|,
name|prot
parameter_list|)
define|\
value|(*(int *)(pte) = (pfnum) | (prot), mtpr(TBIS, ptob(v)))
end_define

begin_comment
comment|/*  * Invalidate a cluster (optimized here for standard CLSIZE).  */
end_comment

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
name|tbiscl
parameter_list|(
name|v
parameter_list|)
value|mtpr(TBIS, ptob(v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * The following constant is used to initialize the map of the  * system page table i/o entries.  * It's value should be the highest i/o address used by all the   * controllers handled in the system as specified in ubminit   * structure in ioconf.c.  */
end_comment

begin_define
define|#
directive|define
name|MAXIOADDR
value|0xffffee45
end_define

begin_comment
comment|/* number of entries in the system page pable for i/o space */
end_comment

begin_define
define|#
directive|define
name|IOSIZE
value|(((MAXIOADDR - (int)IOBASE+ NBPG-1)>> PGSHIFT)+1)
end_define

begin_define
define|#
directive|define
name|TBUFSIZ
value|32
end_define

begin_comment
comment|/* maximum tape buffer size */
end_comment

begin_define
define|#
directive|define
name|ACEBPTE
value|32
end_define

begin_comment
comment|/* ACC Ethernet (ACE) I/O window */
end_comment

end_unit

