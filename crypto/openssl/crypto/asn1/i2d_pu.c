begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/asn1/i2d_pu.c */
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
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/objects.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_RSA
end_ifndef

begin_include
include|#
directive|include
file|<openssl/rsa.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_DSA
end_ifndef

begin_include
include|#
directive|include
file|<openssl/dsa.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|i2d_PublicKey
parameter_list|(
name|EVP_PKEY
modifier|*
name|a
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|pp
parameter_list|)
block|{
switch|switch
condition|(
name|a
operator|->
name|type
condition|)
block|{
ifndef|#
directive|ifndef
name|OPENSSL_NO_RSA
case|case
name|EVP_PKEY_RSA
case|:
return|return
operator|(
name|i2d_RSAPublicKey
argument_list|(
name|a
operator|->
name|pkey
operator|.
name|rsa
argument_list|,
name|pp
argument_list|)
operator|)
return|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OPENSSL_NO_DSA
case|case
name|EVP_PKEY_DSA
case|:
return|return
operator|(
name|i2d_DSAPublicKey
argument_list|(
name|a
operator|->
name|pkey
operator|.
name|dsa
argument_list|,
name|pp
argument_list|)
operator|)
return|;
endif|#
directive|endif
default|default:
name|ASN1err
argument_list|(
name|ASN1_F_I2D_PUBLICKEY
argument_list|,
name|ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
end_function

end_unit

