begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2005, 2006 Free Software Foundation, Inc.
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
comment|// You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// along with this library; see the file COPYING.  If not, write to
end_comment

begin_comment
comment|// the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
end_comment

begin_comment
comment|// MA 02111-1307, USA.
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
comment|// Copyright (C) 2004 Ami Tavory and Vladimir Dreizin, IBM-HRL.
end_comment

begin_comment
comment|// Permission to use, copy, modify, sell, and distribute this software
end_comment

begin_comment
comment|// is hereby granted without fee, provided that the above copyright
end_comment

begin_comment
comment|// notice appears in all copies, and that both that copyright notice
end_comment

begin_comment
comment|// and this permission notice appear in supporting documentation. None
end_comment

begin_comment
comment|// of the above authors, nor IBM Haifa Research Laboratories, make any
end_comment

begin_comment
comment|// representation about the suitability of this software for any
end_comment

begin_comment
comment|// purpose. It is provided "as is" without express or implied
end_comment

begin_comment
comment|// warranty.
end_comment

begin_comment
comment|/** @file ext/vstring.h  *  This file is a GNU extension to the Standard C++ Library.  *  *  Contains an exception-throwing allocator, useful for testing  *  exception safety. In addition, allocation addresses are stored and  *  sanity checked.  */
end_comment

begin_comment
comment|/**  * @file throw_allocator.h   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_THROW_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_THROW_ALLOCATOR_H
value|1
end_define

begin_include
include|#
directive|include
file|<cmath>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<ostream>
end_include

begin_include
include|#
directive|include
file|<stdexcept>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<tr1/random>
end_include

begin_include
include|#
directive|include
file|<bits/functexcept.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_decl_stmt
name|class
name|twister_rand_gen
block|{
name|public
label|:
name|twister_rand_gen
argument_list|(
argument|unsigned int seed =  		     static_cast<unsigned int>(std::time(
literal|0
argument|))
argument_list|)
empty_stmt|;
name|void
name|init
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
name|double
name|get_prob
parameter_list|()
function_decl|;
name|private
label|:
name|std
operator|::
name|tr1
operator|::
name|mt19937
name|_M_generator
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|forced_exception_error
range|:
name|public
name|std
operator|::
name|exception
block|{ }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Substitute for concurrence_error object in the case of -fno-exceptions.
end_comment

begin_function
specifier|inline
name|void
name|__throw_forced_exception_error
parameter_list|()
block|{
if|#
directive|if
name|__EXCEPTIONS
name|throw
name|forced_exception_error
parameter_list|()
function_decl|;
else|#
directive|else
name|__builtin_abort
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_decl_stmt
name|class
name|throw_allocator_base
block|{
name|public
label|:
name|void
name|init
parameter_list|(
name|unsigned
name|long
name|seed
parameter_list|)
function_decl|;
specifier|static
name|void
name|set_throw_prob
parameter_list|(
name|double
name|throw_prob
parameter_list|)
function_decl|;
specifier|static
name|double
name|get_throw_prob
parameter_list|()
function_decl|;
specifier|static
name|void
name|set_label
parameter_list|(
name|size_t
name|l
parameter_list|)
function_decl|;
specifier|static
name|bool
name|empty
parameter_list|()
function_decl|;
struct|struct
name|group_throw_prob_adjustor
block|{
name|group_throw_prob_adjustor
argument_list|(
argument|size_t size
argument_list|)
block|:
name|_M_throw_prob_orig
argument_list|(
argument|_S_throw_prob
argument_list|)
block|{
name|_S_throw_prob
operator|=
literal|1
operator|-
operator|::
name|pow
argument_list|(
name|double
argument_list|(
literal|1
operator|-
name|_S_throw_prob
argument_list|)
argument_list|,
name|double
argument_list|(
literal|0.5
operator|/
operator|(
name|size
operator|+
literal|1
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
operator|~
name|group_throw_prob_adjustor
argument_list|()
block|{
name|_S_throw_prob
operator|=
name|_M_throw_prob_orig
block|; }
name|private
operator|:
specifier|const
name|double
name|_M_throw_prob_orig
expr_stmt|;
block|}
struct|;
struct|struct
name|zero_throw_prob_adjustor
block|{
name|zero_throw_prob_adjustor
argument_list|()
operator|:
name|_M_throw_prob_orig
argument_list|(
argument|_S_throw_prob
argument_list|)
block|{
name|_S_throw_prob
operator|=
literal|0
block|; }
operator|~
name|zero_throw_prob_adjustor
argument_list|()
block|{
name|_S_throw_prob
operator|=
name|_M_throw_prob_orig
block|; }
name|private
operator|:
specifier|const
name|double
name|_M_throw_prob_orig
expr_stmt|;
block|}
struct|;
name|protected
label|:
specifier|static
name|void
name|insert
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|static
name|void
name|erase
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|static
name|void
name|throw_conditionally
parameter_list|()
function_decl|;
comment|// See if a particular address and size has been allocated by this
comment|// allocator.
specifier|static
name|void
name|check_allocated
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|// See if a given label has been allocated by this allocator.
specifier|static
name|void
name|check_allocated
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|size_t
operator|,
name|size_t
operator|>
name|alloc_data_type
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|void
operator|*
operator|,
name|alloc_data_type
operator|>
name|map_type
expr_stmt|;
typedef|typedef
name|map_type
operator|::
name|value_type
name|entry_type
expr_stmt|;
typedef|typedef
name|map_type
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|map_type
operator|::
name|const_reference
name|const_reference
expr_stmt|;
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
operator|,
specifier|const
name|throw_allocator_base
operator|&
operator|)
expr_stmt|;
specifier|static
name|entry_type
name|make_entry
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|static
name|void
name|print_to_string
argument_list|(
name|std
operator|::
name|string
operator|&
argument_list|)
decl_stmt|;
specifier|static
name|void
name|print_to_string
argument_list|(
name|std
operator|::
name|string
operator|&
argument_list|,
name|const_reference
argument_list|)
decl_stmt|;
specifier|static
name|twister_rand_gen
name|_S_g
decl_stmt|;
specifier|static
name|map_type
name|_S_map
decl_stmt|;
specifier|static
name|double
name|_S_throw_prob
decl_stmt|;
specifier|static
name|size_t
name|_S_label
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|throw_allocator
operator|:
name|public
name|throw_allocator_base
block|{
name|public
operator|:
typedef|typedef
name|size_t
name|size_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|T
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|value_type
modifier|&
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|&
name|const_reference
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|throw_allocator
operator|<
name|U
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|throw_allocator
argument_list|()
end_macro

begin_macro
name|throw
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|throw_allocator
argument_list|(
argument|const throw_allocator&
argument_list|)
end_macro

begin_macro
name|throw
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
name|throw_allocator
argument_list|(
argument|const throw_allocator<U>&
argument_list|)
name|throw
argument_list|()
block|{ }
operator|~
name|throw_allocator
argument_list|()
name|throw
argument_list|()
block|{ }
name|size_type
name|max_size
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|std
operator|::
name|allocator
operator|<
name|value_type
operator|>
operator|(
operator|)
operator|.
name|max_size
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|pointer
name|allocate
argument_list|(
name|size_type
name|num
argument_list|,
name|std
operator|::
name|allocator
operator|<
name|void
operator|>
operator|::
name|const_pointer
name|hint
operator|=
literal|0
argument_list|)
block|{
name|throw_conditionally
argument_list|()
expr_stmt|;
name|value_type
modifier|*
specifier|const
name|a
init|=
name|std
operator|::
name|allocator
operator|<
name|value_type
operator|>
operator|(
operator|)
operator|.
name|allocate
argument_list|(
name|num
argument_list|,
name|hint
argument_list|)
decl_stmt|;
name|insert
argument_list|(
name|a
argument_list|,
sizeof|sizeof
argument_list|(
name|value_type
argument_list|)
operator|*
name|num
argument_list|)
expr_stmt|;
return|return
name|a
return|;
block|}
end_decl_stmt

begin_function
name|void
name|construct
parameter_list|(
name|pointer
name|p
parameter_list|,
specifier|const
name|T
modifier|&
name|val
parameter_list|)
block|{
return|return
name|std
operator|::
name|allocator
operator|<
name|value_type
operator|>
operator|(
operator|)
operator|.
name|construct
argument_list|(
name|p
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|destroy
parameter_list|(
name|pointer
name|p
parameter_list|)
block|{
name|std
operator|::
name|allocator
operator|<
name|value_type
operator|>
operator|(
operator|)
operator|.
name|destroy
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|deallocate
parameter_list|(
name|pointer
name|p
parameter_list|,
name|size_type
name|num
parameter_list|)
block|{
name|erase
argument_list|(
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|value_type
argument_list|)
operator|*
name|num
argument_list|)
expr_stmt|;
name|std
operator|::
name|allocator
operator|<
name|value_type
operator|>
operator|(
operator|)
operator|.
name|deallocate
argument_list|(
name|p
argument_list|,
name|num
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|check_allocated
parameter_list|(
name|pointer
name|p
parameter_list|,
name|size_type
name|num
parameter_list|)
block|{
name|throw_allocator_base
operator|::
name|check_allocated
argument_list|(
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|value_type
argument_list|)
operator|*
name|num
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|check_allocated
parameter_list|(
name|size_type
name|label
parameter_list|)
block|{
name|throw_allocator_base
operator|::
name|check_allocated
argument_list|(
name|label
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|throw_allocator
operator|<
name|T
operator|>
operator|&
operator|,
specifier|const
name|throw_allocator
operator|<
name|T
operator|>
operator|&
operator|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|throw_allocator
operator|<
name|T
operator|>
operator|&
operator|,
specifier|const
name|throw_allocator
operator|<
name|T
operator|>
operator|&
operator|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
specifier|const
name|throw_allocator_base
operator|&
name|alloc
operator|)
block|{
name|std
operator|::
name|string
name|error
block|;
name|throw_allocator_base
operator|::
name|print_to_string
argument_list|(
name|error
argument_list|)
block|;
name|os
operator|<<
name|error
block|;
return|return
name|os
return|;
block|}
end_expr_stmt

begin_comment
comment|// XXX Should be in .cc.
end_comment

begin_expr_stmt
name|twister_rand_gen
operator|::
name|twister_rand_gen
argument_list|(
argument|unsigned int seed
argument_list|)
operator|:
name|_M_generator
argument_list|(
argument|seed
argument_list|)
block|{ }
name|void
name|twister_rand_gen
operator|::
name|init
argument_list|(
argument|unsigned int seed
argument_list|)
block|{
name|_M_generator
operator|.
name|seed
argument_list|(
name|seed
argument_list|)
block|; }
name|double
name|twister_rand_gen
operator|::
name|get_prob
argument_list|()
block|{
specifier|const
name|double
name|eng_min
operator|=
name|_M_generator
operator|.
name|min
argument_list|()
block|;
specifier|const
name|double
name|eng_range
operator|=
name|static_cast
operator|<
specifier|const
name|double
operator|>
operator|(
name|_M_generator
operator|.
name|max
argument_list|()
operator|-
name|eng_min
operator|)
block|;
specifier|const
name|double
name|eng_res
operator|=
name|static_cast
operator|<
specifier|const
name|double
operator|>
operator|(
name|_M_generator
argument_list|()
operator|-
name|eng_min
operator|)
block|;
specifier|const
name|double
name|ret
operator|=
name|eng_res
operator|/
name|eng_range
block|;
name|_GLIBCXX_DEBUG_ASSERT
argument_list|(
name|ret
operator|>=
literal|0
operator|&&
name|ret
operator|<=
literal|1
argument_list|)
block|;
return|return
name|ret
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|twister_rand_gen
name|throw_allocator_base
operator|::
name|_S_g
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|throw_allocator_base
operator|::
name|map_type
name|throw_allocator_base
operator|::
name|_S_map
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|double
name|throw_allocator_base
operator|::
name|_S_throw_prob
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|size_t
name|throw_allocator_base
operator|::
name|_S_label
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|throw_allocator_base
operator|::
name|entry_type
name|throw_allocator_base
operator|::
name|make_entry
argument_list|(
argument|void* p
argument_list|,
argument|size_t size
argument_list|)
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|p
argument_list|,
name|alloc_data_type
argument_list|(
name|_S_label
argument_list|,
name|size
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|void
name|throw_allocator_base
operator|::
name|init
argument_list|(
argument|unsigned long seed
argument_list|)
block|{
name|_S_g
operator|.
name|init
argument_list|(
name|seed
argument_list|)
block|; }
name|void
name|throw_allocator_base
operator|::
name|set_throw_prob
argument_list|(
argument|double throw_prob
argument_list|)
block|{
name|_S_throw_prob
operator|=
name|throw_prob
block|; }
name|double
name|throw_allocator_base
operator|::
name|get_throw_prob
argument_list|()
block|{
return|return
name|_S_throw_prob
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|void
name|throw_allocator_base
operator|::
name|set_label
argument_list|(
argument|size_t l
argument_list|)
block|{
name|_S_label
operator|=
name|l
block|; }
name|void
name|throw_allocator_base
operator|::
name|insert
argument_list|(
argument|void* p
argument_list|,
argument|size_t size
argument_list|)
block|{
name|const_iterator
name|found_it
operator|=
name|_S_map
operator|.
name|find
argument_list|(
name|p
argument_list|)
block|;
if|if
condition|(
name|found_it
operator|!=
name|_S_map
operator|.
name|end
argument_list|()
condition|)
block|{
name|std
operator|::
name|string
name|error
argument_list|(
literal|"throw_allocator_base::insert"
argument_list|)
expr_stmt|;
name|error
operator|+=
literal|"double insert!"
expr_stmt|;
name|error
operator|+=
literal|'\n'
expr_stmt|;
name|print_to_string
argument_list|(
name|error
argument_list|,
name|make_entry
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|print_to_string
argument_list|(
name|error
argument_list|,
operator|*
name|found_it
argument_list|)
expr_stmt|;
name|std
operator|::
name|__throw_logic_error
argument_list|(
name|error
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|_S_map
operator|.
name|insert
argument_list|(
name|make_entry
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    bool
name|throw_allocator_base
operator|::
name|empty
argument_list|()
block|{
return|return
name|_S_map
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|void
name|throw_allocator_base
operator|::
name|erase
argument_list|(
argument|void* p
argument_list|,
argument|size_t size
argument_list|)
block|{
name|check_allocated
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
block|;
name|_S_map
operator|.
name|erase
argument_list|(
name|p
argument_list|)
block|;   }
name|void
name|throw_allocator_base
operator|::
name|check_allocated
argument_list|(
argument|void* p
argument_list|,
argument|size_t size
argument_list|)
block|{
name|const_iterator
name|found_it
operator|=
name|_S_map
operator|.
name|find
argument_list|(
name|p
argument_list|)
block|;
if|if
condition|(
name|found_it
operator|==
name|_S_map
operator|.
name|end
argument_list|()
condition|)
block|{
name|std
operator|::
name|string
name|error
argument_list|(
literal|"throw_allocator_base::check_allocated by value "
argument_list|)
expr_stmt|;
name|error
operator|+=
literal|"null erase!"
expr_stmt|;
name|error
operator|+=
literal|'\n'
expr_stmt|;
name|print_to_string
argument_list|(
name|error
argument_list|,
name|make_entry
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|std
operator|::
name|__throw_logic_error
argument_list|(
name|error
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|found_it
operator|->
name|second
operator|.
name|second
operator|!=
name|size
condition|)
block|{
name|std
operator|::
name|string
name|error
argument_list|(
literal|"throw_allocator_base::check_allocated by value "
argument_list|)
expr_stmt|;
name|error
operator|+=
literal|"wrong-size erase!"
expr_stmt|;
name|error
operator|+=
literal|'\n'
expr_stmt|;
name|print_to_string
argument_list|(
name|error
argument_list|,
name|make_entry
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|print_to_string
argument_list|(
name|error
argument_list|,
operator|*
name|found_it
argument_list|)
expr_stmt|;
name|std
operator|::
name|__throw_logic_error
argument_list|(
name|error
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
unit|}    void
name|throw_allocator_base
operator|::
name|check_allocated
argument_list|(
argument|size_t label
argument_list|)
block|{
name|std
operator|::
name|string
name|found
block|;
name|const_iterator
name|it
operator|=
name|_S_map
operator|.
name|begin
argument_list|()
block|;
while|while
condition|(
name|it
operator|!=
name|_S_map
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|it
operator|->
name|second
operator|.
name|first
operator|==
name|label
condition|)
name|print_to_string
argument_list|(
name|found
argument_list|,
operator|*
name|it
argument_list|)
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|found
operator|.
name|empty
argument_list|()
condition|)
block|{
name|std
operator|::
name|string
name|error
argument_list|(
literal|"throw_allocator_base::check_allocated by label "
argument_list|)
expr_stmt|;
name|error
operator|+=
literal|'\n'
expr_stmt|;
name|error
operator|+=
name|found
expr_stmt|;
name|std
operator|::
name|__throw_logic_error
argument_list|(
name|error
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
unit|}    void
name|throw_allocator_base
operator|::
name|throw_conditionally
argument_list|()
block|{
if|if
condition|(
name|_S_g
operator|.
name|get_prob
argument_list|()
operator|<
name|_S_throw_prob
condition|)
name|__throw_forced_exception_error
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|void
name|throw_allocator_base
operator|::
name|print_to_string
argument_list|(
argument|std::string& s
argument_list|)
block|{
name|const_iterator
name|begin
operator|=
name|throw_allocator_base
operator|::
name|_S_map
operator|.
name|begin
argument_list|()
block|;
name|const_iterator
name|end
operator|=
name|throw_allocator_base
operator|::
name|_S_map
operator|.
name|end
argument_list|()
block|;
for|for
control|(
init|;
name|begin
operator|!=
name|end
condition|;
operator|++
name|begin
control|)
name|print_to_string
argument_list|(
name|s
argument_list|,
operator|*
name|begin
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|void
name|throw_allocator_base
operator|::
name|print_to_string
argument_list|(
argument|std::string& s
argument_list|,
argument|const_reference ref
argument_list|)
block|{
name|char
name|buf
index|[
literal|40
index|]
block|;
specifier|const
name|char
name|tab
argument_list|(
literal|'\t'
argument_list|)
block|;
name|s
operator|+=
literal|"address: "
block|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%p"
argument_list|,
name|ref
operator|.
name|first
argument_list|)
block|;
name|s
operator|+=
name|buf
block|;
name|s
operator|+=
name|tab
block|;
name|s
operator|+=
literal|"label: "
block|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%lu"
argument_list|,
name|ref
operator|.
name|second
operator|.
name|first
argument_list|)
block|;
name|s
operator|+=
name|buf
block|;
name|s
operator|+=
name|tab
block|;
name|s
operator|+=
literal|"size: "
block|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%lu"
argument_list|,
name|ref
operator|.
name|second
operator|.
name|second
argument_list|)
block|;
name|s
operator|+=
name|buf
block|;
name|s
operator|+=
literal|'\n'
block|;   }
name|_GLIBCXX_END_NAMESPACE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

