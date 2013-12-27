begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 1999 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
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
file|"roken.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRNDUP
end_ifndef

begin_function
name|ROKEN_LIB_FUNCTION
name|char
modifier|*
name|ROKEN_LIB_CALL
name|strndup
parameter_list|(
specifier|const
name|char
modifier|*
name|old
parameter_list|,
name|size_t
name|sz
parameter_list|)
block|{
name|size_t
name|len
init|=
name|strnlen
argument_list|(
name|old
argument_list|,
name|sz
argument_list|)
decl_stmt|;
name|char
modifier|*
name|t
init|=
name|malloc
argument_list|(
name|len
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|t
operator|!=
name|NULL
condition|)
block|{
name|memcpy
argument_list|(
name|t
argument_list|,
name|old
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|t
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
return|return
name|t
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRNDUP */
end_comment

end_unit

