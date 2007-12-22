begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2005, 2006, 2007 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the terms
end_comment

begin_comment
comment|// of the GNU General Public License as published by the Free Software
end_comment

begin_comment
comment|// Foundation; either version 2, or (at your option) any later
end_comment

begin_comment
comment|// version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful, but
end_comment

begin_comment
comment|// WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
end_comment

begin_comment
comment|// General Public License for more details.
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
comment|// As a special exception, you may use this file as part of a free
end_comment

begin_comment
comment|// software library without restriction.  Specifically, if other files
end_comment

begin_comment
comment|// instantiate templates or use macros or inline functions from this
end_comment

begin_comment
comment|// file, or you compile this file and link it with other files to
end_comment

begin_comment
comment|// produce an executable, this file does not by itself cause the
end_comment

begin_comment
comment|// resulting executable to be covered by the GNU General Public
end_comment

begin_comment
comment|// License.  This exception does not however invalidate any other
end_comment

begin_comment
comment|// reasons why the executable file might be covered by the GNU General
end_comment

begin_comment
comment|// Public License.
end_comment

begin_comment
comment|/** @file ext/type_traits.h  *  This file is a GNU extension to the Standard C++ Library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXT_TYPE_TRAITS
end_ifndef

begin_define
define|#
directive|define
name|_EXT_TYPE_TRAITS
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<bits/cpp_type_traits.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_comment
comment|// Define a nested type if some predicate holds.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
operator|,
name|typename
operator|>
expr|struct
name|__enable_if
block|{ }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__enable_if
operator|<
name|true
operator|,
name|_Tp
operator|>
block|{
typedef|typedef
name|_Tp
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Conditional expression for types. If true, first, if false, second.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|_Cond
operator|,
name|typename
name|_Iftrue
operator|,
name|typename
name|_Iffalse
operator|>
expr|struct
name|__conditional_type
block|{
typedef|typedef
name|_Iftrue
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Iftrue
operator|,
name|typename
name|_Iffalse
operator|>
expr|struct
name|__conditional_type
operator|<
name|false
operator|,
name|_Iftrue
operator|,
name|_Iffalse
operator|>
block|{
typedef|typedef
name|_Iffalse
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Given an integral builtin type, return the corresponding unsigned type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__add_unsigned
block|{
name|private
operator|:
typedef|typedef
name|__enable_if
operator|<
name|std
operator|::
name|__is_integer
operator|<
name|_Tp
operator|>
operator|::
name|__value
operator|,
name|_Tp
operator|>
name|__if_type
expr_stmt|;
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__if_type
operator|::
name|__type
name|__type
expr_stmt|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__add_unsigned
operator|<
name|char
operator|>
block|{
typedef|typedef
name|unsigned
name|char
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__add_unsigned
operator|<
name|signed
name|char
operator|>
block|{
typedef|typedef
name|unsigned
name|char
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__add_unsigned
operator|<
name|short
operator|>
block|{
typedef|typedef
name|unsigned
name|short
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__add_unsigned
operator|<
name|int
operator|>
block|{
typedef|typedef
name|unsigned
name|int
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__add_unsigned
operator|<
name|long
operator|>
block|{
typedef|typedef
name|unsigned
name|long
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__add_unsigned
operator|<
name|long
name|long
operator|>
block|{
typedef|typedef
name|unsigned
name|long
name|long
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Declare but don't define.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__add_unsigned
operator|<
name|bool
operator|>
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__add_unsigned
operator|<
name|wchar_t
operator|>
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Given an integral builtin type, return the corresponding signed type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__remove_unsigned
block|{
name|private
operator|:
typedef|typedef
name|__enable_if
operator|<
name|std
operator|::
name|__is_integer
operator|<
name|_Tp
operator|>
operator|::
name|__value
operator|,
name|_Tp
operator|>
name|__if_type
expr_stmt|;
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__if_type
operator|::
name|__type
name|__type
expr_stmt|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__remove_unsigned
operator|<
name|char
operator|>
block|{
typedef|typedef
name|signed
name|char
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__remove_unsigned
operator|<
name|unsigned
name|char
operator|>
block|{
typedef|typedef
name|signed
name|char
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__remove_unsigned
operator|<
name|unsigned
name|short
operator|>
block|{
typedef|typedef
name|short
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__remove_unsigned
operator|<
name|unsigned
name|int
operator|>
block|{
typedef|typedef
name|int
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__remove_unsigned
operator|<
name|unsigned
name|long
operator|>
block|{
typedef|typedef
name|long
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__remove_unsigned
operator|<
name|unsigned
name|long
name|long
operator|>
block|{
typedef|typedef
name|long
name|long
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Declare but don't define.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__remove_unsigned
operator|<
name|bool
operator|>
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__remove_unsigned
operator|<
name|wchar_t
operator|>
expr_stmt|;
end_expr_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

