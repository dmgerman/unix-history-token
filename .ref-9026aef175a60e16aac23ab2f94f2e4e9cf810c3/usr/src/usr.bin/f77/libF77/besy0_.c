begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)besy0_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function_decl
name|double
name|y0
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|float
name|besy0_
parameter_list|(
name|x
parameter_list|)
name|float
modifier|*
name|x
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|float
operator|)
name|y0
argument_list|(
operator|(
name|double
operator|)
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

