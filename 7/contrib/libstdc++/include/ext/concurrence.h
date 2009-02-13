begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Support for concurrent programing -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2003, 2004, 2005, 2006
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
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
comment|// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
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
comment|/** @file concurrence.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONCURRENCE_H
end_ifndef

begin_define
define|#
directive|define
name|_CONCURRENCE_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<exception>
end_include

begin_include
include|#
directive|include
file|<bits/gthr.h>
end_include

begin_include
include|#
directive|include
file|<bits/functexcept.h>
end_include

begin_expr_stmt
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|__gnu_cxx
argument_list|)
comment|// Available locking policies:
comment|// _S_single    single-threaded code that doesn't need to be locked.
comment|// _S_mutex     multi-threaded code that requires additional support
comment|//              from gthr.h or abstraction layers in concurrance.h.
comment|// _S_atomic    multi-threaded code using atomic operations.
expr|enum
name|_Lock_policy
block|{
name|_S_single
block|,
name|_S_mutex
block|,
name|_S_atomic
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Compile time constant that indicates prefered locking policy in
end_comment

begin_comment
comment|// the current configuration.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|_Lock_policy
name|__default_lock_policy
init|=
ifdef|#
directive|ifdef
name|__GTHREADS
comment|// NB: This macro doesn't actually exist yet in the compiler, but is
comment|// set somewhat haphazardly at configure time.
ifdef|#
directive|ifdef
name|_GLIBCXX_ATOMIC_BUILTINS
name|_S_atomic
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|_S_mutex
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|_S_single
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// NB: As this is used in libsupc++, need to only depend on
end_comment

begin_comment
comment|// exception. No stdexception classes, no use of std::string.
end_comment

begin_decl_stmt
name|class
name|__concurrence_lock_error
range|:
name|public
name|std
operator|::
name|exception
block|{
name|public
operator|:
name|virtual
name|char
specifier|const
operator|*
name|what
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
literal|"__gnu_cxx::__concurrence_lock_error"
return|;
block|}
expr|}
block|;
name|class
name|__concurrence_unlock_error
operator|:
name|public
name|std
operator|::
name|exception
block|{
name|public
operator|:
name|virtual
name|char
specifier|const
operator|*
name|what
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
literal|"__gnu_cxx::__concurrence_unlock_error"
return|;
block|}
expr|}
block|;
comment|// Substitute for concurrence_error object in the case of -fno-exceptions.
specifier|inline
name|void
name|__throw_concurrence_lock_error
argument_list|()
block|{
if|#
directive|if
name|__EXCEPTIONS
name|throw
name|__concurrence_lock_error
argument_list|()
block|;
else|#
directive|else
name|std
operator|::
name|abort
argument_list|()
block|;
endif|#
directive|endif
block|}
specifier|inline
name|void
name|__throw_concurrence_unlock_error
argument_list|()
block|{
if|#
directive|if
name|__EXCEPTIONS
name|throw
name|__concurrence_unlock_error
argument_list|()
block|;
else|#
directive|else
name|std
operator|::
name|abort
argument_list|()
block|;
endif|#
directive|endif
block|}
name|class
name|__mutex
block|{
name|private
operator|:
name|__gthread_mutex_t
name|_M_mutex
block|;
name|__mutex
argument_list|(
specifier|const
name|__mutex
operator|&
argument_list|)
block|;
name|__mutex
operator|&
name|operator
operator|=
operator|(
specifier|const
name|__mutex
operator|&
operator|)
block|;
name|public
operator|:
name|__mutex
argument_list|()
block|{
if|#
directive|if
name|__GTHREADS
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
if|#
directive|if
name|defined
name|__GTHREAD_MUTEX_INIT
name|__gthread_mutex_t
name|__tmp
init|=
name|__GTHREAD_MUTEX_INIT
decl_stmt|;
name|_M_mutex
operator|=
name|__tmp
expr_stmt|;
else|#
directive|else
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|(
operator|&
name|_M_mutex
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
endif|#
directive|endif
block|}
name|void
name|lock
argument_list|()
block|{
if|#
directive|if
name|__GTHREADS
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
if|if
condition|(
name|__gthread_mutex_lock
argument_list|(
operator|&
name|_M_mutex
argument_list|)
operator|!=
literal|0
condition|)
name|__throw_concurrence_lock_error
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
name|void
name|unlock
argument_list|()
block|{
if|#
directive|if
name|__GTHREADS
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
if|if
condition|(
name|__gthread_mutex_unlock
argument_list|(
operator|&
name|_M_mutex
argument_list|)
operator|!=
literal|0
condition|)
name|__throw_concurrence_unlock_error
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
block|}
block|;
name|class
name|__recursive_mutex
block|{
name|private
operator|:
name|__gthread_recursive_mutex_t
name|_M_mutex
block|;
name|__recursive_mutex
argument_list|(
specifier|const
name|__recursive_mutex
operator|&
argument_list|)
block|;
name|__recursive_mutex
operator|&
name|operator
operator|=
operator|(
specifier|const
name|__recursive_mutex
operator|&
operator|)
block|;
name|public
operator|:
name|__recursive_mutex
argument_list|()
block|{
if|#
directive|if
name|__GTHREADS
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
if|#
directive|if
name|defined
name|__GTHREAD_RECURSIVE_MUTEX_INIT
name|__gthread_recursive_mutex_t
name|__tmp
init|=
name|__GTHREAD_RECURSIVE_MUTEX_INIT
decl_stmt|;
name|_M_mutex
operator|=
name|__tmp
expr_stmt|;
else|#
directive|else
name|__GTHREAD_RECURSIVE_MUTEX_INIT_FUNCTION
argument_list|(
operator|&
name|_M_mutex
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
endif|#
directive|endif
block|}
name|void
name|lock
argument_list|()
block|{
if|#
directive|if
name|__GTHREADS
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
if|if
condition|(
name|__gthread_recursive_mutex_lock
argument_list|(
operator|&
name|_M_mutex
argument_list|)
operator|!=
literal|0
condition|)
name|__throw_concurrence_lock_error
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
name|void
name|unlock
argument_list|()
block|{
if|#
directive|if
name|__GTHREADS
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
if|if
condition|(
name|__gthread_recursive_mutex_unlock
argument_list|(
operator|&
name|_M_mutex
argument_list|)
operator|!=
literal|0
condition|)
name|__throw_concurrence_unlock_error
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
block|}
block|;
comment|/// @brief  Scoped lock idiom.
comment|// Acquire the mutex here with a constructor call, then release with
comment|// the destructor call in accordance with RAII style.
name|class
name|__scoped_lock
block|{
name|public
operator|:
typedef|typedef
name|__mutex
name|__mutex_type
typedef|;
name|private
operator|:
name|__mutex_type
operator|&
name|_M_device
block|;
name|__scoped_lock
argument_list|(
specifier|const
name|__scoped_lock
operator|&
argument_list|)
block|;
name|__scoped_lock
operator|&
name|operator
operator|=
operator|(
specifier|const
name|__scoped_lock
operator|&
operator|)
block|;
name|public
operator|:
name|explicit
name|__scoped_lock
argument_list|(
name|__mutex_type
operator|&
name|__name
argument_list|)
operator|:
name|_M_device
argument_list|(
argument|__name
argument_list|)
block|{
name|_M_device
operator|.
name|lock
argument_list|()
block|; }
operator|~
name|__scoped_lock
argument_list|()
name|throw
argument_list|()
block|{
name|_M_device
operator|.
name|unlock
argument_list|()
block|; }
block|}
block|;
name|_GLIBCXX_END_NAMESPACE
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

