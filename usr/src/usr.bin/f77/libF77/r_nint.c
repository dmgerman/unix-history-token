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
literal|"@(#)r_nint.c	5.4 (Berkeley) %G%"
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
name|r_nint
parameter_list|(
name|x
parameter_list|)
name|float
modifier|*
name|x
decl_stmt|;
block|{
name|double
name|floor
parameter_list|()
function_decl|;
name|flt_retval
operator|=
operator|(
operator|*
name|x
operator|)
operator|>=
literal|0
condition|?
name|floor
argument_list|(
operator|*
name|x
operator|+
literal|.5
argument_list|)
else|:
operator|-
name|floor
argument_list|(
literal|.5
operator|-
operator|*
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
name|flt_retval
operator|)
return|;
block|}
end_function

end_unit

