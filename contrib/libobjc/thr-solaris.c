begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective C Runtime Thread Interface    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Galen C. Hunt (gchunt@cs.rochester.edu)    Conditions added by Mircea Oancea (mircea@first.elcom.pub.ro)        This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled with    GCC to produce an executable, this does not cause the resulting executable    to be covered by the GNU General Public License. This exception does not    however invalidate any other reasons why the executable file might be    covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|<objc/thr.h>
end_include

begin_include
include|#
directive|include
file|"runtime.h"
end_include

begin_include
include|#
directive|include
file|<thread.h>
end_include

begin_include
include|#
directive|include
file|<synch.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* Key structure for maintaining thread specific storage */
end_comment

begin_decl_stmt
specifier|static
name|thread_key_t
name|__objc_thread_data_key
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
if|if
condition|(
name|thr_keycreate
argument_list|(
operator|&
name|__objc_thread_data_key
argument_list|,
name|NULL
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
else|else
return|return
operator|-
literal|1
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
name|thread_t
name|new_thread_id
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|thr_create
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
operator|(
name|void
operator|*
operator|)
name|func
argument_list|,
name|arg
argument_list|,
name|THR_DETACHED
operator||
name|THR_NEW_LWP
argument_list|,
operator|&
name|new_thread_id
argument_list|)
operator|==
literal|0
condition|)
name|thread_id
operator|=
operator|*
operator|(
name|objc_thread_t
operator|*
operator|)
operator|&
name|new_thread_id
expr_stmt|;
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
literal|300
expr_stmt|;
break|break;
default|default:
case|case
name|OBJC_THREAD_BACKGROUND_PRIORITY
case|:
name|sys_priority
operator|=
literal|200
expr_stmt|;
break|break;
case|case
name|OBJC_THREAD_LOW_PRIORITY
case|:
name|sys_priority
operator|=
literal|1000
expr_stmt|;
break|break;
block|}
comment|/* Change priority */
if|if
condition|(
name|thr_setprio
argument_list|(
name|thr_self
argument_list|()
argument_list|,
name|sys_priority
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
else|else
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
name|thr_getprio
argument_list|(
name|thr_self
argument_list|()
argument_list|,
operator|&
name|sys_priority
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|sys_priority
operator|>=
literal|250
condition|)
return|return
name|OBJC_THREAD_INTERACTIVE_PRIORITY
return|;
elseif|else
if|if
condition|(
name|sys_priority
operator|>=
literal|150
condition|)
return|return
name|OBJC_THREAD_BACKGROUND_PRIORITY
return|;
return|return
name|OBJC_THREAD_LOW_PRIORITY
return|;
block|}
comment|/* Couldn't get priority. */
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
name|thr_yield
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
name|thr_exit
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
return|return
operator|(
name|objc_thread_t
operator|)
name|thr_self
argument_list|()
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
if|if
condition|(
name|thr_setspecific
argument_list|(
name|__objc_thread_data_key
argument_list|,
name|value
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
else|else
return|return
operator|-
literal|1
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
name|thr_getspecific
argument_list|(
name|__objc_thread_data_key
argument_list|,
operator|&
name|value
argument_list|)
operator|==
literal|0
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
name|mutex_init
argument_list|(
operator|(
name|mutex_t
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
name|USYNC_THREAD
argument_list|,
literal|0
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
name|mutex_destroy
argument_list|(
operator|(
name|mutex_t
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
expr_stmt|;
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
if|if
condition|(
name|mutex_lock
argument_list|(
operator|(
name|mutex_t
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
literal|0
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
name|mutex_trylock
argument_list|(
operator|(
name|mutex_t
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
literal|0
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
if|if
condition|(
name|mutex_unlock
argument_list|(
operator|(
name|mutex_t
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
literal|0
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
return|return
name|cond_init
argument_list|(
operator|(
name|cond_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|condition
operator|->
name|backend
operator|)
operator|)
argument_list|,
name|USYNC_THREAD
argument_list|,
name|NULL
argument_list|)
return|;
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
return|return
name|cond_destroy
argument_list|(
operator|(
name|cond_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|condition
operator|->
name|backend
operator|)
operator|)
argument_list|)
return|;
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
return|return
name|cond_wait
argument_list|(
operator|(
name|cond_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|condition
operator|->
name|backend
operator|)
operator|)
argument_list|,
operator|(
name|mutex_t
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
return|return
name|cond_broadcast
argument_list|(
operator|(
name|cond_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|condition
operator|->
name|backend
operator|)
operator|)
argument_list|)
return|;
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
return|return
name|cond_signal
argument_list|(
operator|(
name|cond_t
operator|*
operator|)
operator|(
operator|&
operator|(
name|condition
operator|->
name|backend
operator|)
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* End of File */
end_comment

end_unit

