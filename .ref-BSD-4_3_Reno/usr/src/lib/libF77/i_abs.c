begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)i_abs.c	5.1	6/7/85  */
end_comment

begin_function
name|long
name|int
name|i_abs
parameter_list|(
name|x
parameter_list|)
name|long
name|int
modifier|*
name|x
decl_stmt|;
block|{
if|if
condition|(
operator|*
name|x
operator|>=
literal|0
condition|)
return|return
operator|(
operator|*
name|x
operator|)
return|;
return|return
operator|(
operator|-
operator|*
name|x
operator|)
return|;
block|}
end_function

end_unit

