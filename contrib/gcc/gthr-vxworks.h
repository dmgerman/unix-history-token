begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Threads compatibility routines for libgcc2 and libobjc for VxWorks.  */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 1997, 1999, 2000 Free Software Foundation, Inc.    Contributed by Mike Stump<mrs@wrs.com>.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GTHR_VXWORKS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GTHR_VXWORKS_H
end_define

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
name|arg
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
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
name|int
name|__gthread_objc_thread_set_priority
parameter_list|(
name|int
name|priority
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
name|int
name|__gthread_objc_mutex_allocate
parameter_list|(
name|objc_mutex_t
name|mutex
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
name|int
name|__gthread_objc_mutex_deallocate
parameter_list|(
name|objc_mutex_t
name|mutex
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
name|int
name|__gthread_objc_mutex_lock
parameter_list|(
name|objc_mutex_t
name|mutex
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
name|int
name|__gthread_objc_mutex_trylock
parameter_list|(
name|objc_mutex_t
name|mutex
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
name|int
name|__gthread_objc_mutex_unlock
parameter_list|(
name|objc_mutex_t
name|mutex
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
name|int
name|__gthread_objc_condition_allocate
parameter_list|(
name|objc_condition_t
name|condition
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
name|int
name|__gthread_objc_condition_deallocate
parameter_list|(
name|objc_condition_t
name|condition
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
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Wake up all threads waiting on this condition.  */
end_comment

begin_function
name|int
name|__gthread_objc_condition_broadcast
parameter_list|(
name|objc_condition_t
name|condition
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
name|int
name|__gthread_objc_condition_signal
parameter_list|(
name|objc_condition_t
name|condition
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

begin_comment
comment|/* POSIX threads specific definitions.    Easy, since the interface is just one-to-one mapping.  */
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
file|<vxWorks.h>
end_include

begin_include
include|#
directive|include
file|<semLib.h>
end_include

begin_comment
comment|/* typedef void *SEM_ID; */
end_comment

begin_typedef
typedef|typedef
name|int
name|__gthread_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|__gthread_once_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SEM_ID
name|__gthread_mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__GTHREAD_MUTEX_INIT
value|0
end_define

begin_define
define|#
directive|define
name|__GTHREAD_ONCE_INIT
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|REG_SAVED_REG
end_ifndef

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
call|(
modifier|*
name|func
call|)
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|__gthread_key_t
name|eh_context_key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is not the right way to do it, but the semantic of pthreads    don't map well enough onto VxWorks.  */
end_comment

begin_function
specifier|static
name|void
name|__ehdtor
parameter_list|(
name|void
modifier|*
name|pTcb
parameter_list|)
block|{
name|int
name|tid
init|=
operator|(
name|int
operator|)
name|pTcb
decl_stmt|;
name|void
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
name|taskVarGet
argument_list|(
name|tid
argument_list|,
operator|&
name|eh_context_key
argument_list|)
decl_stmt|;
if|if
condition|(
name|p
operator|!=
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|p
condition|)
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|taskVarSet
argument_list|(
name|tid
argument_list|,
operator|&
name|eh_context_key
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* This only works for the code in libgcc2.c.  */
end_comment

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
operator|*
name|key
operator|=
literal|0
expr_stmt|;
comment|/* Do this first so that the task variables are visible during the      running of the delete hook.  */
name|taskVarInit
argument_list|()
expr_stmt|;
comment|/* We don't have a way to track dtor here, so instead, we      register a generic routine that can cleanup any task.  */
name|taskDeleteHookAdd
argument_list|(
name|__ehdtor
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__gthread_setspecific
parameter_list|(
name|key
parameter_list|,
name|ptr
parameter_list|)
define|\
value|(key = (int) ptr, 0)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_key_dtor
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
block|{
comment|/* Just reset the key value to zero.  */
if|if
condition|(
name|ptr
condition|)
return|return
name|__gthread_setspecific
argument_list|(
name|key
argument_list|,
literal|0
argument_list|)
return|;
else|else
return|return
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__gthread_key_delete
parameter_list|(
name|key
parameter_list|)
define|\
value|taskVarDelete (taskIdSelf (),&key)
end_define

begin_define
define|#
directive|define
name|__gthread_getspecific
parameter_list|(
name|key
parameter_list|)
define|\
value|((key == 0)					\       ? ((taskVarAdd (taskIdSelf (),&key) != OK)	\ 	 ? (__terminate (), (void*)0)			\ 	 : (void*)0)					\       : (void*)key)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
operator|*
name|mutex
operator|==
literal|0
condition|)
operator|*
name|mutex
operator|=
name|semMCreate
argument_list|(
name|SEM_Q_PRIORITY
operator||
name|SEM_INVERSION_SAFE
operator||
name|SEM_DELETE_SAFE
argument_list|)
expr_stmt|;
return|return
name|semTake
argument_list|(
operator|*
name|mutex
argument_list|,
name|WAIT_FOREVER
argument_list|)
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
operator|*
name|mutex
operator|==
literal|0
condition|)
operator|*
name|mutex
operator|=
name|semMCreate
argument_list|(
name|SEM_Q_PRIORITY
operator||
name|SEM_INVERSION_SAFE
operator||
name|SEM_DELETE_SAFE
argument_list|)
expr_stmt|;
return|return
name|semTake
argument_list|(
operator|*
name|mutex
argument_list|,
name|NO_WAIT
argument_list|)
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
comment|/* We could return the */
return|return
name|semGive
argument_list|(
operator|*
name|mutex
argument_list|)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_GTHR_VXWORKS_H */
end_comment

end_unit

