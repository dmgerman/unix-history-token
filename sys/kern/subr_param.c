begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)param.c	8.3 (Berkeley) 8/20/94  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
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
name|howmany
argument_list|(
literal|30000
argument_list|,
literal|60
operator|*
name|HZ
argument_list|)
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

begin_ifndef
ifndef|#
directive|ifndef
name|MAXFILES
end_ifndef

begin_define
define|#
directive|define
name|MAXFILES
value|(NPROC*2)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_decl_stmt
name|int
name|mbuf_wait
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mbuf sleep time in ticks */
end_comment

begin_comment
comment|/* maximum # of sf_bufs (sendfile(2) zero-copy virtual buffers) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NSFBUFS
end_ifndef

begin_define
define|#
directive|define
name|NSFBUFS
value|(512 + MAXUSERS * 16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|nsfbufs
init|=
name|NSFBUFS
decl_stmt|;
end_decl_stmt

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

