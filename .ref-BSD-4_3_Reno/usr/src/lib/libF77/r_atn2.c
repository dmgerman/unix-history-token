begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)r_atn2.c	5.2	7/8/85  */
end_comment

begin_function
name|float
name|r_atn2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|float
modifier|*
name|x
decl_stmt|,
decl|*
name|y
decl_stmt|;
end_function

begin_block
block|{
name|double
name|atan2
parameter_list|()
function_decl|;
return|return
operator|(
name|atan2
argument_list|(
operator|*
name|x
argument_list|,
operator|*
name|y
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

