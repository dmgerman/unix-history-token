begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// nonstandard construct and destroy functions -*- C++ -*-
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_construct.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STL_CONSTRUCT_H
end_ifndef

begin_define
define|#
directive|define
name|_STL_CONSTRUCT_H
value|1
end_define

begin_include
include|#
directive|include
file|<bits/type_traits.h>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|/**    * @if maint    * Constructs an object in existing memory by invoking an allocated    * object's constructor with an initializer.    * @endif    */
name|template
operator|<
name|typename
name|_T1
operator|,
name|typename
name|_T2
operator|>
specifier|inline
name|void
name|_Construct
argument_list|(
argument|_T1* __p
argument_list|,
argument|const _T2& __value
argument_list|)
block|{
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 402. wrong new expression in [some_]allocator::construct
operator|::
name|new
argument_list|(
argument|static_cast<void*>(__p)
argument_list|)
name|_T1
argument_list|(
name|__value
argument_list|)
block|;     }
comment|/**    * @if maint    * Constructs an object in existing memory by invoking an allocated    * object's default constructor (no initializers).    * @endif    */
name|template
operator|<
name|typename
name|_T1
operator|>
specifier|inline
name|void
name|_Construct
argument_list|(
argument|_T1* __p
argument_list|)
block|{
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 402. wrong new expression in [some_]allocator::construct
operator|::
name|new
argument_list|(
argument|static_cast<void*>(__p)
argument_list|)
name|_T1
argument_list|()
block|;     }
comment|/**    * @if maint    * Destroy the object pointed to by a pointer type.    * @endif    */
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|_Destroy
argument_list|(
argument|_Tp* __pointer
argument_list|)
block|{
name|__pointer
operator|->
expr|~
name|_Tp
argument_list|()
block|; }
comment|/**    * @if maint    * Destroy a range of objects with nontrivial destructors.    *    * This is a helper function used only by _Destroy().    * @endif    */
name|template
operator|<
name|typename
name|_ForwardIterator
operator|>
specifier|inline
name|void
name|__destroy_aux
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|__false_type
argument_list|)
block|{
for|for
control|(
init|;
name|__first
operator|!=
name|__last
condition|;
operator|++
name|__first
control|)
name|std
operator|::
name|_Destroy
argument_list|(
operator|&
operator|*
name|__first
argument_list|)
expr_stmt|;
block|}
comment|/**    * @if maint    * Destroy a range of objects with trivial destructors.  Since the destructors    * are trivial, there's nothing to do and hopefully this function will be    * entirely optimized away.    *    * This is a helper function used only by _Destroy().    * @endif    */
name|template
operator|<
name|typename
name|_ForwardIterator
operator|>
specifier|inline
name|void
name|__destroy_aux
argument_list|(
argument|_ForwardIterator
argument_list|,
argument|_ForwardIterator
argument_list|,
argument|__true_type
argument_list|)
block|{ }
comment|/**    * @if maint    * Destroy a range of objects.  If the value_type of the object has    * a trivial destructor, the compiler should optimize all of this    * away, otherwise the objects' destructors must be invoked.    * @endif    */
name|template
operator|<
name|typename
name|_ForwardIterator
operator|>
specifier|inline
name|void
name|_Destroy
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator
operator|>
operator|::
name|value_type
name|_Value_type
expr_stmt|;
typedef|typedef
name|typename
name|__type_traits
operator|<
name|_Value_type
operator|>
operator|::
name|has_trivial_destructor
name|_Has_trivial_destructor
expr_stmt|;
name|std
operator|::
name|__destroy_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_Has_trivial_destructor
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STL_CONSTRUCT_H */
end_comment

end_unit

