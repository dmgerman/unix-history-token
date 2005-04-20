begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nsseq.c */
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1t.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

begin_include
include|#
directive|include
file|<openssl/objects.h>
end_include

begin_function
specifier|static
name|int
name|nsseq_cb
parameter_list|(
name|int
name|operation
parameter_list|,
name|ASN1_VALUE
modifier|*
modifier|*
name|pval
parameter_list|,
specifier|const
name|ASN1_ITEM
modifier|*
name|it
parameter_list|)
block|{
if|if
condition|(
name|operation
operator|==
name|ASN1_OP_NEW_POST
condition|)
block|{
name|NETSCAPE_CERT_SEQUENCE
modifier|*
name|nsseq
decl_stmt|;
name|nsseq
operator|=
operator|(
name|NETSCAPE_CERT_SEQUENCE
operator|*
operator|)
operator|*
name|pval
expr_stmt|;
name|nsseq
operator|->
name|type
operator|=
name|OBJ_nid2obj
argument_list|(
name|NID_netscape_cert_sequence
argument_list|)
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Netscape certificate sequence structure */
end_comment

begin_expr_stmt
name|ASN1_SEQUENCE_cb
argument_list|(
name|NETSCAPE_CERT_SEQUENCE
argument_list|,
name|nsseq_cb
argument_list|)
operator|=
block|{
name|ASN1_SIMPLE
argument_list|(
name|NETSCAPE_CERT_SEQUENCE
argument_list|,
name|type
argument_list|,
name|ASN1_OBJECT
argument_list|)
block|,
name|ASN1_EXP_SEQUENCE_OF_OPT
argument_list|(
argument|NETSCAPE_CERT_SEQUENCE
argument_list|,
argument|certs
argument_list|,
argument|X509
argument_list|,
literal|0
argument_list|)
block|}
name|ASN1_SEQUENCE_END_cb
argument_list|(
argument|NETSCAPE_CERT_SEQUENCE
argument_list|,
argument|NETSCAPE_CERT_SEQUENCE
argument_list|)
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|NETSCAPE_CERT_SEQUENCE
argument_list|)
end_expr_stmt

end_unit

