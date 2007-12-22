begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997, 1998 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"$Id: strerror.c,v 1.10 1999/12/02 16:58:53 joda Exp $"
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
file|<errno.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|int
name|eno
parameter_list|)
block|{
specifier|static
name|char
name|emsg
index|[
literal|1024
index|]
decl_stmt|;
if|if
condition|(
name|eno
operator|<
literal|0
operator|||
name|eno
operator|>=
name|sys_nerr
condition|)
name|snprintf
argument_list|(
name|emsg
argument_list|,
sizeof|sizeof
argument_list|(
name|emsg
argument_list|)
argument_list|,
literal|"Error %d occurred."
argument_list|,
name|eno
argument_list|)
expr_stmt|;
else|else
name|snprintf
argument_list|(
name|emsg
argument_list|,
sizeof|sizeof
argument_list|(
name|emsg
argument_list|)
argument_list|,
literal|"%s"
argument_list|,
name|sys_errlist
index|[
name|eno
index|]
argument_list|)
expr_stmt|;
return|return
name|emsg
return|;
block|}
end_function

end_unit

