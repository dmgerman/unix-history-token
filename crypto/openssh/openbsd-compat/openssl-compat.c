begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: openssl-compat.c,v 1.8 2009/03/07 11:22:35 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005 Darren Tucker<dtucker@zip.com.au>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER  * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OPENSSL_ENGINE
end_ifdef

begin_include
include|#
directive|include
file|<openssl/engine.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SSH_DONT_OVERLOAD_OPENSSL_FUNCS
end_define

begin_include
include|#
directive|include
file|"openssl-compat.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SSH_OLD_EVP
end_ifdef

begin_function
name|int
name|ssh_EVP_CipherInit
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
name|evp
parameter_list|,
specifier|const
name|EVP_CIPHER
modifier|*
name|type
parameter_list|,
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|char
modifier|*
name|iv
parameter_list|,
name|int
name|enc
parameter_list|)
block|{
name|EVP_CipherInit
argument_list|(
name|evp
argument_list|,
name|type
argument_list|,
name|key
argument_list|,
name|iv
argument_list|,
name|enc
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|ssh_EVP_Cipher
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
name|evp
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|char
modifier|*
name|src
parameter_list|,
name|int
name|len
parameter_list|)
block|{
name|EVP_Cipher
argument_list|(
name|evp
argument_list|,
name|dst
argument_list|,
name|src
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|ssh_EVP_CIPHER_CTX_cleanup
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
name|evp
parameter_list|)
block|{
name|EVP_CIPHER_CTX_cleanup
argument_list|(
name|evp
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

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_EVP_DIGESTUPDATE_VOID
end_ifdef

begin_function
name|int
name|ssh_EVP_DigestUpdate
parameter_list|(
name|EVP_MD_CTX
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|d
parameter_list|,
name|unsigned
name|int
name|cnt
parameter_list|)
block|{
name|EVP_DigestUpdate
argument_list|(
name|ctx
argument_list|,
name|d
argument_list|,
name|cnt
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

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OPENSSL_ENGINE
end_ifdef

begin_function
name|void
name|ssh_SSLeay_add_all_algorithms
parameter_list|(
name|void
parameter_list|)
block|{
name|SSLeay_add_all_algorithms
argument_list|()
expr_stmt|;
comment|/* Enable use of crypto hardware */
name|ENGINE_load_builtin_engines
argument_list|()
expr_stmt|;
name|ENGINE_register_all_complete
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

