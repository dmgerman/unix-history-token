begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)logwtmp.c	8.1 (Berkeley) 6/4/93";
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
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
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<utmpx.h>
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_function
name|void
name|ftpd_logwtmp
parameter_list|(
name|char
modifier|*
name|id
parameter_list|,
name|char
modifier|*
name|user
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|)
block|{
name|struct
name|utmpx
name|ut
decl_stmt|;
name|memset
argument_list|(
operator|&
name|ut
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ut
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|user
operator|!=
literal|'\0'
condition|)
block|{
comment|/* Log in. */
name|ut
operator|.
name|ut_type
operator|=
name|USER_PROCESS
expr_stmt|;
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|ut
operator|.
name|ut_user
argument_list|,
name|user
argument_list|,
sizeof|sizeof
argument_list|(
name|ut
operator|.
name|ut_user
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|addr
operator|!=
name|NULL
condition|)
name|realhostname_sa
argument_list|(
name|ut
operator|.
name|ut_host
argument_list|,
sizeof|sizeof
argument_list|(
name|ut
operator|.
name|ut_host
argument_list|)
argument_list|,
name|addr
argument_list|,
name|addr
operator|->
name|sa_len
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Log out. */
name|ut
operator|.
name|ut_type
operator|=
name|DEAD_PROCESS
expr_stmt|;
block|}
name|ut
operator|.
name|ut_pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|ut
operator|.
name|ut_tv
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|ut
operator|.
name|ut_id
argument_list|,
name|id
argument_list|,
sizeof|sizeof
argument_list|(
name|ut
operator|.
name|ut_id
argument_list|)
argument_list|)
expr_stmt|;
name|pututxline
argument_list|(
operator|&
name|ut
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

