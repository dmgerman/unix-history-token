begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_vm.c,v 1.3 2012/03/17 18:00:28 hannken Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<atf-c.h>
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
file|"../../h_macros.h"
end_include

begin_include
include|#
directive|include
file|"../kernspace/kernspace.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|busypage
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|busypage
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
literal|"Checks VM pagewaits work"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|busypage
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|rump_init
argument_list|()
expr_stmt|;
name|rump_schedule
argument_list|()
expr_stmt|;
name|rumptest_busypage
argument_list|()
expr_stmt|;
name|rump_unschedule
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|uvmwait
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|uvmwait
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
literal|"Tests that uvm_wait works"
argument_list|)
expr_stmt|;
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"timeout"
argument_list|,
literal|"30"
argument_list|)
expr_stmt|;
block|}
end_block

begin_define
define|#
directive|define
name|UVMWAIT_LIMIT
value|1024*1024
end_define

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|uvmwait
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|char
name|buf
index|[
literal|64
index|]
decl_stmt|;
comment|/* limit rump kernel memory */
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%d"
argument_list|,
name|UVMWAIT_LIMIT
argument_list|)
expr_stmt|;
name|setenv
argument_list|(
literal|"RUMP_MEMLIMIT"
argument_list|,
name|buf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
name|rump_schedule
argument_list|()
expr_stmt|;
name|rumptest_alloc
argument_list|(
name|UVMWAIT_LIMIT
argument_list|)
expr_stmt|;
name|rump_unschedule
argument_list|()
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
name|busypage
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|uvmwait
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

