begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective C Runtime Thread Interface - OS/2 emx Implementation    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Thomas Baier (baier@ci.tuwien.ac.at)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|INCL_DOSSEMAPHORES
end_define

begin_define
define|#
directive|define
name|INCL_DOSPROCESS
end_define

begin_comment
comment|/*  * conflicts with objc.h:       SEL, BOOL, id  * solution:  prefixing those with _OS2_ before including<os2.h>  */
end_comment

begin_define
define|#
directive|define
name|SEL
value|_OS2_SEL
end_define

begin_define
define|#
directive|define
name|BOOL
value|_OS2_BOOL
end_define

begin_define
define|#
directive|define
name|id
value|_OS2_id
end_define

begin_include
include|#
directive|include
file|<os2.h>
end_include

begin_undef
undef|#
directive|undef
name|id
end_undef

begin_undef
undef|#
directive|undef
name|SEL
end_undef

begin_undef
undef|#
directive|undef
name|BOOL
end_undef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

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
name|int
name|thread_id
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|thread_id
operator|=
name|_beginthread
argument_list|(
name|func
argument_list|,
name|NULL
argument_list|,
literal|32768
argument_list|,
name|arg
argument_list|)
operator|)
operator|<
literal|0
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
name|ULONG
name|sys_class
init|=
literal|0
decl_stmt|;
name|ULONG
name|sys_priority
init|=
literal|0
decl_stmt|;
comment|/* OBJC_THREAD_INTERACTIVE_PRIORITY -> PRTYC_FOREGROUNDSERVER    * OBJC_THREAD_BACKGROUND_PRIORITY  -> PRTYC_REGULAR    * OBJC_THREAD_LOW_PRIORITY         -> PRTYC_IDLETIME */
switch|switch
condition|(
name|priority
condition|)
block|{
case|case
name|OBJC_THREAD_INTERACTIVE_PRIORITY
case|:
name|sys_class
operator|=
name|PRTYC_REGULAR
expr_stmt|;
name|sys_priority
operator|=
literal|10
expr_stmt|;
break|break;
default|default:
case|case
name|OBJC_THREAD_BACKGROUND_PRIORITY
case|:
name|sys_class
operator|=
name|PRTYC_IDLETIME
expr_stmt|;
name|sys_priority
operator|=
literal|25
expr_stmt|;
break|break;
case|case
name|OBJC_THREAD_LOW_PRIORITY
case|:
name|sys_class
operator|=
name|PRTYC_IDLETIME
expr_stmt|;
name|sys_priority
operator|=
literal|0
expr_stmt|;
break|break;
block|}
comment|/* Change priority */
if|if
condition|(
operator|!
name|DosSetPriority
argument_list|(
name|PRTYS_THREAD
argument_list|,
name|sys_class
argument_list|,
name|sys_priority
argument_list|,
operator|*
name|_threadid
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
name|PTIB
name|ptib
decl_stmt|;
name|PPIB
name|ppib
decl_stmt|;
comment|/* get information about current thread */
name|DosGetInfoBlocks
argument_list|(
operator|&
name|ptib
argument_list|,
operator|&
name|ppib
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ptib
operator|->
name|tib_ptib2
operator|->
name|tib2_ulpri
condition|)
block|{
case|case
name|PRTYC_IDLETIME
case|:
case|case
name|PRTYC_REGULAR
case|:
case|case
name|PRTYC_TIMECRITICAL
case|:
case|case
name|PRTYC_FOREGROUNDSERVER
case|:
default|default:
return|return
name|OBJC_THREAD_INTERACTIVE_PRIORITY
return|;
block|}
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
name|DosSleep
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
comment|/* terminate the thread, NEVER use DosExit () */
name|_endthread
argument_list|()
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
operator|*
name|_threadid
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
name|_threadstore
argument_list|()
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
name|_threadstore
argument_list|()
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
name|DosCreateMutexSem
argument_list|(
name|NULL
argument_list|,
call|(
name|HMTX
call|)
argument_list|(
operator|&
operator|(
name|mutex
operator|->
name|backend
operator|)
argument_list|)
argument_list|,
literal|0L
argument_list|,
literal|0
argument_list|)
operator|>
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
name|DosCloseMutexSem
argument_list|(
call|(
name|HMTX
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
if|if
condition|(
name|DosRequestMutexSem
argument_list|(
call|(
name|HMTX
call|)
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
argument_list|,
operator|-
literal|1L
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
name|DosRequestMutexSem
argument_list|(
call|(
name|HMTX
call|)
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
argument_list|,
literal|0L
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
name|DosReleaseMutexSem
argument_list|(
call|(
name|HMTX
call|)
argument_list|(
name|mutex
operator|->
name|backend
argument_list|)
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

