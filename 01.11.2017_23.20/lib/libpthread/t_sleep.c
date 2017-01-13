begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_sleep.c,v 1.1 2010/07/16 15:42:53 jmmv Exp $ */
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
literal|"$NetBSD: t_sleep.c,v 1.1 2010/07/16 15:42:53 jmmv Exp $"
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
file|<pthread.h>
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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|"h_common.h"
end_include

begin_define
define|#
directive|define
name|LONGTIME
value|2000000000
end_define

begin_function
specifier|static
name|void
modifier|*
name|threadfunc
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|sleep
argument_list|(
name|LONGTIME
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|handler
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
comment|/* 	 * Nothing to do; invoking the handler is enough to interrupt 	 * the sleep. 	 */
block|}
end_function

begin_expr_stmt
name|ATF_TC
argument_list|(
name|sleep1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|sleep1
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
literal|"Checks sleeping past the time when "
literal|"time_t wraps"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|sleep1
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|pthread_t
name|thread
decl_stmt|;
name|struct
name|itimerval
name|it
decl_stmt|;
name|struct
name|sigaction
name|act
decl_stmt|;
name|sigset_t
name|mtsm
decl_stmt|;
name|printf
argument_list|(
literal|"Testing sleeps unreasonably far into the future.\n"
argument_list|)
expr_stmt|;
name|act
operator|.
name|sa_handler
operator|=
name|handler
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|act
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|act
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
name|sigaction
argument_list|(
name|SIGALRM
argument_list|,
operator|&
name|act
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|PTHREAD_REQUIRE
argument_list|(
name|pthread_create
argument_list|(
operator|&
name|thread
argument_list|,
name|NULL
argument_list|,
name|threadfunc
argument_list|,
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
comment|/* make sure the signal is delivered to the child thread */
name|sigemptyset
argument_list|(
operator|&
name|mtsm
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|mtsm
argument_list|,
name|SIGALRM
argument_list|)
expr_stmt|;
name|PTHREAD_REQUIRE
argument_list|(
name|pthread_sigmask
argument_list|(
name|SIG_BLOCK
argument_list|,
operator|&
name|mtsm
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|timerclear
argument_list|(
operator|&
name|it
operator|.
name|it_interval
argument_list|)
expr_stmt|;
name|timerclear
argument_list|(
operator|&
name|it
operator|.
name|it_value
argument_list|)
expr_stmt|;
name|it
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
literal|1
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|it
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|PTHREAD_REQUIRE
argument_list|(
name|pthread_join
argument_list|(
name|thread
argument_list|,
name|NULL
argument_list|)
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
name|sleep1
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

