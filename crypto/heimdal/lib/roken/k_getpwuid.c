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
literal|"$Id: k_getpwuid.c,v 1.9 1999/12/02 16:58:47 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|"roken.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SHADOW_H
end_ifdef

begin_include
include|#
directive|include
file|<shadow.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|struct
name|passwd
modifier|*
name|k_getpwuid
parameter_list|(
name|uid_t
name|uid
parameter_list|)
block|{
name|struct
name|passwd
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|getpwuid
argument_list|(
name|uid
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETSPNAM
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_STRUCT_SPWD
argument_list|)
if|if
condition|(
name|p
condition|)
block|{
name|struct
name|spwd
modifier|*
name|spwd
decl_stmt|;
name|spwd
operator|=
name|getspnam
argument_list|(
name|p
operator|->
name|pw_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|spwd
condition|)
name|p
operator|->
name|pw_passwd
operator|=
name|spwd
operator|->
name|sp_pwdp
expr_stmt|;
name|endspent
argument_list|()
expr_stmt|;
block|}
else|#
directive|else
name|endpwent
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|p
return|;
block|}
end_function

end_unit

