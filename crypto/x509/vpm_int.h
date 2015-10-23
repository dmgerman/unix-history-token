begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vpm_int.h */
end_comment

begin_comment
comment|/*  * Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL project  * 2013.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2013 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_comment
comment|/* internal only structure to hold additional X509_VERIFY_PARAM data */
end_comment

begin_struct
struct|struct
name|X509_VERIFY_PARAM_ID_st
block|{
name|STACK_OF
argument_list|(
name|OPENSSL_STRING
argument_list|)
operator|*
name|hosts
expr_stmt|;
comment|/* Set of acceptable names */
name|unsigned
name|int
name|hostflags
decl_stmt|;
comment|/* Flags to control matching features */
name|char
modifier|*
name|peername
decl_stmt|;
comment|/* Matching hostname in peer certificate */
name|char
modifier|*
name|email
decl_stmt|;
comment|/* If not NULL email address to match */
name|size_t
name|emaillen
decl_stmt|;
name|unsigned
name|char
modifier|*
name|ip
decl_stmt|;
comment|/* If not NULL IP address to match */
name|size_t
name|iplen
decl_stmt|;
comment|/* Length of IP address */
block|}
struct|;
end_struct

end_unit

