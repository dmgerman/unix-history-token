begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.proprietary.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)tanh.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/* 	tanh(arg) computes the hyperbolic tangent of its floating 	point argument.  	sinh and cosh are called except for large arguments, which 	would cause overflow improperly. */
end_comment

begin_decl_stmt
name|double
name|sinh
argument_list|()
decl_stmt|,
name|cosh
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|tanh
parameter_list|(
name|arg
parameter_list|)
name|double
name|arg
decl_stmt|;
block|{
name|double
name|sign
decl_stmt|;
name|sign
operator|=
literal|1.
expr_stmt|;
if|if
condition|(
name|arg
operator|<
literal|0.
condition|)
block|{
name|arg
operator|=
operator|-
name|arg
expr_stmt|;
name|sign
operator|=
operator|-
literal|1.
expr_stmt|;
block|}
if|if
condition|(
name|arg
operator|>
literal|21.
condition|)
return|return
operator|(
name|sign
operator|)
return|;
return|return
operator|(
name|sign
operator|*
name|sinh
argument_list|(
name|arg
argument_list|)
operator|/
name|cosh
argument_list|(
name|arg
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

