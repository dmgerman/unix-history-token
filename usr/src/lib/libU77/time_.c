begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)time_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * return the current time as an integer  *  * calling sequence:  *	integer time  *	i = time()  * where:  *	i will receive the current GMT in seconds.  */
end_comment

begin_function_decl
name|long
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|long
name|time_
parameter_list|()
block|{
return|return
operator|(
name|time
argument_list|(
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

