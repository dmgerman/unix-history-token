begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)param.c	8.3 (Berkeley) 8/20/94  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_param.h"
end_include

begin_include
include|#
directive|include
file|"opt_maxusers.h"
end_include

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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_comment
comment|/*  * System parameter formulae.  */
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

begin_define
define|#
directive|define
name|NPROC
value|(20 + 16 * maxusers)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NBUF
end_ifndef

begin_define
define|#
directive|define
name|NBUF
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXFILES
end_ifndef

begin_define
define|#
directive|define
name|MAXFILES
value|(maxproc * 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|hz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tick
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tickadj
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* can adjust 30ms in 60s */
end_comment

begin_decl_stmt
name|int
name|maxusers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base tunable */
end_comment

begin_decl_stmt
name|int
name|maxproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum # of processes */
end_comment

begin_decl_stmt
name|int
name|maxprocperuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max # of procs per user */
end_comment

begin_decl_stmt
name|int
name|maxfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sys. wide open files limit */
end_comment

begin_decl_stmt
name|int
name|maxfilesperproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* per-proc open files limit */
end_comment

begin_decl_stmt
name|int
name|ncallout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum # of timer events */
end_comment

begin_decl_stmt
name|int
name|nbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nswbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxswzone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max swmeta KVA storage */
end_comment

begin_decl_stmt
name|int
name|maxbcache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max buffer cache KVA storage */
end_comment

begin_decl_stmt
name|u_quad_t
name|maxtsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max text size */
end_comment

begin_decl_stmt
name|u_quad_t
name|dfldsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial data size limit */
end_comment

begin_decl_stmt
name|u_quad_t
name|maxdsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max data size */
end_comment

begin_decl_stmt
name|u_quad_t
name|dflssiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial stack size limit */
end_comment

begin_decl_stmt
name|u_quad_t
name|maxssiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max stack size */
end_comment

begin_decl_stmt
name|u_quad_t
name|sgrowsiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* amount to grow stack */
end_comment

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

begin_comment
comment|/*  * Boot time overrides that are not scaled against main memory  */
end_comment

begin_function
name|void
name|init_param1
parameter_list|(
name|void
parameter_list|)
block|{
name|hz
operator|=
name|HZ
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.hz"
argument_list|,
operator|&
name|hz
argument_list|)
expr_stmt|;
name|tick
operator|=
literal|1000000
operator|/
name|hz
expr_stmt|;
name|tickadj
operator|=
name|howmany
argument_list|(
literal|30000
argument_list|,
literal|60
operator|*
name|hz
argument_list|)
expr_stmt|;
comment|/* can adjust 30ms in 60s */
ifdef|#
directive|ifdef
name|VM_SWZONE_SIZE_MAX
name|maxswzone
operator|=
name|VM_SWZONE_SIZE_MAX
expr_stmt|;
endif|#
directive|endif
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.maxswzone"
argument_list|,
operator|&
name|maxswzone
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VM_BCACHE_SIZE_MAX
name|maxbcache
operator|=
name|VM_BCACHE_SIZE_MAX
expr_stmt|;
endif|#
directive|endif
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.maxbcache"
argument_list|,
operator|&
name|maxbcache
argument_list|)
expr_stmt|;
name|maxtsiz
operator|=
name|MAXTSIZ
expr_stmt|;
name|TUNABLE_QUAD_FETCH
argument_list|(
literal|"kern.maxtsiz"
argument_list|,
operator|&
name|maxtsiz
argument_list|)
expr_stmt|;
name|dfldsiz
operator|=
name|DFLDSIZ
expr_stmt|;
name|TUNABLE_QUAD_FETCH
argument_list|(
literal|"kern.dfldsiz"
argument_list|,
operator|&
name|dfldsiz
argument_list|)
expr_stmt|;
name|maxdsiz
operator|=
name|MAXDSIZ
expr_stmt|;
name|TUNABLE_QUAD_FETCH
argument_list|(
literal|"kern.maxdsiz"
argument_list|,
operator|&
name|maxdsiz
argument_list|)
expr_stmt|;
name|dflssiz
operator|=
name|DFLSSIZ
expr_stmt|;
name|TUNABLE_QUAD_FETCH
argument_list|(
literal|"kern.dflssiz"
argument_list|,
operator|&
name|dflssiz
argument_list|)
expr_stmt|;
name|maxssiz
operator|=
name|MAXSSIZ
expr_stmt|;
name|TUNABLE_QUAD_FETCH
argument_list|(
literal|"kern.maxssiz"
argument_list|,
operator|&
name|maxssiz
argument_list|)
expr_stmt|;
name|sgrowsiz
operator|=
name|SGROWSIZ
expr_stmt|;
name|TUNABLE_QUAD_FETCH
argument_list|(
literal|"kern.sgrowsiz"
argument_list|,
operator|&
name|sgrowsiz
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Boot time overrides that are scaled against main memory  */
end_comment

begin_function
name|void
name|init_param2
parameter_list|(
name|int
name|physpages
parameter_list|)
block|{
comment|/* Base parameters */
name|maxusers
operator|=
name|MAXUSERS
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.maxusers"
argument_list|,
operator|&
name|maxusers
argument_list|)
expr_stmt|;
if|if
condition|(
name|maxusers
operator|==
literal|0
condition|)
block|{
name|maxusers
operator|=
name|physpages
operator|/
operator|(
literal|2
operator|*
literal|1024
operator|*
literal|1024
operator|/
name|PAGE_SIZE
operator|)
expr_stmt|;
if|if
condition|(
name|maxusers
operator|<
literal|32
condition|)
name|maxusers
operator|=
literal|32
expr_stmt|;
if|if
condition|(
name|maxusers
operator|>
literal|384
condition|)
name|maxusers
operator|=
literal|384
expr_stmt|;
block|}
comment|/* 	 * The following can be overridden after boot via sysctl.  Note: 	 * unless overriden, these macros are ultimately based on maxusers. 	 */
name|maxproc
operator|=
name|NPROC
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.maxproc"
argument_list|,
operator|&
name|maxproc
argument_list|)
expr_stmt|;
comment|/* 	 * Limit maxproc so that kmap entries cannot be exhausted by 	 * processes. 	 */
if|if
condition|(
name|maxproc
operator|>
operator|(
name|physpages
operator|/
literal|12
operator|)
condition|)
name|maxproc
operator|=
name|physpages
operator|/
literal|12
expr_stmt|;
name|maxfiles
operator|=
name|MAXFILES
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.maxfiles"
argument_list|,
operator|&
name|maxfiles
argument_list|)
expr_stmt|;
name|maxprocperuid
operator|=
operator|(
name|maxproc
operator|*
literal|9
operator|)
operator|/
literal|10
expr_stmt|;
name|maxfilesperproc
operator|=
operator|(
name|maxfiles
operator|*
literal|9
operator|)
operator|/
literal|10
expr_stmt|;
comment|/* 	 * Cannot be changed after boot. 	 */
name|nbuf
operator|=
name|NBUF
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.nbuf"
argument_list|,
operator|&
name|nbuf
argument_list|)
expr_stmt|;
name|ncallout
operator|=
literal|16
operator|+
name|maxproc
operator|+
name|maxfiles
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"kern.ncallout"
argument_list|,
operator|&
name|ncallout
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

