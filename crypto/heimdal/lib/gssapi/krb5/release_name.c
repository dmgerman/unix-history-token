begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2003 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"krb5/gsskrb5_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: release_name.c 21128 2007-06-18 20:26:50Z lha $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|OM_uint32
name|_gsskrb5_release_name
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_name_t
modifier|*
name|input_name
parameter_list|)
block|{
name|krb5_context
name|context
decl_stmt|;
name|krb5_principal
name|name
init|=
operator|(
name|krb5_principal
operator|)
operator|*
name|input_name
decl_stmt|;
operator|*
name|minor_status
operator|=
literal|0
expr_stmt|;
name|GSSAPI_KRB5_INIT
argument_list|(
operator|&
name|context
argument_list|)
expr_stmt|;
operator|*
name|input_name
operator|=
name|GSS_C_NO_NAME
expr_stmt|;
name|krb5_free_principal
argument_list|(
name|context
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
name|GSS_S_COMPLETE
return|;
block|}
end_function

end_unit

