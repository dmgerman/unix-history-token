begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Stack implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001 Free Software Foundation, Inc.
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
comment|/** @file stl_stack.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GLIBCPP_INTERNAL_STACK_H
end_ifndef

begin_define
define|#
directive|define
name|__GLIBCPP_INTERNAL_STACK_H
end_define

begin_include
include|#
directive|include
file|<bits/concept_check.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// Forward declarations of operators == and<, needed for friend declaration.
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Sequence
operator|=
name|deque
operator|<
name|_Tp
operator|>
expr|>
name|class
name|stack
expr_stmt|;
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Seq
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__x
operator|,
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__y
operator|)
expr_stmt|;
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Seq
operator|>
name|bool
name|operator
operator|<
operator|(
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__x
operator|,
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__y
operator|)
expr_stmt|;
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Sequence
operator|>
name|class
name|stack
block|{
comment|// concept requirements
name|__glibcpp_class_requires
argument_list|(
argument|_Tp
argument_list|,
argument|_SGIAssignableConcept
argument_list|)
name|__glibcpp_class_requires
argument_list|(
argument|_Sequence
argument_list|,
argument|_BackInsertionSequenceConcept
argument_list|)
typedef|typedef
name|typename
name|_Sequence
operator|::
name|value_type
name|_Sequence_value_type
expr_stmt|;
name|__glibcpp_class_requires2
argument_list|(
name|_Tp
argument_list|,
name|_Sequence_value_type
argument_list|,
name|_SameTypeConcept
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
name|_Tp1
operator|,
name|class
name|_Seq1
operator|>
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|stack
operator|<
name|_Tp1
operator|,
name|_Seq1
operator|>
operator|&
operator|,
specifier|const
name|stack
operator|<
name|_Tp1
operator|,
name|_Seq1
operator|>
operator|&
operator|)
expr_stmt|;
name|template
operator|<
name|class
name|_Tp1
operator|,
name|class
name|_Seq1
operator|>
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|stack
operator|<
name|_Tp1
operator|,
name|_Seq1
operator|>
operator|&
operator|,
specifier|const
name|stack
operator|<
name|_Tp1
operator|,
name|_Seq1
operator|>
operator|&
operator|)
expr_stmt|;
name|public
label|:
typedef|typedef
name|typename
name|_Sequence
operator|::
name|value_type
name|value_type
expr_stmt|;
typedef|typedef
name|typename
name|_Sequence
operator|::
name|size_type
name|size_type
expr_stmt|;
typedef|typedef
name|_Sequence
name|container_type
typedef|;
typedef|typedef
name|typename
name|_Sequence
operator|::
name|reference
name|reference
expr_stmt|;
typedef|typedef
name|typename
name|_Sequence
operator|::
name|const_reference
name|const_reference
expr_stmt|;
name|protected
label|:
name|_Sequence
name|c
decl_stmt|;
name|public
label|:
name|stack
argument_list|()
operator|:
name|c
argument_list|()
block|{}
name|explicit
name|stack
argument_list|(
specifier|const
name|_Sequence
operator|&
name|__s
argument_list|)
operator|:
name|c
argument_list|(
argument|__s
argument_list|)
block|{}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|empty
argument_list|()
return|;
block|}
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|size
argument_list|()
return|;
block|}
name|reference
name|top
parameter_list|()
block|{
return|return
name|c
operator|.
name|back
argument_list|()
return|;
block|}
name|const_reference
name|top
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|back
argument_list|()
return|;
block|}
name|void
name|push
parameter_list|(
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
name|c
operator|.
name|push_back
argument_list|(
name|__x
argument_list|)
expr_stmt|;
block|}
name|void
name|pop
parameter_list|()
block|{
name|c
operator|.
name|pop_back
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
name|class
name|_Tp
operator|,
name|class
name|_Seq
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__x
operator|,
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|c
operator|==
name|__y
operator|.
name|c
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Seq
operator|>
name|bool
name|operator
operator|<
operator|(
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__x
operator|,
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|c
operator|<
name|__y
operator|.
name|c
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Seq
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__x
operator|,
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__x
operator|==
name|__y
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Seq
operator|>
name|bool
name|operator
operator|>
operator|(
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__x
operator|,
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__y
operator|<
name|__x
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Seq
operator|>
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__x
operator|,
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__y
operator|<
name|__x
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Seq
operator|>
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__x
operator|,
specifier|const
name|stack
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__x
operator|<
name|__y
operator|)
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
comment|/* __GLIBCPP_INTERNAL_STACK_H */
end_comment

begin_comment
comment|// Local Variables:
end_comment

begin_comment
comment|// mode:C++
end_comment

begin_comment
comment|// End:
end_comment

end_unit

