begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 David E. O'Brien  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)param.h	5.8 (Berkeley) 6/28/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for PowerPC (32-bit only currently)  */
end_comment

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value  * for all data types (int, long, ...).   The result is unsigned int  * and must be cast to any desired pointer type.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIGNBYTES
end_ifndef

begin_define
define|#
directive|define
name|_ALIGNBYTES
value|(sizeof(int) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|_ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((unsigned)(p) + _ALIGNBYTES)& ~_ALIGNBYTES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE
end_ifndef

begin_define
define|#
directive|define
name|_MACHIN
value|"powerpc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ARCH
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ARCH
value|"powerpc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_NO_NAMESPACE_POLLUTION
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PARAM_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE
end_ifndef

begin_define
define|#
directive|define
name|MACHINE
value|"powerpc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_ARCH
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"powerpc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MID_MACHINE
value|MID_POWERPC
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * OBJFORMAT_NAMES is a comma-separated list of the object formats  * that are supported on the architecture.  */
end_comment

begin_define
define|#
directive|define
name|OBJFORMAT_NAMES
value|"elf"
end_define

begin_define
define|#
directive|define
name|OBJFORMAT_DEFAULT
value|"elf"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|MAXCPU
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXCPU
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|ALIGNBYTES
value|_ALIGNBYTES
end_define

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|p
parameter_list|)
value|_ALIGN(p)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE
value|(1<< PAGE_SHIFT)
end_define

begin_comment
comment|/* Page size */
end_comment

begin_define
define|#
directive|define
name|PAGE_MASK
value|(PAGE_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|NPTEPG
value|(PAGE_SIZE/(sizeof (pt_entry_t)))
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|0x100000
end_define

begin_comment
comment|/* start of kernel virtual */
end_comment

begin_define
define|#
directive|define
name|BTOPKERNBASE
value|((u_long)KERNBASE>> PGSHIFT)
end_define

begin_define
define|#
directive|define
name|DEV_BSHIFT
value|9
end_define

begin_comment
comment|/* log2(DEV_BSIZE) */
end_comment

begin_define
define|#
directive|define
name|DEV_BSIZE
value|(1<< DEV_BSHIFT)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BLKDEV_IOSIZE
end_ifndef

begin_define
define|#
directive|define
name|BLKDEV_IOSIZE
value|PAGE_SIZE
end_define

begin_comment
comment|/* default block device I/O size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DFLTPHYS
value|(64 * 1024)
end_define

begin_comment
comment|/* default max raw I/O transfer size */
end_comment

begin_define
define|#
directive|define
name|MAXPHYS
value|(128 * 1024)
end_define

begin_comment
comment|/* max raw I/O transfer size */
end_comment

begin_define
define|#
directive|define
name|MAXDUMPPGS
value|(DFLTPHYS/PAGE_SIZE)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KSTACK_UPAGES
end_ifndef

begin_define
define|#
directive|define
name|KSTACK_PAGES
value|2
end_define

begin_comment
comment|/* includes pcb */
end_comment

begin_define
define|#
directive|define
name|KSTACK_GUARD_PAGES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USPACE
value|(KSTACK_PAGES * PAGE_SIZE)
end_define

begin_comment
comment|/* total size of pcb */
end_comment

begin_define
define|#
directive|define
name|UAREA_PAGES
value|1
end_define

begin_comment
comment|/* holds struct user WITHOUT PCB */
end_comment

begin_comment
comment|/*  * Constants related to network buffer management.  * MCLBYTES must be no larger than PAGE_SIZE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSIZE
end_ifndef

begin_define
define|#
directive|define
name|MSIZE
value|256
end_define

begin_comment
comment|/* size of an mbuf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MCLSHIFT
end_ifndef

begin_define
define|#
directive|define
name|MCLSHIFT
value|11
end_define

begin_comment
comment|/* convert bytes to mbuf clusters */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MCLSHIFT */
end_comment

begin_define
define|#
directive|define
name|MCLBYTES
value|(1<< MCLSHIFT)
end_define

begin_comment
comment|/* size of an mbuf cluster */
end_comment

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

begin_comment
comment|/* pages ("clicks") to bytes */
end_comment

begin_define
define|#
directive|define
name|ctob
parameter_list|(
name|x
parameter_list|)
value|((x)<< PAGE_SHIFT)
end_define

begin_comment
comment|/* bytes to clicks */
end_comment

begin_define
define|#
directive|define
name|btoc
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x) + PAGE_MASK)>> PAGE_SHIFT)
end_define

begin_comment
comment|/* pages ("clicks") to disk blocks */
end_comment

begin_define
define|#
directive|define
name|ctod
parameter_list|(
name|x
parameter_list|)
value|((x)<< (PAGE_SHIFT - DEV_BSHIFT))
end_define

begin_define
define|#
directive|define
name|dtoc
parameter_list|(
name|x
parameter_list|)
value|((x)>> (PAGE_SHIFT - DEV_BSHIFT))
end_define

begin_comment
comment|/* bytes to disk blocks */
end_comment

begin_comment
comment|/*  * btodb() is messy and perhaps slow because `bytes' may be an off_t.  We  * want to shift an unsigned type to avoid sign extension and we don't  * want to widen `bytes' unnecessarily.  Assume that the result fits in  * a daddr_t.  */
end_comment

begin_define
define|#
directive|define
name|btodb
parameter_list|(
name|bytes
parameter_list|)
comment|/* calculates (bytes / DEV_BSIZE) */
define|\
value|(sizeof (bytes)> sizeof(long) \ 	 ? (daddr_t)((unsigned long long)(bytes)>> DEV_BSHIFT) \ 	 : (daddr_t)((unsigned long)(bytes)>> DEV_BSHIFT))
end_define

begin_define
define|#
directive|define
name|dbtob
parameter_list|(
name|db
parameter_list|)
comment|/* calculates (db * DEV_BSIZE) */
define|\
value|((off_t)(db)<< DEV_BSHIFT)
end_define

begin_comment
comment|/*  * Mach derived conversion macros  */
end_comment

begin_define
define|#
directive|define
name|trunc_page
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)& ~(PAGE_MASK))
end_define

begin_define
define|#
directive|define
name|round_page
parameter_list|(
name|x
parameter_list|)
value|(((x) + PAGE_MASK)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|trunc_4mpage
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)& ~PDRMASK)
end_define

begin_define
define|#
directive|define
name|round_4mpage
parameter_list|(
name|x
parameter_list|)
value|((((unsigned)(x)) + PDRMASK)& ~PDRMASK)
end_define

begin_define
define|#
directive|define
name|atop
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ptoa
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|powerpc_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|powerpc_ptob
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|pgtok
parameter_list|(
name|x
parameter_list|)
value|((x) * (PAGE_SIZE / 1024))
end_define

begin_comment
comment|/* XXX: NetBSD defines that we're using for the moment */
end_comment

begin_define
define|#
directive|define
name|USER_SR
value|13
end_define

begin_define
define|#
directive|define
name|KERNEL_SR
value|14
end_define

begin_define
define|#
directive|define
name|KERNEL_VSIDBITS
value|0xfffff
end_define

begin_define
define|#
directive|define
name|KERNEL_SEGMENT
value|(0xfffff0 + KERNEL_SR)
end_define

begin_define
define|#
directive|define
name|EMPTY_SEGMENT
value|0xfffff0
end_define

begin_define
define|#
directive|define
name|USER_ADDR
value|((void *)(USER_SR<< ADDR_SR_SHFT))
end_define

begin_define
define|#
directive|define
name|SEGMENT_LENGTH
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SEGMENT_MASK
value|0xf0000000
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NPMAPS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NPMAPS
value|32768
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NPMAPS) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSGBUFSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|MSGBUFSIZE
value|PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(MSGBUFSIZE) */
end_comment

begin_comment
comment|/*  * XXX: Stop NetBSD msgbuf_paddr code from happening.  */
end_comment

begin_define
define|#
directive|define
name|MSGBUFADDR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PARAM_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NO_NAMESPACE_POLLUTION */
end_comment

end_unit

