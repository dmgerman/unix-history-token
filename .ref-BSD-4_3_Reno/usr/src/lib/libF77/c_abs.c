begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)c_abs.c	5.1	6/7/85  */
end_comment

begin_include
include|#
directive|include
file|"complex"
end_include

begin_function
name|float
name|c_abs
parameter_list|(
name|z
parameter_list|)
name|complex
modifier|*
name|z
decl_stmt|;
block|{
name|double
name|cabs
parameter_list|()
function_decl|;
return|return
operator|(
name|cabs
argument_list|(
name|z
operator|->
name|real
argument_list|,
name|z
operator|->
name|imag
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

