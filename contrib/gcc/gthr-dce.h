begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__gthr_dce_h
end_ifndef

begin_define
define|#
directive|define
name|__gthr_dce_h
end_define

begin_comment
comment|/* DCE threads interface.    DCE threads are based on POSIX threads draft 4, and many things    have changed since then. */
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

begin_comment
comment|/* Howto define __GTHREAD_MUTEX_INIT? */
end_comment

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
name|pthread_key_create
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

begin_decl_stmt
specifier|static
name|void
modifier|*
name|__gthread_active_ptr
init|=
operator|&
name|pthread_create
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_active_p
parameter_list|()
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
parameter_list|()
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
parameter_list|()
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
comment|/* Nothing needed. */
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_key_delete
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|)
block|{
return|return
name|pthread_key_delete
argument_list|(
name|key
argument_list|)
return|;
block|}
end_function

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
comment|/* not __gthr_dce_h */
end_comment

end_unit

