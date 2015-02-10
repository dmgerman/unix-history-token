begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
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

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// TSan-invisible barrier.
end_comment

begin_comment
comment|// Tests use it to establish necessary execution order in a way that does not
end_comment

begin_comment
comment|// interfere with tsan (does not establish synchronization between threads).
end_comment

begin_expr_stmt
name|__typeof
argument_list|(
name|pthread_barrier_wait
argument_list|)
operator|*
name|barrier_wait
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|barrier_init
parameter_list|(
name|pthread_barrier_t
modifier|*
name|barrier
parameter_list|,
name|unsigned
name|count
parameter_list|)
block|{
if|if
condition|(
name|barrier_wait
operator|==
literal|0
condition|)
block|{
name|void
modifier|*
name|h
init|=
name|dlopen
argument_list|(
literal|"libpthread.so.0"
argument_list|,
name|RTLD_LAZY
argument_list|)
decl_stmt|;
if|if
condition|(
name|h
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"failed to dlopen libpthread.so.0, exiting\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|barrier_wait
operator|=
operator|(
name|__typeof
argument_list|(
name|barrier_wait
argument_list|)
operator|)
name|dlsym
argument_list|(
name|h
argument_list|,
literal|"pthread_barrier_wait"
argument_list|)
expr_stmt|;
if|if
condition|(
name|barrier_wait
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"failed to resolve pthread_barrier_wait, exiting\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|pthread_barrier_init
argument_list|(
name|barrier
argument_list|,
literal|0
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Default instance of the barrier, but a test can declare more manually.
end_comment

begin_decl_stmt
name|pthread_barrier_t
name|barrier
decl_stmt|;
end_decl_stmt

end_unit

