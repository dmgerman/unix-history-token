begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_basic.c,v 1.2 2011/02/22 13:25:18 pooka Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"../../h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|lseekrv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|lseekrv
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
literal|"Test lseek return values"
argument_list|)
expr_stmt|;
block|}
end_block

begin_define
define|#
directive|define
name|TESTFILE
value|"testi"
end_define

begin_define
define|#
directive|define
name|FIVE_MEGS
value|(5*1024*1024)
end_define

begin_define
define|#
directive|define
name|FIVE_GIGS
value|(5*1024*1024*1024LL)
end_define

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|lseekrv
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|off_t
name|rv
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|RZ
argument_list|(
name|rump_init
argument_list|()
argument_list|)
expr_stmt|;
name|RL
argument_list|(
name|fd
operator|=
name|rump_sys_open
argument_list|(
name|TESTFILE
argument_list|,
name|O_RDWR
operator||
name|O_CREAT
argument_list|,
literal|0777
argument_list|)
argument_list|)
expr_stmt|;
name|rv
operator|=
name|rump_sys_lseek
argument_list|(
literal|37
argument_list|,
name|FIVE_MEGS
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_ERRNO
argument_list|(
name|EBADF
argument_list|,
name|rv
operator|==
operator|-
literal|1
argument_list|)
expr_stmt|;
name|rv
operator|=
name|rump_sys_lseek
argument_list|(
name|fd
argument_list|,
name|FIVE_MEGS
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ
argument_list|(
name|rv
argument_list|,
name|FIVE_MEGS
argument_list|)
expr_stmt|;
name|rv
operator|=
name|rump_sys_lseek
argument_list|(
name|fd
argument_list|,
name|FIVE_GIGS
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ
argument_list|(
name|rv
argument_list|,
name|FIVE_GIGS
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
name|lseekrv
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

