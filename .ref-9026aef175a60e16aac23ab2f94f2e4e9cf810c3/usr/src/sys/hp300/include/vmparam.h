begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: vmparam.h 1.16 91/01/18$  *  *	@(#)vmparam.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for HP300  */
end_comment

begin_comment
comment|/*  * USRTEXT is the start of the user text/data space, while USRSTACK  * is the top (end) of the user stack.  LOWPAGES and HIGHPAGES are  * the number of pages from the beginning of the P0 region to the  * beginning of the text and from the beginning of the P1 region to the  * beginning of the stack respectively.  *  * NOTE: the ONLY reason that HIGHPAGES is 0x100 instead of UPAGES (3)  * is for HPUX compatibility.  Why??  Because HPUX's debuggers  * have the user's stack hard-wired at FFF00000 for post-mortems,  * and we must be compatible...  */
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
value|(-HIGHPAGES*NBPG)
end_define

begin_comment
comment|/* Start of user stack */
end_comment

begin_define
define|#
directive|define
name|BTOPUSRSTACK
value|(0x100000-HIGHPAGES)
end_define

begin_comment
comment|/* btop(USRSTACK) */
end_comment

begin_define
define|#
directive|define
name|P1PAGES
value|0x100000
end_define

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
value|(0x100000/NBPG)
end_define

begin_comment
comment|/*  * Virtual memory related constants, all in bytes  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXTSIZ
end_ifndef

begin_define
define|#
directive|define
name|MAXTSIZ
value|(8*1024*1024)
end_define

begin_comment
comment|/* max text size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DFLDSIZ
end_ifndef

begin_define
define|#
directive|define
name|DFLDSIZ
value|(16*1024*1024)
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
value|(64*1024*1024)
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
value|(512*1024)
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
comment|/*  * Default sizes of swap allocation chunks (see dmap.h).  * The actual values may be changed in vminit() based on MAXDSIZ.  * With MAXDSIZ of 16Mb and NDMAP of 38, dmmax will be 1024.  * DMMIN should be at least ctod(1) so that vtod() works.  * vminit() insures this.  */
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
value|(2 * NPTEPG)
end_define

begin_comment
comment|/* 8mb */
end_comment

begin_define
define|#
directive|define
name|USRPTSIZE
value|(1 * NPTEPG)
end_define

begin_comment
comment|/* 4mb */
end_comment

begin_comment
comment|/*  * PTEs for mapping user space into the kernel for phyio operations.  * One page is enough to handle 4Mb of simultaneous raw IO operations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USRIOSIZE
end_ifndef

begin_define
define|#
directive|define
name|USRIOSIZE
value|(1 * NPTEPG)
end_define

begin_comment
comment|/* 4mb */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PTEs for system V style shared memory.  * This is basically slop for kmempt which we actually allocate (malloc) from.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHMMAXPGS
end_ifndef

begin_define
define|#
directive|define
name|SHMMAXPGS
value|1024
end_define

begin_comment
comment|/* 4mb */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * External IO space map size.  * By default we make it large enough to map up to 3 DIO-II devices and  * the complete DIO space.  For a 320-only configuration (which has no  * DIO-II) you could define a considerably smaller region.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EIOMAPSIZE
end_ifndef

begin_define
define|#
directive|define
name|EIOMAPSIZE
value|3584
end_define

begin_comment
comment|/* 14mb */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Boundary at which to place first MAPMEM segment if not explicitly  * specified.  Should be a power of two.  This allows some slop for  * the data segment to grow underneath the first mapped segment.  */
end_comment

begin_define
define|#
directive|define
name|MMSEG
value|0x200000
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
value|4
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
comment|/*  * Klustering constants.  Klustering is the gathering  * of pages together for pagein/pageout, while clustering  * is the treatment of hardware page size as though it were  * larger than it really is.  *  * KLMAX gives maximum cluster size in CLSIZE page (cluster-page)  * units.  Note that ctod(KLMAX*CLSIZE) must be<= DMMIN in dmap.h.  * ctob(KLMAX) should also be less than MAXPHYS (in vm_swp.c)  * unless you like "big push" panics.  */
end_comment

begin_define
define|#
directive|define
name|KLMAX
value|(4/CLSIZE)
end_define

begin_define
define|#
directive|define
name|KLSEQL
value|(2/CLSIZE)
end_define

begin_comment
comment|/* in klust if vadvise(VA_SEQL) */
end_comment

begin_define
define|#
directive|define
name|KLIN
value|(4/CLSIZE)
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
value|(4/CLSIZE)
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
comment|/*  * Paging thresholds (see vm_sched.c).  * Strategy of 1/19/85:  *	lotsfree is 512k bytes, but at most 1/4 of memory  *	desfree is 200k bytes, but at most 1/8 of memory  */
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
comment|/*  * Mach derived constants  */
end_comment

begin_comment
comment|/* user/kernel map constants */
end_comment

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|((vm_offset_t)0)
end_define

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|((vm_offset_t)0xFFF00000)
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|((vm_offset_t)0xFFF00000)
end_define

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|((vm_offset_t)0)
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|((vm_offset_t)0xFFFFF000)
end_define

begin_comment
comment|/* virtual sizes (bytes) for various kernel submaps */
end_comment

begin_define
define|#
directive|define
name|VM_MBUF_SIZE
value|(NMBCLUSTERS*MCLBYTES)
end_define

begin_define
define|#
directive|define
name|VM_KMEM_SIZE
value|(NKMEMCLUSTERS*CLBYTES)
end_define

begin_define
define|#
directive|define
name|VM_PHYS_SIZE
value|(USRIOSIZE*CLBYTES)
end_define

begin_comment
comment|/* # of kernel PT pages (initial only, can grow dynamically) */
end_comment

begin_define
define|#
directive|define
name|VM_KERNEL_PT_PAGES
value|((vm_size_t)2)
end_define

begin_comment
comment|/* XXX: SYSPTSIZE */
end_comment

begin_comment
comment|/* pcb base */
end_comment

begin_define
define|#
directive|define
name|pcbb
parameter_list|(
name|p
parameter_list|)
value|((u_int)(p)->p_addr)
end_define

end_unit

