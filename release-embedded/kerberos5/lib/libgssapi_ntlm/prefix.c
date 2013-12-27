begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<gssapi/gssapi.h>
end_include

begin_decl_stmt
name|gss_OID_desc
name|__gss_c_nt_user_name_oid_desc
init|=
block|{
literal|10
block|,
operator|(
name|void
operator|*
operator|)
operator|(
literal|"\x2a\x86\x48\x86\xf7\x12"
literal|"\x01\x02\x01\x01"
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID_desc
name|__gss_c_nt_hostbased_service_oid_desc
init|=
block|{
literal|10
block|,
operator|(
name|void
operator|*
operator|)
operator|(
literal|"\x2a\x86\x48\x86\xf7\x12"
literal|"\x01\x02\x01\x04"
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|_gss_name_prefix
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|"_gss_ntlm"
return|;
block|}
end_function

end_unit

