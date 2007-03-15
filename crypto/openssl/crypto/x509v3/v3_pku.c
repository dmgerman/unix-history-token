begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* v3_pku.c */
end_comment

begin_comment
comment|/* Written by Dr Stephen N Henson (shenson@bigfoot.com) for the OpenSSL  * project 1999.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|<openssl/asn1.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1t.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509v3.h>
end_include

begin_function_decl
specifier|static
name|int
name|i2r_PKEY_USAGE_PERIOD
parameter_list|(
name|X509V3_EXT_METHOD
modifier|*
name|method
parameter_list|,
name|PKEY_USAGE_PERIOD
modifier|*
name|usage
parameter_list|,
name|BIO
modifier|*
name|out
parameter_list|,
name|int
name|indent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* static PKEY_USAGE_PERIOD *v2i_PKEY_USAGE_PERIOD(X509V3_EXT_METHOD *method, X509V3_CTX *ctx, STACK_OF(CONF_VALUE) *values); */
end_comment

begin_decl_stmt
specifier|const
name|X509V3_EXT_METHOD
name|v3_pkey_usage_period
init|=
block|{
name|NID_private_key_usage_period
block|,
literal|0
block|,
name|ASN1_ITEM_ref
argument_list|(
name|PKEY_USAGE_PERIOD
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|(
name|X509V3_EXT_I2R
operator|)
name|i2r_PKEY_USAGE_PERIOD
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ASN1_SEQUENCE
argument_list|(
name|PKEY_USAGE_PERIOD
argument_list|)
operator|=
block|{
name|ASN1_IMP_OPT
argument_list|(
name|PKEY_USAGE_PERIOD
argument_list|,
name|notBefore
argument_list|,
name|ASN1_GENERALIZEDTIME
argument_list|,
literal|0
argument_list|)
block|,
name|ASN1_IMP_OPT
argument_list|(
argument|PKEY_USAGE_PERIOD
argument_list|,
argument|notAfter
argument_list|,
argument|ASN1_GENERALIZEDTIME
argument_list|,
literal|1
argument_list|)
block|}
name|ASN1_SEQUENCE_END
argument_list|(
argument|PKEY_USAGE_PERIOD
argument_list|)
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|PKEY_USAGE_PERIOD
argument_list|)
specifier|static
name|int
name|i2r_PKEY_USAGE_PERIOD
argument_list|(
argument|X509V3_EXT_METHOD *method
argument_list|,
argument|PKEY_USAGE_PERIOD *usage
argument_list|,
argument|BIO *out
argument_list|,
argument|int indent
argument_list|)
block|{
name|BIO_printf
argument_list|(
name|out
argument_list|,
literal|"%*s"
argument_list|,
name|indent
argument_list|,
literal|""
argument_list|)
block|;
if|if
condition|(
name|usage
operator|->
name|notBefore
condition|)
block|{
name|BIO_write
argument_list|(
name|out
argument_list|,
literal|"Not Before: "
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|ASN1_GENERALIZEDTIME_print
argument_list|(
name|out
argument_list|,
name|usage
operator|->
name|notBefore
argument_list|)
expr_stmt|;
if|if
condition|(
name|usage
operator|->
name|notAfter
condition|)
name|BIO_write
argument_list|(
name|out
argument_list|,
literal|", "
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|usage
operator|->
name|notAfter
condition|)
block|{
name|BIO_write
argument_list|(
name|out
argument_list|,
literal|"Not After: "
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|ASN1_GENERALIZEDTIME_print
argument_list|(
name|out
argument_list|,
name|usage
operator|->
name|notAfter
argument_list|)
expr_stmt|;
block|}
end_if

begin_return
return|return
literal|1
return|;
end_return

begin_comment
unit|}
comment|/* static PKEY_USAGE_PERIOD *v2i_PKEY_USAGE_PERIOD(method, ctx, values) X509V3_EXT_METHOD *method; X509V3_CTX *ctx; STACK_OF(CONF_VALUE) *values; { return NULL; } */
end_comment

end_unit

