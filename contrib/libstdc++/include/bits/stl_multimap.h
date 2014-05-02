begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Multimap implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2004, 2005, 2006 Free Software Foundation, Inc.
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_multimap.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MULTIMAP_H
end_ifndef

begin_define
define|#
directive|define
name|_MULTIMAP_H
value|1
end_define

begin_include
include|#
directive|include
file|<bits/concept_check.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NESTED_NAMESPACE
argument_list|(
argument|std
argument_list|,
argument|_GLIBCXX_STD
argument_list|)
end_macro

begin_comment
comment|/**    *  @brief A standard container made up of (key,value) pairs, which can be    *  retrieved based on a key, in logarithmic time.    *    *  @ingroup Containers    *  @ingroup Assoc_containers    *    *  Meets the requirements of a<a href="tables.html#65">container</a>, a    *<a href="tables.html#66">reversible container</a>, and an    *<a href="tables.html#69">associative container</a> (using equivalent    *  keys).  For a @c multimap<Key,T> the key_type is Key, the mapped_type    *  is T, and the value_type is std::pair<const Key,T>.    *    *  Multimaps support bidirectional iterators.    *    *  @if maint    *  The private tree data is declared exactly the same way for map and    *  multimap; the distinction is made entirely in how the tree functions are    *  called (*_unique versus *_equal, same as the standard).    *  @endif   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Key
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
operator|=
name|std
operator|::
name|less
operator|<
name|_Key
operator|>
operator|,
name|typename
name|_Alloc
operator|=
name|std
operator|::
name|allocator
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|_Key
operator|,
name|_Tp
operator|>
expr|>
operator|>
name|class
name|multimap
block|{
name|public
operator|:
typedef|typedef
name|_Key
name|key_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Tp
name|mapped_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|_Key
operator|,
name|_Tp
operator|>
name|value_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|_Compare
name|key_compare
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Alloc
name|allocator_type
typedef|;
end_typedef

begin_label
name|private
label|:
end_label

begin_comment
comment|// concept requirements
end_comment

begin_typedef
typedef|typedef
name|typename
name|_Alloc
operator|::
name|value_type
name|_Alloc_value_type
expr_stmt|;
end_typedef

begin_macro
name|__glibcxx_class_requires
argument_list|(
argument|_Tp
argument_list|,
argument|_SGIAssignableConcept
argument_list|)
end_macro

begin_macro
name|__glibcxx_class_requires4
argument_list|(
argument|_Compare
argument_list|,
argument|bool
argument_list|,
argument|_Key
argument_list|,
argument|_Key
argument_list|,
argument|_BinaryFunctionConcept
argument_list|)
end_macro

begin_macro
name|__glibcxx_class_requires2
argument_list|(
argument|value_type
argument_list|,
argument|_Alloc_value_type
argument_list|,
argument|_SameTypeConcept
argument_list|)
end_macro

begin_label
name|public
label|:
end_label

begin_decl_stmt
name|class
name|value_compare
range|:
name|public
name|std
operator|::
name|binary_function
operator|<
name|value_type
decl_stmt|,
name|value_type
decl_stmt|,
name|bool
decl|>
block|{
name|friend
name|class
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
expr_stmt|;
name|protected
label|:
name|_Compare
name|comp
decl_stmt|;
name|value_compare
argument_list|(
argument|_Compare __c
argument_list|)
block|:
name|comp
argument_list|(
argument|__c
argument_list|)
block|{ }
name|public
label|:
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|value_type
operator|&
name|__x
operator|,
specifier|const
name|value_type
operator|&
name|__y
operator|)
specifier|const
block|{
return|return
name|comp
argument_list|(
name|__x
operator|.
name|first
argument_list|,
name|__y
operator|.
name|first
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// @if maint  This turns a red-black tree into a [multi]map.  @endif
end_comment

begin_typedef
typedef|typedef
name|typename
name|_Alloc
operator|::
name|template
name|rebind
operator|<
name|value_type
operator|>
operator|::
name|other
name|_Pair_alloc_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|_Rb_tree
operator|<
name|key_type
operator|,
name|value_type
operator|,
name|_Select1st
operator|<
name|value_type
operator|>
operator|,
name|key_compare
operator|,
name|_Pair_alloc_type
operator|>
name|_Rep_type
expr_stmt|;
end_typedef

begin_comment
comment|/// @if maint  The actual tree structure.  @endif
end_comment

begin_decl_stmt
name|_Rep_type
name|_M_t
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// many of these are specified differently in ISO, but the following are
end_comment

begin_comment
comment|// "functionally equivalent"
end_comment

begin_typedef
typedef|typedef
name|typename
name|_Pair_alloc_type
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Pair_alloc_type
operator|::
name|const_pointer
name|const_pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Pair_alloc_type
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Pair_alloc_type
operator|::
name|const_reference
name|const_reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|size_type
name|size_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|difference_type
name|difference_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|reverse_iterator
name|reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|const_reverse_iterator
name|const_reverse_iterator
expr_stmt|;
end_typedef

begin_comment
comment|// [23.3.2] construct/copy/destroy
end_comment

begin_comment
comment|// (get_allocator() is also listed in this section)
end_comment

begin_comment
comment|/**        *  @brief  Default constructor creates no elements.        */
end_comment

begin_expr_stmt
name|multimap
argument_list|()
operator|:
name|_M_t
argument_list|()
block|{ }
comment|// for some reason this was made a separate function
comment|/**        *  @brief  Default constructor creates no elements.        */
name|explicit
name|multimap
argument_list|(
specifier|const
name|_Compare
operator|&
name|__comp
argument_list|,
specifier|const
name|allocator_type
operator|&
name|__a
operator|=
name|allocator_type
argument_list|()
argument_list|)
operator|:
name|_M_t
argument_list|(
argument|__comp
argument_list|,
argument|__a
argument_list|)
block|{ }
comment|/**        *  @brief  %Multimap copy constructor.        *  @param  x  A %multimap of identical element and allocator types.        *        *  The newly-created %multimap uses a copy of the allocation object used        *  by @a x.        */
name|multimap
argument_list|(
specifier|const
name|multimap
operator|&
name|__x
argument_list|)
operator|:
name|_M_t
argument_list|(
argument|__x._M_t
argument_list|)
block|{ }
comment|/**        *  @brief  Builds a %multimap from a range.        *  @param  first  An input iterator.        *  @param  last  An input iterator.        *        *  Create a %multimap consisting of copies of the elements from        *  [first,last).  This is linear in N if the range is already sorted,        *  and NlogN otherwise (where N is distance(first,last)).        */
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|multimap
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|)
operator|:
name|_M_t
argument_list|()
block|{
name|_M_t
operator|.
name|_M_insert_equal
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|; }
comment|/**        *  @brief  Builds a %multimap from a range.        *  @param  first  An input iterator.        *  @param  last  An input iterator.        *  @param  comp  A comparison functor.        *  @param  a  An allocator object.        *        *  Create a %multimap consisting of copies of the elements from        *  [first,last).  This is linear in N if the range is already sorted,        *  and NlogN otherwise (where N is distance(first,last)).        */
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|multimap
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|const _Compare& __comp
argument_list|,
argument|const allocator_type& __a = allocator_type()
argument_list|)
operator|:
name|_M_t
argument_list|(
argument|__comp
argument_list|,
argument|__a
argument_list|)
block|{
name|_M_t
operator|.
name|_M_insert_equal
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|; }
comment|// FIXME There is no dtor declared, but we should have something generated
comment|// by Doxygen.  I don't know what tags to add to this paragraph to make
comment|// that happen:
comment|/**        *  The dtor only erases the elements, and note that if the elements        *  themselves are pointers, the pointed-to memory is not touched in any        *  way.  Managing the pointer is the user's responsibilty.        */
comment|/**        *  @brief  %Multimap assignment operator.        *  @param  x  A %multimap of identical element and allocator types.        *        *  All the elements of @a x are copied, but unlike the copy constructor,        *  the allocator object is not copied.        */
name|multimap
operator|&
name|operator
operator|=
operator|(
specifier|const
name|multimap
operator|&
name|__x
operator|)
block|{
name|_M_t
operator|=
name|__x
operator|.
name|_M_t
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Get a copy of the memory allocation object.
end_comment

begin_expr_stmt
name|allocator_type
name|get_allocator
argument_list|()
specifier|const
block|{
return|return
name|_M_t
operator|.
name|get_allocator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// iterators
end_comment

begin_comment
comment|/**        *  Returns a read/write iterator that points to the first pair in the        *  %multimap.  Iteration is done in ascending order according to the        *  keys.        */
end_comment

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|_M_t
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) iterator that points to the first pair        *  in the %multimap.  Iteration is done in ascending order according to        *  the keys.        */
end_comment

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|_M_t
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write iterator that points one past the last pair in        *  the %multimap.  Iteration is done in ascending order according to the        *  keys.        */
end_comment

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|_M_t
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) iterator that points one past the last        *  pair in the %multimap.  Iteration is done in ascending order according        *  to the keys.        */
end_comment

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|_M_t
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write reverse iterator that points to the last pair in        *  the %multimap.  Iteration is done in descending order according to the        *  keys.        */
end_comment

begin_function
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|_M_t
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) reverse iterator that points to the        *  last pair in the %multimap.  Iteration is done in descending order        *  according to the keys.        */
end_comment

begin_expr_stmt
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|_M_t
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write reverse iterator that points to one before the        *  first pair in the %multimap.  Iteration is done in descending order        *  according to the keys.        */
end_comment

begin_function
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|_M_t
operator|.
name|rend
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) reverse iterator that points to one        *  before the first pair in the %multimap.  Iteration is done in        *  descending order according to the keys.        */
end_comment

begin_expr_stmt
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|_M_t
operator|.
name|rend
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// capacity
end_comment

begin_comment
comment|/** Returns true if the %multimap is empty.  */
end_comment

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|_M_t
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/** Returns the size of the %multimap.  */
end_comment

begin_expr_stmt
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|_M_t
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/** Returns the maximum size of the %multimap.  */
end_comment

begin_expr_stmt
name|size_type
name|max_size
argument_list|()
specifier|const
block|{
return|return
name|_M_t
operator|.
name|max_size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// modifiers
end_comment

begin_comment
comment|/**        *  @brief Inserts a std::pair into the %multimap.        *  @param  x  Pair to be inserted (see std::make_pair for easy creation        *             of pairs).        *  @return An iterator that points to the inserted (key,value) pair.        *        *  This function inserts a (key, value) pair into the %multimap.        *  Contrary to a std::map the %multimap does not rely on unique keys and        *  thus multiple pairs with the same key can be inserted.        *        *  Insertion requires logarithmic time.        */
end_comment

begin_function
name|iterator
name|insert
parameter_list|(
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
return|return
name|_M_t
operator|.
name|_M_insert_equal
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief Inserts a std::pair into the %multimap.        *  @param  position  An iterator that serves as a hint as to where the        *                    pair should be inserted.        *  @param  x  Pair to be inserted (see std::make_pair for easy creation        *             of pairs).        *  @return An iterator that points to the inserted (key,value) pair.        *        *  This function inserts a (key, value) pair into the %multimap.        *  Contrary to a std::map the %multimap does not rely on unique keys and        *  thus multiple pairs with the same key can be inserted.        *  Note that the first parameter is only a hint and can potentially        *  improve the performance of the insertion process.  A bad hint would        *  cause no gains in efficiency.        *        *  See http://gcc.gnu.org/onlinedocs/libstdc++/23_containers/howto.html#4        *  for more on "hinting".        *        *  Insertion requires logarithmic time (if the hint is not taken).        */
end_comment

begin_function
name|iterator
name|insert
parameter_list|(
name|iterator
name|__position
parameter_list|,
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
return|return
name|_M_t
operator|.
name|_M_insert_equal
argument_list|(
name|__position
argument_list|,
name|__x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief A template function that attemps to insert a range of elements.        *  @param  first  Iterator pointing to the start of the range to be        *                 inserted.        *  @param  last  Iterator pointing to the end of the range.        *        *  Complexity similar to that of the range constructor.        */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|insert
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|)
block|{
name|_M_t
operator|.
name|_M_insert_equal
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|; }
comment|/**        *  @brief Erases an element from a %multimap.        *  @param  position  An iterator pointing to the element to be erased.        *        *  This function erases an element, pointed to by the given iterator,        *  from a %multimap.  Note that this function only erases the element,        *  and that if the element is itself a pointer, the pointed-to memory is        *  not touched in any way.  Managing the pointer is the user's        *  responsibilty.        */
name|void
name|erase
argument_list|(
argument|iterator __position
argument_list|)
block|{
name|_M_t
operator|.
name|erase
argument_list|(
name|__position
argument_list|)
block|; }
comment|/**        *  @brief Erases elements according to the provided key.        *  @param  x  Key of element to be erased.        *  @return  The number of elements erased.        *        *  This function erases all elements located by the given key from a        *  %multimap.        *  Note that this function only erases the element, and that if        *  the element is itself a pointer, the pointed-to memory is not touched        *  in any way.  Managing the pointer is the user's responsibilty.        */
name|size_type
name|erase
argument_list|(
argument|const key_type& __x
argument_list|)
block|{
return|return
name|_M_t
operator|.
name|erase
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief Erases a [first,last) range of elements from a %multimap.        *  @param  first  Iterator pointing to the start of the range to be        *                 erased.        *  @param  last  Iterator pointing to the end of the range to be erased.        *        *  This function erases a sequence of elements from a %multimap.        *  Note that this function only erases the elements, and that if        *  the elements themselves are pointers, the pointed-to memory is not        *  touched in any way.  Managing the pointer is the user's responsibilty.        */
end_comment

begin_function
name|void
name|erase
parameter_list|(
name|iterator
name|__first
parameter_list|,
name|iterator
name|__last
parameter_list|)
block|{
name|_M_t
operator|.
name|erase
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Swaps data with another %multimap.        *  @param  x  A %multimap of the same element and allocator types.        *        *  This exchanges the elements between two multimaps in constant time.        *  (It is only swapping a pointer, an integer, and an instance of        *  the @c Compare type (which itself is often stateless and empty), so it        *  should be quite fast.)        *  Note that the global std::swap() function is specialized such that        *  std::swap(m1,m2) will feed to this function.        */
end_comment

begin_function
name|void
name|swap
parameter_list|(
name|multimap
modifier|&
name|__x
parameter_list|)
block|{
name|_M_t
operator|.
name|swap
argument_list|(
name|__x
operator|.
name|_M_t
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  Erases all elements in a %multimap.  Note that this function only        *  erases the elements, and that if the elements themselves are pointers,        *  the pointed-to memory is not touched in any way.  Managing the pointer        *  is the user's responsibilty.        */
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|_M_t
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// observers
end_comment

begin_comment
comment|/**        *  Returns the key comparison object out of which the %multimap        *  was constructed.        */
end_comment

begin_expr_stmt
name|key_compare
name|key_comp
argument_list|()
specifier|const
block|{
return|return
name|_M_t
operator|.
name|key_comp
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a value comparison object, built from the key comparison        *  object out of which the %multimap was constructed.        */
end_comment

begin_expr_stmt
name|value_compare
name|value_comp
argument_list|()
specifier|const
block|{
return|return
name|value_compare
argument_list|(
name|_M_t
operator|.
name|key_comp
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// multimap operations
end_comment

begin_comment
comment|/**        *  @brief Tries to locate an element in a %multimap.        *  @param  x  Key of (key, value) pair to be located.        *  @return  Iterator pointing to sought-after element,        *           or end() if not found.        *        *  This function takes a key and tries to locate the element with which        *  the key matches.  If successful the function returns an iterator        *  pointing to the sought after %pair.  If unsuccessful it returns the        *  past-the-end ( @c end() ) iterator.        */
end_comment

begin_function
name|iterator
name|find
parameter_list|(
specifier|const
name|key_type
modifier|&
name|__x
parameter_list|)
block|{
return|return
name|_M_t
operator|.
name|find
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief Tries to locate an element in a %multimap.        *  @param  x  Key of (key, value) pair to be located.        *  @return  Read-only (constant) iterator pointing to sought-after        *           element, or end() if not found.        *        *  This function takes a key and tries to locate the element with which        *  the key matches.  If successful the function returns a constant        *  iterator pointing to the sought after %pair.  If unsuccessful it        *  returns the past-the-end ( @c end() ) iterator.        */
end_comment

begin_decl_stmt
name|const_iterator
name|find
argument_list|(
specifier|const
name|key_type
operator|&
name|__x
argument_list|)
decl|const
block|{
return|return
name|_M_t
operator|.
name|find
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief Finds the number of elements with given key.        *  @param  x  Key of (key, value) pairs to be located.        *  @return Number of elements with specified key.        */
end_comment

begin_decl_stmt
name|size_type
name|count
argument_list|(
specifier|const
name|key_type
operator|&
name|__x
argument_list|)
decl|const
block|{
return|return
name|_M_t
operator|.
name|count
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief Finds the beginning of a subsequence matching given key.        *  @param  x  Key of (key, value) pair to be located.        *  @return  Iterator pointing to first element equal to or greater        *           than key, or end().        *        *  This function returns the first element of a subsequence of elements        *  that matches the given key.  If unsuccessful it returns an iterator        *  pointing to the first element that has a greater value than given key        *  or end() if no such element exists.        */
end_comment

begin_function
name|iterator
name|lower_bound
parameter_list|(
specifier|const
name|key_type
modifier|&
name|__x
parameter_list|)
block|{
return|return
name|_M_t
operator|.
name|lower_bound
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief Finds the beginning of a subsequence matching given key.        *  @param  x  Key of (key, value) pair to be located.        *  @return  Read-only (constant) iterator pointing to first element        *           equal to or greater than key, or end().        *        *  This function returns the first element of a subsequence of elements        *  that matches the given key.  If unsuccessful the iterator will point        *  to the next greatest element or, if no such greater element exists, to        *  end().        */
end_comment

begin_decl_stmt
name|const_iterator
name|lower_bound
argument_list|(
specifier|const
name|key_type
operator|&
name|__x
argument_list|)
decl|const
block|{
return|return
name|_M_t
operator|.
name|lower_bound
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief Finds the end of a subsequence matching given key.        *  @param  x  Key of (key, value) pair to be located.        *  @return Iterator pointing to the first element        *          greater than key, or end().        */
end_comment

begin_function
name|iterator
name|upper_bound
parameter_list|(
specifier|const
name|key_type
modifier|&
name|__x
parameter_list|)
block|{
return|return
name|_M_t
operator|.
name|upper_bound
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief Finds the end of a subsequence matching given key.        *  @param  x  Key of (key, value) pair to be located.        *  @return  Read-only (constant) iterator pointing to first iterator        *           greater than key, or end().        */
end_comment

begin_decl_stmt
name|const_iterator
name|upper_bound
argument_list|(
specifier|const
name|key_type
operator|&
name|__x
argument_list|)
decl|const
block|{
return|return
name|_M_t
operator|.
name|upper_bound
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief Finds a subsequence matching given key.        *  @param  x  Key of (key, value) pairs to be located.        *  @return  Pair of iterators that possibly points to the subsequence        *           matching given key.        *        *  This function is equivalent to        *  @code        *    std::make_pair(c.lower_bound(val),        *                   c.upper_bound(val))        *  @endcode        *  (but is faster than making the calls separately).        */
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|iterator
operator|,
name|iterator
operator|>
name|equal_range
argument_list|(
argument|const key_type& __x
argument_list|)
block|{
return|return
name|_M_t
operator|.
name|equal_range
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief Finds a subsequence matching given key.        *  @param  x  Key of (key, value) pairs to be located.        *  @return  Pair of read-only (constant) iterators that possibly points        *           to the subsequence matching given key.        *        *  This function is equivalent to        *  @code        *    std::make_pair(c.lower_bound(val),        *                   c.upper_bound(val))        *  @endcode        *  (but is faster than making the calls separately).        */
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|const_iterator
operator|,
name|const_iterator
operator|>
name|equal_range
argument_list|(
argument|const key_type& __x
argument_list|)
specifier|const
block|{
return|return
name|_M_t
operator|.
name|equal_range
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_K1
operator|,
name|typename
name|_T1
operator|,
name|typename
name|_C1
operator|,
name|typename
name|_A1
operator|>
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|multimap
operator|<
name|_K1
operator|,
name|_T1
operator|,
name|_C1
operator|,
name|_A1
operator|>
operator|&
operator|,
specifier|const
name|multimap
operator|<
name|_K1
operator|,
name|_T1
operator|,
name|_C1
operator|,
name|_A1
operator|>
operator|&
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_K1
operator|,
name|typename
name|_T1
operator|,
name|typename
name|_C1
operator|,
name|typename
name|_A1
operator|>
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|multimap
operator|<
name|_K1
operator|,
name|_T1
operator|,
name|_C1
operator|,
name|_A1
operator|>
operator|&
operator|,
specifier|const
name|multimap
operator|<
name|_K1
operator|,
name|_T1
operator|,
name|_C1
operator|,
name|_A1
operator|>
operator|&
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief  Multimap equality comparison.    *  @param  x  A %multimap.    *  @param  y  A %multimap of the same type as @a x.    *  @return  True iff the size and elements of the maps are equal.    *    *  This is an equivalence relation.  It is linear in the size of the    *  multimaps.  Multimaps are considered equivalent if their sizes are equal,    *  and if corresponding elements compare equal.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Key
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
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
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|_M_t
operator|==
name|__y
operator|.
name|_M_t
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Multimap ordering relation.    *  @param  x  A %multimap.    *  @param  y  A %multimap of the same type as @a x.    *  @return  True iff @a x is lexicographically less than @a y.    *    *  This is a total ordering relation.  It is linear in the size of the    *  multimaps.  The elements must be comparable with @c<.    *    *  See std::lexicographical_compare() for how the determination is made.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Key
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
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
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|_M_t
operator|<
name|__y
operator|.
name|_M_t
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Based on operator==
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Key
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
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
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__x
operator|==
name|__y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Based on operator<
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Key
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
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
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__y
operator|<
name|__x
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Based on operator<
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Key
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
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
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__y
operator|<
name|__x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Based on operator<
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Key
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
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
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multimap
operator|<
name|_Key
operator|,
name|_Tp
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__x
operator|<
name|__y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// See std::multimap::swap().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Key
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|multimap<_Key
argument_list|,
argument|_Tp
argument_list|,
argument|_Compare
argument_list|,
argument|_Alloc>& __x
argument_list|,
argument|multimap<_Key
argument_list|,
argument|_Tp
argument_list|,
argument|_Compare
argument_list|,
argument|_Alloc>& __y
argument_list|)
block|{
name|__x
operator|.
name|swap
argument_list|(
name|__y
argument_list|)
block|; }
name|_GLIBCXX_END_NESTED_NAMESPACE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MULTIMAP_H */
end_comment

end_unit

