begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_exect.c,v 1.6 2016/12/12 10:34:55 joerg Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2014 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|t_exect_null
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|t_exect_null
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
literal|"Tests an empty exect(2) executing"
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
specifier|volatile
name|sig_atomic_t
name|caught
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|sigtrap_handler
parameter_list|(
name|int
name|sig
parameter_list|,
name|siginfo_t
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
block|{
name|ATF_REQUIRE_EQ
argument_list|(
name|sig
argument_list|,
name|SIGTRAP
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ
argument_list|(
name|info
operator|->
name|si_code
argument_list|,
name|TRAP_TRACE
argument_list|)
expr_stmt|;
operator|++
name|caught
expr_stmt|;
block|}
end_function

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|t_exect_null
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|struct
name|sigaction
name|act
decl_stmt|;
comment|/* 	 * Currently exect(3) is misdesigned -- see PR port-amd64/51700 and it 	 * needs to be redone from scratch. 	 * 	 * This test affects amd64 releng machines causing tests to hang or 	 * fail. As there is little point to test interface that is still not, 	 * designed and implemented and is breaking tests - skip it 	 * unconditionally for all ports. 	 */
comment|/* Prevent static analysis from requiring t_exec_null to be __dead. */
if|if
condition|(
operator|!
name|caught
condition|)
name|atf_tc_skip
argument_list|(
literal|"exect(3) misdesigned and hangs - PR port-amd64/51700"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|sigemptyset
argument_list|(
operator|&
name|act
operator|.
name|sa_mask
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|act
operator|.
name|sa_sigaction
operator|=
name|sigtrap_handler
expr_stmt|;
name|act
operator|.
name|sa_flags
operator|=
name|SA_SIGINFO
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|sigaction
argument_list|(
name|SIGTRAP
argument_list|,
operator|&
name|act
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_ERRNO
argument_list|(
name|EFAULT
argument_list|,
name|exect
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
operator|==
operator|-
literal|1
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ_MSG
argument_list|(
name|caught
argument_list|,
literal|1
argument_list|,
literal|"expected caught (1) != received (%d)"
argument_list|,
operator|(
name|int
operator|)
name|caught
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
name|t_exect_null
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

