begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)erf_.c	5.1	6/7/85  */
end_comment

begin_function
name|float
name|erf_
parameter_list|(
name|x
parameter_list|)
name|float
modifier|*
name|x
decl_stmt|;
block|{
name|double
name|erf
parameter_list|()
function_decl|;
return|return
operator|(
name|erf
argument_list|(
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

