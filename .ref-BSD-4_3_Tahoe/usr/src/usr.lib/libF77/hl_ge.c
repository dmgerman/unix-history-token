begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)hl_ge.c	5.1	6/7/85  */
end_comment

begin_function
name|short
name|hl_ge
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|la
parameter_list|,
name|lb
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_decl_stmt
name|long
name|int
name|la
decl_stmt|,
name|lb
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|s_cmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|la
argument_list|,
name|lb
argument_list|)
operator|>=
literal|0
operator|)
return|;
block|}
end_block

end_unit

