begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Thread and mutex controls for Objective C.    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Galen C. Hunt (gchunt@cs.rochester.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__thread_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__thread_INCLUDE_GNU
end_define

begin_include
include|#
directive|include
file|"objc/objc.h"
end_include

begin_comment
comment|/*************************************************************************  *  Universal static variables:  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__objc_thread_exit_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global exit status.   */
end_comment

begin_comment
comment|/********  *  Thread safe implementation types and functions.    */
end_comment

begin_comment
comment|/* Thread priorities */
end_comment

begin_define
define|#
directive|define
name|OBJC_THREAD_INTERACTIVE_PRIORITY
value|2
end_define

begin_define
define|#
directive|define
name|OBJC_THREAD_BACKGROUND_PRIORITY
value|1
end_define

begin_define
define|#
directive|define
name|OBJC_THREAD_LOW_PRIORITY
value|0
end_define

begin_comment
comment|/* A thread */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|objc_thread_t
typedef|;
end_typedef

begin_comment
comment|/* This structure represents a single mutual exclusion lock. */
end_comment

begin_struct
struct|struct
name|objc_mutex
block|{
specifier|volatile
name|objc_thread_t
name|owner
decl_stmt|;
comment|/* Id of thread that owns. */
specifier|volatile
name|int
name|depth
decl_stmt|;
comment|/* # of acquires. */
name|void
modifier|*
name|backend
decl_stmt|;
comment|/* Specific to backend */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|objc_mutex
modifier|*
name|objc_mutex_t
typedef|;
end_typedef

begin_comment
comment|/* This structure represents a single condition mutex */
end_comment

begin_struct
struct|struct
name|objc_condition
block|{
name|void
modifier|*
name|backend
decl_stmt|;
comment|/* Specific to backend */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|objc_condition
modifier|*
name|objc_condition_t
typedef|;
end_typedef

begin_comment
comment|/* Frontend mutex functions */
end_comment

begin_function_decl
name|objc_mutex_t
name|objc_mutex_allocate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_mutex_deallocate
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_mutex_lock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_mutex_unlock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_mutex_trylock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Frontend condition mutex functions */
end_comment

begin_function_decl
name|objc_condition_t
name|objc_condition_allocate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_condition_deallocate
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_condition_wait
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|,
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_condition_signal
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_condition_broadcast
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Frontend thread functions */
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_thread_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_thread_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_thread_set_priority
parameter_list|(
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_thread_get_priority
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|objc_thread_get_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_thread_set_data
parameter_list|(
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|objc_thread_t
name|objc_thread_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   Use this to set the hook function that will be called when the    runtime initially becomes multi threaded.   The hook function is only called once, meaning only when the    2nd thread is spawned, not for each and every thread.    It returns the previous hook function or NULL if there is none.    A program outside of the runtime could set this to some function so   it can be informed; for example, the GNUstep Base Library sets it    so it can implement the NSBecomingMultiThreaded notification.   */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|objc_thread_callback
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
name|objc_thread_callback
name|objc_set_thread_callback
parameter_list|(
name|objc_thread_callback
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Backend initialization functions */
end_comment

begin_function_decl
name|int
name|__objc_init_thread_system
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_fini_thread_system
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Backend mutex functions */
end_comment

begin_function_decl
name|int
name|__objc_mutex_allocate
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_mutex_deallocate
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_mutex_lock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_mutex_trylock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_mutex_unlock
parameter_list|(
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Backend condition mutex functions */
end_comment

begin_function_decl
name|int
name|__objc_condition_allocate
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_condition_deallocate
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_condition_wait
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|,
name|objc_mutex_t
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_condition_broadcast
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_condition_signal
parameter_list|(
name|objc_condition_t
name|condition
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Backend thread functions */
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_thread_set_priority
parameter_list|(
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_thread_get_priority
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__objc_thread_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_thread_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|objc_thread_t
name|__objc_thread_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__objc_thread_set_data
parameter_list|(
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|__objc_thread_get_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __thread_INCLUDE_GNU */
end_comment

end_unit

