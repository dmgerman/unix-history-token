begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective C Runtime Thread Interface - Win32 Implementation    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Galen C. Hunt (gchunt@cs.rochester.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|__OBJC__
end_ifndef

begin_define
define|#
directive|define
name|__OBJC__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|/* Key structure for maintaining thread specific storage */
end_comment

begin_decl_stmt
specifier|static
name|DWORD
name|__objc_data_tls
init|=
operator|(
name|DWORD
operator|)
operator|-
literal|1
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
operator|(
name|__objc_data_tls
operator|=
name|TlsAlloc
argument_list|()
operator|)
operator|!=
operator|(
name|DWORD
operator|)
operator|-
literal|1
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
if|if
condition|(
name|__objc_data_tls
operator|!=
operator|(
name|DWORD
operator|)
operator|-
literal|1
condition|)
name|TlsFree
argument_list|(
name|__objc_data_tls
argument_list|)
expr_stmt|;
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
name|DWORD
name|thread_id
init|=
literal|0
decl_stmt|;
name|HANDLE
name|win32_handle
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|win32_handle
operator|=
name|CreateThread
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
operator|(
name|LPTHREAD_START_ROUTINE
operator|)
name|func
argument_list|,
name|arg
argument_list|,
literal|0
argument_list|,
operator|&
name|thread_id
argument_list|)
operator|)
condition|)
name|thread_id
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|objc_thread_t
operator|)
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
name|THREAD_PRIORITY_NORMAL
expr_stmt|;
break|break;
default|default:
case|case
name|OBJC_THREAD_BACKGROUND_PRIORITY
case|:
name|sys_priority
operator|=
name|THREAD_PRIORITY_BELOW_NORMAL
expr_stmt|;
break|break;
case|case
name|OBJC_THREAD_LOW_PRIORITY
case|:
name|sys_priority
operator|=
name|THREAD_PRIORITY_LOWEST
expr_stmt|;
break|break;
block|}
comment|/* Change priority */
if|if
condition|(
name|SetThreadPriority
argument_list|(
name|GetCurrentThread
argument_list|()
argument_list|,
name|sys_priority
argument_list|)
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
name|sys_priority
operator|=
name|GetThreadPriority
argument_list|(
name|GetCurrentThread
argument_list|()
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|sys_priority
condition|)
block|{
case|case
name|THREAD_PRIORITY_HIGHEST
case|:
case|case
name|THREAD_PRIORITY_TIME_CRITICAL
case|:
case|case
name|THREAD_PRIORITY_ABOVE_NORMAL
case|:
case|case
name|THREAD_PRIORITY_NORMAL
case|:
return|return
name|OBJC_THREAD_INTERACTIVE_PRIORITY
return|;
default|default:
case|case
name|THREAD_PRIORITY_BELOW_NORMAL
case|:
return|return
name|OBJC_THREAD_BACKGROUND_PRIORITY
return|;
case|case
name|THREAD_PRIORITY_IDLE
case|:
case|case
name|THREAD_PRIORITY_LOWEST
case|:
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
name|Sleep
argument_list|(
literal|0
argument_list|)
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
name|ExitThread
argument_list|(
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
name|GetCurrentThreadId
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
name|TlsSetValue
argument_list|(
name|__objc_data_tls
argument_list|,
name|value
argument_list|)
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
return|return
name|TlsGetValue
argument_list|(
name|__objc_data_tls
argument_list|)
return|;
comment|/* Return thread data.      */
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
operator|(
name|mutex
operator|->
name|backend
operator|=
operator|(
name|void
operator|*
operator|)
name|CreateMutex
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
name|NULL
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
name|CloseHandle
argument_list|(
call|(
name|HANDLE
call|)
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
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
name|int
name|status
decl_stmt|;
name|status
operator|=
name|WaitForSingleObject
argument_list|(
call|(
name|HANDLE
call|)
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|WAIT_OBJECT_0
operator|&&
name|status
operator|!=
name|WAIT_ABANDONED
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
name|int
name|status
decl_stmt|;
name|status
operator|=
name|WaitForSingleObject
argument_list|(
call|(
name|HANDLE
call|)
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|WAIT_OBJECT_0
operator|&&
name|status
operator|!=
name|WAIT_ABANDONED
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
name|ReleaseMutex
argument_list|(
call|(
name|HANDLE
call|)
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
argument_list|)
operator|==
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
comment|/* Unimplemented. */
return|return
operator|-
literal|1
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
comment|/* Unimplemented. */
return|return
operator|-
literal|1
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
comment|/* Unimplemented. */
return|return
operator|-
literal|1
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
comment|/* Unimplemented. */
return|return
operator|-
literal|1
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
comment|/* Unimplemented. */
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* End of File */
end_comment

end_unit

