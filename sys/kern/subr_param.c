begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)param.c	8.3 (Berkeley) 8/20/94  * $Id: param.c,v 1.25 1997/06/14 11:38:46 bde Exp $  */
end_comment

begin_include
include|#
directive|include
file|"opt_sysvipc.h"
end_include

begin_include
include|#
directive|include
file|"opt_param.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|<sys/sem.h>
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
file|<sys/msg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * System parameter formulae.  *  * This file is copied into each directory where we compile  * the kernel; it should be modified there to suit local taste  * if necessary.  *  * Compiled with -DMAXUSERS=xx  */
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

begin_define
define|#
directive|define
name|NPROC
value|(20 + 16 * MAXUSERS)
end_define

begin_define
define|#
directive|define
name|MAXFILES
value|(NPROC*2)
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
name|MAXFILES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system wide open files limit */
end_comment

begin_decl_stmt
name|int
name|maxfilesperproc
init|=
name|MAXFILES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* per-process open files limit */
end_comment

begin_decl_stmt
name|int
name|ncallout
init|=
literal|16
operator|+
name|NPROC
operator|+
name|MAXFILES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum # of timer events */
end_comment

begin_comment
comment|/* maximum # of mbuf clusters */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NMBCLUSTERS
end_ifndef

begin_define
define|#
directive|define
name|NMBCLUSTERS
value|(512 + MAXUSERS * 16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|nmbclusters
init|=
name|NMBCLUSTERS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allocate 1/4th amount of virtual address space for mbufs XXX */
end_comment

begin_decl_stmt
name|int
name|nmbufs
init|=
name|NMBCLUSTERS
operator|*
literal|4
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
value|(SHMMAXPGS*PAGE_SIZE)
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
value|(SHMMAXPGS)
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
comment|/*  * These may be set to nonzero here or by patching.  * If they are nonzero at bootstrap time then they are  * initialized to values dependent on the memory size.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NBUF
end_ifdef

begin_decl_stmt
name|int
name|nbuf
init|=
name|NBUF
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|nbuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|nswbuf
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These have to be allocated somewhere; allocating  * them here forces loader errors if this file is omitted  * (if they've been externed everywhere else; hah!).  */
end_comment

begin_decl_stmt
name|struct
name|buf
modifier|*
name|swbuf
decl_stmt|;
end_decl_stmt

end_unit

