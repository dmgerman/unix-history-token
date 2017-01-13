begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_fork.c,v 1.1 2010/07/16 15:42:53 jmmv Exp $ */
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
literal|"$NetBSD: t_fork.c,v 1.1 2010/07/16 15:42:53 jmmv Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Written by Love Hörnquist Åstrand<lha@NetBSD.org>, March 2003.  * Public domain.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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

begin_decl_stmt
specifier|static
name|pid_t
name|parent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|thread_survived
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
modifier|*
name|print_pid
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|sleep
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|thread_survived
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|parent
operator|!=
name|getpid
argument_list|()
condition|)
block|{
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_expr_stmt
name|ATF_TC
argument_list|(
name|fork
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|fork
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
literal|"Checks that child process doesn't get threads"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|fork
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|pthread_t
name|p
decl_stmt|;
name|pid_t
name|fork_pid
decl_stmt|;
name|parent
operator|=
name|getpid
argument_list|()
expr_stmt|;
name|PTHREAD_REQUIRE
argument_list|(
name|pthread_create
argument_list|(
operator|&
name|p
argument_list|,
name|NULL
argument_list|,
name|print_pid
argument_list|,
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
name|fork_pid
operator|=
name|fork
argument_list|()
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|fork_pid
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|fork_pid
condition|)
block|{
name|int
name|status
decl_stmt|;
name|PTHREAD_REQUIRE
argument_list|(
name|pthread_join
argument_list|(
name|p
argument_list|,
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|thread_survived
argument_list|,
literal|"thread did not survive in parent"
argument_list|)
expr_stmt|;
name|waitpid
argument_list|(
name|fork_pid
argument_list|,
operator|&
name|status
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|WIFEXITED
argument_list|(
name|status
argument_list|)
argument_list|,
literal|"child died wrongly"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ_MSG
argument_list|(
name|WEXITSTATUS
argument_list|(
name|status
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|"thread survived in child"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sleep
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|thread_survived
condition|?
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
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
name|fork
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

