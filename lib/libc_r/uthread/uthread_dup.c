begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"pthread_private.h"
end_include

begin_function
name|int
name|dup
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
comment|/* Lock the file descriptor: */
if|if
condition|(
operator|(
name|ret
operator|=
name|_thread_fd_lock
argument_list|(
name|fd
argument_list|,
name|FD_RDWR
argument_list|,
name|NULL
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* Perform the 'dup' syscall: */
if|if
condition|(
operator|(
name|ret
operator|=
name|_thread_sys_dup
argument_list|(
name|fd
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{ 		}
comment|/* Initialise the file descriptor table entry: */
elseif|else
if|if
condition|(
name|_thread_fd_table_init
argument_list|(
name|ret
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* Quietly close the file: */
name|_thread_sys_close
argument_list|(
name|ret
argument_list|)
expr_stmt|;
comment|/* Reset the file descriptor: */
name|ret
operator|=
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|/* 			 * Save the file open flags so that they can be 			 * checked later:  			 */
name|_thread_fd_table
index|[
name|ret
index|]
operator|->
name|flags
operator|=
name|_thread_fd_table
index|[
name|fd
index|]
operator|->
name|flags
expr_stmt|;
block|}
comment|/* Unlock the file descriptor: */
name|_thread_fd_unlock
argument_list|(
name|fd
argument_list|,
name|FD_RDWR
argument_list|)
expr_stmt|;
block|}
comment|/* Return the completion status: */
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

