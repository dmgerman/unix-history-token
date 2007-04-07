begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)unistd.h	8.2 (Berkeley) 1/7/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UNISTD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UNISTD_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * POSIX options and option groups we unconditionally do or don't  * implement.  Those options which are implemented (or not) entirely  * in user mode are defined in<unistd.h>.  Please keep this list in  * alphabetical order.  *  * Anything which is defined as zero below **must** have an  * implementation for the corresponding sysconf() which is able to  * determine conclusively whether or not the feature is supported.  * Anything which is defined as other than -1 below **must** have  * complete headers, types, and function declarations as specified by  * the POSIX standard; however, if the relevant sysconf() function  * returns -1, the functions may be stubbed out.  */
end_comment

begin_define
define|#
directive|define
name|_POSIX_ADVISORY_INFO
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_ASYNCHRONOUS_IO
value|0
end_define

begin_define
define|#
directive|define
name|_POSIX_CHOWN_RESTRICTED
value|1
end_define

begin_define
define|#
directive|define
name|_POSIX_CLOCK_SELECTION
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_CPUTIME
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_FSYNC
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_IPV6
value|0
end_define

begin_define
define|#
directive|define
name|_POSIX_JOB_CONTROL
value|1
end_define

begin_define
define|#
directive|define
name|_POSIX_MAPPED_FILES
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_MEMLOCK
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_MEMLOCK_RANGE
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_MEMORY_PROTECTION
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_MESSAGE_PASSING
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_MONOTONIC_CLOCK
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_NO_TRUNC
value|1
end_define

begin_define
define|#
directive|define
name|_POSIX_PRIORITIZED_IO
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_PRIORITY_SCHEDULING
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_RAW_SOCKETS
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_REALTIME_SIGNALS
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_SEMAPHORES
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_SHARED_MEMORY_OBJECTS
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_SPORADIC_SERVER
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_SYNCHRONIZED_IO
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_TIMEOUTS
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_TIMERS
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_TYPED_MEMORY_OBJECTS
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|0xff
end_define

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|_XOPEN_SHM
value|1
end_define

begin_define
define|#
directive|define
name|_XOPEN_STREAMS
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Although we have saved user/group IDs, we do not use them in setuid  * as described in POSIX 1003.1, because the feature does not work for  * root.  We use the saved IDs in seteuid/setegid, which are not currently  * part of the POSIX 1003.1 specification.  XXX revisit for 1003.1-2001  * as this is now mandatory.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_NOT_AVAILABLE
end_ifdef

begin_define
define|#
directive|define
name|_POSIX_SAVED_IDS
value|1
end_define

begin_comment
comment|/* saved set-user-ID and set-group-ID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the POSIX.1 version we target for compliance. */
end_comment

begin_define
define|#
directive|define
name|_POSIX_VERSION
value|200112L
end_define

begin_comment
comment|/* access function */
end_comment

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_comment
comment|/* test for existence of file */
end_comment

begin_define
define|#
directive|define
name|X_OK
value|0x01
end_define

begin_comment
comment|/* test for execute or search permission */
end_comment

begin_define
define|#
directive|define
name|W_OK
value|0x02
end_define

begin_comment
comment|/* test for write permission */
end_comment

begin_define
define|#
directive|define
name|R_OK
value|0x04
end_define

begin_comment
comment|/* test for read permission */
end_comment

begin_comment
comment|/* whence values for lseek(2) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* set file offset to offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_comment
comment|/* set file offset to current plus offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/* set file offset to EOF plus offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|SEEK_DATA
value|3
end_define

begin_comment
comment|/* set file offset to next data past offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_HOLE
value|4
end_define

begin_comment
comment|/* set file offset to next hole past offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/* whence values for lseek(2); renamed by POSIX 1003.1 */
end_comment

begin_define
define|#
directive|define
name|L_SET
value|SEEK_SET
end_define

begin_define
define|#
directive|define
name|L_INCR
value|SEEK_CUR
end_define

begin_define
define|#
directive|define
name|L_XTND
value|SEEK_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* configurable pathname variables */
end_comment

begin_define
define|#
directive|define
name|_PC_LINK_MAX
value|1
end_define

begin_define
define|#
directive|define
name|_PC_MAX_CANON
value|2
end_define

begin_define
define|#
directive|define
name|_PC_MAX_INPUT
value|3
end_define

begin_define
define|#
directive|define
name|_PC_NAME_MAX
value|4
end_define

begin_define
define|#
directive|define
name|_PC_PATH_MAX
value|5
end_define

begin_define
define|#
directive|define
name|_PC_PIPE_BUF
value|6
end_define

begin_define
define|#
directive|define
name|_PC_CHOWN_RESTRICTED
value|7
end_define

begin_define
define|#
directive|define
name|_PC_NO_TRUNC
value|8
end_define

begin_define
define|#
directive|define
name|_PC_VDISABLE
value|9
end_define

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199309
end_if

begin_define
define|#
directive|define
name|_PC_ASYNC_IO
value|53
end_define

begin_define
define|#
directive|define
name|_PC_PRIO_IO
value|54
end_define

begin_define
define|#
directive|define
name|_PC_SYNC_IO
value|55
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|_PC_ALLOC_SIZE_MIN
value|10
end_define

begin_define
define|#
directive|define
name|_PC_FILESIZEBITS
value|12
end_define

begin_define
define|#
directive|define
name|_PC_REC_INCR_XFER_SIZE
value|14
end_define

begin_define
define|#
directive|define
name|_PC_REC_MAX_XFER_SIZE
value|15
end_define

begin_define
define|#
directive|define
name|_PC_REC_MIN_XFER_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|_PC_REC_XFER_ALIGN
value|17
end_define

begin_define
define|#
directive|define
name|_PC_SYMLINK_MAX
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|_PC_ACL_EXTENDED
value|59
end_define

begin_define
define|#
directive|define
name|_PC_ACL_PATH_MAX
value|60
end_define

begin_define
define|#
directive|define
name|_PC_CAP_PRESENT
value|61
end_define

begin_define
define|#
directive|define
name|_PC_INF_PRESENT
value|62
end_define

begin_define
define|#
directive|define
name|_PC_MAC_PRESENT
value|63
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* From OpenSolaris, used by SEEK_DATA/SEEK_HOLE. */
end_comment

begin_define
define|#
directive|define
name|_PC_MIN_HOLE_SIZE
value|21
end_define

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_comment
comment|/*  * rfork() options.  *  * XXX currently, some operations without RFPROC set are not supported.  */
end_comment

begin_define
define|#
directive|define
name|RFNAMEG
value|(1<<0)
end_define

begin_comment
comment|/* UNIMPL new plan9 `name space' */
end_comment

begin_define
define|#
directive|define
name|RFENVG
value|(1<<1)
end_define

begin_comment
comment|/* UNIMPL copy plan9 `env space' */
end_comment

begin_define
define|#
directive|define
name|RFFDG
value|(1<<2)
end_define

begin_comment
comment|/* copy fd table */
end_comment

begin_define
define|#
directive|define
name|RFNOTEG
value|(1<<3)
end_define

begin_comment
comment|/* UNIMPL create new plan9 `note group' */
end_comment

begin_define
define|#
directive|define
name|RFPROC
value|(1<<4)
end_define

begin_comment
comment|/* change child (else changes curproc) */
end_comment

begin_define
define|#
directive|define
name|RFMEM
value|(1<<5)
end_define

begin_comment
comment|/* share `address space' */
end_comment

begin_define
define|#
directive|define
name|RFNOWAIT
value|(1<<6)
end_define

begin_comment
comment|/* give child to init */
end_comment

begin_define
define|#
directive|define
name|RFCNAMEG
value|(1<<10)
end_define

begin_comment
comment|/* UNIMPL zero plan9 `name space' */
end_comment

begin_define
define|#
directive|define
name|RFCENVG
value|(1<<11)
end_define

begin_comment
comment|/* UNIMPL zero plan9 `env space' */
end_comment

begin_define
define|#
directive|define
name|RFCFDG
value|(1<<12)
end_define

begin_comment
comment|/* close all fds, zero fd table */
end_comment

begin_define
define|#
directive|define
name|RFTHREAD
value|(1<<13)
end_define

begin_comment
comment|/* enable kernel thread support */
end_comment

begin_define
define|#
directive|define
name|RFSIGSHARE
value|(1<<14)
end_define

begin_comment
comment|/* share signal handlers */
end_comment

begin_define
define|#
directive|define
name|RFLINUXTHPN
value|(1<<16)
end_define

begin_comment
comment|/* do linux clone exit parent notification */
end_comment

begin_define
define|#
directive|define
name|RFSTOPPED
value|(1<<17)
end_define

begin_comment
comment|/* leave child in a stopped state */
end_comment

begin_define
define|#
directive|define
name|RFHIGHPID
value|(1<<18)
end_define

begin_comment
comment|/* use a pid higher then 10 (idleproc) */
end_comment

begin_define
define|#
directive|define
name|RFPPWAIT
value|(1<<31)
end_define

begin_comment
comment|/* parent sleeps until child exits (vfork) */
end_comment

begin_define
define|#
directive|define
name|RFKERNELONLY
value|(RFSTOPPED | RFHIGHPID | RFPPWAIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UNISTD_H_ */
end_comment

end_unit

