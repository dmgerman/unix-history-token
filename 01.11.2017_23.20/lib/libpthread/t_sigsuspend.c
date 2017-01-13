begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_sigsuspend.c,v 1.1 2010/07/16 15:42:53 jmmv Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
literal|"$NetBSD: t_sigsuspend.c,v 1.1 2010/07/16 15:42:53 jmmv Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Regression test for sigsuspend in libpthread when pthread lib isn't  * initialized.  *  * Written by Love  FIXME strand<lha@NetBSD.org>, March 2003.  * Public domain.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_decl_stmt
name|int
name|alarm_set
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|alarm_handler
parameter_list|(
name|int
name|signo
parameter_list|)
block|{
name|alarm_set
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ATF_TC
argument_list|(
name|sigsuspend
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|sigsuspend
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
literal|"Checks sigsuspend in libpthread when pthread lib isn't initialized"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|sigsuspend
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|struct
name|sigaction
name|sa
decl_stmt|;
name|sigset_t
name|set
decl_stmt|;
name|sa
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
name|sa
operator|.
name|sa_handler
operator|=
name|alarm_handler
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|sa
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|sigaction
argument_list|(
name|SIGALRM
argument_list|,
operator|&
name|sa
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|set
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|set
argument_list|,
name|SIGUSR1
argument_list|)
expr_stmt|;
name|sigsuspend
argument_list|(
operator|&
name|set
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|alarm_set
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
name|sigsuspend
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

