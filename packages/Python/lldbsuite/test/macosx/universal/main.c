begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|void
name|call_me
parameter_list|()
block|{
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Hello there!\n"
argument_list|)
expr_stmt|;
comment|// Set break point at this line.
if|if
condition|(
name|argc
operator|==
literal|2
operator|&&
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"keep_waiting"
argument_list|)
operator|==
literal|0
condition|)
while|while
condition|(
literal|1
condition|)
block|{
name|call_me
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

