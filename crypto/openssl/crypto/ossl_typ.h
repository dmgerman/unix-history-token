begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2001 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_OPENSSL_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_OPENSSL_TYPES_H
end_define

begin_include
include|#
directive|include
file|<openssl/e_os2.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NO_ASN1_TYPEDEFS
end_ifdef

begin_define
define|#
directive|define
name|ASN1_INTEGER
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_ENUMERATED
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_BIT_STRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_OCTET_STRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_PRINTABLESTRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_T61STRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_IA5STRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_UTCTIME
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_GENERALIZEDTIME
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_TIME
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_GENERALSTRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_UNIVERSALSTRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_BMPSTRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_VISIBLESTRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_UTF8STRING
value|ASN1_STRING
end_define

begin_define
define|#
directive|define
name|ASN1_BOOLEAN
value|int
end_define

begin_define
define|#
directive|define
name|ASN1_NULL
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_INTEGER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_ENUMERATED
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_BIT_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_OCTET_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_PRINTABLESTRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_T61STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_IA5STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_GENERALSTRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_UNIVERSALSTRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_BMPSTRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_UTCTIME
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_TIME
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_GENERALIZEDTIME
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_VISIBLESTRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|asn1_string_st
name|ASN1_UTF8STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ASN1_BOOLEAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ASN1_NULL
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_SYS_WIN32
end_ifdef

begin_undef
undef|#
directive|undef
name|X509_NAME
end_undef

begin_undef
undef|#
directive|undef
name|PKCS7_ISSUER_AND_SERIAL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|evp_cipher_st
name|EVP_CIPHER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|evp_cipher_ctx_st
name|EVP_CIPHER_CTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|env_md_st
name|EVP_MD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|env_md_ctx_st
name|EVP_MD_CTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|evp_pkey_st
name|EVP_PKEY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|x509_st
name|X509
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|X509_algor_st
name|X509_ALGOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|X509_crl_st
name|X509_CRL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|X509_name_st
name|X509_NAME
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|x509_store_st
name|X509_STORE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|x509_store_ctx_st
name|X509_STORE_CTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|engine_st
name|ENGINE
typedef|;
end_typedef

begin_comment
comment|/* If placed in pkcs12.h, we end up with a circular depency with pkcs7.h */
end_comment

begin_define
define|#
directive|define
name|DECLARE_PKCS12_STACK_OF
parameter_list|(
name|type
parameter_list|)
end_define

begin_comment
comment|/* Nothing */
end_comment

begin_define
define|#
directive|define
name|IMPLEMENT_PKCS12_STACK_OF
parameter_list|(
name|type
parameter_list|)
end_define

begin_comment
comment|/* Nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* def HEADER_OPENSSL_TYPES_H */
end_comment

end_unit

