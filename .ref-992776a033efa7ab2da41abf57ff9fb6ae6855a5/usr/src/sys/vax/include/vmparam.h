begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmparam.h	4.3	83/02/21	*/
end_comment

begin_comment
comment|/*  * Machine dependent constants for VAX  */
end_comment

begin_comment
comment|/*  * USRTEXT is the start of the user text/data space, while USRSTACK  * is the top (end) of the user stack.  LOWPAGES and HIGHPAGES are  * the number of pages from the beginning of the P0 region to the  * beginning of the text and from the beginning of the P1 region to the  * beginning of the stack respectively.  */
end_comment

begin_comment
comment|/* number of ptes per page */
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
value|(0x80000000-UPAGES*NBPG)
end_define

begin_comment
comment|/* Start of user stack */
end_comment

begin_define
define|#
directive|define
name|P1PAGES
value|0x200000
end_define

begin_comment
comment|/* number of pages in P1 region */
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
comment|/*  * Virtual memory related constants  */
end_comment

begin_define
define|#
directive|define
name|SLOP
value|32
end_define

begin_define
define|#
directive|define
name|MAXTSIZ
value|(6*2048-SLOP)
end_define

begin_comment
comment|/* max text size (clicks) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXDSIZ
end_ifndef

begin_define
define|#
directive|define
name|MAXDSIZ
value|(12*1024-32-SLOP)
end_define

begin_comment
comment|/* max data size (clicks) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXSSIZ
value|(12*1024-32-SLOP)
end_define

begin_comment
comment|/* max stack size (clicks) */
end_comment

begin_comment
comment|/*  * Sizes of the system and user portions of the system page table.  */
end_comment

begin_comment
comment|/* SYSPTSIZE IS SILLY; IT SHOULD BE COMPUTED AT BOOT TIME */
end_comment

begin_define
define|#
directive|define
name|SYSPTSIZE
value|(35*NPTEPG)
end_define

begin_define
define|#
directive|define
name|USRPTSIZE
value|(8*NPTEPG)
end_define

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

end_unit

