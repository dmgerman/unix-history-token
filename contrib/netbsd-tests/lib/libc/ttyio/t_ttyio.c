begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_ttyio.c,v 1.2 2011/04/19 20:07:53 martin Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001, 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Andrew Brown.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
literal|"$NetBSD: t_ttyio.c,v 1.2 2011/04/19 20:07:53 martin Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<err.h>
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
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<util.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_elif

begin_function_decl
name|int
name|openpty
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|,
name|struct
name|winsize
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|where openpty?
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_define
define|#
directive|define
name|REQUIRE_ERRNO
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|ATF_REQUIRE_MSG(x != v, "%s: %s", #x, strerror(errno))
end_define

begin_expr_stmt
name|ATF_TC
argument_list|(
name|ioctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|ioctl
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
literal|"Checks that ioctl calls are restarted "
literal|"properly after being interrupted"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|sigchld
parameter_list|(
name|int
name|nsig
parameter_list|)
block|{
name|REQUIRE_ERRNO
argument_list|(
name|wait
argument_list|(
name|NULL
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|ioctl
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|int
name|m
decl_stmt|,
name|s
decl_stmt|,
name|rc
decl_stmt|;
name|char
name|name
index|[
literal|128
index|]
decl_stmt|,
name|buf
index|[
literal|128
index|]
decl_stmt|;
name|struct
name|termios
name|term
decl_stmt|;
name|struct
name|sigaction
name|sa
decl_stmt|;
comment|/* unbuffer stdout */
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* 	 * Create default termios settings for later use 	 */
name|memset
argument_list|(
operator|&
name|term
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|term
argument_list|)
argument_list|)
expr_stmt|;
name|term
operator|.
name|c_iflag
operator|=
name|TTYDEF_IFLAG
expr_stmt|;
name|term
operator|.
name|c_oflag
operator|=
name|TTYDEF_OFLAG
expr_stmt|;
name|term
operator|.
name|c_cflag
operator|=
name|TTYDEF_CFLAG
expr_stmt|;
name|term
operator|.
name|c_lflag
operator|=
name|TTYDEF_LFLAG
expr_stmt|;
name|cfsetspeed
argument_list|(
operator|&
name|term
argument_list|,
name|TTYDEF_SPEED
argument_list|)
expr_stmt|;
comment|/* get a tty */
name|REQUIRE_ERRNO
argument_list|(
name|openpty
argument_list|(
operator|&
name|m
argument_list|,
operator|&
name|s
argument_list|,
name|name
argument_list|,
operator|&
name|term
argument_list|,
name|NULL
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|fork
argument_list|()
condition|)
block|{
case|case
operator|-
literal|1
case|:
name|atf_tc_fail
argument_list|(
literal|"fork(): %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
case|case
literal|0
case|:
comment|/* wait for parent to get set up */
operator|(
name|void
operator|)
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"child1: exiting\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
default|default:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"parent: spawned child1\n"
argument_list|)
expr_stmt|;
break|break;
block|}
switch|switch
condition|(
name|fork
argument_list|()
condition|)
block|{
case|case
operator|-
literal|1
case|:
name|atf_tc_fail
argument_list|(
literal|"fork(): %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
case|case
literal|0
case|:
comment|/* wait for parent to get upset */
operator|(
name|void
operator|)
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* drain the tty q */
if|if
condition|(
name|read
argument_list|(
name|m
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"read"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"child2: exiting\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
default|default:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"parent: spawned child2\n"
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* set up a restarting signal handler */
operator|(
name|void
operator|)
name|sigemptyset
argument_list|(
operator|&
name|sa
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|sa
operator|.
name|sa_handler
operator|=
name|sigchld
expr_stmt|;
name|sa
operator|.
name|sa_flags
operator|=
name|SA_RESTART
expr_stmt|;
name|REQUIRE_ERRNO
argument_list|(
name|sigaction
argument_list|(
name|SIGCHLD
argument_list|,
operator|&
name|sa
argument_list|,
name|NULL
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* put something in the output q */
name|REQUIRE_ERRNO
argument_list|(
name|write
argument_list|(
name|s
argument_list|,
literal|"Hello world\n"
argument_list|,
literal|12
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* ask for output to drain but don't drain it */
name|rc
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|tcsetattr
argument_list|(
name|s
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|term
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"parent: tcsetattr: %s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|rc
operator|=
literal|1
expr_stmt|;
block|}
comment|/* wait for last child */
name|sa
operator|.
name|sa_handler
operator|=
name|SIG_DFL
expr_stmt|;
name|REQUIRE_ERRNO
argument_list|(
name|sigaction
argument_list|(
name|SIGCHLD
argument_list|,
operator|&
name|sa
argument_list|,
name|NULL
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|wait
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ
argument_list|(
name|rc
argument_list|,
literal|0
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
name|ioctl
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

