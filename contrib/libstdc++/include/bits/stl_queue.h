begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Queue implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002 Free Software Foundation, Inc.
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_queue.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GLIBCPP_INTERNAL_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|__GLIBCPP_INTERNAL_QUEUE_H
end_define

begin_include
include|#
directive|include
file|<bits/concept_check.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// Forward declarations of operators< and ==, needed for friend declaration.
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Sequence
operator|=
name|deque
operator|<
name|_Tp
operator|>
expr|>
name|class
name|queue
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Seq
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
operator|,
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
operator|)
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Seq
operator|>
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
operator|,
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Seq
operator|>
operator|&
operator|)
expr_stmt|;
comment|/**    *  @brief  A standard container giving FIFO behavior.    *    *  @ingroup Containers    *  @ingroup Sequences    *    *  Meets many of the requirements of a    *<a href="tables.html#65">container</a>,    *  but does not define anything to do with iterators.  Very few of the    *  other standard container interfaces are defined.    *    *  This is not a true container, but an @e adaptor.  It holds another    *  container, and provides a wrapper interface to that container.  The    *  wrapper is what enforces strict first-in-first-out %queue behavior.    *    *  The second template parameter defines the type of the underlying    *  sequence/container.  It defaults to std::deque, but it can be any type    *  that supports @c front, @c back, @c push_back, and @c pop_front,    *  such as std::list or an appropriate user-defined type.    *    *  Members not found in "normal" containers are @c container_type,    *  which is a typedef for the second Sequence parameter, and @c push and    *  @c pop, which are standard %queue/FIFO operations.   */
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Sequence
operator|>
name|class
name|queue
block|{
comment|// concept requirements
typedef|typedef
name|typename
name|_Sequence
operator|::
name|value_type
name|_Sequence_value_type
expr_stmt|;
name|__glibcpp_class_requires
argument_list|(
argument|_Tp
argument_list|,
argument|_SGIAssignableConcept
argument_list|)
name|__glibcpp_class_requires
argument_list|(
argument|_Sequence
argument_list|,
argument|_FrontInsertionSequenceConcept
argument_list|)
name|__glibcpp_class_requires
argument_list|(
argument|_Sequence
argument_list|,
argument|_BackInsertionSequenceConcept
argument_list|)
name|__glibcpp_class_requires2
argument_list|(
argument|_Tp
argument_list|,
argument|_Sequence_value_type
argument_list|,
argument|_SameTypeConcept
argument_list|)
name|template
operator|<
name|typename
name|_Tp1
operator|,
name|typename
name|_Seq1
operator|>
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|queue
operator|<
name|_Tp1
operator|,
name|_Seq1
operator|>
operator|&
operator|,
specifier|const
name|queue
operator|<
name|_Tp1
operator|,
name|_Seq1
operator|>
operator|&
operator|)
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp1
operator|,
name|typename
name|_Seq1
operator|>
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|queue
operator|<
name|_Tp1
operator|,
name|_Seq1
operator|>
operator|&
operator|,
specifier|const
name|queue
operator|<
name|_Tp1
operator|,
name|_Seq1
operator|>
operator|&
operator|)
expr_stmt|;
name|public
label|:
typedef|typedef
name|typename
name|_Sequence
operator|::
name|value_type
name|value_type
expr_stmt|;
typedef|typedef
name|typename
name|_Sequence
operator|::
name|reference
name|reference
expr_stmt|;
typedef|typedef
name|typename
name|_Sequence
operator|::
name|const_reference
name|const_reference
expr_stmt|;
typedef|typedef
name|typename
name|_Sequence
operator|::
name|size_type
name|size_type
expr_stmt|;
typedef|typedef
name|_Sequence
name|container_type
typedef|;
name|protected
label|:
comment|/**      *  'c' is the underlying container.  Maintainers wondering why this isn't      *  uglified as per style guidelines should note that this name is      *  specified in the standard, [23.2.3.1].  (Why?  Presumably for the same      *  reason that it's protected instead of private:  to allow derivation.      *  But none of the other containers allow for derivation.  Odd.)     */
name|_Sequence
name|c
decl_stmt|;
name|public
label|:
comment|/**      *  @brief  Default constructor creates no elements.     */
name|explicit
name|queue
argument_list|(
specifier|const
name|_Sequence
operator|&
name|__c
operator|=
name|_Sequence
argument_list|()
argument_list|)
operator|:
name|c
argument_list|(
argument|__c
argument_list|)
block|{}
comment|/**      *  Returns true if the %queue is empty.     */
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/**  Returns the number of elements in the %queue.  */
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|size
argument_list|()
return|;
block|}
comment|/**      *  Returns a read/write reference to the data at the first element of the      *  %queue.     */
name|reference
name|front
parameter_list|()
block|{
return|return
name|c
operator|.
name|front
argument_list|()
return|;
block|}
comment|/**      *  Returns a read-only (constant) reference to the data at the first      *  element of the %queue.     */
name|const_reference
name|front
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|front
argument_list|()
return|;
block|}
comment|/**      *  Returns a read/write reference to the data at the last element of the      *  %queue.     */
name|reference
name|back
parameter_list|()
block|{
return|return
name|c
operator|.
name|back
argument_list|()
return|;
block|}
comment|/**      *  Returns a read-only (constant) reference to the data at the last      *  element of the %queue.     */
name|const_reference
name|back
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|back
argument_list|()
return|;
block|}
comment|/**      *  @brief  Add data to the end of the %queue.      *  @param  x  Data to be added.      *      *  This is a typical %queue operation.  The function creates an element at      *  the end of the %queue and assigns the given data to it.      *  The time complexity of the operation depends on the underlying      *  sequence.     */
name|void
name|push
parameter_list|(
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
name|c
operator|.
name|push_back
argument_list|(
name|__x
argument_list|)
expr_stmt|;
block|}
comment|/**      *  @brief  Removes first element.      *      *  This is a typical %queue operation.  It shrinks the %queue by one.      *  The time complexity of the operation depends on the underlying      *  sequence.      *      *  Note that no data is returned, and if the first element's data is      *  needed, it should be retrieved before pop() is called.     */
name|void
name|pop
parameter_list|()
block|{
name|c
operator|.
name|pop_front
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**    *  @brief  Queue equality comparison.    *  @param  x  A %queue.    *  @param  y  A %queue of the same type as @a x.    *  @return  True iff the size and elements of the queues are equal.    *    *  This is an equivalence relation.  Complexity and semantics depend on the    *  underlying sequence type, but the expected rules are:  this relation is    *  linear in the size of the sequences, and queues are considered equivalent    *  if their sequences compare equal.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Sequence
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
operator|>
operator|&
name|__x
operator|,
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|c
operator|==
name|__y
operator|.
name|c
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Queue ordering relation.    *  @param  x  A %queue.    *  @param  y  A %queue of the same type as @a x.    *  @return  True iff @a x is lexographically less than @a y.    *    *  This is an total ordering relation.  Complexity and semantics depend on    *  the underlying sequence type, but the expected rules are:  this relation    *  is linear in the size of the sequences, the elements must be comparable    *  with @c<, and std::lexographical_compare() is usually used to make the    *  determination.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Sequence
operator|>
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
operator|>
operator|&
name|__x
operator|,
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|c
operator|<
name|__y
operator|.
name|c
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
name|_Tp
operator|,
name|typename
name|_Sequence
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
operator|>
operator|&
name|__x
operator|,
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
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
name|_Tp
operator|,
name|typename
name|_Sequence
operator|>
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
operator|>
operator|&
name|__x
operator|,
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
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
name|_Tp
operator|,
name|typename
name|_Sequence
operator|>
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
operator|>
operator|&
name|__x
operator|,
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
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
name|_Tp
operator|,
name|typename
name|_Sequence
operator|>
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
operator|>
operator|&
name|__x
operator|,
specifier|const
name|queue
operator|<
name|_Tp
operator|,
name|_Sequence
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
comment|/**    *  @brief  A standard container automatically sorting its contents.    *    *  @ingroup Containers    *  @ingroup Sequences    *    *  This is not a true container, but an @e adaptor.  It holds another    *  container, and provides a wrapper interface to that container.  The    *  wrapper is what enforces sorting and first-in-first-out %queue behavior.    *  Very few of the standard container/sequence interface requirements are    *  met (e.g., iterators).    *    *  The second template parameter defines the type of the underlying    *  sequence/container.  It defaults to std::vector, but it can be any type    *  that supports @c front(), @c push_back, @c pop_back, and random-access    *  iterators, such as std::deque or an appropriate user-defined type.    *    *  The third template parameter supplies the means of making priority    *  comparisons.  It defaults to @c less<value_type> but can be anything    *  defining a strict weak ordering.    *    *  Members not found in "normal" containers are @c container_type,    *  which is a typedef for the second Sequence parameter, and @c push,    *  @c pop, and @c top, which are standard %queue/FIFO operations.    *    *  @note  No equality/comparison operators are provided for %priority_queue.    *    *  @note  Sorting of the elements takes place as they are added to, and    *         removed from, the %priority_queue using the %priority_queue's    *         member functions.  If you access the elements by other means, and    *         change their data such that the sorting order would be different,    *         the %priority_queue will not re-sort the elements for you.  (How    *         could it know to do so?)   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Sequence
operator|=
name|vector
operator|<
name|_Tp
operator|>
operator|,
name|typename
name|_Compare
operator|=
name|less
operator|<
name|typename
name|_Sequence
operator|::
name|value_type
operator|>
expr|>
name|class
name|priority_queue
block|{
comment|// concept requirements
typedef|typedef
name|typename
name|_Sequence
operator|::
name|value_type
name|_Sequence_value_type
expr_stmt|;
name|__glibcpp_class_requires
argument_list|(
argument|_Tp
argument_list|,
argument|_SGIAssignableConcept
argument_list|)
name|__glibcpp_class_requires
argument_list|(
argument|_Sequence
argument_list|,
argument|_SequenceConcept
argument_list|)
name|__glibcpp_class_requires
argument_list|(
argument|_Sequence
argument_list|,
argument|_RandomAccessContainerConcept
argument_list|)
name|__glibcpp_class_requires2
argument_list|(
argument|_Tp
argument_list|,
argument|_Sequence_value_type
argument_list|,
argument|_SameTypeConcept
argument_list|)
name|__glibcpp_class_requires4
argument_list|(
argument|_Compare
argument_list|,
argument|bool
argument_list|,
argument|_Tp
argument_list|,
argument|_Tp
argument_list|,
argument|_BinaryFunctionConcept
argument_list|)
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|_Sequence
operator|::
name|value_type
name|value_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Sequence
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Sequence
operator|::
name|const_reference
name|const_reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Sequence
operator|::
name|size_type
name|size_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|_Sequence
name|container_type
typedef|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_comment
comment|//  See queue::c for notes on these names.
end_comment

begin_decl_stmt
name|_Sequence
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_Compare
name|comp
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/**      *  @brief  Default constructor creates no elements.     */
end_comment

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|priority_queue
argument_list|(
specifier|const
name|_Compare
operator|&
name|__x
operator|=
name|_Compare
argument_list|()
argument_list|,
specifier|const
name|_Sequence
operator|&
name|__s
operator|=
name|_Sequence
argument_list|()
argument_list|)
operator|:
name|c
argument_list|(
name|__s
argument_list|)
operator|,
name|comp
argument_list|(
argument|__x
argument_list|)
block|{
name|make_heap
argument_list|(
name|c
operator|.
name|begin
argument_list|()
argument_list|,
name|c
operator|.
name|end
argument_list|()
argument_list|,
name|comp
argument_list|)
block|; }
comment|/**      *  @brief  Builds a %queue from a range.      *  @param  first  An input iterator.      *  @param  last  An input iterator.      *  @param  x  A comparison functor describing a strict weak ordering.      *  @param  s  An initial sequence with which to start.      *       *  Begins by copying @a s, inserting a copy of the elements from      *  @a [first,last) into the copy of @a s, then ordering the copy      *  according to @a x.      *      *  For more information on function objects, see the documentation on      *  @link s20_3_1_base functor base classes@endlink.     */
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|priority_queue
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|const _Compare& __x = _Compare()
argument_list|,
argument|const _Sequence& __s = _Sequence()
argument_list|)
operator|:
name|c
argument_list|(
name|__s
argument_list|)
operator|,
name|comp
argument_list|(
argument|__x
argument_list|)
block|{
name|c
operator|.
name|insert
argument_list|(
name|c
operator|.
name|end
argument_list|()
argument_list|,
name|__first
argument_list|,
name|__last
argument_list|)
block|;
name|make_heap
argument_list|(
name|c
operator|.
name|begin
argument_list|()
argument_list|,
name|c
operator|.
name|end
argument_list|()
argument_list|,
name|comp
argument_list|)
block|;       }
comment|/**      *  Returns true if the %queue is empty.     */
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**  Returns the number of elements in the %queue.  */
end_comment

begin_expr_stmt
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**      *  Returns a read-only (constant) reference to the data at the first      *  element of the %queue.     */
end_comment

begin_expr_stmt
name|const_reference
name|top
argument_list|()
specifier|const
block|{
return|return
name|c
operator|.
name|front
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**      *  @brief  Add data to the %queue.      *  @param  x  Data to be added.      *      *  This is a typical %queue operation.      *  The time complexity of the operation depends on the underlying      *  sequence.     */
end_comment

begin_function
name|void
name|push
parameter_list|(
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
name|try
block|{
name|c
operator|.
name|push_back
argument_list|(
name|__x
argument_list|)
expr_stmt|;
name|push_heap
argument_list|(
name|c
operator|.
name|begin
argument_list|()
argument_list|,
name|c
operator|.
name|end
argument_list|()
argument_list|,
name|comp
argument_list|)
expr_stmt|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|c
operator|.
name|clear
argument_list|()
expr_stmt|;
name|__throw_exception_again
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/**      *  @brief  Removes first element.      *      *  This is a typical %queue operation.  It shrinks the %queue by one.      *  The time complexity of the operation depends on the underlying      *  sequence.      *      *  Note that no data is returned, and if the first element's data is      *  needed, it should be retrieved before pop() is called.     */
end_comment

begin_function
name|void
name|pop
parameter_list|()
block|{
name|try
block|{
name|pop_heap
argument_list|(
name|c
operator|.
name|begin
argument_list|()
argument_list|,
name|c
operator|.
name|end
argument_list|()
argument_list|,
name|comp
argument_list|)
expr_stmt|;
name|c
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|c
operator|.
name|clear
argument_list|()
expr_stmt|;
name|__throw_exception_again
expr_stmt|;
block|}
block|}
end_function

begin_comment
unit|};
comment|// No equality/comparison operators are provided for priority_queue.
end_comment

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GLIBCPP_INTERNAL_QUEUE_H */
end_comment

end_unit

