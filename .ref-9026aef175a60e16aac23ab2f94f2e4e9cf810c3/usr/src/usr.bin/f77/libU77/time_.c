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
literal|"@(#)time_.c	5.2 (Berkeley) %G%"
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
comment|/*  * return the current time as an integer  *  * calling sequence:  *	integer time  *	i = time()  * where:  *	i will receive the current GMT in seconds.  */
end_comment

begin_function_decl
name|long
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|long
name|time_
parameter_list|()
block|{
return|return
operator|(
name|time
argument_list|(
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

