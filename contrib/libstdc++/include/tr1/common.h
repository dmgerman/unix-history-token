begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Internal header for TR1 complex -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2006 Free Software Foundation, Inc.
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
comment|/** @file tr1/common.h  *  This is a TR1 C++ Library header.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TR1_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_TR1_COMMON_H
value|1
end_define

begin_include
include|#
directive|include
file|<tr1/type_traits>
end_include

begin_comment
comment|// namespace std::tr1
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|tr1
argument_list|)
name|template
operator|<
name|typename
name|_Tp
operator|,
name|bool
operator|=
name|is_integral
operator|<
name|_Tp
operator|>
operator|::
name|value
operator|>
expr|struct
name|__promote
block|{
typedef|typedef
name|double
name|__type
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__promote
operator|<
name|_Tp
operator|,
name|false
operator|>
block|{
typedef|typedef
name|_Tp
name|__type
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Up
operator|>
expr|struct
name|__promote_2
block|{
name|private
operator|:
typedef|typedef
name|typename
name|__promote
operator|<
name|_Tp
operator|>
operator|::
name|__type
name|__type1
expr_stmt|;
typedef|typedef
name|typename
name|__promote
operator|<
name|_Up
operator|>
operator|::
name|__type
name|__type2
expr_stmt|;
name|public
label|:
typedef|typedef
name|__typeof__
argument_list|(
argument|__type1() + __type2()
argument_list|)
name|__type
expr_stmt|;
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
operator|,
name|typename
name|_Up
operator|,
name|typename
name|_Vp
operator|>
expr|struct
name|__promote_3
block|{
name|private
operator|:
typedef|typedef
name|typename
name|__promote
operator|<
name|_Tp
operator|>
operator|::
name|__type
name|__type1
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__promote
operator|<
name|_Up
operator|>
operator|::
name|__type
name|__type2
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|__promote
operator|<
name|_Vp
operator|>
operator|::
name|__type
name|__type3
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|__type1() + __type2() + __type3()
argument_list|)
name|__type
expr_stmt|;
end_typedef

begin_expr_stmt
unit|};
name|_GLIBCXX_END_NAMESPACE
end_expr_stmt

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

