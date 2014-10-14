begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_sigaction.c,v 1.2 2012/11/07 16:51:16 pgoyette Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__COPYRIGHT
argument_list|(
literal|"@(#) Copyright (c) 2010\  The NetBSD Foundation, inc. All rights reserved."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_sigaction.c,v 1.2 2012/11/07 16:51:16 pgoyette Exp $"
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
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
file|<atf-c/config.h>
end_include

begin_include
include|#
directive|include
file|"../../../h_macros.h"
end_include

begin_decl_stmt
specifier|static
name|bool
name|handler_called
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|handler
parameter_list|(
name|int
name|signo
parameter_list|)
block|{
name|handler_called
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sa_resethand_child
parameter_list|(
specifier|const
name|int
name|flags
parameter_list|)
block|{
name|struct
name|sigaction
name|sa
decl_stmt|;
name|sa
operator|.
name|sa_flags
operator|=
name|flags
expr_stmt|;
name|sa
operator|.
name|sa_handler
operator|=
operator|&
name|handler
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
name|SIGUSR1
argument_list|,
operator|&
name|sa
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGUSR1
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|handler_called
condition|?
name|EXIT_SUCCESS
else|:
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|wait_and_check_child
parameter_list|(
specifier|const
name|pid_t
name|pid
parameter_list|,
specifier|const
name|char
modifier|*
name|fail_message
parameter_list|)
block|{
name|int
name|status
decl_stmt|;
operator|(
name|void
operator|)
name|waitpid
argument_list|(
name|pid
argument_list|,
operator|&
name|status
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|WIFEXITED
argument_list|(
name|status
argument_list|)
condition|)
name|ATF_CHECK_EQ
argument_list|(
name|EXIT_SUCCESS
argument_list|,
name|WEXITSTATUS
argument_list|(
name|status
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|atf_tc_fail
argument_list|(
literal|"%s; raw exit status was %d"
argument_list|,
name|fail_message
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|catch
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
return|return;
block|}
end_function

begin_expr_stmt
name|ATF_TC
argument_list|(
name|sigaction_basic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|sigaction_basic
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
literal|"Checks for correct I&D cache"
literal|"synchronization after copying out the trampoline code."
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|sigaction_basic
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|static
name|struct
name|sigaction
name|sa
decl_stmt|;
name|sa
operator|.
name|sa_handler
operator|=
name|catch
expr_stmt|;
name|sigaction
argument_list|(
name|SIGUSR1
argument_list|,
operator|&
name|sa
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGUSR1
argument_list|)
expr_stmt|;
name|atf_tc_pass
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|sigaction_noflags
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|sigaction_noflags
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
literal|"Checks programming a signal with "
literal|"sigaction(2) but without any flags"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|sigaction_noflags
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|pid_t
name|pid
init|=
name|fork
argument_list|()
decl_stmt|;
if|if
condition|(
name|pid
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"fork(2) failed"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|pid
operator|==
literal|0
condition|)
name|sa_resethand_child
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|else
name|wait_and_check_child
argument_list|(
name|pid
argument_list|,
literal|"Child process did not exit cleanly;"
literal|" it failed to process the signal"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|sigaction_resethand
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|sigaction_resethand
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
literal|"Checks that SA_RESETHAND works"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|sigaction_resethand
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|pid_t
name|pid
init|=
name|fork
argument_list|()
decl_stmt|;
if|if
condition|(
name|pid
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"fork(2) failed"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|pid
operator|==
literal|0
condition|)
name|sa_resethand_child
argument_list|(
name|SA_RESETHAND
argument_list|)
expr_stmt|;
else|else
block|{
name|wait_and_check_child
argument_list|(
name|pid
argument_list|,
literal|"Child process did not exit cleanly;"
literal|" it either failed to process the signal or SA_RESETHAND"
literal|" is broken"
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
name|sigaction_basic
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|sigaction_noflags
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|sigaction_resethand
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

