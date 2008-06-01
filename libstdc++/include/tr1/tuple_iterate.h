begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// class template tuple -*- C++ -*-
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
comment|/** @file tr1/tuple_iterate.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|// Chris Jefferson<chris@bubblescope.net>
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|tr1
argument_list|)
comment|/// @brief class tuple_size
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|>
expr|struct
name|tuple_size
operator|<
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
expr|>
block|{
specifier|static
specifier|const
name|int
name|value
operator|=
name|_GLIBCXX_NUM_ARGS
block|; }
expr_stmt|;
if|#
directive|if
name|_GLIBCXX_NUM_ARGS
operator|>
literal|0
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|>
specifier|const
name|int
name|tuple_size
operator|<
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
expr|>
operator|::
name|value
expr_stmt|;
endif|#
directive|endif
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|>
ifdef|#
directive|ifdef
name|_GLIBCXX_LAST_INCLUDE
name|class
name|tuple
else|#
directive|else
name|class
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
endif|#
directive|endif
block|{
name|_GLIBCXX_BIND_MEMBERS
name|public
operator|:
name|tuple
argument_list|()
block|{ }
if|#
directive|if
name|_GLIBCXX_NUM_ARGS
operator|==
literal|2
name|template
operator|<
name|typename
name|_U1
block|,
name|typename
name|_U2
operator|>
name|tuple
argument_list|(
specifier|const
name|std
operator|::
name|pair
operator|<
name|_U1
argument_list|,
name|_U2
operator|>
operator|&
name|__u
argument_list|)
operator|:
name|_M_arg1
argument_list|(
name|__u
operator|.
name|first
argument_list|)
block|,
name|_M_arg2
argument_list|(
argument|__u.second
argument_list|)
block|{ }
name|template
operator|<
name|typename
name|_U1
block|,
name|typename
name|_U2
operator|>
name|tuple
operator|&
name|operator
operator|=
operator|(
specifier|const
name|std
operator|::
name|pair
operator|<
name|_U1
operator|,
name|_U2
operator|>
operator|&
name|__u
operator|)
block|{
name|_M_arg1
operator|=
name|__u
operator|.
name|first
block|;
name|_M_arg2
operator|=
name|__u
operator|.
name|second
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
if|#
directive|if
name|_GLIBCXX_NUM_ARGS
operator|>
literal|0
name|explicit
name|tuple
argument_list|(
name|_GLIBCXX_TUPLE_ADD_CREF
argument_list|)
operator|:
name|_GLIBCXX_BIND_MEMBERS_INIT
block|{ }
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS_U
operator|>
name|tuple
argument_list|(
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
operator|&
name|__in
argument_list|)
operator|:
name|_GLIBCXX_TUPLE_COPY_INIT
block|{ }
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS_U
operator|>
name|tuple
operator|&
name|operator
operator|=
operator|(
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS_U
operator|>
operator|&
name|__in
operator|)
block|{
name|_GLIBCXX_TUPLE_ASSIGN
return|return
operator|*
name|this
return|;
block|}
name|tuple
argument_list|(
specifier|const
name|tuple
operator|&
name|__in
argument_list|)
operator|:
name|_GLIBCXX_TUPLE_COPY_INIT
block|{ }
else|#
directive|else
name|tuple
argument_list|(
argument|const tuple&
argument_list|)
block|{ }
endif|#
directive|endif
name|tuple
operator|&
name|operator
operator|=
operator|(
specifier|const
name|tuple
operator|&
name|__in
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
operator|)
block|{
name|_GLIBCXX_TUPLE_ASSIGN
return|return
operator|*
name|this
return|;
block|}
name|template
operator|<
name|int
name|__i
block|,
name|typename
name|__Type
operator|>
name|friend
name|class
name|__get_helper
block|;
name|template
operator|<
name|_GLIBCXX_TUPLE_ALL_TEMPLATE_PARAMS_UNNAMED
operator|>
name|friend
name|class
name|tuple
block|;   }
expr_stmt|;
ifndef|#
directive|ifndef
name|_GLIBCXX_LAST_INCLUDE
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__get_helper
operator|<
name|_GLIBCXX_NUM_ARGS
operator|,
name|_Tp
operator|>
block|{
specifier|static
name|typename
name|__add_ref
operator|<
name|typename
name|tuple_element
operator|<
name|_GLIBCXX_NUM_ARGS
block|,
name|_Tp
operator|>
operator|::
name|type
operator|>
operator|::
name|type
name|get_value
argument_list|(
argument|_Tp& __in
argument_list|)
block|{
return|return
name|__in
operator|.
name|_GLIBCXX_CAT
argument_list|(
name|_M_arg
argument_list|,
name|_GLIBCXX_NUM_ARGS_PLUS_1
argument_list|)
return|;
block|}
specifier|static
name|typename
name|__add_c_ref
operator|<
name|typename
name|tuple_element
operator|<
name|_GLIBCXX_NUM_ARGS
block|,
name|_Tp
operator|>
operator|::
name|type
operator|>
operator|::
name|type
name|get_value
argument_list|(
argument|const _Tp& __in
argument_list|)
block|{
return|return
name|__in
operator|.
name|_GLIBCXX_CAT
argument_list|(
name|_M_arg
argument_list|,
name|_GLIBCXX_NUM_ARGS_PLUS_1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// @brief class tuple_element
name|template
operator|<
name|_GLIBCXX_TUPLE_ALL_TEMPLATE_PARAMS
operator|>
expr|struct
name|tuple_element
operator|<
name|_GLIBCXX_NUM_ARGS
block|,
name|tuple
operator|<
name|_GLIBCXX_TUPLE_ALL_TEMPLATE_ARGS
operator|>
expr|>
block|{
typedef|typedef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
name|type
typedef|;
block|}
block|;
endif|#
directive|endif
if|#
directive|if
name|_GLIBCXX_NUM_ARGS
operator|==
literal|0
name|tuple
operator|<
operator|>
specifier|inline
name|make_tuple
argument_list|()
block|{
return|return
name|tuple
operator|<
operator|>
operator|(
operator|)
return|;
block|}
name|tuple
operator|<
operator|>
specifier|inline
name|tie
argument_list|()
block|{
return|return
name|tuple
operator|<
operator|>
operator|(
operator|)
return|;
block|}
else|#
directive|else
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|>
name|typename
name|__stripped_tuple_type
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
operator|::
name|__type
specifier|inline
name|make_tuple
argument_list|(
argument|_GLIBCXX_PARAMS
argument_list|)
block|{
return|return
name|typename
name|__stripped_tuple_type
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
operator|::
name|__type
argument_list|(
name|_GLIBCXX_ARGS
argument_list|)
return|;
block|}
name|template
operator|<
name|_GLIBCXX_TEMPLATE_PARAMS
operator|>
name|tuple
operator|<
name|_GLIBCXX_REF_TEMPLATE_ARGS
operator|>
specifier|inline
name|tie
argument_list|(
argument|_GLIBCXX_REF_PARAMS
argument_list|)
block|{
return|return
name|make_tuple
argument_list|(
name|_GLIBCXX_REF_WRAP_PARAMS
argument_list|)
return|;
block|}
endif|#
directive|endif
name|_GLIBCXX_END_NAMESPACE
expr|}
end_decl_stmt

end_unit

