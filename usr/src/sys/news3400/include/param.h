begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: machparam.h 1.11 89/08/14$  *  *	@(#)param.h	8.3 (Berkeley) 5/14/95  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for DEC Station 3100.  */
end_comment

begin_define
define|#
directive|define
name|MACHINE
value|"news3400"
end_define

begin_define
define|#
directive|define
name|NCPUS
value|1
end_define

begin_define
define|#
directive|define
name|COFF
end_define

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value for all  * data types (int, long, ...).   The result is u_int and must be cast to  * any desired pointer type.  */
end_comment

begin_define
define|#
directive|define
name|ALIGNBYTES
value|7
end_define

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((u_int)(p) + ALIGNBYTES)&~ ALIGNBYTES)
end_define

begin_define
define|#
directive|define
name|NBPG
value|4096
end_define

begin_comment
comment|/* bytes/page */
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
name|PGSHIFT
value|12
end_define

begin_comment
comment|/* LOG2(NBPG) */
end_comment

begin_define
define|#
directive|define
name|NPTEPG
value|(NBPG/4)
end_define

begin_define
define|#
directive|define
name|NBSEG
value|0x400000
end_define

begin_comment
comment|/* bytes/segment */
end_comment

begin_define
define|#
directive|define
name|SEGOFSET
value|(NBSEG-1)
end_define

begin_comment
comment|/* byte offset into segment */
end_comment

begin_define
define|#
directive|define
name|SEGSHIFT
value|22
end_define

begin_comment
comment|/* LOG2(NBSEG) */
end_comment

begin_define
define|#
directive|define
name|KERNBASE
value|0x80000000
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
name|DEV_BSIZE
value|512
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
name|BLKDEV_IOSIZE
value|2048
end_define

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
name|CLSIZE
value|1
end_define

begin_define
define|#
directive|define
name|CLSIZELOG2
value|0
end_define

begin_comment
comment|/* NOTE: SSIZE, SINCR and UPAGES must be multiples of CLSIZE */
end_comment

begin_define
define|#
directive|define
name|SSIZE
value|1
end_define

begin_comment
comment|/* initial stack size/NBPG */
end_comment

begin_define
define|#
directive|define
name|SINCR
value|1
end_define

begin_comment
comment|/* increment of stack/NBPG */
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
name|UADDR
value|0xffffd000
end_define

begin_comment
comment|/* address of u */
end_comment

begin_define
define|#
directive|define
name|UVPN
value|(UADDR>>PGSHIFT)
end_define

begin_comment
comment|/* virtual page number of u */
end_comment

begin_define
define|#
directive|define
name|KERNELSTACK
value|(UADDR+UPAGES*NBPG)
end_define

begin_comment
comment|/* top of kernel stack */
end_comment

begin_comment
comment|/*  * Constants related to network buffer management.  * MCLBYTES must be no larger than CLBYTES (the software page size), and,  * on machines that exchange pages of input or output buffers with mbuf  * clusters (MAPPED_MBUFS), MCLBYTES must also be an integral multiple  * of the hardware page size.  */
end_comment

begin_define
define|#
directive|define
name|MSIZE
value|128
end_define

begin_comment
comment|/* size of an mbuf */
end_comment

begin_define
define|#
directive|define
name|MCLBYTES
value|1024
end_define

begin_define
define|#
directive|define
name|MCLSHIFT
value|10
end_define

begin_define
define|#
directive|define
name|MCLOFSET
value|(MCLBYTES - 1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NMBCLUSTERS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_define
define|#
directive|define
name|NMBCLUSTERS
value|512
end_define

begin_comment
comment|/* map size, max cluster allocation */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NMBCLUSTERS
value|256
end_define

begin_comment
comment|/* map size, max cluster allocation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Size of kernel malloc arena in CLBYTES-sized logical pages  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NKMEMCLUSTERS
end_ifndef

begin_define
define|#
directive|define
name|NKMEMCLUSTERS
value|(2048*1024/CLBYTES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pages ("clicks") (4096 bytes) to disk blocks */
end_comment

begin_define
define|#
directive|define
name|ctod
parameter_list|(
name|x
parameter_list|)
value|((x)<<(PGSHIFT-DEV_BSHIFT))
end_define

begin_define
define|#
directive|define
name|dtoc
parameter_list|(
name|x
parameter_list|)
value|((x)>>(PGSHIFT-DEV_BSHIFT))
end_define

begin_define
define|#
directive|define
name|dtob
parameter_list|(
name|x
parameter_list|)
value|((x)<<DEV_BSHIFT)
end_define

begin_comment
comment|/* pages to bytes */
end_comment

begin_define
define|#
directive|define
name|ctob
parameter_list|(
name|x
parameter_list|)
value|((x)<<PGSHIFT)
end_define

begin_comment
comment|/* bytes to pages */
end_comment

begin_define
define|#
directive|define
name|btoc
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x)+(NBPG-1))>>PGSHIFT)
end_define

begin_define
define|#
directive|define
name|btodb
parameter_list|(
name|bytes
parameter_list|)
comment|/* calculates (bytes / DEV_BSIZE) */
define|\
value|((bytes)>> DEV_BSHIFT)
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
value|((db)<< DEV_BSHIFT)
end_define

begin_comment
comment|/*  * Map a ``block device block'' to a file system block.  * This should be device dependent, and should use the bsize  * field from the disk label.  * For now though just use DEV_BSIZE.  */
end_comment

begin_define
define|#
directive|define
name|bdbtofsb
parameter_list|(
name|bn
parameter_list|)
value|((bn) / (BLKDEV_IOSIZE/DEV_BSIZE))
end_define

begin_comment
comment|/*  * Mach derived conversion macros  */
end_comment

begin_define
define|#
directive|define
name|pmax_round_page
parameter_list|(
name|x
parameter_list|)
value|((((unsigned)(x)) + NBPG - 1)& ~(NBPG-1))
end_define

begin_define
define|#
directive|define
name|pmax_trunc_page
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)& ~(NBPG-1))
end_define

begin_define
define|#
directive|define
name|pmax_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)>> PGSHIFT)
end_define

begin_define
define|#
directive|define
name|pmax_ptob
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)<< PGSHIFT)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|news3400
end_ifdef

begin_define
define|#
directive|define
name|splnet
value|spl2
end_define

begin_define
define|#
directive|define
name|splsoftclock
value|spl2
end_define

begin_define
define|#
directive|define
name|splbio
value|spl3
end_define

begin_define
define|#
directive|define
name|spltty
value|spl4
end_define

begin_define
define|#
directive|define
name|splimp
value|spl4
end_define

begin_define
define|#
directive|define
name|splclock
value|spl5
end_define

begin_define
define|#
directive|define
name|splstatclock
value|spl5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* news3400 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|cpuspeed
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = cpuspeed * (n) / 2; while (--N> 0); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KERNEL */
end_comment

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = (n); while (--N> 0); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|intrcnt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|intrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_define
define|#
directive|define
name|INTR_CLOCK
value|0
end_define

begin_define
define|#
directive|define
name|INTR_SOFTCLK
value|1
end_define

begin_define
define|#
directive|define
name|INTR_SOFTINT
value|2
end_define

begin_define
define|#
directive|define
name|INTR_AST
value|3
end_define

begin_define
define|#
directive|define
name|INTR_SCSI00
value|4
end_define

begin_define
define|#
directive|define
name|INTR_SCSI01
value|5
end_define

begin_define
define|#
directive|define
name|INTR_SCSI02
value|6
end_define

begin_define
define|#
directive|define
name|INTR_SCSI03
value|7
end_define

begin_define
define|#
directive|define
name|INTR_SCSI04
value|8
end_define

begin_define
define|#
directive|define
name|INTR_SCSI05
value|9
end_define

begin_define
define|#
directive|define
name|INTR_SCSI06
value|10
end_define

begin_define
define|#
directive|define
name|INTR_SCSI07
value|11
end_define

begin_define
define|#
directive|define
name|INTR_SCSI10
value|12
end_define

begin_define
define|#
directive|define
name|INTR_SCSI11
value|13
end_define

begin_define
define|#
directive|define
name|INTR_SCSI12
value|14
end_define

begin_define
define|#
directive|define
name|INTR_SCSI13
value|15
end_define

begin_define
define|#
directive|define
name|INTR_SCSI14
value|16
end_define

begin_define
define|#
directive|define
name|INTR_SCSI15
value|17
end_define

begin_define
define|#
directive|define
name|INTR_SCSI16
value|18
end_define

begin_define
define|#
directive|define
name|INTR_SCSI17
value|19
end_define

begin_define
define|#
directive|define
name|INTR_ETHER0
value|20
end_define

begin_define
define|#
directive|define
name|INTR_ETHER1
value|21
end_define

begin_define
define|#
directive|define
name|INTR_ETHER2
value|22
end_define

begin_define
define|#
directive|define
name|INTR_VME2
value|23
end_define

begin_define
define|#
directive|define
name|INTR_VME4
value|24
end_define

begin_define
define|#
directive|define
name|INTR_RS0
value|25
end_define

begin_define
define|#
directive|define
name|INTR_RS1
value|26
end_define

begin_define
define|#
directive|define
name|INTR_RS2
value|27
end_define

begin_define
define|#
directive|define
name|INTR_RS3
value|28
end_define

begin_define
define|#
directive|define
name|INTR_RS4
value|29
end_define

begin_define
define|#
directive|define
name|INTR_RS5
value|30
end_define

begin_define
define|#
directive|define
name|INTR_RS6
value|31
end_define

begin_define
define|#
directive|define
name|INTR_RS7
value|32
end_define

begin_define
define|#
directive|define
name|INTR_RS8
value|33
end_define

begin_define
define|#
directive|define
name|INTR_RS9
value|34
end_define

begin_define
define|#
directive|define
name|INTR_RS10
value|35
end_define

begin_define
define|#
directive|define
name|INTR_RS11
value|36
end_define

begin_define
define|#
directive|define
name|INTR_PRINTER
value|37
end_define

begin_define
define|#
directive|define
name|INTR_FD
value|38
end_define

begin_define
define|#
directive|define
name|INTR_AUDIO
value|39
end_define

begin_define
define|#
directive|define
name|INTR_KEYBOARD
value|40
end_define

begin_define
define|#
directive|define
name|INTR_MOUSE
value|41
end_define

begin_define
define|#
directive|define
name|INTR_BITMAP
value|42
end_define

begin_define
define|#
directive|define
name|INTR_FDDI
value|43
end_define

begin_define
define|#
directive|define
name|INTR_RENDER
value|44
end_define

begin_define
define|#
directive|define
name|NINTRSLOT
value|45
end_define

begin_comment
comment|/* # of intrcnt[] slot */
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

begin_comment
comment|/*  * A simple spin lock.  *  * This structure only sets one bit of data, but is sized based on the  * minimum word size that can be operated on by the hardware test-and-set  * instruction. It is only needed for multiprocessors, as uniprocessors  * will always run to completion or a sleep. It is an error to hold one  * of these locks while a process is sleeping.  */
end_comment

begin_struct
struct|struct
name|simplelock
block|{
name|int
name|lock_data
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|&&
name|NCPUS
operator|>
literal|1
end_if

begin_comment
comment|/*  * The simple-lock routines are the primitives out of which the lock  * package is built. The machine-dependent code must implement an  * atomic test_and_set operation that indivisibly sets the simple lock  * to non-zero and returns its old value. It also assumes that the  * setting of the lock to zero below is indivisible. Simple locks may  * only be used for exclusive locks.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|simple_lock_init
parameter_list|(
name|lkp
parameter_list|)
name|struct
name|simplelock
modifier|*
name|lkp
decl_stmt|;
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
name|lkp
parameter_list|)
name|__volatile
name|struct
name|simplelock
modifier|*
name|lkp
decl_stmt|;
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
name|lkp
parameter_list|)
name|__volatile
name|struct
name|simplelock
modifier|*
name|lkp
decl_stmt|;
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
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|simple_unlock
parameter_list|(
name|lkp
parameter_list|)
name|__volatile
name|struct
name|simplelock
modifier|*
name|lkp
decl_stmt|;
block|{
name|lkp
operator|->
name|lock_data
operator|=
literal|0
expr_stmt|;
block|}
end_function

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
comment|/* !_SIMPLELOCK_H_ */
end_comment

end_unit

