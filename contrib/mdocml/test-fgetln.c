begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|size_t
name|sz
decl_stmt|;
name|fclose
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|!=
name|fgetln
argument_list|(
name|stdin
argument_list|,
operator|&
name|sz
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

