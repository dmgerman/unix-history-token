begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_lwp_ctl.c,v 1.2 2012/03/18 06:20:51 jruoho Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
literal|"$NetBSD: t_lwp_ctl.c,v 1.2 2012/03/18 06:20:51 jruoho Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/lwpctl.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<lwp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|lwpctl_counter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|lwpctl_counter
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
literal|"Checks lwpctl preemption counter"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|lwpctl_counter
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|lwpctl_t
modifier|*
name|lc
decl_stmt|;
name|struct
name|timespec
name|ts
decl_stmt|;
name|int
name|ctr1
decl_stmt|,
name|ctr2
decl_stmt|;
name|ATF_REQUIRE
argument_list|(
name|_lwp_ctl
argument_list|(
name|LWPCTL_FEATURE_PCTR
argument_list|,
operator|&
name|lc
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|/* Ensure that preemption is reported. */
name|ctr1
operator|=
name|lc
operator|->
name|lc_pctr
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"pctr = %d\n"
argument_list|,
name|ctr1
argument_list|)
expr_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
literal|10
operator|*
literal|1000000
expr_stmt|;
name|ts
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|nanosleep
argument_list|(
operator|&
name|ts
argument_list|,
literal|0
argument_list|)
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
name|ctr2
operator|=
name|lc
operator|->
name|lc_pctr
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"pctr = %d\n"
argument_list|,
name|ctr2
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|ctr1
operator|!=
name|ctr2
argument_list|,
literal|"counters match"
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
name|lwpctl_counter
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

