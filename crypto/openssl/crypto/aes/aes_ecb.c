begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/aes/aes_ecb.c -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2002 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AES_DEBUG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|NDEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<openssl/aes.h>
end_include

begin_include
include|#
directive|include
file|"aes_locl.h"
end_include

begin_function
name|void
name|AES_ecb_encrypt
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|in
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
specifier|const
name|AES_KEY
modifier|*
name|key
parameter_list|,
specifier|const
name|int
name|enc
parameter_list|)
block|{
name|assert
argument_list|(
name|in
operator|&&
name|out
operator|&&
name|key
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|AES_ENCRYPT
operator|==
name|enc
operator|)
operator|||
operator|(
name|AES_DECRYPT
operator|==
name|enc
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|AES_ENCRYPT
operator|==
name|enc
condition|)
name|AES_encrypt
argument_list|(
name|in
argument_list|,
name|out
argument_list|,
name|key
argument_list|)
expr_stmt|;
else|else
name|AES_decrypt
argument_list|(
name|in
argument_list|,
name|out
argument_list|,
name|key
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

