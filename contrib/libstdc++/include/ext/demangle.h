begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// C++ IA64 / g++ v3 demangler  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2003, 2004 Free Software Foundation, Inc.
end_comment

begin_comment
comment|// Written by Carlo Wood<carlo@alinoe.com>
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
comment|// This file implements demangling of "C++ ABI for Itanium"-mangled symbol
end_comment

begin_comment
comment|// and type names as described in Revision 1.73 of the C++ ABI as can be found
end_comment

begin_comment
comment|// at http://www.codesourcery.com/cxx-abi/abi.html#mangling
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEMANGLER_H
end_ifndef

begin_define
define|#
directive|define
name|_DEMANGLER_H
value|1
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<ext/new_allocator.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_DEMANGLER_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_CWDEBUG
value|0
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_DEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_DOUT
parameter_list|(
name|cntrl
parameter_list|,
name|data
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING2
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING3
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_RETURN
value|return M_result
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_RETURN2
value|return M_result
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_RETURN3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_FAILURE
define|\
value|do { M_result = false; return false; } while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_GLIBCXX_DEMANGLER_CWDEBUG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
name|namespace
name|demangler
block|{
enum|enum
name|substitution_nt
block|{
name|type
block|,
name|template_template_param
block|,
name|nested_name_prefix
block|,
name|nested_name_template_prefix
block|,
name|unscoped_template_name
block|}
enum|;
struct|struct
name|substitution_st
block|{
name|int
name|M_start_pos
decl_stmt|;
name|substitution_nt
name|M_type
decl_stmt|;
name|int
name|M_number_of_prefixes
decl_stmt|;
name|substitution_st
argument_list|(
argument|int start_pos
argument_list|,
argument|substitution_nt type
argument_list|,
argument|int number_of_prefixes
argument_list|)
block|:
name|M_start_pos
argument_list|(
name|start_pos
argument_list|)
operator|,
name|M_type
argument_list|(
name|type
argument_list|)
operator|,
name|M_number_of_prefixes
argument_list|(
argument|number_of_prefixes
argument_list|)
block|{ }
block|}
struct|;
enum|enum
name|simple_qualifier_nt
block|{
name|complex_or_imaginary
init|=
literal|'G'
block|,
name|pointer
init|=
literal|'P'
block|,
name|reference
init|=
literal|'R'
block|}
enum|;
enum|enum
name|cv_qualifier_nt
block|{
name|cv_qualifier
init|=
literal|'K'
block|}
enum|;
enum|enum
name|param_qualifier_nt
block|{
name|vendor_extension
init|=
literal|'U'
block|,
name|array
init|=
literal|'A'
block|,
name|pointer_to_member
init|=
literal|'M'
block|}
enum|;
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|=
name|__gnu_cxx
operator|::
name|new_allocator
operator|<
name|Tp
operator|>
expr|>
name|class
name|qualifier
expr_stmt|;
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|=
name|__gnu_cxx
operator|::
name|new_allocator
operator|<
name|Tp
operator|>
expr|>
name|class
name|qualifier_list
expr_stmt|;
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|=
name|__gnu_cxx
operator|::
name|new_allocator
operator|<
name|Tp
operator|>
expr|>
name|class
name|session
expr_stmt|;
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|class
name|qualifier
block|{
typedef|typedef
name|typename
name|Allocator
operator|::
name|template
name|rebind
operator|<
name|char
operator|>
operator|::
name|other
name|char_Allocator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|basic_string
operator|<
name|char
operator|,
name|std
operator|::
name|char_traits
operator|<
name|char
operator|>
operator|,
name|char_Allocator
operator|>
name|string_type
expr_stmt|;
name|private
label|:
name|char
name|M_qualifier1
decl_stmt|;
name|char
name|M_qualifier2
decl_stmt|;
name|char
name|M_qualifier3
decl_stmt|;
name|mutable
name|unsigned
name|char
name|M_cnt
decl_stmt|;
name|string_type
name|M_optional_type
decl_stmt|;
name|int
name|M_start_pos
decl_stmt|;
name|bool
name|M_part_of_substitution
decl_stmt|;
name|public
label|:
name|qualifier
argument_list|(
argument|int start_pos
argument_list|,
argument|simple_qualifier_nt simple_qualifier
argument_list|,
argument|int inside_substitution
argument_list|)
block|:
name|M_qualifier1
argument_list|(
name|simple_qualifier
argument_list|)
operator|,
name|M_start_pos
argument_list|(
name|start_pos
argument_list|)
operator|,
name|M_part_of_substitution
argument_list|(
argument|inside_substitution
argument_list|)
block|{ }
name|qualifier
argument_list|(
argument|int start_pos
argument_list|,
argument|cv_qualifier_nt
argument_list|,
argument|char const* start
argument_list|,
argument|int count
argument_list|,
argument|int inside_substitution
argument_list|)
operator|:
name|M_qualifier1
argument_list|(
name|start
index|[
literal|0
index|]
argument_list|)
operator|,
name|M_qualifier2
argument_list|(
operator|(
name|count
operator|>
literal|1
operator|)
operator|?
name|start
index|[
literal|1
index|]
operator|:
literal|'\0'
argument_list|)
operator|,
name|M_qualifier3
argument_list|(
operator|(
name|count
operator|>
literal|2
operator|)
operator|?
name|start
index|[
literal|2
index|]
operator|:
literal|'\0'
argument_list|)
operator|,
name|M_start_pos
argument_list|(
name|start_pos
argument_list|)
operator|,
name|M_part_of_substitution
argument_list|(
argument|inside_substitution
argument_list|)
block|{ }
name|qualifier
argument_list|(
argument|int start_pos
argument_list|,
argument|param_qualifier_nt param_qualifier
argument_list|,
argument|string_type optional_type
argument_list|,
argument|int inside_substitution
argument_list|)
operator|:
name|M_qualifier1
argument_list|(
name|param_qualifier
argument_list|)
operator|,
name|M_optional_type
argument_list|(
name|optional_type
argument_list|)
operator|,
name|M_start_pos
argument_list|(
name|start_pos
argument_list|)
operator|,
name|M_part_of_substitution
argument_list|(
argument|inside_substitution
argument_list|)
block|{ }
name|int
name|get_start_pos
argument_list|(
argument|void
argument_list|)
specifier|const
block|{
return|return
name|M_start_pos
return|;
block|}
name|char
name|first_qualifier
argument_list|(
name|void
argument_list|)
decl|const
block|{
name|M_cnt
operator|=
literal|1
expr_stmt|;
return|return
name|M_qualifier1
return|;
block|}
name|char
name|next_qualifier
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
operator|++
name|M_cnt
operator|==
literal|2
operator|)
condition|?
name|M_qualifier2
else|:
operator|(
operator|(
name|M_cnt
operator|==
literal|3
operator|)
condition|?
name|M_qualifier3
else|:
literal|0
operator|)
return|;
block|}
name|string_type
specifier|const
modifier|&
name|get_optional_type
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
name|M_optional_type
return|;
block|}
name|bool
name|part_of_substitution
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
name|M_part_of_substitution
return|;
block|}
if|#
directive|if
name|_GLIBCXX_DEMANGLER_CWDEBUG
name|friend
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ostream
operator|&
name|os
operator|,
name|qualifier
specifier|const
operator|&
name|qual
operator|)
block|{
name|os
operator|<<
operator|(
name|char
operator|)
name|qual
operator|.
name|M_qualifier1
block|;
if|if
condition|(
name|qual
operator|.
name|M_qualifier1
operator|==
name|vendor_extension
operator|||
name|qual
operator|.
name|M_qualifier1
operator|==
name|array
operator|||
name|qual
operator|.
name|M_qualifier1
operator|==
name|pointer_to_member
condition|)
name|os
operator|<<
literal|" ["
operator|<<
name|qual
operator|.
name|M_optional_type
operator|<<
literal|']'
expr_stmt|;
elseif|else
if|if
condition|(
name|qual
operator|.
name|M_qualifier1
operator|==
literal|'K'
operator|||
name|qual
operator|.
name|M_qualifier1
operator|==
literal|'V'
operator|||
name|qual
operator|.
name|M_qualifier1
operator|==
literal|'r'
condition|)
block|{
if|if
condition|(
name|qual
operator|.
name|M_qualifier2
condition|)
block|{
name|os
operator|<<
operator|(
name|char
operator|)
name|qual
operator|.
name|M_qualifier2
expr_stmt|;
if|if
condition|(
name|qual
operator|.
name|M_qualifier3
condition|)
name|os
operator|<<
operator|(
name|char
operator|)
name|qual
operator|.
name|M_qualifier3
expr_stmt|;
block|}
block|}
return|return
name|os
return|;
block|}
endif|#
directive|endif
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|class
name|qualifier_list
block|{
typedef|typedef
name|typename
name|Allocator
operator|::
name|template
name|rebind
operator|<
name|char
operator|>
operator|::
name|other
name|char_Allocator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|basic_string
operator|<
name|char
operator|,
name|std
operator|::
name|char_traits
operator|<
name|char
operator|>
operator|,
name|char_Allocator
operator|>
name|string_type
expr_stmt|;
name|private
label|:
name|mutable
name|bool
name|M_printing_suppressed
decl_stmt|;
typedef|typedef
name|qualifier
operator|<
name|Tp
operator|,
name|Allocator
operator|>
name|qual
expr_stmt|;
typedef|typedef
name|typename
name|Allocator
operator|::
name|template
name|rebind
operator|<
name|qual
operator|>
operator|::
name|other
name|qual_Allocator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|qual
operator|,
name|qual_Allocator
operator|>
name|qual_vector
expr_stmt|;
name|qual_vector
name|M_qualifier_starts
decl_stmt|;
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|&
name|M_demangler
expr_stmt|;
name|void
name|decode_KVrA
argument_list|(
name|string_type
operator|&
name|prefix
argument_list|,
name|string_type
operator|&
name|postfix
argument_list|,
name|int
name|cvq
argument_list|,
name|typename
name|qual_vector
operator|::
name|const_reverse_iterator
specifier|const
operator|&
name|iter_array
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|qualifier_list
argument_list|(
name|session
operator|<
name|Tp
argument_list|,
name|Allocator
operator|>
operator|&
name|demangler_obj
argument_list|)
operator|:
name|M_printing_suppressed
argument_list|(
name|false
argument_list|)
operator|,
name|M_demangler
argument_list|(
argument|demangler_obj
argument_list|)
block|{ }
name|void
name|add_qualifier_start
argument_list|(
argument|simple_qualifier_nt simple_qualifier
argument_list|,
argument|int start_pos
argument_list|,
argument|int inside_substitution
argument_list|)
block|{
name|M_qualifier_starts
operator|.
name|push_back
argument_list|(
name|qualifier
operator|<
name|Tp
argument_list|,
name|Allocator
operator|>
operator|(
name|start_pos
operator|,
name|simple_qualifier
operator|,
name|inside_substitution
operator|)
argument_list|)
block|; }
name|void
name|add_qualifier_start
argument_list|(
argument|cv_qualifier_nt cv_qualifier
argument_list|,
argument|int start_pos
argument_list|,
argument|int count
argument_list|,
argument|int inside_substitution
argument_list|)
block|{
name|M_qualifier_starts
operator|.
name|push_back
argument_list|(
name|qualifier
operator|<
name|Tp
argument_list|,
name|Allocator
operator|>
operator|(
name|start_pos
operator|,
name|cv_qualifier
operator|,
operator|&
name|M_demangler
operator|.
name|M_str
index|[
name|start_pos
index|]
operator|,
name|count
operator|,
name|inside_substitution
operator|)
argument_list|)
block|; }
name|void
name|add_qualifier_start
argument_list|(
argument|param_qualifier_nt param_qualifier
argument_list|,
argument|int start_pos
argument_list|,
argument|string_type optional_type
argument_list|,
argument|int inside_substitution
argument_list|)
block|{
name|M_qualifier_starts
operator|.
name|push_back
argument_list|(
name|qualifier
operator|<
name|Tp
argument_list|,
name|Allocator
operator|>
operator|(
name|start_pos
operator|,
name|param_qualifier
operator|,
name|optional_type
operator|,
name|inside_substitution
operator|)
argument_list|)
block|; }
name|void
name|decode_qualifiers
argument_list|(
argument|string_type& prefix
argument_list|,
argument|string_type& postfix
argument_list|,
argument|bool member_function_pointer_qualifiers
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|suppressed
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
name|M_printing_suppressed
return|;
block|}
name|void
name|printing_suppressed
parameter_list|(
name|void
parameter_list|)
block|{
name|M_printing_suppressed
operator|=
name|true
expr_stmt|;
block|}
name|size_t
name|size
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
name|M_qualifier_starts
operator|.
name|size
argument_list|()
return|;
block|}
if|#
directive|if
name|_GLIBCXX_DEMANGLER_CWDEBUG
name|friend
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ostream
operator|&
name|os
operator|,
name|qualifier_list
specifier|const
operator|&
name|list
operator|)
block|{
name|typename
name|qual_vector
operator|::
name|const_iterator
name|iter
operator|=
name|list
operator|.
name|M_qualifier_starts
operator|.
name|begin
argument_list|()
block|;
if|if
condition|(
name|iter
operator|!=
name|list
operator|.
name|M_qualifier_starts
operator|.
name|end
argument_list|()
condition|)
block|{
name|os
operator|<<
literal|"{ "
operator|<<
operator|*
name|iter
expr_stmt|;
while|while
condition|(
operator|++
name|iter
operator|!=
name|list
operator|.
name|M_qualifier_starts
operator|.
name|end
argument_list|()
condition|)
name|os
operator|<<
literal|", "
operator|<<
operator|*
name|iter
expr_stmt|;
name|os
operator|<<
literal|" }"
expr_stmt|;
block|}
else|else
name|os
operator|<<
literal|"{ }"
expr_stmt|;
return|return
name|os
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
unit|};
struct|struct
name|implementation_details
block|{
name|private
label|:
name|unsigned
name|int
name|M_style
decl_stmt|;
name|public
label|:
comment|// The following flags change the behaviour of the demangler.  The
comment|// default behaviour is that none of these flags is set.
specifier|static
name|unsigned
name|int
specifier|const
name|style_void
init|=
literal|1
decl_stmt|;
comment|// Default behaviour:				int f()
comment|// Use (void) instead of ():			int f(void)
specifier|static
name|unsigned
name|int
specifier|const
name|style_literal
init|=
literal|2
decl_stmt|;
comment|// Default behaviour:				(long)13,
comment|//						(unsigned long long)19
comment|// Use extensions 'u', 'l' and 'll' for integral
comment|// literals (as in template arguments):		13l, 19ull
specifier|static
name|unsigned
name|int
specifier|const
name|style_literal_int
init|=
literal|4
decl_stmt|;
comment|// Default behaviour:				4
comment|// Use also an explicit
comment|//   cast for int in literals:			(int)4
specifier|static
name|unsigned
name|int
specifier|const
name|style_compact_expr_ops
init|=
literal|8
decl_stmt|;
comment|// Default behaviour:				(i)< (3), sizeof (int)
comment|// Don't output spaces around
comment|//   operators in expressions:			(i)<(3), sizeof(int)
specifier|static
name|unsigned
name|int
specifier|const
name|style_sizeof_typename
init|=
literal|16
decl_stmt|;
comment|// Default behaviour:				sizeof (X::t)
comment|// Put 'typename' infront of<nested-name>
comment|// types inside a 'sizeof':			sizeof (typename X::t)
name|public
label|:
name|implementation_details
argument_list|(
argument|unsigned int style_flags =
literal|0
argument_list|)
block|:
name|M_style
argument_list|(
argument|style_flags
argument_list|)
block|{ }
name|virtual
operator|~
name|implementation_details
argument_list|()
block|{ }
name|bool
name|get_style_void
argument_list|(
argument|void
argument_list|)
specifier|const
block|{
return|return
operator|(
name|M_style
operator|&
name|style_void
operator|)
return|;
block|}
name|bool
name|get_style_literal
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
name|M_style
operator|&
name|style_literal
operator|)
return|;
block|}
name|bool
name|get_style_literal_int
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
name|M_style
operator|&
name|style_literal_int
operator|)
return|;
block|}
name|bool
name|get_style_compact_expr_ops
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
name|M_style
operator|&
name|style_compact_expr_ops
operator|)
return|;
block|}
name|bool
name|get_style_sizeof_typename
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
name|M_style
operator|&
name|style_sizeof_typename
operator|)
return|;
block|}
comment|// This can be overridden by user implementations.
name|virtual
name|bool
name|decode_real
argument_list|(
name|char
operator|*
comment|/* output */
argument_list|,
name|unsigned
name|long
operator|*
comment|/* input */
argument_list|,
name|size_t
comment|/* size_of_real */
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
block|}
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|class
name|session
block|{
name|public
operator|:
name|friend
name|class
name|qualifier_list
operator|<
name|Tp
block|,
name|Allocator
operator|>
block|;
typedef|typedef
name|typename
name|Allocator
operator|::
name|template
name|rebind
operator|<
name|char
operator|>
operator|::
name|other
name|char_Allocator
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|basic_string
operator|<
name|char
operator|,
name|std
operator|::
name|char_traits
operator|<
name|char
operator|>
operator|,
name|char_Allocator
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|char
specifier|const
modifier|*
name|M_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|M_pos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|M_maxpos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|M_result
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|M_inside_template_args
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|M_inside_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|M_inside_substitution
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|M_saw_destructor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|M_name_is_cdtor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|M_name_is_template
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|M_name_is_conversion_operator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|M_template_args_need_space
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|string_type
name|M_function_name
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typename
name|Allocator
operator|::
name|template
name|rebind
operator|<
name|int
operator|>
operator|::
name|other
name|int_Allocator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Allocator
operator|::
name|template
name|rebind
operator|<
name|substitution_st
operator|>
operator|::
name|other
name|subst_Allocator
expr_stmt|;
end_typedef

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|int
operator|,
name|int_Allocator
operator|>
name|M_template_arg_pos
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|M_template_arg_pos_offset
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|substitution_st
operator|,
name|subst_Allocator
operator|>
name|M_substitutions_pos
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|implementation_details
specifier|const
modifier|&
name|M_implementation_details
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typename
name|Allocator
operator|::
name|template
name|rebind
operator|<
name|qualifier_list
operator|<
name|Allocator
operator|>
expr|>
operator|::
name|other
name|qualifier_list_Allocator
expr_stmt|;
end_typedef

begin_decl_stmt
name|qualifier_list_Allocator
name|M_qualifier_list_alloc
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|_GLIBCXX_DEMANGLER_CWDEBUG
end_if

begin_decl_stmt
name|bool
name|M_inside_add_substitution
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_label
name|public
label|:
end_label

begin_macro
name|explicit
end_macro

begin_macro
name|session
argument_list|(
argument|char const* in
argument_list|,
argument|int len
argument_list|,
argument|implementation_details const& id = implementation_details()
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|M_str
argument_list|(
name|in
argument_list|)
operator|,
name|M_pos
argument_list|(
literal|0
argument_list|)
operator|,
name|M_maxpos
argument_list|(
name|len
operator|-
literal|1
argument_list|)
operator|,
name|M_result
argument_list|(
name|true
argument_list|)
operator|,
name|M_inside_template_args
argument_list|(
literal|0
argument_list|)
operator|,
name|M_inside_type
argument_list|(
literal|0
argument_list|)
operator|,
name|M_inside_substitution
argument_list|(
literal|0
argument_list|)
operator|,
name|M_saw_destructor
argument_list|(
name|false
argument_list|)
operator|,
name|M_name_is_cdtor
argument_list|(
name|false
argument_list|)
operator|,
name|M_name_is_template
argument_list|(
name|false
argument_list|)
operator|,
name|M_name_is_conversion_operator
argument_list|(
name|false
argument_list|)
operator|,
name|M_template_args_need_space
argument_list|(
name|false
argument_list|)
operator|,
name|M_template_arg_pos_offset
argument_list|(
literal|0
argument_list|)
operator|,
name|M_implementation_details
argument_list|(
name|id
argument_list|)
if|#
directive|if
name|_GLIBCXX_DEMANGLER_CWDEBUG
operator|,
name|M_inside_add_substitution
argument_list|(
argument|false
argument_list|)
endif|#
directive|endif
block|{ }
specifier|static
name|int
name|decode_encoding
argument_list|(
argument|string_type& output
argument_list|,
argument|char const* input
argument_list|,
argument|int len
argument_list|,
argument|implementation_details const& id = implementation_details()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|decode_type
argument_list|(
name|string_type
operator|&
name|output
argument_list|,
name|qualifier_list
operator|<
name|Tp
argument_list|,
name|Allocator
operator|>
operator|*
name|qualifiers
operator|=
name|NULL
argument_list|)
block|{
name|string_type
name|postfix
decl_stmt|;
name|bool
name|res
init|=
name|decode_type_with_postfix
argument_list|(
name|output
argument_list|,
name|postfix
argument_list|,
name|qualifiers
argument_list|)
decl_stmt|;
name|output
operator|+=
name|postfix
expr_stmt|;
return|return
name|res
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|remaining_input_characters
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
name|current
argument_list|()
operator|!=
literal|0
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|char
name|current
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
name|M_pos
operator|>
name|M_maxpos
operator|)
condition|?
literal|0
else|:
name|M_str
index|[
name|M_pos
index|]
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|char
name|next_peek
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
name|M_pos
operator|>=
name|M_maxpos
operator|)
condition|?
literal|0
else|:
name|M_str
index|[
name|M_pos
operator|+
literal|1
index|]
return|;
block|}
end_decl_stmt

begin_function
name|char
name|next
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|M_pos
operator|>=
name|M_maxpos
operator|)
condition|?
literal|0
else|:
name|M_str
index|[
operator|++
name|M_pos
index|]
return|;
block|}
end_function

begin_function
name|char
name|eat_current
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|M_pos
operator|>
name|M_maxpos
operator|)
condition|?
literal|0
else|:
name|M_str
index|[
name|M_pos
operator|++
index|]
return|;
block|}
end_function

begin_function
name|void
name|store
parameter_list|(
name|int
modifier|&
name|saved_pos
parameter_list|)
block|{
name|saved_pos
operator|=
name|M_pos
expr_stmt|;
block|}
end_function

begin_function
name|void
name|restore
parameter_list|(
name|int
name|saved_pos
parameter_list|)
block|{
name|M_pos
operator|=
name|saved_pos
expr_stmt|;
name|M_result
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|add_substitution
parameter_list|(
name|int
name|start_pos
parameter_list|,
name|substitution_nt
name|sub_type
parameter_list|,
name|int
name|number_of_prefixes
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|decode_type_with_postfix
argument_list|(
name|string_type
operator|&
name|prefix
argument_list|,
name|string_type
operator|&
name|postfix
argument_list|,
name|qualifier_list
operator|<
name|Tp
argument_list|,
name|Allocator
operator|>
operator|*
name|qualifiers
operator|=
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|decode_bare_function_type
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_builtin_type
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_call_offset
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_class_enum_type
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_expression
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_literal
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_local_name
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_name
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|,
name|string_type
modifier|&
name|nested_name_qualifiers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_nested_name
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|,
name|string_type
modifier|&
name|qualifiers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_number
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_operator_name
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_source_name
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|decode_substitution
argument_list|(
name|string_type
operator|&
name|output
argument_list|,
name|qualifier_list
operator|<
name|Tp
argument_list|,
name|Allocator
operator|>
operator|*
name|qualifiers
operator|=
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|decode_template_args
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|decode_template_param
argument_list|(
name|string_type
operator|&
name|output
argument_list|,
name|qualifier_list
operator|<
name|Tp
argument_list|,
name|Allocator
operator|>
operator|*
name|qualifiers
operator|=
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|decode_unqualified_name
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_unscoped_name
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_non_negative_decimal_integer
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_special_name
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|decode_real
parameter_list|(
name|string_type
modifier|&
name|output
parameter_list|,
name|size_t
name|size_of_real
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
if|#
directive|if
operator|!
name|_GLIBCXX_DEMANGLER_CWDEBUG
specifier|inline
endif|#
directive|endif
name|void
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|add_substitution
argument_list|(
argument|int start_pos
argument_list|,
argument|substitution_nt sub_type
argument_list|,
argument|int number_of_prefixes =
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|M_inside_substitution
condition|)
block|{
if|#
directive|if
name|_GLIBCXX_DEMANGLER_CWDEBUG
if|if
condition|(
name|M_inside_add_substitution
condition|)
return|return;
endif|#
directive|endif
name|M_substitutions_pos
operator|.
name|push_back
argument_list|(
name|substitution_st
argument_list|(
name|start_pos
argument_list|,
name|sub_type
argument_list|,
name|number_of_prefixes
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|_GLIBCXX_DEMANGLER_CWDEBUG
if|if
condition|(
operator|!
name|DEBUGCHANNELS
operator|::
name|dc
operator|::
name|demangler
operator|.
name|is_on
argument_list|()
condition|)
return|return;
name|string_type
name|substitution_name
argument_list|(
literal|"S"
argument_list|)
decl_stmt|;
name|int
name|n
init|=
name|M_substitutions_pos
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
name|substitution_name
operator|+=
operator|(
name|n
operator|<=
literal|10
operator|)
condition|?
call|(
name|char
call|)
argument_list|(
name|n
operator|+
literal|'0'
operator|-
literal|1
argument_list|)
else|:
call|(
name|char
call|)
argument_list|(
name|n
operator|+
literal|'A'
operator|-
literal|11
argument_list|)
expr_stmt|;
name|substitution_name
operator|+=
literal|'_'
expr_stmt|;
name|string_type
name|subst
decl_stmt|;
name|int
name|saved_pos
init|=
name|M_pos
decl_stmt|;
name|M_pos
operator|=
name|start_pos
expr_stmt|;
name|M_inside_add_substitution
operator|=
name|true
expr_stmt|;
name|_GLIBCXX_DEMANGLER_DEBUG
argument_list|(
name|dc
operator|::
name|demangler
operator|.
name|off
argument_list|()
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|sub_type
condition|)
block|{
case|case
name|type
case|:
name|decode_type
argument_list|(
name|subst
argument_list|)
expr_stmt|;
break|break;
case|case
name|template_template_param
case|:
name|decode_template_param
argument_list|(
name|subst
argument_list|)
expr_stmt|;
break|break;
case|case
name|nested_name_prefix
case|:
case|case
name|nested_name_template_prefix
case|:
for|for
control|(
name|int
name|cnt
init|=
name|number_of_prefixes
init|;
name|cnt
operator|>
literal|0
condition|;
operator|--
name|cnt
control|)
block|{
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'I'
condition|)
block|{
name|subst
operator|+=
literal|' '
expr_stmt|;
name|decode_template_args
argument_list|(
name|subst
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
if|if
condition|(
name|cnt
operator|<
name|number_of_prefixes
condition|)
name|subst
operator|+=
literal|"::"
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'S'
condition|)
name|decode_substitution
argument_list|(
name|subst
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'T'
condition|)
name|decode_template_param
argument_list|(
name|subst
argument_list|)
expr_stmt|;
else|else
name|decode_unqualified_name
argument_list|(
name|subst
argument_list|)
expr_stmt|;
block|}
end_else

begin_empty_stmt
unit|} 	      break
empty_stmt|;
end_empty_stmt

begin_case
case|case
name|unscoped_template_name
case|:
end_case

begin_expr_stmt
name|decode_unscoped_name
argument_list|(
name|subst
argument_list|)
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_expr_stmt
unit|} 	  M_pos
operator|=
name|saved_pos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_DEBUG
argument_list|(
name|dc
operator|::
name|demangler
operator|.
name|on
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_DOUT
argument_list|(
name|dc
operator|::
name|demangler
argument_list|,
literal|"Adding substitution "
operator|<<
name|substitution_name
operator|<<
literal|" : "
operator|<<
name|subst
operator|<<
literal|" (from "
operator|<<
name|location_ct
argument_list|(
operator|(
name|char
operator|*
operator|)
name|__builtin_return_address
argument_list|(
literal|0
argument_list|)
operator|+
name|builtin_return_address_offset
argument_list|)
operator|<<
literal|"<- "
operator|<<
name|location_ct
argument_list|(
operator|(
name|char
operator|*
operator|)
name|__builtin_return_address
argument_list|(
literal|1
argument_list|)
operator|+
name|builtin_return_address_offset
argument_list|)
operator|<<
literal|"<- "
operator|<<
name|location_ct
argument_list|(
operator|(
name|char
operator|*
operator|)
name|__builtin_return_address
argument_list|(
literal|2
argument_list|)
operator|+
name|builtin_return_address_offset
argument_list|)
operator|<<
literal|")."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|M_inside_add_substitution
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}       }
comment|// We don't want to depend on locale (or include<cctype> for that matter).
end_comment

begin_comment
comment|// We also don't want to use "safe-ctype.h" because that headerfile is not
end_comment

begin_comment
comment|// available to the users.
end_comment

begin_function
specifier|inline
name|bool
name|isdigit
parameter_list|(
name|char
name|c
parameter_list|)
block|{
return|return
name|c
operator|>=
literal|'0'
operator|&&
name|c
operator|<=
literal|'9'
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|islower
parameter_list|(
name|char
name|c
parameter_list|)
block|{
return|return
name|c
operator|>=
literal|'a'
operator|&&
name|c
operator|<=
literal|'z'
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|isupper
parameter_list|(
name|char
name|c
parameter_list|)
block|{
return|return
name|c
operator|>=
literal|'A'
operator|&&
name|c
operator|<=
literal|'Z'
return|;
block|}
end_function

begin_function
specifier|inline
name|char
name|tolower
parameter_list|(
name|char
name|c
parameter_list|)
block|{
return|return
name|isupper
argument_list|(
name|c
argument_list|)
condition|?
name|c
operator|-
literal|'A'
operator|+
literal|'a'
else|:
name|c
return|;
block|}
end_function

begin_comment
comment|//
end_comment

begin_comment
comment|//<non-negative decimal integer> ::= 0
end_comment

begin_comment
comment|//                                ::= 1|2|3|4|5|6|7|8|9 [<digit>+]
end_comment

begin_comment
comment|//<digit>                        ::= 0|1|2|3|4|5|6|7|8|9
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_non_negative_decimal_integer
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|char
name|c
operator|=
name|current
argument_list|()
block|;
if|if
condition|(
name|c
operator|==
literal|'0'
condition|)
block|{
name|output
operator|+=
literal|'0'
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
operator|!
name|isdigit
argument_list|(
name|c
argument_list|)
condition|)
name|M_result
operator|=
name|false
expr_stmt|;
end_elseif

begin_else
else|else
block|{
do|do
block|{
name|output
operator|+=
name|c
expr_stmt|;
block|}
do|while
condition|(
name|isdigit
argument_list|(
operator|(
name|c
operator|=
name|next
argument_list|()
operator|)
argument_list|)
condition|)
do|;
block|}
end_else

begin_return
return|return
name|M_result
return|;
end_return

begin_comment
unit|}
comment|//<number> ::= [n]<non-negative decimal integer>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_number
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_number"
argument_list|)
block|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'n'
condition|)
name|decode_non_negative_decimal_integer
argument_list|(
name|output
argument_list|)
expr_stmt|;
else|else
block|{
name|output
operator|+=
literal|'-'
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
name|decode_non_negative_decimal_integer
argument_list|(
name|output
argument_list|)
expr_stmt|;
block|}
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<builtin-type> ::= v  # void
end_comment

begin_comment
comment|//                ::= w  # wchar_t
end_comment

begin_comment
comment|//                ::= b  # bool
end_comment

begin_comment
comment|//                ::= c  # char
end_comment

begin_comment
comment|//                ::= a  # signed char
end_comment

begin_comment
comment|//                ::= h  # unsigned char
end_comment

begin_comment
comment|//                ::= s  # short
end_comment

begin_comment
comment|//                ::= t  # unsigned short
end_comment

begin_comment
comment|//                ::= i  # int
end_comment

begin_comment
comment|//                ::= j  # unsigned int
end_comment

begin_comment
comment|//                ::= l  # long
end_comment

begin_comment
comment|//                ::= m  # unsigned long
end_comment

begin_comment
comment|//                ::= x  # long long, __int64
end_comment

begin_comment
comment|//                ::= y  # unsigned long long, __int64
end_comment

begin_comment
comment|//                ::= n  # __int128
end_comment

begin_comment
comment|//                ::= o  # unsigned __int128
end_comment

begin_comment
comment|//                ::= f  # float
end_comment

begin_comment
comment|//                ::= d  # double
end_comment

begin_comment
comment|//                ::= e  # long double, __float80
end_comment

begin_comment
comment|//                ::= g  # __float128
end_comment

begin_comment
comment|//                ::= z  # ellipsis
end_comment

begin_comment
comment|//                ::= u<source-name>    # vendor extended type
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
unit|char
specifier|const
modifier|*
specifier|const
name|builtin_type_c
index|[
literal|26
index|]
init|=
block|{
literal|"signed char"
block|,
comment|// a
literal|"bool"
block|,
comment|// b
literal|"char"
block|,
comment|// c
literal|"double"
block|,
comment|// d
literal|"long double"
block|,
comment|// e
literal|"float"
block|,
comment|// f
literal|"__float128"
block|,
comment|// g
literal|"unsigned char"
block|,
comment|// h
literal|"int"
block|,
comment|// i
literal|"unsigned int"
block|,
comment|// j
name|NULL
block|,
comment|// k
literal|"long"
block|,
comment|// l
literal|"unsigned long"
block|,
comment|// m
literal|"__int128"
block|,
comment|// n
literal|"unsigned __int128"
block|,
comment|// o
name|NULL
block|,
comment|// p
name|NULL
block|,
comment|// q
name|NULL
block|,
comment|// r
literal|"short"
block|,
comment|// s
literal|"unsigned short"
block|,
comment|// t
name|NULL
block|,
comment|// u
literal|"void"
block|,
comment|// v
literal|"wchar_t"
block|,
comment|// w
literal|"long long"
block|,
comment|// x
literal|"unsigned long long"
block|,
comment|// y
literal|"..."
comment|// z
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_builtin_type
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_builtin_type"
argument_list|)
block|;
name|char
specifier|const
operator|*
name|bt
block|;
if|if
condition|(
operator|!
name|islower
argument_list|(
name|current
argument_list|()
argument_list|)
operator|||
operator|!
operator|(
name|bt
operator|=
name|builtin_type_c
index|[
name|current
argument_list|()
operator|-
literal|'a'
index|]
operator|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
name|bt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<class-enum-type> ::=<name>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_class_enum_type
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_class_enum_type"
argument_list|)
block|;
name|string_type
name|nested_name_qualifiers
block|;
if|if
condition|(
operator|!
name|decode_name
argument_list|(
name|output
argument_list|,
name|nested_name_qualifiers
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
name|nested_name_qualifiers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<substitution> ::=
end_comment

begin_comment
comment|//   S<seq-id> _
end_comment

begin_comment
comment|//   S_
end_comment

begin_comment
comment|//   St # ::std::
end_comment

begin_comment
comment|//   Sa # ::std::allocator
end_comment

begin_comment
comment|//   Sb # ::std::basic_string
end_comment

begin_comment
comment|//   Ss # ::std::basic_string<char, std::char_traits<char>,
end_comment

begin_comment
comment|//                            std::allocator<char>>
end_comment

begin_comment
comment|//   Si # ::std::basic_istream<char,  std::char_traits<char>>
end_comment

begin_comment
comment|//   So # ::std::basic_ostream<char,  std::char_traits<char>>
end_comment

begin_comment
comment|//   Sd # ::std::basic_iostream<char, std::char_traits<char>>
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<seq-id> ::=
end_comment

begin_comment
comment|//   0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z
end_comment

begin_comment
comment|//       [<seq-id>]	# Base 36 number
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_substitution
argument_list|(
argument|string_type& output
argument_list|,
argument|qualifier_list<Tp
argument_list|,
argument|Allocator>* qualifiers
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_substitution"
argument_list|)
block|;
name|unsigned
name|int
name|value
operator|=
literal|0
block|;
name|char
name|c
operator|=
name|next
argument_list|()
block|;
if|if
condition|(
name|c
operator|!=
literal|'_'
condition|)
block|{
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'a'
case|:
block|{
name|output
operator|+=
literal|"std::allocator"
expr_stmt|;
if|if
condition|(
operator|!
name|M_inside_template_args
condition|)
block|{
name|M_function_name
operator|=
literal|"allocator"
expr_stmt|;
name|M_name_is_template
operator|=
name|true
expr_stmt|;
name|M_name_is_cdtor
operator|=
name|false
expr_stmt|;
name|M_name_is_conversion_operator
operator|=
name|false
expr_stmt|;
block|}
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|qualifiers
condition|)
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} 	    case
literal|'b'
operator|:
block|{
name|output
operator|+=
literal|"std::basic_string"
block|;
if|if
condition|(
operator|!
name|M_inside_template_args
condition|)
block|{
name|M_function_name
operator|=
literal|"basic_string"
expr_stmt|;
name|M_name_is_template
operator|=
name|true
expr_stmt|;
name|M_name_is_cdtor
operator|=
name|false
expr_stmt|;
name|M_name_is_conversion_operator
operator|=
name|false
expr_stmt|;
block|}
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|qualifiers
condition|)
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} 	    case
literal|'d'
operator|:
name|output
operator|+=
literal|"std::iostream"
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|M_inside_template_args
condition|)
block|{
name|M_function_name
operator|=
literal|"iostream"
expr_stmt|;
name|M_name_is_template
operator|=
name|true
expr_stmt|;
name|M_name_is_cdtor
operator|=
name|false
expr_stmt|;
name|M_name_is_conversion_operator
operator|=
name|false
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|qualifiers
condition|)
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_case
case|case
literal|'i'
case|:
end_case

begin_expr_stmt
name|output
operator|+=
literal|"std::istream"
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|M_inside_template_args
condition|)
block|{
name|M_function_name
operator|=
literal|"istream"
expr_stmt|;
name|M_name_is_template
operator|=
name|true
expr_stmt|;
name|M_name_is_cdtor
operator|=
name|false
expr_stmt|;
name|M_name_is_conversion_operator
operator|=
name|false
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|qualifiers
condition|)
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_case
case|case
literal|'o'
case|:
end_case

begin_expr_stmt
name|output
operator|+=
literal|"std::ostream"
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|M_inside_template_args
condition|)
block|{
name|M_function_name
operator|=
literal|"ostream"
expr_stmt|;
name|M_name_is_template
operator|=
name|true
expr_stmt|;
name|M_name_is_cdtor
operator|=
name|false
expr_stmt|;
name|M_name_is_conversion_operator
operator|=
name|false
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|qualifiers
condition|)
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_case
case|case
literal|'s'
case|:
end_case

begin_expr_stmt
name|output
operator|+=
literal|"std::string"
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|M_inside_template_args
condition|)
block|{
name|M_function_name
operator|=
literal|"string"
expr_stmt|;
name|M_name_is_template
operator|=
name|true
expr_stmt|;
name|M_name_is_cdtor
operator|=
name|false
expr_stmt|;
name|M_name_is_conversion_operator
operator|=
name|false
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|qualifiers
condition|)
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_case
case|case
literal|'t'
case|:
end_case

begin_expr_stmt
name|output
operator|+=
literal|"std"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|qualifiers
condition|)
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_default
default|default:
end_default

begin_for
for|for
control|(
init|;
condition|;
name|c
operator|=
name|next
argument_list|()
control|)
block|{
if|if
condition|(
name|isdigit
argument_list|(
name|c
argument_list|)
condition|)
name|value
operator|=
name|value
operator|*
literal|36
operator|+
name|c
operator|-
literal|'0'
expr_stmt|;
elseif|else
if|if
condition|(
name|isupper
argument_list|(
name|c
argument_list|)
condition|)
name|value
operator|=
name|value
operator|*
literal|36
operator|+
name|c
operator|-
literal|'A'
operator|+
literal|10
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|==
literal|'_'
condition|)
break|break;
else|else
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
end_for

begin_expr_stmt
operator|++
name|value
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_expr_stmt
unit|} 	}
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|value
operator|>=
name|M_substitutions_pos
operator|.
name|size
argument_list|()
operator|||
name|M_inside_type
operator|>
literal|20
condition|)
comment|// Rather than core dump.
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_if

begin_expr_stmt
operator|++
name|M_inside_substitution
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|saved_pos
init|=
name|M_pos
decl_stmt|;
end_decl_stmt

begin_function_decl
name|substitution_st
modifier|&
name|substitution
parameter_list|(
name|M_substitutions_pos
index|[
name|value
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|M_pos
operator|=
name|substitution
operator|.
name|M_start_pos
expr_stmt|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|substitution
operator|.
name|M_type
condition|)
block|{
case|case
name|type
case|:
name|decode_type
argument_list|(
name|output
argument_list|,
name|qualifiers
argument_list|)
expr_stmt|;
break|break;
case|case
name|template_template_param
case|:
name|decode_template_param
argument_list|(
name|output
argument_list|,
name|qualifiers
argument_list|)
expr_stmt|;
break|break;
case|case
name|nested_name_prefix
case|:
case|case
name|nested_name_template_prefix
case|:
for|for
control|(
name|int
name|cnt
init|=
name|substitution
operator|.
name|M_number_of_prefixes
init|;
name|cnt
operator|>
literal|0
condition|;
operator|--
name|cnt
control|)
block|{
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'I'
condition|)
block|{
if|if
condition|(
name|M_template_args_need_space
condition|)
name|output
operator|+=
literal|' '
expr_stmt|;
name|M_template_args_need_space
operator|=
name|false
expr_stmt|;
if|if
condition|(
operator|!
name|decode_template_args
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|cnt
operator|<
name|substitution
operator|.
name|M_number_of_prefixes
condition|)
name|output
operator|+=
literal|"::"
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'S'
condition|)
block|{
if|if
condition|(
operator|!
name|decode_substitution
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|decode_unqualified_name
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
block|}
if|if
condition|(
name|qualifiers
condition|)
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
break|break;
case|case
name|unscoped_template_name
case|:
name|decode_unscoped_name
argument_list|(
name|output
argument_list|)
expr_stmt|;
if|if
condition|(
name|qualifiers
condition|)
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
break|break;
block|}
end_switch

begin_expr_stmt
name|M_pos
operator|=
name|saved_pos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|--
name|M_inside_substitution
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<template-param> ::= T_			# first template parameter
end_comment

begin_comment
comment|//                  ::= T<parameter-2 non-negative number> _
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_template_param
argument_list|(
argument|string_type& output
argument_list|,
argument|qualifier_list<Tp
argument_list|,
argument|Allocator>* qualifiers
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_template_parameter"
argument_list|)
block|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'T'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|unsigned
name|int
name|value
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
operator|(
name|c
operator|=
name|next
argument_list|()
operator|)
operator|!=
literal|'_'
condition|)
block|{
while|while
condition|(
name|isdigit
argument_list|(
name|c
argument_list|)
condition|)
block|{
name|value
operator|=
name|value
operator|*
literal|10
operator|+
name|c
operator|-
literal|'0'
expr_stmt|;
name|c
operator|=
name|next
argument_list|()
expr_stmt|;
block|}
operator|++
name|value
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|eat_current
argument_list|()
operator|!=
literal|'_'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_if

begin_expr_stmt
name|value
operator|+=
name|M_template_arg_pos_offset
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|value
operator|>=
name|M_template_arg_pos
operator|.
name|size
argument_list|()
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_if

begin_decl_stmt
name|int
name|saved_pos
init|=
name|M_pos
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|M_pos
operator|=
name|M_template_arg_pos
index|[
name|value
index|]
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|M_inside_type
operator|>
literal|20
condition|)
comment|// Rather than core dump.
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_if

begin_expr_stmt
operator|++
name|M_inside_substitution
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'X'
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
name|decode_expression
argument_list|(
name|output
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'L'
condition|)
name|decode_literal
argument_list|(
name|output
argument_list|)
expr_stmt|;
else|else
name|decode_type
argument_list|(
name|output
argument_list|,
name|qualifiers
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
operator|--
name|M_inside_substitution
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|M_pos
operator|=
name|saved_pos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_real
argument_list|(
argument|string_type& output
argument_list|,
argument|size_t size_of_real
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_real"
argument_list|)
block|;
name|unsigned
name|long
name|words
index|[
literal|4
index|]
block|;
comment|// 32 bit per long, maximum of 128 bits.
name|unsigned
name|long
operator|*
name|word
operator|=
operator|&
name|words
index|[
literal|0
index|]
block|;
name|int
name|saved_pos
block|;
name|store
argument_list|(
name|saved_pos
argument_list|)
block|;
comment|// The following assumes that leading zeroes are also included in the
comment|// mangled name, I am not sure that is conforming to the C++-ABI, but
comment|// it is what g++ does.
name|unsigned
name|char
name|nibble
block|,
name|c
operator|=
name|current
argument_list|()
block|;
for|for
control|(
name|size_t
name|word_cnt
init|=
name|size_of_real
operator|/
literal|4
init|;
name|word_cnt
operator|>
literal|0
condition|;
operator|--
name|word_cnt
control|)
block|{
for|for
control|(
name|int
name|nibble_cnt
init|=
literal|0
init|;
name|nibble_cnt
operator|<
literal|8
condition|;
operator|++
name|nibble_cnt
control|)
block|{
comment|// Translate character into nibble.
if|if
condition|(
name|c
operator|<
literal|'0'
operator|||
name|c
operator|>
literal|'f'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
name|c
operator|<=
literal|'9'
condition|)
name|nibble
operator|=
name|c
operator|-
literal|'0'
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|>=
literal|'a'
condition|)
name|nibble
operator|=
name|c
operator|-
literal|'a'
operator|+
literal|10
expr_stmt|;
else|else
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
comment|// Write nibble into word array.
if|if
condition|(
name|nibble_cnt
operator|==
literal|0
condition|)
operator|*
name|word
operator|=
name|nibble
operator|<<
literal|28
expr_stmt|;
else|else
operator|*
name|word
operator||=
operator|(
name|nibble
operator|<<
operator|(
literal|28
operator|-
literal|4
operator|*
name|nibble_cnt
operator|)
operator|)
expr_stmt|;
name|c
operator|=
name|next
argument_list|()
expr_stmt|;
block|}
operator|++
name|word
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} 	char
name|buf
index|[
literal|24
index|]
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|M_implementation_details
operator|.
name|decode_real
argument_list|(
name|buf
argument_list|,
name|words
argument_list|,
name|size_of_real
argument_list|)
condition|)
block|{
name|output
operator|+=
name|buf
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|restore
argument_list|(
name|saved_pos
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|output
operator|+=
literal|'['
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|c
operator|=
name|current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|size_t
name|nibble_cnt
init|=
literal|0
init|;
name|nibble_cnt
operator|<
literal|2
operator|*
name|size_of_real
condition|;
operator|++
name|nibble_cnt
control|)
block|{
if|if
condition|(
name|c
operator|<
literal|'0'
operator|||
name|c
operator|>
literal|'f'
operator|||
operator|(
name|c
operator|>
literal|'9'
operator|&&
name|c
operator|<
literal|'a'
operator|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
name|c
expr_stmt|;
name|c
operator|=
name|next
argument_list|()
expr_stmt|;
block|}
end_for

begin_expr_stmt
name|output
operator|+=
literal|']'
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_literal
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_literal"
argument_list|)
block|;
name|eat_current
argument_list|()
block|;
comment|// Eat the 'L'.
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'_'
condition|)
block|{
if|if
condition|(
name|next
argument_list|()
operator|!=
literal|'Z'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|M_pos
operator|+=
name|decode_encoding
argument_list|(
name|output
argument_list|,
name|M_str
operator|+
name|M_pos
argument_list|,
name|M_maxpos
operator|-
name|M_pos
operator|+
literal|1
argument_list|,
name|M_implementation_details
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
comment|// Special cases
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'b'
condition|)
block|{
if|if
condition|(
name|next
argument_list|()
operator|==
literal|'0'
condition|)
name|output
operator|+=
literal|"false"
expr_stmt|;
else|else
name|output
operator|+=
literal|"true"
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
name|char
name|c
init|=
name|current
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|c
operator|==
literal|'i'
operator|||
name|c
operator|==
literal|'j'
operator|||
name|c
operator|==
literal|'l'
operator|||
name|c
operator|==
literal|'m'
operator|||
name|c
operator|==
literal|'x'
operator|||
name|c
operator|==
literal|'y'
operator|)
operator|&&
name|M_implementation_details
operator|.
name|get_style_literal
argument_list|()
condition|)
name|eat_current
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|==
literal|'i'
operator|&&
operator|!
name|M_implementation_details
operator|.
name|get_style_literal_int
argument_list|()
condition|)
name|eat_current
argument_list|()
expr_stmt|;
else|else
block|{
name|output
operator|+=
literal|'('
expr_stmt|;
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|')'
expr_stmt|;
block|}
if|if
condition|(
name|c
operator|>=
literal|'d'
operator|&&
name|c
operator|<=
literal|'g'
condition|)
block|{
name|size_t
name|size_of_real
init|=
operator|(
name|c
operator|==
literal|'d'
operator|)
condition|?
sizeof|sizeof
argument_list|(
name|double
argument_list|)
else|:
operator|(
operator|(
name|c
operator|==
literal|'f'
operator|)
condition|?
sizeof|sizeof
argument_list|(
name|float
argument_list|)
else|:
operator|(
name|c
operator|==
literal|'e'
operator|)
condition|?
expr|sizeof
operator|(
name|long
name|double
operator|)
else|:
literal|16
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|decode_real
argument_list|(
name|output
argument_list|,
name|size_of_real
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|decode_number
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
name|M_implementation_details
operator|.
name|get_style_literal
argument_list|()
condition|)
block|{
if|if
condition|(
name|c
operator|==
literal|'j'
operator|||
name|c
operator|==
literal|'m'
operator|||
name|c
operator|==
literal|'y'
condition|)
name|output
operator|+=
literal|'u'
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'l'
operator|||
name|c
operator|==
literal|'m'
condition|)
name|output
operator|+=
literal|'l'
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'x'
operator|||
name|c
operator|==
literal|'y'
condition|)
name|output
operator|+=
literal|"ll"
expr_stmt|;
block|}
block|}
end_else

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<operator-name> ::=
end_comment

begin_comment
comment|//   nw				# new
end_comment

begin_comment
comment|//   na				# new[]
end_comment

begin_comment
comment|//   dl				# delete
end_comment

begin_comment
comment|//   da				# delete[]
end_comment

begin_comment
comment|//   ps				# + (unary)
end_comment

begin_comment
comment|//   ng				# - (unary)
end_comment

begin_comment
comment|//   ad				#& (unary)
end_comment

begin_comment
comment|//   de				# * (unary)
end_comment

begin_comment
comment|//   co				# ~
end_comment

begin_comment
comment|//   pl				# +
end_comment

begin_comment
comment|//   mi				# -
end_comment

begin_comment
comment|//   ml				# *
end_comment

begin_comment
comment|//   dv				# /
end_comment

begin_comment
comment|//   rm				# %
end_comment

begin_comment
comment|//   an				#&
end_comment

begin_comment
comment|//   or				# |
end_comment

begin_comment
comment|//   eo				# ^
end_comment

begin_comment
comment|//   aS				# =
end_comment

begin_comment
comment|//   pL				# +=
end_comment

begin_comment
comment|//   mI				# -=
end_comment

begin_comment
comment|//   mL				# *=
end_comment

begin_comment
comment|//   dV				# /=
end_comment

begin_comment
comment|//   rM				# %=
end_comment

begin_comment
comment|//   aN				#&=
end_comment

begin_comment
comment|//   oR				# |=
end_comment

begin_comment
comment|//   eO				# ^=
end_comment

begin_comment
comment|//   ls				#<<
end_comment

begin_comment
comment|//   rs				#>>
end_comment

begin_comment
comment|//   lS				#<<=
end_comment

begin_comment
comment|//   rS				#>>=
end_comment

begin_comment
comment|//   eq				# ==
end_comment

begin_comment
comment|//   ne				# !=
end_comment

begin_comment
comment|//   lt				#<
end_comment

begin_comment
comment|//   gt				#>
end_comment

begin_comment
comment|//   le				#<=
end_comment

begin_comment
comment|//   ge				#>=
end_comment

begin_comment
comment|//   nt				# !
end_comment

begin_comment
comment|//   aa				#&&
end_comment

begin_comment
comment|//   oo				# ||
end_comment

begin_comment
comment|//   pp				# ++
end_comment

begin_comment
comment|//   mm				# --
end_comment

begin_comment
comment|//   cm				# ,
end_comment

begin_comment
comment|//   pm				# ->*
end_comment

begin_comment
comment|//   pt				# ->
end_comment

begin_comment
comment|//   cl				# ()
end_comment

begin_comment
comment|//   ix				# []
end_comment

begin_comment
comment|//   qu				# ?
end_comment

begin_comment
comment|//   st				# sizeof (a type)
end_comment

begin_comment
comment|//   sz				# sizeof (an expression)
end_comment

begin_comment
comment|//   cv<type>			# (cast)
end_comment

begin_comment
comment|//   v<digit><source-name>	# vendor extended operator
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Symbol operator codes exist of two characters, we need to find a
end_comment

begin_comment
comment|// quick hash so that their names can be looked up in a table.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The puzzle :)
end_comment

begin_comment
comment|// Shift the rows so that there is at most one character per column.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A perfect solution (Oh no, it's THE MATRIX!):
end_comment

begin_comment
comment|//                                              horizontal
end_comment

begin_comment
comment|//    .......................................   offset + 'a'
end_comment

begin_comment
comment|// a, a||d|||||||||n||||s||||||||||||||||||||       0
end_comment

begin_comment
comment|// c,  || |||||||lm o||| ||||||||||||||||||||       0
end_comment

begin_comment
comment|// d,  || a|||e||    l|| ||||||v|||||||||||||       4
end_comment

begin_comment
comment|// e,  ||  ||| ||     || |||o|q |||||||||||||       8
end_comment

begin_comment
comment|// g,  ||  ||| ||     || e|| |  ||||||||t||||      15
end_comment

begin_comment
comment|// i,  ||  ||| ||     ||  || |  |||||||| |||x      15
end_comment

begin_comment
comment|// l,  |e  ||| ||     st  || |  |||||||| |||       -2
end_comment

begin_comment
comment|// m,  |   |i| lm         || |  |||||||| |||       -2
end_comment

begin_comment
comment|// n,  a   e g            t| w  |||||||| |||        1
end_comment

begin_comment
comment|// o,                      |    ||||o||r |||       16
end_comment

begin_comment
comment|// p,                      |    ||lm |p  st|       17
end_comment

begin_comment
comment|// q,                      |    u|   |     |        6
end_comment

begin_comment
comment|// r,                      m     s   |     |        9
end_comment

begin_comment
comment|// s,                                t     z       12
end_comment

begin_comment
comment|//    .......................................
end_comment

begin_comment
comment|// ^            ^__ second character
end_comment

begin_comment
comment|// |___ first character
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Putting that solution in tables:
end_comment

begin_expr_stmt
unit|char
specifier|const
name|offset_table_c
index|[
literal|1
operator|+
name|CHAR_MAX
operator|-
name|CHAR_MIN
index|]
operator|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
if|#
directive|if
operator|(
name|CHAR_MIN
operator|<
literal|0
operator|)
comment|// Add -CHAR_MIN extra zeroes (128):
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|//   a    b    c    d    e    f    g    h    i    j    k
literal|0
block|,
operator|-
literal|97
block|,
literal|0
block|,
operator|-
literal|97
block|,
operator|-
literal|93
block|,
operator|-
literal|89
block|,
literal|0
block|,
operator|-
literal|82
block|,
literal|0
block|,
operator|-
literal|82
block|,
literal|0
block|,
literal|0
block|,
comment|//   l    m    n    o    p    q    r    s    t    u    v
operator|-
literal|99
block|,
operator|-
literal|99
block|,
operator|-
literal|96
block|,
operator|-
literal|81
block|,
operator|-
literal|80
block|,
operator|-
literal|91
block|,
operator|-
literal|88
block|,
operator|-
literal|85
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
else|#
directive|else
comment|//   a    b    c    d    e    f    g    h    i    j    k
literal|0
block|,
literal|159
block|,
literal|0
block|,
literal|159
block|,
literal|163
block|,
literal|167
block|,
literal|0
block|,
literal|174
block|,
literal|0
block|,
literal|174
block|,
literal|0
block|,
literal|0
block|,
comment|//   l    m    n    o    p    q    r    s    t    u    v
literal|157
block|,
literal|157
block|,
literal|160
block|,
literal|175
block|,
literal|176
block|,
literal|165
block|,
literal|168
block|,
literal|171
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
endif|#
directive|endif
comment|// ... more zeros
block|}
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|xary_nt
block|{
name|unary
block|,
name|binary
block|,
name|trinary
block|}
enum|;
end_enum

begin_struct
struct|struct
name|entry_st
block|{
name|char
specifier|const
modifier|*
name|opcode
decl_stmt|;
name|char
specifier|const
modifier|*
name|symbol_name
decl_stmt|;
name|xary_nt
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|entry_st
specifier|const
name|symbol_name_table_c
index|[
literal|39
index|]
init|=
block|{
block|{
literal|"aa"
block|,
literal|"operator&&"
block|,
name|binary
block|}
block|,
block|{
literal|"na"
block|,
literal|"operator new[]"
block|,
name|unary
block|}
block|,
block|{
literal|"le"
block|,
literal|"operator<="
block|,
name|binary
block|}
block|,
block|{
literal|"ad"
block|,
literal|"operator&"
block|,
name|unary
block|}
block|,
block|{
literal|"da"
block|,
literal|"operator delete[]"
block|,
name|unary
block|}
block|,
block|{
literal|"ne"
block|,
literal|"operator!="
block|,
name|binary
block|}
block|,
block|{
literal|"mi="
block|,
literal|"operator-"
block|,
name|binary
block|}
block|,
block|{
literal|"ng"
block|,
literal|"operator-"
block|,
name|unary
block|}
block|,
block|{
literal|"de"
block|,
literal|"operator*"
block|,
name|unary
block|}
block|,
block|{
literal|"ml="
block|,
literal|"operator*"
block|,
name|binary
block|}
block|,
block|{
literal|"mm"
block|,
literal|"operator--"
block|,
name|unary
block|}
block|,
block|{
literal|"cl"
block|,
literal|"operator()"
block|,
name|unary
block|}
block|,
block|{
literal|"cm"
block|,
literal|"operator,"
block|,
name|binary
block|}
block|,
block|{
literal|"an="
block|,
literal|"operator&"
block|,
name|binary
block|}
block|,
block|{
literal|"co"
block|,
literal|"operator~"
block|,
name|binary
block|}
block|,
block|{
literal|"dl"
block|,
literal|"operator delete"
block|,
name|unary
block|}
block|,
block|{
literal|"ls="
block|,
literal|"operator<<"
block|,
name|binary
block|}
block|,
block|{
literal|"lt"
block|,
literal|"operator<"
block|,
name|binary
block|}
block|,
block|{
literal|"as="
block|,
literal|"operator"
block|,
name|binary
block|}
block|,
block|{
literal|"ge"
block|,
literal|"operator>="
block|,
name|binary
block|}
block|,
block|{
literal|"nt"
block|,
literal|"operator!"
block|,
name|unary
block|}
block|,
block|{
literal|"rm="
block|,
literal|"operator%"
block|,
name|binary
block|}
block|,
block|{
literal|"eo="
block|,
literal|"operator^"
block|,
name|binary
block|}
block|,
block|{
literal|"nw"
block|,
literal|"operator new"
block|,
name|unary
block|}
block|,
block|{
literal|"eq"
block|,
literal|"operator=="
block|,
name|binary
block|}
block|,
block|{
literal|"dv="
block|,
literal|"operator/"
block|,
name|binary
block|}
block|,
block|{
literal|"qu"
block|,
literal|"operator?"
block|,
name|trinary
block|}
block|,
block|{
literal|"rs="
block|,
literal|"operator>>"
block|,
name|binary
block|}
block|,
block|{
literal|"pl="
block|,
literal|"operator+"
block|,
name|binary
block|}
block|,
block|{
literal|"pm"
block|,
literal|"operator->*"
block|,
name|binary
block|}
block|,
block|{
literal|"oo"
block|,
literal|"operator||"
block|,
name|binary
block|}
block|,
block|{
literal|"st"
block|,
literal|"sizeof"
block|,
name|unary
block|}
block|,
block|{
literal|"pp"
block|,
literal|"operator++"
block|,
name|unary
block|}
block|,
block|{
literal|"or="
block|,
literal|"operator|"
block|,
name|binary
block|}
block|,
block|{
literal|"gt"
block|,
literal|"operator>"
block|,
name|binary
block|}
block|,
block|{
literal|"ps"
block|,
literal|"operator+"
block|,
name|unary
block|}
block|,
block|{
literal|"pt"
block|,
literal|"operator->"
block|,
name|binary
block|}
block|,
block|{
literal|"sz"
block|,
literal|"sizeof"
block|,
name|unary
block|}
block|,
block|{
literal|"ix"
block|,
literal|"operator[]"
block|,
name|unary
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_operator_name
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_operator_name"
argument_list|)
block|;
name|char
name|opcode0
operator|=
name|current
argument_list|()
block|;
name|char
name|opcode1
operator|=
name|tolower
argument_list|(
name|next
argument_list|()
argument_list|)
block|;
specifier|register
name|char
name|hash
block|;
if|if
condition|(
operator|(
name|hash
operator|=
name|offset_table_c
index|[
name|opcode0
operator|-
name|CHAR_MIN
index|]
operator|)
condition|)
block|{
name|hash
operator|+=
name|opcode1
expr_stmt|;
if|if
condition|(
if|#
directive|if
operator|(
name|CHAR_MIN
operator|<
literal|0
operator|)
name|hash
operator|>=
literal|0
operator|&&
endif|#
directive|endif
name|hash
operator|<
literal|39
condition|)
block|{
name|int
name|index
init|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|hash
operator|)
operator|)
decl_stmt|;
name|entry_st
name|entry
init|=
name|symbol_name_table_c
index|[
name|index
index|]
decl_stmt|;
if|if
condition|(
name|entry
operator|.
name|opcode
index|[
literal|0
index|]
operator|==
name|opcode0
operator|&&
name|entry
operator|.
name|opcode
index|[
literal|1
index|]
operator|==
name|opcode1
operator|&&
operator|(
name|opcode1
operator|==
name|current
argument_list|()
operator|||
name|entry
operator|.
name|opcode
index|[
literal|2
index|]
operator|==
literal|'='
operator|)
condition|)
block|{
name|output
operator|+=
name|entry
operator|.
name|symbol_name
expr_stmt|;
if|if
condition|(
name|opcode1
operator|!=
name|current
argument_list|()
condition|)
name|output
operator|+=
literal|'='
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
name|hash
operator|==
literal|16
operator|||
name|hash
operator|==
literal|17
condition|)
name|M_template_args_need_space
operator|=
name|true
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|opcode0
operator|==
literal|'c'
operator|&&
name|opcode1
operator|==
literal|'v'
condition|)
comment|// casting operator
block|{
name|eat_current
argument_list|()
expr_stmt|;
name|output
operator|+=
literal|"operator "
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'T'
condition|)
block|{
comment|// This is a templated cast operator.
comment|// It must be of the form "cvT_I...E".
comment|// Let M_template_arg_pos already point
comment|// to the template argument.
name|M_template_arg_pos_offset
operator|=
name|M_template_arg_pos
operator|.
name|size
argument_list|()
expr_stmt|;
name|M_template_arg_pos
operator|.
name|push_back
argument_list|(
name|M_pos
operator|+
literal|3
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
operator|!
name|M_inside_template_args
condition|)
name|M_name_is_conversion_operator
operator|=
name|true
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_elseif

begin_expr_stmt
unit|} 	}
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//
end_comment

begin_comment
comment|//<expression> ::=<unary operator-name><expression>
end_comment

begin_comment
comment|//              ::=<binary operator-name><expression><expression>
end_comment

begin_comment
comment|//              ::=<trinary operator-name><expression><expression><expression>
end_comment

begin_comment
comment|//              ::= st<type>
end_comment

begin_comment
comment|//              ::=<template-param>
end_comment

begin_comment
comment|//              ::= sr<type><unqualified-name>                   # dependent name
end_comment

begin_comment
comment|//              ::= sr<type><unqualified-name><template-args>   # dependent template-id
end_comment

begin_comment
comment|//              ::=<expr-primary>
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<expr-primary> ::= L<type><value number> E     # integer literal
end_comment

begin_comment
comment|//                ::= L<type><value float> E	# floating literal
end_comment

begin_comment
comment|//                ::= L<mangled-name> E		# external name
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_expression
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_expression"
argument_list|)
block|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'T'
condition|)
block|{
if|if
condition|(
operator|!
name|decode_template_param
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'L'
condition|)
block|{
if|if
condition|(
operator|!
name|decode_literal
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'E'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_elseif

begin_elseif
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'s'
condition|)
block|{
name|char
name|opcode1
init|=
name|next
argument_list|()
decl_stmt|;
if|if
condition|(
name|opcode1
operator|==
literal|'t'
operator|||
name|opcode1
operator|==
literal|'z'
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
name|M_implementation_details
operator|.
name|get_style_compact_expr_ops
argument_list|()
condition|)
name|output
operator|+=
literal|"sizeof("
expr_stmt|;
else|else
name|output
operator|+=
literal|"sizeof ("
expr_stmt|;
if|if
condition|(
name|opcode1
operator|==
literal|'t'
condition|)
block|{
comment|// I cannot think of a mangled name that is valid for both cases
comment|// when just replacing the 't' by a 'z' or vica versa, which
comment|// indicates that there is no ambiguity that dictates the need
comment|// for a seperate "st" case, except to be able catch invalid
comment|// mangled names.  However there CAN be ambiguity in the demangled
comment|// name when there are both a type and a symbol of the same name,
comment|// which then leads to different encoding (of course) with
comment|// sizeof (type) or sizeof (expression) respectively, but that
comment|// ambiguity is not per se related to "sizeof" except that that
comment|// is the only place where both a type AND an expression are valid
comment|// in as part of a (template function) type.
comment|//
comment|// Example:
comment|//
comment|// struct B { typedef int t; };
comment|// struct A : public B { static int t[2]; };
comment|// template<int i, int j> struct C { typedef int q; };
comment|// template<int i, typename T>
comment|//   void f(typename C<sizeof (typename T::t),
comment|//                     sizeof (T::t)>::q) { }
comment|// void instantiate() { f<5, A>(0); }
comment|//
comment|// Leads to _Z1fILi5E1AEvN1CIXstN1T1tEEXszsrS2_1tEE1qE which
comment|// demangles as
comment|// void f<5, A>(C<sizeof (T::t), sizeof (T::t)>::q)
comment|//
comment|// This is ambiguity is very unlikely to happen and it is kind
comment|// of fuzzy to detect when adding a 'typename' makes sense.
comment|//
if|if
condition|(
name|M_implementation_details
operator|.
name|get_style_sizeof_typename
argument_list|()
condition|)
block|{
comment|// We can only get here inside a template parameter,
comment|// so this is syntactically correct if the given type is
comment|// a typedef.  The only disadvantage is that it is inconsistent
comment|// with all other places where the 'typename' keyword should be
comment|// used and we don't.
comment|// With this, the above example will demangle as
comment|// void f<5, A>(C<sizeof (typename T::t), sizeof (T::t)>::q)
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'N'
operator|||
comment|//<nested-name>
comment|// This should be a safe bet.
operator|(
name|current
argument_list|()
operator|==
literal|'S'
operator|&&
name|next_peek
argument_list|()
operator|==
literal|'t'
operator|)
condition|)
comment|// std::something, guess that
comment|// this involves a typedef.
name|output
operator|+=
literal|"typename "
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|decode_expression
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
name|output
operator|+=
literal|')'
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'r'
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|"::"
expr_stmt|;
if|if
condition|(
operator|!
name|decode_unqualified_name
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'I'
operator|||
name|decode_template_args
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
block|}
end_elseif

begin_else
else|else
block|{
name|char
name|opcode0
init|=
name|current
argument_list|()
decl_stmt|;
name|char
name|opcode1
init|=
name|tolower
argument_list|(
name|next
argument_list|()
argument_list|)
decl_stmt|;
specifier|register
name|char
name|hash
decl_stmt|;
if|if
condition|(
operator|(
name|hash
operator|=
name|offset_table_c
index|[
name|opcode0
operator|-
name|CHAR_MIN
index|]
operator|)
condition|)
block|{
name|hash
operator|+=
name|opcode1
expr_stmt|;
if|if
condition|(
if|#
directive|if
operator|(
name|CHAR_MIN
operator|<
literal|0
operator|)
name|hash
operator|>=
literal|0
operator|&&
endif|#
directive|endif
name|hash
operator|<
literal|39
condition|)
block|{
name|int
name|index
init|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|hash
operator|)
operator|)
decl_stmt|;
name|entry_st
name|entry
init|=
name|symbol_name_table_c
index|[
name|index
index|]
decl_stmt|;
if|if
condition|(
name|entry
operator|.
name|opcode
index|[
literal|0
index|]
operator|==
name|opcode0
operator|&&
name|entry
operator|.
name|opcode
index|[
literal|1
index|]
operator|==
name|opcode1
operator|&&
operator|(
name|opcode1
operator|==
name|current
argument_list|()
operator|||
name|entry
operator|.
name|opcode
index|[
literal|2
index|]
operator|==
literal|'='
operator|)
condition|)
block|{
name|char
specifier|const
modifier|*
name|op
init|=
name|entry
operator|.
name|symbol_name
operator|+
literal|8
decl_stmt|;
comment|// Skip "operator".
if|if
condition|(
operator|*
name|op
operator|==
literal|' '
condition|)
comment|// operator new and delete.
operator|++
name|op
expr_stmt|;
if|if
condition|(
name|entry
operator|.
name|type
operator|==
name|unary
condition|)
name|output
operator|+=
name|op
expr_stmt|;
name|bool
name|is_eq
init|=
operator|(
name|opcode1
operator|!=
name|current
argument_list|()
operator|)
decl_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
name|index
operator|==
literal|34
operator|&&
name|M_inside_template_args
condition|)
comment|// operator>
name|output
operator|+=
literal|'('
expr_stmt|;
name|output
operator|+=
literal|'('
expr_stmt|;
if|if
condition|(
operator|!
name|decode_expression
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|')'
expr_stmt|;
if|if
condition|(
name|entry
operator|.
name|type
operator|!=
name|unary
condition|)
block|{
if|if
condition|(
operator|!
name|M_implementation_details
operator|.
name|get_style_compact_expr_ops
argument_list|()
condition|)
name|output
operator|+=
literal|' '
expr_stmt|;
name|output
operator|+=
name|op
expr_stmt|;
if|if
condition|(
name|is_eq
condition|)
name|output
operator|+=
literal|'='
expr_stmt|;
if|if
condition|(
operator|!
name|M_implementation_details
operator|.
name|get_style_compact_expr_ops
argument_list|()
condition|)
name|output
operator|+=
literal|' '
expr_stmt|;
name|output
operator|+=
literal|'('
expr_stmt|;
if|if
condition|(
operator|!
name|decode_expression
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|')'
expr_stmt|;
if|if
condition|(
name|index
operator|==
literal|34
operator|&&
name|M_inside_template_args
condition|)
name|output
operator|+=
literal|')'
expr_stmt|;
if|if
condition|(
name|entry
operator|.
name|type
operator|==
name|trinary
condition|)
block|{
if|if
condition|(
name|M_implementation_details
operator|.
name|get_style_compact_expr_ops
argument_list|()
condition|)
name|output
operator|+=
literal|":("
expr_stmt|;
else|else
name|output
operator|+=
literal|" : ("
expr_stmt|;
if|if
condition|(
operator|!
name|decode_expression
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|')'
expr_stmt|;
block|}
block|}
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opcode0
operator|==
literal|'c'
operator|&&
name|opcode1
operator|==
literal|'v'
condition|)
comment|// casting operator.
block|{
name|eat_current
argument_list|()
expr_stmt|;
name|output
operator|+=
literal|'('
expr_stmt|;
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|")("
expr_stmt|;
if|if
condition|(
operator|!
name|decode_expression
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|')'
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
block|}
block|}
block|}
end_else

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//
end_comment

begin_comment
comment|//<template-args> ::= I<template-arg>+ E
end_comment

begin_comment
comment|//<template-arg> ::=<type>			# type or template
end_comment

begin_comment
comment|//                ::= L<type><value number> E	# integer literal
end_comment

begin_comment
comment|//                ::= L<type><value float> E	# floating literal
end_comment

begin_comment
comment|//                ::= L<mangled-name> E		# external name
end_comment

begin_comment
comment|//                ::= X<expression> E		# expression
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_template_args
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_template_args"
argument_list|)
block|;
if|if
condition|(
name|eat_current
argument_list|()
operator|!=
literal|'I'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|int
name|prev_size
operator|=
name|M_template_arg_pos
operator|.
name|size
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|++
name|M_inside_template_args
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|M_template_args_need_space
condition|)
block|{
name|output
operator|+=
literal|' '
expr_stmt|;
name|M_template_args_need_space
operator|=
name|false
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|output
operator|+=
literal|'<'
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|M_inside_template_args
operator|==
literal|1
operator|&&
operator|!
name|M_inside_type
condition|)
name|M_template_arg_pos
operator|.
name|push_back
argument_list|(
name|M_pos
argument_list|)
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'X'
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|decode_expression
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'E'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'L'
condition|)
block|{
if|if
condition|(
operator|!
name|decode_literal
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'E'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'E'
condition|)
break|break;
name|output
operator|+=
literal|", "
expr_stmt|;
block|}
end_for

begin_expr_stmt
name|eat_current
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|*
operator|(
name|output
operator|.
name|rbegin
argument_list|()
operator|)
operator|==
literal|'>'
condition|)
name|output
operator|+=
literal|' '
expr_stmt|;
end_if

begin_expr_stmt
name|output
operator|+=
literal|'>'
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|--
name|M_inside_template_args
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|M_inside_template_args
operator|&&
operator|!
name|M_inside_type
condition|)
block|{
name|M_name_is_template
operator|=
name|true
expr_stmt|;
name|M_template_arg_pos_offset
operator|=
name|prev_size
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<bare-function-type> ::=
end_comment

begin_comment
comment|//<signature type>+		# Types are parameter types.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that the possible return type of the<bare-function-type>
end_comment

begin_comment
comment|// has already been eaten before we call this function.  This makes
end_comment

begin_comment
comment|// our<bare-function-type> slightly different from the one in
end_comment

begin_comment
comment|// the C++-ABI description.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_bare_function_type
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_bare_function_type"
argument_list|)
block|;
if|if
condition|(
name|M_saw_destructor
condition|)
block|{
if|if
condition|(
name|eat_current
argument_list|()
operator|!=
literal|'v'
operator|||
operator|(
name|current
argument_list|()
operator|!=
literal|'E'
operator|&&
name|current
argument_list|()
operator|!=
literal|0
operator|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|"()"
expr_stmt|;
name|M_saw_destructor
operator|=
name|false
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'v'
operator|&&
operator|!
name|M_implementation_details
operator|.
name|get_style_void
argument_list|()
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'E'
operator|&&
name|current
argument_list|()
operator|!=
literal|0
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|"()"
expr_stmt|;
name|M_saw_destructor
operator|=
name|false
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|output
operator|+=
literal|'('
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|M_template_args_need_space
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|output
argument_list|)
condition|)
comment|// Must have at least one parameter.
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_if

begin_while
while|while
condition|(
name|current
argument_list|()
operator|!=
literal|'E'
operator|&&
name|current
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|output
operator|+=
literal|", "
expr_stmt|;
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
end_while

begin_expr_stmt
name|output
operator|+=
literal|')'
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<type> ::=
end_comment

begin_comment
comment|//<builtin-type>		# Starts with a lower case character != r.
end_comment

begin_comment
comment|//<function-type>	# Starts with F
end_comment

begin_comment
comment|//<class-enum-type>	# Starts with N, S, C, D, Z, a digit or a lower
end_comment

begin_comment
comment|//				# case character.  Since a lower case character
end_comment

begin_comment
comment|//				# would be an operator name, that would be an
end_comment

begin_comment
comment|//				# error.  The S is a substitution or St
end_comment

begin_comment
comment|//				# (::std::).  A 'C' would be a constructor and
end_comment

begin_comment
comment|//				# thus also an error.
end_comment

begin_comment
comment|//<template-param>	# Starts with T
end_comment

begin_comment
comment|//<substitution>         # Starts with S
end_comment

begin_comment
comment|//<template-template-param><template-args>  # Starts with T or S,
end_comment

begin_comment
comment|//						    # equivalent with the above.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<array-type>			# Starts with A
end_comment

begin_comment
comment|//<pointer-to-member-type>	# Starts with M
end_comment

begin_comment
comment|//<CV-qualifiers><type>		# Starts with r, V or K
end_comment

begin_comment
comment|//   P<type>   # pointer-to	# Starts with P
end_comment

begin_comment
comment|//   R<type>   # reference-to	# Starts with R
end_comment

begin_comment
comment|//   C<type>   # complex (C 2000)	# Starts with C
end_comment

begin_comment
comment|//   G<type>   # imaginary (C 2000)# Starts with G
end_comment

begin_comment
comment|//   U<source-name><type>		# vendor extended type qualifier,
end_comment

begin_comment
comment|//					# starts with U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<template-template-param> ::=<template-param>
end_comment

begin_comment
comment|//                           ::=<substitution>
end_comment

begin_comment
comment|// My own analysis of how to decode qualifiers:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// F is a<function-type>,<T> is a<builtin-type>,<class-enum-type>,
end_comment

begin_comment
comment|//<template-param> or<template-template-param><template-args>.
end_comment

begin_comment
comment|//<Q> represents a series of qualifiers (not G or C).
end_comment

begin_comment
comment|//<C> is an unqualified type.
end_comment

begin_comment
comment|//<R> is a qualified type.
end_comment

begin_comment
comment|//<B> is the bare-function-type without return type.
end_comment

begin_comment
comment|//<I> is the array index.
end_comment

begin_comment
comment|//						Substitutions:
end_comment

begin_comment
comment|//<Q>M<C><Q2>F<R><B>E  ==> R (C::*Q)B Q2	"<C>", "F<R><B>E"
end_comment

begin_comment
comment|//						    (<R> and<B> recursive),
end_comment

begin_comment
comment|//						    "M<C><Q2>F<R><B>E".
end_comment

begin_comment
comment|//<Q>F<R><B>E	    ==> R (Q)B		"<R>", "<B>" (<B> recursive)
end_comment

begin_comment
comment|//                                              and "F<R><B>E".
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that if<R> has postfix qualifiers (an array or function), then
end_comment

begin_comment
comment|// those are added AFTER the (member) function type.  For example:
end_comment

begin_comment
comment|//<Q>FPA<R><B>E ==> R (*(Q)B) [], where the PA added the prefix
end_comment

begin_comment
comment|// "(*" and the postfix ") []".
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<Q>G<T>		    ==> imaginary T Q	"<T>", "G<T>" (<T> recursive).
end_comment

begin_comment
comment|//<Q>C<T>		    ==> complex T Q	"<T>", "C<T>" (<T> recursive).
end_comment

begin_comment
comment|//<Q><T>		    ==> T Q		"<T>" (<T> recursive).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// where<Q> is any of:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<Q>P		==> *Q				"P..."
end_comment

begin_comment
comment|//<Q>R		==>&Q				"R..."
end_comment

begin_comment
comment|//<Q>[K|V|r]+	==> [ const| volatile| restrict]+Q	"KVr..."
end_comment

begin_comment
comment|//<Q>U<S>		==>  SQ				"U<S>..."
end_comment

begin_comment
comment|//<Q>M<C>		==> C::*Q			"M<C>..." (<C> recurs.)
end_comment

begin_comment
comment|// A<I>		==>  [I]			"A<I>..." (<I> recurs.)
end_comment

begin_comment
comment|//<Q>A<I>		==>  (Q) [I]			"A<I>..." (<I> recurs.)
end_comment

begin_comment
comment|//   Note that when<Q> ends on an A<I2> then the brackets are omitted
end_comment

begin_comment
comment|//   and no space is written between the two:
end_comment

begin_comment
comment|//   A<I2>A<I>	==>  [I2][I]
end_comment

begin_comment
comment|//   If<Q> ends on [KVr]+, which can happen in combination with
end_comment

begin_comment
comment|//   substitutions only, then special handling is required, see below.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A<substitution> is handled with an input position switch during which
end_comment

begin_comment
comment|// new substitutions are turned off.  Because recursive handling of types
end_comment

begin_comment
comment|// (and therefore the order in which substitutions must be generated) must
end_comment

begin_comment
comment|// be done left to right, but the generation of Q needs processing right to
end_comment

begin_comment
comment|// left, substitutions per<type> are generated by reading the input left
end_comment

begin_comment
comment|// to right and marking the starts of all substitutions only - implicitly
end_comment

begin_comment
comment|// finishing them at the end of the type.  Then the output and real
end_comment

begin_comment
comment|// substitutions are generated.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The following comment was for the demangling of g++ version 3.0.x.  The
end_comment

begin_comment
comment|// mangling (and I believe even the ABI description) have been fixed now
end_comment

begin_comment
comment|// (as of g++ version 3.1).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// g++ 3.0.x only:
end_comment

begin_comment
comment|// The ABI specifies for pointer-to-member function types the format
end_comment

begin_comment
comment|//<Q>M<T>F<R><B>E.  In other words, the qualifier<Q2> (see above) is
end_comment

begin_comment
comment|// implicitely contained in<T> instead of explicitly part of the M format.
end_comment

begin_comment
comment|// I am convinced that this is a bug in the ABI.  Unfortunately, this is
end_comment

begin_comment
comment|// how we have to demangle things as it has a direct impact on the order
end_comment

begin_comment
comment|// in which substitutions are stored.  This ill-formed design results in
end_comment

begin_comment
comment|// rather ill-formed demangler code too however :/
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<Q2> is now explicitely part of the M format.
end_comment

begin_comment
comment|// For some weird reason, g++ (3.2.1) does not add substitutions for
end_comment

begin_comment
comment|// qualified member function pointers.  I think that is another bug.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In the case of
end_comment

begin_comment
comment|//<Q>A<I>
end_comment

begin_comment
comment|// where<Q> ends on [K|V|r]+ then that part should be processed as
end_comment

begin_comment
comment|// if it was behind the A<I> instead of in front of it.  This is
end_comment

begin_comment
comment|// because a constant array of ints is normally always mangled as
end_comment

begin_comment
comment|// an array of constant ints.  KVr qualifiers can end up in front
end_comment

begin_comment
comment|// of an array when the array is part of a substitution or template
end_comment

begin_comment
comment|// parameter, but the demangling should still result in the same
end_comment

begin_comment
comment|// syntax; thus KA2_i (const array of ints) must result in the same
end_comment

begin_comment
comment|// demangling as A2_Ki (array of const ints).  As a result we must
end_comment

begin_comment
comment|// demangle ...[...[[KVr]+A<I0>][KVr]+A<I1>]...[KVr]+A<In>[KVr]+
end_comment

begin_comment
comment|// as A<I0>A<I1>...A<In>[KVr]+ where each K, V and r in the series
end_comment

begin_comment
comment|// collapses to a single character at the right of the string.
end_comment

begin_comment
comment|// For example:
end_comment

begin_comment
comment|// VA9_KrA6_KVi --> A9_A6_KVri --> int volatile const restrict [9][6]
end_comment

begin_comment
comment|// Note that substitutions are still added as usual (the translation
end_comment

begin_comment
comment|// to A9_A6_KVri does not really happen).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This decoding is achieved by delaying the decoding of any sequence
end_comment

begin_comment
comment|// of [KVrA]'s and processing them together in the order: first the
end_comment

begin_comment
comment|// short-circuited KVr part and then the arrays.
end_comment

begin_decl_stmt
unit|static
name|int
specifier|const
name|cvq_K
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Saw at least one K
end_comment

begin_decl_stmt
specifier|static
name|int
specifier|const
name|cvq_V
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Saw at least one V
end_comment

begin_decl_stmt
specifier|static
name|int
specifier|const
name|cvq_r
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Saw at least one r
end_comment

begin_decl_stmt
specifier|static
name|int
specifier|const
name|cvq_A
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Saw at least one A
end_comment

begin_decl_stmt
specifier|static
name|int
specifier|const
name|cvq_last
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_comment
comment|// No remaining qualifiers.
end_comment

begin_decl_stmt
specifier|static
name|int
specifier|const
name|cvq_A_cnt
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Bit 5 and higher represent the
end_comment

begin_comment
comment|//   number of A's in the series.
end_comment

begin_comment
comment|// In the function below, iter_array points to the first (right most)
end_comment

begin_comment
comment|// A in the series, if any.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|void
name|qualifier_list
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_KVrA
argument_list|(
argument|string_type& prefix
argument_list|,
argument|string_type& postfix
argument_list|,
argument|int cvq
argument_list|,
argument|typename qual_vector::const_reverse_iterator const& iter_array
argument_list|)
specifier|const
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING3
argument_list|(
literal|"decode_KVrA"
argument_list|)
block|;
if|if
condition|(
operator|(
name|cvq
operator|&
name|cvq_K
operator|)
condition|)
name|prefix
operator|+=
literal|" const"
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|(
name|cvq
operator|&
name|cvq_V
operator|)
condition|)
name|prefix
operator|+=
literal|" volatile"
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|(
name|cvq
operator|&
name|cvq_r
operator|)
condition|)
name|prefix
operator|+=
literal|" restrict"
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|(
name|cvq
operator|&
name|cvq_A
operator|)
condition|)
block|{
name|int
name|n
init|=
name|cvq
operator|>>
literal|5
decl_stmt|;
for|for
control|(
name|typename
name|qual_vector
operator|::
name|const_reverse_iterator
name|iter
operator|=
name|iter_array
init|;
name|iter
operator|!=
name|M_qualifier_starts
operator|.
name|rend
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
switch|switch
condition|(
operator|(
operator|*
name|iter
operator|)
operator|.
name|first_qualifier
argument_list|()
condition|)
block|{
case|case
literal|'K'
case|:
case|case
literal|'V'
case|:
case|case
literal|'r'
case|:
break|break;
case|case
literal|'A'
case|:
block|{
name|string_type
name|index
init|=
operator|(
operator|*
name|iter
operator|)
operator|.
name|get_optional_type
argument_list|()
decl_stmt|;
if|if
condition|(
operator|--
name|n
operator|==
literal|0
operator|&&
operator|(
name|cvq
operator|&
name|cvq_last
operator|)
condition|)
name|postfix
operator|=
literal|" ["
operator|+
name|index
operator|+
literal|"]"
operator|+
name|postfix
expr_stmt|;
elseif|else
if|if
condition|(
name|n
operator|>
literal|0
condition|)
name|postfix
operator|=
literal|"["
operator|+
name|index
operator|+
literal|"]"
operator|+
name|postfix
expr_stmt|;
else|else
block|{
name|prefix
operator|+=
literal|" ("
expr_stmt|;
name|postfix
operator|=
literal|") ["
operator|+
name|index
operator|+
literal|"]"
operator|+
name|postfix
expr_stmt|;
block|}
break|break;
block|}
default|default:
name|_GLIBCXX_DEMANGLER_RETURN3
expr_stmt|;
block|}
block|}
block|}
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN3
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|void
name|qualifier_list
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_qualifiers
argument_list|(
argument|string_type& prefix
argument_list|,
argument|string_type& postfix
argument_list|,
argument|bool member_function_pointer_qualifiers = false
argument_list|)
specifier|const
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING3
argument_list|(
literal|"decode_qualifiers"
argument_list|)
block|;
name|int
name|cvq
operator|=
literal|0
block|;
name|typename
name|qual_vector
operator|::
name|const_reverse_iterator
name|iter_array
block|;
for|for
control|(
name|typename
name|qual_vector
operator|::
name|const_reverse_iterator
name|iter
operator|=
name|M_qualifier_starts
operator|.
name|rbegin
argument_list|()
init|;
name|iter
operator|!=
name|M_qualifier_starts
operator|.
name|rend
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
if|if
condition|(
operator|!
name|member_function_pointer_qualifiers
operator|&&
operator|!
operator|(
operator|*
name|iter
operator|)
operator|.
name|part_of_substitution
argument_list|()
condition|)
block|{
name|int
name|saved_inside_substitution
init|=
name|M_demangler
operator|.
name|M_inside_substitution
decl_stmt|;
name|M_demangler
operator|.
name|M_inside_substitution
operator|=
literal|0
expr_stmt|;
name|M_demangler
operator|.
name|add_substitution
argument_list|(
operator|(
operator|*
name|iter
operator|)
operator|.
name|get_start_pos
argument_list|()
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|M_demangler
operator|.
name|M_inside_substitution
operator|=
name|saved_inside_substitution
expr_stmt|;
block|}
name|char
name|qualifier_char
operator|=
operator|(
operator|*
name|iter
operator|)
operator|.
name|first_qualifier
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
init|;
name|qualifier_char
condition|;
name|qualifier_char
operator|=
operator|(
operator|*
name|iter
operator|)
operator|.
name|next_qualifier
argument_list|()
control|)
block|{
switch|switch
condition|(
name|qualifier_char
condition|)
block|{
case|case
literal|'P'
case|:
if|if
condition|(
name|cvq
condition|)
block|{
name|decode_KVrA
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|,
name|cvq
argument_list|,
name|iter_array
argument_list|)
expr_stmt|;
name|cvq
operator|=
literal|0
expr_stmt|;
block|}
name|prefix
operator|+=
literal|"*"
expr_stmt|;
break|break;
case|case
literal|'R'
case|:
if|if
condition|(
name|cvq
condition|)
block|{
name|decode_KVrA
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|,
name|cvq
argument_list|,
name|iter_array
argument_list|)
expr_stmt|;
name|cvq
operator|=
literal|0
expr_stmt|;
block|}
name|prefix
operator|+=
literal|"&"
expr_stmt|;
break|break;
case|case
literal|'K'
case|:
name|cvq
operator||=
name|cvq_K
expr_stmt|;
continue|continue;
case|case
literal|'V'
case|:
name|cvq
operator||=
name|cvq_V
expr_stmt|;
continue|continue;
case|case
literal|'r'
case|:
name|cvq
operator||=
name|cvq_r
expr_stmt|;
continue|continue;
case|case
literal|'A'
case|:
if|if
condition|(
operator|!
operator|(
name|cvq
operator|&
name|cvq_A
operator|)
condition|)
block|{
name|cvq
operator||=
name|cvq_A
expr_stmt|;
name|iter_array
operator|=
name|iter
expr_stmt|;
block|}
name|cvq
operator|+=
name|cvq_A_cnt
expr_stmt|;
break|break;
case|case
literal|'M'
case|:
if|if
condition|(
name|cvq
condition|)
block|{
name|decode_KVrA
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|,
name|cvq
argument_list|,
name|iter_array
argument_list|)
expr_stmt|;
name|cvq
operator|=
literal|0
expr_stmt|;
block|}
name|prefix
operator|+=
literal|" "
expr_stmt|;
name|prefix
operator|+=
operator|(
operator|*
name|iter
operator|)
operator|.
name|get_optional_type
argument_list|()
expr_stmt|;
name|prefix
operator|+=
literal|"::*"
expr_stmt|;
break|break;
case|case
literal|'U'
case|:
if|if
condition|(
name|cvq
condition|)
block|{
name|decode_KVrA
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|,
name|cvq
argument_list|,
name|iter_array
argument_list|)
expr_stmt|;
name|cvq
operator|=
literal|0
expr_stmt|;
block|}
name|prefix
operator|+=
literal|" "
expr_stmt|;
name|prefix
operator|+=
operator|(
operator|*
name|iter
operator|)
operator|.
name|get_optional_type
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'G'
case|:
comment|// Only here so we added a substitution.
break|break;
block|}
break|break;
block|}
end_for

begin_expr_stmt
unit|} 	if
operator|(
name|cvq
operator|)
name|decode_KVrA
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|,
name|cvq
operator||
name|cvq_last
argument_list|,
name|iter_array
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|M_printing_suppressed
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN3
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_type_with_postfix
argument_list|(
argument|string_type& prefix
argument_list|,
argument|string_type& postfix
argument_list|,
argument|qualifier_list<Tp
argument_list|,
argument|Allocator>* qualifiers
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING2
argument_list|(
literal|"decode_type"
argument_list|)
block|;
operator|++
name|M_inside_type
block|;
name|bool
name|recursive_template_param_or_substitution_call
block|;
if|if
condition|(
operator|!
operator|(
name|recursive_template_param_or_substitution_call
operator|=
name|qualifiers
operator|)
condition|)
block|{
name|qualifier_list
operator|<
name|Allocator
operator|>
operator|*
name|raw_qualifiers
operator|=
name|M_qualifier_list_alloc
operator|.
name|allocate
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|qualifiers
operator|=
name|new
argument_list|(
argument|raw_qualifiers
argument_list|)
name|qualifier_list
operator|<
name|Allocator
operator|>
operator|(
operator|*
name|this
operator|)
expr_stmt|;
block|}
comment|// First eat all qualifiers.
name|bool
name|failure
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
init|;
condition|;
control|)
comment|// So we can use 'continue' to eat the next qualifier.
block|{
name|int
name|start_pos
init|=
name|M_pos
decl_stmt|;
switch|switch
condition|(
name|current
argument_list|()
condition|)
block|{
case|case
literal|'P'
case|:
name|qualifiers
operator|->
name|add_qualifier_start
argument_list|(
name|pointer
argument_list|,
name|start_pos
argument_list|,
name|M_inside_substitution
argument_list|)
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
continue|continue;
case|case
literal|'R'
case|:
name|qualifiers
operator|->
name|add_qualifier_start
argument_list|(
name|reference
argument_list|,
name|start_pos
argument_list|,
name|M_inside_substitution
argument_list|)
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
continue|continue;
case|case
literal|'K'
case|:
case|case
literal|'V'
case|:
case|case
literal|'r'
case|:
block|{
name|char
name|c
decl_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
do|do
block|{
operator|++
name|count
expr_stmt|;
name|c
operator|=
name|next
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|c
operator|==
literal|'K'
operator|||
name|c
operator|==
literal|'V'
operator|||
name|c
operator|==
literal|'r'
condition|)
do|;
name|qualifiers
operator|->
name|add_qualifier_start
argument_list|(
name|cv_qualifier
argument_list|,
name|start_pos
argument_list|,
name|count
argument_list|,
name|M_inside_substitution
argument_list|)
expr_stmt|;
continue|continue;
block|}
case|case
literal|'U'
case|:
block|{
name|eat_current
argument_list|()
expr_stmt|;
name|string_type
name|source_name
decl_stmt|;
if|if
condition|(
operator|!
name|decode_source_name
argument_list|(
name|source_name
argument_list|)
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
name|qualifiers
operator|->
name|add_qualifier_start
argument_list|(
name|vendor_extension
argument_list|,
name|start_pos
argument_list|,
name|source_name
argument_list|,
name|M_inside_substitution
argument_list|)
expr_stmt|;
continue|continue;
block|}
case|case
literal|'A'
case|:
block|{
comment|//<array-type> ::= A<positive dimension number> _<element type>
comment|//              ::= A [<dimension expression>] _<element type>
comment|//
name|string_type
name|index
decl_stmt|;
name|int
name|saved_pos
decl_stmt|;
name|store
argument_list|(
name|saved_pos
argument_list|)
expr_stmt|;
if|if
condition|(
name|next
argument_list|()
operator|==
literal|'n'
operator|||
operator|!
name|decode_number
argument_list|(
name|index
argument_list|)
condition|)
block|{
name|restore
argument_list|(
name|saved_pos
argument_list|)
expr_stmt|;
if|if
condition|(
name|next
argument_list|()
operator|!=
literal|'_'
operator|&&
operator|!
name|decode_expression
argument_list|(
name|index
argument_list|)
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|eat_current
argument_list|()
operator|!=
literal|'_'
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
name|qualifiers
operator|->
name|add_qualifier_start
argument_list|(
name|array
argument_list|,
name|start_pos
argument_list|,
name|index
argument_list|,
name|M_inside_substitution
argument_list|)
expr_stmt|;
continue|continue;
block|}
case|case
literal|'M'
case|:
block|{
comment|//<pointer-to-member-type> ::= M<class type><member type>
comment|//<Q>M<C> or<Q>M<C><Q2>F<R><B>E
name|eat_current
argument_list|()
expr_stmt|;
name|string_type
name|class_type
decl_stmt|;
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|class_type
argument_list|)
condition|)
comment|// Substitution: "<C>".
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
name|char
name|c
init|=
name|current
argument_list|()
decl_stmt|;
if|if
condition|(
name|c
operator|==
literal|'F'
operator|||
name|c
operator|==
literal|'K'
operator|||
name|c
operator|==
literal|'V'
operator|||
name|c
operator|==
literal|'r'
condition|)
comment|// Must be CV-qualifiers and a member function pointer.
block|{
comment|//<Q>M<C><Q2>F<R><B>E	==> R (C::*Q)B Q2
comment|//     substitutions: "<C>", "F<R><B>E" (<R> and<B>
comment|//                    recursive), "M<C><Q2>F<R><B>E".
name|int
name|count
init|=
literal|0
decl_stmt|;
name|int
name|Q2_start_pos
init|=
name|M_pos
decl_stmt|;
while|while
condition|(
name|c
operator|==
literal|'K'
operator|||
name|c
operator|==
literal|'V'
operator|||
name|c
operator|==
literal|'r'
condition|)
comment|// Decode<Q2>.
block|{
operator|++
name|count
expr_stmt|;
name|c
operator|=
name|next
argument_list|()
expr_stmt|;
block|}
name|qualifier_list
operator|<
name|Tp
operator|,
name|Allocator
operator|>
name|class_type_qualifiers
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
condition|)
name|class_type_qualifiers
operator|.
name|add_qualifier_start
argument_list|(
name|cv_qualifier
argument_list|,
name|Q2_start_pos
argument_list|,
name|count
argument_list|,
name|M_inside_substitution
argument_list|)
expr_stmt|;
name|string_type
name|member_function_qualifiers
decl_stmt|;
comment|// It is unclear why g++ doesn't add a substitution for
comment|// "<Q2>F<R><B>E" as it should I think.
name|string_type
name|member_function_qualifiers_postfix
decl_stmt|;
name|class_type_qualifiers
operator|.
name|decode_qualifiers
argument_list|(
name|member_function_qualifiers
argument_list|,
name|member_function_qualifiers_postfix
argument_list|,
name|true
argument_list|)
expr_stmt|;
name|member_function_qualifiers
operator|+=
name|member_function_qualifiers_postfix
expr_stmt|;
comment|// I don't think this substitution is actually ever used.
name|int
name|function_pos
init|=
name|M_pos
decl_stmt|;
if|if
condition|(
name|eat_current
argument_list|()
operator|!=
literal|'F'
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
comment|// Return type.
comment|// Constructors, destructors and conversion operators don't
comment|// have a return type, but seem to never get here.
name|string_type
name|return_type_postfix
decl_stmt|;
if|if
condition|(
operator|!
name|decode_type_with_postfix
argument_list|(
name|prefix
argument_list|,
name|return_type_postfix
argument_list|)
condition|)
comment|// substitution:<R> recursive
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
name|prefix
operator|+=
literal|" ("
expr_stmt|;
name|prefix
operator|+=
name|class_type
expr_stmt|;
name|prefix
operator|+=
literal|"::*"
expr_stmt|;
name|string_type
name|bare_function_type
decl_stmt|;
if|if
condition|(
operator|!
name|decode_bare_function_type
argument_list|(
name|bare_function_type
argument_list|)
operator|||
name|eat_current
argument_list|()
operator|!=
literal|'E'
condition|)
comment|// Substitution:<B> recursive.
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
comment|// substitution: "F<R><B>E".
name|add_substitution
argument_list|(
name|function_pos
argument_list|,
name|type
argument_list|)
expr_stmt|;
comment|// substitution: "M<C><Q2>F<R><B>E".
name|add_substitution
argument_list|(
name|start_pos
argument_list|,
name|type
argument_list|)
expr_stmt|;
comment|// substitution: all qualified types if any.
name|qualifiers
operator|->
name|decode_qualifiers
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
name|postfix
operator|+=
literal|")"
expr_stmt|;
name|postfix
operator|+=
name|bare_function_type
expr_stmt|;
name|postfix
operator|+=
name|member_function_qualifiers
expr_stmt|;
name|postfix
operator|+=
name|return_type_postfix
expr_stmt|;
goto|goto
name|decode_type_exit
goto|;
block|}
name|qualifiers
operator|->
name|add_qualifier_start
argument_list|(
name|pointer_to_member
argument_list|,
name|start_pos
argument_list|,
name|class_type
argument_list|,
name|M_inside_substitution
argument_list|)
expr_stmt|;
continue|continue;
block|}
default|default:
break|break;
block|}
break|break;
block|}
end_for

begin_if
if|if
condition|(
operator|!
name|failure
condition|)
block|{
comment|//<Q>G<T>			==> imaginary T Q
comment|//     substitutions: "<T>", "G<T>" (<T> recursive).
comment|//<Q>C<T>			==> complex T Q
comment|//     substitutions: "<T>", "C<T>" (<T> recursive).
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'C'
operator|||
name|current
argument_list|()
operator|==
literal|'G'
condition|)
block|{
name|prefix
operator|+=
name|current
argument_list|()
operator|==
literal|'C'
condition|?
literal|"complex "
else|:
literal|"imaginary "
expr_stmt|;
name|qualifiers
operator|->
name|add_qualifier_start
argument_list|(
name|complex_or_imaginary
argument_list|,
name|M_pos
argument_list|,
name|M_inside_substitution
argument_list|)
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
block|}
name|int
name|start_pos
init|=
name|M_pos
decl_stmt|;
switch|switch
condition|(
name|current
argument_list|()
condition|)
block|{
case|case
literal|'F'
case|:
block|{
comment|//<function-type> ::= F [Y]<bare-function-type> E
comment|//
comment|// Note that g++ never generates the 'Y', but we try to
comment|// demangle it anyway.
name|bool
name|extern_C
init|=
operator|(
name|next
argument_list|()
operator|==
literal|'Y'
operator|)
decl_stmt|;
if|if
condition|(
name|extern_C
condition|)
name|eat_current
argument_list|()
expr_stmt|;
comment|//<Q>F<R><B>E		==> R (Q)B
comment|//     substitution: "<R>", "<B>" (<B> recursive) and "F<R><B>E".
comment|// Return type.
name|string_type
name|return_type_postfix
decl_stmt|;
if|if
condition|(
operator|!
name|decode_type_with_postfix
argument_list|(
name|prefix
argument_list|,
name|return_type_postfix
argument_list|)
condition|)
comment|// Substitution: "<R>".
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
comment|// Only array and function (pointer) types have a postfix.
comment|// In that case we don't want the space but expect something
comment|// like prefix is "int (*" and postfix is ") [1]".
comment|// We do want the space if this pointer is qualified.
if|if
condition|(
name|return_type_postfix
operator|.
name|size
argument_list|()
operator|==
literal|0
operator|||
operator|(
name|prefix
operator|.
name|size
argument_list|()
operator|>
literal|0
operator|&&
operator|*
name|prefix
operator|.
name|rbegin
argument_list|()
operator|!=
literal|'*'
operator|)
condition|)
name|prefix
operator|+=
literal|' '
expr_stmt|;
name|prefix
operator|+=
literal|'('
expr_stmt|;
name|string_type
name|bare_function_type
decl_stmt|;
if|if
condition|(
operator|!
name|decode_bare_function_type
argument_list|(
name|bare_function_type
argument_list|)
comment|// substitution: "<B>" (<B> recursive).
operator|||
name|eat_current
argument_list|()
operator|!=
literal|'E'
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
name|add_substitution
argument_list|(
name|start_pos
argument_list|,
name|type
argument_list|)
expr_stmt|;
comment|// Substitution: "F<R><B>E".
name|qualifiers
operator|->
name|decode_qualifiers
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
comment|// substitution: all qualified types, if any.
name|postfix
operator|+=
literal|")"
expr_stmt|;
if|if
condition|(
name|extern_C
condition|)
name|postfix
operator|+=
literal|" [extern \"C\"] "
expr_stmt|;
name|postfix
operator|+=
name|bare_function_type
expr_stmt|;
name|postfix
operator|+=
name|return_type_postfix
expr_stmt|;
break|break;
block|}
case|case
literal|'T'
case|:
if|if
condition|(
operator|!
name|decode_template_param
argument_list|(
name|prefix
argument_list|,
name|qualifiers
argument_list|)
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'I'
condition|)
block|{
name|add_substitution
argument_list|(
name|start_pos
argument_list|,
name|template_template_param
argument_list|)
expr_stmt|;
comment|// substitution: "<template-template-param>".
if|if
condition|(
operator|!
name|decode_template_args
argument_list|(
name|prefix
argument_list|)
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|recursive_template_param_or_substitution_call
operator|&&
name|qualifiers
operator|->
name|suppressed
argument_list|()
condition|)
block|{
name|add_substitution
argument_list|(
name|start_pos
argument_list|,
name|type
argument_list|)
expr_stmt|;
comment|// substitution: "<template-param>" or
comment|// "<template-template-param><template-args>".
name|qualifiers
operator|->
name|decode_qualifiers
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
comment|// substitution: all qualified types, if any.
block|}
break|break;
case|case
literal|'S'
case|:
if|if
condition|(
name|M_pos
operator|>=
name|M_maxpos
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|M_str
index|[
name|M_pos
operator|+
literal|1
index|]
operator|!=
literal|'t'
condition|)
block|{
if|if
condition|(
operator|!
name|decode_substitution
argument_list|(
name|prefix
argument_list|,
name|qualifiers
argument_list|)
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'I'
condition|)
block|{
if|if
condition|(
operator|!
name|decode_template_args
argument_list|(
name|prefix
argument_list|)
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|!
name|recursive_template_param_or_substitution_call
operator|&&
name|qualifiers
operator|->
name|suppressed
argument_list|()
condition|)
name|add_substitution
argument_list|(
name|start_pos
argument_list|,
name|type
argument_list|)
expr_stmt|;
comment|// Substitution:
comment|//   "<template-template-param><template-args>".
block|}
if|if
condition|(
operator|!
name|recursive_template_param_or_substitution_call
operator|&&
name|qualifiers
operator|->
name|suppressed
argument_list|()
condition|)
name|qualifiers
operator|->
name|decode_qualifiers
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
comment|// Substitution: all qualified types, if any.
break|break;
block|}
comment|/* Fall-through for St */
case|case
literal|'N'
case|:
case|case
literal|'Z'
case|:
case|case
literal|'0'
case|:
case|case
literal|'1'
case|:
case|case
literal|'2'
case|:
case|case
literal|'3'
case|:
case|case
literal|'4'
case|:
case|case
literal|'5'
case|:
case|case
literal|'6'
case|:
case|case
literal|'7'
case|:
case|case
literal|'8'
case|:
case|case
literal|'9'
case|:
comment|//<Q><T>			==> T Q
comment|//     substitutions: "<T>" (<T> recursive).
if|if
condition|(
operator|!
name|decode_class_enum_type
argument_list|(
name|prefix
argument_list|)
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|!
name|recursive_template_param_or_substitution_call
condition|)
block|{
name|add_substitution
argument_list|(
name|start_pos
argument_list|,
name|type
argument_list|)
expr_stmt|;
comment|// substitution: "<class-enum-type>".
name|qualifiers
operator|->
name|decode_qualifiers
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
comment|// substitution: all qualified types, if any.
block|}
else|else
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
break|break;
default|default:
comment|//<Q><T>			==> T Q
comment|//     substitutions: "<T>" (<T> recursive).
if|if
condition|(
operator|!
name|decode_builtin_type
argument_list|(
name|prefix
argument_list|)
condition|)
block|{
name|failure
operator|=
name|true
expr_stmt|;
break|break;
block|}
comment|// If decode_type was called from decode_template_param then we
comment|// need to suppress calling qualifiers here in order to get a
comment|// substitution added anyway (for the<template-param>).
if|if
condition|(
operator|!
name|recursive_template_param_or_substitution_call
condition|)
name|qualifiers
operator|->
name|decode_qualifiers
argument_list|(
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
else|else
name|qualifiers
operator|->
name|printing_suppressed
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
end_if

begin_label
name|decode_type_exit
label|:
end_label

begin_expr_stmt
operator|--
name|M_inside_type
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|recursive_template_param_or_substitution_call
condition|)
block|{
name|qualifiers
operator|->
expr|~
name|qualifier_list
operator|<
name|Allocator
operator|>
operator|(
operator|)
expr_stmt|;
name|M_qualifier_list_alloc
operator|.
name|deallocate
argument_list|(
name|qualifiers
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|failure
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN2
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<nested-name> ::= N [<CV-qualifiers>]<prefix><unqualified-name> E
end_comment

begin_comment
comment|//               ::= N [<CV-qualifiers>]<template-prefix><template-args> E
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<prefix> ::=<prefix><unqualified-name>
end_comment

begin_comment
comment|//          ::=<template-prefix><template-args>
end_comment

begin_comment
comment|//          ::=<template-param>
end_comment

begin_comment
comment|//          ::= # empty
end_comment

begin_comment
comment|//          ::=<substitution>
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<template-prefix> ::=<prefix><template unqualified-name>
end_comment

begin_comment
comment|//                   ::=<template-param>
end_comment

begin_comment
comment|//                   ::=<substitution>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_nested_name
argument_list|(
argument|string_type& output
argument_list|,
argument|string_type& qualifiers
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_nested_name"
argument_list|)
block|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'N'
operator|||
name|M_pos
operator|>=
name|M_maxpos
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
comment|//<CV-qualifiers> ::= [r] [V] [K]  # restrict (C99), volatile, const
name|char
specifier|const
operator|*
name|qualifiers_start
operator|=
operator|&
name|M_str
index|[
name|M_pos
operator|+
literal|1
index|]
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|char
name|c
init|=
name|next
argument_list|()
init|;
name|c
operator|==
literal|'K'
operator|||
name|c
operator|==
literal|'V'
operator|||
name|c
operator|==
literal|'r'
condition|;
name|c
operator|=
name|next
argument_list|()
control|)
empty_stmt|;
end_for

begin_for
for|for
control|(
name|char
specifier|const
modifier|*
name|qualifier_ptr
init|=
operator|&
name|M_str
index|[
name|M_pos
operator|-
literal|1
index|]
init|;
name|qualifier_ptr
operator|>=
name|qualifiers_start
condition|;
operator|--
name|qualifier_ptr
control|)
switch|switch
condition|(
operator|*
name|qualifier_ptr
condition|)
block|{
case|case
literal|'K'
case|:
name|qualifiers
operator|+=
literal|" const"
expr_stmt|;
break|break;
case|case
literal|'V'
case|:
name|qualifiers
operator|+=
literal|" volatile"
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
name|qualifiers
operator|+=
literal|" restrict"
expr_stmt|;
break|break;
block|}
end_for

begin_decl_stmt
name|int
name|number_of_prefixes
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|substitution_start
init|=
name|M_pos
decl_stmt|;
end_decl_stmt

begin_for
for|for
control|(
init|;
condition|;
control|)
block|{
operator|++
name|number_of_prefixes
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'S'
condition|)
block|{
if|if
condition|(
operator|!
name|decode_substitution
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'I'
condition|)
block|{
if|if
condition|(
operator|!
name|decode_template_args
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'E'
condition|)
block|{
comment|// substitution: "<template-prefix><template-args>".
name|add_substitution
argument_list|(
name|substitution_start
argument_list|,
name|nested_name_prefix
argument_list|,
name|number_of_prefixes
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'T'
condition|)
block|{
if|if
condition|(
operator|!
name|decode_template_param
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|decode_unqualified_name
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'E'
condition|)
block|{
comment|// substitution: "<prefix><unqualified-name>" or
comment|// "<prefix><template unqualified-name>".
name|add_substitution
argument_list|(
name|substitution_start
argument_list|,
operator|(
name|current
argument_list|()
operator|==
literal|'I'
operator|)
condition|?
name|nested_name_template_prefix
else|:
name|nested_name_prefix
argument_list|,
name|number_of_prefixes
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'E'
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'I'
condition|)
name|output
operator|+=
literal|"::"
expr_stmt|;
elseif|else
if|if
condition|(
name|M_template_args_need_space
condition|)
name|output
operator|+=
literal|' '
expr_stmt|;
name|M_template_args_need_space
operator|=
name|false
expr_stmt|;
block|}
end_for

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<local-name> := Z<function encoding> E<entity name> [<discriminator>]
end_comment

begin_comment
comment|//              := Z<function encoding> E s [<discriminator>]
end_comment

begin_comment
comment|//<discriminator> := _<non-negative number>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_local_name
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_local_name"
argument_list|)
block|;
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'Z'
operator|||
name|M_pos
operator|>=
name|M_maxpos
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|(
name|M_pos
operator|+=
name|decode_encoding
argument_list|(
name|output
argument_list|,
name|M_str
operator|+
name|M_pos
operator|+
literal|1
argument_list|,
name|M_maxpos
operator|-
name|M_pos
argument_list|,
name|M_implementation_details
argument_list|)
operator|+
literal|1
operator|)
operator|<
literal|0
operator|||
name|eat_current
argument_list|()
operator|!=
literal|'E'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_if

begin_expr_stmt
name|output
operator|+=
literal|"::"
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'s'
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
name|output
operator|+=
literal|"string literal"
expr_stmt|;
block|}
else|else
block|{
name|string_type
name|nested_name_qualifiers
decl_stmt|;
if|if
condition|(
operator|!
name|decode_name
argument_list|(
name|output
argument_list|,
name|nested_name_qualifiers
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
name|nested_name_qualifiers
expr_stmt|;
block|}
end_if

begin_decl_stmt
name|string_type
name|discriminator
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'_'
operator|&&
name|next
argument_list|()
operator|!=
literal|'n'
operator|&&
operator|!
name|decode_number
argument_list|(
name|discriminator
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<source-name> ::=<positive length number><identifier>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_source_name
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_source_name"
argument_list|)
block|;
name|int
name|length
operator|=
name|current
argument_list|()
operator|-
literal|'0'
block|;
if|if
condition|(
name|length
operator|<
literal|1
operator|||
name|length
operator|>
literal|9
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|isdigit
argument_list|(
name|next
argument_list|()
argument_list|)
condition|)
name|length
operator|=
literal|10
operator|*
name|length
operator|+
name|current
argument_list|()
operator|-
literal|'0'
expr_stmt|;
end_while

begin_decl_stmt
name|char
specifier|const
modifier|*
name|ptr
init|=
operator|&
name|M_str
index|[
name|M_pos
index|]
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|length
operator|>
literal|11
operator|&&
operator|!
name|strncmp
argument_list|(
name|ptr
argument_list|,
literal|"_GLOBAL_"
argument_list|,
literal|8
argument_list|)
operator|&&
name|ptr
index|[
literal|9
index|]
operator|==
literal|'N'
operator|&&
name|ptr
index|[
literal|8
index|]
operator|==
name|ptr
index|[
literal|10
index|]
condition|)
block|{
name|output
operator|+=
literal|"(anonymous namespace)"
expr_stmt|;
if|if
condition|(
operator|(
name|M_pos
operator|+=
name|length
operator|)
operator|>
name|M_maxpos
operator|+
literal|1
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
else|else
while|while
condition|(
name|length
operator|--
condition|)
block|{
if|if
condition|(
name|current
argument_list|()
operator|==
literal|0
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
name|eat_current
argument_list|()
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<unqualified-name> ::=<operator-name>	# Starts with lower case.
end_comment

begin_comment
comment|//                    ::=<ctor-dtor-name>  # Starts with 'C' or 'D'.
end_comment

begin_comment
comment|//                    ::=<source-name>	# Starts with a digit.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_unqualified_name
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_unqualified_name"
argument_list|)
block|;
if|if
condition|(
name|M_inside_template_args
condition|)
block|{
if|if
condition|(
operator|!
name|decode_source_name
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|isdigit
argument_list|(
name|current
argument_list|()
argument_list|)
condition|)
block|{
name|bool
name|recursive_unqualified_name
init|=
operator|(
operator|&
name|M_function_name
operator|==
operator|&
name|output
operator|)
decl_stmt|;
comment|// This can be a recursive call when we are decoding
comment|// an<operator-name> that is a cast operator for a some
comment|//<unqualified-name>; for example "operator Foo()".
comment|// In that case this is thus not a ctor or dtor and we
comment|// are not interested in updating M_function_name.
if|if
condition|(
operator|!
name|recursive_unqualified_name
condition|)
name|M_function_name
operator|.
name|clear
argument_list|()
expr_stmt|;
name|M_name_is_template
operator|=
name|false
expr_stmt|;
name|M_name_is_cdtor
operator|=
name|false
expr_stmt|;
name|M_name_is_conversion_operator
operator|=
name|false
expr_stmt|;
if|if
condition|(
operator|!
name|decode_source_name
argument_list|(
name|M_function_name
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
operator|!
name|recursive_unqualified_name
condition|)
name|output
operator|+=
name|M_function_name
expr_stmt|;
block|}
end_elseif

begin_elseif
elseif|else
if|if
condition|(
name|islower
argument_list|(
name|current
argument_list|()
argument_list|)
condition|)
block|{
name|M_function_name
operator|.
name|clear
argument_list|()
expr_stmt|;
name|M_name_is_template
operator|=
name|false
expr_stmt|;
name|M_name_is_cdtor
operator|=
name|false
expr_stmt|;
name|M_name_is_conversion_operator
operator|=
name|false
expr_stmt|;
if|if
condition|(
operator|!
name|decode_operator_name
argument_list|(
name|M_function_name
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
name|M_function_name
expr_stmt|;
block|}
end_elseif

begin_elseif
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'C'
operator|||
name|current
argument_list|()
operator|==
literal|'D'
condition|)
block|{
comment|//<ctor-dtor-name> ::=
comment|//   C1	# complete object (in-charge) constructor
comment|//   C2	# base object (not-in-charge) constructor
comment|//   C3	# complete object (in-charge) allocating constructor
comment|//   D0	# deleting (in-charge) destructor
comment|//   D1	# complete object (in-charge) destructor
comment|//   D2	# base object (not-in-charge) destructor
comment|//
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'C'
condition|)
block|{
name|char
name|c
init|=
name|next
argument_list|()
decl_stmt|;
if|if
condition|(
name|c
operator|<
literal|'1'
operator|||
name|c
operator|>
literal|'3'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
else|else
block|{
name|char
name|c
init|=
name|next
argument_list|()
decl_stmt|;
if|if
condition|(
name|c
operator|<
literal|'0'
operator|||
name|c
operator|>
literal|'2'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|'~'
expr_stmt|;
name|M_saw_destructor
operator|=
name|true
expr_stmt|;
block|}
name|M_name_is_cdtor
operator|=
name|true
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
name|output
operator|+=
name|M_function_name
expr_stmt|;
block|}
end_elseif

begin_else
else|else
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_else

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<unscoped-name> ::=
end_comment

begin_comment
comment|//<unqualified-name>		# Starts not with an 'S'
end_comment

begin_comment
comment|//   St<unqualified-name>		# ::std::
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_unscoped_name
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_unscoped_name"
argument_list|)
block|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'S'
condition|)
block|{
if|if
condition|(
name|next
argument_list|()
operator|!=
literal|'t'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
name|output
operator|+=
literal|"std::"
expr_stmt|;
block|}
name|decode_unqualified_name
argument_list|(
name|output
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<name> ::=
end_comment

begin_comment
comment|//<nested-name>				# Starts with 'N'
end_comment

begin_comment
comment|//<unscoped-template-name><template-args> # idem
end_comment

begin_comment
comment|//<local-name>				# Starts with 'Z'
end_comment

begin_comment
comment|//<unscoped-name>			# Starts with 'S', 'C', 'D',
end_comment

begin_comment
comment|//						# a digit or a lower case
end_comment

begin_comment
comment|//						# character.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<unscoped-template-name> ::=<unscoped-name>
end_comment

begin_comment
comment|//                          ::=<substitution>
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_name
argument_list|(
argument|string_type& output
argument_list|,
argument|string_type& nested_name_qualifiers
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_name"
argument_list|)
block|;
name|int
name|substitution_start
operator|=
name|M_pos
block|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'S'
operator|&&
operator|(
name|M_pos
operator|>=
name|M_maxpos
operator|||
name|M_str
index|[
name|M_pos
operator|+
literal|1
index|]
operator|!=
literal|'t'
operator|)
condition|)
block|{
if|if
condition|(
operator|!
name|decode_substitution
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'N'
condition|)
block|{
name|decode_nested_name
argument_list|(
name|output
argument_list|,
name|nested_name_qualifiers
argument_list|)
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_elseif

begin_elseif
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'Z'
condition|)
block|{
name|decode_local_name
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_elseif

begin_elseif
elseif|else
if|if
condition|(
operator|!
name|decode_unscoped_name
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_elseif

begin_if
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'I'
condition|)
block|{
comment|// Must have been an<unscoped-template-name>.
name|add_substitution
argument_list|(
name|substitution_start
argument_list|,
name|unscoped_template_name
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|decode_template_args
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|M_template_args_need_space
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//<call-offset> ::= h<nv-offset> _
end_comment

begin_comment
comment|//               ::= v<v-offset> _
end_comment

begin_comment
comment|//<nv-offset>   ::=<offset number>
end_comment

begin_comment
comment|//     non-virtual base override
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<v-offset>    ::=<offset number> _<virtual offset number>
end_comment

begin_comment
comment|//     virtual base override, with vcall offset
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_call_offset
argument_list|(
argument|string_type&
if|#
directive|if
name|_GLIBCXX_DEMANGLER_CWDEBUG
argument|output
endif|#
directive|endif
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_call_offset"
argument_list|)
block|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'h'
condition|)
block|{
name|string_type
name|dummy
decl_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
name|decode_number
argument_list|(
name|dummy
argument_list|)
operator|&&
name|current
argument_list|()
operator|==
literal|'_'
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_expr_stmt

begin_if
unit|} 	else
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'v'
condition|)
block|{
name|string_type
name|dummy
decl_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
name|decode_number
argument_list|(
name|dummy
argument_list|)
operator|&&
name|current
argument_list|()
operator|==
literal|'_'
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
name|decode_number
argument_list|(
name|dummy
argument_list|)
operator|&&
name|current
argument_list|()
operator|==
literal|'_'
condition|)
block|{
name|eat_current
argument_list|()
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
block|}
block|}
end_if

begin_expr_stmt
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//
end_comment

begin_comment
comment|//<special-name> ::=
end_comment

begin_comment
comment|//   TV<type>			# virtual table
end_comment

begin_comment
comment|//   TT<type>			# VTT structure (construction
end_comment

begin_comment
comment|//                                    vtable index).
end_comment

begin_comment
comment|//   TI<type>			# typeinfo structure
end_comment

begin_comment
comment|//   TS<type>			# typeinfo name (null-terminated
end_comment

begin_comment
comment|//                                    byte string).
end_comment

begin_comment
comment|//   GV<object name>		# Guard variable for one-time
end_comment

begin_comment
comment|//					  initialization of static objects in
end_comment

begin_comment
comment|//					  a local scope.
end_comment

begin_comment
comment|//   T<call-offset><base encoding># base is the nominal target function
end_comment

begin_comment
comment|//					  of thunk.
end_comment

begin_comment
comment|//   Tc<call-offset><call-offset><base encoding> # base is the nominal
end_comment

begin_comment
comment|//                                    target function of thunk; first
end_comment

begin_comment
comment|//                                    call-offset is 'this' adjustment;
end_comment

begin_comment
comment|//					  second call-offset is result
end_comment

begin_comment
comment|//					  adjustment
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|bool
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_special_name
argument_list|(
argument|string_type& output
argument_list|)
block|{
name|_GLIBCXX_DEMANGLER_DOUT_ENTERING
argument_list|(
literal|"decode_special_name"
argument_list|)
block|;
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'G'
condition|)
block|{
if|if
condition|(
name|next
argument_list|()
operator|!=
literal|'V'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|"guard variable for "
expr_stmt|;
name|string_type
name|nested_name_qualifiers
decl_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|decode_name
argument_list|(
name|output
argument_list|,
name|nested_name_qualifiers
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
name|nested_name_qualifiers
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|current
argument_list|()
operator|!=
literal|'T'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
end_elseif

begin_switch
switch|switch
condition|(
name|next
argument_list|()
condition|)
block|{
case|case
literal|'V'
case|:
name|output
operator|+=
literal|"vtable for "
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
name|decode_type
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
case|case
literal|'T'
case|:
name|output
operator|+=
literal|"VTT for "
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
name|decode_type
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
case|case
literal|'I'
case|:
name|output
operator|+=
literal|"typeinfo for "
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
name|decode_type
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
case|case
literal|'S'
case|:
name|output
operator|+=
literal|"typeinfo name for "
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
name|decode_type
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
case|case
literal|'c'
case|:
name|output
operator|+=
literal|"covariant return thunk to "
expr_stmt|;
if|if
condition|(
operator|!
name|decode_call_offset
argument_list|(
name|output
argument_list|)
operator|||
operator|!
name|decode_call_offset
argument_list|(
name|output
argument_list|)
operator|||
operator|(
name|M_pos
operator|+=
name|decode_encoding
argument_list|(
name|output
argument_list|,
name|M_str
operator|+
name|M_pos
argument_list|,
name|M_maxpos
operator|-
name|M_pos
operator|+
literal|1
argument_list|,
name|M_implementation_details
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
case|case
literal|'C'
case|:
comment|// GNU extension?
block|{
name|string_type
name|first
decl_stmt|;
name|output
operator|+=
literal|"construction vtable for "
expr_stmt|;
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|first
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
while|while
condition|(
name|isdigit
argument_list|(
name|current
argument_list|()
argument_list|)
condition|)
name|eat_current
argument_list|()
expr_stmt|;
if|if
condition|(
name|eat_current
argument_list|()
operator|!=
literal|'_'
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
if|if
condition|(
operator|!
name|decode_type
argument_list|(
name|output
argument_list|)
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|output
operator|+=
literal|"-in-"
expr_stmt|;
name|output
operator|+=
name|first
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
default|default:
if|if
condition|(
name|current
argument_list|()
operator|==
literal|'v'
condition|)
name|output
operator|+=
literal|"virtual thunk to "
expr_stmt|;
else|else
name|output
operator|+=
literal|"non-virtual thunk to "
expr_stmt|;
if|if
condition|(
operator|!
name|decode_call_offset
argument_list|(
name|output
argument_list|)
operator|||
operator|(
name|M_pos
operator|+=
name|decode_encoding
argument_list|(
name|output
argument_list|,
name|M_str
operator|+
name|M_pos
argument_list|,
name|M_maxpos
operator|-
name|M_pos
operator|+
literal|1
argument_list|,
name|M_implementation_details
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|_GLIBCXX_DEMANGLER_FAILURE
expr_stmt|;
name|_GLIBCXX_DEMANGLER_RETURN
expr_stmt|;
block|}
end_switch

begin_comment
unit|}
comment|//<encoding> ::=
end_comment

begin_comment
comment|//<function name><bare-function-type>	# Starts with 'C', 'D', 'N',
end_comment

begin_comment
comment|//						  'S', a digit or a lower case
end_comment

begin_comment
comment|//						  character.
end_comment

begin_comment
comment|//<data name>				# Idem.
end_comment

begin_comment
comment|//<special-name>				# Starts with 'T' or 'G'.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|int
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|decode_encoding
argument_list|(
argument|string_type& output
argument_list|,
argument|char const* in
argument_list|,
argument|int len
argument_list|,
argument|implementation_details const& id
argument_list|)
block|{
if|#
directive|if
name|_GLIBCXX_DEMANGLER_CWDEBUG
name|_GLIBCXX_DEMANGLER_DOUT
argument_list|(
name|dc
operator|::
name|demangler
argument_list|,
literal|"Output thus far: \""
operator|<<
name|output
operator|<<
literal|'"'
argument_list|)
block|;
name|string_type
name|input
argument_list|(
name|in
argument_list|,
name|len
operator|>
literal|0x40000000
condition|?
name|strlen
argument_list|(
name|in
argument_list|)
else|:
name|len
argument_list|)
block|;
name|_GLIBCXX_DEMANGLER_DOUT
argument_list|(
name|dc
operator|::
name|demangler
argument_list|,
literal|"Entering decode_encoding(\""
operator|<<
name|input
operator|<<
literal|"\")"
argument_list|)
block|;
endif|#
directive|endif
if|if
condition|(
name|len
operator|<=
literal|0
condition|)
return|return
name|INT_MIN
return|;
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
name|demangler_session
argument_list|(
name|in
argument_list|,
name|len
argument_list|,
name|id
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|string_type
name|nested_name_qualifiers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|saved_pos
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|demangler_session
operator|.
name|store
argument_list|(
name|saved_pos
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|demangler_session
operator|.
name|decode_special_name
argument_list|(
name|output
argument_list|)
condition|)
return|return
name|demangler_session
operator|.
name|M_pos
return|;
end_if

begin_expr_stmt
name|demangler_session
operator|.
name|restore
argument_list|(
name|saved_pos
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|string_type
name|name
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
operator|!
name|demangler_session
operator|.
name|decode_name
argument_list|(
name|name
argument_list|,
name|nested_name_qualifiers
argument_list|)
condition|)
return|return
name|INT_MIN
return|;
end_if

begin_if
if|if
condition|(
name|demangler_session
operator|.
name|current
argument_list|()
operator|==
literal|0
operator|||
name|demangler_session
operator|.
name|current
argument_list|()
operator|==
literal|'E'
condition|)
block|{
name|output
operator|+=
name|name
expr_stmt|;
name|output
operator|+=
name|nested_name_qualifiers
expr_stmt|;
return|return
name|demangler_session
operator|.
name|M_pos
return|;
block|}
end_if

begin_comment
comment|// Must have been a<function name>.
end_comment

begin_decl_stmt
name|string_type
name|return_type_postfix
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|demangler_session
operator|.
name|M_name_is_template
operator|&&
operator|!
operator|(
name|demangler_session
operator|.
name|M_name_is_cdtor
operator|||
name|demangler_session
operator|.
name|M_name_is_conversion_operator
operator|)
condition|)
block|{
comment|// Return type of function
if|if
condition|(
operator|!
name|demangler_session
operator|.
name|decode_type_with_postfix
argument_list|(
name|output
argument_list|,
name|return_type_postfix
argument_list|)
condition|)
return|return
name|INT_MIN
return|;
name|output
operator|+=
literal|' '
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|output
operator|+=
name|name
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|demangler_session
operator|.
name|decode_bare_function_type
argument_list|(
name|output
argument_list|)
condition|)
return|return
name|INT_MIN
return|;
end_if

begin_expr_stmt
name|output
operator|+=
name|nested_name_qualifiers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|output
operator|+=
name|return_type_postfix
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|demangler_session
operator|.
name|M_pos
return|;
end_return

begin_comment
unit|}      }
comment|// namespace demangler
end_comment

begin_comment
comment|// Public interface
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
expr|struct
name|demangle
block|{
typedef|typedef
name|typename
name|Allocator
operator|::
name|template
name|rebind
operator|<
name|char
operator|>
operator|::
name|other
name|char_Allocator
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|basic_string
operator|<
name|char
operator|,
name|std
operator|::
name|char_traits
operator|<
name|char
operator|>
operator|,
name|char_Allocator
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
name|string_type
name|symbol
argument_list|(
name|char
specifier|const
operator|*
name|in
argument_list|,
name|demangler
operator|::
name|implementation_details
specifier|const
operator|&
name|id
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|string_type
name|type
argument_list|(
name|char
specifier|const
operator|*
name|in
argument_list|,
name|demangler
operator|::
name|implementation_details
specifier|const
operator|&
name|id
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// demangle::symbol()
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Demangle `input' which should be a mangled function name as for
end_comment

begin_comment
comment|// instance returned by nm(1).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|typename
name|demangle
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|string_type
name|demangle
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|symbol
argument_list|(
argument|char const* input
argument_list|,
argument|demangler::implementation_details const& id
argument_list|)
block|{
comment|//<mangled-name> ::= _Z<encoding>
comment|//<mangled-name> ::= _GLOBAL_ _<type>_<disambiguation part>
comment|//<type> can be I or D (GNU extension)
typedef|typedef
name|demangler
operator|::
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
name|demangler_type
expr_stmt|;
name|string_type
name|result
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|failure
init|=
operator|(
name|input
index|[
literal|0
index|]
operator|!=
literal|'_'
operator|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
operator|!
name|failure
condition|)
block|{
if|if
condition|(
name|input
index|[
literal|1
index|]
operator|==
literal|'G'
condition|)
block|{
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|input
argument_list|,
literal|"_GLOBAL__"
argument_list|,
literal|9
argument_list|)
operator|&&
operator|(
name|input
index|[
literal|9
index|]
operator|==
literal|'D'
operator|||
name|input
index|[
literal|9
index|]
operator|==
literal|'I'
operator|)
operator|&&
name|input
index|[
literal|10
index|]
operator|==
literal|'_'
condition|)
block|{
if|if
condition|(
name|input
index|[
literal|9
index|]
operator|==
literal|'D'
condition|)
name|result
operator|.
name|assign
argument_list|(
literal|"global destructors keyed to "
argument_list|,
literal|28
argument_list|)
expr_stmt|;
else|else
name|result
operator|.
name|assign
argument_list|(
literal|"global constructors keyed to "
argument_list|,
literal|29
argument_list|)
expr_stmt|;
comment|// Output the disambiguation part as-is.
name|result
operator|+=
name|input
operator|+
literal|11
expr_stmt|;
block|}
else|else
name|failure
operator|=
name|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|input
index|[
literal|1
index|]
operator|==
literal|'Z'
condition|)
block|{
name|int
name|cnt
init|=
name|demangler_type
operator|::
name|decode_encoding
argument_list|(
name|result
argument_list|,
name|input
operator|+
literal|2
argument_list|,
name|INT_MAX
argument_list|,
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
name|cnt
operator|<
literal|0
operator|||
name|input
index|[
name|cnt
operator|+
literal|2
index|]
operator|!=
literal|0
condition|)
name|failure
operator|=
name|true
expr_stmt|;
block|}
else|else
name|failure
operator|=
name|true
expr_stmt|;
block|}
end_if

begin_comment
comment|// Failure to demangle, return the mangled name.
end_comment

begin_if
if|if
condition|(
name|failure
condition|)
name|result
operator|.
name|assign
argument_list|(
name|input
argument_list|,
name|strlen
argument_list|(
name|input
argument_list|)
argument_list|)
expr_stmt|;
end_if

begin_return
return|return
name|result
return|;
end_return

begin_comment
unit|}
comment|// demangle::type()
end_comment

begin_comment
comment|// Demangle `input' which must be a zero terminated mangled type
end_comment

begin_comment
comment|// name as for instance returned by std::type_info::name().
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tp
operator|,
name|typename
name|Allocator
operator|>
name|typename
name|demangle
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|string_type
name|demangle
operator|<
name|Tp
operator|,
name|Allocator
operator|>
operator|::
name|type
argument_list|(
argument|char const* input
argument_list|,
argument|demangler::implementation_details const& id
argument_list|)
block|{
name|std
operator|::
name|basic_string
operator|<
name|char
block|,
name|std
operator|::
name|char_traits
operator|<
name|char
operator|>
block|,
name|Allocator
operator|>
name|result
block|;
if|if
condition|(
name|input
operator|==
name|NULL
condition|)
name|result
operator|=
literal|"(null)"
expr_stmt|;
else|else
block|{
name|demangler
operator|::
name|session
operator|<
name|Tp
operator|,
name|Allocator
operator|>
name|demangler_session
argument_list|(
name|input
argument_list|,
name|INT_MAX
argument_list|,
name|id
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|demangler_session
operator|.
name|decode_type
argument_list|(
name|result
argument_list|)
operator|||
name|demangler_session
operator|.
name|remaining_input_characters
argument_list|()
condition|)
block|{
comment|// Failure to demangle, return the mangled name.
name|result
operator|=
name|input
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}       return
name|result
expr_stmt|;
end_expr_stmt

begin_comment
unit|} }
comment|// namespace __gnu_cxx
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __DEMANGLE_H
end_comment

end_unit

