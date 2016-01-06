begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|handler_usr1
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|puts
argument_list|(
literal|"got signal usr1"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|handler_alrm
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|puts
argument_list|(
literal|"got signal ALRM"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|signal
argument_list|(
name|SIGUSR1
argument_list|,
name|handler_usr1
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|handler_alrm
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"Put breakpoint here"
argument_list|)
expr_stmt|;
while|while
condition|(
name|i
operator|++
operator|<
literal|20
condition|)
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

