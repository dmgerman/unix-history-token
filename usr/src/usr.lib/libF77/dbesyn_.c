begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dbesyn_.c	5.1	6/7/85  */
end_comment

begin_function_decl
name|double
name|yn
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|double
name|dbesyn_
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
name|long
modifier|*
name|n
decl_stmt|;
name|double
modifier|*
name|x
decl_stmt|;
block|{
return|return
operator|(
name|yn
argument_list|(
operator|(
name|int
operator|)
operator|*
name|n
argument_list|,
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

