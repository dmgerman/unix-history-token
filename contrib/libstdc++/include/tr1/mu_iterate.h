begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// TR1 functional -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2005 Free Software Foundation, Inc.
end_comment

begin_comment
comment|// Written by Douglas Gregor<doug.gregor -at- gmail.com>
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
comment|/** @file tr1/mu_iterate.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|// Determine the result type when we pass the arguments along. This
end_comment

begin_comment
comment|// involves passing along the cv-qualifiers placed on _Mu and
end_comment

begin_comment
comment|// unwrapping the argument bundle.
end_comment

begin_comment
comment|// @namespace std::tr1
end_comment

begin_comment
comment|// @class std::tr1::_Mu::result
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CVMu
operator|,
name|typename
name|_CVArg
name|_GLIBCXX_COMMA
name|_GLIBCXX_TEMPLATE_PARAMS
operator|>
name|class
name|result
operator|<
name|_CVMu
argument_list|(
name|_CVArg
argument_list|,
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
argument_list|)
operator|>
operator|:
name|public
name|result_of
operator|<
name|_CVArg
argument_list|(
name|_GLIBCXX_TEMPLATE_ARGS
argument_list|)
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CVArg
name|_GLIBCXX_COMMA
name|_GLIBCXX_TEMPLATE_PARAMS
operator|>
name|typename
name|result_of
operator|<
name|_CVArg
argument_list|(
name|_GLIBCXX_TEMPLATE_ARGS
argument_list|)
operator|>
operator|::
name|type
name|operator
argument_list|()
operator|(
name|_CVArg
operator|&
name|__arg
operator|,
specifier|const
name|tuple
operator|<
name|_GLIBCXX_TEMPLATE_ARGS
operator|>
operator|&
name|__tuple
operator|)
specifier|const
specifier|volatile
block|{
return|return
name|__arg
argument_list|(
name|_GLIBCXX_MU_GET_TUPLE_ARGS
argument_list|)
return|;
block|}
end_expr_stmt

end_unit

