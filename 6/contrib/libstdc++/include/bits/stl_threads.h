begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Threading support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|/*  * Copyright (c) 1997-1999  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_threads.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STL_THREADS_H
end_ifndef

begin_define
define|#
directive|define
name|_STL_THREADS_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_comment
comment|// The only supported threading model is GCC's own gthr.h abstraction
end_comment

begin_comment
comment|// layer.
end_comment

begin_include
include|#
directive|include
file|"bits/gthr.h"
end_include

begin_decl_stmt
name|namespace
name|__gnu_internal
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|)
specifier|extern
name|__gthread_mutex_t
name|_GLIBCXX_mutex
decl_stmt|;
specifier|extern
name|__gthread_mutex_t
modifier|*
name|_GLIBCXX_mutex_address
decl_stmt|;
specifier|extern
name|__gthread_once_t
name|_GLIBCXX_once
decl_stmt|;
specifier|extern
name|void
name|_GLIBCXX_mutex_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_GLIBCXX_mutex_address_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|// namespace __gnu_internal
end_comment

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
comment|// Locking class.  Note that this class *does not have a
comment|// constructor*.  It must be initialized either statically, with
comment|// __STL_MUTEX_INITIALIZER, or dynamically, by explicitly calling
comment|// the _M_initialize member function.  (This is similar to the ways
comment|// that a pthreads mutex can be initialized.)  There are explicit
comment|// member functions for acquiring and releasing the lock.
comment|// There is no constructor because static initialization is
comment|// essential for some uses, and only a class aggregate (see section
comment|// 8.5.1 of the C++ standard) can be initialized that way.  That
comment|// means we must have no constructors, no base classes, no virtual
comment|// functions, and no private or protected members.
struct|struct
name|_STL_mutex_lock
block|{
comment|// The class must be statically initialized with __STL_MUTEX_INITIALIZER.
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|)
specifier|volatile
name|int
name|_M_init_flag
decl_stmt|;
name|__gthread_once_t
name|_M_once
decl_stmt|;
endif|#
directive|endif
name|__gthread_mutex_t
name|_M_lock
decl_stmt|;
name|void
name|_M_initialize
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|__GTHREAD_MUTEX_INIT
comment|// There should be no code in this path given the usage rules above.
elif|#
directive|elif
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|)
if|if
condition|(
name|_M_init_flag
condition|)
return|return;
if|if
condition|(
name|__gthread_once
argument_list|(
operator|&
name|__gnu_internal
operator|::
name|_GLIBCXX_once
argument_list|,
name|__gnu_internal
operator|::
name|_GLIBCXX_mutex_init
argument_list|)
operator|!=
literal|0
operator|&&
name|__gthread_active_p
argument_list|()
condition|)
name|abort
argument_list|()
expr_stmt|;
name|__gthread_mutex_lock
argument_list|(
operator|&
name|__gnu_internal
operator|::
name|_GLIBCXX_mutex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|_M_init_flag
condition|)
block|{
comment|// Even though we have a global lock, we use __gthread_once to be
comment|// absolutely certain the _M_lock mutex is only initialized once on
comment|// multiprocessor systems.
name|__gnu_internal
operator|::
name|_GLIBCXX_mutex_address
operator|=
operator|&
name|_M_lock
expr_stmt|;
if|if
condition|(
name|__gthread_once
argument_list|(
operator|&
name|_M_once
argument_list|,
name|__gnu_internal
operator|::
name|_GLIBCXX_mutex_address_init
argument_list|)
operator|!=
literal|0
operator|&&
name|__gthread_active_p
argument_list|()
condition|)
name|abort
argument_list|()
expr_stmt|;
name|_M_init_flag
operator|=
literal|1
expr_stmt|;
block|}
name|__gthread_mutex_unlock
argument_list|(
operator|&
name|__gnu_internal
operator|::
name|_GLIBCXX_mutex
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|void
name|_M_acquire_lock
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|)
if|if
condition|(
operator|!
name|_M_init_flag
condition|)
name|_M_initialize
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|__gthread_mutex_lock
argument_list|(
operator|&
name|_M_lock
argument_list|)
expr_stmt|;
block|}
name|void
name|_M_release_lock
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|)
if|if
condition|(
operator|!
name|_M_init_flag
condition|)
name|_M_initialize
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|__gthread_mutex_unlock
argument_list|(
operator|&
name|_M_lock
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
ifdef|#
directive|ifdef
name|__GTHREAD_MUTEX_INIT
define|#
directive|define
name|__STL_MUTEX_INITIALIZER
value|= { __GTHREAD_MUTEX_INIT }
elif|#
directive|elif
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|)
ifdef|#
directive|ifdef
name|__GTHREAD_MUTEX_INIT_DEFAULT
define|#
directive|define
name|__STL_MUTEX_INITIALIZER
define|\
value|= { 0, __GTHREAD_ONCE_INIT, __GTHREAD_MUTEX_INIT_DEFAULT }
else|#
directive|else
define|#
directive|define
name|__STL_MUTEX_INITIALIZER
value|= { 0, __GTHREAD_ONCE_INIT }
endif|#
directive|endif
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|// namespace __gnu_cxx
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

