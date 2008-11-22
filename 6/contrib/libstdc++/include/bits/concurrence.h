begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Support for concurrent programing -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2003, 2004
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

begin_comment
comment|// GCC's thread abstraction layer
end_comment

begin_include
include|#
directive|include
file|"bits/gthr.h"
end_include

begin_if
if|#
directive|if
name|__GTHREADS
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__GTHREAD_MUTEX_INIT
end_ifdef

begin_define
define|#
directive|define
name|__glibcxx_mutex_type
value|__gthread_mutex_t
end_define

begin_define
define|#
directive|define
name|__glibcxx_mutex_define_initialized
parameter_list|(
name|NAME
parameter_list|)
define|\
value|__gthread_mutex_t NAME = __GTHREAD_MUTEX_INIT
end_define

begin_define
define|#
directive|define
name|__glibcxx_mutex_lock
parameter_list|(
name|NAME
parameter_list|)
define|\
value|__gthread_mutex_lock(&NAME)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Implies __GTHREAD_MUTEX_INIT_FUNCTION
end_comment

begin_decl_stmt
name|struct
name|__glibcxx_mutex
range|:
name|public
name|__gthread_mutex_t
block|{
name|__glibcxx_mutex
argument_list|()
block|{
name|__GTHREAD_MUTEX_INIT_FUNCTION
argument_list|(
name|this
argument_list|)
block|; }
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__glibcxx_mutex_type
value|__glibcxx_mutex
end_define

begin_define
define|#
directive|define
name|__glibcxx_mutex_define_initialized
parameter_list|(
name|NAME
parameter_list|)
define|\
value|__glibcxx_mutex NAME
end_define

begin_define
define|#
directive|define
name|__glibcxx_mutex_lock
parameter_list|(
name|NAME
parameter_list|)
define|\
value|__gthread_mutex_lock(&NAME)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__glibcxx_mutex_unlock
parameter_list|(
name|NAME
parameter_list|)
value|__gthread_mutex_unlock(&NAME)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__glibcxx_mutex_type
value|__gthread_mutex_t
end_define

begin_define
define|#
directive|define
name|__glibcxx_mutex_define_initialized
parameter_list|(
name|NAME
parameter_list|)
value|__gthread_mutex_t NAME
end_define

begin_define
define|#
directive|define
name|__glibcxx_mutex_lock
parameter_list|(
name|NAME
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_mutex_unlock
parameter_list|(
name|NAME
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
typedef|typedef
name|__glibcxx_mutex_type
name|mutex_type
typedef|;
comment|// Scoped lock idiom.
comment|// Acquire the mutex here with a constructor call, then release with
comment|// the destructor call in accordance with RAII style.
name|class
name|lock
block|{
comment|// Externally defined and initialized.
name|mutex_type
modifier|&
name|device
decl_stmt|;
name|public
label|:
name|explicit
name|lock
argument_list|(
name|mutex_type
operator|&
name|name
argument_list|)
operator|:
name|device
argument_list|(
argument|name
argument_list|)
block|{
name|__glibcxx_mutex_lock
argument_list|(
name|device
argument_list|)
block|; }
operator|~
name|lock
argument_list|()
name|throw
argument_list|()
block|{
name|__glibcxx_mutex_unlock
argument_list|(
name|device
argument_list|)
block|; }
name|private
operator|:
name|lock
argument_list|(
specifier|const
name|lock
operator|&
argument_list|)
expr_stmt|;
name|lock
modifier|&
name|operator
init|=
operator|(
specifier|const
name|lock
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

