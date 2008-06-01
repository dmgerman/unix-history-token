begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// TR1 type_traits -*- C++ -*-
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
comment|/** @file tr1/type_traits_fwd.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPE_TRAITS_FWD_H
end_ifndef

begin_define
define|#
directive|define
name|_TYPE_TRAITS_FWD_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstddef>
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
comment|/// @brief  helper classes [4.3].
name|template
operator|<
name|typename
name|_Tp
operator|,
name|_Tp
name|__v
operator|>
expr|struct
name|integral_constant
expr_stmt|;
typedef|typedef
name|integral_constant
operator|<
name|bool
operator|,
name|true
operator|>
name|true_type
expr_stmt|;
typedef|typedef
name|integral_constant
operator|<
name|bool
operator|,
name|false
operator|>
name|false_type
expr_stmt|;
comment|/// @brief  primary type categories [4.5.1].
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_void
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_integral
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_floating_point
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_array
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_pointer
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_reference
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_member_object_pointer
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_member_function_pointer
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_enum
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_union
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_class
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_function
expr_stmt|;
comment|/// @brief  composite type traits [4.5.2].
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_arithmetic
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_fundamental
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_object
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_scalar
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_compound
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_member_pointer
expr_stmt|;
comment|// Extension.
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_union_or_class
expr_stmt|;
comment|/// @brief  type properties [4.5.3].
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_const
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_volatile
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_pod
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_empty
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_polymorphic
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_abstract
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|has_trivial_constructor
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|has_trivial_copy
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|has_trivial_assign
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|has_trivial_destructor
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|has_nothrow_constructor
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|has_nothrow_copy
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|has_nothrow_assign
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|has_virtual_destructor
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_signed
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|is_unsigned
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|alignment_of
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|rank
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|,
name|unsigned
name|_Uint
operator|=
literal|0
operator|>
expr|struct
name|extent
expr_stmt|;
comment|/// @brief  relationships between types [4.6].
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Up
operator|>
expr|struct
name|is_same
expr_stmt|;
name|template
operator|<
name|typename
name|_From
operator|,
name|typename
name|_To
operator|>
expr|struct
name|is_convertible
expr_stmt|;
name|template
operator|<
name|typename
name|_Base
operator|,
name|typename
name|_Derived
operator|>
expr|struct
name|is_base_of
expr_stmt|;
comment|/// @brief  const-volatile modifications [4.7.1].
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|remove_const
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|remove_volatile
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|remove_cv
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|add_const
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|add_volatile
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|add_cv
expr_stmt|;
comment|/// @brief  reference modifications [4.7.2].
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|remove_reference
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|add_reference
expr_stmt|;
comment|/// @brief  array modifications [4.7.3].
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|remove_extent
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|remove_all_extents
expr_stmt|;
comment|/// @brief  pointer modifications [4.7.4].
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|remove_pointer
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|add_pointer
expr_stmt|;
comment|/// @brief  other transformations [4.8].
name|template
operator|<
name|std
operator|::
name|size_t
name|_Len
operator|,
name|std
operator|::
name|size_t
name|_Align
operator|>
expr|struct
name|aligned_storage
expr_stmt|;
name|_GLIBCXX_END_NAMESPACE
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

