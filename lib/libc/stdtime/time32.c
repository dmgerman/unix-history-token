begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 FreeBSD Inc.  * All rights reserved.  *  * These routines are for converting time_t to fixed-bit representations  * for use in protocols or storage.  When converting time to a larger  * representation of time_t these routines are expected to assume temporal  * locality and use the 50-year rule to properly set the msb bits.  XXX  *  * Redistribution and use under the terms of the COPYRIGHT file at the  * base of the source tree.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/*  * Convert a 32 bit representation of time_t into time_t.  XXX needs to  * implement the 50-year rule to handle post-2038 conversions.  */
end_comment

begin_function
name|time_t
name|time32_to_time
parameter_list|(
name|__int32_t
name|t32
parameter_list|)
block|{
return|return
operator|(
operator|(
name|time_t
operator|)
name|t32
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert time_t to a 32 bit representation.  If time_t is 64 bits we can  * simply chop it down.   The resulting 32 bit representation can be   * converted back to a temporally local 64 bit time_t using time32_to_time.  */
end_comment

begin_function
name|__int32_t
name|time_to_time32
parameter_list|(
name|time_t
name|t
parameter_list|)
block|{
return|return
operator|(
operator|(
name|__int32_t
operator|)
name|t
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert a 64 bit representation of time_t into time_t.  If time_t is  * represented as 32 bits we can simply chop it and not support times  * past 2038.  */
end_comment

begin_function
name|time_t
name|time64_to_time
parameter_list|(
name|__int64_t
name|t64
parameter_list|)
block|{
return|return
operator|(
operator|(
name|time_t
operator|)
name|t64
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert time_t to a 64 bit representation.  If time_t is represented  * as 32 bits we simply sign-extend and do not support times past 2038.  */
end_comment

begin_function
name|__int64_t
name|time_to_time64
parameter_list|(
name|time_t
name|t
parameter_list|)
block|{
return|return
operator|(
operator|(
name|__int64_t
operator|)
name|t
operator|)
return|;
block|}
end_function

end_unit

