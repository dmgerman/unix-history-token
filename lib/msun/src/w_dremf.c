begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * dremf() wrapper for remainderf().  *  * Written by J.T. Conklin,<jtc@wimsey.com>  * Placed into the Public Domain, 1994.  */
end_comment

begin_include
include|#
directive|include
file|"math.h"
end_include

begin_include
include|#
directive|include
file|"math_private.h"
end_include

begin_function
name|float
name|dremf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
block|{
return|return
name|remainderf
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

end_unit

