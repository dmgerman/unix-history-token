begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)r_cnjg.c	5.1	6/7/85  */
end_comment

begin_include
include|#
directive|include
file|"complex"
end_include

begin_macro
name|r_cnjg
argument_list|(
argument|r
argument_list|,
argument|z
argument_list|)
end_macro

begin_decl_stmt
name|complex
modifier|*
name|r
decl_stmt|,
modifier|*
name|z
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|r
operator|->
name|real
operator|=
name|z
operator|->
name|real
expr_stmt|;
name|r
operator|->
name|imag
operator|=
operator|-
name|z
operator|->
name|imag
expr_stmt|;
block|}
end_block

end_unit

