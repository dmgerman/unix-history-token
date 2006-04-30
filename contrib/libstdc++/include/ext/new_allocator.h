begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Allocator that wraps operator new -*- C++ -*-
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

begin_ifndef
ifndef|#
directive|ifndef
name|_NEW_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_NEW_ALLOCATOR_H
value|1
end_define

begin_include
include|#
directive|include
file|<new>
end_include

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
comment|/**    *  @brief  An allocator that uses global new, as per [20.4].    *    *  This is precisely the allocator defined in the C++ Standard.     *    - all allocation calls operator new    *    - all deallocation calls operator delete    *    *  (See @link Allocators allocators info @endlink for more.)    */
name|template
operator|<
name|typename
name|_Tp
operator|>
name|class
name|new_allocator
block|{
name|public
operator|:
typedef|typedef
name|size_t
name|size_type
typedef|;
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
typedef|typedef
specifier|const
name|_Tp
modifier|*
name|const_pointer
typedef|;
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
typedef|typedef
specifier|const
name|_Tp
modifier|&
name|const_reference
typedef|;
typedef|typedef
name|_Tp
name|value_type
typedef|;
name|template
operator|<
name|typename
name|_Tp1
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|new_allocator
operator|<
name|_Tp1
operator|>
name|other
expr_stmt|;
block|}
empty_stmt|;
name|new_allocator
argument_list|()
name|throw
argument_list|()
block|{ }
name|new_allocator
argument_list|(
argument|const new_allocator&
argument_list|)
name|throw
argument_list|()
block|{ }
name|template
operator|<
name|typename
name|_Tp1
operator|>
name|new_allocator
argument_list|(
argument|const new_allocator<_Tp1>&
argument_list|)
name|throw
argument_list|()
block|{ }
operator|~
name|new_allocator
argument_list|()
name|throw
argument_list|()
block|{ }
name|pointer
name|address
argument_list|(
argument|reference __x
argument_list|)
specifier|const
block|{
return|return
operator|&
name|__x
return|;
block|}
name|const_pointer
name|address
argument_list|(
name|const_reference
name|__x
argument_list|)
decl|const
block|{
return|return
operator|&
name|__x
return|;
block|}
comment|// NB: __n is permitted to be 0.  The C++ standard says nothing
comment|// about what the return value is when __n == 0.
name|pointer
name|allocate
parameter_list|(
name|size_type
name|__n
parameter_list|,
specifier|const
name|void
modifier|*
init|=
literal|0
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
operator|::
name|operator
name|new
argument_list|(
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
operator|)
return|;
block|}
comment|// __p is not permitted to be a null pointer.
name|void
name|deallocate
parameter_list|(
name|pointer
name|__p
parameter_list|,
name|size_type
parameter_list|)
block|{
operator|::
name|operator
name|delete
argument_list|(
name|__p
argument_list|)
expr_stmt|;
block|}
name|size_type
name|max_size
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|size_t
argument_list|(
operator|-
literal|1
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
return|;
block|}
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 402. wrong new expression in [some_] allocator::construct
name|void
name|construct
parameter_list|(
name|pointer
name|__p
parameter_list|,
specifier|const
name|_Tp
modifier|&
name|__val
parameter_list|)
block|{
operator|::
name|new
argument_list|(
argument|__p
argument_list|)
name|_Tp
argument_list|(
name|__val
argument_list|)
expr_stmt|;
block|}
name|void
name|destroy
parameter_list|(
name|pointer
name|__p
parameter_list|)
block|{
name|__p
operator|->
expr|~
name|_Tp
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|new_allocator
operator|<
name|_Tp
operator|>
operator|&
operator|,
specifier|const
name|new_allocator
operator|<
name|_Tp
operator|>
operator|&
operator|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|new_allocator
operator|<
name|_Tp
operator|>
operator|&
operator|,
specifier|const
name|new_allocator
operator|<
name|_Tp
operator|>
operator|&
operator|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// namespace __gnu_cxx
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

