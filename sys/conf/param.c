begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)param.c	7.20 (Berkeley) 6/27/91  *	$Id: param.c,v 1.5 1994/01/21 09:55:52 davidg Exp $  */
end_comment

begin_include
include|#
directive|include
file|"sys/param.h"
end_include

begin_include
include|#
directive|include
file|"sys/systm.h"
end_include

begin_include
include|#
directive|include
file|"sys/socket.h"
end_include

begin_include
include|#
directive|include
file|"sys/proc.h"
end_include

begin_include
include|#
directive|include
file|"sys/vnode.h"
end_include

begin_include
include|#
directive|include
file|"sys/file.h"
end_include

begin_include
include|#
directive|include
file|"sys/callout.h"
end_include

begin_include
include|#
directive|include
file|"sys/clist.h"
end_include

begin_include
include|#
directive|include
file|"sys/mbuf.h"
end_include

begin_include
include|#
directive|include
file|"ufs/quota.h"
end_include

begin_include
include|#
directive|include
file|"sys/kernel.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSHM
end_ifdef

begin_include
include|#
directive|include
file|"machine/vmparam.h"
end_include

begin_include
include|#
directive|include
file|"sys/shm.h"
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
comment|/*  * System parameter formulae.  *  * This file is copied into each directory where we compile  * the kernel; it should be modified there to suit local taste  * if necessary.  *  * Compiled with -DHZ=xx -DTIMEZONE=x -DDST=x -DMAXUSERS=xx -DMAXFDESCS=xx  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|TICKADJ
end_ifndef

begin_decl_stmt
name|int
name|tickadj
init|=
literal|240000
operator|/
operator|(
literal|60
operator|*
name|HZ
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* can adjust 240ms in 60s */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|tickadj
init|=
name|TICKADJ
comment|/* NTP users may prefer a smaller value */
endif|#
directive|endif
expr|struct
name|timezone
name|tz
operator|=
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

begin_define
define|#
directive|define
name|NTEXT
value|(NPROC)
end_define

begin_comment
comment|/* actually the object cache */
end_comment

begin_decl_stmt
name|int
name|vm_cache_max
init|=
name|NTEXT
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NVNODE
value|(NPROC + NTEXT + 100)
end_define

begin_decl_stmt
name|long
name|desiredvnodes
init|=
name|NVNODE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxfdescs
init|=
name|MAXFDESCS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxfiles
init|=
literal|3
operator|*
operator|(
name|NPROC
operator|+
name|MAXUSERS
operator|)
operator|+
literal|80
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncallout
init|=
literal|16
operator|+
name|NPROC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nclist
init|=
literal|60
operator|+
literal|12
operator|*
name|MAXUSERS
decl_stmt|;
end_decl_stmt

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

begin_define
define|#
directive|define
name|SHMMAX
value|(SHMMAXPGS*NBPG)
end_define

begin_define
define|#
directive|define
name|SHMMIN
value|1
end_define

begin_define
define|#
directive|define
name|SHMMNI
value|32
end_define

begin_comment
comment|/*<= SHMMMNI in shm.h */
end_comment

begin_define
define|#
directive|define
name|SHMSEG
value|8
end_define

begin_define
define|#
directive|define
name|SHMALL
value|(SHMMAXPGS/CLSIZE)
end_define

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

begin_comment
comment|/* From kernel.h: */
end_comment

begin_decl_stmt
name|long
name|hostid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hostnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|domainname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|domainnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
name|boottime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
name|time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|phz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lbolt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fixpt_t
name|avenrunnable
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|)
end_if

begin_decl_stmt
name|double
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT_43 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_decl_stmt
name|u_long
name|s_textsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|profiling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
modifier|*
name|kcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s_lowpc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

