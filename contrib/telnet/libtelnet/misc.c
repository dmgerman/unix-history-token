begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static const char sccsid[] = "@(#)misc.c	8.1 (Berkeley) 6/4/93";
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
file|"misc.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AUTHENTICATION
argument_list|)
end_if

begin_include
include|#
directive|include
file|"auth.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENCRYPTION
end_ifdef

begin_include
include|#
directive|include
file|"encrypt.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENCRYPTION */
end_comment

begin_decl_stmt
name|char
modifier|*
name|RemoteHostName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|LocalHostName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|UserNameRequested
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ConnectedCount
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|auth_encrypt_init
parameter_list|(
name|local
parameter_list|,
name|remote
parameter_list|,
name|name
parameter_list|,
name|server
parameter_list|)
name|char
modifier|*
name|local
decl_stmt|;
name|char
modifier|*
name|remote
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|server
decl_stmt|;
block|{
name|RemoteHostName
operator|=
name|remote
expr_stmt|;
name|LocalHostName
operator|=
name|local
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|AUTHENTICATION
argument_list|)
name|auth_init
argument_list|(
name|name
argument_list|,
name|server
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ENCRYPTION
name|encrypt_init
argument_list|(
name|name
argument_list|,
name|server
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ENCRYPTION */
if|if
condition|(
name|UserNameRequested
condition|)
block|{
name|free
argument_list|(
name|UserNameRequested
argument_list|)
expr_stmt|;
name|UserNameRequested
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|auth_encrypt_user
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
if|if
condition|(
name|UserNameRequested
condition|)
name|free
argument_list|(
name|UserNameRequested
argument_list|)
expr_stmt|;
name|UserNameRequested
operator|=
name|name
condition|?
name|strdup
argument_list|(
name|name
argument_list|)
else|:
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|auth_encrypt_connect
parameter_list|(
name|cnt
parameter_list|)
name|int
name|cnt
decl_stmt|;
block|{ }
end_function

begin_function
name|void
name|printd
parameter_list|(
name|data
parameter_list|,
name|cnt
parameter_list|)
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
name|int
name|cnt
decl_stmt|;
block|{
if|if
condition|(
name|cnt
operator|>
literal|16
condition|)
name|cnt
operator|=
literal|16
expr_stmt|;
while|while
condition|(
name|cnt
operator|--
operator|>
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|" %02x"
argument_list|,
operator|*
name|data
argument_list|)
expr_stmt|;
operator|++
name|data
expr_stmt|;
block|}
block|}
end_function

end_unit

