begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)param.c	7.15 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1980, 1986, 1989 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"../sys/param.h"
end_include

begin_include
include|#
directive|include
file|"../sys/systm.h"
end_include

begin_include
include|#
directive|include
file|"../sys/socket.h"
end_include

begin_include
include|#
directive|include
file|"../sys/user.h"
end_include

begin_include
include|#
directive|include
file|"../sys/proc.h"
end_include

begin_include
include|#
directive|include
file|"../sys/vnode.h"
end_include

begin_include
include|#
directive|include
file|"../sys/file.h"
end_include

begin_include
include|#
directive|include
file|"../sys/callout.h"
end_include

begin_include
include|#
directive|include
file|"../sys/clist.h"
end_include

begin_include
include|#
directive|include
file|"../sys/mbuf.h"
end_include

begin_include
include|#
directive|include
file|"../ufs/quota.h"
end_include

begin_include
include|#
directive|include
file|"../sys/kernel.h"
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
file|"../sys/shm.h"
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
value|(20 + 8 * MAXUSERS)
end_define

begin_decl_stmt
name|int
name|nproc
init|=
name|NPROC
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NTEXT
value|100
end_define

begin_comment
comment|/* actually the object cache */
end_comment

begin_define
define|#
directive|define
name|NVNODE
value|(NPROC + NTEXT + 300)
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
name|nfile
init|=
literal|16
operator|*
operator|(
name|NPROC
operator|+
literal|16
operator|+
name|MAXUSERS
operator|)
operator|/
literal|10
operator|+
literal|32
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
comment|/*  * Values in support of System V compatible shared memory.  */
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
name|proc
modifier|*
name|proc
decl_stmt|,
modifier|*
name|procNPROC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|file
modifier|*
name|file
decl_stmt|,
modifier|*
name|fileNFILE
decl_stmt|;
end_decl_stmt

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

