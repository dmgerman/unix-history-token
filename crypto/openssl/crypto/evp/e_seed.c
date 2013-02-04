begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/evp/e_seed.c -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2007 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|<openssl/opensslconf.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_SEED
end_ifndef

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<openssl/seed.h>
end_include

begin_include
include|#
directive|include
file|"evp_locl.h"
end_include

begin_function_decl
specifier|static
name|int
name|seed_init_key
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
name|ctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|iv
parameter_list|,
name|int
name|enc
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|SEED_KEY_SCHEDULE
name|ks
decl_stmt|;
block|}
name|EVP_SEED_KEY
typedef|;
end_typedef

begin_macro
name|IMPLEMENT_BLOCK_CIPHER
argument_list|(
argument|seed
argument_list|,
argument|ks
argument_list|,
argument|SEED
argument_list|,
argument|EVP_SEED_KEY
argument_list|,
argument|NID_seed
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|,
literal|128
argument_list|,
literal|0
argument_list|,
argument|seed_init_key
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
end_macro

begin_function
specifier|static
name|int
name|seed_init_key
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
name|ctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|iv
parameter_list|,
name|int
name|enc
parameter_list|)
block|{
name|SEED_set_key
argument_list|(
name|key
argument_list|,
name|ctx
operator|->
name|cipher_data
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

