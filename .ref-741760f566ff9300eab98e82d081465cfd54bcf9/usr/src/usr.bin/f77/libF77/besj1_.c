begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)besj1_.c	5.1	%G%  */
end_comment

begin_function_decl
name|double
name|j1
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|float
name|besj1_
parameter_list|(
name|x
parameter_list|)
name|float
modifier|*
name|x
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|float
operator|)
name|j1
argument_list|(
operator|(
name|double
operator|)
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

