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
literal|"@(#)r_imag.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"complex"
end_include

begin_function
name|float
name|r_imag
parameter_list|(
name|z
parameter_list|)
name|complex
modifier|*
name|z
decl_stmt|;
block|{
return|return
operator|(
name|z
operator|->
name|imag
operator|)
return|;
block|}
end_function

end_unit

