begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Types used in iterator implementation -*- C++ -*-
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996-1998  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_iterator_base_types.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  *  *  This file contains all of the general iterator-related utility types,  *  such as iterator_traits and struct iterator.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GLIBCPP_INTERNAL_ITERATOR_BASE_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|__GLIBCPP_INTERNAL_ITERATOR_BASE_TYPES_H
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_decl_stmt
name|namespace
name|std
block|{
comment|//@{
comment|/**    *  @defgroup iterator_tags Iterator Tags    *  These are empty types, used to distinguish different iterators.  The    *  distinction is not made by what they contain, but simply by what they    *  are.  Different underlying algorithms can then be used based on the    *  different operations supporetd by different iterator types.   */
comment|///  Marking input iterators.
struct|struct
name|input_iterator_tag
block|{}
struct|;
comment|///  Marking output iterators.
struct|struct
name|output_iterator_tag
block|{}
struct|;
comment|/// Forward iterators support a superset of input iterator operations.
name|struct
name|forward_iterator_tag
range|:
name|public
name|input_iterator_tag
block|{}
decl_stmt|;
comment|/// Bidirectional iterators support a superset of forward iterator operations.
name|struct
name|bidirectional_iterator_tag
range|:
name|public
name|forward_iterator_tag
block|{}
decl_stmt|;
comment|/// Random-access iterators support a superset of bidirectional iterator operations.
name|struct
name|random_access_iterator_tag
range|:
name|public
name|bidirectional_iterator_tag
block|{}
decl_stmt|;
comment|//@}
comment|/**    *  @brief  Common %iterator class.    *    *  This class does nothing but define nested typedefs.  %Iterator classes    *  can inherit from this class to save some work.  The typedefs are then    *  used in specializations and overloading.    *    *  In particular, there are no default implementations of requirements    *  such as @c operator++ and the like.  (How could there be?)   */
name|template
operator|<
name|typename
name|_Category
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Distance
operator|=
name|ptrdiff_t
operator|,
name|typename
name|_Pointer
operator|=
name|_Tp
operator|*
operator|,
name|typename
name|_Reference
operator|=
name|_Tp
operator|&
operator|>
expr|struct
name|iterator
block|{
comment|/// One of the @link iterator_tags tag types@endlink.
typedef|typedef
name|_Category
name|iterator_category
typedef|;
comment|/// The type "pointed to" by the iterator.
typedef|typedef
name|_Tp
name|value_type
typedef|;
comment|/// Distance between iterators is represented as this type.
typedef|typedef
name|_Distance
name|difference_type
typedef|;
comment|/// This type represents a pointer-to-value_type.
typedef|typedef
name|_Pointer
name|pointer
typedef|;
comment|/// This type represents a reference-to-value_type.
typedef|typedef
name|_Reference
name|reference
typedef|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**    *  This class does nothing but define nested typedefs.  The general    *  version simply "forwards" the nested typedefs from the Iterator    *  argument.  Specialized versions for pointers and pointers-to-const    *  provide tighter, more correct semantics.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Iterator
operator|>
expr|struct
name|iterator_traits
block|{
typedef|typedef
name|typename
name|_Iterator
operator|::
name|iterator_category
name|iterator_category
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|_Iterator
operator|::
name|value_type
name|value_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Iterator
operator|::
name|difference_type
name|difference_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Iterator
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Iterator
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|iterator_traits
operator|<
name|_Tp
operator|*
operator|>
block|{
typedef|typedef
name|random_access_iterator_tag
name|iterator_category
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

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
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|iterator_traits
operator|<
specifier|const
name|_Tp
operator|*
operator|>
block|{
typedef|typedef
name|random_access_iterator_tag
name|iterator_category
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_comment
unit|};
comment|/**    *  @if maint    *  This function is not a part of the C++ standard but is syntactic    *  sugar for internal library use only.    *  @endif   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Iter
operator|>
specifier|inline
name|typename
name|iterator_traits
operator|<
name|_Iter
operator|>
operator|::
name|iterator_category
name|__iterator_category
argument_list|(
argument|const _Iter&
argument_list|)
block|{
return|return
name|typename
name|iterator_traits
operator|<
name|_Iter
operator|>
operator|::
name|iterator_category
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GLIBCPP_INTERNAL_ITERATOR_BASE_TYPES_H */
end_comment

end_unit

