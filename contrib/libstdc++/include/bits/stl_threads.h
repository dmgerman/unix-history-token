begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Threading support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002 Free Software Foundation, Inc.
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
name|__SGI_STL_INTERNAL_THREADS_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_INTERNAL_THREADS_H
end_define

begin_comment
comment|// The only supported threading model is GCC's own gthr.h abstraction layer.
end_comment

begin_include
include|#
directive|include
file|"bits/gthr.h"
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// Class _Refcount_Base provides a type, _RC_t, a data member,
comment|// _M_ref_count, and member functions _M_incr and _M_decr, which perform
comment|// atomic preincrement/predecrement.  The constructor initializes
comment|// _M_ref_count.
struct|struct
name|_Refcount_Base
block|{
comment|// The type _RC_t
typedef|typedef
name|size_t
name|_RC_t
typedef|;
comment|// The data member _M_ref_count
specifier|volatile
name|_RC_t
name|_M_ref_count
decl_stmt|;
comment|// Constructor
name|__gthread_mutex_t
name|_M_ref_count_lock
decl_stmt|;
name|_Refcount_Base
argument_list|(
argument|_RC_t __n
argument_list|)
block|:
name|_M_ref_count
argument_list|(
argument|__n
argument_list|)
block|{
ifdef|#
directive|ifdef
name|__GTHREAD_MUTEX_INIT
name|__gthread_mutex_t
name|__tmp
init|=
name|__GTHREAD_MUTEX_INIT
decl_stmt|;
name|_M_ref_count_lock
operator|=
name|__tmp
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|)
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|(
operator|&
name|_M_ref_count_lock
argument_list|)
expr_stmt|;
else|#
directive|else
error|#
directive|error
error|__GTHREAD_MUTEX_INIT or __GTHREAD_MUTEX_INIT_FUNCTION should be defined by gthr.h abstraction layer, report problem to libstdc++@gcc.gnu.org.
endif|#
directive|endif
block|}
name|void
name|_M_incr
parameter_list|()
block|{
name|__gthread_mutex_lock
argument_list|(
operator|&
name|_M_ref_count_lock
argument_list|)
expr_stmt|;
operator|++
name|_M_ref_count
expr_stmt|;
name|__gthread_mutex_unlock
argument_list|(
operator|&
name|_M_ref_count_lock
argument_list|)
expr_stmt|;
block|}
name|_RC_t
name|_M_decr
parameter_list|()
block|{
name|__gthread_mutex_lock
argument_list|(
operator|&
name|_M_ref_count_lock
argument_list|)
expr_stmt|;
specifier|volatile
name|_RC_t
name|__tmp
init|=
operator|--
name|_M_ref_count
decl_stmt|;
name|__gthread_mutex_unlock
argument_list|(
operator|&
name|_M_ref_count_lock
argument_list|)
expr_stmt|;
return|return
name|__tmp
return|;
block|}
block|}
struct|;
comment|// Atomic swap on unsigned long
comment|// This is guaranteed to behave as though it were atomic only if all
comment|// possibly concurrent updates use _Atomic_swap.
comment|// In some cases the operation is emulated with a lock.
if|#
directive|if
name|defined
argument_list|(
name|__GTHREAD_MUTEX_INIT
argument_list|)
comment|// This could be optimized to use the atomicity.h abstraction layer.
comment|// vyzo: simple _Atomic_swap implementation following the guidelines above
comment|// We use a template here only to get a unique initialized instance.
name|template
operator|<
name|int
name|__dummy
operator|>
expr|struct
name|_Swap_lock_struct
block|{
specifier|static
name|__gthread_mutex_t
name|_S_swap_lock
block|; }
expr_stmt|;
name|template
operator|<
name|int
name|__dummy
operator|>
name|__gthread_mutex_t
name|_Swap_lock_struct
operator|<
name|__dummy
operator|>
operator|::
name|_S_swap_lock
operator|=
name|__GTHREAD_MUTEX_INIT
expr_stmt|;
comment|// This should be portable, but performance is expected to be quite
comment|// awful.  This really needs platform specific code.
specifier|inline
name|unsigned
name|long
name|_Atomic_swap
parameter_list|(
name|unsigned
name|long
modifier|*
name|__p
parameter_list|,
name|unsigned
name|long
name|__q
parameter_list|)
block|{
name|__gthread_mutex_lock
argument_list|(
operator|&
name|_Swap_lock_struct
operator|<
literal|0
operator|>
operator|::
name|_S_swap_lock
argument_list|)
expr_stmt|;
name|unsigned
name|long
name|__result
init|=
operator|*
name|__p
decl_stmt|;
operator|*
name|__p
operator|=
name|__q
expr_stmt|;
name|__gthread_mutex_unlock
argument_list|(
operator|&
name|_Swap_lock_struct
operator|<
literal|0
operator|>
operator|::
name|_S_swap_lock
argument_list|)
expr_stmt|;
return|return
name|__result
return|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|//namespace std
end_comment

begin_comment
comment|// Locking class.  Note that this class *does not have a
end_comment

begin_comment
comment|// constructor*.  It must be initialized either statically, with
end_comment

begin_comment
comment|// __STL_MUTEX_INITIALIZER, or dynamically, by explicitly calling
end_comment

begin_comment
comment|// the _M_initialize member function.  (This is similar to the ways
end_comment

begin_comment
comment|// that a pthreads mutex can be initialized.)  There are explicit
end_comment

begin_comment
comment|// member functions for acquiring and releasing the lock.
end_comment

begin_comment
comment|// There is no constructor because static initialization is
end_comment

begin_comment
comment|// essential for some uses, and only a class aggregate (see section
end_comment

begin_comment
comment|// 8.5.1 of the C++ standard) can be initialized that way.  That
end_comment

begin_comment
comment|// means we must have no constructors, no base classes, no virtual
end_comment

begin_comment
comment|// functions, and no private or protected members.
end_comment

begin_if
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
end_if

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
specifier|extern
name|__gthread_mutex_t
name|_GLIBCPP_mutex
decl_stmt|;
specifier|extern
name|__gthread_mutex_t
modifier|*
name|_GLIBCPP_mutex_address
decl_stmt|;
specifier|extern
name|__gthread_once_t
name|_GLIBCPP_once
decl_stmt|;
specifier|extern
name|void
name|_GLIBCPP_mutex_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_GLIBCPP_mutex_address_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|std
block|{
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
name|__gnu_cxx
operator|::
name|_GLIBCPP_once
argument_list|,
name|__gnu_cxx
operator|::
name|_GLIBCPP_mutex_init
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
name|__gnu_cxx
operator|::
name|_GLIBCPP_mutex
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
name|__gnu_cxx
operator|::
name|_GLIBCPP_mutex_address
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
name|__gnu_cxx
operator|::
name|_GLIBCPP_mutex_address_init
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
name|__gnu_cxx
operator|::
name|_GLIBCPP_mutex
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
comment|// A locking class that uses _STL_mutex_lock.  The constructor takes a
comment|// reference to an _STL_mutex_lock, and acquires a lock.  The
comment|// destructor releases the lock.  It's not clear that this is exactly
comment|// the right functionality.  It will probably change in the future.
struct|struct
name|_STL_auto_lock
block|{
name|_STL_mutex_lock
modifier|&
name|_M_lock
decl_stmt|;
name|_STL_auto_lock
argument_list|(
name|_STL_mutex_lock
operator|&
name|__lock
argument_list|)
operator|:
name|_M_lock
argument_list|(
argument|__lock
argument_list|)
block|{
name|_M_lock
operator|.
name|_M_acquire_lock
argument_list|()
block|; }
operator|~
name|_STL_auto_lock
argument_list|()
block|{
name|_M_lock
operator|.
name|_M_release_lock
argument_list|()
block|; }
name|private
operator|:
name|void
name|operator
operator|=
operator|(
specifier|const
name|_STL_auto_lock
operator|&
operator|)
expr_stmt|;
name|_STL_auto_lock
argument_list|(
specifier|const
name|_STL_auto_lock
operator|&
argument_list|)
expr_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

