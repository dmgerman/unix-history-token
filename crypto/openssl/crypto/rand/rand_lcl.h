begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/rand/md_rand.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2000 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_RAND_LCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_RAND_LCL_H
end_define

begin_define
define|#
directive|define
name|ENTROPY_NEEDED
value|20
end_define

begin_comment
comment|/* require 160 bits = 20 bytes of randomness */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_MD5_RAND
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_SHA1_RAND
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_MDC2_RAND
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_MD2_RAND
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_SHA
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_SHA1
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_SHA1_RAND
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|NO_MD5
argument_list|)
end_elif

begin_define
define|#
directive|define
name|USE_MD5_RAND
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|NO_MDC2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_DES
argument_list|)
end_elif

begin_define
define|#
directive|define
name|USE_MDC2_RAND
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|NO_MD2
argument_list|)
end_elif

begin_define
define|#
directive|define
name|USE_MD2_RAND
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|No message digest algorithm available
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_MD5_RAND
argument_list|)
end_if

begin_include
include|#
directive|include
file|<openssl/md5.h>
end_include

begin_define
define|#
directive|define
name|MD_DIGEST_LENGTH
value|MD5_DIGEST_LENGTH
end_define

begin_define
define|#
directive|define
name|MD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MD5(a,b,c)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|USE_SHA1_RAND
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/sha.h>
end_include

begin_define
define|#
directive|define
name|MD_DIGEST_LENGTH
value|SHA_DIGEST_LENGTH
end_define

begin_define
define|#
directive|define
name|MD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|SHA1(a,b,c)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|USE_MDC2_RAND
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/mdc2.h>
end_include

begin_define
define|#
directive|define
name|MD_DIGEST_LENGTH
value|MDC2_DIGEST_LENGTH
end_define

begin_define
define|#
directive|define
name|MD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MDC2(a,b,c)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|USE_MD2_RAND
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/md2.h>
end_include

begin_define
define|#
directive|define
name|MD_DIGEST_LENGTH
value|MD2_DIGEST_LENGTH
end_define

begin_define
define|#
directive|define
name|MD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MD2(a,b,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_MD5_RAND
argument_list|)
end_if

begin_include
include|#
directive|include
file|<openssl/md5.h>
end_include

begin_define
define|#
directive|define
name|MD_DIGEST_LENGTH
value|MD5_DIGEST_LENGTH
end_define

begin_define
define|#
directive|define
name|MD_CTX
value|MD5_CTX
end_define

begin_define
define|#
directive|define
name|MD_Init
parameter_list|(
name|a
parameter_list|)
value|MD5_Init(a)
end_define

begin_define
define|#
directive|define
name|MD_Update
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MD5_Update(a,b,c)
end_define

begin_define
define|#
directive|define
name|MD_Final
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|MD5_Final(a,b)
end_define

begin_define
define|#
directive|define
name|MD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MD5(a,b,c)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|USE_SHA1_RAND
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/sha.h>
end_include

begin_define
define|#
directive|define
name|MD_DIGEST_LENGTH
value|SHA_DIGEST_LENGTH
end_define

begin_define
define|#
directive|define
name|MD_CTX
value|SHA_CTX
end_define

begin_define
define|#
directive|define
name|MD_Init
parameter_list|(
name|a
parameter_list|)
value|SHA1_Init(a)
end_define

begin_define
define|#
directive|define
name|MD_Update
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|SHA1_Update(a,b,c)
end_define

begin_define
define|#
directive|define
name|MD_Final
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|SHA1_Final(a,b)
end_define

begin_define
define|#
directive|define
name|MD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|SHA1(a,b,c)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|USE_MDC2_RAND
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/mdc2.h>
end_include

begin_define
define|#
directive|define
name|MD_DIGEST_LENGTH
value|MDC2_DIGEST_LENGTH
end_define

begin_define
define|#
directive|define
name|MD_CTX
value|MDC2_CTX
end_define

begin_define
define|#
directive|define
name|MD_Init
parameter_list|(
name|a
parameter_list|)
value|MDC2_Init(a)
end_define

begin_define
define|#
directive|define
name|MD_Update
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MDC2_Update(a,b,c)
end_define

begin_define
define|#
directive|define
name|MD_Final
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|MDC2_Final(a,b)
end_define

begin_define
define|#
directive|define
name|MD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MDC2(a,b,c)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|USE_MD2_RAND
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/md2.h>
end_include

begin_define
define|#
directive|define
name|MD_DIGEST_LENGTH
value|MD2_DIGEST_LENGTH
end_define

begin_define
define|#
directive|define
name|MD_CTX
value|MD2_CTX
end_define

begin_define
define|#
directive|define
name|MD_Init
parameter_list|(
name|a
parameter_list|)
value|MD2_Init(a)
end_define

begin_define
define|#
directive|define
name|MD_Update
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MD2_Update(a,b,c)
end_define

begin_define
define|#
directive|define
name|MD_Final
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|MD2_Final(a,b)
end_define

begin_define
define|#
directive|define
name|MD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MD2(a,b,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

