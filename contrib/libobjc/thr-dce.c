begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective C Runtime Thread Interface    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Galen C. Hunt (gchunt@cs.rochester.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled with    GCC to produce an executable, this does not cause the resulting executable    to be covered by the GNU General Public License. This exception does not    however invalidate any other reasons why the executable file might be    covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<thr.h>
end_include

begin_include
include|#
directive|include
file|"runtime.h"
end_include

begin_comment
comment|/* Key structure for maintaining thread specific storage */
end_comment

begin_decl_stmt
specifier|static
name|pthread_key_t
name|_objc_thread_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Backend initialization functions */
end_comment

begin_comment
comment|/* Initialize the threads subsystem. */
end_comment

begin_function
name|int
name|__objc_init_thread_system
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Initialize the thread storage key */
return|return
name|pthread_keycreate
argument_list|(
operator|&
name|_objc_thread_storage
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Close the threads subsystem. */
end_comment

begin_function
name|int
name|__objc_close_thread_system
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Destroy the thread storage key */
comment|/* Not implemented yet */
comment|/* return pthread_key_delete(&_objc_thread_storage); */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Backend thread functions */
end_comment

begin_comment
comment|/* Create a new thread of execution. */
end_comment

begin_function
name|objc_thread_t
name|__objc_thread_detach
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|objc_thread_t
name|thread_id
decl_stmt|;
name|pthread_t
name|new_thread_handle
decl_stmt|;
if|if
condition|(
name|pthread_create
argument_list|(
operator|&
name|new_thread_handle
argument_list|,
name|pthread_attr_default
argument_list|,
operator|(
name|void
operator|*
operator|)
name|func
argument_list|,
name|arg
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* ??? May not work! (64bit) */
name|thread_id
operator|=
operator|*
operator|(
name|objc_thread_t
operator|*
operator|)
operator|&
name|new_thread_handle
expr_stmt|;
name|pthread_detach
argument_list|(
operator|&
name|new_thread_handle
argument_list|)
expr_stmt|;
comment|/* Fully detach thread.     */
block|}
else|else
name|thread_id
operator|=
name|NULL
expr_stmt|;
return|return
name|thread_id
return|;
block|}
end_function

begin_comment
comment|/* Set the current thread's priority. */
end_comment

begin_function
name|int
name|__objc_thread_set_priority
parameter_list|(
name|int
name|priority
parameter_list|)
block|{
name|int
name|sys_priority
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|priority
condition|)
block|{
case|case
name|OBJC_THREAD_INTERACTIVE_PRIORITY
case|:
name|sys_priority
operator|=
operator|(
name|PRI_FG_MIN_NP
operator|+
name|PRI_FG_MAX_NP
operator|)
operator|/
literal|2
expr_stmt|;
break|break;
default|default:
case|case
name|OBJC_THREAD_BACKGROUND_PRIORITY
case|:
name|sys_priority
operator|=
operator|(
name|PRI_BG_MIN_NP
operator|+
name|PRI_BG_MAX_NP
operator|)
operator|/
literal|2
expr_stmt|;
break|break;
case|case
name|OBJC_THREAD_LOW_PRIORITY
case|:
name|sys_priority
operator|=
operator|(
name|PRI_BG_MIN_NP
operator|+
name|PRI_BG_MAX_NP
operator|)
operator|/
literal|2
expr_stmt|;
break|break;
block|}
comment|/* Change the priority. */
if|if
condition|(
name|pthread_setprio
argument_list|(
name|pthread_self
argument_list|()
argument_list|,
name|sys_priority
argument_list|)
operator|>=
literal|0
condition|)
return|return
literal|0
return|;
else|else
comment|/* Failed */
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Return the current thread's priority. */
end_comment

begin_function
name|int
name|__objc_thread_get_priority
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|sys_priority
decl_stmt|;
if|if
condition|(
operator|(
name|sys_priority
operator|=
name|pthread_getprio
argument_list|(
name|pthread_self
argument_list|()
argument_list|)
operator|)
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|sys_priority
operator|>=
name|PRI_FG_MIN_NP
operator|&&
name|sys_priority
operator|<=
name|PRI_FG_MAX_NP
condition|)
return|return
name|OBJC_THREAD_INTERACTIVE_PRIORITY
return|;
if|if
condition|(
name|sys_priority
operator|>=
name|PRI_BG_MIN_NP
operator|&&
name|sys_priority
operator|<=
name|PRI_BG_MAX_NP
condition|)
return|return
name|OBJC_THREAD_BACKGROUND_PRIORITY
return|;
return|return
name|OBJC_THREAD_LOW_PRIORITY
return|;
block|}
comment|/* Failed */
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Yield our process time to another thread. */
end_comment

begin_function
name|void
name|__objc_thread_yield
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_yield
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Terminate the current thread. */
end_comment

begin_function
name|int
name|__objc_thread_exit
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* exit the thread */
name|pthread_exit
argument_list|(
operator|&
name|__objc_thread_exit_status
argument_list|)
expr_stmt|;
comment|/* Failed if we reached here */
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Returns an integer value which uniquely describes a thread. */
end_comment

begin_function
name|objc_thread_t
name|__objc_thread_id
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_t
name|self
init|=
name|pthread_self
argument_list|()
decl_stmt|;
return|return
operator|(
name|objc_thread_t
operator|)
name|pthread_getunique_np
argument_list|(
operator|&
name|self
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Sets the thread's local storage pointer. */
end_comment

begin_function
name|int
name|__objc_thread_set_data
parameter_list|(
name|void
modifier|*
name|value
parameter_list|)
block|{
return|return
name|pthread_setspecific
argument_list|(
name|_objc_thread_storage
argument_list|,
name|value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Returns the thread's local storage pointer. */
end_comment

begin_function
name|void
modifier|*
name|__objc_thread_get_data
parameter_list|(
name|void
parameter_list|)
block|{
name|void
modifier|*
name|value
init|=
name|NULL
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|pthread_getspecific
argument_list|(
name|_objc_thread_storage
argument_list|,
operator|&
name|value
argument_list|)
operator|)
condition|)
return|return
name|value
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Backend mutex functions */
end_comment

begin_comment
comment|/* Allocate a mutex. */
end_comment

begin_function
name|int
name|__objc_mutex_allocate
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|pthread_mutex_init
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|mutex
operator|->
name|backend
operator|)
operator|)
argument_list|,
name|pthread_mutexattr_default
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
else|else
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Deallocate a mutex. */
end_comment

begin_function
name|int
name|__objc_mutex_deallocate
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|mutex
operator|->
name|backend
operator|)
operator|)
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
else|else
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Grab a lock on a mutex. */
end_comment

begin_function
name|int
name|__objc_mutex_lock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
return|return
name|pthread_mutex_lock
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|mutex
operator|->
name|backend
operator|)
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Try to grab a lock on a mutex. */
end_comment

begin_function
name|int
name|__objc_mutex_trylock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|pthread_mutex_trylock
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|mutex
operator|->
name|backend
operator|)
operator|)
argument_list|)
operator|!=
literal|1
condition|)
return|return
operator|-
literal|1
return|;
else|else
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Unlock the mutex */
end_comment

begin_function
name|int
name|__objc_mutex_unlock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
return|return
name|pthread_mutex_unlock
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|mutex
operator|->
name|backend
operator|)
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Backend condition mutex functions */
end_comment

begin_comment
comment|/* Allocate a condition. */
end_comment

begin_function
name|int
name|__objc_condition_allocate
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
comment|/* Unimplemented. */
return|return
operator|-
literal|1
return|;
comment|/*   if (pthread_cond_init((pthread_cond_t *)(&(condition->backend)), NULL))     return -1;   else     return 0;     */
block|}
end_function

begin_comment
comment|/* Deallocate a condition. */
end_comment

begin_function
name|int
name|__objc_condition_deallocate
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
comment|/* Unimplemented. */
return|return
operator|-
literal|1
return|;
comment|/*   return pthread_cond_destroy((pthread_cond_t *)(&(condition->backend)));   */
block|}
end_function

begin_comment
comment|/* Wait on the condition */
end_comment

begin_function
name|int
name|__objc_condition_wait
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|,
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
comment|/* Unimplemented. */
return|return
operator|-
literal|1
return|;
comment|/*   return pthread_cond_wait((pthread_cond_t *)(&(condition->backend)), 			   (pthread_mutex_t *)(&(mutex->backend))); 			   */
block|}
end_function

begin_comment
comment|/* Wake up all threads waiting on this condition. */
end_comment

begin_function
name|int
name|__objc_condition_broadcast
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
comment|/* Unimplemented. */
return|return
operator|-
literal|1
return|;
comment|/*   return pthread_cond_broadcast((pthread_cond_t *)(&(condition->backend)));   */
block|}
end_function

begin_comment
comment|/* Wake up one thread waiting on this condition. */
end_comment

begin_function
name|int
name|__objc_condition_signal
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
comment|/* Unimplemented. */
return|return
operator|-
literal|1
return|;
comment|/*   return pthread_cond_signal((pthread_cond_t *)(&(condition->backend)));   */
block|}
end_function

begin_comment
comment|/* End of File */
end_comment

end_unit

