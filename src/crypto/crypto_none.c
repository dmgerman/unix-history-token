begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / Empty template functions for crypto wrapper  * Copyright (c) 2005, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
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
name|md4_vector
parameter_list|(
name|size_t
name|num_elem
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
index|[]
parameter_list|,
specifier|const
name|size_t
modifier|*
name|len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|des_encrypt
parameter_list|(
specifier|const
name|u8
modifier|*
name|clear
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|u8
modifier|*
name|cypher
parameter_list|)
block|{ }
end_function

end_unit

