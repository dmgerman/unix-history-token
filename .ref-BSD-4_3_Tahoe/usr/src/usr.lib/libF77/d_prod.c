begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)d_prod.c	5.1	6/7/85  */
end_comment

begin_function
name|double
name|d_prod
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
return|return
operator|(
operator|(
operator|*
name|x
operator|)
operator|*
operator|(
operator|*
name|y
operator|)
operator|)
return|;
block|}
end_block

end_unit

