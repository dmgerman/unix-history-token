begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<dlfcn.h>
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
name|void
modifier|*
name|handle
init|=
name|dlopen
argument_list|(
literal|"com.apple.sbd.xpc/com.apple.sbd"
argument_list|,
name|RTLD_NOW
argument_list|)
decl_stmt|;
if|if
condition|(
name|handle
condition|)
block|{
if|if
condition|(
name|dlsym
argument_list|(
name|handle
argument_list|,
literal|"foo"
argument_list|)
condition|)
block|{
name|system
argument_list|(
literal|"/bin/rm -rf com.apple.sbd.xpc com.apple.sbd.xpc.dSYM"
argument_list|)
expr_stmt|;
name|setup_is_complete
operator|=
literal|1
expr_stmt|;
comment|// At this point we want lldb to attach to the process.  If lldb attaches
comment|// before we've removed the dlopen'ed bundle, lldb will find the bundle
comment|// at its actual filepath and not have to do any tricky work, invalidating
comment|// the test.
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
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

