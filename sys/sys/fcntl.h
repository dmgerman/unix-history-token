begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fcntl.h	8.3 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FCNTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FCNTL_H_
end_define

begin_comment
comment|/*  * This file includes the definitions for open and fcntl  * described by POSIX for<fcntl.h>; it also includes  * related kernel definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
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
comment|/*  * File status flags: these are used by open(2), fcntl(2).  * They are also used (indirectly) in the kernel file structure f_flags,  * which is a superset of the open/fcntl flags.  Open flags and f_flags  * are inter-convertible using OFLAGS(fflags) and FFLAGS(oflags).  * Open/fcntl flags begin with O_; kernel-internal flags begin with F.  */
end_comment

begin_comment
comment|/* open-only flags */
end_comment

begin_define
define|#
directive|define
name|O_RDONLY
value|0x0000
end_define

begin_comment
comment|/* open for reading only */
end_comment

begin_define
define|#
directive|define
name|O_WRONLY
value|0x0001
end_define

begin_comment
comment|/* open for writing only */
end_comment

begin_define
define|#
directive|define
name|O_RDWR
value|0x0002
end_define

begin_comment
comment|/* open for reading and writing */
end_comment

begin_define
define|#
directive|define
name|O_ACCMODE
value|0x0003
end_define

begin_comment
comment|/* mask for above modes */
end_comment

begin_comment
comment|/*  * Kernel encoding of open mode; separate read and write bits that are  * independently testable: 1 greater than the above.  *  * XXX  * FREAD and FWRITE are excluded from the #ifdef _KERNEL so that TIOCFLUSH,  * which was documented to use FREAD/FWRITE, continues to work.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|FREAD
value|0x0001
end_define

begin_define
define|#
directive|define
name|FWRITE
value|0x0002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|O_NONBLOCK
value|0x0004
end_define

begin_comment
comment|/* no delay */
end_comment

begin_define
define|#
directive|define
name|O_APPEND
value|0x0008
end_define

begin_comment
comment|/* set append mode */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|O_SHLOCK
value|0x0010
end_define

begin_comment
comment|/* open with shared file lock */
end_comment

begin_define
define|#
directive|define
name|O_EXLOCK
value|0x0020
end_define

begin_comment
comment|/* open with exclusive file lock */
end_comment

begin_define
define|#
directive|define
name|O_ASYNC
value|0x0040
end_define

begin_comment
comment|/* signal pgrp when data ready */
end_comment

begin_define
define|#
directive|define
name|O_FSYNC
value|0x0080
end_define

begin_comment
comment|/* synchronous writes */
end_comment

begin_define
define|#
directive|define
name|O_NOFOLLOW
value|0x0100
end_define

begin_comment
comment|/* don't follow symlinks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|O_CREAT
value|0x0200
end_define

begin_comment
comment|/* create if nonexistent */
end_comment

begin_define
define|#
directive|define
name|O_TRUNC
value|0x0400
end_define

begin_comment
comment|/* truncate to zero length */
end_comment

begin_define
define|#
directive|define
name|O_EXCL
value|0x0800
end_define

begin_comment
comment|/* error if already exists */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* FMARK/FDEFER kept in f_gcflags */
end_comment

begin_define
define|#
directive|define
name|FMARK
value|0x1
end_define

begin_comment
comment|/* mark during gc() */
end_comment

begin_define
define|#
directive|define
name|FDEFER
value|0x2
end_define

begin_comment
comment|/* defer for next gc pass */
end_comment

begin_define
define|#
directive|define
name|FHASLOCK
value|0x4000
end_define

begin_comment
comment|/* descriptor holds advisory lock */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Defined by POSIX 1003.1; BSD default, but must be distinct from O_RDONLY. */
end_comment

begin_define
define|#
directive|define
name|O_NOCTTY
value|0x8000
end_define

begin_comment
comment|/* don't assign controlling terminal */
end_comment

begin_comment
comment|/* Attempt to bypass buffer cache */
end_comment

begin_define
define|#
directive|define
name|O_DIRECT
value|0x00010000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* convert from open() flags to/from fflags; convert O_RD/WR to FREAD/FWRITE */
end_comment

begin_define
define|#
directive|define
name|FFLAGS
parameter_list|(
name|oflags
parameter_list|)
value|((oflags) + 1)
end_define

begin_define
define|#
directive|define
name|OFLAGS
parameter_list|(
name|fflags
parameter_list|)
value|((fflags) - 1)
end_define

begin_comment
comment|/* bits to save after open */
end_comment

begin_define
define|#
directive|define
name|FMASK
value|(FREAD|FWRITE|FAPPEND|FASYNC|FFSYNC|FNONBLOCK|O_DIRECT)
end_define

begin_comment
comment|/* bits settable by fcntl(F_SETFL, ...) */
end_comment

begin_define
define|#
directive|define
name|FCNTLFLAGS
value|(FAPPEND|FASYNC|FFSYNC|FNONBLOCK|FPOSIXSHM|O_DIRECT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The O_* flags used to have only F* names, which were used in the kernel  * and by fcntl.  We retain the F* names for the kernel f_flag field  * and for backward compatibility for fcntl.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|FAPPEND
value|O_APPEND
end_define

begin_comment
comment|/* kernel/compat */
end_comment

begin_define
define|#
directive|define
name|FASYNC
value|O_ASYNC
end_define

begin_comment
comment|/* kernel/compat */
end_comment

begin_define
define|#
directive|define
name|FFSYNC
value|O_FSYNC
end_define

begin_comment
comment|/* kernel */
end_comment

begin_define
define|#
directive|define
name|FNONBLOCK
value|O_NONBLOCK
end_define

begin_comment
comment|/* kernel */
end_comment

begin_define
define|#
directive|define
name|FNDELAY
value|O_NONBLOCK
end_define

begin_comment
comment|/* compat */
end_comment

begin_define
define|#
directive|define
name|O_NDELAY
value|O_NONBLOCK
end_define

begin_comment
comment|/* compat */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We are out of bits in f_flag (which is a short).  However,  * the flag bits not set in FMASK are only meaningful in the  * initial open syscall.  Those bits can thus be given a  * different meaning for fcntl(2).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/*  * Set by shm_open(3) to get automatic MAP_ASYNC behavior  * for POSIX shared memory objects (which are otherwise  * implemented as plain files).  */
end_comment

begin_define
define|#
directive|define
name|FPOSIXSHM
value|O_NOFOLLOW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Constants used for fcntl(2)  */
end_comment

begin_comment
comment|/* command values */
end_comment

begin_define
define|#
directive|define
name|F_DUPFD
value|0
end_define

begin_comment
comment|/* duplicate file descriptor */
end_comment

begin_define
define|#
directive|define
name|F_GETFD
value|1
end_define

begin_comment
comment|/* get file descriptor flags */
end_comment

begin_define
define|#
directive|define
name|F_SETFD
value|2
end_define

begin_comment
comment|/* set file descriptor flags */
end_comment

begin_define
define|#
directive|define
name|F_GETFL
value|3
end_define

begin_comment
comment|/* get file status flags */
end_comment

begin_define
define|#
directive|define
name|F_SETFL
value|4
end_define

begin_comment
comment|/* set file status flags */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|F_GETOWN
value|5
end_define

begin_comment
comment|/* get SIGIO/SIGURG proc/pgrp */
end_comment

begin_define
define|#
directive|define
name|F_SETOWN
value|6
end_define

begin_comment
comment|/* set SIGIO/SIGURG proc/pgrp */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|F_GETLK
value|7
end_define

begin_comment
comment|/* get record locking information */
end_comment

begin_define
define|#
directive|define
name|F_SETLK
value|8
end_define

begin_comment
comment|/* set record locking information */
end_comment

begin_define
define|#
directive|define
name|F_SETLKW
value|9
end_define

begin_comment
comment|/* F_SETLK; wait if blocked */
end_comment

begin_comment
comment|/* file descriptor flags (F_GETFD, F_SETFD) */
end_comment

begin_define
define|#
directive|define
name|FD_CLOEXEC
value|1
end_define

begin_comment
comment|/* close-on-exec flag */
end_comment

begin_comment
comment|/* record locking flags (F_GETLK, F_SETLK, F_SETLKW) */
end_comment

begin_define
define|#
directive|define
name|F_RDLCK
value|1
end_define

begin_comment
comment|/* shared or read lock */
end_comment

begin_define
define|#
directive|define
name|F_UNLCK
value|2
end_define

begin_comment
comment|/* unlock */
end_comment

begin_define
define|#
directive|define
name|F_WRLCK
value|3
end_define

begin_comment
comment|/* exclusive or write lock */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|F_WAIT
value|0x010
end_define

begin_comment
comment|/* Wait until lock is granted */
end_comment

begin_define
define|#
directive|define
name|F_FLOCK
value|0x020
end_define

begin_comment
comment|/* Use flock(2) semantics for lock */
end_comment

begin_define
define|#
directive|define
name|F_POSIX
value|0x040
end_define

begin_comment
comment|/* Use POSIX semantics for lock */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Advisory file segment locking data type -  * information passed to system by user  */
end_comment

begin_struct
struct|struct
name|flock
block|{
name|off_t
name|l_start
decl_stmt|;
comment|/* starting offset */
name|off_t
name|l_len
decl_stmt|;
comment|/* len = 0 means until end of file */
name|pid_t
name|l_pid
decl_stmt|;
comment|/* lock owner */
name|short
name|l_type
decl_stmt|;
comment|/* lock type: read/write, etc. */
name|short
name|l_whence
decl_stmt|;
comment|/* type of l_start */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/* lock operations for flock(2) */
end_comment

begin_define
define|#
directive|define
name|LOCK_SH
value|0x01
end_define

begin_comment
comment|/* shared file lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_EX
value|0x02
end_define

begin_comment
comment|/* exclusive file lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_NB
value|0x04
end_define

begin_comment
comment|/* don't block when locking */
end_comment

begin_define
define|#
directive|define
name|LOCK_UN
value|0x08
end_define

begin_comment
comment|/* unlock file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|creat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fcntl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_function_decl
name|int
name|flock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

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

begin_comment
comment|/* !_SYS_FCNTL_H_ */
end_comment

end_unit

