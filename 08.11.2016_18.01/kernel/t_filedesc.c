begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_filedesc.c,v 1.5 2012/03/18 09:46:50 jruoho Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_filedesc.c,v 1.5 2012/03/18 09:46:50 jruoho Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<rump/rump.h>
end_include

begin_include
include|#
directive|include
file|<rump/rump_syscalls.h>
end_include

begin_include
include|#
directive|include
file|"../h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|getfilerace
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|getfilerace
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"race between multithreaded proc. "
literal|"fd_getfile() and fd_close() (PR kern/43694)"
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|volatile
name|bool
name|quit
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
modifier|*
name|wrkwrk
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
comment|/* just something to cause fd_getfile() to be called */
while|while
condition|(
operator|!
name|quit
condition|)
name|rump_sys_write
argument_list|(
name|fd
argument_list|,
operator|&
name|fd
argument_list|,
sizeof|sizeof
argument_list|(
name|fd
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* for me, 1000 triggers extremely seldom, 10k sometimes, 100k almost always */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_ITERATIONS
value|10000
end_define

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|getfilerace
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|pthread_t
name|pt
decl_stmt|;
name|int
name|fd_wrk
decl_stmt|;
name|int
name|i
decl_stmt|,
name|iters
decl_stmt|;
comment|/* 	 * Want a multiprocessor virtual kernel.  A multiprocessor host 	 * probably helps too, but that's harder to do in software... 	 */
name|setenv
argument_list|(
literal|"RUMP_NCPU"
argument_list|,
literal|"2"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
name|fd
operator|=
name|fd_wrk
operator|=
name|rump_sys_open
argument_list|(
literal|"/dev/null"
argument_list|,
name|O_RDWR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"cannot open /dev/null"
argument_list|)
expr_stmt|;
if|if
condition|(
name|atf_tc_has_config_var
argument_list|(
name|tc
argument_list|,
literal|"iters"
argument_list|)
condition|)
name|iters
operator|=
name|atoi
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"iters"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|iters
operator|=
name|DEFAULT_ITERATIONS
expr_stmt|;
name|pthread_create
argument_list|(
operator|&
name|pt
argument_list|,
name|NULL
argument_list|,
name|wrkwrk
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|iters
condition|;
name|i
operator|++
control|)
block|{
name|rump_sys_close
argument_list|(
name|fd_wrk
argument_list|)
expr_stmt|;
name|fd_wrk
operator|=
name|rump_sys_open
argument_list|(
literal|"/dev/null"
argument_list|,
name|O_RDWR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|fd
operator|==
name|fd_wrk
argument_list|)
expr_stmt|;
block|}
name|quit
operator|=
name|true
expr_stmt|;
name|pthread_join
argument_list|(
name|pt
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|getfilerace
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

