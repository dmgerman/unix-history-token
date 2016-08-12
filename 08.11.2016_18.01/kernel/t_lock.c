begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_lock.c,v 1.1 2009/02/20 21:39:57 jmmv Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__COPYRIGHT
argument_list|(
literal|"@(#) Copyright (c) 2008\  The NetBSD Foundation, inc. All rights reserved."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_lock.c,v 1.1 2009/02/20 21:39:57 jmmv Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<machine/lock.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|"../h_macros.h"
end_include

begin_decl_stmt
name|__cpu_simple_lock_t
name|lk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|handled
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|handler
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
name|handled
operator|=
literal|1
expr_stmt|;
name|__cpu_simple_unlock
argument_list|(
operator|&
name|lk
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ATF_TC
argument_list|(
name|lock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|lock
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
literal|"timeout"
argument_list|,
literal|"3"
argument_list|)
expr_stmt|;
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks __cpu_simple_lock()/__cpu_simple_unlock()"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|lock
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|struct
name|itimerval
name|itv
decl_stmt|;
name|__cpu_simple_lock_init
argument_list|(
operator|&
name|lk
argument_list|)
expr_stmt|;
name|REQUIRE_LIBC
argument_list|(
name|signal
argument_list|(
name|SIGVTALRM
argument_list|,
name|handler
argument_list|)
argument_list|,
name|SIG_ERR
argument_list|)
expr_stmt|;
name|itv
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|itv
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|itv
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
literal|1
expr_stmt|;
name|itv
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|RL
argument_list|(
name|setitimer
argument_list|(
name|ITIMER_VIRTUAL
argument_list|,
operator|&
name|itv
argument_list|,
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
name|__cpu_simple_lock
argument_list|(
operator|&
name|lk
argument_list|)
expr_stmt|;
name|__cpu_simple_lock
argument_list|(
operator|&
name|lk
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|handled
argument_list|)
expr_stmt|;
name|__cpu_simple_unlock
argument_list|(
operator|&
name|lk
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
name|lock
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

