begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|var
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%p is %d\n"
argument_list|,
operator|&
name|var
argument_list|,
name|var
argument_list|)
expr_stmt|;
comment|// break on this line
return|return
operator|++
name|var
return|;
block|}
end_function

end_unit

