begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2000 Damien Miller.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: bsd-arc4random.c,v 1.5 2002/05/08 22:57:18 tim Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ARC4RANDOM
end_ifndef

begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rc4.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_comment
comment|/* Size of key to use */
end_comment

begin_define
define|#
directive|define
name|SEED_SIZE
value|20
end_define

begin_comment
comment|/* Number of bytes to reseed after */
end_comment

begin_define
define|#
directive|define
name|REKEY_BYTES
value|(1<< 24)
end_define

begin_decl_stmt
specifier|static
name|int
name|rc4_ready
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|RC4_KEY
name|rc4
decl_stmt|;
end_decl_stmt

begin_function
name|unsigned
name|int
name|arc4random
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|int
name|r
init|=
literal|0
decl_stmt|;
specifier|static
name|int
name|first_time
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|rc4_ready
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|first_time
condition|)
name|seed_rng
argument_list|()
expr_stmt|;
name|first_time
operator|=
literal|0
expr_stmt|;
name|arc4random_stir
argument_list|()
expr_stmt|;
block|}
name|RC4
argument_list|(
operator|&
name|rc4
argument_list|,
sizeof|sizeof
argument_list|(
name|r
argument_list|)
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|&
name|r
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|&
name|r
argument_list|)
expr_stmt|;
name|rc4_ready
operator|-=
sizeof|sizeof
argument_list|(
name|r
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_function
name|void
name|arc4random_stir
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|char
name|rand_buf
index|[
name|SEED_SIZE
index|]
decl_stmt|;
name|memset
argument_list|(
operator|&
name|rc4
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|rc4
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|RAND_bytes
argument_list|(
name|rand_buf
argument_list|,
sizeof|sizeof
argument_list|(
name|rand_buf
argument_list|)
argument_list|)
condition|)
name|fatal
argument_list|(
literal|"Couldn't obtain random bytes (error %ld)"
argument_list|,
name|ERR_get_error
argument_list|()
argument_list|)
expr_stmt|;
name|RC4_set_key
argument_list|(
operator|&
name|rc4
argument_list|,
sizeof|sizeof
argument_list|(
name|rand_buf
argument_list|)
argument_list|,
name|rand_buf
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|rand_buf
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|rand_buf
argument_list|)
argument_list|)
expr_stmt|;
name|rc4_ready
operator|=
name|REKEY_BYTES
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_ARC4RANDOM */
end_comment

end_unit

