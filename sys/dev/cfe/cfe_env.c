begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Neelkanth Natu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kenv.h>
end_include

begin_include
include|#
directive|include
file|<dev/cfe/cfe_api.h>
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
name|CFE_ENV_SIZE
end_ifndef

begin_define
define|#
directive|define
name|CFE_ENV_SIZE
value|PAGE_SIZE
end_define

begin_comment
comment|/* default is one page */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|cfe_env_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|char
name|cfe_env_buf
index|[
name|CFE_ENV_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|cfe_env_init
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|idx
decl_stmt|;
name|char
name|name
index|[
name|KENV_MNAMELEN
index|]
decl_stmt|,
name|val
index|[
name|KENV_MVALLEN
index|]
decl_stmt|;
name|init_static_kenv
argument_list|(
name|cfe_env_buf
argument_list|,
name|CFE_ENV_SIZE
argument_list|)
expr_stmt|;
name|idx
operator|=
literal|0
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
name|cfe_enumenv
argument_list|(
name|idx
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
argument_list|,
name|val
argument_list|,
sizeof|sizeof
argument_list|(
name|val
argument_list|)
argument_list|)
operator|!=
literal|0
condition|)
break|break;
if|if
condition|(
name|kern_setenv
argument_list|(
name|name
argument_list|,
name|val
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"No space to store CFE env: \"%s=%s\"\n"
argument_list|,
name|name
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
operator|++
name|idx
expr_stmt|;
block|}
block|}
end_function

end_unit

