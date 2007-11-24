begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Multiset implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2004 Free Software Foundation, Inc.
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_multiset.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MULTISET_H
end_ifndef

begin_define
define|#
directive|define
name|_MULTISET_H
value|1
end_define

begin_include
include|#
directive|include
file|<bits/concept_check.h>
end_include

begin_decl_stmt
name|namespace
name|_GLIBCXX_STD
block|{
comment|// Forward declaration of operators< and ==, needed for friend declaration.
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|=
name|less
operator|<
name|_Key
operator|>
operator|,
name|class
name|_Alloc
operator|=
name|allocator
operator|<
name|_Key
operator|>
expr|>
name|class
name|multiset
expr_stmt|;
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
expr_stmt|;
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
expr_stmt|;
comment|/**    *  @brief A standard container made up of elements, which can be retrieved    *  in logarithmic time.    *    *  @ingroup Containers    *  @ingroup Assoc_containers    *    *  Meets the requirements of a<a href="tables.html#65">container</a>, a    *<a href="tables.html#66">reversible container</a>, and an    *<a href="tables.html#69">associative container</a> (using equivalent    *  keys).  For a @c multiset<Key> the key_type and value_type are Key.    *    *  Multisets support bidirectional iterators.    *    *  @if maint    *  The private tree data is declared exactly the same way for set and    *  multiset; the distinction is made entirely in how the tree functions are    *  called (*_unique versus *_equal, same as the standard).    *  @endif   */
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
name|class
name|multiset
block|{
comment|// concept requirements
name|__glibcxx_class_requires
argument_list|(
argument|_Key
argument_list|,
argument|_SGIAssignableConcept
argument_list|)
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
name|public
operator|:
comment|// typedefs:
typedef|typedef
name|_Key
name|key_type
typedef|;
typedef|typedef
name|_Key
name|value_type
typedef|;
typedef|typedef
name|_Compare
name|key_compare
typedef|;
typedef|typedef
name|_Compare
name|value_compare
typedef|;
name|private
label|:
comment|/// @if maint  This turns a red-black tree into a [multi]set.  @endif
typedef|typedef
name|_Rb_tree
operator|<
name|key_type
operator|,
name|value_type
operator|,
name|_Identity
operator|<
name|value_type
operator|>
operator|,
name|key_compare
operator|,
name|_Alloc
operator|>
name|_Rep_type
expr_stmt|;
comment|/// @if maint  The actual tree structure.  @endif
name|_Rep_type
name|_M_t
decl_stmt|;
name|public
label|:
typedef|typedef
name|typename
name|_Alloc
operator|::
name|pointer
name|pointer
expr_stmt|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|const_pointer
name|const_pointer
expr_stmt|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|reference
name|reference
expr_stmt|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|const_reference
name|const_reference
expr_stmt|;
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// DR 103. set::iterator is required to be modifiable,
comment|// but this allows modification of keys.
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|const_iterator
name|iterator
expr_stmt|;
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|const_reverse_iterator
name|reverse_iterator
expr_stmt|;
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|const_reverse_iterator
name|const_reverse_iterator
expr_stmt|;
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|size_type
name|size_type
expr_stmt|;
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|difference_type
name|difference_type
expr_stmt|;
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|allocator_type
name|allocator_type
expr_stmt|;
comment|// allocation/deallocation
comment|/**      *  @brief  Default constructor creates no elements.      */
name|multiset
argument_list|()
operator|:
name|_M_t
argument_list|(
argument|_Compare()
argument_list|,
argument|allocator_type()
argument_list|)
block|{ }
name|explicit
name|multiset
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
comment|/**        *  @brief  Builds a %multiset from a range.        *  @param  first  An input iterator.        *  @param  last  An input iterator.        *        *  Create a %multiset consisting of copies of the elements from        *  [first,last).  This is linear in N if the range is already sorted,        *  and NlogN otherwise (where N is distance(first,last)).        */
name|template
operator|<
name|class
name|_InputIterator
operator|>
name|multiset
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|)
operator|:
name|_M_t
argument_list|(
argument|_Compare()
argument_list|,
argument|allocator_type()
argument_list|)
block|{
name|_M_t
operator|.
name|insert_equal
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|; }
comment|/**        *  @brief  Builds a %multiset from a range.        *  @param  first  An input iterator.        *  @param  last  An input iterator.        *  @param  comp  A comparison functor.        *  @param  a  An allocator object.        *        *  Create a %multiset consisting of copies of the elements from        *  [first,last).  This is linear in N if the range is already sorted,        *  and NlogN otherwise (where N is distance(first,last)).        */
name|template
operator|<
name|class
name|_InputIterator
operator|>
name|multiset
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
name|insert_equal
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|; }
comment|/**        *  @brief  %Multiset copy constructor.        *  @param  x  A %multiset of identical element and allocator types.        *        *  The newly-created %multiset uses a copy of the allocation object used        *  by @a x.        */
name|multiset
argument_list|(
specifier|const
name|multiset
operator|<
name|_Key
argument_list|,
name|_Compare
argument_list|,
name|_Alloc
operator|>
operator|&
name|__x
argument_list|)
operator|:
name|_M_t
argument_list|(
argument|__x._M_t
argument_list|)
block|{ }
comment|/**        *  @brief  %Multiset assignment operator.        *  @param  x  A %multiset of identical element and allocator types.        *        *  All the elements of @a x are copied, but unlike the copy constructor,        *  the allocator object is not copied.        */
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
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
comment|// accessors:
comment|///  Returns the comparison object.
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
comment|///  Returns the comparison object.
name|value_compare
name|value_comp
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
comment|///  Returns the memory allocation object.
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
comment|/**        *  Returns a read/write iterator that points to the first element in the        *  %multiset.  Iteration is done in ascending order according to the        *  keys.        */
name|iterator
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
comment|/**        *  Returns a read/write iterator that points one past the last element in        *  the %multiset.  Iteration is done in ascending order according to the        *  keys.        */
name|iterator
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
comment|/**        *  Returns a read/write reverse iterator that points to the last element        *  in the %multiset.  Iteration is done in descending order according to        *  the keys.        */
name|reverse_iterator
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
comment|/**        *  Returns a read/write reverse iterator that points to the last element        *  in the %multiset.  Iteration is done in descending order according to        *  the keys.        */
name|reverse_iterator
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
comment|///  Returns true if the %set is empty.
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
comment|///  Returns the size of the %set.
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
comment|///  Returns the maximum size of the %set.
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
comment|/**        *  @brief  Swaps data with another %multiset.        *  @param  x  A %multiset of the same element and allocator types.        *        *  This exchanges the elements between two multisets in constant time.        *  (It is only swapping a pointer, an integer, and an instance of the @c        *  Compare type (which itself is often stateless and empty), so it should        *  be quite fast.)        *  Note that the global std::swap() function is specialized such that        *  std::swap(s1,s2) will feed to this function.        */
name|void
name|swap
argument_list|(
name|multiset
operator|<
name|_Key
argument_list|,
name|_Compare
argument_list|,
name|_Alloc
operator|>
operator|&
name|__x
argument_list|)
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
comment|// insert/erase
comment|/**        *  @brief Inserts an element into the %multiset.        *  @param  x  Element to be inserted.        *  @return An iterator that points to the inserted element.        *        *  This function inserts an element into the %multiset.  Contrary        *  to a std::set the %multiset does not rely on unique keys and thus        *  multiple copies of the same element can be inserted.        *        *  Insertion requires logarithmic time.        */
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
name|insert_equal
argument_list|(
name|__x
argument_list|)
return|;
block|}
comment|/**        *  @brief Inserts an element into the %multiset.        *  @param  position  An iterator that serves as a hint as to where the        *                    element should be inserted.        *  @param  x  Element to be inserted.        *  @return An iterator that points to the inserted element.        *        *  This function inserts an element into the %multiset.  Contrary        *  to a std::set the %multiset does not rely on unique keys and thus        *  multiple copies of the same element can be inserted.        *        *  Note that the first parameter is only a hint and can potentially        *  improve the performance of the insertion process.  A bad hint would        *  cause no gains in efficiency.        *        *  See http://gcc.gnu.org/onlinedocs/libstdc++/23_containers/howto.html#4        *  for more on "hinting".        *        *  Insertion requires logarithmic time (if the hint is not taken).        */
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
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|iterator
name|_Rep_iterator
expr_stmt|;
return|return
name|_M_t
operator|.
name|insert_equal
argument_list|(
operator|(
name|_Rep_iterator
operator|&
operator|)
name|__position
argument_list|,
name|__x
argument_list|)
return|;
block|}
comment|/**        *  @brief A template function that attemps to insert a range of elements.        *  @param  first  Iterator pointing to the start of the range to be        *                 inserted.        *  @param  last  Iterator pointing to the end of the range.        *        *  Complexity similar to that of the range constructor.        */
name|template
operator|<
name|class
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
name|insert_equal
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|; }
comment|/**        *  @brief Erases an element from a %multiset.        *  @param  position  An iterator pointing to the element to be erased.        *        *  This function erases an element, pointed to by the given iterator,        *  from a %multiset.  Note that this function only erases the element,        *  and that if the element is itself a pointer, the pointed-to memory is        *  not touched in any way.  Managing the pointer is the user's        *  responsibilty.        */
name|void
name|erase
argument_list|(
argument|iterator __position
argument_list|)
block|{
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|iterator
name|_Rep_iterator
expr_stmt|;
name|_M_t
operator|.
name|erase
argument_list|(
operator|(
name|_Rep_iterator
operator|&
operator|)
name|__position
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief Erases elements according to the provided key.        *  @param  x  Key of element to be erased.        *  @return  The number of elements erased.        *        *  This function erases all elements located by the given key from a        *  %multiset.        *  Note that this function only erases the element, and that if        *  the element is itself a pointer, the pointed-to memory is not touched        *  in any way.  Managing the pointer is the user's responsibilty.        */
end_comment

begin_function
name|size_type
name|erase
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
name|erase
argument_list|(
name|__x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief Erases a [first,last) range of elements from a %multiset.        *  @param  first  Iterator pointing to the start of the range to be        *                 erased.        *  @param  last  Iterator pointing to the end of the range to be erased.        *        *  This function erases a sequence of elements from a %multiset.        *  Note that this function only erases the elements, and that if        *  the elements themselves are pointers, the pointed-to memory is not        *  touched in any way.  Managing the pointer is the user's responsibilty.        */
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
typedef|typedef
name|typename
name|_Rep_type
operator|::
name|iterator
name|_Rep_iterator
expr_stmt|;
name|_M_t
operator|.
name|erase
argument_list|(
operator|(
name|_Rep_iterator
operator|&
operator|)
name|__first
argument_list|,
operator|(
name|_Rep_iterator
operator|&
operator|)
name|__last
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  Erases all elements in a %multiset.  Note that this function only        *  erases the elements, and that if the elements themselves are pointers,        *  the pointed-to memory is not touched in any way.  Managing the pointer        *  is the user's responsibilty.        */
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
comment|// multiset operations:
end_comment

begin_comment
comment|/**        *  @brief Finds the number of elements with given key.        *  @param  x  Key of elements to be located.        *  @return Number of elements with specified key.        */
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
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 214.  set::find() missing const overload
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief Tries to locate an element in a %set.        *  @param  x  Element to be located.        *  @return  Iterator pointing to sought-after element, or end() if not        *           found.        *        *  This function takes a key and tries to locate the element with which        *  the key matches.  If successful the function returns an iterator        *  pointing to the sought after element.  If unsuccessful it returns the        *  past-the-end ( @c end() ) iterator.        */
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
comment|//@}
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief Finds the beginning of a subsequence matching given key.        *  @param  x  Key to be located.        *  @return  Iterator pointing to first element equal to or greater        *           than key, or end().        *        *  This function returns the first element of a subsequence of elements        *  that matches the given key.  If unsuccessful it returns an iterator        *  pointing to the first element that has a greater value than given key        *  or end() if no such element exists.        */
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
comment|//@}
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief Finds the end of a subsequence matching given key.        *  @param  x  Key to be located.        *  @return Iterator pointing to the first element        *          greater than key, or end().        */
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
comment|//@}
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief Finds a subsequence matching given key.        *  @param  x  Key to be located.        *  @return  Pair of iterators that possibly points to the subsequence        *           matching given key.        *        *  This function is equivalent to        *  @code        *    std::make_pair(c.lower_bound(val),        *                   c.upper_bound(val))        *  @endcode        *  (but is faster than making the calls separately).        *        *  This function probably only makes sense for multisets.        */
end_comment

begin_expr_stmt
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

begin_expr_stmt
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
name|class
name|_K1
operator|,
name|class
name|_C1
operator|,
name|class
name|_A1
operator|>
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|multiset
operator|<
name|_K1
operator|,
name|_C1
operator|,
name|_A1
operator|>
operator|&
operator|,
specifier|const
name|multiset
operator|<
name|_K1
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
name|class
name|_K1
operator|,
name|class
name|_C1
operator|,
name|class
name|_A1
operator|>
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|multiset
operator|<
name|_K1
operator|,
name|_C1
operator|,
name|_A1
operator|>
operator|&
operator|,
specifier|const
name|multiset
operator|<
name|_K1
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
comment|/**    *  @brief  Multiset equality comparison.    *  @param  x  A %multiset.    *  @param  y  A %multiset of the same type as @a x.    *  @return  True iff the size and elements of the multisets are equal.    *    *  This is an equivalence relation.  It is linear in the size of the    *  multisets.    *  Multisets are considered equivalent if their sizes are equal, and if    *  corresponding elements compare equal.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multiset
operator|<
name|_Key
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
comment|/**    *  @brief  Multiset ordering relation.    *  @param  x  A %multiset.    *  @param  y  A %multiset of the same type as @a x.    *  @return  True iff @a x is lexicographically less than @a y.    *    *  This is a total ordering relation.  It is linear in the size of the    *  maps.  The elements must be comparable with @c<.    *    *  See std::lexicographical_compare() for how the determination is made.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multiset
operator|<
name|_Key
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
comment|///  Returns !(x == y).
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multiset
operator|<
name|_Key
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
comment|///  Returns y< x.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multiset
operator|<
name|_Key
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
comment|///  Returns !(y< x)
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multiset
operator|<
name|_Key
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
comment|///  Returns !(x< y)
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|multiset
operator|<
name|_Key
operator|,
name|_Compare
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|multiset
operator|<
name|_Key
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
comment|/// See std::multiset::swap().
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Key
operator|,
name|class
name|_Compare
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|multiset<_Key
argument_list|,
argument|_Compare
argument_list|,
argument|_Alloc>& __x
argument_list|,
argument|multiset<_Key
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
end_expr_stmt

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MULTISET_H */
end_comment

end_unit

