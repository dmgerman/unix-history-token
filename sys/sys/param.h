begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)param.h	8.3 (Berkeley) 4/4/95  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

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

begin_comment
comment|/*   * __FreeBSD_version numbers are documented in the Porter's Handbook.  * If you bump the version for any reason, you should update the documentation  * there.  * Currently this lives here:  *  *	doc/en_US.ISO8859-1/books/porters-handbook/book.sgml  *  * scheme is:<major><two digit minor>Rxx  *		'R' is 0 if release branch or x.0-CURRENT before RELENG_*_0  *		is created, otherwise 1.  */
end_comment

begin_undef
undef|#
directive|undef
name|__FreeBSD_version
end_undef

begin_define
define|#
directive|define
name|__FreeBSD_version
value|700038
end_define

begin_comment
comment|/* Master, propagated to newvers */
end_comment

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
value|19
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

begin_define
define|#
directive|define
name|SPECNAMELEN
value|63
end_define

begin_comment
comment|/* max length of devicename */
end_comment

begin_comment
comment|/* More types and definitions used throughout the kernel. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/priority.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* Signals. */
end_comment

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Machine type dependent parameters. */
end_comment

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

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
name|DEV_BSHIFT
end_ifndef

begin_define
define|#
directive|define
name|DEV_BSHIFT
value|9
end_define

begin_comment
comment|/* log2(DEV_BSIZE) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEV_BSIZE
value|(1<<DEV_BSHIFT)
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

begin_ifndef
ifndef|#
directive|ifndef
name|DFLTPHYS
end_ifndef

begin_define
define|#
directive|define
name|DFLTPHYS
value|(64 * 1024)
end_define

begin_comment
comment|/* default max raw I/O transfer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPHYS
end_ifndef

begin_define
define|#
directive|define
name|MAXPHYS
value|(128 * 1024)
end_define

begin_comment
comment|/* max raw I/O transfer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXDUMPPGS
end_ifndef

begin_define
define|#
directive|define
name|MAXDUMPPGS
value|(DFLTPHYS/PAGE_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|MJUMPAGESIZE
value|PAGE_SIZE
end_define

begin_comment
comment|/* jumbo cluster 4k */
end_comment

begin_define
define|#
directive|define
name|MJUM9BYTES
value|(9 * 1024)
end_define

begin_comment
comment|/* jumbo cluster 9k */
end_comment

begin_define
define|#
directive|define
name|MJUM16BYTES
value|(16 * 1024)
end_define

begin_comment
comment|/* jumbo cluster 16k */
end_comment

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

begin_comment
comment|/* clicks to bytes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ctob
end_ifndef

begin_define
define|#
directive|define
name|ctob
parameter_list|(
name|x
parameter_list|)
value|((x)<<PAGE_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bytes to clicks */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|btoc
end_ifndef

begin_define
define|#
directive|define
name|btoc
parameter_list|(
name|x
parameter_list|)
value|(((vm_offset_t)(x)+PAGE_MASK)>>PAGE_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * btodb() is messy and perhaps slow because `bytes' may be an off_t.  We  * want to shift an unsigned type to avoid sign extension and we don't  * want to widen `bytes' unnecessarily.  Assume that the result fits in  * a daddr_t.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|btodb
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dbtob
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NO_NAMESPACE_POLLUTION */
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
name|PDROP
value|0x200
end_define

begin_comment
comment|/* OR'd with pri to stop re-entry of interlock mutex */
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
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
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
comment|/*  * File system parameters and macros.  *  * MAXBSIZE -	Filesystems are made out of blocks of at most MAXBSIZE bytes  *		per block.  MAXBSIZE may be made larger without effecting  *		any existing filesystems as long as it does not exceed MAXPHYS,  *		and may be made smaller at the risk of not being able to use  *		filesystems which require a block size exceeding MAXBSIZE.  *  * BKVASIZE -	Nominal buffer space per buffer, in bytes.  BKVASIZE is the  *		minimum KVM memory reservation the kernel is willing to make.  *		Filesystems can of course request smaller chunks.  Actual   *		backing memory uses a chunk size of a page (PAGE_SIZE).  *  *		If you make BKVASIZE too small you risk seriously fragmenting  *		the buffer KVM map which may slow things down a bit.  If you  *		make it too big the kernel will not be able to optimally use   *		the KVM memory reserved for the buffer cache and will wind   *		up with too-few buffers.  *  *		The default is 16384, roughly 2x the block size used by a  *		normal UFS filesystem.  */
end_comment

begin_define
define|#
directive|define
name|MAXBSIZE
value|65536
end_define

begin_comment
comment|/* must be power of 2 */
end_comment

begin_define
define|#
directive|define
name|BKVASIZE
value|16384
end_define

begin_comment
comment|/* must be power of 2 */
end_comment

begin_define
define|#
directive|define
name|BKVAMASK
value|(BKVASIZE-1)
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Basic byte order function prototypes for non-inline functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_BYTEORDER_PROTOTYPED
end_ifndef

begin_define
define|#
directive|define
name|_BYTEORDER_PROTOTYPED
end_define

begin_function_decl
name|__BEGIN_DECLS
name|__uint32_t
name|htonl
parameter_list|(
name|__uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__uint16_t
name|htons
parameter_list|(
name|__uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__uint32_t
name|ntohl
parameter_list|(
name|__uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__uint16_t
name|ntohs
parameter_list|(
name|__uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_BYTEORDER_FUNC_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_BYTEORDER_FUNC_DEFINED
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|__htonl(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|__htons(x)
end_define

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|__ntohl(x)
end_define

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|__ntohs(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BYTEORDER_FUNC_DEFINED */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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

begin_define
define|#
directive|define
name|dbtoc
parameter_list|(
name|db
parameter_list|)
comment|/* calculates devblks to pages */
define|\
value|((db + (ctodb(1) - 1))>> (PAGE_SHIFT - DEV_BSHIFT))
end_define

begin_define
define|#
directive|define
name|ctodb
parameter_list|(
name|db
parameter_list|)
comment|/* calculates pages to devblks */
define|\
value|((db)<< (PAGE_SHIFT - DEV_BSHIFT))
end_define

begin_comment
comment|/*  * Solaris compatibility definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SOLARIS_C_SOURCE
end_ifdef

begin_define
define|#
directive|define
name|PAGESIZE
value|PAGE_SIZE
end_define

begin_comment
comment|/*  * The OpenSolaris version is set according to the version last imported  * from http://dlc.sun.com/osol/on/downloads/current/. In FreeBSD header  * files it can be used to determine the level of compatibility that the  * FreeBSD headers provide to OpenSolaris code. Perhaps one day there  * will be a really, really Single Unix Specification.  */
end_comment

begin_define
define|#
directive|define
name|__OpenSolaris_version
value|20060731
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
comment|/* _SYS_PARAM_H_ */
end_comment

end_unit

