begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Allocators -*- C++ -*-
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
comment|/*  * Copyright (c) 1996-1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file allocator.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_ALLOCATOR_H
value|1
end_define

begin_comment
comment|// Define the base class to std::allocator.
end_comment

begin_include
include|#
directive|include
file|<bits/c++allocator.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|typename
name|_Tp
operator|>
name|class
name|allocator
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|allocator
operator|<
name|void
operator|>
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
name|void
modifier|*
name|pointer
typedef|;
typedef|typedef
specifier|const
name|void
modifier|*
name|const_pointer
typedef|;
typedef|typedef
name|void
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
name|allocator
operator|<
name|_Tp1
operator|>
name|other
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**    *  @brief  The "standard" allocator, as per [20.4].    *    *  (See @link Allocators allocators info @endlink for more.)    */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
name|class
name|allocator
operator|:
name|public
name|___glibcxx_base_allocator
operator|<
name|_Tp
operator|>
block|{
name|public
operator|:
typedef|typedef
name|size_t
name|size_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|&
name|const_reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp1
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|allocator
operator|<
name|_Tp1
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|allocator
argument_list|()
end_macro

begin_macro
name|throw
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|allocator
argument_list|(
argument|const allocator& a
argument_list|)
end_macro

begin_expr_stmt
name|throw
argument_list|()
operator|:
name|___glibcxx_base_allocator
operator|<
name|_Tp
operator|>
operator|(
name|a
operator|)
block|{ }
name|template
operator|<
name|typename
name|_Tp1
operator|>
name|allocator
argument_list|(
argument|const allocator<_Tp1>&
argument_list|)
name|throw
argument_list|()
block|{ }
operator|~
name|allocator
argument_list|()
name|throw
argument_list|()
block|{ }
end_expr_stmt

begin_comment
comment|// Inherit everything else.
end_comment

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_T1
operator|,
name|typename
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|allocator
operator|<
name|_T1
operator|>
operator|&
operator|,
specifier|const
name|allocator
operator|<
name|_T2
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
name|_T1
operator|,
name|typename
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|allocator
operator|<
name|_T1
operator|>
operator|&
operator|,
specifier|const
name|allocator
operator|<
name|_T2
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
comment|// Inhibit implicit instantiations for required instantiations,
end_comment

begin_comment
comment|// which are defined via explicit instantiations elsewhere.
end_comment

begin_comment
comment|// NB: This syntax is a GNU extension.
end_comment

begin_if
if|#
directive|if
name|_GLIBCXX_EXTERN_TEMPLATE
end_if

begin_extern
extern|extern template class allocator<char>;
end_extern

begin_extern
extern|extern template class allocator<wchar_t>;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Undefine.
end_comment

begin_undef
undef|#
directive|undef
name|___glibcxx_base_allocator
end_undef

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

