begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// class template tuple -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2004, 2005 Free Software Foundation, Inc.
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
comment|/** @file tr1/tuple_defs.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_REPEAT_HEADER
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_REPEAT_HEADER
value|"tuple_defs.h"
end_define

begin_include
include|#
directive|include
file|"repeat.h"
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REPEAT_HEADER
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_LAST_INCLUDE
end_ifdef

begin_comment
comment|// Chris Jefferson<chris@bubblescope.net>
end_comment

begin_expr_stmt
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
operator|>
name|class
name|tuple
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns a const reference to the ith element of a tuple.
end_comment

begin_comment
comment|// Any const or non-const ref elements are returned with their original type.
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|__i
operator|,
name|_GLIBCXX_TEMPLATE_PARAMS
operator|>
name|typename
name|__add_ref
operator|<
name|typename
name|tuple_element
operator|<
name|__i
operator|,
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
expr|>
operator|::
name|type
operator|>
operator|::
name|type
name|get
argument_list|(
argument|tuple<_GLIBCXX_TEMPLATE_ARGS>& __t
argument_list|)
block|{
return|return
name|__get_helper
operator|<
name|__i
operator|,
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
expr|>
operator|::
name|get_value
argument_list|(
name|__t
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|int
name|__i
operator|,
name|_GLIBCXX_TEMPLATE_PARAMS
operator|>
name|typename
name|__add_c_ref
operator|<
name|typename
name|tuple_element
operator|<
name|__i
operator|,
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
expr|>
operator|::
name|type
operator|>
operator|::
name|type
name|get
argument_list|(
argument|const tuple<_GLIBCXX_TEMPLATE_ARGS>& __t
argument_list|)
block|{
return|return
name|__get_helper
operator|<
name|__i
operator|,
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
expr|>
operator|::
name|get_value
argument_list|(
name|__t
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|,
name|_GLIBCXX_TEMPLATE_PARAMS_U
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
operator|&
name|__t
operator|,
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
operator|&
name|__u
operator|)
block|{
typedef|typedef
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
name|_Tp
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
name|_Up
expr_stmt|;
end_typedef

begin_return
return|return
name|__tuple_compare
operator|<
name|tuple_size
operator|<
name|_Tp
operator|>
operator|::
name|value
operator|-
name|tuple_size
operator|<
name|_Tp
operator|>
operator|::
name|value
operator|,
literal|0
operator|,
name|tuple_size
operator|<
name|_Tp
operator|>
operator|::
name|value
operator|,
name|_Tp
operator|,
name|_Up
operator|>
operator|::
name|__eq
argument_list|(
name|__t
argument_list|,
name|__u
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}   template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|,
name|_GLIBCXX_TEMPLATE_PARAMS_U
operator|>
name|bool
name|operator
operator|<
operator|(
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
operator|&
name|__t
operator|,
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
operator|&
name|__u
operator|)
block|{
typedef|typedef
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
name|_Tp
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
name|_Up
expr_stmt|;
end_typedef

begin_return
return|return
name|__tuple_compare
operator|<
name|tuple_size
operator|<
name|_Tp
operator|>
operator|::
name|value
operator|-
name|tuple_size
operator|<
name|_Tp
operator|>
operator|::
name|value
operator|,
literal|0
operator|,
name|tuple_size
operator|<
name|_Tp
operator|>
operator|::
name|value
operator|,
name|_Tp
operator|,
name|_Up
operator|>
operator|::
name|__less
argument_list|(
name|__t
argument_list|,
name|__u
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}   template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|,
name|_GLIBCXX_TEMPLATE_PARAMS_U
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
operator|&
name|__t
operator|,
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
operator|&
name|__u
operator|)
block|{
return|return
operator|!
operator|(
name|__t
operator|==
name|__u
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|,
name|_GLIBCXX_TEMPLATE_PARAMS_U
operator|>
name|bool
name|operator
operator|>
operator|(
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
operator|&
name|__t
operator|,
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
operator|&
name|__u
operator|)
block|{
return|return
name|__u
operator|<
name|__t
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|,
name|_GLIBCXX_TEMPLATE_PARAMS_U
operator|>
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
operator|&
name|__t
operator|,
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
operator|&
name|__u
operator|)
block|{
return|return
operator|!
operator|(
name|__u
operator|<
name|__t
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|,
name|_GLIBCXX_TEMPLATE_PARAMS_U
operator|>
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
operator|&
name|__t
operator|,
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
operator|&
name|__u
operator|)
block|{
return|return
operator|!
operator|(
name|__t
operator|<
name|__u
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
operator|>
expr|struct
name|__stripped_tuple_type
block|{
typedef|typedef
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
operator|>
name|__type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

