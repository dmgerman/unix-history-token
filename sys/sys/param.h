begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)param.h	8.3 (Berkeley) 4/4/95  * $Id: param.h,v 1.26 1997/03/03 09:51:10 ache Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PARAM_H_
end_define

begin_define
define|#
directive|define
name|BSD
value|199506
end_define

begin_comment
comment|/* System version (year& month). */
end_comment

begin_define
define|#
directive|define
name|BSD4_3
value|1
end_define

begin_define
define|#
directive|define
name|BSD4_4
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Machine-independent constants (some used in following include files).  * Redefined constants are from POSIX 1003.1 limits file.  *  * MAXCOMLEN should be>= sizeof(ac_comm) (see<acct.h>)  * MAXLOGNAME should be == UT_NAMESIZE+1 (see<utmp.h>)  */
end_comment

begin_include
include|#
directive|include
file|<sys/syslimits.h>
end_include

begin_define
define|#
directive|define
name|MAXCOMLEN
value|16
end_define

begin_comment
comment|/* max command name remembered */
end_comment

begin_define
define|#
directive|define
name|MAXINTERP
value|32
end_define

begin_comment
comment|/* max interpreter file name length */
end_comment

begin_define
define|#
directive|define
name|MAXLOGNAME
value|17
end_define

begin_comment
comment|/* max login name length (incl. NUL) */
end_comment

begin_define
define|#
directive|define
name|MAXUPRC
value|CHILD_MAX
end_define

begin_comment
comment|/* max simultaneous processes */
end_comment

begin_define
define|#
directive|define
name|NCARGS
value|ARG_MAX
end_define

begin_comment
comment|/* max bytes for an exec function */
end_comment

begin_define
define|#
directive|define
name|NGROUPS
value|NGROUPS_MAX
end_define

begin_comment
comment|/* max number groups */
end_comment

begin_define
define|#
directive|define
name|NOFILE
value|OPEN_MAX
end_define

begin_comment
comment|/* max open files per process */
end_comment

begin_define
define|#
directive|define
name|NOGROUP
value|65535
end_define

begin_comment
comment|/* marker for empty group set member */
end_comment

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|256
end_define

begin_comment
comment|/* max hostname size */
end_comment

begin_comment
comment|/* More types and definitions used throughout the kernel. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/rtprio.h>
end_include

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Signals. */
end_comment

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_comment
comment|/* Machine type dependent parameters. */
end_comment

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_comment
comment|/*  * Priorities.  Note that with 32 run queues, differences less than 4 are  * insignificant.  */
end_comment

begin_define
define|#
directive|define
name|PSWP
value|0
end_define

begin_define
define|#
directive|define
name|PVM
value|4
end_define

begin_define
define|#
directive|define
name|PINOD
value|8
end_define

begin_define
define|#
directive|define
name|PRIBIO
value|16
end_define

begin_define
define|#
directive|define
name|PVFS
value|20
end_define

begin_define
define|#
directive|define
name|PZERO
value|22
end_define

begin_comment
comment|/* No longer magic, shouldn't be here.  XXX */
end_comment

begin_define
define|#
directive|define
name|PSOCK
value|24
end_define

begin_define
define|#
directive|define
name|PWAIT
value|32
end_define

begin_define
define|#
directive|define
name|PCONFIG
value|32
end_define

begin_define
define|#
directive|define
name|PLOCK
value|36
end_define

begin_define
define|#
directive|define
name|PPAUSE
value|40
end_define

begin_define
define|#
directive|define
name|PUSER
value|50
end_define

begin_define
define|#
directive|define
name|MAXPRI
value|127
end_define

begin_comment
comment|/* Priorities range from 0 through MAXPRI. */
end_comment

begin_define
define|#
directive|define
name|PRIMASK
value|0x0ff
end_define

begin_define
define|#
directive|define
name|PCATCH
value|0x100
end_define

begin_comment
comment|/* OR'd with pri for tsleep to check signals */
end_comment

begin_define
define|#
directive|define
name|NZERO
value|0
end_define

begin_comment
comment|/* default "nice" */
end_comment

begin_define
define|#
directive|define
name|NBPW
value|sizeof(int)
end_define

begin_comment
comment|/* number of bytes per word (integer) */
end_comment

begin_define
define|#
directive|define
name|CMASK
value|022
end_define

begin_comment
comment|/* default file mask: S_IWGRP|S_IWOTH */
end_comment

begin_define
define|#
directive|define
name|NODEV
value|(dev_t)(-1)
end_define

begin_comment
comment|/* non-existent device */
end_comment

begin_comment
comment|/*  * Clustering of hardware pages on machines with ridiculously small  * page sizes is done here.  The paging subsystem deals with units of  * CLSIZE pte's describing PAGE_SIZE (from machine/machparam.h) pages each.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|CLBYTES
value|(CLSIZE*PAGE_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CBLOCK
value|128
end_define

begin_comment
comment|/* Clist block size, must be a power of 2. */
end_comment

begin_define
define|#
directive|define
name|CBQSIZE
value|(CBLOCK/NBBY)
end_define

begin_comment
comment|/* Quote bytes/cblock - can do better. */
end_comment

begin_comment
comment|/* Data chars/clist. */
end_comment

begin_define
define|#
directive|define
name|CBSIZE
value|(CBLOCK - sizeof(struct cblock *) - CBQSIZE)
end_define

begin_define
define|#
directive|define
name|CROUND
value|(CBLOCK - 1)
end_define

begin_comment
comment|/* Clist rounding. */
end_comment

begin_comment
comment|/*  * File system parameters and macros.  *  * The file system is made out of blocks of at most MAXBSIZE units, with  * smaller units (fragments) only in the last direct block.  MAXBSIZE  * primarily determines the size of buffers in the buffer pool.  It may be  * made larger without any effect on existing file systems; however making  * it smaller make make some file systems unmountable.  Also, MAXBSIZE  * must be less than MAXPHYS!!!  DFLTBSIZE is the average amount of  * memory allocated by vfs_bio per nbuf.  BKVASIZE is the average amount  * of kernel virtual space allocated per nbuf.  BKVASIZE should be>=  * DFLTBSIZE.  If it is significantly bigger than DFLTBSIZE, then  * kva fragmentation causes fewer performance problems.  */
end_comment

begin_define
define|#
directive|define
name|MAXBSIZE
value|65536
end_define

begin_define
define|#
directive|define
name|BKVASIZE
value|8192
end_define

begin_define
define|#
directive|define
name|DFLTBSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|MAXFRAG
value|8
end_define

begin_comment
comment|/*  * MAXPATHLEN defines the longest permissible path length after expanding  * symbolic links. It is used to allocate a temporary buffer from the buffer  * pool in which to do the name expansion, hence should be a power of two,  * and must be less than or equal to MAXBSIZE.  MAXSYMLINKS defines the  * maximum number of symbolic links that may be expanded in a path name.  * It should be set high enough to allow all legitimate uses, but halt  * infinite loops reasonably quickly.  */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_define
define|#
directive|define
name|MAXSYMLINKS
value|32
end_define

begin_comment
comment|/* Bit map related macros. */
end_comment

begin_define
define|#
directive|define
name|setbit
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|((a)[(i)/NBBY] |= 1<<((i)%NBBY))
end_define

begin_define
define|#
directive|define
name|clrbit
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|((a)[(i)/NBBY]&= ~(1<<((i)%NBBY)))
end_define

begin_define
define|#
directive|define
name|isset
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|((a)[(i)/NBBY]& (1<<((i)%NBBY)))
end_define

begin_define
define|#
directive|define
name|isclr
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|(((a)[(i)/NBBY]& (1<<((i)%NBBY))) == 0)
end_define

begin_comment
comment|/* Macros for counting and rounding. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|howmany
end_ifndef

begin_define
define|#
directive|define
name|howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))/(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|rounddown
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)/(y))*(y))
end_define

begin_define
define|#
directive|define
name|roundup
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x)+((y)-1))/(y))*(y))
end_define

begin_comment
comment|/* to any y */
end_comment

begin_define
define|#
directive|define
name|roundup2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))&(~((y)-1)))
end_define

begin_comment
comment|/* if y is powers of two */
end_comment

begin_define
define|#
directive|define
name|powerof2
parameter_list|(
name|x
parameter_list|)
value|((((x)-1)&(x))==0)
end_define

begin_comment
comment|/* Macros for min/max. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Constants for setting the parameters of the kernel memory allocator.  *  * 2 ** MINBUCKET is the smallest unit of memory that will be  * allocated. It must be at least large enough to hold a pointer.  *  * Units of memory less or equal to MAXALLOCSAVE will permanently  * allocate physical memory; requests for these size pieces of  * memory are quite fast. Allocations greater than MAXALLOCSAVE must  * always allocate and free physical memory; requests for these  * size allocations should be done infrequently as they will be slow.  *  * Constraints: PAGE_SIZE<= MAXALLOCSAVE<= 2 ** (MINBUCKET + 14), and  * MAXALLOCSIZE must be a power of two.  */
end_comment

begin_define
define|#
directive|define
name|MINBUCKET
value|4
end_define

begin_comment
comment|/* 4 => min allocation of 16 bytes */
end_comment

begin_define
define|#
directive|define
name|MAXALLOCSAVE
value|(2 * PAGE_SIZE)
end_define

begin_comment
comment|/*  * Scale factor for scaled integers used to count %cpu time and load avgs.  *  * The number of CPU `tick's that map to a unique `%age' can be expressed  * by the formula (1 / (2 ^ (FSHIFT - 11))).  The maximum load average that  * can be calculated (assuming 32 bits) can be closely approximated using  * the formula (2 ^ (2 * (16 - FSHIFT))) for (FSHIFT< 15).  *  * For the scheduler to maintain a 1:1 mapping of CPU `tick' to `%age',  * FSHIFT must be at least 11; this gives us a maximum load avg of ~1024.  */
end_comment

begin_define
define|#
directive|define
name|FSHIFT
value|11
end_define

begin_comment
comment|/* bits to right of fixed binary point */
end_comment

begin_define
define|#
directive|define
name|FSCALE
value|(1<<FSHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_PARAM_H_ */
end_comment

end_unit

