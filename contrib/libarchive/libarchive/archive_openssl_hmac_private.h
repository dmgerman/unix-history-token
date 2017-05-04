begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_OPENSSL_HMAC_PRIVATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_OPENSSL_HMAC_PRIVATE_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<openssl/hmac.h>
end_include

begin_include
include|#
directive|include
file|<openssl/opensslv.h>
end_include

begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x10100000L
operator|||
name|defined
argument_list|(
name|LIBRESSL_VERSION_NUMBER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* malloc, free */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* memset */
end_comment

begin_function
specifier|static
specifier|inline
name|HMAC_CTX
modifier|*
name|HMAC_CTX_new
parameter_list|(
name|void
parameter_list|)
block|{
name|HMAC_CTX
modifier|*
name|ctx
init|=
operator|(
name|HMAC_CTX
operator|*
operator|)
name|calloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|HMAC_CTX
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|ctx
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|HMAC_CTX_free
parameter_list|(
name|HMAC_CTX
modifier|*
name|ctx
parameter_list|)
block|{
name|HMAC_CTX_cleanup
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|ctx
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|ctx
argument_list|)
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

