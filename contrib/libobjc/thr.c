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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"runtime.h"
end_include

begin_comment
comment|/* Global exit status. */
end_comment

begin_decl_stmt
name|int
name|__objc_thread_exit_status
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag which lets us know if we ever became multi threaded */
end_comment

begin_decl_stmt
name|int
name|__objc_is_multi_threaded
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The hook function called when the runtime becomes multi threaded */
end_comment

begin_decl_stmt
name|objc_thread_callback
name|_objc_became_multi_threaded
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   Use this to set the hook function that will be called when the    runtime initially becomes multi threaded.   The hook function is only called once, meaning only when the    2nd thread is spawned, not for each and every thread.    It returns the previous hook function or NULL if there is none.    A program outside of the runtime could set this to some function so   it can be informed; for example, the GNUstep Base Library sets it    so it can implement the NSBecomingMultiThreaded notification.   */
end_comment

begin_function
name|objc_thread_callback
name|objc_set_thread_callback
parameter_list|(
name|objc_thread_callback
name|func
parameter_list|)
block|{
name|objc_thread_callback
name|temp
init|=
name|_objc_became_multi_threaded
decl_stmt|;
name|_objc_became_multi_threaded
operator|=
name|func
expr_stmt|;
return|return
name|temp
return|;
block|}
end_function

begin_comment
comment|/*   Private functions    These functions are utilized by the frontend, but they are not   considered part of the public interface.   */
end_comment

begin_comment
comment|/*   First function called in a thread, starts everything else.    This function is passed to the backend by objc_thread_detach   as the starting function for a new thread.  */
end_comment

begin_struct
struct|struct
name|__objc_thread_start_state
block|{
name|SEL
name|selector
decl_stmt|;
name|id
name|object
decl_stmt|;
name|id
name|argument
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|volatile
name|void
name|__objc_thread_detach_function
parameter_list|(
name|struct
name|__objc_thread_start_state
modifier|*
name|istate
parameter_list|)
block|{
comment|/* Valid state? */
if|if
condition|(
name|istate
condition|)
block|{
name|id
function_decl|(
modifier|*
name|imp
function_decl|)
parameter_list|(
name|id
parameter_list|,
name|SEL
parameter_list|,
name|id
parameter_list|)
function_decl|;
name|SEL
name|selector
init|=
name|istate
operator|->
name|selector
decl_stmt|;
name|id
name|object
init|=
name|istate
operator|->
name|object
decl_stmt|;
name|id
name|argument
init|=
name|istate
operator|->
name|argument
decl_stmt|;
comment|/* Don't need anymore so free it */
name|objc_free
argument_list|(
name|istate
argument_list|)
expr_stmt|;
comment|/* Clear out the thread local storage */
name|objc_thread_set_data
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
comment|/* Check to see if we just became multi threaded */
if|if
condition|(
operator|!
name|__objc_is_multi_threaded
condition|)
block|{
name|__objc_is_multi_threaded
operator|=
literal|1
expr_stmt|;
comment|/* Call the hook function */
if|if
condition|(
name|_objc_became_multi_threaded
operator|!=
name|NULL
condition|)
call|(
modifier|*
name|_objc_became_multi_threaded
call|)
argument_list|()
expr_stmt|;
block|}
comment|/* Call the method */
if|if
condition|(
operator|(
name|imp
operator|=
operator|(
name|id
argument_list|(
operator|*
argument_list|)
argument_list|(
name|id
argument_list|,
name|SEL
argument_list|,
name|id
argument_list|)
operator|)
name|objc_msg_lookup
argument_list|(
name|object
argument_list|,
name|selector
argument_list|)
operator|)
condition|)
call|(
modifier|*
name|imp
call|)
argument_list|(
name|object
argument_list|,
name|selector
argument_list|,
name|argument
argument_list|)
expr_stmt|;
else|else
name|objc_error
argument_list|(
name|object
argument_list|,
name|OBJC_ERR_UNIMPLEMENTED
argument_list|,
literal|"objc_thread_detach called with bad selector.\n"
argument_list|)
expr_stmt|;
block|}
else|else
name|objc_error
argument_list|(
name|nil
argument_list|,
name|OBJC_ERR_BAD_STATE
argument_list|,
literal|"objc_thread_detach called with NULL state.\n"
argument_list|)
expr_stmt|;
comment|/* Exit the thread */
name|objc_thread_exit
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*   Frontend functions    These functions constitute the public interface to the Objective-C thread   and mutex functionality.   */
end_comment

begin_comment
comment|/* Frontend thread functions */
end_comment

begin_comment
comment|/*   Detach a new thread of execution and return its id.  Returns NULL if fails.   Thread is started by sending message with selector to object.  Message   takes a single argument.   */
end_comment

begin_function
name|objc_thread_t
name|objc_thread_detach
parameter_list|(
name|SEL
name|selector
parameter_list|,
name|id
name|object
parameter_list|,
name|id
name|argument
parameter_list|)
block|{
name|struct
name|__objc_thread_start_state
modifier|*
name|istate
decl_stmt|;
name|objc_thread_t
name|thread_id
init|=
name|NULL
decl_stmt|;
comment|/* Allocate the state structure */
if|if
condition|(
operator|!
operator|(
name|istate
operator|=
operator|(
expr|struct
name|__objc_thread_start_state
operator|*
operator|)
name|objc_malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|istate
argument_list|)
argument_list|)
operator|)
condition|)
return|return
name|NULL
return|;
comment|/* Initialize the state structure */
name|istate
operator|->
name|selector
operator|=
name|selector
expr_stmt|;
name|istate
operator|->
name|object
operator|=
name|object
expr_stmt|;
name|istate
operator|->
name|argument
operator|=
name|argument
expr_stmt|;
comment|/* lock access */
name|objc_mutex_lock
argument_list|(
name|__objc_runtime_mutex
argument_list|)
expr_stmt|;
comment|/* Call the backend to spawn the thread */
if|if
condition|(
operator|(
name|thread_id
operator|=
name|__objc_thread_detach
argument_list|(
operator|(
name|void
operator|*
operator|)
name|__objc_thread_detach_function
argument_list|,
name|istate
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* failed! */
name|objc_mutex_unlock
argument_list|(
name|__objc_runtime_mutex
argument_list|)
expr_stmt|;
name|objc_free
argument_list|(
name|istate
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
comment|/* Increment our thread counter */
name|__objc_runtime_threads_alive
operator|++
expr_stmt|;
name|objc_mutex_unlock
argument_list|(
name|__objc_runtime_mutex
argument_list|)
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
name|objc_thread_set_priority
parameter_list|(
name|int
name|priority
parameter_list|)
block|{
comment|/* Call the backend */
return|return
name|__objc_thread_set_priority
argument_list|(
name|priority
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Return the current thread's priority. */
end_comment

begin_function
name|int
name|objc_thread_get_priority
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Call the backend */
return|return
name|__objc_thread_get_priority
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/*   Yield our process time to another thread.  Any BUSY waiting that is done   by a thread should use this function to make sure that other threads can   make progress even on a lazy uniprocessor system.   */
end_comment

begin_function
name|void
name|objc_thread_yield
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Call the backend */
name|__objc_thread_yield
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*   Terminate the current tread.  Doesn't return.   Actually, if it failed returns -1.   */
end_comment

begin_function
name|int
name|objc_thread_exit
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Decrement our counter of the number of threads alive */
name|objc_mutex_lock
argument_list|(
name|__objc_runtime_mutex
argument_list|)
expr_stmt|;
name|__objc_runtime_threads_alive
operator|--
expr_stmt|;
name|objc_mutex_unlock
argument_list|(
name|__objc_runtime_mutex
argument_list|)
expr_stmt|;
comment|/* Call the backend to terminate the thread */
return|return
name|__objc_thread_exit
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/*   Returns an integer value which uniquely describes a thread.  Must not be   NULL which is reserved as a marker for "no thread".   */
end_comment

begin_function
name|objc_thread_t
name|objc_thread_id
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Call the backend */
return|return
name|__objc_thread_id
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/*   Sets the thread's local storage pointer.    Returns 0 if successful or -1 if failed.   */
end_comment

begin_function
name|int
name|objc_thread_set_data
parameter_list|(
name|void
modifier|*
name|value
parameter_list|)
block|{
comment|/* Call the backend */
return|return
name|__objc_thread_set_data
argument_list|(
name|value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*   Returns the thread's local storage pointer.  Returns NULL on failure.   */
end_comment

begin_function
name|void
modifier|*
name|objc_thread_get_data
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Call the backend */
return|return
name|__objc_thread_get_data
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/* Frontend mutex functions */
end_comment

begin_comment
comment|/*   Allocate a mutex.  Return the mutex pointer if successful or NULL if the   allocation failed for any reason.   */
end_comment

begin_function
name|objc_mutex_t
name|objc_mutex_allocate
parameter_list|(
name|void
parameter_list|)
block|{
name|objc_mutex_t
name|mutex
decl_stmt|;
comment|/* Allocate the mutex structure */
if|if
condition|(
operator|!
operator|(
name|mutex
operator|=
operator|(
name|objc_mutex_t
operator|)
name|objc_malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|objc_mutex
argument_list|)
argument_list|)
operator|)
condition|)
return|return
name|NULL
return|;
comment|/* Call backend to create the mutex */
if|if
condition|(
name|__objc_mutex_allocate
argument_list|(
name|mutex
argument_list|)
condition|)
block|{
comment|/* failed! */
name|objc_free
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
comment|/* Initialize mutex */
name|mutex
operator|->
name|owner
operator|=
name|NULL
expr_stmt|;
name|mutex
operator|->
name|depth
operator|=
literal|0
expr_stmt|;
return|return
name|mutex
return|;
block|}
end_function

begin_comment
comment|/*   Deallocate a mutex.  Note that this includes an implicit mutex_lock to   insure that no one else is using the lock.  It is legal to deallocate   a lock if we have a lock on it, but illegal to deallocate a lock held   by anyone else.   Returns the number of locks on the thread.  (1 for deallocate).   */
end_comment

begin_function
name|int
name|objc_mutex_deallocate
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
name|int
name|depth
decl_stmt|;
comment|/* Valid mutex? */
if|if
condition|(
operator|!
name|mutex
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Acquire lock on mutex */
name|depth
operator|=
name|objc_mutex_lock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
comment|/* Call backend to destroy mutex */
if|if
condition|(
name|__objc_mutex_deallocate
argument_list|(
name|mutex
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Free the mutex structure */
name|objc_free
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
comment|/* Return last depth */
return|return
name|depth
return|;
block|}
end_function

begin_comment
comment|/*   Grab a lock on a mutex.  If this thread already has a lock on this mutex   then we increment the lock count.  If another thread has a lock on the    mutex we block and wait for the thread to release the lock.   Returns the lock count on the mutex held by this thread.   */
end_comment

begin_function
name|int
name|objc_mutex_lock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
name|objc_thread_t
name|thread_id
decl_stmt|;
name|int
name|status
decl_stmt|;
comment|/* Valid mutex? */
if|if
condition|(
operator|!
name|mutex
condition|)
return|return
operator|-
literal|1
return|;
comment|/* If we already own the lock then increment depth */
name|thread_id
operator|=
name|objc_thread_id
argument_list|()
expr_stmt|;
if|if
condition|(
name|mutex
operator|->
name|owner
operator|==
name|thread_id
condition|)
return|return
operator|++
name|mutex
operator|->
name|depth
return|;
comment|/* Call the backend to lock the mutex */
name|status
operator|=
name|__objc_mutex_lock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
comment|/* Failed? */
if|if
condition|(
name|status
condition|)
return|return
name|status
return|;
comment|/* Successfully locked the thread */
name|mutex
operator|->
name|owner
operator|=
name|thread_id
expr_stmt|;
return|return
name|mutex
operator|->
name|depth
operator|=
literal|1
return|;
block|}
end_function

begin_comment
comment|/*   Try to grab a lock on a mutex.  If this thread already has a lock on   this mutex then we increment the lock count and return it.  If another   thread has a lock on the mutex returns -1.   */
end_comment

begin_function
name|int
name|objc_mutex_trylock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
name|objc_thread_t
name|thread_id
decl_stmt|;
name|int
name|status
decl_stmt|;
comment|/* Valid mutex? */
if|if
condition|(
operator|!
name|mutex
condition|)
return|return
operator|-
literal|1
return|;
comment|/* If we already own the lock then increment depth */
name|thread_id
operator|=
name|objc_thread_id
argument_list|()
expr_stmt|;
if|if
condition|(
name|mutex
operator|->
name|owner
operator|==
name|thread_id
condition|)
return|return
operator|++
name|mutex
operator|->
name|depth
return|;
comment|/* Call the backend to try to lock the mutex */
name|status
operator|=
name|__objc_mutex_trylock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
comment|/* Failed? */
if|if
condition|(
name|status
condition|)
return|return
name|status
return|;
comment|/* Successfully locked the thread */
name|mutex
operator|->
name|owner
operator|=
name|thread_id
expr_stmt|;
return|return
name|mutex
operator|->
name|depth
operator|=
literal|1
return|;
block|}
end_function

begin_comment
comment|/*    Unlocks the mutex by one level.   Decrements the lock count on this mutex by one.   If the lock count reaches zero, release the lock on the mutex.   Returns the lock count on the mutex.   It is an error to attempt to unlock a mutex which this thread    doesn't hold in which case return -1 and the mutex is unaffected.   */
end_comment

begin_function
name|int
name|objc_mutex_unlock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
name|objc_thread_t
name|thread_id
decl_stmt|;
name|int
name|status
decl_stmt|;
comment|/* Valid mutex? */
if|if
condition|(
operator|!
name|mutex
condition|)
return|return
operator|-
literal|1
return|;
comment|/* If another thread owns the lock then abort */
name|thread_id
operator|=
name|objc_thread_id
argument_list|()
expr_stmt|;
if|if
condition|(
name|mutex
operator|->
name|owner
operator|!=
name|thread_id
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Decrement depth and return */
if|if
condition|(
name|mutex
operator|->
name|depth
operator|>
literal|1
condition|)
return|return
operator|--
name|mutex
operator|->
name|depth
return|;
comment|/* Depth down to zero so we are no longer the owner */
name|mutex
operator|->
name|depth
operator|=
literal|0
expr_stmt|;
name|mutex
operator|->
name|owner
operator|=
name|NULL
expr_stmt|;
comment|/* Have the backend unlock the mutex */
name|status
operator|=
name|__objc_mutex_unlock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
comment|/* Failed? */
if|if
condition|(
name|status
condition|)
return|return
name|status
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Frontend condition mutex functions */
end_comment

begin_comment
comment|/*   Allocate a condition.  Return the condition pointer if successful or NULL   if the allocation failed for any reason.   */
end_comment

begin_function
name|objc_condition_t
name|objc_condition_allocate
parameter_list|(
name|void
parameter_list|)
block|{
name|objc_condition_t
name|condition
decl_stmt|;
comment|/* Allocate the condition mutex structure */
if|if
condition|(
operator|!
operator|(
name|condition
operator|=
operator|(
name|objc_condition_t
operator|)
name|objc_malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|objc_condition
argument_list|)
argument_list|)
operator|)
condition|)
return|return
name|NULL
return|;
comment|/* Call the backend to create the condition mutex */
if|if
condition|(
name|__objc_condition_allocate
argument_list|(
name|condition
argument_list|)
condition|)
block|{
comment|/* failed! */
name|objc_free
argument_list|(
name|condition
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
comment|/* Success! */
return|return
name|condition
return|;
block|}
end_function

begin_comment
comment|/*   Deallocate a condition. Note that this includes an implicit    condition_broadcast to insure that waiting threads have the opportunity   to wake.  It is legal to dealloc a condition only if no other   thread is/will be using it. Here we do NOT check for other threads   waiting but just wake them up.   */
end_comment

begin_function
name|int
name|objc_condition_deallocate
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
comment|/* Broadcast the condition */
if|if
condition|(
name|objc_condition_broadcast
argument_list|(
name|condition
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Call the backend to destroy */
if|if
condition|(
name|__objc_condition_deallocate
argument_list|(
name|condition
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Free the condition mutex structure */
name|objc_free
argument_list|(
name|condition
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*   Wait on the condition unlocking the mutex until objc_condition_signal()   or objc_condition_broadcast() are called for the same condition. The   given mutex *must* have the depth set to 1 so that it can be unlocked   here, so that someone else can lock it and signal/broadcast the condition.   The mutex is used to lock access to the shared data that make up the   "condition" predicate.   */
end_comment

begin_function
name|int
name|objc_condition_wait
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|,
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
name|objc_thread_t
name|thread_id
decl_stmt|;
comment|/* Valid arguments? */
if|if
condition|(
operator|!
name|mutex
operator|||
operator|!
name|condition
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Make sure we are owner of mutex */
name|thread_id
operator|=
name|objc_thread_id
argument_list|()
expr_stmt|;
if|if
condition|(
name|mutex
operator|->
name|owner
operator|!=
name|thread_id
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Cannot be locked more than once */
if|if
condition|(
name|mutex
operator|->
name|depth
operator|>
literal|1
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Virtually unlock the mutex */
name|mutex
operator|->
name|depth
operator|=
literal|0
expr_stmt|;
name|mutex
operator|->
name|owner
operator|=
operator|(
name|objc_thread_t
operator|)
name|NULL
expr_stmt|;
comment|/* Call the backend to wait */
name|__objc_condition_wait
argument_list|(
name|condition
argument_list|,
name|mutex
argument_list|)
expr_stmt|;
comment|/* Make ourselves owner of the mutex */
name|mutex
operator|->
name|owner
operator|=
name|thread_id
expr_stmt|;
name|mutex
operator|->
name|depth
operator|=
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*   Wake up all threads waiting on this condition. It is recommended that    the called would lock the same mutex as the threads in objc_condition_wait   before changing the "condition predicate" and make this call and unlock it   right away after this call.   */
end_comment

begin_function
name|int
name|objc_condition_broadcast
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
comment|/* Valid condition mutex? */
if|if
condition|(
operator|!
name|condition
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|__objc_condition_broadcast
argument_list|(
name|condition
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*   Wake up one thread waiting on this condition. It is recommended that    the called would lock the same mutex as the threads in objc_condition_wait   before changing the "condition predicate" and make this call and unlock it   right away after this call.   */
end_comment

begin_function
name|int
name|objc_condition_signal
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
comment|/* Valid condition mutex? */
if|if
condition|(
operator|!
name|condition
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|__objc_condition_signal
argument_list|(
name|condition
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* End of File */
end_comment

end_unit

