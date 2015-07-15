begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Crypto-quality random number functions  *  * Author: Harlan Stenn, 2014  *  * This file is Copyright (c) 2014 by Network Time Foundation.  * BSD terms apply: see the file COPYRIGHT in the distribution root for details.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<l_stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ntp_random.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OPENSSL_CRYPTO_RAND
end_ifdef

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include

begin_decl_stmt
name|int
name|crypto_rand_init
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ARC4RANDOM_BUF
end_ifndef

begin_function_decl
specifier|static
name|void
name|arc4random_buf
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evutil_secure_rng_get_bytes
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|arc4random_buf
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
block|{
name|evutil_secure_rng_get_bytes
argument_list|(
name|buf
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
return|return;
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

begin_comment
comment|/*  * As of late 2014, here's how we plan to provide cryptographic-quality  * random numbers:  *   * - If we are building with OpenSSL, use RAND_poll() and RAND_bytes().  * - Otherwise, use arc4random().  *   * Use of arc4random() can be forced using configure --disable-openssl-random  *  * We can count on arc4random existing, thru the OS or thru libevent.  * The quality of arc4random depends on the implementor.  *   * RAND_poll() doesn't show up until XXX.  If it's not present, we  * need to either provide our own or use arc4random().  */
end_comment

begin_comment
comment|/*  * ntp_crypto_srandom:  *  * Initialize the random number generator, if needed by the underlying  * crypto random number generation mechanism.  */
end_comment

begin_function
name|void
name|ntp_crypto_srandom
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_OPENSSL_CRYPTO_RAND
if|if
condition|(
operator|!
name|crypto_rand_init
condition|)
block|{
name|RAND_poll
argument_list|()
expr_stmt|;
name|crypto_rand_init
operator|=
literal|1
expr_stmt|;
block|}
else|#
directive|else
comment|/* No initialization needed for arc4random() */
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * ntp_crypto_random_buf:  *  * Returns 0 on success, -1 on error.  */
end_comment

begin_function
name|int
name|ntp_crypto_random_buf
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_OPENSSL_CRYPTO_RAND
name|int
name|rc
decl_stmt|;
name|rc
operator|=
name|RAND_bytes
argument_list|(
name|buf
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
if|if
condition|(
literal|1
operator|!=
name|rc
condition|)
block|{
name|unsigned
name|long
name|err
decl_stmt|;
name|char
modifier|*
name|err_str
decl_stmt|;
name|err
operator|=
name|ERR_get_error
argument_list|()
expr_stmt|;
name|err_str
operator|=
name|ERR_error_string
argument_list|(
name|err
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* XXX: Log the error */
operator|(
name|void
operator|)
operator|&
name|err_str
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
return|return
literal|0
return|;
else|#
directive|else
name|arc4random_buf
argument_list|(
name|buf
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function

end_unit

