begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2007 Free Software Foundation, Inc.
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
comment|/** @file ext/numeric_traits.h  *  This file is a GNU extension to the Standard C++ Library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXT_NUMERIC_TRAITS
end_ifndef

begin_define
define|#
directive|define
name|_EXT_NUMERIC_TRAITS
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
file|<limits>
end_include

begin_include
include|#
directive|include
file|<bits/cpp_type_traits.h>
end_include

begin_include
include|#
directive|include
file|<ext/type_traits.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_comment
comment|// Compile time constants for builtin types.
end_comment

begin_comment
comment|// Sadly std::numeric_limits member functions cannot be used for this.
end_comment

begin_define
define|#
directive|define
name|__glibcxx_signed
parameter_list|(
name|_Tp
parameter_list|)
value|((_Tp)(-1)< 0)
end_define

begin_define
define|#
directive|define
name|__glibcxx_digits
parameter_list|(
name|_Tp
parameter_list|)
define|\
value|(sizeof(_Tp) * __CHAR_BIT__ - __glibcxx_signed(_Tp))
end_define

begin_define
define|#
directive|define
name|__glibcxx_min
parameter_list|(
name|_Tp
parameter_list|)
define|\
value|(__glibcxx_signed(_Tp) ? (_Tp)1<< __glibcxx_digits(_Tp) : (_Tp)0)
end_define

begin_define
define|#
directive|define
name|__glibcxx_max
parameter_list|(
name|_Tp
parameter_list|)
define|\
value|(__glibcxx_signed(_Tp) ? \    (((((_Tp)1<< (__glibcxx_digits(_Tp) - 1)) - 1)<< 1) + 1) : ~(_Tp)0)
end_define

begin_expr_stmt
name|template
operator|<
name|typename
name|_Value
operator|>
expr|struct
name|__numeric_traits_integer
block|{
comment|// Only integers for initialization of member constant.
specifier|static
specifier|const
name|_Value
name|__min
operator|=
name|__glibcxx_min
argument_list|(
name|_Value
argument_list|)
block|;
specifier|static
specifier|const
name|_Value
name|__max
operator|=
name|__glibcxx_max
argument_list|(
name|_Value
argument_list|)
block|;     }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Value
operator|>
specifier|const
name|_Value
name|__numeric_traits_integer
operator|<
name|_Value
operator|>
operator|::
name|__min
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Value
operator|>
specifier|const
name|_Value
name|__numeric_traits_integer
operator|<
name|_Value
operator|>
operator|::
name|__max
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Value
operator|>
expr|struct
name|__numeric_traits_floating
block|{
comment|// Only floating point types. See N1822.
specifier|static
specifier|const
name|int
name|__max_digits10
operator|=
literal|2
operator|+
name|std
operator|::
name|numeric_limits
operator|<
name|_Value
operator|>
operator|::
name|digits
operator|*
literal|3010
operator|/
literal|10000
block|;     }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Value
operator|>
specifier|const
name|int
name|__numeric_traits_floating
operator|<
name|_Value
operator|>
operator|::
name|__max_digits10
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Value
operator|>
expr|struct
name|__numeric_traits
operator|:
name|public
name|__conditional_type
operator|<
name|std
operator|::
name|__is_integer
operator|<
name|_Value
operator|>
operator|::
name|__value
operator|,
name|__numeric_traits_integer
operator|<
name|_Value
operator|>
operator|,
name|__numeric_traits_floating
operator|<
name|_Value
operator|>
expr|>
operator|::
name|__type
block|{ }
expr_stmt|;
end_expr_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_undef
undef|#
directive|undef
name|__glibcxx_signed
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_min
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_max
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_digits
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

