begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)d_dprod.c	5.1	8/9/85  */
end_comment

begin_function
name|double
name|d_dprod
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|double
modifier|*
name|x
decl_stmt|,
decl|*
name|y
decl_stmt|;
end_function

begin_block
block|{
comment|/* dprod with -r8 flag - all in double precision */
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

