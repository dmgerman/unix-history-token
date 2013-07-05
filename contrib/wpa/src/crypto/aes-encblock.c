begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * AES encrypt_block  *  * Copyright (c) 2003-2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"aes.h"
end_include

begin_include
include|#
directive|include
file|"aes_wrap.h"
end_include

begin_comment
comment|/**  * aes_128_encrypt_block - Perform one AES 128-bit block operation  * @key: Key for AES  * @in: Input data (16 bytes)  * @out: Output of the AES block operation (16 bytes)  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function
name|int
name|aes_128_encrypt_block
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|in
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|)
block|{
name|void
modifier|*
name|ctx
decl_stmt|;
name|ctx
operator|=
name|aes_encrypt_init
argument_list|(
name|key
argument_list|,
literal|16
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctx
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
name|aes_encrypt
argument_list|(
name|ctx
argument_list|,
name|in
argument_list|,
name|out
argument_list|)
expr_stmt|;
name|aes_encrypt_deinit
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

