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
literal|"@(#)ROUND.c	1.4 (Berkeley) %G%"
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
name|long
name|ROUND
parameter_list|(
name|value
parameter_list|)
name|double
name|value
decl_stmt|;
block|{
if|if
condition|(
name|value
operator|>=
literal|0.0
condition|)
return|return
call|(
name|long
call|)
argument_list|(
name|value
operator|+
literal|0.5
argument_list|)
return|;
return|return
call|(
name|long
call|)
argument_list|(
name|value
operator|-
literal|0.5
argument_list|)
return|;
block|}
end_function

end_unit

