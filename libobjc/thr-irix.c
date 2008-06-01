begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective C Runtime Thread Interface - SGI IRIX Implementation    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Galen C. Hunt (gchunt@cs.rochester.edu)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled with    GCC to produce an executable, this does not cause the resulting executable    to be covered by the GNU General Public License. This exception does not    however invalidate any other reasons why the executable file might be    covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysmp.h>
end_include

begin_include
include|#
directive|include
file|<sys/prctl.h>
end_include

begin_include
include|#
directive|include
file|<ulocks.h>
end_include

begin_include
include|#
directive|include
file|"objc/thr.h"
end_include

begin_include
include|#
directive|include
file|"objc/runtime.h"
end_include

begin_comment
comment|/* Key structure for maintaining thread specific storage */
end_comment

begin_decl_stmt
specifier|static
name|void
modifier|*
name|__objc_shared_arena_handle
init|=
name|NULL
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
comment|/* Name of IRIX arena. */
name|char
name|arena_name
index|[
literal|64
index|]
decl_stmt|;
name|DEBUG_PRINTF
argument_list|(
literal|"__objc_init_thread_system\n"
argument_list|)
expr_stmt|;
comment|/* Construct a temporary name for arena. */
name|sprintf
argument_list|(
name|arena_name
argument_list|,
literal|"/usr/tmp/objc_%05u"
argument_list|,
operator|(
name|unsigned
operator|)
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* Up to 256 threads.  Arena only for threads. */
name|usconfig
argument_list|(
name|CONF_INITUSERS
argument_list|,
literal|256
argument_list|)
expr_stmt|;
name|usconfig
argument_list|(
name|CONF_ARENATYPE
argument_list|,
name|US_SHAREDONLY
argument_list|)
expr_stmt|;
comment|/* Initialize the arena */
if|if
condition|(
operator|!
operator|(
name|__objc_shared_arena_handle
operator|=
name|usinit
argument_list|(
name|arena_name
argument_list|)
operator|)
condition|)
comment|/* Failed */
return|return
operator|-
literal|1
return|;
return|return
literal|0
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
name|int
name|sys_id
decl_stmt|;
if|if
condition|(
operator|(
name|sys_id
operator|=
name|sproc
argument_list|(
operator|(
name|void
operator|*
operator|)
name|func
argument_list|,
name|PR_SALL
argument_list|,
name|arg
argument_list|)
operator|)
operator|>=
literal|0
condition|)
name|thread_id
operator|=
operator|(
name|objc_thread_t
operator|)
name|sys_id
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
comment|/* Not implemented yet */
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
comment|/* Not implemented yet */
return|return
name|OBJC_THREAD_INTERACTIVE_PRIORITY
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
name|sginap
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
comment|/* IRIX only has exit. */
name|exit
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
comment|/* Threads are processes. */
return|return
operator|(
name|objc_thread_t
operator|)
name|get_pid
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
operator|*
operator|(
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|PRDA
operator|->
name|usr_prda
operator|)
operator|=
name|value
expr_stmt|;
return|return
literal|0
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
operator|*
operator|(
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|PRDA
operator|->
name|usr_prda
operator|)
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
operator|!
operator|(
call|(
name|ulock_t
call|)
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
operator|=
name|usnewlock
argument_list|(
name|__objc_shared_arena_handle
argument_list|)
operator|)
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
name|usfreelock
argument_list|(
call|(
name|ulock_t
call|)
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
argument_list|,
name|__objc_shared_arena_handle
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
name|ussetlock
argument_list|(
call|(
name|ulock_t
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
name|ustestlock
argument_list|(
call|(
name|ulock_t
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
name|usunsetlock
argument_list|(
call|(
name|ulock_t
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

