begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)bzero.c	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This is designed to be small, not fast.  */
end_comment

begin_function
name|void
name|bzero
parameter_list|(
name|s1
parameter_list|,
name|n
parameter_list|)
name|void
modifier|*
name|s1
decl_stmt|;
name|unsigned
name|n
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|t
init|=
name|s1
decl_stmt|;
while|while
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
operator|*
name|t
operator|++
operator|=
literal|0
expr_stmt|;
name|n
operator|--
expr_stmt|;
block|}
block|}
end_function

end_unit

