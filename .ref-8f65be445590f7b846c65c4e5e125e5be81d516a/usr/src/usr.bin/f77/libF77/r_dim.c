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
literal|"@(#)r_dim.c	5.4 (Berkeley) %G%"
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
name|float
name|flt_retval
decl_stmt|;
end_decl_stmt

begin_function
name|float
name|r_dim
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|float
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_block
block|{
name|flt_retval
operator|=
operator|*
name|a
operator|>
operator|*
name|b
condition|?
operator|*
name|a
operator|-
operator|*
name|b
else|:
literal|0
expr_stmt|;
return|return
operator|(
name|flt_retval
operator|)
return|;
block|}
end_block

end_unit

