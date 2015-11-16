begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ssl/d1_meth.h */
end_comment

begin_comment
comment|/*  * DTLS implementation written by Nagendra Modadugu  * (nagendra@cs.stanford.edu) for the OpenSSL project 2005.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1999-2005 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/objects.h>
end_include

begin_include
include|#
directive|include
file|"ssl_locl.h"
end_include

begin_function_decl
specifier|static
specifier|const
name|SSL_METHOD
modifier|*
name|dtls1_get_method
parameter_list|(
name|int
name|ver
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|const
name|SSL_METHOD
modifier|*
name|dtls1_get_method
parameter_list|(
name|int
name|ver
parameter_list|)
block|{
if|if
condition|(
name|ver
operator|==
name|DTLS1_VERSION
condition|)
return|return
operator|(
name|DTLSv1_method
argument_list|()
operator|)
return|;
elseif|else
if|if
condition|(
name|ver
operator|==
name|DTLS1_2_VERSION
condition|)
return|return
operator|(
name|DTLSv1_2_method
argument_list|()
operator|)
return|;
else|else
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_macro
name|IMPLEMENT_dtls1_meth_func
argument_list|(
argument|DTLS1_VERSION
argument_list|,
argument|DTLSv1_method
argument_list|,
argument|dtls1_accept
argument_list|,
argument|dtls1_connect
argument_list|,
argument|dtls1_get_method
argument_list|,
argument|DTLSv1_enc_data
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_dtls1_meth_func
argument_list|(
argument|DTLS1_2_VERSION
argument_list|,
argument|DTLSv1_2_method
argument_list|,
argument|dtls1_accept
argument_list|,
argument|dtls1_connect
argument_list|,
argument|dtls1_get_method
argument_list|,
argument|DTLSv1_2_enc_data
argument_list|)
end_macro

begin_macro
name|IMPLEMENT_dtls1_meth_func
argument_list|(
argument|DTLS_ANY_VERSION
argument_list|,
argument|DTLS_method
argument_list|,
argument|dtls1_accept
argument_list|,
argument|dtls1_connect
argument_list|,
argument|dtls1_get_method
argument_list|,
argument|DTLSv1_2_enc_data
argument_list|)
end_macro

end_unit

