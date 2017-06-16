begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<MyFramework/MyFramework.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_decl_stmt
name|int
name|setup_is_complete
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|system
argument_list|(
literal|"/bin/rm -rf MyFramework MyFramework.framework MyFramework.framework.dSYM"
argument_list|)
expr_stmt|;
name|setup_is_complete
operator|=
literal|1
expr_stmt|;
comment|// At this point we want lldb to attach to the process.  If lldb attaches
comment|// before we've removed the framework we're running against, it will be
comment|// easy for lldb to find the binary& dSYM without using target.exec-search-paths,
comment|// which is the point of this test.
for|for
control|(
name|int
name|loop_limiter
init|=
literal|0
init|;
name|loop_limiter
operator|<
literal|100
condition|;
name|loop_limiter
operator|++
control|)
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
name|foo
argument_list|()
return|;
block|}
end_function

end_unit

