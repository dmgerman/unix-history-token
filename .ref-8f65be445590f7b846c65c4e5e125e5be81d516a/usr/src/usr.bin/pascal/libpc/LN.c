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
literal|"@(#)LN.c	1.6 (Berkeley) %G%"
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
file|<math.h>
end_include

begin_function
name|double
name|LN
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
operator|<=
literal|0
condition|)
block|{
name|ERROR
argument_list|(
literal|"Non-positive argument of %e to ln\n"
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
return|return
name|log
argument_list|(
name|value
argument_list|)
return|;
block|}
end_function

end_unit

