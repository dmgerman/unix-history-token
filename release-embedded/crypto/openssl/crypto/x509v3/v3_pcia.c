begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* v3_pcia.c -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* Contributed to the OpenSSL Project 2004  * by Richard Levitte (richard@levitte.org)  */
end_comment

begin_comment
comment|/* Copyright (c) 2004 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

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

begin_expr_stmt
name|ASN1_SEQUENCE
argument_list|(
name|PROXY_POLICY
argument_list|)
operator|=
block|{
name|ASN1_SIMPLE
argument_list|(
name|PROXY_POLICY
argument_list|,
name|policyLanguage
argument_list|,
name|ASN1_OBJECT
argument_list|)
block|,
name|ASN1_OPT
argument_list|(
argument|PROXY_POLICY
argument_list|,
argument|policy
argument_list|,
argument|ASN1_OCTET_STRING
argument_list|)
block|}
name|ASN1_SEQUENCE_END
argument_list|(
argument|PROXY_POLICY
argument_list|)
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|PROXY_POLICY
argument_list|)
name|ASN1_SEQUENCE
argument_list|(
name|PROXY_CERT_INFO_EXTENSION
argument_list|)
operator|=
block|{
name|ASN1_OPT
argument_list|(
name|PROXY_CERT_INFO_EXTENSION
argument_list|,
name|pcPathLengthConstraint
argument_list|,
name|ASN1_INTEGER
argument_list|)
block|,
name|ASN1_SIMPLE
argument_list|(
argument|PROXY_CERT_INFO_EXTENSION
argument_list|,
argument|proxyPolicy
argument_list|,
argument|PROXY_POLICY
argument_list|)
block|}
name|ASN1_SEQUENCE_END
argument_list|(
argument|PROXY_CERT_INFO_EXTENSION
argument_list|)
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|PROXY_CERT_INFO_EXTENSION
argument_list|)
end_expr_stmt

end_unit

