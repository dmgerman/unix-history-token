begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Versatile string utility -*- C++ -*-
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
comment|/** @file ext/vstring_util.h  *  This file is a GNU extension to the Standard C++ Library.  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VSTRING_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_VSTRING_UTIL_H
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
file|<ext/vstring_fwd.h>
end_include

begin_include
include|#
directive|include
file|<debug/debug.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_function.h>
end_include

begin_comment
comment|// For less
end_comment

begin_include
include|#
directive|include
file|<bits/functexcept.h>
end_include

begin_include
include|#
directive|include
file|<locale>
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_comment
comment|// For std::distance, srd::search.
end_comment

begin_include
include|#
directive|include
file|<bits/ostream_insert.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|,
name|typename
name|_Alloc
operator|>
expr|struct
name|__vstring_utility
block|{
typedef|typedef
name|typename
name|_Alloc
operator|::
name|template
name|rebind
operator|<
name|_CharT
operator|>
operator|::
name|other
name|_CharT_alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Traits
name|traits_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Traits
operator|::
name|char_type
name|value_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_CharT_alloc_type
operator|::
name|size_type
name|size_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_CharT_alloc_type
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_CharT_alloc_type
operator|::
name|const_pointer
name|const_pointer
expr_stmt|;
end_typedef

begin_comment
comment|// For __sso_string.
end_comment

begin_typedef
typedef|typedef
name|__gnu_cxx
operator|::
name|__normal_iterator
operator|<
name|pointer
operator|,
name|__gnu_cxx
operator|::
name|__versa_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|,
name|__sso_string_base
operator|>
expr|>
name|__sso_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__gnu_cxx
operator|::
name|__normal_iterator
operator|<
name|const_pointer
operator|,
name|__gnu_cxx
operator|::
name|__versa_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|,
name|__sso_string_base
operator|>
expr|>
name|__const_sso_iterator
expr_stmt|;
end_typedef

begin_comment
comment|// For __rc_string.
end_comment

begin_typedef
typedef|typedef
name|__gnu_cxx
operator|::
name|__normal_iterator
operator|<
name|pointer
operator|,
name|__gnu_cxx
operator|::
name|__versa_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|,
name|__rc_string_base
operator|>
expr|>
name|__rc_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__gnu_cxx
operator|::
name|__normal_iterator
operator|<
name|const_pointer
operator|,
name|__gnu_cxx
operator|::
name|__versa_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|,
name|__rc_string_base
operator|>
expr|>
name|__const_rc_iterator
expr_stmt|;
end_typedef

begin_comment
comment|// NB:  When the allocator is empty, deriving from it saves space
end_comment

begin_comment
comment|// (http://www.cantrip.org/emptyopt.html).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Alloc1
operator|>
expr|struct
name|_Alloc_hider
operator|:
name|public
name|_Alloc1
block|{
name|_Alloc_hider
argument_list|(
specifier|const
name|_Alloc1
operator|&
name|__a
argument_list|,
name|_CharT
operator|*
name|__ptr
argument_list|)
operator|:
name|_Alloc1
argument_list|(
name|__a
argument_list|)
block|,
name|_M_p
argument_list|(
argument|__ptr
argument_list|)
block|{ }
name|_CharT
operator|*
name|_M_p
block|;
comment|// The actual data.
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// For use in _M_construct (_S_construct) forward_iterator_tag.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Type
operator|>
specifier|static
name|bool
name|_S_is_null_pointer
argument_list|(
argument|_Type* __ptr
argument_list|)
block|{
return|return
name|__ptr
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Type
operator|>
specifier|static
name|bool
name|_S_is_null_pointer
argument_list|(
argument|_Type
argument_list|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_comment
comment|// When __n = 1 way faster than the general multichar
end_comment

begin_comment
comment|// traits_type::copy/move/assign.
end_comment

begin_function
specifier|static
name|void
name|_S_copy
parameter_list|(
name|_CharT
modifier|*
name|__d
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|,
name|size_type
name|__n
parameter_list|)
block|{
if|if
condition|(
name|__n
operator|==
literal|1
condition|)
name|traits_type
operator|::
name|assign
argument_list|(
operator|*
name|__d
argument_list|,
operator|*
name|__s
argument_list|)
expr_stmt|;
else|else
name|traits_type
operator|::
name|copy
argument_list|(
name|__d
argument_list|,
name|__s
argument_list|,
name|__n
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|_S_move
parameter_list|(
name|_CharT
modifier|*
name|__d
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|,
name|size_type
name|__n
parameter_list|)
block|{
if|if
condition|(
name|__n
operator|==
literal|1
condition|)
name|traits_type
operator|::
name|assign
argument_list|(
operator|*
name|__d
argument_list|,
operator|*
name|__s
argument_list|)
expr_stmt|;
else|else
name|traits_type
operator|::
name|move
argument_list|(
name|__d
argument_list|,
name|__s
argument_list|,
name|__n
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|_S_assign
parameter_list|(
name|_CharT
modifier|*
name|__d
parameter_list|,
name|size_type
name|__n
parameter_list|,
name|_CharT
name|__c
parameter_list|)
block|{
if|if
condition|(
name|__n
operator|==
literal|1
condition|)
name|traits_type
operator|::
name|assign
argument_list|(
operator|*
name|__d
argument_list|,
name|__c
argument_list|)
expr_stmt|;
else|else
name|traits_type
operator|::
name|assign
argument_list|(
name|__d
argument_list|,
name|__n
argument_list|,
name|__c
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// _S_copy_chars is a separate template to permit specialization
end_comment

begin_comment
comment|// to optimize for the common case of pointers as iterators.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Iterator
operator|>
specifier|static
name|void
name|_S_copy_chars
argument_list|(
argument|_CharT* __p
argument_list|,
argument|_Iterator __k1
argument_list|,
argument|_Iterator __k2
argument_list|)
block|{
for|for
control|(
init|;
name|__k1
operator|!=
name|__k2
condition|;
operator|++
name|__k1
operator|,
operator|++
name|__p
control|)
name|traits_type
operator|::
name|assign
argument_list|(
operator|*
name|__p
argument_list|,
operator|*
name|__k1
argument_list|)
expr_stmt|;
comment|// These types are off.
block|}
end_expr_stmt

begin_function
specifier|static
name|void
name|_S_copy_chars
parameter_list|(
name|_CharT
modifier|*
name|__p
parameter_list|,
name|__sso_iterator
name|__k1
parameter_list|,
name|__sso_iterator
name|__k2
parameter_list|)
block|{
name|_S_copy_chars
argument_list|(
name|__p
argument_list|,
name|__k1
operator|.
name|base
argument_list|()
argument_list|,
name|__k2
operator|.
name|base
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|_S_copy_chars
parameter_list|(
name|_CharT
modifier|*
name|__p
parameter_list|,
name|__const_sso_iterator
name|__k1
parameter_list|,
name|__const_sso_iterator
name|__k2
parameter_list|)
block|{
name|_S_copy_chars
argument_list|(
name|__p
argument_list|,
name|__k1
operator|.
name|base
argument_list|()
argument_list|,
name|__k2
operator|.
name|base
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|_S_copy_chars
parameter_list|(
name|_CharT
modifier|*
name|__p
parameter_list|,
name|__rc_iterator
name|__k1
parameter_list|,
name|__rc_iterator
name|__k2
parameter_list|)
block|{
name|_S_copy_chars
argument_list|(
name|__p
argument_list|,
name|__k1
operator|.
name|base
argument_list|()
argument_list|,
name|__k2
operator|.
name|base
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|_S_copy_chars
parameter_list|(
name|_CharT
modifier|*
name|__p
parameter_list|,
name|__const_rc_iterator
name|__k1
parameter_list|,
name|__const_rc_iterator
name|__k2
parameter_list|)
block|{
name|_S_copy_chars
argument_list|(
name|__p
argument_list|,
name|__k1
operator|.
name|base
argument_list|()
argument_list|,
name|__k2
operator|.
name|base
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|_S_copy_chars
parameter_list|(
name|_CharT
modifier|*
name|__p
parameter_list|,
name|_CharT
modifier|*
name|__k1
parameter_list|,
name|_CharT
modifier|*
name|__k2
parameter_list|)
block|{
name|_S_copy
argument_list|(
name|__p
argument_list|,
name|__k1
argument_list|,
name|__k2
operator|-
name|__k1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|_S_copy_chars
parameter_list|(
name|_CharT
modifier|*
name|__p
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__k1
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__k2
parameter_list|)
block|{
name|_S_copy
argument_list|(
name|__p
argument_list|,
name|__k1
argument_list|,
name|__k2
operator|-
name|__k1
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
unit|};
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VSTRING_UTIL_H */
end_comment

end_unit

