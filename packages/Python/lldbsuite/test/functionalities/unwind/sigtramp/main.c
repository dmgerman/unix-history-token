begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
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
name|void
name|handler
parameter_list|(
name|int
name|in
parameter_list|)
block|{
name|puts
argument_list|(
literal|"in handler routine"
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_function
name|void
name|foo
parameter_list|()
block|{
name|puts
argument_list|(
literal|"in foo ()"
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGUSR1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|puts
argument_list|(
literal|"in main"
argument_list|)
expr_stmt|;
comment|// Set breakpoint here
name|signal
argument_list|(
name|SIGUSR1
argument_list|,
name|handler
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"signal handler set up"
argument_list|)
expr_stmt|;
name|foo
argument_list|()
expr_stmt|;
name|puts
argument_list|(
literal|"exiting"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

