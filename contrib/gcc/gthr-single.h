begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Threads compatibility routines for libgcc2 and libobjc.  */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 1997, 1999, 2000 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GTHR_SINGLE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GTHR_SINGLE_H
end_define

begin_comment
comment|/* Just provide compatibility for mutex handling.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|__gthread_mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__GTHREAD_MUTEX_INIT
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
value|x __attribute__((unused))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBOBJC
end_ifdef

begin_comment
comment|/* Thread local storage for a single thread */
end_comment

begin_decl_stmt
specifier|static
name|void
modifier|*
name|thread_local_storage
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Backend initialization functions */
end_comment

begin_comment
comment|/* Initialize the threads subsystem.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_init_thread_system
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* No thread support available */
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Close the threads subsystem.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_close_thread_system
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* No thread support available */
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Backend thread functions */
end_comment

begin_comment
comment|/* Create a new thread of execution.  */
end_comment

begin_function
specifier|static
specifier|inline
name|objc_thread_t
name|__gthread_objc_thread_detach
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|UNUSED
parameter_list|(
name|arg
parameter_list|)
parameter_list|)
block|{
comment|/* No thread support available */
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Set the current thread's priority.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_thread_set_priority
parameter_list|(
name|int
name|UNUSED
parameter_list|(
name|priority
parameter_list|)
parameter_list|)
block|{
comment|/* No thread support available */
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Return the current thread's priority.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_thread_get_priority
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|OBJC_THREAD_INTERACTIVE_PRIORITY
return|;
block|}
end_function

begin_comment
comment|/* Yield our process time to another thread.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|__gthread_objc_thread_yield
parameter_list|(
name|void
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/* Terminate the current thread.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_thread_exit
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* No thread support available */
comment|/* Should we really exit the program */
comment|/* exit(&__objc_thread_exit_status); */
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Returns an integer value which uniquely describes a thread.  */
end_comment

begin_function
specifier|static
specifier|inline
name|objc_thread_t
name|__gthread_objc_thread_id
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* No thread support, use 1.  */
return|return
operator|(
name|objc_thread_t
operator|)
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Sets the thread's local storage pointer.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_thread_set_data
parameter_list|(
name|void
modifier|*
name|value
parameter_list|)
block|{
name|thread_local_storage
operator|=
name|value
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Returns the thread's local storage pointer.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|__gthread_objc_thread_get_data
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|thread_local_storage
return|;
block|}
end_function

begin_comment
comment|/* Backend mutex functions */
end_comment

begin_comment
comment|/* Allocate a mutex.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_mutex_allocate
parameter_list|(
name|objc_mutex_t
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Deallocate a mutex.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_mutex_deallocate
parameter_list|(
name|objc_mutex_t
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Grab a lock on a mutex.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_mutex_lock
parameter_list|(
name|objc_mutex_t
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
comment|/* There can only be one thread, so we always get the lock */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Try to grab a lock on a mutex.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_mutex_trylock
parameter_list|(
name|objc_mutex_t
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
comment|/* There can only be one thread, so we always get the lock */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Unlock the mutex */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_mutex_unlock
parameter_list|(
name|objc_mutex_t
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Backend condition mutex functions */
end_comment

begin_comment
comment|/* Allocate a condition.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_allocate
parameter_list|(
name|objc_condition_t
name|UNUSED
parameter_list|(
name|condition
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Deallocate a condition.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_deallocate
parameter_list|(
name|objc_condition_t
name|UNUSED
parameter_list|(
name|condition
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Wait on the condition */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_wait
parameter_list|(
name|objc_condition_t
name|UNUSED
parameter_list|(
name|condition
parameter_list|)
parameter_list|,
name|objc_mutex_t
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Wake up all threads waiting on this condition.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_broadcast
parameter_list|(
name|objc_condition_t
name|UNUSED
parameter_list|(
name|condition
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Wake up one thread waiting on this condition.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_signal
parameter_list|(
name|objc_condition_t
name|UNUSED
parameter_list|(
name|condition
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _LIBOBJC */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_active_p
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_mutex_lock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_mutex_trylock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_mutex_unlock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBOBJC */
end_comment

begin_undef
undef|#
directive|undef
name|UNUSED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_GTHR_SINGLE_H */
end_comment

end_unit

