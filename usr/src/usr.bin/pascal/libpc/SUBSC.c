begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)SUBSC.c	1.6 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_decl_stmt
name|char
name|ESUBSC
index|[]
init|=
literal|"Subscript value of %D is out of range\n"
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|SUBSC
parameter_list|(
name|i
parameter_list|,
name|lower
parameter_list|,
name|upper
parameter_list|)
name|long
name|i
decl_stmt|,
name|lower
decl_stmt|,
name|upper
decl_stmt|;
block|{
if|if
condition|(
name|i
operator|<
name|lower
operator|||
name|i
operator|>
name|upper
condition|)
block|{
name|ERROR
argument_list|(
name|ESUBSC
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|i
return|;
block|}
end_function

end_unit

