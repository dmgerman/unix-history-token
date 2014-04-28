begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Components for manipulating sequences of characters -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005,
end_comment

begin_comment
comment|// 2006, 2007
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
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
comment|/** @file basic_string.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 21 Strings library
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BASIC_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|_BASIC_STRING_H
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
file|<ext/atomicity.h>
end_include

begin_include
include|#
directive|include
file|<debug/debug.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_comment
comment|/**    *  @class basic_string basic_string.h<string>    *  @brief  Managing sequences of characters and character-like objects.    *    *  @ingroup Containers    *  @ingroup Sequences    *    *  Meets the requirements of a<a href="tables.html#65">container</a>, a    *<a href="tables.html#66">reversible container</a>, and a    *<a href="tables.html#67">sequence</a>.  Of the    *<a href="tables.html#68">optional sequence requirements</a>, only    *  @c push_back, @c at, and array access are supported.    *    *  @doctodo    *    *    *  @if maint    *  Documentation?  What's that?    *  Nathan Myers<ncm@cantrip.org>.    *    *  A string looks like this:    *    *  @code    *                                        [_Rep]    *                                        _M_length    *   [basic_string<char_type>]            _M_capacity    *   _M_dataplus                          _M_refcount    *   _M_p ---------------->               unnamed array of char_type    *  @endcode    *    *  Where the _M_p points to the first character in the string, and    *  you cast it to a pointer-to-_Rep and subtract 1 to get a    *  pointer to the header.    *    *  This approach has the enormous advantage that a string object    *  requires only one allocation.  All the ugliness is confined    *  within a single pair of inline functions, which each compile to    *  a single "add" instruction: _Rep::_M_data(), and    *  string::_M_rep(); and the allocation function which gets a    *  block of raw bytes and with room enough and constructs a _Rep    *  object at the front.    *    *  The reason you want _M_data pointing to the character array and    *  not the _Rep is so that the debugger can see the string    *  contents. (Probably we should add a non-inline member to get    *  the _Rep for the debugger to use, so users can check the actual    *  string length.)    *    *  Note that the _Rep object is a POD so that you can have a    *  static "empty string" _Rep object already "constructed" before    *  static constructors have run.  The reference-count encoding is    *  chosen so that a 0 indicates one reference, so you never try to    *  destroy the empty-string _Rep object.    *    *  All but the last paragraph is considered pretty conventional    *  for a C++ string implementation.    *  @endif   */
end_comment

begin_comment
comment|// 21.3  Template class basic_string
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
name|basic_string
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
comment|// Types:
name|public
operator|:
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
name|_Alloc
name|allocator_type
typedef|;
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
name|difference_type
name|difference_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_CharT_alloc_type
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_CharT_alloc_type
operator|::
name|const_reference
name|const_reference
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

begin_typedef
typedef|typedef
name|__gnu_cxx
operator|::
name|__normal_iterator
operator|<
name|pointer
operator|,
name|basic_string
operator|>
name|iterator
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
name|basic_string
operator|>
name|const_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|const_iterator
operator|>
name|const_reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|iterator
operator|>
name|reverse_iterator
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
comment|//   4. All fields==0 is an empty string, given the extra storage
end_comment

begin_comment
comment|//      beyond-the-end for a null terminator; thus, the shared
end_comment

begin_comment
comment|//      empty string representation needs no constructor.
end_comment

begin_struct
struct|struct
name|_Rep_base
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
struct|;
end_struct

begin_decl_stmt
name|struct
name|_Rep
range|:
name|_Rep_base
block|{
comment|// Types:
typedef|typedef
name|typename
name|_Alloc
operator|::
name|template
name|rebind
operator|<
name|char
operator|>
operator|::
name|other
name|_Raw_bytes_alloc
expr_stmt|;
comment|// (Public) Data members:
comment|// The maximum number of individual char_type elements of an
comment|// individual string is determined by _S_max_size. This is the
comment|// value that will be returned by max_size().  (Whereas npos
comment|// is the maximum number of bytes the allocator can allocate.)
comment|// If one was to divvy up the theoretical largest size string,
comment|// with a terminating character and m _CharT elements, it'd
comment|// look like this:
comment|// npos = sizeof(_Rep) + (m * sizeof(_CharT)) + sizeof(_CharT)
comment|// Solving for m:
comment|// m = ((npos - sizeof(_Rep))/sizeof(CharT)) - 1
comment|// In addition, this implementation quarters this amount.
specifier|static
specifier|const
name|size_type
name|_S_max_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|_CharT
name|_S_terminal
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The following storage is init'd to 0 by the linker, resulting
end_comment

begin_comment
comment|// (carefully) in an empty string with one reference.
end_comment

begin_decl_stmt
specifier|static
name|size_type
name|_S_empty_rep_storage
index|[]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|_Rep
modifier|&
name|_S_empty_rep
parameter_list|()
block|{
comment|// NB: Mild hack to avoid strict-aliasing warnings.  Note that
comment|// _S_empty_rep_storage is never modified and the punning should
comment|// be reasonably safe in this case.
name|void
modifier|*
name|__p
init|=
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|&
name|_S_empty_rep_storage
operator|)
decl_stmt|;
return|return
operator|*
name|reinterpret_cast
operator|<
name|_Rep
operator|*
operator|>
operator|(
name|__p
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|_M_is_leaked
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|_M_refcount
operator|<
literal|0
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
name|this
operator|->
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
name|this
operator|->
name|_M_refcount
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_M_set_sharable
parameter_list|()
block|{
name|this
operator|->
name|_M_refcount
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_M_set_length_and_sharable
parameter_list|(
name|size_type
name|__n
parameter_list|)
block|{
name|this
operator|->
name|_M_set_sharable
argument_list|()
expr_stmt|;
comment|// One reference.
name|this
operator|->
name|_M_length
operator|=
name|__n
expr_stmt|;
name|traits_type
operator|::
name|assign
argument_list|(
name|this
operator|->
name|_M_refdata
argument_list|()
index|[
name|__n
index|]
argument_list|,
name|_S_terminal
argument_list|)
expr_stmt|;
comment|// grrr. (per 21.3.4)
comment|// You cannot leave those LWG people alone for a second.
block|}
end_function

begin_function
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
end_function

begin_function
name|_CharT
modifier|*
name|_M_grab
parameter_list|(
specifier|const
name|_Alloc
modifier|&
name|__alloc1
parameter_list|,
specifier|const
name|_Alloc
modifier|&
name|__alloc2
parameter_list|)
block|{
return|return
operator|(
operator|!
name|_M_is_leaked
argument_list|()
operator|&&
name|__alloc1
operator|==
name|__alloc2
operator|)
condition|?
name|_M_refcopy
argument_list|()
else|:
name|_M_clone
argument_list|(
name|__alloc1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Create& Destroy
end_comment

begin_function_decl
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
end_function_decl

begin_function
name|void
name|_M_dispose
parameter_list|(
specifier|const
name|_Alloc
modifier|&
name|__a
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|_GLIBCXX_FULLY_DYNAMIC_STRING
if|if
condition|(
name|__builtin_expect
argument_list|(
name|this
operator|!=
operator|&
name|_S_empty_rep
argument_list|()
argument_list|,
name|false
argument_list|)
condition|)
endif|#
directive|endif
if|if
condition|(
name|__gnu_cxx
operator|::
name|__exchange_and_add_dispatch
argument_list|(
operator|&
name|this
operator|->
name|_M_refcount
argument_list|,
operator|-
literal|1
argument_list|)
operator|<=
literal|0
condition|)
name|_M_destroy
argument_list|(
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// XXX MT
end_comment

begin_function_decl
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
end_function_decl

begin_function
name|_CharT
modifier|*
name|_M_refcopy
parameter_list|()
function|throw
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|_GLIBCXX_FULLY_DYNAMIC_STRING
if|if
condition|(
name|__builtin_expect
argument_list|(
name|this
operator|!=
operator|&
name|_S_empty_rep
argument_list|()
argument_list|,
name|false
argument_list|)
condition|)
endif|#
directive|endif
name|__gnu_cxx
operator|::
name|__atomic_add_dispatch
argument_list|(
operator|&
name|this
operator|->
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
end_function

begin_comment
comment|// XXX MT
end_comment

begin_function_decl
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
end_function_decl

begin_comment
unit|};
comment|// Use empty-base optimization: http://www.cantrip.org/emptyopt.html
end_comment

begin_decl_stmt
name|struct
name|_Alloc_hider
range|:
name|_Alloc
block|{
name|_Alloc_hider
argument_list|(
name|_CharT
operator|*
name|__dat
argument_list|,
specifier|const
name|_Alloc
operator|&
name|__a
argument_list|)
operator|:
name|_Alloc
argument_list|(
name|__a
argument_list|)
block|,
name|_M_p
argument_list|(
argument|__dat
argument_list|)
block|{ }
name|_CharT
operator|*
name|_M_p
block|;
comment|// The actual data.
block|}
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Data Members (public):
end_comment

begin_comment
comment|// NB: This is an unsigned type, and thus represents the maximum
end_comment

begin_comment
comment|// size that the allocator can hold.
end_comment

begin_comment
comment|///  Value returned by various member functions when they fail.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|size_type
name|npos
init|=
name|static_cast
operator|<
name|size_type
operator|>
operator|(
operator|-
literal|1
operator|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Data Members (private):
end_comment

begin_decl_stmt
name|mutable
name|_Alloc_hider
name|_M_dataplus
decl_stmt|;
end_decl_stmt

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

begin_function
name|_CharT
modifier|*
name|_M_data
parameter_list|(
name|_CharT
modifier|*
name|__p
parameter_list|)
block|{
return|return
operator|(
name|_M_dataplus
operator|.
name|_M_p
operator|=
name|__p
operator|)
return|;
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

begin_comment
comment|// For the internal use we have functions similar to `begin'/`end'
end_comment

begin_comment
comment|// but they do not call _M_leak.
end_comment

begin_expr_stmt
name|iterator
name|_M_ibegin
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|_M_data
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|_M_iend
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|_M_data
argument_list|()
operator|+
name|this
operator|->
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|_M_leak
parameter_list|()
comment|// for use in begin()& non-const op[]
block|{
if|if
condition|(
operator|!
name|_M_rep
argument_list|()
operator|->
name|_M_is_leaked
argument_list|()
condition|)
name|_M_leak_hard
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|size_type
name|_M_check
argument_list|(
name|size_type
name|__pos
argument_list|,
specifier|const
name|char
operator|*
name|__s
argument_list|)
decl|const
block|{
if|if
condition|(
name|__pos
operator|>
name|this
operator|->
name|size
argument_list|()
condition|)
name|__throw_out_of_range
argument_list|(
name|__N
argument_list|(
name|__s
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|__pos
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_check_length
argument_list|(
name|size_type
name|__n1
argument_list|,
name|size_type
name|__n2
argument_list|,
specifier|const
name|char
operator|*
name|__s
argument_list|)
decl|const
block|{
if|if
condition|(
name|this
operator|->
name|max_size
argument_list|()
operator|-
operator|(
name|this
operator|->
name|size
argument_list|()
operator|-
name|__n1
operator|)
operator|<
name|__n2
condition|)
name|__throw_length_error
argument_list|(
name|__N
argument_list|(
name|__s
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NB: _M_limit doesn't check for a bad __pos value.
end_comment

begin_decl_stmt
name|size_type
name|_M_limit
argument_list|(
name|size_type
name|__pos
argument_list|,
name|size_type
name|__off
argument_list|)
decl|const
block|{
specifier|const
name|bool
name|__testoff
init|=
name|__off
operator|<
name|this
operator|->
name|size
argument_list|()
operator|-
name|__pos
decl_stmt|;
return|return
name|__testoff
condition|?
name|__off
else|:
name|this
operator|->
name|size
argument_list|()
operator|-
name|__pos
return|;
block|}
end_decl_stmt

begin_comment
comment|// True if _Rep and source do not overlap.
end_comment

begin_decl_stmt
name|bool
name|_M_disjunct
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|)
decl|const
block|{
return|return
operator|(
name|less
operator|<
specifier|const
name|_CharT
operator|*
operator|>
operator|(
operator|)
operator|(
name|__s
operator|,
name|_M_data
argument_list|()
operator|)
operator|||
name|less
operator|<
specifier|const
name|_CharT
operator|*
operator|>
operator|(
operator|)
operator|(
name|_M_data
argument_list|()
operator|+
name|this
operator|->
name|size
argument_list|()
operator|,
name|__s
operator|)
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// When __n = 1 way faster than the general multichar
end_comment

begin_comment
comment|// traits_type::copy/move/assign.
end_comment

begin_function
specifier|static
name|void
name|_M_copy
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
name|_M_move
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
name|_M_assign
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
name|class
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
name|iterator
name|__k1
parameter_list|,
name|iterator
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
name|const_iterator
name|__k1
parameter_list|,
name|const_iterator
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
name|_M_copy
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
name|_M_copy
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
name|int
name|_S_compare
parameter_list|(
name|size_type
name|__x
parameter_list|,
name|size_type
name|__y
parameter_list|)
block|{
if|if
condition|(
name|__x
operator|>
name|__y
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|__x
operator|<
name|__y
condition|)
return|return
operator|-
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

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
name|size_type
name|__len2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_M_leak_hard
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|_Rep
modifier|&
name|_S_empty_rep
parameter_list|()
block|{
return|return
name|_Rep
operator|::
name|_S_empty_rep
argument_list|()
return|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|// Construct/copy/destroy:
end_comment

begin_comment
comment|// NB: We overload ctors in some cases instead of using default
end_comment

begin_comment
comment|// arguments, per 17.4.4.4 para. 2 item 2.
end_comment

begin_comment
comment|/**        *  @brief  Default constructor creates an empty string.        */
end_comment

begin_expr_stmt
specifier|inline
name|basic_string
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Construct an empty string using allocator @a a.        */
end_comment

begin_function_decl
name|explicit
name|basic_string
parameter_list|(
specifier|const
name|_Alloc
modifier|&
name|__a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// NB: per LWG issue 42, semantics different from IS:
end_comment

begin_comment
comment|/**        *  @brief  Construct string with copy of value of @a str.        *  @param  str  Source string.        */
end_comment

begin_expr_stmt
name|basic_string
argument_list|(
specifier|const
name|basic_string
operator|&
name|__str
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Construct string as copy of a substring.        *  @param  str  Source string.        *  @param  pos  Index of first character to copy from.        *  @param  n  Number of characters to copy (default remainder).        */
end_comment

begin_macro
name|basic_string
argument_list|(
argument|const basic_string& __str
argument_list|,
argument|size_type __pos
argument_list|,
argument|size_type __n = npos
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**        *  @brief  Construct string as copy of a substring.        *  @param  str  Source string.        *  @param  pos  Index of first character to copy from.        *  @param  n  Number of characters to copy.        *  @param  a  Allocator to use.        */
end_comment

begin_macro
name|basic_string
argument_list|(
argument|const basic_string& __str
argument_list|,
argument|size_type __pos
argument_list|,
argument|size_type __n
argument_list|,
argument|const _Alloc& __a
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**        *  @brief  Construct string initialized by a character array.        *  @param  s  Source character array.        *  @param  n  Number of characters to copy.        *  @param  a  Allocator to use (default is default allocator).        *        *  NB: @a s must have at least @a n characters, '\0' has no special        *  meaning.        */
end_comment

begin_macro
name|basic_string
argument_list|(
argument|const _CharT* __s
argument_list|,
argument|size_type __n
argument_list|,
argument|const _Alloc& __a = _Alloc()
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**        *  @brief  Construct string as copy of a C string.        *  @param  s  Source C string.        *  @param  a  Allocator to use (default is default allocator).        */
end_comment

begin_expr_stmt
name|basic_string
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
specifier|const
name|_Alloc
operator|&
name|__a
operator|=
name|_Alloc
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Construct string as multiple characters.        *  @param  n  Number of characters.        *  @param  c  Character to use.        *  @param  a  Allocator to use (default is default allocator).        */
end_comment

begin_macro
name|basic_string
argument_list|(
argument|size_type __n
argument_list|,
argument|_CharT __c
argument_list|,
argument|const _Alloc& __a = _Alloc()
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**        *  @brief  Construct string as copy of a range.        *  @param  beg  Start of range.        *  @param  end  End of range.        *  @param  a  Allocator to use (default is default allocator).        */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIterator
operator|>
name|basic_string
argument_list|(
argument|_InputIterator __beg
argument_list|,
argument|_InputIterator __end
argument_list|,
argument|const _Alloc& __a = _Alloc()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Destroy the string instance.        */
end_comment

begin_expr_stmt
operator|~
name|basic_string
argument_list|()
block|{
name|_M_rep
argument_list|()
operator|->
name|_M_dispose
argument_list|(
name|this
operator|->
name|get_allocator
argument_list|()
argument_list|)
block|; }
comment|/**        *  @brief  Assign the value of @a str to this string.        *  @param  str  Source string.        */
name|basic_string
operator|&
name|operator
operator|=
operator|(
specifier|const
name|basic_string
operator|&
name|__str
operator|)
block|{
return|return
name|this
operator|->
name|assign
argument_list|(
name|__str
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Copy contents of @a s into this string.        *  @param  s  Source null-terminated string.        */
end_comment

begin_decl_stmt
name|basic_string
modifier|&
name|operator
init|=
operator|(
specifier|const
name|_CharT
operator|*
name|__s
operator|)
block|{
return|return
name|this
operator|->
name|assign
argument_list|(
name|__s
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Set value to string of length 1.        *  @param  c  Source character.        *        *  Assigning to a character makes this string length 1 and        *  (*this)[0] == @a c.        */
end_comment

begin_decl_stmt
name|basic_string
modifier|&
name|operator
init|=
operator|(
name|_CharT
name|__c
operator|)
block|{
name|this
operator|->
name|assign
argument_list|(
literal|1
argument_list|,
name|__c
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_comment
comment|// Iterators:
end_comment

begin_comment
comment|/**        *  Returns a read/write iterator that points to the first character in        *  the %string.  Unshares the string.        */
end_comment

begin_function
name|iterator
name|begin
parameter_list|()
block|{
name|_M_leak
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|_M_data
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) iterator that points to the first        *  character in the %string.        */
end_comment

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|_M_data
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write iterator that points one past the last        *  character in the %string.  Unshares the string.        */
end_comment

begin_function
name|iterator
name|end
parameter_list|()
block|{
name|_M_leak
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|_M_data
argument_list|()
operator|+
name|this
operator|->
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) iterator that points one past the        *  last character in the %string.        */
end_comment

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|_M_data
argument_list|()
operator|+
name|this
operator|->
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write reverse iterator that points to the last        *  character in the %string.  Iteration is done in reverse element        *  order.  Unshares the string.        */
end_comment

begin_function
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|reverse_iterator
argument_list|(
name|this
operator|->
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) reverse iterator that points        *  to the last character in the %string.  Iteration is done in        *  reverse element order.        */
end_comment

begin_expr_stmt
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|const_reverse_iterator
argument_list|(
name|this
operator|->
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write reverse iterator that points to one before the        *  first character in the %string.  Iteration is done in reverse        *  element order.  Unshares the string.        */
end_comment

begin_function
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|reverse_iterator
argument_list|(
name|this
operator|->
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) reverse iterator that points        *  to one before the first character in the %string.  Iteration        *  is done in reverse element order.        */
end_comment

begin_expr_stmt
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|const_reverse_iterator
argument_list|(
name|this
operator|->
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Capacity:
end_comment

begin_comment
comment|///  Returns the number of characters in the string, not including any
end_comment

begin_comment
comment|///  null-termination.
end_comment

begin_expr_stmt
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|_M_rep
argument_list|()
operator|->
name|_M_length
return|;
block|}
end_expr_stmt

begin_comment
comment|///  Returns the number of characters in the string, not including any
end_comment

begin_comment
comment|///  null-termination.
end_comment

begin_expr_stmt
name|size_type
name|length
argument_list|()
specifier|const
block|{
return|return
name|_M_rep
argument_list|()
operator|->
name|_M_length
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the size() of the largest possible %string.
end_comment

begin_expr_stmt
name|size_type
name|max_size
argument_list|()
specifier|const
block|{
return|return
name|_Rep
operator|::
name|_S_max_size
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Resizes the %string to the specified number of characters.        *  @param  n  Number of characters the %string should contain.        *  @param  c  Character to fill any new elements.        *        *  This function will %resize the %string to the specified        *  number of characters.  If the number is smaller than the        *  %string's current size the %string is truncated, otherwise        *  the %string is extended and new elements are set to @a c.        */
end_comment

begin_function_decl
name|void
name|resize
parameter_list|(
name|size_type
name|__n
parameter_list|,
name|_CharT
name|__c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Resizes the %string to the specified number of characters.        *  @param  n  Number of characters the %string should contain.        *        *  This function will resize the %string to the specified length.  If        *  the new size is smaller than the %string's current size the %string        *  is truncated, otherwise the %string is extended and new characters        *  are default-constructed.  For basic types such as char, this means        *  setting them to 0.        */
end_comment

begin_function
name|void
name|resize
parameter_list|(
name|size_type
name|__n
parameter_list|)
block|{
name|this
operator|->
name|resize
argument_list|(
name|__n
argument_list|,
name|_CharT
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  Returns the total number of characters that the %string can hold        *  before needing to allocate more memory.        */
end_comment

begin_expr_stmt
name|size_type
name|capacity
argument_list|()
specifier|const
block|{
return|return
name|_M_rep
argument_list|()
operator|->
name|_M_capacity
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Attempt to preallocate enough memory for specified number of        *          characters.        *  @param  res_arg  Number of characters required.        *  @throw  std::length_error  If @a res_arg exceeds @c max_size().        *        *  This function attempts to reserve enough memory for the        *  %string to hold the specified number of characters.  If the        *  number requested is more than max_size(), length_error is        *  thrown.        *        *  The advantage of this function is that if optimal code is a        *  necessity and the user can determine the string length that will be        *  required, the user can reserve the memory in %advance, and thus        *  prevent a possible reallocation of memory and copying of %string        *  data.        */
end_comment

begin_function_decl
name|void
name|reserve
parameter_list|(
name|size_type
name|__res_arg
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  Erases the string, making it empty.        */
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|_M_mutate
argument_list|(
literal|0
argument_list|,
name|this
operator|->
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  Returns true if the %string is empty.  Equivalent to *this == "".        */
end_comment

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|// Element access:
end_comment

begin_comment
comment|/**        *  @brief  Subscript access to the data contained in the %string.        *  @param  pos  The index of the character to access.        *  @return  Read-only (constant) reference to the character.        *        *  This operator allows for easy, array-style, data access.        *  Note that data access with this operator is unchecked and        *  out_of_range lookups are not defined. (For checked lookups        *  see at().)        */
end_comment

begin_decl_stmt
name|const_reference
name|operator
index|[]
argument_list|(
name|size_type
name|__pos
argument_list|)
decl|const
block|{
name|_GLIBCXX_DEBUG_ASSERT
argument_list|(
name|__pos
operator|<=
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|_M_data
argument_list|()
index|[
name|__pos
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Subscript access to the data contained in the %string.        *  @param  pos  The index of the character to access.        *  @return  Read/write reference to the character.        *        *  This operator allows for easy, array-style, data access.        *  Note that data access with this operator is unchecked and        *  out_of_range lookups are not defined. (For checked lookups        *  see at().)  Unshares the string.        */
end_comment

begin_function
name|reference
name|operator
function|[]
parameter_list|(
name|size_type
name|__pos
parameter_list|)
block|{
comment|// allow pos == size() as v3 extension:
name|_GLIBCXX_DEBUG_ASSERT
argument_list|(
name|__pos
operator|<=
name|size
argument_list|()
argument_list|)
expr_stmt|;
comment|// but be strict in pedantic mode:
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|__pos
operator|<
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|_M_leak
argument_list|()
expr_stmt|;
return|return
name|_M_data
argument_list|()
index|[
name|__pos
index|]
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Provides access to the data contained in the %string.        *  @param n The index of the character to access.        *  @return  Read-only (const) reference to the character.        *  @throw  std::out_of_range  If @a n is an invalid index.        *        *  This function provides for safer data access.  The parameter is        *  first checked that it is in the range of the string.  The function        *  throws out_of_range if the check fails.        */
end_comment

begin_decl_stmt
name|const_reference
name|at
argument_list|(
name|size_type
name|__n
argument_list|)
decl|const
block|{
if|if
condition|(
name|__n
operator|>=
name|this
operator|->
name|size
argument_list|()
condition|)
name|__throw_out_of_range
argument_list|(
name|__N
argument_list|(
literal|"basic_string::at"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|_M_data
argument_list|()
index|[
name|__n
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Provides access to the data contained in the %string.        *  @param n The index of the character to access.        *  @return  Read/write reference to the character.        *  @throw  std::out_of_range  If @a n is an invalid index.        *        *  This function provides for safer data access.  The parameter is        *  first checked that it is in the range of the string.  The function        *  throws out_of_range if the check fails.  Success results in        *  unsharing the string.        */
end_comment

begin_function
name|reference
name|at
parameter_list|(
name|size_type
name|__n
parameter_list|)
block|{
if|if
condition|(
name|__n
operator|>=
name|size
argument_list|()
condition|)
name|__throw_out_of_range
argument_list|(
name|__N
argument_list|(
literal|"basic_string::at"
argument_list|)
argument_list|)
expr_stmt|;
name|_M_leak
argument_list|()
expr_stmt|;
return|return
name|_M_data
argument_list|()
index|[
name|__n
index|]
return|;
block|}
end_function

begin_comment
comment|// Modifiers:
end_comment

begin_comment
comment|/**        *  @brief  Append a string to this string.        *  @param str  The string to append.        *  @return  Reference to this string.        */
end_comment

begin_expr_stmt
name|basic_string
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|basic_string
operator|&
name|__str
operator|)
block|{
return|return
name|this
operator|->
name|append
argument_list|(
name|__str
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Append a C string.        *  @param s  The C string to append.        *  @return  Reference to this string.        */
end_comment

begin_expr_stmt
name|basic_string
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|_CharT
operator|*
name|__s
operator|)
block|{
return|return
name|this
operator|->
name|append
argument_list|(
name|__s
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Append a character.        *  @param c  The character to append.        *  @return  Reference to this string.        */
end_comment

begin_expr_stmt
name|basic_string
operator|&
name|operator
operator|+=
operator|(
name|_CharT
name|__c
operator|)
block|{
name|this
operator|->
name|push_back
argument_list|(
name|__c
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Append a string to this string.        *  @param str  The string to append.        *  @return  Reference to this string.        */
end_comment

begin_function_decl
name|basic_string
modifier|&
name|append
parameter_list|(
specifier|const
name|basic_string
modifier|&
name|__str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Append a substring.        *  @param str  The string to append.        *  @param pos  Index of the first character of str to append.        *  @param n  The number of characters to append.        *  @return  Reference to this string.        *  @throw  std::out_of_range if @a pos is not a valid index.        *        *  This function appends @a n characters from @a str starting at @a pos        *  to this string.  If @a n is is larger than the number of available        *  characters in @a str, the remainder of @a str is appended.        */
end_comment

begin_function_decl
name|basic_string
modifier|&
name|append
parameter_list|(
specifier|const
name|basic_string
modifier|&
name|__str
parameter_list|,
name|size_type
name|__pos
parameter_list|,
name|size_type
name|__n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Append a C substring.        *  @param s  The C string to append.        *  @param n  The number of characters to append.        *  @return  Reference to this string.        */
end_comment

begin_function_decl
name|basic_string
modifier|&
name|append
parameter_list|(
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|,
name|size_type
name|__n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Append a C string.        *  @param s  The C string to append.        *  @return  Reference to this string.        */
end_comment

begin_function
name|basic_string
modifier|&
name|append
parameter_list|(
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|)
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|append
argument_list|(
name|__s
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Append multiple characters.        *  @param n  The number of characters to append.        *  @param c  The character to use.        *  @return  Reference to this string.        *        *  Appends n copies of c to this string.        */
end_comment

begin_function_decl
name|basic_string
modifier|&
name|append
parameter_list|(
name|size_type
name|__n
parameter_list|,
name|_CharT
name|__c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Append a range of characters.        *  @param first  Iterator referencing the first character to append.        *  @param last  Iterator marking the end of the range.        *  @return  Reference to this string.        *        *  Appends characters in the range [first,last) to this string.        */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIterator
operator|>
name|basic_string
operator|&
name|append
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|)
block|{
return|return
name|this
operator|->
name|replace
argument_list|(
name|_M_iend
argument_list|()
argument_list|,
name|_M_iend
argument_list|()
argument_list|,
name|__first
argument_list|,
name|__last
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Append a single character.        *  @param c  Character to append.        */
end_comment

begin_function
name|void
name|push_back
parameter_list|(
name|_CharT
name|__c
parameter_list|)
block|{
specifier|const
name|size_type
name|__len
init|=
literal|1
operator|+
name|this
operator|->
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|__len
operator|>
name|this
operator|->
name|capacity
argument_list|()
operator|||
name|_M_rep
argument_list|()
operator|->
name|_M_is_shared
argument_list|()
condition|)
name|this
operator|->
name|reserve
argument_list|(
name|__len
argument_list|)
expr_stmt|;
name|traits_type
operator|::
name|assign
argument_list|(
name|_M_data
argument_list|()
index|[
name|this
operator|->
name|size
argument_list|()
index|]
argument_list|,
name|__c
argument_list|)
expr_stmt|;
name|_M_rep
argument_list|()
operator|->
name|_M_set_length_and_sharable
argument_list|(
name|__len
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Set value to contents of another string.        *  @param  str  Source string to use.        *  @return  Reference to this string.        */
end_comment

begin_function_decl
name|basic_string
modifier|&
name|assign
parameter_list|(
specifier|const
name|basic_string
modifier|&
name|__str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Set value to a substring of a string.        *  @param str  The string to use.        *  @param pos  Index of the first character of str.        *  @param n  Number of characters to use.        *  @return  Reference to this string.        *  @throw  std::out_of_range if @a pos is not a valid index.        *        *  This function sets this string to the substring of @a str consisting        *  of @a n characters at @a pos.  If @a n is is larger than the number        *  of available characters in @a str, the remainder of @a str is used.        */
end_comment

begin_function
name|basic_string
modifier|&
name|assign
parameter_list|(
specifier|const
name|basic_string
modifier|&
name|__str
parameter_list|,
name|size_type
name|__pos
parameter_list|,
name|size_type
name|__n
parameter_list|)
block|{
return|return
name|this
operator|->
name|assign
argument_list|(
name|__str
operator|.
name|_M_data
argument_list|()
operator|+
name|__str
operator|.
name|_M_check
argument_list|(
name|__pos
argument_list|,
literal|"basic_string::assign"
argument_list|)
argument_list|,
name|__str
operator|.
name|_M_limit
argument_list|(
name|__pos
argument_list|,
name|__n
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Set value to a C substring.        *  @param s  The C string to use.        *  @param n  Number of characters to use.        *  @return  Reference to this string.        *        *  This function sets the value of this string to the first @a n        *  characters of @a s.  If @a n is is larger than the number of        *  available characters in @a s, the remainder of @a s is used.        */
end_comment

begin_function_decl
name|basic_string
modifier|&
name|assign
parameter_list|(
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|,
name|size_type
name|__n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Set value to contents of a C string.        *  @param s  The C string to use.        *  @return  Reference to this string.        *        *  This function sets the value of this string to the value of @a s.        *  The data is copied, so there is no dependence on @a s once the        *  function returns.        */
end_comment

begin_function
name|basic_string
modifier|&
name|assign
parameter_list|(
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|)
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|assign
argument_list|(
name|__s
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Set value to multiple characters.        *  @param n  Length of the resulting string.        *  @param c  The character to use.        *  @return  Reference to this string.        *        *  This function sets the value of this string to @a n copies of        *  character @a c.        */
end_comment

begin_function
name|basic_string
modifier|&
name|assign
parameter_list|(
name|size_type
name|__n
parameter_list|,
name|_CharT
name|__c
parameter_list|)
block|{
return|return
name|_M_replace_aux
argument_list|(
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|,
name|this
operator|->
name|size
argument_list|()
argument_list|,
name|__n
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Set value to a range of characters.        *  @param first  Iterator referencing the first character to append.        *  @param last  Iterator marking the end of the range.        *  @return  Reference to this string.        *        *  Sets value of string to characters in the range [first,last).       */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIterator
operator|>
name|basic_string
operator|&
name|assign
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|)
block|{
return|return
name|this
operator|->
name|replace
argument_list|(
name|_M_ibegin
argument_list|()
argument_list|,
name|_M_iend
argument_list|()
argument_list|,
name|__first
argument_list|,
name|__last
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Insert multiple characters.        *  @param p  Iterator referencing location in string to insert at.        *  @param n  Number of characters to insert        *  @param c  The character to insert.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Inserts @a n copies of character @a c starting at the position        *  referenced by iterator @a p.  If adding characters causes the length        *  to exceed max_size(), length_error is thrown.  The value of the        *  string doesn't change if an error is thrown.       */
end_comment

begin_function
name|void
name|insert
parameter_list|(
name|iterator
name|__p
parameter_list|,
name|size_type
name|__n
parameter_list|,
name|_CharT
name|__c
parameter_list|)
block|{
name|this
operator|->
name|replace
argument_list|(
name|__p
argument_list|,
name|__p
argument_list|,
name|__n
argument_list|,
name|__c
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Insert a range of characters.        *  @param p  Iterator referencing location in string to insert at.        *  @param beg  Start of range.        *  @param end  End of range.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Inserts characters in range [beg,end).  If adding characters causes        *  the length to exceed max_size(), length_error is thrown.  The value        *  of the string doesn't change if an error is thrown.       */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIterator
operator|>
name|void
name|insert
argument_list|(
argument|iterator __p
argument_list|,
argument|_InputIterator __beg
argument_list|,
argument|_InputIterator __end
argument_list|)
block|{
name|this
operator|->
name|replace
argument_list|(
name|__p
argument_list|,
name|__p
argument_list|,
name|__beg
argument_list|,
name|__end
argument_list|)
block|; }
comment|/**        *  @brief  Insert value of a string.        *  @param pos1  Iterator referencing location in string to insert at.        *  @param str  The string to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Inserts value of @a str starting at @a pos1.  If adding characters        *  causes the length to exceed max_size(), length_error is thrown.  The        *  value of the string doesn't change if an error is thrown.       */
name|basic_string
operator|&
name|insert
argument_list|(
argument|size_type __pos1
argument_list|,
argument|const basic_string& __str
argument_list|)
block|{
return|return
name|this
operator|->
name|insert
argument_list|(
name|__pos1
argument_list|,
name|__str
argument_list|,
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Insert a substring.        *  @param pos1  Iterator referencing location in string to insert at.        *  @param str  The string to insert.        *  @param pos2  Start of characters in str to insert.        *  @param n  Number of characters to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *  @throw  std::out_of_range  If @a pos1> size() or        *  @a pos2> @a str.size().        *        *  Starting at @a pos1, insert @a n character of @a str beginning with        *  @a pos2.  If adding characters causes the length to exceed        *  max_size(), length_error is thrown.  If @a pos1 is beyond the end of        *  this string or @a pos2 is beyond the end of @a str, out_of_range is        *  thrown.  The value of the string doesn't change if an error is        *  thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|insert
parameter_list|(
name|size_type
name|__pos1
parameter_list|,
specifier|const
name|basic_string
modifier|&
name|__str
parameter_list|,
name|size_type
name|__pos2
parameter_list|,
name|size_type
name|__n
parameter_list|)
block|{
return|return
name|this
operator|->
name|insert
argument_list|(
name|__pos1
argument_list|,
name|__str
operator|.
name|_M_data
argument_list|()
operator|+
name|__str
operator|.
name|_M_check
argument_list|(
name|__pos2
argument_list|,
literal|"basic_string::insert"
argument_list|)
argument_list|,
name|__str
operator|.
name|_M_limit
argument_list|(
name|__pos2
argument_list|,
name|__n
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Insert a C substring.        *  @param pos  Iterator referencing location in string to insert at.        *  @param s  The C string to insert.        *  @param n  The number of characters to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *  @throw  std::out_of_range  If @a pos is beyond the end of this        *  string.        *        *  Inserts the first @a n characters of @a s starting at @a pos.  If        *  adding characters causes the length to exceed max_size(),        *  length_error is thrown.  If @a pos is beyond end(), out_of_range is        *  thrown.  The value of the string doesn't change if an error is        *  thrown.       */
end_comment

begin_function_decl
name|basic_string
modifier|&
name|insert
parameter_list|(
name|size_type
name|__pos
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|,
name|size_type
name|__n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Insert a C string.        *  @param pos  Iterator referencing location in string to insert at.        *  @param s  The C string to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *  @throw  std::out_of_range  If @a pos is beyond the end of this        *  string.        *        *  Inserts the first @a n characters of @a s starting at @a pos.  If        *  adding characters causes the length to exceed max_size(),        *  length_error is thrown.  If @a pos is beyond end(), out_of_range is        *  thrown.  The value of the string doesn't change if an error is        *  thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|insert
parameter_list|(
name|size_type
name|__pos
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|)
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|insert
argument_list|(
name|__pos
argument_list|,
name|__s
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Insert multiple characters.        *  @param pos  Index in string to insert at.        *  @param n  Number of characters to insert        *  @param c  The character to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *  @throw  std::out_of_range  If @a pos is beyond the end of this        *  string.        *        *  Inserts @a n copies of character @a c starting at index @a pos.  If        *  adding characters causes the length to exceed max_size(),        *  length_error is thrown.  If @a pos> length(), out_of_range is        *  thrown.  The value of the string doesn't change if an error is        *  thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|insert
parameter_list|(
name|size_type
name|__pos
parameter_list|,
name|size_type
name|__n
parameter_list|,
name|_CharT
name|__c
parameter_list|)
block|{
return|return
name|_M_replace_aux
argument_list|(
name|_M_check
argument_list|(
name|__pos
argument_list|,
literal|"basic_string::insert"
argument_list|)
argument_list|,
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|,
name|__n
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Insert one character.        *  @param p  Iterator referencing position in string to insert at.        *  @param c  The character to insert.        *  @return  Iterator referencing newly inserted char.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Inserts character @a c at position referenced by @a p.  If adding        *  character causes the length to exceed max_size(), length_error is        *  thrown.  If @a p is beyond end of string, out_of_range is thrown.        *  The value of the string doesn't change if an error is thrown.       */
end_comment

begin_function
name|iterator
name|insert
parameter_list|(
name|iterator
name|__p
parameter_list|,
name|_CharT
name|__c
parameter_list|)
block|{
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|__p
operator|>=
name|_M_ibegin
argument_list|()
operator|&&
name|__p
operator|<=
name|_M_iend
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|size_type
name|__pos
init|=
name|__p
operator|-
name|_M_ibegin
argument_list|()
decl_stmt|;
name|_M_replace_aux
argument_list|(
name|__pos
argument_list|,
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|,
name|size_type
argument_list|(
literal|1
argument_list|)
argument_list|,
name|__c
argument_list|)
expr_stmt|;
name|_M_rep
argument_list|()
operator|->
name|_M_set_leaked
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|_M_data
argument_list|()
operator|+
name|__pos
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Remove characters.        *  @param pos  Index of first character to remove (default 0).        *  @param n  Number of characters to remove (default remainder).        *  @return  Reference to this string.        *  @throw  std::out_of_range  If @a pos is beyond the end of this        *  string.        *        *  Removes @a n characters from this string starting at @a pos.  The        *  length of the string is reduced by @a n.  If there are< @a n        *  characters to remove, the remainder of the string is truncated.  If        *  @a p is beyond end of string, out_of_range is thrown.  The value of        *  the string doesn't change if an error is thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|erase
parameter_list|(
name|size_type
name|__pos
init|=
literal|0
parameter_list|,
name|size_type
name|__n
init|=
name|npos
parameter_list|)
block|{
name|_M_mutate
argument_list|(
name|_M_check
argument_list|(
name|__pos
argument_list|,
literal|"basic_string::erase"
argument_list|)
argument_list|,
name|_M_limit
argument_list|(
name|__pos
argument_list|,
name|__n
argument_list|)
argument_list|,
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Remove one character.        *  @param position  Iterator referencing the character to remove.        *  @return  iterator referencing same location after removal.        *        *  Removes the character at @a position from this string. The value        *  of the string doesn't change if an error is thrown.       */
end_comment

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|__position
parameter_list|)
block|{
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|__position
operator|>=
name|_M_ibegin
argument_list|()
operator|&&
name|__position
operator|<
name|_M_iend
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|size_type
name|__pos
init|=
name|__position
operator|-
name|_M_ibegin
argument_list|()
decl_stmt|;
name|_M_mutate
argument_list|(
name|__pos
argument_list|,
name|size_type
argument_list|(
literal|1
argument_list|)
argument_list|,
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|_M_rep
argument_list|()
operator|->
name|_M_set_leaked
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|_M_data
argument_list|()
operator|+
name|__pos
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Remove a range of characters.        *  @param first  Iterator referencing the first character to remove.        *  @param last  Iterator referencing the end of the range.        *  @return  Iterator referencing location of first after removal.        *        *  Removes the characters in the range [first,last) from this string.        *  The value of the string doesn't change if an error is thrown.       */
end_comment

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|__first
parameter_list|,
name|iterator
name|__last
parameter_list|)
block|{
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|__first
operator|>=
name|_M_ibegin
argument_list|()
operator|&&
name|__first
operator|<=
name|__last
operator|&&
name|__last
operator|<=
name|_M_iend
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|size_type
name|__pos
init|=
name|__first
operator|-
name|_M_ibegin
argument_list|()
decl_stmt|;
name|_M_mutate
argument_list|(
name|__pos
argument_list|,
name|__last
operator|-
name|__first
argument_list|,
name|size_type
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|_M_rep
argument_list|()
operator|->
name|_M_set_leaked
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|_M_data
argument_list|()
operator|+
name|__pos
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Replace characters with value from another string.        *  @param pos  Index of first character to replace.        *  @param n  Number of characters to be replaced.        *  @param str  String to insert.        *  @return  Reference to this string.        *  @throw  std::out_of_range  If @a pos is beyond the end of this        *  string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [pos,pos+n) from this string.        *  In place, the value of @a str is inserted.  If @a pos is beyond end        *  of string, out_of_range is thrown.  If the length of the result        *  exceeds max_size(), length_error is thrown.  The value of the string        *  doesn't change if an error is thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|size_type
name|__pos
parameter_list|,
name|size_type
name|__n
parameter_list|,
specifier|const
name|basic_string
modifier|&
name|__str
parameter_list|)
block|{
return|return
name|this
operator|->
name|replace
argument_list|(
name|__pos
argument_list|,
name|__n
argument_list|,
name|__str
operator|.
name|_M_data
argument_list|()
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Replace characters with value from another string.        *  @param pos1  Index of first character to replace.        *  @param n1  Number of characters to be replaced.        *  @param str  String to insert.        *  @param pos2  Index of first character of str to use.        *  @param n2  Number of characters from str to use.        *  @return  Reference to this string.        *  @throw  std::out_of_range  If @a pos1> size() or @a pos2>        *  str.size().        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [pos1,pos1 + n) from this        *  string.  In place, the value of @a str is inserted.  If @a pos is        *  beyond end of string, out_of_range is thrown.  If the length of the        *  result exceeds max_size(), length_error is thrown.  The value of the        *  string doesn't change if an error is thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|size_type
name|__pos1
parameter_list|,
name|size_type
name|__n1
parameter_list|,
specifier|const
name|basic_string
modifier|&
name|__str
parameter_list|,
name|size_type
name|__pos2
parameter_list|,
name|size_type
name|__n2
parameter_list|)
block|{
return|return
name|this
operator|->
name|replace
argument_list|(
name|__pos1
argument_list|,
name|__n1
argument_list|,
name|__str
operator|.
name|_M_data
argument_list|()
operator|+
name|__str
operator|.
name|_M_check
argument_list|(
name|__pos2
argument_list|,
literal|"basic_string::replace"
argument_list|)
argument_list|,
name|__str
operator|.
name|_M_limit
argument_list|(
name|__pos2
argument_list|,
name|__n2
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Replace characters with value of a C substring.        *  @param pos  Index of first character to replace.        *  @param n1  Number of characters to be replaced.        *  @param s  C string to insert.        *  @param n2  Number of characters from @a s to use.        *  @return  Reference to this string.        *  @throw  std::out_of_range  If @a pos1> size().        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [pos,pos + n1) from this string.        *  In place, the first @a n2 characters of @a s are inserted, or all        *  of @a s if @a n2 is too large.  If @a pos is beyond end of string,        *  out_of_range is thrown.  If the length of result exceeds max_size(),        *  length_error is thrown.  The value of the string doesn't change if        *  an error is thrown.       */
end_comment

begin_function_decl
name|basic_string
modifier|&
name|replace
parameter_list|(
name|size_type
name|__pos
parameter_list|,
name|size_type
name|__n1
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|,
name|size_type
name|__n2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Replace characters with value of a C string.        *  @param pos  Index of first character to replace.        *  @param n1  Number of characters to be replaced.        *  @param s  C string to insert.        *  @return  Reference to this string.        *  @throw  std::out_of_range  If @a pos> size().        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [pos,pos + n1) from this string.        *  In place, the first @a n characters of @a s are inserted.  If @a        *  pos is beyond end of string, out_of_range is thrown.  If the length        *  of result exceeds max_size(), length_error is thrown.  The value of        *  the string doesn't change if an error is thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|size_type
name|__pos
parameter_list|,
name|size_type
name|__n1
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|)
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|replace
argument_list|(
name|__pos
argument_list|,
name|__n1
argument_list|,
name|__s
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Replace characters with multiple characters.        *  @param pos  Index of first character to replace.        *  @param n1  Number of characters to be replaced.        *  @param n2  Number of characters to insert.        *  @param c  Character to insert.        *  @return  Reference to this string.        *  @throw  std::out_of_range  If @a pos> size().        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [pos,pos + n1) from this string.        *  In place, @a n2 copies of @a c are inserted.  If @a pos is beyond        *  end of string, out_of_range is thrown.  If the length of result        *  exceeds max_size(), length_error is thrown.  The value of the string        *  doesn't change if an error is thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|size_type
name|__pos
parameter_list|,
name|size_type
name|__n1
parameter_list|,
name|size_type
name|__n2
parameter_list|,
name|_CharT
name|__c
parameter_list|)
block|{
return|return
name|_M_replace_aux
argument_list|(
name|_M_check
argument_list|(
name|__pos
argument_list|,
literal|"basic_string::replace"
argument_list|)
argument_list|,
name|_M_limit
argument_list|(
name|__pos
argument_list|,
name|__n1
argument_list|)
argument_list|,
name|__n2
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Replace range of characters with string.        *  @param i1  Iterator referencing start of range to replace.        *  @param i2  Iterator referencing end of range to replace.        *  @param str  String value to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [i1,i2).  In place, the value of        *  @a str is inserted.  If the length of result exceeds max_size(),        *  length_error is thrown.  The value of the string doesn't change if        *  an error is thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|iterator
name|__i1
parameter_list|,
name|iterator
name|__i2
parameter_list|,
specifier|const
name|basic_string
modifier|&
name|__str
parameter_list|)
block|{
return|return
name|this
operator|->
name|replace
argument_list|(
name|__i1
argument_list|,
name|__i2
argument_list|,
name|__str
operator|.
name|_M_data
argument_list|()
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Replace range of characters with C substring.        *  @param i1  Iterator referencing start of range to replace.        *  @param i2  Iterator referencing end of range to replace.        *  @param s  C string value to insert.        *  @param n  Number of characters from s to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [i1,i2).  In place, the first @a        *  n characters of @a s are inserted.  If the length of result exceeds        *  max_size(), length_error is thrown.  The value of the string doesn't        *  change if an error is thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|iterator
name|__i1
parameter_list|,
name|iterator
name|__i2
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
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|_M_ibegin
argument_list|()
operator|<=
name|__i1
operator|&&
name|__i1
operator|<=
name|__i2
operator|&&
name|__i2
operator|<=
name|_M_iend
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|replace
argument_list|(
name|__i1
operator|-
name|_M_ibegin
argument_list|()
argument_list|,
name|__i2
operator|-
name|__i1
argument_list|,
name|__s
argument_list|,
name|__n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Replace range of characters with C string.        *  @param i1  Iterator referencing start of range to replace.        *  @param i2  Iterator referencing end of range to replace.        *  @param s  C string value to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [i1,i2).  In place, the        *  characters of @a s are inserted.  If the length of result exceeds        *  max_size(), length_error is thrown.  The value of the string doesn't        *  change if an error is thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|iterator
name|__i1
parameter_list|,
name|iterator
name|__i2
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|)
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|replace
argument_list|(
name|__i1
argument_list|,
name|__i2
argument_list|,
name|__s
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Replace range of characters with multiple characters        *  @param i1  Iterator referencing start of range to replace.        *  @param i2  Iterator referencing end of range to replace.        *  @param n  Number of characters to insert.        *  @param c  Character to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [i1,i2).  In place, @a n copies        *  of @a c are inserted.  If the length of result exceeds max_size(),        *  length_error is thrown.  The value of the string doesn't change if        *  an error is thrown.       */
end_comment

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|iterator
name|__i1
parameter_list|,
name|iterator
name|__i2
parameter_list|,
name|size_type
name|__n
parameter_list|,
name|_CharT
name|__c
parameter_list|)
block|{
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|_M_ibegin
argument_list|()
operator|<=
name|__i1
operator|&&
name|__i1
operator|<=
name|__i2
operator|&&
name|__i2
operator|<=
name|_M_iend
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|_M_replace_aux
argument_list|(
name|__i1
operator|-
name|_M_ibegin
argument_list|()
argument_list|,
name|__i2
operator|-
name|__i1
argument_list|,
name|__n
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Replace range of characters with range.        *  @param i1  Iterator referencing start of range to replace.        *  @param i2  Iterator referencing end of range to replace.        *  @param k1  Iterator referencing start of range to insert.        *  @param k2  Iterator referencing end of range to insert.        *  @return  Reference to this string.        *  @throw  std::length_error  If new length exceeds @c max_size().        *        *  Removes the characters in the range [i1,i2).  In place, characters        *  in the range [k1,k2) are inserted.  If the length of result exceeds        *  max_size(), length_error is thrown.  The value of the string doesn't        *  change if an error is thrown.       */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIterator
operator|>
name|basic_string
operator|&
name|replace
argument_list|(
argument|iterator __i1
argument_list|,
argument|iterator __i2
argument_list|,
argument|_InputIterator __k1
argument_list|,
argument|_InputIterator __k2
argument_list|)
block|{
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|_M_ibegin
argument_list|()
operator|<=
name|__i1
operator|&&
name|__i1
operator|<=
name|__i2
operator|&&
name|__i2
operator|<=
name|_M_iend
argument_list|()
argument_list|)
block|;
name|__glibcxx_requires_valid_range
argument_list|(
name|__k1
argument_list|,
name|__k2
argument_list|)
block|;
typedef|typedef
name|typename
name|std
operator|::
name|__is_integer
operator|<
name|_InputIterator
operator|>
operator|::
name|__type
name|_Integral
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|_M_replace_dispatch
argument_list|(
name|__i1
argument_list|,
name|__i2
argument_list|,
name|__k1
argument_list|,
name|__k2
argument_list|,
name|_Integral
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|// Specializations for the common case of pointer and iterator:
end_comment

begin_comment
comment|// useful to avoid the overhead of temporary buffering in _M_replace.
end_comment

begin_expr_stmt
unit|basic_string
operator|&
name|replace
argument_list|(
argument|iterator __i1
argument_list|,
argument|iterator __i2
argument_list|,
argument|_CharT* __k1
argument_list|,
argument|_CharT* __k2
argument_list|)
block|{
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|_M_ibegin
argument_list|()
operator|<=
name|__i1
operator|&&
name|__i1
operator|<=
name|__i2
operator|&&
name|__i2
operator|<=
name|_M_iend
argument_list|()
argument_list|)
block|;
name|__glibcxx_requires_valid_range
argument_list|(
name|__k1
argument_list|,
name|__k2
argument_list|)
block|;
return|return
name|this
operator|->
name|replace
argument_list|(
name|__i1
operator|-
name|_M_ibegin
argument_list|()
argument_list|,
name|__i2
operator|-
name|__i1
argument_list|,
name|__k1
argument_list|,
name|__k2
operator|-
name|__k1
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|iterator
name|__i1
parameter_list|,
name|iterator
name|__i2
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
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|_M_ibegin
argument_list|()
operator|<=
name|__i1
operator|&&
name|__i1
operator|<=
name|__i2
operator|&&
name|__i2
operator|<=
name|_M_iend
argument_list|()
argument_list|)
expr_stmt|;
name|__glibcxx_requires_valid_range
argument_list|(
name|__k1
argument_list|,
name|__k2
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|replace
argument_list|(
name|__i1
operator|-
name|_M_ibegin
argument_list|()
argument_list|,
name|__i2
operator|-
name|__i1
argument_list|,
name|__k1
argument_list|,
name|__k2
operator|-
name|__k1
argument_list|)
return|;
block|}
end_function

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|iterator
name|__i1
parameter_list|,
name|iterator
name|__i2
parameter_list|,
name|iterator
name|__k1
parameter_list|,
name|iterator
name|__k2
parameter_list|)
block|{
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|_M_ibegin
argument_list|()
operator|<=
name|__i1
operator|&&
name|__i1
operator|<=
name|__i2
operator|&&
name|__i2
operator|<=
name|_M_iend
argument_list|()
argument_list|)
expr_stmt|;
name|__glibcxx_requires_valid_range
argument_list|(
name|__k1
argument_list|,
name|__k2
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|replace
argument_list|(
name|__i1
operator|-
name|_M_ibegin
argument_list|()
argument_list|,
name|__i2
operator|-
name|__i1
argument_list|,
name|__k1
operator|.
name|base
argument_list|()
argument_list|,
name|__k2
operator|-
name|__k1
argument_list|)
return|;
block|}
end_function

begin_function
name|basic_string
modifier|&
name|replace
parameter_list|(
name|iterator
name|__i1
parameter_list|,
name|iterator
name|__i2
parameter_list|,
name|const_iterator
name|__k1
parameter_list|,
name|const_iterator
name|__k2
parameter_list|)
block|{
name|_GLIBCXX_DEBUG_PEDASSERT
argument_list|(
name|_M_ibegin
argument_list|()
operator|<=
name|__i1
operator|&&
name|__i1
operator|<=
name|__i2
operator|&&
name|__i2
operator|<=
name|_M_iend
argument_list|()
argument_list|)
expr_stmt|;
name|__glibcxx_requires_valid_range
argument_list|(
name|__k1
argument_list|,
name|__k2
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|replace
argument_list|(
name|__i1
operator|-
name|_M_ibegin
argument_list|()
argument_list|,
name|__i2
operator|-
name|__i1
argument_list|,
name|__k1
operator|.
name|base
argument_list|()
argument_list|,
name|__k2
operator|-
name|__k1
argument_list|)
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|class
name|_Integer
operator|>
name|basic_string
operator|&
name|_M_replace_dispatch
argument_list|(
argument|iterator __i1
argument_list|,
argument|iterator __i2
argument_list|,
argument|_Integer __n
argument_list|,
argument|_Integer __val
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|_M_replace_aux
argument_list|(
name|__i1
operator|-
name|_M_ibegin
argument_list|()
argument_list|,
name|__i2
operator|-
name|__i1
argument_list|,
name|__n
argument_list|,
name|__val
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIterator
operator|>
name|basic_string
operator|&
name|_M_replace_dispatch
argument_list|(
argument|iterator __i1
argument_list|,
argument|iterator __i2
argument_list|,
argument|_InputIterator __k1
argument_list|,
argument|_InputIterator __k2
argument_list|,
argument|__false_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|basic_string
modifier|&
name|_M_replace_aux
parameter_list|(
name|size_type
name|__pos1
parameter_list|,
name|size_type
name|__n1
parameter_list|,
name|size_type
name|__n2
parameter_list|,
name|_CharT
name|__c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|basic_string
modifier|&
name|_M_replace_safe
parameter_list|(
name|size_type
name|__pos1
parameter_list|,
name|size_type
name|__n1
parameter_list|,
specifier|const
name|_CharT
modifier|*
name|__s
parameter_list|,
name|size_type
name|__n2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// _S_construct_aux is used to implement the 21.3.1 para 15 which
end_comment

begin_comment
comment|// requires special behaviour if _InIter is an integral type
end_comment

begin_expr_stmt
name|template
operator|<
name|class
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
argument|__false_type
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
name|class
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
argument|__true_type
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
name|class
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
name|class
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
argument|input_iterator_tag
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
name|class
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
argument|forward_iterator_tag
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

begin_comment
comment|/**        *  @brief  Copy substring into C string.        *  @param s  C string to copy value into.        *  @param n  Number of characters to copy.        *  @param pos  Index of first character to copy.        *  @return  Number of characters actually copied        *  @throw  std::out_of_range  If pos> size().        *        *  Copies up to @a n characters starting at @a pos into the C string @a        *  s.  If @a pos is greater than size(), out_of_range is thrown.       */
end_comment

begin_decl_stmt
name|size_type
name|copy
argument_list|(
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__n
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Swap contents with another string.        *  @param s  String to swap with.        *        *  Exchanges the contents of this string with that of @a s in constant        *  time.       */
end_comment

begin_function_decl
name|void
name|swap
parameter_list|(
name|basic_string
modifier|&
name|__s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// String operations:
end_comment

begin_comment
comment|/**        *  @brief  Return const pointer to null-terminated contents.        *        *  This is a handle to internal data.  Do not modify or dire things may        *  happen.       */
end_comment

begin_expr_stmt
specifier|const
name|_CharT
operator|*
name|c_str
argument_list|()
specifier|const
block|{
return|return
name|_M_data
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return const pointer to contents.        *        *  This is a handle to internal data.  Do not modify or dire things may        *  happen.       */
end_comment

begin_expr_stmt
specifier|const
name|_CharT
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|_M_data
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return copy of allocator used to construct this string.       */
end_comment

begin_expr_stmt
name|allocator_type
name|get_allocator
argument_list|()
specifier|const
block|{
return|return
name|_M_dataplus
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Find position of a C substring.        *  @param s  C string to locate.        *  @param pos  Index of character to search from.        *  @param n  Number of characters from @a s to search for.        *  @return  Index of start of first occurrence.        *        *  Starting from @a pos, searches forward for the first @a n characters        *  in @a s within this string.  If found, returns the index where it        *  begins.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
argument_list|,
name|size_type
name|__n
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a string.        *  @param str  String to locate.        *  @param pos  Index of character to search from (default 0).        *  @return  Index of start of first occurrence.        *        *  Starting from @a pos, searches forward for value of @a str within        *  this string.  If found, returns the index where it begins.  If not        *  found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find
argument_list|(
specifier|const
name|basic_string
operator|&
name|__str
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|find
argument_list|(
name|__str
operator|.
name|data
argument_list|()
argument_list|,
name|__pos
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a C string.        *  @param s  C string to locate.        *  @param pos  Index of character to search from (default 0).        *  @return  Index of start of first occurrence.        *        *  Starting from @a pos, searches forward for the value of @a s within        *  this string.  If found, returns the index where it begins.  If not        *  found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|find
argument_list|(
name|__s
argument_list|,
name|__pos
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a character.        *  @param c  Character to locate.        *  @param pos  Index of character to search from (default 0).        *  @return  Index of first occurrence.        *        *  Starting from @a pos, searches forward for @a c within this string.        *  If found, returns the index where it was found.  If not found,        *  returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find
argument_list|(
name|_CharT
name|__c
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a string.        *  @param str  String to locate.        *  @param pos  Index of character to search back from (default end).        *  @return  Index of start of last occurrence.        *        *  Starting from @a pos, searches backward for value of @a str within        *  this string.  If found, returns the index where it begins.  If not        *  found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|rfind
argument_list|(
specifier|const
name|basic_string
operator|&
name|__str
argument_list|,
name|size_type
name|__pos
operator|=
name|npos
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|rfind
argument_list|(
name|__str
operator|.
name|data
argument_list|()
argument_list|,
name|__pos
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a C substring.        *  @param s  C string to locate.        *  @param pos  Index of character to search back from.        *  @param n  Number of characters from s to search for.        *  @return  Index of start of last occurrence.        *        *  Starting from @a pos, searches backward for the first @a n        *  characters in @a s within this string.  If found, returns the index        *  where it begins.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|rfind
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
argument_list|,
name|size_type
name|__n
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a C string.        *  @param s  C string to locate.        *  @param pos  Index of character to start search at (default end).        *  @return  Index of start of  last occurrence.        *        *  Starting from @a pos, searches backward for the value of @a s within        *  this string.  If found, returns the index where it begins.  If not        *  found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|rfind
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
operator|=
name|npos
argument_list|)
decl|const
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|rfind
argument_list|(
name|__s
argument_list|,
name|__pos
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a character.        *  @param c  Character to locate.        *  @param pos  Index of character to search back from (default end).        *  @return  Index of last occurrence.        *        *  Starting from @a pos, searches backward for @a c within this string.        *  If found, returns the index where it was found.  If not found,        *  returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|rfind
argument_list|(
name|_CharT
name|__c
argument_list|,
name|size_type
name|__pos
operator|=
name|npos
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a character of string.        *  @param str  String containing characters to locate.        *  @param pos  Index of character to search from (default 0).        *  @return  Index of first occurrence.        *        *  Starting from @a pos, searches forward for one of the characters of        *  @a str within this string.  If found, returns the index where it was        *  found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_first_of
argument_list|(
specifier|const
name|basic_string
operator|&
name|__str
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|find_first_of
argument_list|(
name|__str
operator|.
name|data
argument_list|()
argument_list|,
name|__pos
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a character of C substring.        *  @param s  String containing characters to locate.        *  @param pos  Index of character to search from.        *  @param n  Number of characters from s to search for.        *  @return  Index of first occurrence.        *        *  Starting from @a pos, searches forward for one of the first @a n        *  characters of @a s within this string.  If found, returns the index        *  where it was found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_first_of
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
argument_list|,
name|size_type
name|__n
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a character of C string.        *  @param s  String containing characters to locate.        *  @param pos  Index of character to search from (default 0).        *  @return  Index of first occurrence.        *        *  Starting from @a pos, searches forward for one of the characters of        *  @a s within this string.  If found, returns the index where it was        *  found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_first_of
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|find_first_of
argument_list|(
name|__s
argument_list|,
name|__pos
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a character.        *  @param c  Character to locate.        *  @param pos  Index of character to search from (default 0).        *  @return  Index of first occurrence.        *        *  Starting from @a pos, searches forward for the character @a c within        *  this string.  If found, returns the index where it was found.  If        *  not found, returns npos.        *        *  Note: equivalent to find(c, pos).       */
end_comment

begin_decl_stmt
name|size_type
name|find_first_of
argument_list|(
name|_CharT
name|__c
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|find
argument_list|(
name|__c
argument_list|,
name|__pos
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a character of string.        *  @param str  String containing characters to locate.        *  @param pos  Index of character to search back from (default end).        *  @return  Index of last occurrence.        *        *  Starting from @a pos, searches backward for one of the characters of        *  @a str within this string.  If found, returns the index where it was        *  found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_last_of
argument_list|(
specifier|const
name|basic_string
operator|&
name|__str
argument_list|,
name|size_type
name|__pos
operator|=
name|npos
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|find_last_of
argument_list|(
name|__str
operator|.
name|data
argument_list|()
argument_list|,
name|__pos
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a character of C substring.        *  @param s  C string containing characters to locate.        *  @param pos  Index of character to search back from.        *  @param n  Number of characters from s to search for.        *  @return  Index of last occurrence.        *        *  Starting from @a pos, searches backward for one of the first @a n        *  characters of @a s within this string.  If found, returns the index        *  where it was found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_last_of
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
argument_list|,
name|size_type
name|__n
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a character of C string.        *  @param s  C string containing characters to locate.        *  @param pos  Index of character to search back from (default end).        *  @return  Index of last occurrence.        *        *  Starting from @a pos, searches backward for one of the characters of        *  @a s within this string.  If found, returns the index where it was        *  found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_last_of
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
operator|=
name|npos
argument_list|)
decl|const
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|find_last_of
argument_list|(
name|__s
argument_list|,
name|__pos
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a character.        *  @param c  Character to locate.        *  @param pos  Index of character to search back from (default end).        *  @return  Index of last occurrence.        *        *  Starting from @a pos, searches backward for @a c within this string.        *  If found, returns the index where it was found.  If not found,        *  returns npos.        *        *  Note: equivalent to rfind(c, pos).       */
end_comment

begin_decl_stmt
name|size_type
name|find_last_of
argument_list|(
name|_CharT
name|__c
argument_list|,
name|size_type
name|__pos
operator|=
name|npos
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|rfind
argument_list|(
name|__c
argument_list|,
name|__pos
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a character not in string.        *  @param str  String containing characters to avoid.        *  @param pos  Index of character to search from (default 0).        *  @return  Index of first occurrence.        *        *  Starting from @a pos, searches forward for a character not contained        *  in @a str within this string.  If found, returns the index where it        *  was found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_first_not_of
argument_list|(
specifier|const
name|basic_string
operator|&
name|__str
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|find_first_not_of
argument_list|(
name|__str
operator|.
name|data
argument_list|()
argument_list|,
name|__pos
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a character not in C substring.        *  @param s  C string containing characters to avoid.        *  @param pos  Index of character to search from.        *  @param n  Number of characters from s to consider.        *  @return  Index of first occurrence.        *        *  Starting from @a pos, searches forward for a character not contained        *  in the first @a n characters of @a s within this string.  If found,        *  returns the index where it was found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_first_not_of
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
argument_list|,
name|size_type
name|__n
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a character not in C string.        *  @param s  C string containing characters to avoid.        *  @param pos  Index of character to search from (default 0).        *  @return  Index of first occurrence.        *        *  Starting from @a pos, searches forward for a character not contained        *  in @a s within this string.  If found, returns the index where it        *  was found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_first_not_of
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|find_first_not_of
argument_list|(
name|__s
argument_list|,
name|__pos
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find position of a different character.        *  @param c  Character to avoid.        *  @param pos  Index of character to search from (default 0).        *  @return  Index of first occurrence.        *        *  Starting from @a pos, searches forward for a character other than @a c        *  within this string.  If found, returns the index where it was found.        *  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_first_not_of
argument_list|(
name|_CharT
name|__c
argument_list|,
name|size_type
name|__pos
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a character not in string.        *  @param str  String containing characters to avoid.        *  @param pos  Index of character to search back from (default end).        *  @return  Index of last occurrence.        *        *  Starting from @a pos, searches backward for a character not        *  contained in @a str within this string.  If found, returns the index        *  where it was found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_last_not_of
argument_list|(
specifier|const
name|basic_string
operator|&
name|__str
argument_list|,
name|size_type
name|__pos
operator|=
name|npos
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|find_last_not_of
argument_list|(
name|__str
operator|.
name|data
argument_list|()
argument_list|,
name|__pos
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a character not in C substring.        *  @param s  C string containing characters to avoid.        *  @param pos  Index of character to search back from.        *  @param n  Number of characters from s to consider.        *  @return  Index of last occurrence.        *        *  Starting from @a pos, searches backward for a character not        *  contained in the first @a n characters of @a s within this string.        *  If found, returns the index where it was found.  If not found,        *  returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_last_not_of
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
argument_list|,
name|size_type
name|__n
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a character not in C string.        *  @param s  C string containing characters to avoid.        *  @param pos  Index of character to search back from (default end).        *  @return  Index of last occurrence.        *        *  Starting from @a pos, searches backward for a character not        *  contained in @a s within this string.  If found, returns the index        *  where it was found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_last_not_of
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__pos
operator|=
name|npos
argument_list|)
decl|const
block|{
name|__glibcxx_requires_string
argument_list|(
name|__s
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|find_last_not_of
argument_list|(
name|__s
argument_list|,
name|__pos
argument_list|,
name|traits_type
operator|::
name|length
argument_list|(
name|__s
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find last position of a different character.        *  @param c  Character to avoid.        *  @param pos  Index of character to search back from (default end).        *  @return  Index of last occurrence.        *        *  Starting from @a pos, searches backward for a character other than        *  @a c within this string.  If found, returns the index where it was        *  found.  If not found, returns npos.       */
end_comment

begin_decl_stmt
name|size_type
name|find_last_not_of
argument_list|(
name|_CharT
name|__c
argument_list|,
name|size_type
name|__pos
operator|=
name|npos
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Get a substring.        *  @param pos  Index of first character (default 0).        *  @param n  Number of characters in substring (default remainder).        *  @return  The new string.        *  @throw  std::out_of_range  If pos> size().        *        *  Construct and return a new string using the @a n characters starting        *  at @a pos.  If the string is too short, use the remainder of the        *  characters.  If @a pos is beyond the end of the string, out_of_range        *  is thrown.       */
end_comment

begin_decl_stmt
name|basic_string
name|substr
argument_list|(
name|size_type
name|__pos
operator|=
literal|0
argument_list|,
name|size_type
name|__n
operator|=
name|npos
argument_list|)
decl|const
block|{
return|return
name|basic_string
argument_list|(
operator|*
name|this
argument_list|,
name|_M_check
argument_list|(
name|__pos
argument_list|,
literal|"basic_string::substr"
argument_list|)
argument_list|,
name|__n
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Compare to a string.        *  @param str  String to compare against.        *  @return  Integer< 0, 0, or> 0.        *        *  Returns an integer< 0 if this string is ordered before @a str, 0 if        *  their values are equivalent, or> 0 if this string is ordered after        *  @a str.  Determines the effective length rlen of the strings to        *  compare as the smallest of size() and str.size().  The function        *  then compares the two strings by calling traits::compare(data(),        *  str.data(),rlen).  If the result of the comparison is nonzero returns        *  it, otherwise the shorter one is ordered first.       */
end_comment

begin_decl_stmt
name|int
name|compare
argument_list|(
specifier|const
name|basic_string
operator|&
name|__str
argument_list|)
decl|const
block|{
specifier|const
name|size_type
name|__size
init|=
name|this
operator|->
name|size
argument_list|()
decl_stmt|;
specifier|const
name|size_type
name|__osize
init|=
name|__str
operator|.
name|size
argument_list|()
decl_stmt|;
specifier|const
name|size_type
name|__len
init|=
name|std
operator|::
name|min
argument_list|(
name|__size
argument_list|,
name|__osize
argument_list|)
decl_stmt|;
name|int
name|__r
init|=
name|traits_type
operator|::
name|compare
argument_list|(
name|_M_data
argument_list|()
argument_list|,
name|__str
operator|.
name|data
argument_list|()
argument_list|,
name|__len
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|__r
condition|)
name|__r
operator|=
name|_S_compare
argument_list|(
name|__size
argument_list|,
name|__osize
argument_list|)
expr_stmt|;
return|return
name|__r
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Compare substring to a string.        *  @param pos  Index of first character of substring.        *  @param n  Number of characters in substring.        *  @param str  String to compare against.        *  @return  Integer< 0, 0, or> 0.        *        *  Form the substring of this string from the @a n characters starting        *  at @a pos.  Returns an integer< 0 if the substring is ordered        *  before @a str, 0 if their values are equivalent, or> 0 if the        *  substring is ordered after @a str.  Determines the effective length        *  rlen of the strings to compare as the smallest of the length of the        *  substring and @a str.size().  The function then compares the two        *  strings by calling traits::compare(substring.data(),str.data(),rlen).        *  If the result of the comparison is nonzero returns it, otherwise the        *  shorter one is ordered first.       */
end_comment

begin_decl_stmt
name|int
name|compare
argument_list|(
name|size_type
name|__pos
argument_list|,
name|size_type
name|__n
argument_list|,
specifier|const
name|basic_string
operator|&
name|__str
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Compare substring to a substring.        *  @param pos1  Index of first character of substring.        *  @param n1  Number of characters in substring.        *  @param str  String to compare against.        *  @param pos2  Index of first character of substring of str.        *  @param n2  Number of characters in substring of str.        *  @return  Integer< 0, 0, or> 0.        *        *  Form the substring of this string from the @a n1 characters starting        *  at @a pos1.  Form the substring of @a str from the @a n2 characters        *  starting at @a pos2.  Returns an integer< 0 if this substring is        *  ordered before the substring of @a str, 0 if their values are        *  equivalent, or> 0 if this substring is ordered after the substring        *  of @a str.  Determines the effective length rlen of the strings        *  to compare as the smallest of the lengths of the substrings.  The        *  function then compares the two strings by calling        *  traits::compare(substring.data(),str.substr(pos2,n2).data(),rlen).        *  If the result of the comparison is nonzero returns it, otherwise the        *  shorter one is ordered first.       */
end_comment

begin_decl_stmt
name|int
name|compare
argument_list|(
name|size_type
name|__pos1
argument_list|,
name|size_type
name|__n1
argument_list|,
specifier|const
name|basic_string
operator|&
name|__str
argument_list|,
name|size_type
name|__pos2
argument_list|,
name|size_type
name|__n2
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Compare to a C string.        *  @param s  C string to compare against.        *  @return  Integer< 0, 0, or> 0.        *        *  Returns an integer< 0 if this string is ordered before @a s, 0 if        *  their values are equivalent, or> 0 if this string is ordered after        *  @a s.  Determines the effective length rlen of the strings to        *  compare as the smallest of size() and the length of a string        *  constructed from @a s.  The function then compares the two strings        *  by calling traits::compare(data(),s,rlen).  If the result of the        *  comparison is nonzero returns it, otherwise the shorter one is        *  ordered first.       */
end_comment

begin_decl_stmt
name|int
name|compare
argument_list|(
specifier|const
name|_CharT
operator|*
name|__s
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 5 String::compare specification questionable
end_comment

begin_comment
comment|/**        *  @brief  Compare substring to a C string.        *  @param pos  Index of first character of substring.        *  @param n1  Number of characters in substring.        *  @param s  C string to compare against.        *  @return  Integer< 0, 0, or> 0.        *        *  Form the substring of this string from the @a n1 characters starting        *  at @a pos.  Returns an integer< 0 if the substring is ordered        *  before @a s, 0 if their values are equivalent, or> 0 if the        *  substring is ordered after @a s.  Determines the effective length        *  rlen of the strings to compare as the smallest of the length of the         *  substring and the length of a string constructed from @a s.  The        *  function then compares the two string by calling        *  traits::compare(substring.data(),s,rlen).  If the result of the        *  comparison is nonzero returns it, otherwise the shorter one is        *  ordered first.       */
end_comment

begin_decl_stmt
name|int
name|compare
argument_list|(
name|size_type
name|__pos
argument_list|,
name|size_type
name|__n1
argument_list|,
specifier|const
name|_CharT
operator|*
name|__s
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Compare substring against a character array.        *  @param pos1  Index of first character of substring.        *  @param n1  Number of characters in substring.        *  @param s  character array to compare against.        *  @param n2  Number of characters of s.        *  @return  Integer< 0, 0, or> 0.        *        *  Form the substring of this string from the @a n1 characters starting        *  at @a pos1.  Form a string from the first @a n2 characters of @a s.        *  Returns an integer< 0 if this substring is ordered before the string        *  from @a s, 0 if their values are equivalent, or> 0 if this substring        *  is ordered after the string from @a s.   Determines the effective        *  length rlen of the strings to compare as the smallest of the length        *  of the substring and @a n2.  The function then compares the two        *  strings by calling traits::compare(substring.data(),s,rlen).  If the        *  result of the comparison is nonzero returns it, otherwise the shorter        *  one is ordered first.        *        *  NB: s must have at least n2 characters, '\0' has no special        *  meaning.       */
end_comment

begin_decl_stmt
name|int
name|compare
argument_list|(
name|size_type
name|__pos
argument_list|,
name|size_type
name|__n1
argument_list|,
specifier|const
name|_CharT
operator|*
name|__s
argument_list|,
name|size_type
name|__n2
argument_list|)
decl|const
decl_stmt|;
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
specifier|inline
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|::
name|basic_string
argument_list|()
ifndef|#
directive|ifndef
name|_GLIBCXX_FULLY_DYNAMIC_STRING
operator|:
name|_M_dataplus
argument_list|(
argument|_S_empty_rep()._M_refdata()
argument_list|,
argument|_Alloc()
argument_list|)
block|{ }
else|#
directive|else
operator|:
name|_M_dataplus
argument_list|(
argument|_S_construct(size_type(), _CharT(), _Alloc())
argument_list|,
argument|_Alloc()
argument_list|)
block|{ }
endif|#
directive|endif
comment|// operator+
comment|/**    *  @brief  Concatenate two strings.    *  @param lhs  First string.    *  @param rhs  Last string.    *  @return  New string with value of @a lhs followed by @a rhs.    */
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
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|operator
operator|+
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
name|basic_string
operator|<
name|_CharT
block|,
name|_Traits
block|,
name|_Alloc
operator|>
name|__str
argument_list|(
name|__lhs
argument_list|)
block|;
name|__str
operator|.
name|append
argument_list|(
name|__rhs
argument_list|)
block|;
return|return
name|__str
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Concatenate C string and string.    *  @param lhs  First string.    *  @param rhs  Last string.    *  @return  New string with value of @a lhs followed by @a rhs.    */
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
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|operator
operator|+
operator|(
specifier|const
name|_CharT
operator|*
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**    *  @brief  Concatenate character and string.    *  @param lhs  First string.    *  @param rhs  Last string.    *  @return  New string with @a lhs followed by @a rhs.    */
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
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|operator
operator|+
operator|(
name|_CharT
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**    *  @brief  Concatenate string and C string.    *  @param lhs  First string.    *  @param rhs  Last string.    *  @return  New string with @a lhs followed by @a rhs.    */
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
specifier|inline
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|operator
operator|+
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|_CharT
operator|*
name|__rhs
operator|)
block|{
name|basic_string
operator|<
name|_CharT
block|,
name|_Traits
block|,
name|_Alloc
operator|>
name|__str
argument_list|(
name|__lhs
argument_list|)
block|;
name|__str
operator|.
name|append
argument_list|(
name|__rhs
argument_list|)
block|;
return|return
name|__str
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Concatenate string and character.    *  @param lhs  First string.    *  @param rhs  Last string.    *  @return  New string with @a lhs followed by @a rhs.    */
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
specifier|inline
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|operator
operator|+
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
name|_CharT
name|__rhs
operator|)
block|{
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|__string_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__string_type
operator|::
name|size_type
name|__size_type
expr_stmt|;
end_typedef

begin_function_decl
name|__string_type
name|__str
parameter_list|(
name|__lhs
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|__str
operator|.
name|append
argument_list|(
name|__size_type
argument_list|(
literal|1
argument_list|)
argument_list|,
name|__rhs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__str
return|;
end_return

begin_comment
unit|}
comment|// operator ==
end_comment

begin_comment
comment|/**    *  @brief  Test equivalence of two strings.    *  @param lhs  First string.    *  @param rhs  Second string.    *  @return  True if @a lhs.compare(@a rhs) == 0.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test equivalence of C string and string.    *  @param lhs  C string.    *  @param rhs  String.    *  @return  True if @a rhs.compare(@a lhs) == 0.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|_CharT
operator|*
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__rhs
operator|.
name|compare
argument_list|(
name|__lhs
argument_list|)
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test equivalence of string and C string.    *  @param lhs  String.    *  @param rhs  C string.    *  @return  True if @a lhs.compare(@a rhs) == 0.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|_CharT
operator|*
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|// operator !=
end_comment

begin_comment
comment|/**    *  @brief  Test difference of two strings.    *  @param lhs  First string.    *  @param rhs  Second string.    *  @return  True if @a lhs.compare(@a rhs) != 0.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__rhs
operator|.
name|compare
argument_list|(
name|__lhs
argument_list|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test difference of C string and string.    *  @param lhs  C string.    *  @param rhs  String.    *  @return  True if @a rhs.compare(@a lhs) != 0.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|_CharT
operator|*
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__rhs
operator|.
name|compare
argument_list|(
name|__lhs
argument_list|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test difference of string and C string.    *  @param lhs  String.    *  @param rhs  C string.    *  @return  True if @a lhs.compare(@a rhs) != 0.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|_CharT
operator|*
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|// operator<
end_comment

begin_comment
comment|/**    *  @brief  Test if string precedes string.    *  @param lhs  First string.    *  @param rhs  Second string.    *  @return  True if @a lhs precedes @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|<
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test if string precedes C string.    *  @param lhs  String.    *  @param rhs  C string.    *  @return  True if @a lhs precedes @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|_CharT
operator|*
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|<
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test if C string precedes string.    *  @param lhs  C string.    *  @param rhs  String.    *  @return  True if @a lhs precedes @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|_CharT
operator|*
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__rhs
operator|.
name|compare
argument_list|(
name|__lhs
argument_list|)
operator|>
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|// operator>
end_comment

begin_comment
comment|/**    *  @brief  Test if string follows string.    *  @param lhs  First string.    *  @param rhs  Second string.    *  @return  True if @a lhs follows @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|>
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test if string follows C string.    *  @param lhs  String.    *  @param rhs  C string.    *  @return  True if @a lhs follows @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|_CharT
operator|*
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|>
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test if C string follows string.    *  @param lhs  C string.    *  @param rhs  String.    *  @return  True if @a lhs follows @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|_CharT
operator|*
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__rhs
operator|.
name|compare
argument_list|(
name|__lhs
argument_list|)
operator|<
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|// operator<=
end_comment

begin_comment
comment|/**    *  @brief  Test if string doesn't follow string.    *  @param lhs  First string.    *  @param rhs  Second string.    *  @return  True if @a lhs doesn't follow @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|<=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test if string doesn't follow C string.    *  @param lhs  String.    *  @param rhs  C string.    *  @return  True if @a lhs doesn't follow @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|_CharT
operator|*
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|<=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test if C string doesn't follow string.    *  @param lhs  C string.    *  @param rhs  String.    *  @return  True if @a lhs doesn't follow @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|_CharT
operator|*
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__rhs
operator|.
name|compare
argument_list|(
name|__lhs
argument_list|)
operator|>=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|// operator>=
end_comment

begin_comment
comment|/**    *  @brief  Test if string doesn't precede string.    *  @param lhs  First string.    *  @param rhs  Second string.    *  @return  True if @a lhs doesn't precede @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|>=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test if string doesn't precede C string.    *  @param lhs  String.    *  @param rhs  C string.    *  @return  True if @a lhs doesn't precede @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__lhs
operator|,
specifier|const
name|_CharT
operator|*
name|__rhs
operator|)
block|{
return|return
name|__lhs
operator|.
name|compare
argument_list|(
name|__rhs
argument_list|)
operator|>=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Test if C string doesn't precede string.    *  @param lhs  C string.    *  @param rhs  String.    *  @return  True if @a lhs doesn't precede @a rhs.  False otherwise.    */
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
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|_CharT
operator|*
name|__lhs
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__rhs
operator|)
block|{
return|return
name|__rhs
operator|.
name|compare
argument_list|(
name|__lhs
argument_list|)
operator|<=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Swap contents of two strings.    *  @param lhs  First string.    *  @param rhs  Second string.    *    *  Exchanges the contents of @a lhs and @a rhs in constant time.    */
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
specifier|inline
name|void
name|swap
argument_list|(
argument|basic_string<_CharT
argument_list|,
argument|_Traits
argument_list|,
argument|_Alloc>& __lhs
argument_list|,
argument|basic_string<_CharT
argument_list|,
argument|_Traits
argument_list|,
argument|_Alloc>& __rhs
argument_list|)
block|{
name|__lhs
operator|.
name|swap
argument_list|(
name|__rhs
argument_list|)
block|; }
comment|/**    *  @brief  Read stream into a string.    *  @param is  Input stream.    *  @param str  Buffer to store into.    *  @return  Reference to the input stream.    *    *  Stores characters from @a is into @a str until whitespace is found, the    *  end of the stream is encountered, or str.max_size() is reached.  If    *  is.width() is non-zero, that is the limit on the number of characters    *  stored into @a str.  Any previous contents of @a str are erased.    */
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
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__is
operator|,
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__str
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|basic_istream
operator|<
name|char
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|char
operator|>
operator|&
name|__is
operator|,
name|basic_string
operator|<
name|char
operator|>
operator|&
name|__str
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**    *  @brief  Write string to a stream.    *  @param os  Output stream.    *  @param str  String to write out.    *  @return  Reference to the output stream.    *    *  Output characters of @a str into os following the same rules as for    *  writing a C string.    */
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
specifier|inline
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|<<
operator|(
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__os
operator|,
specifier|const
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__str
operator|)
block|{
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 586. string inserter not a formatted function
return|return
name|__ostream_insert
argument_list|(
name|__os
argument_list|,
name|__str
operator|.
name|data
argument_list|()
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Read a line from stream into a string.    *  @param is  Input stream.    *  @param str  Buffer to store into.    *  @param delim  Character marking end of line.    *  @return  Reference to the input stream.    *    *  Stores characters from @a is into @a str until @a delim is found, the    *  end of the stream is encountered, or str.max_size() is reached.  If    *  is.width() is non-zero, that is the limit on the number of characters    *  stored into @a str.  Any previous contents of @a str are erased.  If @a    *  delim was encountered, it is extracted but not stored into @a str.    */
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
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|getline
argument_list|(
argument|basic_istream<_CharT
argument_list|,
argument|_Traits>& __is
argument_list|,
argument|basic_string<_CharT
argument_list|,
argument|_Traits
argument_list|,
argument|_Alloc>& __str
argument_list|,
argument|_CharT __delim
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**    *  @brief  Read a line from stream into a string.    *  @param is  Input stream.    *  @param str  Buffer to store into.    *  @return  Reference to the input stream.    *    *  Stores characters from is into @a str until '\n' is found, the end of    *  the stream is encountered, or str.max_size() is reached.  If is.width()    *  is non-zero, that is the limit on the number of characters stored into    *  @a str.  Any previous contents of @a str are erased.  If end of line was    *  encountered, it is extracted but not stored into @a str.    */
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
specifier|inline
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|getline
argument_list|(
argument|basic_istream<_CharT
argument_list|,
argument|_Traits>& __is
argument_list|,
argument|basic_string<_CharT
argument_list|,
argument|_Traits
argument_list|,
argument|_Alloc>& __str
argument_list|)
block|{
return|return
name|getline
argument_list|(
name|__is
argument_list|,
name|__str
argument_list|,
name|__is
operator|.
name|widen
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|basic_istream
operator|<
name|char
operator|>
operator|&
name|getline
argument_list|(
argument|basic_istream<char>& __in
argument_list|,
argument|basic_string<char>& __str
argument_list|,
argument|char __delim
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|basic_istream
operator|<
name|wchar_t
operator|>
operator|&
name|getline
argument_list|(
argument|basic_istream<wchar_t>& __in
argument_list|,
argument|basic_string<wchar_t>& __str
argument_list|,
argument|wchar_t __delim
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BASIC_STRING_H */
end_comment

end_unit

