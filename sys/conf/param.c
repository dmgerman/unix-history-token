begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)param.c	8.3 (Berkeley) 8/20/94  */
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

begin_define
define|#
directive|define
name|NTEXT
value|(80 + NPROC / 8)
end_define

begin_comment
comment|/* actually the object cache */
end_comment

begin_define
define|#
directive|define
name|NVNODE
value|(NPROC + NTEXT + 100)
end_define

begin_decl_stmt
name|int
name|desiredvnodes
init|=
name|NVNODE
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

end_unit

