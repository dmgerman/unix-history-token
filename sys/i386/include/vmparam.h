begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vmparam.h	5.9 (Berkeley) 5/12/91  *	$Id: vmparam.h,v 1.9 1993/12/19 00:50:19 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_VMPARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_VMPARAM_H_
value|1
end_define

begin_comment
comment|/*  * Machine dependent constants for 386.  */
end_comment

begin_comment
comment|/*  * Virtual address space arrangement. On 386, both user and kernel  * share the address space, not unlike the vax.  * USRTEXT is the start of the user text/data space, while USRSTACK  * is the top (end) of the user stack. Immediately above the user stack  * resides the user structure, which is UPAGES long and contains the  * kernel stack.  *  * Immediately after the user structure is the page table map, and then  * kernal address space.  */
end_comment

begin_define
define|#
directive|define
name|USRTEXT
value|0UL
end_define

begin_define
define|#
directive|define
name|USRSTACK
value|0xFDBFE000UL
end_define

begin_define
define|#
directive|define
name|BTOPUSRSTACK
value|(0xFDC00-(UPAGES))
end_define

begin_comment
comment|/* btop(USRSTACK) */
end_comment

begin_define
define|#
directive|define
name|LOWPAGES
value|0UL
end_define

begin_define
define|#
directive|define
name|HIGHPAGES
value|UPAGES
end_define

begin_comment
comment|/*  * Virtual memory related constants, all in bytes  */
end_comment

begin_define
define|#
directive|define
name|MAXTSIZ
value|(16UL*1024*1024)
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
value|(64UL*1024*1024)
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
value|(128UL*1024*1024)
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
value|(512UL*1024)
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
value|(64UL*1024*1024)
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

begin_define
define|#
directive|define
name|SYSPTSIZE
value|(2*NPTEPG)
end_define

begin_define
define|#
directive|define
name|USRPTSIZE
value|(2*NPTEPG)
end_define

begin_comment
comment|/*  * Size of the Shared Memory Pages page table.  */
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
value|512
end_define

begin_comment
comment|/* XXX until we have more kmap space */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Size of User Raw I/O map  */
end_comment

begin_define
define|#
directive|define
name|USRIOSIZE
value|300
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
comment|/*  * A swapped in process is given a small amount of core without being bothered  * by the page replacement algorithm.  Basically this says that if you are  * swapped in you deserve some resources.  We protect the last SAFERSS  * pages against paging and will just swap you out rather than paging you.  * Note that each process has at least UPAGES+CLSIZE pages which are not  * paged anyways (this is currently 8+2=10 pages or 5k bytes), so this  * number just means a swapped in process is given around 25k bytes.  * Just for fun: current memory prices are 4600$ a megabyte on VAX (4/22/81),  * so we loan each swapped in process memory worth 100$, or just admit  * that we don't consider it worthwhile and swap it out to disk which costs  * $30/mb or about $0.75.  * { wfj 6/16/89: Retail AT memory expansion $800/megabyte, loan of $17  *   on disk costing $7/mb or $0.18 (in memory still 100:1 in cost!) }  */
end_comment

begin_define
define|#
directive|define
name|SAFERSS
value|8
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
name|prot
parameter_list|)
define|\
value|{(*(int *)(pte) = ((pfnum)<<PGSHIFT) | (prot)) ; }
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
value|((vm_offset_t)0xFDBFE000UL)
end_define

begin_define
define|#
directive|define
name|UPT_MIN_ADDRESS
value|((vm_offset_t)0xFDC00000UL)
end_define

begin_define
define|#
directive|define
name|UPT_MAX_ADDRESS
value|((vm_offset_t)0xFDFF7000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|UPT_MAX_ADDRESS
end_define

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|((vm_offset_t)0xFDFF7000UL)
end_define

begin_define
define|#
directive|define
name|UPDT
value|VM_MIN_KERNEL_ADDRESS
end_define

begin_define
define|#
directive|define
name|KPT_MIN_ADDRESS
value|((vm_offset_t)0xFDFF8000UL)
end_define

begin_define
define|#
directive|define
name|KPT_MAX_ADDRESS
value|((vm_offset_t)0xFDFFF000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|((vm_offset_t)0xFF7FF000UL)
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
value|(16 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|VM_PHYS_SIZE
value|(USRIOSIZE*CLBYTES)
end_define

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

begin_comment
comment|/*  * Flush MMU TLB  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I386_CR3PAT
end_ifndef

begin_define
define|#
directive|define
name|I386_CR3PAT
value|0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|_cr3
parameter_list|()
value|({u_long rtn; \ 	asm (" movl %%cr3,%%eax; movl %%eax,%0 " \ 		: "=g" (rtn) \ 		: \ 		: "ax"); \ 	rtn; \ })
end_define

begin_define
define|#
directive|define
name|load_cr3
parameter_list|(
name|s
parameter_list|)
value|({ u_long val; \ 	val = (s) | I386_CR3PAT; \ 	asm ("movl %0,%%eax; movl %%eax,%%cr3" \ 		:  \ 		: "g" (val) \ 		: "ax"); \ })
end_define

begin_define
define|#
directive|define
name|tlbflush
parameter_list|()
value|({ u_long val; \ 	val = u.u_pcb.pcb_ptd | I386_CR3PAT; \ 	asm ("movl %0,%%eax; movl %%eax,%%cr3" \ 		:  \ 		: "g" (val) \ 		: "ax"); \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_VMPARAM_H_ */
end_comment

end_unit

