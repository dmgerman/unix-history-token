begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/prctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
comment|// Immediately enable any ptracer so that we can allow the stub attach
comment|// operation to succeed.  Some Linux kernels are locked down so that
comment|// only an ancestor process can be a ptracer of a process.  This disables that
comment|// restriction.  Without it, attach-related stub tests will fail.
if|#
directive|if
name|defined
argument_list|(
name|PR_SET_PTRACER
argument_list|)
operator|&&
name|defined
argument_list|(
name|PR_SET_PTRACER_ANY
argument_list|)
name|int
name|prctl_result
decl_stmt|;
comment|// For now we execute on best effort basis.  If this fails for
comment|// some reason, so be it.
name|prctl_result
operator|=
name|prctl
argument_list|(
name|PR_SET_PTRACER
argument_list|,
name|PR_SET_PTRACER_ANY
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|prctl_result
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|printf
argument_list|(
literal|"Hello world.\n"
argument_list|)
expr_stmt|;
comment|// Set break point at this line.
if|if
condition|(
name|argc
operator|==
literal|1
condition|)
return|return
literal|0
return|;
comment|// Waiting to be attached by the debugger, otherwise.
name|char
name|line
index|[
literal|100
index|]
decl_stmt|;
while|while
condition|(
name|fgets
argument_list|(
name|line
argument_list|,
sizeof|sizeof
argument_list|(
name|line
argument_list|)
argument_list|,
name|stdin
argument_list|)
condition|)
block|{
comment|// Waiting to be attached...
name|printf
argument_list|(
literal|"input line=>%s\n"
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Exiting now\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

