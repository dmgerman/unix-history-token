begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_tcsetpgrp.c,v 1.3 2012/03/18 07:14:08 jruoho Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jukka Ruohonen.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_tcsetpgrp.c,v 1.3 2012/03/18 07:14:08 jruoho Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|tcsetpgrp_err
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|tcsetpgrp_err
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
literal|"Test errors from tcsetpgrp(3)"
literal|" (PR lib/41673)"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|tcsetpgrp_err
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|int
name|rv
decl_stmt|,
name|sta
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
if|if
condition|(
name|isatty
argument_list|(
name|STDIN_FILENO
argument_list|)
operator|==
literal|0
condition|)
return|return;
name|pid
operator|=
name|fork
argument_list|()
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|pid
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|pid
operator|==
literal|0
condition|)
block|{
comment|/* 		 * The child process ID doesn't match any active 		 * process group ID, so the following call should 		 * fail with EPERM (and not EINVAL). 		 */
name|errno
operator|=
literal|0
expr_stmt|;
name|rv
operator|=
name|tcsetpgrp
argument_list|(
name|STDIN_FILENO
argument_list|,
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|==
literal|0
operator|||
name|errno
operator|!=
name|EPERM
condition|)
name|_exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
name|EXIT_SUCCESS
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|wait
argument_list|(
operator|&
name|sta
argument_list|)
expr_stmt|;
if|if
condition|(
name|WIFEXITED
argument_list|(
name|sta
argument_list|)
operator|==
literal|0
operator|||
name|WEXITSTATUS
argument_list|(
name|sta
argument_list|)
operator|!=
name|EXIT_SUCCESS
condition|)
name|atf_tc_fail
argument_list|(
literal|"wrong errno"
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
name|tcsetpgrp_err
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

