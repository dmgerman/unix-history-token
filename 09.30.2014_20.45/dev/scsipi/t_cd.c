begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_cd.c,v 1.7 2014/04/25 00:24:39 pooka Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2010 Antti Kantee.  All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<util.h>
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
file|"scsitest.h"
end_include

begin_include
include|#
directive|include
file|"../../h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|noisyeject
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|noisyeject
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
literal|"test for CD eject noisyness "
literal|"(PR kern/43785)"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|noisyeject
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|static
name|char
name|fname
index|[]
init|=
literal|"/dev/rcd0_"
decl_stmt|;
name|int
name|part
decl_stmt|,
name|fd
decl_stmt|,
name|arg
init|=
literal|0
decl_stmt|;
name|RL
argument_list|(
name|part
operator|=
name|getrawpartition
argument_list|()
argument_list|)
expr_stmt|;
name|fname
index|[
name|strlen
argument_list|(
name|fname
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'a'
operator|+
name|part
expr_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
comment|/* 	 * Rump CD emulation has been fixed, so no longer a problem. 	 * 	atf_tc_expect_signal(SIGSEGV, "PR kern/47646: Broken test or " 	    "a real problem in rump or the driver"); 	 */
name|RL
argument_list|(
name|fd
operator|=
name|rump_sys_open
argument_list|(
name|fname
argument_list|,
name|O_RDWR
argument_list|)
argument_list|)
expr_stmt|;
name|RL
argument_list|(
name|rump_sys_ioctl
argument_list|(
name|fd
argument_list|,
name|DIOCEJECT
argument_list|,
operator|&
name|arg
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ
argument_list|(
name|rump_scsitest_err
index|[
name|RUMP_SCSITEST_NOISYSYNC
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|RL
argument_list|(
name|rump_sys_close
argument_list|(
name|fd
argument_list|)
argument_list|)
expr_stmt|;
comment|// atf_tc_expect_fail("PR kern/43785");
name|ATF_REQUIRE_EQ
argument_list|(
name|rump_scsitest_err
index|[
name|RUMP_SCSITEST_NOISYSYNC
index|]
argument_list|,
literal|0
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
name|noisyeject
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

