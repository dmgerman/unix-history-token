begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * FIPS 186-2 PRF for Microsoft CryptoAPI  * Copyright (c) 2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
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
file|"crypto.h"
end_include

begin_function
name|int
name|fips186_2_prf
parameter_list|(
specifier|const
name|u8
modifier|*
name|seed
parameter_list|,
name|size_t
name|seed_len
parameter_list|,
name|u8
modifier|*
name|x
parameter_list|,
name|size_t
name|xlen
parameter_list|)
block|{
comment|/* FIX: how to do this with CryptoAPI? */
return|return
operator|-
literal|1
return|;
block|}
end_function

end_unit

