begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)h_mod.c	5.1	6/7/85  */
end_comment

begin_function
name|short
name|h_mod
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|short
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_block
block|{
return|return
operator|(
operator|*
name|a
operator|%
operator|*
name|b
operator|)
return|;
block|}
end_block

end_unit

