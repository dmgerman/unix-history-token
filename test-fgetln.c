begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|size_t
name|sz
decl_stmt|;
name|cp
operator|=
name|fgetln
argument_list|(
name|stdin
argument_list|,
operator|&
name|sz
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

