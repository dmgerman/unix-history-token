begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998, 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"kadm_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: check_password.c,v 1.3 1999/12/02 16:58:39 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* This is a client side password check. Should perhaps be merged with    kadmind version that lives in pw_check.c */
end_comment

begin_function
name|int
name|kadm_check_pw
parameter_list|(
specifier|const
name|char
modifier|*
name|password
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|t
decl_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|password
argument_list|)
operator|==
literal|0
condition|)
return|return
name|KADM_PASS_Q_NULL
return|;
if|if
condition|(
name|strlen
argument_list|(
name|password
argument_list|)
operator|<
name|MIN_KPW_LEN
condition|)
return|return
name|KADM_PASS_Q_TOOSHORT
return|;
comment|/* Don't allow all lower case passwords regardless of length */
for|for
control|(
name|t
operator|=
name|password
init|;
operator|*
name|t
operator|&&
name|islower
argument_list|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|t
argument_list|)
condition|;
name|t
operator|++
control|)
empty_stmt|;
if|if
condition|(
operator|*
name|t
operator|==
literal|'\0'
condition|)
return|return
name|KADM_PASS_Q_CLASS
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

