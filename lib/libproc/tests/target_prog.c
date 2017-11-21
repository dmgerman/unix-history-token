begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Mark Johnston<markj@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
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

begin_decl_stmt
specifier|static
specifier|volatile
name|sig_atomic_t
name|saw
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|usr1
parameter_list|(
name|int
name|sig
name|__unused
parameter_list|)
block|{
name|saw
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|qux
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_expr_stmt
name|__weak_reference
argument_list|(
name|foo
argument_list|,
name|_foo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_expr_stmt
name|__strong_reference
argument_list|(
name|bar
argument_list|,
name|baz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|qux
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_expr_stmt
name|__strong_reference
argument_list|(
name|qux
argument_list|,
name|$qux
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|bar
argument_list|()
expr_stmt|;
comment|/* force the symbol to be emitted */
if|if
condition|(
name|argc
operator|==
literal|1
condition|)
return|return
operator|(
name|EXIT_SUCCESS
operator|)
return|;
if|if
condition|(
name|argc
operator|==
literal|2
operator|&&
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"-s"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|signal
argument_list|(
name|SIGUSR1
argument_list|,
name|usr1
argument_list|)
operator|==
name|SIG_ERR
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"signal"
argument_list|)
expr_stmt|;
if|if
condition|(
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGUSR1
argument_list|)
operator|!=
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"kill"
argument_list|)
expr_stmt|;
return|return
operator|(
name|saw
operator|==
literal|1
condition|?
name|EXIT_SUCCESS
else|:
name|EXIT_FAILURE
operator|)
return|;
block|}
return|return
operator|(
name|EXIT_FAILURE
operator|)
return|;
block|}
end_function

end_unit

