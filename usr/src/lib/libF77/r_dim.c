begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)r_dim.c	5.3	7/9/85  */
end_comment

begin_decl_stmt
name|float
name|flt_retval
decl_stmt|;
end_decl_stmt

begin_function
name|float
name|r_dim
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|float
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_block
block|{
name|flt_retval
operator|=
operator|*
name|a
operator|>
operator|*
name|b
condition|?
operator|*
name|a
operator|-
operator|*
name|b
else|:
literal|0
expr_stmt|;
return|return
operator|(
name|flt_retval
operator|)
return|;
block|}
end_block

end_unit

