begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"$Id: hstrerror.c,v 1.22 1999/12/02 16:58:46 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_HSTRERROR
end_ifndef

begin_include
include|#
directive|include
file|"roken.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDB_H
end_ifdef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|SunOS
argument_list|)
operator|&&
operator|(
name|SunOS
operator|>=
literal|50
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|hstrerror
value|broken_proto
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_undef
undef|#
directive|undef
name|hstrerror
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_H_ERRNO
end_ifndef

begin_decl_stmt
name|int
name|h_errno
init|=
operator|-
literal|17
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some magic number */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|HAVE_H_ERRLIST
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_H_NERR
argument_list|)
operator|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|h_errlist
index|[]
init|=
block|{
literal|"Resolver Error 0 (no error)"
block|,
literal|"Unknown host"
block|,
comment|/* 1 HOST_NOT_FOUND */
literal|"Host name lookup failure"
block|,
comment|/* 2 TRY_AGAIN */
literal|"Unknown server error"
block|,
comment|/* 3 NO_RECOVERY */
literal|"No address associated with name"
block|,
comment|/* 4 NO_ADDRESS */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|h_nerr
init|=
block|{
sizeof|sizeof
name|h_errlist
operator|/
sizeof|sizeof
name|h_errlist
index|[
literal|0
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_H_ERRLIST_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|h_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|h_nerr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|const
name|char
modifier|*
name|hstrerror
parameter_list|(
name|int
name|herr
parameter_list|)
block|{
if|if
condition|(
literal|0
operator|<=
name|herr
operator|&&
name|herr
operator|<
name|h_nerr
condition|)
return|return
name|h_errlist
index|[
name|herr
index|]
return|;
elseif|else
if|if
condition|(
name|herr
operator|==
operator|-
literal|17
condition|)
return|return
literal|"unknown error"
return|;
else|else
return|return
literal|"Error number out of range (hstrerror)"
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

