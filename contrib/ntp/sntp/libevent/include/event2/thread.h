begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_THREAD_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_THREAD_H_INCLUDED_
end_define

begin_comment
comment|/** @file event2/thread.h    Functions for multi-threaded applications using Libevent.    When using a multi-threaded application in which multiple threads   add and delete events from a single event base, Libevent needs to   lock its data structures.    Like the memory-management function hooks, all of the threading functions   _must_ be set up before an event_base is created if you want the base to   use them.    Most programs will either be using Windows threads or Posix threads.  You   can configure Libevent to use one of these event_use_windows_threads() or   event_use_pthreads() respectively.  If you're using another threading   library, you'll need to configure threading functions manually using   evthread_set_lock_callbacks() and evthread_set_condition_callbacks().   */
end_comment

begin_include
include|#
directive|include
file|<event2/visibility.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<event2/event-config.h>
comment|/**    @name Flags passed to lock functions     @{ */
comment|/** A flag passed to a locking callback when the lock was allocated as a  * read-write lock, and we want to acquire or release the lock for writing. */
define|#
directive|define
name|EVTHREAD_WRITE
value|0x04
comment|/** A flag passed to a locking callback when the lock was allocated as a  * read-write lock, and we want to acquire or release the lock for reading. */
define|#
directive|define
name|EVTHREAD_READ
value|0x08
comment|/** A flag passed to a locking callback when we don't want to block waiting  * for the lock; if we can't get the lock immediately, we will instead  * return nonzero from the locking callback. */
define|#
directive|define
name|EVTHREAD_TRY
value|0x10
comment|/**@}*/
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVENT__DISABLE_THREAD_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
define|#
directive|define
name|EVTHREAD_LOCK_API_VERSION
value|1
comment|/**    @name Types of locks     @{*/
comment|/** A recursive lock is one that can be acquired multiple times at once by the  * same thread.  No other process can allocate the lock until the thread that  * has been holding it has unlocked it as many times as it locked it. */
define|#
directive|define
name|EVTHREAD_LOCKTYPE_RECURSIVE
value|1
comment|/* A read-write lock is one that allows multiple simultaneous readers, but  * where any one writer excludes all other writers and readers. */
define|#
directive|define
name|EVTHREAD_LOCKTYPE_READWRITE
value|2
comment|/**@}*/
comment|/** This structure describes the interface a threading library uses for  * locking.   It's used to tell evthread_set_lock_callbacks() how to use  * locking on this platform.  */
struct|struct
name|evthread_lock_callbacks
block|{
comment|/** The current version of the locking API.  Set this to 	 * EVTHREAD_LOCK_API_VERSION */
name|int
name|lock_api_version
decl_stmt|;
comment|/** Which kinds of locks does this version of the locking API 	 * support?  A bitfield of EVTHREAD_LOCKTYPE_RECURSIVE and 	 * EVTHREAD_LOCKTYPE_READWRITE. 	 * 	 * (Note that RECURSIVE locks are currently mandatory, and 	 * READWRITE locks are not currently used.) 	 **/
name|unsigned
name|supported_locktypes
decl_stmt|;
comment|/** Function to allocate and initialize new lock of type 'locktype'. 	 * Returns NULL on failure. */
name|void
modifier|*
function_decl|(
modifier|*
name|alloc
function_decl|)
parameter_list|(
name|unsigned
name|locktype
parameter_list|)
function_decl|;
comment|/** Funtion to release all storage held in 'lock', which was created 	 * with type 'locktype'. */
name|void
function_decl|(
modifier|*
name|free
function_decl|)
parameter_list|(
name|void
modifier|*
name|lock
parameter_list|,
name|unsigned
name|locktype
parameter_list|)
function_decl|;
comment|/** Acquire an already-allocated lock at 'lock' with mode 'mode'. 	 * Returns 0 on success, and nonzero on failure. */
name|int
function_decl|(
modifier|*
name|lock
function_decl|)
parameter_list|(
name|unsigned
name|mode
parameter_list|,
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
comment|/** Release a lock at 'lock' using mode 'mode'.  Returns 0 on success, 	 * and nonzero on failure. */
name|int
function_decl|(
modifier|*
name|unlock
function_decl|)
parameter_list|(
name|unsigned
name|mode
parameter_list|,
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
block|}
struct|;
comment|/** Sets a group of functions that Libevent should use for locking.  * For full information on the required callback API, see the  * documentation for the individual members of evthread_lock_callbacks.  *  * Note that if you're using Windows or the Pthreads threading library, you  * probably shouldn't call this function; instead, use  * evthread_use_windows_threads() or evthread_use_posix_threads() if you can.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evthread_set_lock_callbacks
parameter_list|(
specifier|const
name|struct
name|evthread_lock_callbacks
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|EVTHREAD_CONDITION_API_VERSION
value|1
struct_decl|struct
name|timeval
struct_decl|;
comment|/** This structure describes the interface a threading library uses for  * condition variables.  It's used to tell evthread_set_condition_callbacks  * how to use locking on this platform.  */
struct|struct
name|evthread_condition_callbacks
block|{
comment|/** The current version of the conditions API.  Set this to 	 * EVTHREAD_CONDITION_API_VERSION */
name|int
name|condition_api_version
decl_stmt|;
comment|/** Function to allocate and initialize a new condition variable. 	 * Returns the condition variable on success, and NULL on failure. 	 * The 'condtype' argument will be 0 with this API version. 	 */
name|void
modifier|*
function_decl|(
modifier|*
name|alloc_condition
function_decl|)
parameter_list|(
name|unsigned
name|condtype
parameter_list|)
function_decl|;
comment|/** Function to free a condition variable. */
name|void
function_decl|(
modifier|*
name|free_condition
function_decl|)
parameter_list|(
name|void
modifier|*
name|cond
parameter_list|)
function_decl|;
comment|/** Function to signal a condition variable.  If 'broadcast' is 1, all 	 * threads waiting on 'cond' should be woken; otherwise, only on one 	 * thread is worken.  Should return 0 on success, -1 on failure. 	 * This function will only be called while holding the associated 	 * lock for the condition. 	 */
name|int
function_decl|(
modifier|*
name|signal_condition
function_decl|)
parameter_list|(
name|void
modifier|*
name|cond
parameter_list|,
name|int
name|broadcast
parameter_list|)
function_decl|;
comment|/** Function to wait for a condition variable.  The lock 'lock' 	 * will be held when this function is called; should be released 	 * while waiting for the condition to be come signalled, and 	 * should be held again when this function returns. 	 * If timeout is provided, it is interval of seconds to wait for 	 * the event to become signalled; if it is NULL, the function 	 * should wait indefinitely. 	 * 	 * The function should return -1 on error; 0 if the condition 	 * was signalled, or 1 on a timeout. */
name|int
function_decl|(
modifier|*
name|wait_condition
function_decl|)
parameter_list|(
name|void
modifier|*
name|cond
parameter_list|,
name|void
modifier|*
name|lock
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|timeout
parameter_list|)
function_decl|;
block|}
struct|;
comment|/** Sets a group of functions that Libevent should use for condition variables.  * For full information on the required callback API, see the  * documentation for the individual members of evthread_condition_callbacks.  *  * Note that if you're using Windows or the Pthreads threading library, you  * probably shouldn't call this function; instead, use  * evthread_use_windows_threads() or evthread_use_pthreads() if you can.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evthread_set_condition_callbacks
parameter_list|(
specifier|const
name|struct
name|evthread_condition_callbacks
modifier|*
parameter_list|)
function_decl|;
comment|/**    Sets the function for determining the thread id.     @param base the event base for which to set the id function    @param id_fn the identify function Libevent should invoke to      determine the identity of a thread. */
name|EVENT2_EXPORT_SYMBOL
name|void
name|evthread_set_id_callback
argument_list|(
name|unsigned
name|long
argument_list|(
operator|*
name|id_fn
argument_list|)
argument_list|(
name|void
argument_list|)
argument_list|)
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EVENT__DISABLE_THREAD_SUPPORT
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
comment|/** Sets up Libevent for use with Windows builtin locking and thread ID     functions.  Unavailable if Libevent is not built for Windows.      @return 0 on success, -1 on failure. */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evthread_use_windows_threads
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**    Defined if Libevent was built with support for evthread_use_windows_threads() */
define|#
directive|define
name|EVTHREAD_USE_WINDOWS_THREADS_IMPLEMENTED
value|1
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|EVENT__HAVE_PTHREADS
argument_list|)
operator|||
name|defined
argument_list|(
name|EVENT_IN_DOXYGEN_
argument_list|)
comment|/** Sets up Libevent for use with Pthreads locking and thread ID functions.     Unavailable if Libevent is not build for use with pthreads.  Requires     libraries to link against Libevent_pthreads as well as Libevent.      @return 0 on success, -1 on failure. */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evthread_use_pthreads
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** Defined if Libevent was built with support for evthread_use_pthreads() */
define|#
directive|define
name|EVTHREAD_USE_PTHREADS_IMPLEMENTED
value|1
endif|#
directive|endif
comment|/** Enable debugging wrappers around the current lock callbacks.  If Libevent  * makes one of several common locking errors, exit with an assertion failure.  *  * If you're going to call this function, you must do so before any locks are  * allocated.  **/
name|EVENT2_EXPORT_SYMBOL
name|void
name|evthread_enable_lock_debugging
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Old (misspelled) version: This is deprecated; use  * evthread_enable_log_debugging instead. */
name|EVENT2_EXPORT_SYMBOL
name|void
name|evthread_enable_lock_debuging
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EVENT__DISABLE_THREAD_SUPPORT */
struct_decl|struct
name|event_base
struct_decl|;
comment|/** Make sure it's safe to tell an event base to wake up from another thread     or a signal handler.      You shouldn't need to call this by hand; configuring the base with thread     support should be necessary and sufficient.      @return 0 on success, -1 on failure.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evthread_make_base_notifiable
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT2_THREAD_H_INCLUDED_ */
end_comment

end_unit

