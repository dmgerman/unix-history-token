begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pow_dd.c	5.1	6/7/85  */
end_comment

begin_function
name|double
name|pow_dd
parameter_list|(
name|ap
parameter_list|,
name|bp
parameter_list|)
name|double
modifier|*
name|ap
decl_stmt|,
decl|*
name|bp
decl_stmt|;
end_function

begin_block
block|{
name|double
name|pow
parameter_list|()
function_decl|;
return|return
operator|(
name|pow
argument_list|(
operator|*
name|ap
argument_list|,
operator|*
name|bp
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

