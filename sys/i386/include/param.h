begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)param.h	5.8 (Berkeley) 6/28/91  *	$Id: param.h,v 1.35 1997/08/21 05:07:56 fsmp Exp $  */
end_comment

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

begin_comment
comment|/*  * Machine dependent constants for Intel 386.  */
end_comment

begin_define
define|#
directive|define
name|MACHINE
value|"i386"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|NCPUS
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCPUS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MID_MACHINE
value|MID_I386
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value  * for all data types (int, long, ...).   The result is unsigned int  * and must be cast to any desired pointer type.  */
end_comment

begin_define
define|#
directive|define
name|ALIGNBYTES
value|(sizeof(int) - 1)
end_define

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((unsigned)(p) + ALIGNBYTES)& ~ALIGNBYTES)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|12
end_define

begin_comment
comment|/* LOG2(PAGE_SIZE) */
end_comment

begin_define
define|#
directive|define
name|PAGE_SIZE
value|(1<<PAGE_SHIFT)
end_define

begin_comment
comment|/* bytes/page */
end_comment

begin_define
define|#
directive|define
name|PAGE_MASK
value|(PAGE_SIZE-1)
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
name|NPDEPG
value|(PAGE_SIZE/(sizeof (pd_entry_t)))
end_define

begin_define
define|#
directive|define
name|PDRSHIFT
value|22
end_define

begin_comment
comment|/* LOG2(NBPDR) */
end_comment

begin_define
define|#
directive|define
name|NBPDR
value|(1<<PDRSHIFT)
end_define

begin_comment
comment|/* bytes/page dir */
end_comment

begin_define
define|#
directive|define
name|PDRMASK
value|(NBPDR-1)
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
value|(1<<DEV_BSHIFT)
end_define

begin_define
define|#
directive|define
name|BLKDEV_IOSIZE
value|2048
end_define

begin_define
define|#
directive|define
name|MAXPHYS
value|(64 * 1024)
end_define

begin_comment
comment|/* max raw I/O transfer size */
end_comment

begin_define
define|#
directive|define
name|IOPAGES
value|2
end_define

begin_comment
comment|/* pages of i/o permission bitmap */
end_comment

begin_define
define|#
directive|define
name|UPAGES
value|2
end_define

begin_comment
comment|/* pages of u-area */
end_comment

begin_define
define|#
directive|define
name|UPAGES_HOLE
value|2
end_define

begin_comment
comment|/* pages of "hole" at top of user space where */
end_comment

begin_comment
comment|/* the upages used to be. DO NOT CHANGE! */
end_comment

begin_comment
comment|/*  * Constants related to network buffer management.  * MCLBYTES must be no larger than CLBYTES (the software page size), and,  * on machines that exchange pages of input or output buffers with mbuf  * clusters (MAPPED_MBUFS), MCLBYTES must also be an integral multiple  * of the hardware page size.  */
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
value|128
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
comment|/* convert bytes to m_buf clusters */
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
comment|/* size of an m_buf cluster */
end_comment

begin_define
define|#
directive|define
name|MCLOFSET
value|(MCLBYTES - 1)
end_define

begin_comment
comment|/* offset within an m_buf cluster */
end_comment

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

begin_comment
comment|/* clicks to bytes */
end_comment

begin_define
define|#
directive|define
name|ctob
parameter_list|(
name|x
parameter_list|)
value|((x)<<PAGE_SHIFT)
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
value|(((unsigned)(x)+PAGE_MASK)>>PAGE_SHIFT)
end_define

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
value|((unsigned)(x)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|round_page
parameter_list|(
name|x
parameter_list|)
value|((((unsigned)(x)) + PAGE_MASK)& ~PAGE_MASK)
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
value|((unsigned)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ptoa
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|i386_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|i386_ptob
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)<< PAGE_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIMPLELOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIMPLELOCK_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|MPLOCKED
value|lock ;
end_define

begin_comment
comment|/*  * Some handy macros to allow logical organization and  * convenient reassignment of various locks.  */
end_comment

begin_define
define|#
directive|define
name|FPU_LOCK
value|call	_get_fpu_lock
end_define

begin_define
define|#
directive|define
name|ALIGN_LOCK
value|call	_get_align_lock
end_define

begin_define
define|#
directive|define
name|SYSCALL_LOCK
value|call	_get_syscall_lock
end_define

begin_define
define|#
directive|define
name|ALTSYSCALL_LOCK
value|call	_get_altsyscall_lock
end_define

begin_comment
comment|/*  * Protects INTR() ISRs.  */
end_comment

begin_define
define|#
directive|define
name|ISR_TRYLOCK
define|\
value|pushl	$_mp_lock ;
comment|/* GIANT_LOCK */
value|\ 	call	_MPtrylock ;
comment|/* try to get lock */
value|\ 	add	$4, %esp
end_define

begin_define
define|#
directive|define
name|ISR_RELLOCK
define|\
value|pushl	$_mp_lock ;
comment|/* GIANT_LOCK */
value|\ 	call	_MPrellock ;						\ 	add	$4, %esp
end_define

begin_comment
comment|/*  * Protects the IO APIC and apic_imen as a critical region.  */
end_comment

begin_define
define|#
directive|define
name|IMASK_LOCK
define|\
value|pushl	$_imen_lock ;
comment|/* address of lock */
value|\ 	call	_s_lock ;
comment|/* MP-safe */
value|\ 	addl	$4, %esp
end_define

begin_define
define|#
directive|define
name|IMASK_UNLOCK
define|\
value|pushl	$_imen_lock ;
comment|/* address of lock */
value|\ 	call	_s_unlock ;
comment|/* MP-safe */
value|\ 	addl	$4, %esp
end_define

begin_comment
comment|/*  * Protects spl updates as a critical region.  * Items within this 'region' include:  *  cpl  *  cil  *  ipending  *  ???  */
end_comment

begin_define
define|#
directive|define
name|CPL_LOCK
define|\
value|pushl	$_cpl_lock ;
comment|/* address of lock */
value|\ 	call	_s_lock ;
comment|/* MP-safe */
value|\ 	addl	$4, %esp
end_define

begin_define
define|#
directive|define
name|CPL_UNLOCK
define|\
value|pushl	$_cpl_lock ;
comment|/* address of lock */
value|\ 	call	_s_unlock ;
comment|/* MP-safe */
value|\ 	addl	$4, %esp
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|MPLOCKED
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|FPU_LOCK
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|ALIGN_LOCK
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|SYSCALL_LOCK
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|ALTSYSCALL_LOCK
end_define

begin_comment
comment|/* NOP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LOCORE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_comment
comment|/*  * Protects com/tty data as a critical region.  */
end_comment

begin_define
define|#
directive|define
name|COM_LOCK
parameter_list|()
value|s_lock(&com_lock)
end_define

begin_define
define|#
directive|define
name|COM_UNLOCK
parameter_list|()
value|s_unlock(&com_lock)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|COM_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|COM_UNLOCK
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_comment
comment|/*  * A simple spin lock.  *  * This structure only sets one bit of data, but is sized based on the  * minimum word size that can be operated on by the hardware test-and-set  * instruction. It is only needed for multiprocessors, as uniprocessors  * will always run to completion or a sleep. It is an error to hold one  * of these locks while a process is sleeping.  */
end_comment

begin_struct
struct|struct
name|simplelock
block|{
specifier|volatile
name|int
name|lock_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* functions in simplelock.s */
end_comment

begin_decl_stmt
name|void
name|s_lock_init
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|s_lock
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s_lock_try
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|s_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global data in mp_machdep.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|imen_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|cpl_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|fast_intr_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|intr_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|com_lock
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIMPLELOCK_DEBUG
argument_list|)
operator|&&
name|NCPUS
operator|>
literal|1
end_if

begin_comment
comment|/*  * The simple-lock routines are the primitives out of which the lock  * package is built. The machine-dependent code must implement an  * atomic test_and_set operation that indivisibly sets the simple lock  * to non-zero and returns its old value. It also assumes that the  * setting of the lock to zero below is indivisible. Simple locks may  * only be used for exclusive locks.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|the_original_code
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|simple_lock_init
parameter_list|(
name|struct
name|simplelock
modifier|*
name|lkp
parameter_list|)
block|{
name|lkp
operator|->
name|lock_data
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|simple_lock
parameter_list|(
name|struct
name|simplelock
modifier|*
name|lkp
parameter_list|)
block|{
while|while
condition|(
name|test_and_set
argument_list|(
operator|&
name|lkp
operator|->
name|lock_data
argument_list|)
condition|)
continue|continue;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|simple_lock_try
parameter_list|(
name|struct
name|simplelock
modifier|*
name|lkp
parameter_list|)
block|{
return|return
operator|(
operator|!
name|test_and_set
argument_list|(
operator|&
name|lkp
operator|->
name|lock_data
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|simple_unlock
parameter_list|(
name|struct
name|simplelock
modifier|*
name|lkp
parameter_list|)
block|{
name|lkp
operator|->
name|lock_data
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* the_original_code */
end_comment

begin_comment
comment|/*  * This set of defines turns on the real functions in i386/isa/apic_ipl.s.  * It has never actually been tested.  */
end_comment

begin_define
define|#
directive|define
name|simple_lock_init
parameter_list|(
name|alp
parameter_list|)
value|s_lock_init(alp)
end_define

begin_define
define|#
directive|define
name|simple_lock
parameter_list|(
name|alp
parameter_list|)
value|s_lock(alp)
end_define

begin_define
define|#
directive|define
name|simple_lock_try
parameter_list|(
name|alp
parameter_list|)
value|s_lock_try(alp)
end_define

begin_define
define|#
directive|define
name|simple_unlock
parameter_list|(
name|alp
parameter_list|)
value|s_unlock(alp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the_original_code */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCPUS> 1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SIMPLELOCK_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PARAM_H_ */
end_comment

end_unit

