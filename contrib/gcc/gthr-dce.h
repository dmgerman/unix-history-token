begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 1997, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GTHR_DCE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GTHR_DCE_H
end_define

begin_comment
comment|/* If _DCE_THREADS is not defined, then we're building the single    threaded version of the libraries and do not want to reference    anything related to pthreads or dce.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DCE_THREADS
end_ifndef

begin_include
include|#
directive|include
file|"gthr-single.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DCE threads interface.    DCE threads are based on POSIX threads draft 4, and many things    have changed since then.  */
end_comment

begin_define
define|#
directive|define
name|__GTHREADS
value|1
end_define

begin_include
include|#
directive|include
file|<pthread.h>
end_include

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
value|x
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

begin_typedef
typedef|typedef
name|pthread_key_t
name|__gthread_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_once_t
name|__gthread_once_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|__gthread_mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__GTHREAD_ONCE_INIT
value|pthread_once_init
end_define

begin_define
define|#
directive|define
name|__GTHREAD_MUTEX_INIT_FUNCTION
value|__gthread_mutex_init_function
end_define

begin_define
define|#
directive|define
name|__GTHREAD_MUTEX_INIT_DEFAULT
value|pthread_once_init
end_define

begin_if
if|#
directive|if
name|SUPPORTS_WEAK
operator|&&
name|GTHREAD_USE_WEAK
end_if

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_once
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_once_init
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_keycreate
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_key_delete
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_getspecific
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_setspecific
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_create
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_mutex_init
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_mutex_lock
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_mutex_trylock
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_mutex_unlock
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBOBJC
end_ifdef

begin_comment
comment|/* Objective C.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_cond_broadcast
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_cond_destroy
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_cond_init
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_cond_signal
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_cond_wait
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_exit
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_getunique_np
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_mutex_destroy
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_self
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|pthread_yield
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|void
modifier|*
name|__gthread_active_ptr
init|=
operator|(
name|void
operator|*
operator|)
operator|&
name|pthread_create
decl_stmt|;
end_decl_stmt

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
name|__gthread_active_ptr
operator|!=
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not SUPPORTS_WEAK */
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
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUPPORTS_WEAK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBOBJC
end_ifdef

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
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
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
else|else
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
if|if
condition|(
name|__gthread_active_p
argument_list|()
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
operator|!
name|__gthread_active_p
argument_list|()
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|!
operator|(
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
operator|)
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
comment|/* Fully detach thread.  */
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
comment|/* Set the current thread's priority.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_thread_set_priority
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
if|if
condition|(
operator|!
name|__gthread_active_p
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
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
comment|/* Change the priority.  */
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
name|int
name|sys_priority
decl_stmt|;
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
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
else|else
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
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
name|pthread_yield
argument_list|()
expr_stmt|;
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
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
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
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
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
else|else
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
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
return|return
name|pthread_setspecific
argument_list|(
name|_objc_thread_storage
argument_list|,
name|value
argument_list|)
return|;
else|else
block|{
name|thread_local_storage
operator|=
name|value
expr_stmt|;
return|return
literal|0
return|;
block|}
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
name|void
modifier|*
name|value
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
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
else|else
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
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
name|mutex
operator|->
name|backend
operator|=
name|objc_malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|pthread_mutex_t
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|pthread_mutex_init
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
name|mutex
operator|->
name|backend
argument_list|,
name|pthread_mutexattr_default
argument_list|)
condition|)
block|{
name|objc_free
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
expr_stmt|;
name|mutex
operator|->
name|backend
operator|=
name|NULL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
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
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
name|mutex
operator|->
name|backend
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
name|objc_free
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
expr_stmt|;
name|mutex
operator|->
name|backend
operator|=
name|NULL
expr_stmt|;
block|}
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
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
return|return
name|pthread_mutex_lock
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
name|mutex
operator|->
name|backend
argument_list|)
return|;
else|else
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
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
operator|&&
name|pthread_mutex_trylock
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
name|mutex
operator|->
name|backend
argument_list|)
operator|!=
literal|1
condition|)
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
comment|/* Unlock the mutex */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_mutex_unlock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
return|return
name|pthread_mutex_unlock
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
name|mutex
operator|->
name|backend
argument_list|)
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
comment|/* Allocate a condition.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_allocate
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
comment|/* Unimplemented.  */
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
comment|/* Deallocate a condition.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_deallocate
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
comment|/* Unimplemented.  */
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
comment|/* Wait on the condition */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_wait
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|,
name|objc_mutex_t
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
comment|/* Unimplemented.  */
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
comment|/* Wake up all threads waiting on this condition.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_broadcast
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
comment|/* Unimplemented.  */
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
comment|/* Wake up one thread waiting on this condition.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_objc_condition_signal
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
comment|/* Unimplemented.  */
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
name|__gthread_once
parameter_list|(
name|__gthread_once_t
modifier|*
name|once
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
return|return
name|pthread_once
argument_list|(
name|once
argument_list|,
name|func
argument_list|)
return|;
else|else
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_key_create
parameter_list|(
name|__gthread_key_t
modifier|*
name|key
parameter_list|,
name|void
function_decl|(
modifier|*
name|dtor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
return|return
name|pthread_keycreate
argument_list|(
name|key
argument_list|,
name|dtor
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|__gthread_key_dtor
argument_list|(
name|UNUSED
argument_list|(
argument|__gthread_key_t key
argument_list|)
argument_list|,
name|UNUSED
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
argument_list|)
block|{
comment|/* Nothing needed.  */
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|__gthread_key_delete
argument_list|(
name|UNUSED
argument_list|(
argument|__gthread_key_t key
argument_list|)
argument_list|)
block|{
comment|/* Operation is not supported.  */
return|return
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|__gthread_getspecific
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|)
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
name|pthread_getspecific
argument_list|(
name|key
argument_list|,
operator|&
name|ptr
argument_list|)
operator|==
literal|0
condition|)
return|return
name|ptr
return|;
else|else
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_setspecific
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|pthread_setspecific
argument_list|(
name|key
argument_list|,
operator|(
name|void
operator|*
operator|)
name|ptr
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|__gthread_mutex_init_function
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
name|pthread_mutex_init
argument_list|(
name|mutex
argument_list|,
name|pthread_mutexattr_default
argument_list|)
expr_stmt|;
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
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
return|return
name|pthread_mutex_lock
argument_list|(
name|mutex
argument_list|)
return|;
else|else
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
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
return|return
name|pthread_mutex_trylock
argument_list|(
name|mutex
argument_list|)
return|;
else|else
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
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
return|return
name|pthread_mutex_unlock
argument_list|(
name|mutex
argument_list|)
return|;
else|else
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_GTHR_DCE_H */
end_comment

end_unit

