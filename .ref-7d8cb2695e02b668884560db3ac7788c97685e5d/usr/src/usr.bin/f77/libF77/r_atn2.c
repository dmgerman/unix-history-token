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
literal|"@(#)r_atn2.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function
name|float
name|r_atn2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|float
modifier|*
name|x
decl_stmt|,
decl|*
name|y
decl_stmt|;
end_function

begin_block
block|{
name|double
name|atan2
parameter_list|()
function_decl|;
return|return
operator|(
name|atan2
argument_list|(
operator|*
name|x
argument_list|,
operator|*
name|y
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

