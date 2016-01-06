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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|pthread_mutex_t
name|contended_mutex
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_mutex_t
name|control_mutex
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_cond_t
name|control_condition
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_mutex_t
name|thread_started_mutex
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_cond_t
name|thread_started_condition
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This function runs in a thread.  The locking dance is to make sure that
end_comment

begin_comment
comment|// by the time the main thread reaches the pthread_join below, this thread
end_comment

begin_comment
comment|// has for sure acquired the contended_mutex.  So then the call_me_to_get_lock
end_comment

begin_comment
comment|// function will block trying to get the mutex, and only succeed once it
end_comment

begin_comment
comment|// signals this thread, then lets it run to wake up from the cond_wait and
end_comment

begin_comment
comment|// release the mutex.
end_comment

begin_function
name|void
modifier|*
name|lock_acquirer_1
parameter_list|(
name|void
modifier|*
name|input
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|contended_mutex
argument_list|)
expr_stmt|;
comment|// Grab this mutex, that will ensure that the main thread
comment|// is in its cond_wait for it (since that's when it drops the mutex.
name|pthread_mutex_lock
argument_list|(
operator|&
name|thread_started_mutex
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|thread_started_mutex
argument_list|)
expr_stmt|;
comment|// Now signal the main thread that it can continue, we have the contended lock
comment|// so the call to call_me_to_get_lock won't make any progress till  this
comment|// thread gets a chance to run.
name|pthread_mutex_lock
argument_list|(
operator|&
name|control_mutex
argument_list|)
expr_stmt|;
name|pthread_cond_signal
argument_list|(
operator|&
name|thread_started_condition
argument_list|)
expr_stmt|;
name|pthread_cond_wait
argument_list|(
operator|&
name|control_condition
argument_list|,
operator|&
name|control_mutex
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|contended_mutex
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|int
name|call_me_to_get_lock
parameter_list|()
block|{
name|pthread_cond_signal
argument_list|(
operator|&
name|control_condition
argument_list|)
expr_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|contended_mutex
argument_list|)
expr_stmt|;
return|return
literal|567
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|pthread_t
name|thread_1
decl_stmt|;
name|pthread_cond_init
argument_list|(
operator|&
name|control_condition
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_cond_init
argument_list|(
operator|&
name|thread_started_condition
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|thread_started_mutex
argument_list|)
expr_stmt|;
name|pthread_create
argument_list|(
operator|&
name|thread_1
argument_list|,
name|NULL
argument_list|,
name|lock_acquirer_1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_cond_wait
argument_list|(
operator|&
name|thread_started_condition
argument_list|,
operator|&
name|thread_started_mutex
argument_list|)
expr_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|control_mutex
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|control_mutex
argument_list|)
expr_stmt|;
comment|// Break here.  At this point the other thread will have the contended_mutex,
comment|// and be sitting in its cond_wait for the control condition.  So there is
comment|// no way that our by-hand calling of call_me_to_get_lock will proceed
comment|// without running the first thread at least somewhat.
name|call_me_to_get_lock
argument_list|()
expr_stmt|;
name|pthread_join
argument_list|(
name|thread_1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

