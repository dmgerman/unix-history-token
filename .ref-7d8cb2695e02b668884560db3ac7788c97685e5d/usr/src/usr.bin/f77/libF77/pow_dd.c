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
literal|"@(#)pow_dd.c	5.2 (Berkeley) %G%"
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
name|double
name|pow_dd
parameter_list|(
name|ap
parameter_list|,
name|bp
parameter_list|)
name|double
modifier|*
name|ap
decl_stmt|,
decl|*
name|bp
decl_stmt|;
end_function

begin_block
block|{
name|double
name|pow
parameter_list|()
function_decl|;
return|return
operator|(
name|pow
argument_list|(
operator|*
name|ap
argument_list|,
operator|*
name|bp
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

