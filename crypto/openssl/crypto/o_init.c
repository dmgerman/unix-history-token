begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* o_init.c */
end_comment

begin_comment
comment|/* Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL  * project.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2011 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  */
end_comment

begin_include
include|#
directive|include
file|<e_os.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_FIPS
end_ifdef

begin_include
include|#
directive|include
file|<openssl/fips.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Perform any essential OpenSSL initialization operations.  * Currently only sets FIPS callbacks  */
end_comment

begin_function
name|void
name|OPENSSL_init
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|done
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|done
condition|)
return|return;
name|done
operator|=
literal|1
expr_stmt|;
ifdef|#
directive|ifdef
name|OPENSSL_FIPS
name|FIPS_set_locking_callbacks
argument_list|(
name|CRYPTO_lock
argument_list|,
name|CRYPTO_add_lock
argument_list|)
expr_stmt|;
name|FIPS_set_error_callbacks
argument_list|(
name|ERR_put_error
argument_list|,
name|ERR_add_error_vdata
argument_list|)
expr_stmt|;
name|FIPS_set_malloc_callbacks
argument_list|(
name|CRYPTO_malloc
argument_list|,
name|CRYPTO_free
argument_list|)
expr_stmt|;
name|RAND_init_fips
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
literal|0
block|fprintf(stderr, "Called OPENSSL_init\n");
endif|#
directive|endif
block|}
end_function

end_unit

