begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: gai_strerror.c,v 1.2 1999/12/03 04:10:06 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"roken.h"
end_include

begin_struct
specifier|static
struct|struct
name|gai_error
block|{
name|int
name|code
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
block|}
name|errors
index|[]
init|=
block|{
block|{
name|EAI_NOERROR
block|,
literal|"no error"
block|}
block|,
block|{
name|EAI_ADDRFAMILY
block|,
literal|"address family for nodename not supported"
block|}
block|,
block|{
name|EAI_AGAIN
block|,
literal|"temporary failure in name resolution"
block|}
block|,
block|{
name|EAI_BADFLAGS
block|,
literal|"invalid value for ai_flags"
block|}
block|,
block|{
name|EAI_FAIL
block|,
literal|"non-recoverable failure in name resolution"
block|}
block|,
block|{
name|EAI_FAMILY
block|,
literal|"ai_family not supported"
block|}
block|,
block|{
name|EAI_MEMORY
block|,
literal|"memory allocation failure"
block|}
block|,
block|{
name|EAI_NODATA
block|,
literal|"no address associated with nodename"
block|}
block|,
block|{
name|EAI_NONAME
block|,
literal|"nodename nor servname provided, or not known"
block|}
block|,
block|{
name|EAI_SERVICE
block|,
literal|"servname not supported for ai_socktype"
block|}
block|,
block|{
name|EAI_SOCKTYPE
block|,
literal|"ai_socktype not supported"
block|}
block|,
block|{
name|EAI_SYSTEM
block|,
literal|"system error returned in errno"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|, }
struct|;
end_struct

begin_comment
comment|/*  *  */
end_comment

begin_function
name|char
modifier|*
name|gai_strerror
parameter_list|(
name|int
name|ecode
parameter_list|)
block|{
name|struct
name|gai_error
modifier|*
name|g
decl_stmt|;
for|for
control|(
name|g
operator|=
name|errors
init|;
name|g
operator|->
name|str
operator|!=
name|NULL
condition|;
operator|++
name|g
control|)
if|if
condition|(
name|g
operator|->
name|code
operator|==
name|ecode
condition|)
return|return
name|g
operator|->
name|str
return|;
return|return
literal|"unknown error code in gai_strerror"
return|;
block|}
end_function

end_unit

