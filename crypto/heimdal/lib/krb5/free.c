begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"krb5_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: free.c,v 1.5 1999/12/02 17:05:09 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|krb5_error_code
name|krb5_free_kdc_rep
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|krb5_kdc_rep
modifier|*
name|rep
parameter_list|)
block|{
name|free_KDC_REP
argument_list|(
operator|&
name|rep
operator|->
name|kdc_rep
argument_list|)
expr_stmt|;
name|free_EncTGSRepPart
argument_list|(
operator|&
name|rep
operator|->
name|enc_part
argument_list|)
expr_stmt|;
name|free_KRB_ERROR
argument_list|(
operator|&
name|rep
operator|->
name|error
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|krb5_error_code
name|krb5_xfree
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

