begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
specifier|const
modifier|*
name|argv
index|[]
parameter_list|,
name|char
specifier|const
modifier|*
name|envp
index|[]
parameter_list|)
block|{
name|puts
argument_list|(
literal|"stop here"
argument_list|)
expr_stmt|;
comment|// Set breakpoint here
return|return
literal|0
return|;
block|}
end_function

end_unit

