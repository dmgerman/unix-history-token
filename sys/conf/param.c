begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)param.c	8.2 (Berkeley) 1/21/94  * $Id: param.c,v 1.7 1995/02/16 11:29:19 joerg Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/clist.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/quota.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSHM
end_ifdef

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<sys/shm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSEM
end_ifdef

begin_include
include|#
directive|include
file|"sys/sem.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVMSG
end_ifdef

begin_include
include|#
directive|include
file|"sys/msg.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * System parameter formulae.  *  * This file is copied into each directory where we compile  * the kernel; it should be modified there to suit local taste  * if necessary.  *  * Compiled with -DHZ=xx -DTIMEZONE=x -DDST=x -DMAXUSERS=xx  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HZ
end_ifndef

begin_define
define|#
directive|define
name|HZ
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|hz
init|=
name|HZ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tick
init|=
literal|1000000
operator|/
name|HZ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tickadj
init|=
literal|30000
operator|/
operator|(
literal|60
operator|*
name|HZ
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* can adjust 30ms in 60s */
end_comment

begin_decl_stmt
name|struct
name|timezone
name|tz
init|=
block|{
name|TIMEZONE
block|,
name|DST
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NPROC
value|(20 + 16 * MAXUSERS)
end_define

begin_decl_stmt
name|int
name|maxproc
init|=
name|NPROC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum # of processes */
end_comment

begin_decl_stmt
name|int
name|maxprocperuid
init|=
name|NPROC
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum # of processes per user */
end_comment

begin_decl_stmt
name|int
name|maxfiles
init|=
name|NPROC
operator|*
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system wide open files limit */
end_comment

begin_decl_stmt
name|int
name|maxfilesperproc
init|=
name|NPROC
operator|*
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system wide open files limit */
end_comment

begin_decl_stmt
name|int
name|ncallout
init|=
literal|16
operator|+
name|NPROC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum # of timer events */
end_comment

begin_decl_stmt
name|int
name|nmbclusters
init|=
name|NMBCLUSTERS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fscale
init|=
name|FSCALE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel uses `FSCALE', user uses `fscale' */
end_comment

begin_comment
comment|/*  * Values in support of System V compatible shared memory.	XXX  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSHM
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SHMMAX
end_ifndef

begin_define
define|#
directive|define
name|SHMMAX
value|(SHMMAXPGS*NBPG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHMMIN
end_ifndef

begin_define
define|#
directive|define
name|SHMMIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHMMNI
end_ifndef

begin_define
define|#
directive|define
name|SHMMNI
value|32
end_define

begin_comment
comment|/*<= SHMMMNI in shm.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHMSEG
end_ifndef

begin_define
define|#
directive|define
name|SHMSEG
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHMALL
end_ifndef

begin_define
define|#
directive|define
name|SHMALL
value|(SHMMAXPGS/CLSIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|shminfo
name|shminfo
init|=
block|{
name|SHMMAX
block|,
name|SHMMIN
block|,
name|SHMMNI
block|,
name|SHMSEG
block|,
name|SHMALL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Values in support of System V compatible semaphores.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSEM
end_ifdef

begin_decl_stmt
name|struct
name|seminfo
name|seminfo
init|=
block|{
name|SEMMAP
block|,
comment|/* # of entries in semaphore map */
name|SEMMNI
block|,
comment|/* # of semaphore identifiers */
name|SEMMNS
block|,
comment|/* # of semaphores in system */
name|SEMMNU
block|,
comment|/* # of undo structures in system */
name|SEMMSL
block|,
comment|/* max # of semaphores per id */
name|SEMOPM
block|,
comment|/* max # of operations per semop call */
name|SEMUME
block|,
comment|/* max # of undo entries per process */
name|SEMUSZ
block|,
comment|/* size in bytes of undo structure */
name|SEMVMX
block|,
comment|/* semaphore maximum value */
name|SEMAEM
comment|/* adjust on exit max value */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Values in support of System V compatible messages.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVMSG
end_ifdef

begin_decl_stmt
name|struct
name|msginfo
name|msginfo
init|=
block|{
name|MSGMAX
block|,
comment|/* max chars in a message */
name|MSGMNI
block|,
comment|/* # of message queue identifiers */
name|MSGMNB
block|,
comment|/* max chars in a queue */
name|MSGTQL
block|,
comment|/* max messages in system */
name|MSGSSZ
block|,
comment|/* size of a message segment */
comment|/* (must be small power of 2 greater than 4) */
name|MSGSEG
comment|/* number of message segments */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These are initialized at bootstrap time  * to values dependent on memory size  */
end_comment

begin_decl_stmt
name|int
name|nbuf
decl_stmt|,
name|nswbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These have to be allocated somewhere; allocating  * them here forces loader errors if this file is omitted  * (if they've been externed everywhere else; hah!).  */
end_comment

begin_decl_stmt
name|struct
name|callout
modifier|*
name|callout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cblock
modifier|*
name|cfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
modifier|*
name|buf
decl_stmt|,
modifier|*
name|swbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buffers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Proc/pgrp hashing.  * Here so that hash table sizes can depend on MAXUSERS/NPROC.  * Hash size must be a power of two.  * NOW omission of this file will cause loader errors!  */
end_comment

begin_if
if|#
directive|if
name|NPROC
operator|>
literal|1024
end_if

begin_define
define|#
directive|define
name|PIDHSZ
value|512
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|NPROC
operator|>
literal|512
end_if

begin_define
define|#
directive|define
name|PIDHSZ
value|256
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|NPROC
operator|>
literal|256
end_if

begin_define
define|#
directive|define
name|PIDHSZ
value|128
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIDHSZ
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|proc
modifier|*
name|pidhash
index|[
name|PIDHSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pgrp
modifier|*
name|pgrphash
index|[
name|PIDHSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pidhashmask
init|=
name|PIDHSZ
operator|-
literal|1
decl_stmt|;
end_decl_stmt

end_unit

