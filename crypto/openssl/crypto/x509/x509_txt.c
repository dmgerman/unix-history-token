begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/x509/x509_txt.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|<openssl/lhash.h>
end_include

begin_include
include|#
directive|include
file|<openssl/buffer.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1.h>
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
specifier|const
name|char
modifier|*
name|X509_verify_cert_error_string
parameter_list|(
name|long
name|n
parameter_list|)
block|{
specifier|static
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
switch|switch
condition|(
operator|(
name|int
operator|)
name|n
condition|)
block|{
case|case
name|X509_V_OK
case|:
return|return
operator|(
literal|"ok"
operator|)
return|;
case|case
name|X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT
case|:
return|return
operator|(
literal|"unable to get issuer certificate"
operator|)
return|;
case|case
name|X509_V_ERR_UNABLE_TO_GET_CRL
case|:
return|return
operator|(
literal|"unable to get certificate CRL"
operator|)
return|;
case|case
name|X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE
case|:
return|return
operator|(
literal|"unable to decrypt certificate's signature"
operator|)
return|;
case|case
name|X509_V_ERR_UNABLE_TO_DECRYPT_CRL_SIGNATURE
case|:
return|return
operator|(
literal|"unable to decrypt CRL's signature"
operator|)
return|;
case|case
name|X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY
case|:
return|return
operator|(
literal|"unable to decode issuer public key"
operator|)
return|;
case|case
name|X509_V_ERR_CERT_SIGNATURE_FAILURE
case|:
return|return
operator|(
literal|"certificate signature failure"
operator|)
return|;
case|case
name|X509_V_ERR_CRL_SIGNATURE_FAILURE
case|:
return|return
operator|(
literal|"CRL signature failure"
operator|)
return|;
case|case
name|X509_V_ERR_CERT_NOT_YET_VALID
case|:
return|return
operator|(
literal|"certificate is not yet valid"
operator|)
return|;
case|case
name|X509_V_ERR_CRL_NOT_YET_VALID
case|:
return|return
operator|(
literal|"CRL is not yet valid"
operator|)
return|;
case|case
name|X509_V_ERR_CERT_HAS_EXPIRED
case|:
return|return
operator|(
literal|"certificate has expired"
operator|)
return|;
case|case
name|X509_V_ERR_CRL_HAS_EXPIRED
case|:
return|return
operator|(
literal|"CRL has expired"
operator|)
return|;
case|case
name|X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD
case|:
return|return
operator|(
literal|"format error in certificate's notBefore field"
operator|)
return|;
case|case
name|X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD
case|:
return|return
operator|(
literal|"format error in certificate's notAfter field"
operator|)
return|;
case|case
name|X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD
case|:
return|return
operator|(
literal|"format error in CRL's lastUpdate field"
operator|)
return|;
case|case
name|X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD
case|:
return|return
operator|(
literal|"format error in CRL's nextUpdate field"
operator|)
return|;
case|case
name|X509_V_ERR_OUT_OF_MEM
case|:
return|return
operator|(
literal|"out of memory"
operator|)
return|;
case|case
name|X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT
case|:
return|return
operator|(
literal|"self signed certificate"
operator|)
return|;
case|case
name|X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN
case|:
return|return
operator|(
literal|"self signed certificate in certificate chain"
operator|)
return|;
case|case
name|X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY
case|:
return|return
operator|(
literal|"unable to get local issuer certificate"
operator|)
return|;
case|case
name|X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE
case|:
return|return
operator|(
literal|"unable to verify the first certificate"
operator|)
return|;
case|case
name|X509_V_ERR_CERT_CHAIN_TOO_LONG
case|:
return|return
operator|(
literal|"certificate chain too long"
operator|)
return|;
case|case
name|X509_V_ERR_CERT_REVOKED
case|:
return|return
operator|(
literal|"certificate revoked"
operator|)
return|;
case|case
name|X509_V_ERR_INVALID_CA
case|:
return|return
operator|(
literal|"invalid CA certificate"
operator|)
return|;
case|case
name|X509_V_ERR_INVALID_NON_CA
case|:
return|return
operator|(
literal|"invalid non-CA certificate (has CA markings)"
operator|)
return|;
case|case
name|X509_V_ERR_PATH_LENGTH_EXCEEDED
case|:
return|return
operator|(
literal|"path length constraint exceeded"
operator|)
return|;
case|case
name|X509_V_ERR_PROXY_PATH_LENGTH_EXCEEDED
case|:
return|return
operator|(
literal|"proxy path length constraint exceeded"
operator|)
return|;
case|case
name|X509_V_ERR_PROXY_CERTIFICATES_NOT_ALLOWED
case|:
return|return
operator|(
literal|"proxy cerificates not allowed, please set the appropriate flag"
operator|)
return|;
case|case
name|X509_V_ERR_INVALID_PURPOSE
case|:
return|return
operator|(
literal|"unsupported certificate purpose"
operator|)
return|;
case|case
name|X509_V_ERR_CERT_UNTRUSTED
case|:
return|return
operator|(
literal|"certificate not trusted"
operator|)
return|;
case|case
name|X509_V_ERR_CERT_REJECTED
case|:
return|return
operator|(
literal|"certificate rejected"
operator|)
return|;
case|case
name|X509_V_ERR_APPLICATION_VERIFICATION
case|:
return|return
operator|(
literal|"application verification failure"
operator|)
return|;
case|case
name|X509_V_ERR_SUBJECT_ISSUER_MISMATCH
case|:
return|return
operator|(
literal|"subject issuer mismatch"
operator|)
return|;
case|case
name|X509_V_ERR_AKID_SKID_MISMATCH
case|:
return|return
operator|(
literal|"authority and subject key identifier mismatch"
operator|)
return|;
case|case
name|X509_V_ERR_AKID_ISSUER_SERIAL_MISMATCH
case|:
return|return
operator|(
literal|"authority and issuer serial number mismatch"
operator|)
return|;
case|case
name|X509_V_ERR_KEYUSAGE_NO_CERTSIGN
case|:
return|return
operator|(
literal|"key usage does not include certificate signing"
operator|)
return|;
case|case
name|X509_V_ERR_UNABLE_TO_GET_CRL_ISSUER
case|:
return|return
operator|(
literal|"unable to get CRL issuer certificate"
operator|)
return|;
case|case
name|X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION
case|:
return|return
operator|(
literal|"unhandled critical extension"
operator|)
return|;
case|case
name|X509_V_ERR_KEYUSAGE_NO_CRL_SIGN
case|:
return|return
operator|(
literal|"key usage does not include CRL signing"
operator|)
return|;
case|case
name|X509_V_ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE
case|:
return|return
operator|(
literal|"key usage does not include digital signature"
operator|)
return|;
case|case
name|X509_V_ERR_UNHANDLED_CRITICAL_CRL_EXTENSION
case|:
return|return
operator|(
literal|"unhandled critical CRL extension"
operator|)
return|;
case|case
name|X509_V_ERR_INVALID_EXTENSION
case|:
return|return
operator|(
literal|"invalid or inconsistent certificate extension"
operator|)
return|;
case|case
name|X509_V_ERR_INVALID_POLICY_EXTENSION
case|:
return|return
operator|(
literal|"invalid or inconsistent certificate policy extension"
operator|)
return|;
case|case
name|X509_V_ERR_NO_EXPLICIT_POLICY
case|:
return|return
operator|(
literal|"no explicit policy"
operator|)
return|;
case|case
name|X509_V_ERR_UNNESTED_RESOURCE
case|:
return|return
operator|(
literal|"RFC 3779 resource not subset of parent's resources"
operator|)
return|;
default|default:
name|BIO_snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
literal|"error number %ld"
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
block|}
end_function

end_unit

