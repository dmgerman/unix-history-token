begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997, 1999 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_define
define|#
directive|define
name|HC_DEPRECATED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|<rand.h>
end_include

begin_undef
undef|#
directive|undef
name|__attribute__
end_undef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|X
parameter_list|)
end_define

begin_function
name|void
name|HC_DEPRECATED
name|DES_rand_data
parameter_list|(
name|void
modifier|*
name|outdata
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|RAND_bytes
argument_list|(
name|outdata
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|HC_DEPRECATED
name|DES_generate_random_block
parameter_list|(
name|DES_cblock
modifier|*
name|block
parameter_list|)
block|{
name|RAND_bytes
argument_list|(
name|block
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|block
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|DES_rand_data_key
value|hc_DES_rand_data_key
end_define

begin_function_decl
name|void
name|HC_DEPRECATED
name|DES_rand_data_key
parameter_list|(
name|DES_cblock
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Generate a random DES key.  */
end_comment

begin_function
name|void
name|HC_DEPRECATED
name|DES_rand_data_key
parameter_list|(
name|DES_cblock
modifier|*
name|key
parameter_list|)
block|{
name|DES_new_random_key
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|HC_DEPRECATED
name|DES_set_sequence_number
parameter_list|(
name|void
modifier|*
name|ll
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|HC_DEPRECATED
name|DES_set_random_generator_seed
parameter_list|(
name|DES_cblock
modifier|*
name|seed
parameter_list|)
block|{
name|RAND_seed
argument_list|(
name|seed
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|seed
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Generate a random des key using a random block, fixup parity and  * skip weak keys.  *  * @param key is set to a random key.  *  * @return 0 on success, non zero on random number generator failure.  *  * @ingroup hcrypto_des  */
end_comment

begin_function
name|int
name|HC_DEPRECATED
name|DES_new_random_key
parameter_list|(
name|DES_cblock
modifier|*
name|key
parameter_list|)
block|{
do|do
block|{
if|if
condition|(
name|RAND_bytes
argument_list|(
name|key
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|key
argument_list|)
argument_list|)
operator|!=
literal|1
condition|)
return|return
literal|1
return|;
name|DES_set_odd_parity
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|DES_is_weak_key
argument_list|(
name|key
argument_list|)
condition|)
do|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Seed the random number generator. Deprecated, use @ref page_rand  *  * @param seed a seed to seed that random number generate with.  *  * @ingroup hcrypto_des  */
end_comment

begin_function
name|void
name|HC_DEPRECATED
name|DES_init_random_number_generator
parameter_list|(
name|DES_cblock
modifier|*
name|seed
parameter_list|)
block|{
name|RAND_seed
argument_list|(
name|seed
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|seed
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Generate a random key, deprecated since it doesn't return an error  * code, use DES_new_random_key().  *  * @param key is set to a random key.  *  * @ingroup hcrypto_des  */
end_comment

begin_function
name|void
name|HC_DEPRECATED
name|DES_random_key
parameter_list|(
name|DES_cblock
modifier|*
name|key
parameter_list|)
block|{
if|if
condition|(
name|DES_new_random_key
argument_list|(
name|key
argument_list|)
condition|)
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

