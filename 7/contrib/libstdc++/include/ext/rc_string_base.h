begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Reference-counted versatile string base -*- C++ -*-
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
comment|/** @file ext/rc_string_base.h  *  This file is a GNU extension to the Standard C++ Library.  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RC_STRING_BASE_H
end_ifndef

begin_define
define|#
directive|define
name|_RC_STRING_BASE_H
value|1
end_define

begin_include
include|#
directive|include
file|<ext/atomicity.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_comment
comment|/**    *  @if maint    *  Documentation?  What's that?    *  Nathan Myers<ncm@cantrip.org>.    *    *  A string looks like this:    *    *  @code    *                                        [_Rep]    *                                        _M_length    *   [__rc_string_base<char_type>]        _M_capacity    *   _M_dataplus                          _M_refcount    *   _M_p ---------------->               unnamed array of char_type    *  @endcode    *    *  Where the _M_p points to the first character in the string, and    *  you cast it to a pointer-to-_Rep and subtract 1 to get a    *  pointer to the header.    *    *  This approach has the enormous advantage that a string object    *  requires only one allocation.  All the ugliness is confined    *  within a single pair of inline functions, which each compile to    *  a single "add" instruction: _Rep::_M_refdata(), and    *  __rc_string_base::_M_rep(); and the allocation function which gets a    *  block of raw bytes and with room enough and constructs a _Rep    *  object at the front.    *    *  The reason you want _M_data pointing to the character array and    *  not the _Rep is so that the debugger can see the string    *  contents. (Probably we should add a non-inline member to get    *  the _Rep for the debugger to use, so users can check the actual    *  string length.)    *    *  Note that the _Rep object is a POD so that you can have a    *  static "empty string" _Rep object already "constructed" before    *  static constructors have run.  The reference-count encoding is    *  chosen so that a 0 indicates one reference, so you never try to    *  destroy the empty-string _Rep object.    *    *  All but the last paragraph is considered pretty conventional    *  for a C++ string implementation.    *  @endif   */
end_comment

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
name|class
name|__rc_string_base
operator|:
name|protected
name|__vstring_utility
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_Traits
name|traits_type
typedef|;
end_expr_stmt

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
name|_Alloc
name|allocator_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__vstring_utility
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|_Util_Base
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Util_Base
operator|::
name|_CharT_alloc_type
name|_CharT_alloc_type
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

begin_label
name|private
label|:
end_label

begin_comment
comment|// _Rep: string representation
end_comment

begin_comment
comment|//   Invariants:
end_comment

begin_comment
comment|//   1. String really contains _M_length + 1 characters: due to 21.3.4
end_comment

begin_comment
comment|//      must be kept null-terminated.
end_comment

begin_comment
comment|//   2. _M_capacity>= _M_length
end_comment

begin_comment
comment|//      Allocated memory is always (_M_capacity + 1) * sizeof(_CharT).
end_comment

begin_comment
comment|//   3. _M_refcount has three states:
end_comment

begin_comment
comment|//      -1: leaked, one reference, no ref-copies allowed, non-const.
end_comment

begin_comment
comment|//       0: one reference, non-const.
end_comment

begin_comment
comment|//     n>0: n + 1 references, operations require a lock, const.
end_comment

begin_comment
comment|//   4. All fields == 0 is an empty string, given the extra storage
end_comment

begin_comment
comment|//      beyond-the-end for a null terminator; thus, the shared
end_comment

begin_comment
comment|//      empty string representation needs no constructor.
end_comment

begin_struct
struct|struct
name|_Rep
block|{
union|union
block|{
struct|struct
block|{
name|size_type
name|_M_length
decl_stmt|;
name|size_type
name|_M_capacity
decl_stmt|;
name|_Atomic_word
name|_M_refcount
decl_stmt|;
block|}
name|_M_info
struct|;
comment|// Only for alignment purposes.
name|_CharT
name|_M_align
decl_stmt|;
block|}
union|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|template
name|rebind
operator|<
name|_Rep
operator|>
operator|::
name|other
name|_Rep_alloc_type
expr_stmt|;
name|_CharT
modifier|*
name|_M_refdata
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|_CharT
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|_CharT
modifier|*
name|_M_refcopy
parameter_list|()
function|throw
parameter_list|()
block|{
name|__atomic_add_dispatch
argument_list|(
operator|&
name|_M_info
operator|.
name|_M_refcount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|_M_refdata
argument_list|()
return|;
block|}
comment|// XXX MT
name|void
name|_M_set_length
parameter_list|(
name|size_type
name|__n
parameter_list|)
block|{
name|_M_info
operator|.
name|_M_refcount
operator|=
literal|0
expr_stmt|;
comment|// One reference.
name|_M_info
operator|.
name|_M_length
operator|=
name|__n
expr_stmt|;
comment|// grrr. (per 21.3.4)
comment|// You cannot leave those LWG people alone for a second.
name|traits_type
operator|::
name|assign
argument_list|(
name|_M_refdata
argument_list|()
index|[
name|__n
index|]
argument_list|,
name|_CharT
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Create& Destroy
specifier|static
name|_Rep
modifier|*
name|_S_create
parameter_list|(
name|size_type
parameter_list|,
name|size_type
parameter_list|,
specifier|const
name|_Alloc
modifier|&
parameter_list|)
function_decl|;
name|void
name|_M_destroy
parameter_list|(
specifier|const
name|_Alloc
modifier|&
parameter_list|)
function_decl|throw
parameter_list|()
function_decl|;
name|_CharT
modifier|*
name|_M_clone
parameter_list|(
specifier|const
name|_Alloc
modifier|&
parameter_list|,
name|size_type
name|__res
init|=
literal|0
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|_Rep_empty
range|:
name|public
name|_Rep
block|{
name|_CharT
name|_M_terminal
block|;       }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|_Rep_empty
name|_S_empty_rep
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The maximum number of individual char_type elements of an
end_comment

begin_comment
comment|// individual string is determined by _S_max_size. This is the
end_comment

begin_comment
comment|// value that will be returned by max_size().  (Whereas npos
end_comment

begin_comment
comment|// is the maximum number of bytes the allocator can allocate.)
end_comment

begin_comment
comment|// If one was to divvy up the theoretical largest size string,
end_comment

begin_comment
comment|// with a terminating character and m _CharT elements, it'd
end_comment

begin_comment
comment|// look like this:
end_comment

begin_comment
comment|// npos = sizeof(_Rep) + (m * sizeof(_CharT)) + sizeof(_CharT)
end_comment

begin_comment
comment|//        + sizeof(_Rep) - 1
end_comment

begin_comment
comment|// (NB: last two terms for rounding reasons, see _M_create below)
end_comment

begin_comment
comment|// Solving for m:
end_comment

begin_comment
comment|// m = ((npos - 2 * sizeof(_Rep) + 1) / sizeof(_CharT)) - 1
end_comment

begin_comment
comment|// In addition, this implementation halfs this amount.
end_comment

begin_enum
enum|enum
block|{
name|_S_max_size
init|=
operator|(
operator|(
operator|(
name|static_cast
operator|<
name|size_type
operator|>
operator|(
operator|-
literal|1
operator|)
operator|-
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|_Rep
argument_list|)
operator|+
literal|1
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|_CharT
argument_list|)
operator|)
operator|-
literal|1
operator|)
operator|/
literal|2
block|}
enum|;
end_enum

begin_comment
comment|// Data Member (private):
end_comment

begin_expr_stmt
name|mutable
name|typename
name|_Util_Base
operator|::
name|template
name|_Alloc_hider
operator|<
name|_Alloc
operator|>
name|_M_dataplus
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|_M_data
parameter_list|(
name|_CharT
modifier|*
name|__p
parameter_list|)
block|{
name|_M_dataplus
operator|.
name|_M_p
operator|=
name|__p
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|_Rep
operator|*
name|_M_rep
argument_list|()
specifier|const
block|{
return|return
operator|&
operator|(
operator|(
name|reinterpret_cast
operator|<
name|_Rep
operator|*
operator|>
operator|(
name|_M_data
argument_list|()
operator|)
operator|)
index|[
operator|-
literal|1
index|]
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|_CharT
modifier|*
name|_M_grab
argument_list|(
specifier|const
name|_Alloc
operator|&
name|__alloc
argument_list|)
decl|const
block|{
return|return
operator|(
operator|!
name|_M_is_leaked
argument_list|()
operator|&&
name|_M_get_allocator
argument_list|()
operator|==
name|__alloc
operator|)
condition|?
name|_M_rep
argument_list|()
operator|->
name|_M_refcopy
argument_list|()
else|:
name|_M_rep
argument_list|()
operator|->
name|_M_clone
argument_list|(
name|__alloc
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|void
name|_M_dispose
parameter_list|()
block|{
if|if
condition|(
name|__exchange_and_add_dispatch
argument_list|(
operator|&
name|_M_rep
argument_list|()
operator|->
name|_M_info
operator|.
name|_M_refcount
argument_list|,
operator|-
literal|1
argument_list|)
operator|<=
literal|0
condition|)
name|_M_rep
argument_list|()
operator|->
name|_M_destroy
argument_list|(
name|_M_get_allocator
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// XXX MT
end_comment

begin_expr_stmt
name|bool
name|_M_is_leaked
argument_list|()
specifier|const
block|{
return|return
name|_M_rep
argument_list|()
operator|->
name|_M_info
operator|.
name|_M_refcount
operator|<
literal|0
return|;
block|}
end_expr_stmt

begin_function
name|void
name|_M_set_sharable
parameter_list|()
block|{
name|_M_rep
argument_list|()
operator|->
name|_M_info
operator|.
name|_M_refcount
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|_M_leak_hard
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// _S_construct_aux is used to implement the 21.3.1 para 15 which
end_comment

begin_comment
comment|// requires special behaviour if _InIterator is an integral type
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InIterator
operator|>
specifier|static
name|_CharT
operator|*
name|_S_construct_aux
argument_list|(
argument|_InIterator __beg
argument_list|,
argument|_InIterator __end
argument_list|,
argument|const _Alloc& __a
argument_list|,
argument|std::__false_type
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InIterator
operator|>
operator|::
name|iterator_category
name|_Tag
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|_S_construct
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__a
argument_list|,
name|_Tag
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}        template
operator|<
name|typename
name|_InIterator
operator|>
specifier|static
name|_CharT
operator|*
name|_S_construct_aux
argument_list|(
argument|_InIterator __beg
argument_list|,
argument|_InIterator __end
argument_list|,
argument|const _Alloc& __a
argument_list|,
argument|std::__true_type
argument_list|)
block|{
return|return
name|_S_construct
argument_list|(
name|static_cast
operator|<
name|size_type
operator|>
operator|(
name|__beg
operator|)
argument_list|,
name|static_cast
operator|<
name|value_type
operator|>
operator|(
name|__end
operator|)
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_InIterator
operator|>
specifier|static
name|_CharT
operator|*
name|_S_construct
argument_list|(
argument|_InIterator __beg
argument_list|,
argument|_InIterator __end
argument_list|,
argument|const _Alloc& __a
argument_list|)
block|{
typedef|typedef
name|typename
name|std
operator|::
name|__is_integer
operator|<
name|_InIterator
operator|>
operator|::
name|__type
name|_Integral
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|_S_construct_aux
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__a
argument_list|,
name|_Integral
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|// For Input Iterators, used in istreambuf_iterators, etc.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InIterator
operator|>
specifier|static
name|_CharT
operator|*
name|_S_construct
argument_list|(
argument|_InIterator __beg
argument_list|,
argument|_InIterator __end
argument_list|,
argument|const _Alloc& __a
argument_list|,
argument|std::input_iterator_tag
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// For forward_iterators up to random_access_iterators, used for
end_comment

begin_comment
comment|// string::iterator, _CharT*, etc.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_FwdIterator
operator|>
specifier|static
name|_CharT
operator|*
name|_S_construct
argument_list|(
argument|_FwdIterator __beg
argument_list|,
argument|_FwdIterator __end
argument_list|,
argument|const _Alloc& __a
argument_list|,
argument|std::forward_iterator_tag
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|_CharT
modifier|*
name|_S_construct
parameter_list|(
name|size_type
name|__req
parameter_list|,
name|_CharT
name|__c
parameter_list|,
specifier|const
name|_Alloc
modifier|&
name|__a
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|size_type
name|_M_max_size
argument_list|()
specifier|const
block|{
return|return
name|size_type
argument_list|(
name|_S_max_size
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_CharT
operator|*
name|_M_data
argument_list|()
specifier|const
block|{
return|return
name|_M_dataplus
operator|.
name|_M_p
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|size_type
name|_M_length
argument_list|()
specifier|const
block|{
return|return
name|_M_rep
argument_list|()
operator|->
name|_M_info
operator|.
name|_M_length
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|size_type
name|_M_capacity
argument_list|()
specifier|const
block|{
return|return
name|_M_rep
argument_list|()
operator|->
name|_M_info
operator|.
name|_M_capacity
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|_M_is_shared
argument_list|()
specifier|const
block|{
return|return
name|_M_rep
argument_list|()
operator|->
name|_M_info
operator|.
name|_M_refcount
operator|>
literal|0
return|;
block|}
end_expr_stmt

begin_function
name|void
name|_M_set_leaked
parameter_list|()
block|{
name|_M_rep
argument_list|()
operator|->
name|_M_info
operator|.
name|_M_refcount
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_M_leak
parameter_list|()
comment|// for use in begin()& non-const op[]
block|{
if|if
condition|(
operator|!
name|_M_is_leaked
argument_list|()
condition|)
name|_M_leak_hard
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_M_set_length
parameter_list|(
name|size_type
name|__n
parameter_list|)
block|{
name|_M_rep
argument_list|()
operator|->
name|_M_set_length
argument_list|(
name|__n
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|__rc_string_base
argument_list|()
operator|:
name|_M_dataplus
argument_list|(
argument|_Alloc()
argument_list|,
argument|_S_empty_rep._M_refcopy()
argument_list|)
block|{ }
name|__rc_string_base
argument_list|(
specifier|const
name|_Alloc
operator|&
name|__a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__rc_string_base
argument_list|(
specifier|const
name|__rc_string_base
operator|&
name|__rcs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|__rc_string_base
argument_list|(
argument|size_type __n
argument_list|,
argument|_CharT __c
argument_list|,
argument|const _Alloc& __a
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|__rc_string_base
argument_list|(
argument|_InputIterator __beg
argument_list|,
argument|_InputIterator __end
argument_list|,
argument|const _Alloc& __a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|~
name|__rc_string_base
argument_list|()
block|{
name|_M_dispose
argument_list|()
block|; }
name|allocator_type
operator|&
name|_M_get_allocator
argument_list|()
block|{
return|return
name|_M_dataplus
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|allocator_type
operator|&
name|_M_get_allocator
argument_list|()
specifier|const
block|{
return|return
name|_M_dataplus
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|_M_swap
parameter_list|(
name|__rc_string_base
modifier|&
name|__rcs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_M_assign
parameter_list|(
specifier|const
name|__rc_string_base
modifier|&
name|__rcs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_M_reserve
parameter_list|(
name|size_type
name|__res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_M_mutate
parameter_list|(
name|size_type
name|__pos
parameter_list|,
name|size_type
name|__len1
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|,
name|size_type
name|__len2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_M_erase
parameter_list|(
name|size_type
name|__pos
parameter_list|,
name|size_type
name|__n
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_M_clear
parameter_list|()
block|{
name|_M_erase
argument_list|(
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|,
name|_M_length
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|bool
name|_M_compare
argument_list|(
specifier|const
name|__rc_string_base
operator|&
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_expr_stmt
unit|};
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
name|typename
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_Rep_empty
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_S_empty_rep
expr_stmt|;
end_expr_stmt

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
name|typename
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_Rep
operator|*
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_Rep
operator|::
name|_S_create
argument_list|(
argument|size_type __capacity
argument_list|,
argument|size_type __old_capacity
argument_list|,
argument|const _Alloc& __alloc
argument_list|)
block|{
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 83.  String::npos vs. string::max_size()
if|if
condition|(
name|__capacity
operator|>
name|size_type
argument_list|(
name|_S_max_size
argument_list|)
condition|)
name|std
operator|::
name|__throw_length_error
argument_list|(
name|__N
argument_list|(
literal|"__rc_string_base::_Rep::_S_create"
argument_list|)
argument_list|)
expr_stmt|;
comment|// The standard places no restriction on allocating more memory
comment|// than is strictly needed within this layer at the moment or as
comment|// requested by an explicit application call to reserve().
comment|// Many malloc implementations perform quite poorly when an
comment|// application attempts to allocate memory in a stepwise fashion
comment|// growing each allocation size by only 1 char.  Additionally,
comment|// it makes little sense to allocate less linear memory than the
comment|// natural blocking size of the malloc implementation.
comment|// Unfortunately, we would need a somewhat low-level calculation
comment|// with tuned parameters to get this perfect for any particular
comment|// malloc implementation.  Fortunately, generalizations about
comment|// common features seen among implementations seems to suffice.
comment|// __pagesize need not match the actual VM page size for good
comment|// results in practice, thus we pick a common value on the low
comment|// side.  __malloc_header_size is an estimate of the amount of
comment|// overhead per memory allocation (in practice seen N * sizeof
comment|// (void*) where N is 0, 2 or 4).  According to folklore,
comment|// picking this value on the high side is better than
comment|// low-balling it (especially when this algorithm is used with
comment|// malloc implementations that allocate memory blocks rounded up
comment|// to a size which is a power of 2).
specifier|const
name|size_type
name|__pagesize
operator|=
literal|4096
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|size_type
name|__malloc_header_size
init|=
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The below implements an exponential growth policy, necessary to
end_comment

begin_comment
comment|// meet amortized linear time requirements of the library: see
end_comment

begin_comment
comment|// http://gcc.gnu.org/ml/libstdc++/2001-07/msg00085.html.
end_comment

begin_if
if|if
condition|(
name|__capacity
operator|>
name|__old_capacity
operator|&&
name|__capacity
operator|<
literal|2
operator|*
name|__old_capacity
condition|)
block|{
name|__capacity
operator|=
literal|2
operator|*
name|__old_capacity
expr_stmt|;
comment|// Never allocate a string bigger than _S_max_size.
if|if
condition|(
name|__capacity
operator|>
name|size_type
argument_list|(
name|_S_max_size
argument_list|)
condition|)
name|__capacity
operator|=
name|size_type
argument_list|(
name|_S_max_size
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|// NB: Need an array of char_type[__capacity], plus a terminating
end_comment

begin_comment
comment|// null char_type() element, plus enough for the _Rep data structure,
end_comment

begin_comment
comment|// plus sizeof(_Rep) - 1 to upper round to a size multiple of
end_comment

begin_comment
comment|// sizeof(_Rep).
end_comment

begin_comment
comment|// Whew. Seemingly so needy, yet so elemental.
end_comment

begin_decl_stmt
name|size_type
name|__size
init|=
operator|(
operator|(
name|__capacity
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|_CharT
argument_list|)
operator|+
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|_Rep
argument_list|)
operator|-
literal|1
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|size_type
name|__adj_size
init|=
name|__size
operator|+
name|__malloc_header_size
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|__adj_size
operator|>
name|__pagesize
operator|&&
name|__capacity
operator|>
name|__old_capacity
condition|)
block|{
specifier|const
name|size_type
name|__extra
init|=
name|__pagesize
operator|-
name|__adj_size
operator|%
name|__pagesize
decl_stmt|;
name|__capacity
operator|+=
name|__extra
operator|/
sizeof|sizeof
argument_list|(
name|_CharT
argument_list|)
expr_stmt|;
if|if
condition|(
name|__capacity
operator|>
name|size_type
argument_list|(
name|_S_max_size
argument_list|)
condition|)
name|__capacity
operator|=
name|size_type
argument_list|(
name|_S_max_size
argument_list|)
expr_stmt|;
name|__size
operator|=
operator|(
name|__capacity
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|_CharT
argument_list|)
operator|+
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|_Rep
argument_list|)
operator|-
literal|1
expr_stmt|;
block|}
end_if

begin_comment
comment|// NB: Might throw, but no worries about a leak, mate: _Rep()
end_comment

begin_comment
comment|// does not throw.
end_comment

begin_decl_stmt
name|_Rep
modifier|*
name|__place
init|=
name|_Rep_alloc_type
argument_list|(
name|__alloc
argument_list|)
operator|.
name|allocate
argument_list|(
name|__size
operator|/
sizeof|sizeof
argument_list|(
name|_Rep
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_Rep
modifier|*
name|__p
init|=
name|new
argument_list|(
argument|__place
argument_list|)
name|_Rep
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|__p
operator|->
name|_M_info
operator|.
name|_M_capacity
operator|=
name|__capacity
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__p
return|;
end_return

begin_expr_stmt
unit|}    template
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
name|void
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_Rep
operator|::
name|_M_destroy
argument_list|(
argument|const _Alloc& __a
argument_list|)
name|throw
argument_list|()
block|{
specifier|const
name|size_type
name|__size
operator|=
operator|(
operator|(
name|_M_info
operator|.
name|_M_capacity
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|_CharT
argument_list|)
operator|+
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|_Rep
argument_list|)
operator|-
literal|1
operator|)
block|;
name|_Rep_alloc_type
argument_list|(
name|__a
argument_list|)
operator|.
name|deallocate
argument_list|(
name|this
argument_list|,
name|__size
operator|/
sizeof|sizeof
argument_list|(
name|_Rep
argument_list|)
argument_list|)
block|;     }
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
name|_CharT
operator|*
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_Rep
operator|::
name|_M_clone
argument_list|(
argument|const _Alloc& __alloc
argument_list|,
argument|size_type __res
argument_list|)
block|{
comment|// Requested capacity of the clone.
specifier|const
name|size_type
name|__requested_cap
operator|=
name|_M_info
operator|.
name|_M_length
operator|+
name|__res
block|;
name|_Rep
operator|*
name|__r
operator|=
name|_Rep
operator|::
name|_S_create
argument_list|(
name|__requested_cap
argument_list|,
name|_M_info
operator|.
name|_M_capacity
argument_list|,
name|__alloc
argument_list|)
block|;
if|if
condition|(
name|_M_info
operator|.
name|_M_length
condition|)
name|_S_copy
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
argument_list|,
name|_M_refdata
argument_list|()
argument_list|,
name|_M_info
operator|.
name|_M_length
argument_list|)
expr_stmt|;
name|__r
operator|->
name|_M_set_length
argument_list|(
name|_M_info
operator|.
name|_M_length
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__r
operator|->
name|_M_refdata
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    template
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
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|__rc_string_base
argument_list|(
specifier|const
name|_Alloc
operator|&
name|__a
argument_list|)
operator|:
name|_M_dataplus
argument_list|(
argument|__a
argument_list|,
argument|_S_construct(size_type(), _CharT(), __a)
argument_list|)
block|{ }
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
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|__rc_string_base
argument_list|(
specifier|const
name|__rc_string_base
operator|&
name|__rcs
argument_list|)
operator|:
name|_M_dataplus
argument_list|(
argument|__rcs._M_get_allocator()
argument_list|,
argument|__rcs._M_grab(__rcs._M_get_allocator())
argument_list|)
block|{ }
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
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|__rc_string_base
argument_list|(
argument|size_type __n
argument_list|,
argument|_CharT __c
argument_list|,
argument|const _Alloc& __a
argument_list|)
operator|:
name|_M_dataplus
argument_list|(
argument|__a
argument_list|,
argument|_S_construct(__n, __c, __a)
argument_list|)
block|{ }
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
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|__rc_string_base
argument_list|(
argument|_InputIterator __beg
argument_list|,
argument|_InputIterator __end
argument_list|,
argument|const _Alloc& __a
argument_list|)
operator|:
name|_M_dataplus
argument_list|(
argument|__a
argument_list|,
argument|_S_construct(__beg, __end, __a)
argument_list|)
block|{ }
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
name|void
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_M_leak_hard
argument_list|()
block|{
if|if
condition|(
name|_M_is_shared
argument_list|()
condition|)
name|_M_erase
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_M_set_leaked
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// NB: This is the special case for Input Iterators, used in
end_comment

begin_comment
comment|// istreambuf_iterators, etc.
end_comment

begin_comment
comment|// Input Iterators have a cost structure very different from
end_comment

begin_comment
comment|// pointers, calling for a different coding style.
end_comment

begin_expr_stmt
unit|template
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
name|template
operator|<
name|typename
name|_InIterator
operator|>
name|_CharT
operator|*
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_S_construct
argument_list|(
argument|_InIterator __beg
argument_list|,
argument|_InIterator __end
argument_list|,
argument|const _Alloc& __a
argument_list|,
argument|std::input_iterator_tag
argument_list|)
block|{
if|if
condition|(
name|__beg
operator|==
name|__end
operator|&&
name|__a
operator|==
name|_Alloc
argument_list|()
condition|)
return|return
name|_S_empty_rep
operator|.
name|_M_refcopy
argument_list|()
return|;
comment|// Avoid reallocation for common case.
name|_CharT
name|__buf
index|[
literal|128
index|]
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|size_type
name|__len
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
name|__beg
operator|!=
name|__end
operator|&&
name|__len
operator|<
sizeof|sizeof
argument_list|(
name|__buf
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|_CharT
argument_list|)
condition|)
block|{
name|__buf
index|[
name|__len
operator|++
index|]
operator|=
operator|*
name|__beg
expr_stmt|;
operator|++
name|__beg
expr_stmt|;
block|}
end_while

begin_decl_stmt
name|_Rep
modifier|*
name|__r
init|=
name|_Rep
operator|::
name|_S_create
argument_list|(
name|__len
argument_list|,
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|,
name|__a
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|_S_copy
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
argument_list|,
name|__buf
argument_list|,
name|__len
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|try
end_macro

begin_block
block|{
while|while
condition|(
name|__beg
operator|!=
name|__end
condition|)
block|{
if|if
condition|(
name|__len
operator|==
name|__r
operator|->
name|_M_info
operator|.
name|_M_capacity
condition|)
block|{
comment|// Allocate more space.
name|_Rep
modifier|*
name|__another
init|=
name|_Rep
operator|::
name|_S_create
argument_list|(
name|__len
operator|+
literal|1
argument_list|,
name|__len
argument_list|,
name|__a
argument_list|)
decl_stmt|;
name|_S_copy
argument_list|(
name|__another
operator|->
name|_M_refdata
argument_list|()
argument_list|,
name|__r
operator|->
name|_M_refdata
argument_list|()
argument_list|,
name|__len
argument_list|)
expr_stmt|;
name|__r
operator|->
name|_M_destroy
argument_list|(
name|__a
argument_list|)
expr_stmt|;
name|__r
operator|=
name|__another
expr_stmt|;
block|}
name|__r
operator|->
name|_M_refdata
argument_list|()
index|[
name|__len
operator|++
index|]
operator|=
operator|*
name|__beg
expr_stmt|;
operator|++
name|__beg
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|catch
argument_list|(
argument|...
argument_list|)
end_macro

begin_block
block|{
name|__r
operator|->
name|_M_destroy
argument_list|(
name|__a
argument_list|)
expr_stmt|;
name|__throw_exception_again
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|__r
operator|->
name|_M_set_length
argument_list|(
name|__len
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__r
operator|->
name|_M_refdata
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    template
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
name|template
operator|<
name|typename
name|_InIterator
operator|>
name|_CharT
operator|*
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_S_construct
argument_list|(
argument|_InIterator __beg
argument_list|,
argument|_InIterator __end
argument_list|,
argument|const _Alloc& __a
argument_list|,
argument|std::forward_iterator_tag
argument_list|)
block|{
if|if
condition|(
name|__beg
operator|==
name|__end
operator|&&
name|__a
operator|==
name|_Alloc
argument_list|()
condition|)
return|return
name|_S_empty_rep
operator|.
name|_M_refcopy
argument_list|()
return|;
end_expr_stmt

begin_comment
comment|// NB: Not required, but considered best practice.
end_comment

begin_if
if|if
condition|(
name|__builtin_expect
argument_list|(
name|_S_is_null_pointer
argument_list|(
name|__beg
argument_list|)
operator|&&
name|__beg
operator|!=
name|__end
argument_list|,
literal|0
argument_list|)
condition|)
name|std
operator|::
name|__throw_logic_error
argument_list|(
name|__N
argument_list|(
literal|"__rc_string_base::"
literal|"_S_construct NULL not valid"
argument_list|)
argument_list|)
expr_stmt|;
end_if

begin_decl_stmt
specifier|const
name|size_type
name|__dnew
init|=
name|static_cast
operator|<
name|size_type
operator|>
operator|(
name|std
operator|::
name|distance
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Check for out_of_range and length_error exceptions.
end_comment

begin_decl_stmt
name|_Rep
modifier|*
name|__r
init|=
name|_Rep
operator|::
name|_S_create
argument_list|(
name|__dnew
argument_list|,
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|,
name|__a
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|try
end_macro

begin_block
block|{
name|_S_copy_chars
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
argument_list|,
name|__beg
argument_list|,
name|__end
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|catch
argument_list|(
argument|...
argument_list|)
end_macro

begin_block
block|{
name|__r
operator|->
name|_M_destroy
argument_list|(
name|__a
argument_list|)
expr_stmt|;
name|__throw_exception_again
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|__r
operator|->
name|_M_set_length
argument_list|(
name|__dnew
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__r
operator|->
name|_M_refdata
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    template
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
name|_CharT
operator|*
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_S_construct
argument_list|(
argument|size_type __n
argument_list|,
argument|_CharT __c
argument_list|,
argument|const _Alloc& __a
argument_list|)
block|{
if|if
condition|(
name|__n
operator|==
literal|0
operator|&&
name|__a
operator|==
name|_Alloc
argument_list|()
condition|)
return|return
name|_S_empty_rep
operator|.
name|_M_refcopy
argument_list|()
return|;
comment|// Check for out_of_range and length_error exceptions.
name|_Rep
operator|*
name|__r
operator|=
name|_Rep
operator|::
name|_S_create
argument_list|(
name|__n
argument_list|,
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|,
name|__a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__n
condition|)
name|_S_assign
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
argument_list|,
name|__n
argument_list|,
name|__c
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|__r
operator|->
name|_M_set_length
argument_list|(
name|__n
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__r
operator|->
name|_M_refdata
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    template
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
name|void
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_M_swap
argument_list|(
argument|__rc_string_base& __rcs
argument_list|)
block|{
if|if
condition|(
name|_M_is_leaked
argument_list|()
condition|)
name|_M_set_sharable
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__rcs
operator|.
name|_M_is_leaked
argument_list|()
condition|)
name|__rcs
operator|.
name|_M_set_sharable
argument_list|()
expr_stmt|;
end_if

begin_decl_stmt
name|_CharT
modifier|*
name|__tmp
init|=
name|_M_data
argument_list|()
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|_M_data
argument_list|(
name|__rcs
operator|.
name|_M_data
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__rcs
operator|.
name|_M_data
argument_list|(
name|__tmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 431. Swapping containers with unequal allocators.
end_comment

begin_expr_stmt
name|std
operator|::
name|__alloc_swap
operator|<
name|allocator_type
operator|>
operator|::
name|_S_do_it
argument_list|(
name|_M_get_allocator
argument_list|()
argument_list|,
name|__rcs
operator|.
name|_M_get_allocator
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}     template
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
name|void
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_M_assign
argument_list|(
argument|const __rc_string_base& __rcs
argument_list|)
block|{
if|if
condition|(
name|_M_rep
argument_list|()
operator|!=
name|__rcs
operator|.
name|_M_rep
argument_list|()
condition|)
block|{
name|_CharT
modifier|*
name|__tmp
init|=
name|__rcs
operator|.
name|_M_grab
argument_list|(
name|_M_get_allocator
argument_list|()
argument_list|)
decl_stmt|;
name|_M_dispose
argument_list|()
expr_stmt|;
name|_M_data
argument_list|(
name|__tmp
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}    template
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
name|void
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_M_reserve
argument_list|(
argument|size_type __res
argument_list|)
block|{
comment|// Make sure we don't shrink below the current size.
if|if
condition|(
name|__res
operator|<
name|_M_length
argument_list|()
condition|)
name|__res
operator|=
name|_M_length
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__res
operator|!=
name|_M_capacity
argument_list|()
operator|||
name|_M_is_shared
argument_list|()
condition|)
block|{
name|_CharT
modifier|*
name|__tmp
init|=
name|_M_rep
argument_list|()
operator|->
name|_M_clone
argument_list|(
name|_M_get_allocator
argument_list|()
argument_list|,
name|__res
operator|-
name|_M_length
argument_list|()
argument_list|)
decl_stmt|;
name|_M_dispose
argument_list|()
expr_stmt|;
name|_M_data
argument_list|(
name|__tmp
argument_list|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
unit|}    template
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
name|void
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_M_mutate
argument_list|(
argument|size_type __pos
argument_list|,
argument|size_type __len1
argument_list|,
argument|const _CharT* __s
argument_list|,
argument|size_type __len2
argument_list|)
block|{
specifier|const
name|size_type
name|__how_much
operator|=
name|_M_length
argument_list|()
operator|-
name|__pos
operator|-
name|__len1
block|;
name|_Rep
operator|*
name|__r
operator|=
name|_Rep
operator|::
name|_S_create
argument_list|(
name|_M_length
argument_list|()
operator|+
name|__len2
operator|-
name|__len1
argument_list|,
name|_M_capacity
argument_list|()
argument_list|,
name|_M_get_allocator
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|__pos
condition|)
name|_S_copy
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
argument_list|,
name|_M_data
argument_list|()
argument_list|,
name|__pos
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__s
operator|&&
name|__len2
condition|)
name|_S_copy
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
operator|+
name|__pos
argument_list|,
name|__s
argument_list|,
name|__len2
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|__how_much
condition|)
name|_S_copy
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
operator|+
name|__pos
operator|+
name|__len2
argument_list|,
name|_M_data
argument_list|()
operator|+
name|__pos
operator|+
name|__len1
argument_list|,
name|__how_much
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|_M_dispose
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_M_data
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
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
name|void
name|__rc_string_base
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|_M_erase
argument_list|(
argument|size_type __pos
argument_list|,
argument|size_type __n
argument_list|)
block|{
specifier|const
name|size_type
name|__new_size
operator|=
name|_M_length
argument_list|()
operator|-
name|__n
block|;
specifier|const
name|size_type
name|__how_much
operator|=
name|_M_length
argument_list|()
operator|-
name|__pos
operator|-
name|__n
block|;
if|if
condition|(
name|_M_is_shared
argument_list|()
condition|)
block|{
comment|// Must reallocate.
name|_Rep
modifier|*
name|__r
init|=
name|_Rep
operator|::
name|_S_create
argument_list|(
name|__new_size
argument_list|,
name|_M_capacity
argument_list|()
argument_list|,
name|_M_get_allocator
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|__pos
condition|)
name|_S_copy
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
argument_list|,
name|_M_data
argument_list|()
argument_list|,
name|__pos
argument_list|)
expr_stmt|;
if|if
condition|(
name|__how_much
condition|)
name|_S_copy
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
operator|+
name|__pos
argument_list|,
name|_M_data
argument_list|()
operator|+
name|__pos
operator|+
name|__n
argument_list|,
name|__how_much
argument_list|)
expr_stmt|;
name|_M_dispose
argument_list|()
expr_stmt|;
name|_M_data
argument_list|(
name|__r
operator|->
name|_M_refdata
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|__how_much
operator|&&
name|__n
condition|)
block|{
comment|// Work in-place.
name|_S_move
argument_list|(
name|_M_data
argument_list|()
operator|+
name|__pos
argument_list|,
name|_M_data
argument_list|()
operator|+
name|__pos
operator|+
name|__n
argument_list|,
name|__how_much
argument_list|)
expr_stmt|;
block|}
end_elseif

begin_expr_stmt
name|_M_rep
argument_list|()
operator|->
name|_M_set_length
argument_list|(
name|__new_size
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
operator|>
specifier|inline
name|bool
name|__rc_string_base
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
name|std
operator|::
name|allocator
operator|<
name|char
operator|>
expr|>
operator|::
name|_M_compare
argument_list|(
argument|const __rc_string_base& __rcs
argument_list|)
specifier|const
block|{
if|if
condition|(
name|_M_rep
argument_list|()
operator|==
name|__rcs
operator|.
name|_M_rep
argument_list|()
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
unit|template
operator|<
operator|>
specifier|inline
name|bool
name|__rc_string_base
operator|<
name|wchar_t
operator|,
name|std
operator|::
name|char_traits
operator|<
name|wchar_t
operator|>
operator|,
name|std
operator|::
name|allocator
operator|<
name|wchar_t
operator|>
expr|>
operator|::
name|_M_compare
argument_list|(
argument|const __rc_string_base& __rcs
argument_list|)
specifier|const
block|{
if|if
condition|(
name|_M_rep
argument_list|()
operator|==
name|__rcs
operator|.
name|_M_rep
argument_list|()
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
unit|_GLIBCXX_END_NAMESPACE
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RC_STRING_BASE_H */
end_comment

end_unit

