begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Support for atomic operations -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2004, 2005, 2006 Free Software Foundation, Inc.
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
comment|/** @file atomicity.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_ATOMICITY_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_ATOMICITY_H
value|1
end_define

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_include
include|#
directive|include
file|<bits/gthr.h>
end_include

begin_include
include|#
directive|include
file|<bits/atomic_word.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_comment
comment|// Functions for portable atomic access.
end_comment

begin_comment
comment|// To abstract locking primatives across all thread policies, use:
end_comment

begin_comment
comment|// __exchange_and_add_dispatch
end_comment

begin_comment
comment|// __atomic_add_dispatch
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_ATOMIC_BUILTINS
end_ifdef

begin_function
specifier|static
specifier|inline
name|_Atomic_word
name|__exchange_and_add
parameter_list|(
specifier|volatile
name|_Atomic_word
modifier|*
name|__mem
parameter_list|,
name|int
name|__val
parameter_list|)
block|{
return|return
name|__sync_fetch_and_add
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|__atomic_add
parameter_list|(
specifier|volatile
name|_Atomic_word
modifier|*
name|__mem
parameter_list|,
name|int
name|__val
parameter_list|)
block|{
name|__sync_fetch_and_add
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|_Atomic_word
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
name|__exchange_and_add
argument_list|(
specifier|volatile
name|_Atomic_word
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
name|__atomic_add
argument_list|(
specifier|volatile
name|_Atomic_word
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
name|_Atomic_word
name|__exchange_and_add_single
parameter_list|(
name|_Atomic_word
modifier|*
name|__mem
parameter_list|,
name|int
name|__val
parameter_list|)
block|{
name|_Atomic_word
name|__result
init|=
operator|*
name|__mem
decl_stmt|;
operator|*
name|__mem
operator|+=
name|__val
expr_stmt|;
return|return
name|__result
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|__atomic_add_single
parameter_list|(
name|_Atomic_word
modifier|*
name|__mem
parameter_list|,
name|int
name|__val
parameter_list|)
block|{
operator|*
name|__mem
operator|+=
name|__val
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|inline
name|_Atomic_word
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
name|__exchange_and_add_dispatch
argument_list|(
name|_Atomic_word
operator|*
name|__mem
argument_list|,
name|int
name|__val
argument_list|)
block|{
ifdef|#
directive|ifdef
name|__GTHREADS
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
return|return
name|__exchange_and_add
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
return|;
else|else
return|return
name|__exchange_and_add_single
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
return|;
else|#
directive|else
return|return
name|__exchange_and_add_single
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
return|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|void
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
name|__atomic_add_dispatch
argument_list|(
name|_Atomic_word
operator|*
name|__mem
argument_list|,
name|int
name|__val
argument_list|)
block|{
ifdef|#
directive|ifdef
name|__GTHREADS
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
name|__atomic_add
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
expr_stmt|;
else|else
name|__atomic_add_single
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
expr_stmt|;
else|#
directive|else
name|__atomic_add_single
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_comment
comment|// Even if the CPU doesn't need a memory barrier, we need to ensure
end_comment

begin_comment
comment|// that the compiler doesn't reorder memory accesses across the
end_comment

begin_comment
comment|// barriers.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_READ_MEM_BARRIER
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_READ_MEM_BARRIER
value|__asm __volatile ("":::"memory")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_WRITE_MEM_BARRIER
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_WRITE_MEM_BARRIER
value|__asm __volatile ("":::"memory")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

