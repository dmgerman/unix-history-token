begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Safe sequence implementation  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2003, 2004
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

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_DEBUG_SAFE_SEQUENCE_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_SAFE_SEQUENCE_H
value|1
end_define

begin_include
include|#
directive|include
file|<debug/debug.h>
end_include

begin_include
include|#
directive|include
file|<debug/safe_base.h>
end_include

begin_decl_stmt
name|namespace
name|__gnu_debug
block|{
name|template
operator|<
name|typename
name|_Iterator
operator|,
name|typename
name|_Sequence
operator|>
name|class
name|_Safe_iterator
expr_stmt|;
comment|/** A simple function object that returns true if the passed-in    *  value is not equal to the stored value. It saves typing over    *  using both bind1st and not_equal.    */
name|template
operator|<
name|typename
name|_Type
operator|>
name|class
name|_Not_equal_to
block|{
name|_Type
name|__value
block|;
name|public
operator|:
name|explicit
name|_Not_equal_to
argument_list|(
specifier|const
name|_Type
operator|&
name|__v
argument_list|)
operator|:
name|__value
argument_list|(
argument|__v
argument_list|)
block|{ }
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|_Type
operator|&
name|__x
operator|)
specifier|const
block|{
return|return
name|__value
operator|!=
name|__x
return|;
block|}
expr|}
block|;
comment|/** A function object that returns true when the given random access       iterator is at least @c n steps away from the given iterator. */
name|template
operator|<
name|typename
name|_Iterator
operator|>
name|class
name|_After_nth_from
block|{
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|_Iterator
operator|>
operator|::
name|difference_type
name|difference_type
expr_stmt|;
name|_Iterator
name|_M_base
block|;
name|difference_type
name|_M_n
block|;
name|public
operator|:
name|_After_nth_from
argument_list|(
specifier|const
name|difference_type
operator|&
name|__n
argument_list|,
specifier|const
name|_Iterator
operator|&
name|__base
argument_list|)
operator|:
name|_M_base
argument_list|(
name|__base
argument_list|)
block|,
name|_M_n
argument_list|(
argument|__n
argument_list|)
block|{ }
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|_Iterator
operator|&
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
operator|-
name|_M_base
operator|>=
name|_M_n
return|;
block|}
expr|}
block|;
comment|/**    * @brief Base class for constructing a "safe" sequence type that    * tracks iterators that reference it.    *    * The class template %_Safe_sequence simplifies the construction of    * "safe" sequences that track the iterators that reference the    * sequence, so that the iterators are notified of changes in the    * sequence that may affect their operation, e.g., if the container    * invalidates its iterators or is destructed. This class template    * may only be used by deriving from it and passing the name of the    * derived class as its template parameter via the curiously    * recurring template pattern. The derived class must have @c    * iterator and @const_iterator types that are instantiations of    * class template _Safe_iterator for this sequence. Iterators will    * then be tracked automatically.    */
name|template
operator|<
name|typename
name|_Sequence
operator|>
name|class
name|_Safe_sequence
operator|:
name|public
name|_Safe_sequence_base
block|{
name|public
operator|:
comment|/** Invalidates all iterators @c x that reference this sequence, 	  are not singular, and for which @c pred(x) returns @c 	  true. The user of this routine should be careful not to make 	  copies of the iterators passed to @p pred, as the copies may 	  interfere with the invalidation. */
name|template
operator|<
name|typename
name|_Predicate
operator|>
name|void
name|_M_invalidate_if
argument_list|(
argument|_Predicate __pred
argument_list|)
block|;
comment|/** Transfers all iterators that reference this memory location 	  to this sequence from whatever sequence they are attached 	  to. */
name|template
operator|<
name|typename
name|_Iterator
operator|>
name|void
name|_M_transfer_iter
argument_list|(
specifier|const
name|_Safe_iterator
operator|<
name|_Iterator
argument_list|,
name|_Sequence
operator|>
operator|&
name|__x
argument_list|)
block|;     }
block|;
name|template
operator|<
name|typename
name|_Sequence
operator|>
name|template
operator|<
name|typename
name|_Predicate
operator|>
name|void
name|_Safe_sequence
operator|<
name|_Sequence
operator|>
operator|::
name|_M_invalidate_if
argument_list|(
argument|_Predicate __pred
argument_list|)
block|{
typedef|typedef
name|typename
name|_Sequence
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|typename
name|_Sequence
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
for|for
control|(
name|_Safe_iterator_base
modifier|*
name|__iter
init|=
name|_M_iterators
init|;
name|__iter
condition|;
control|)
block|{
name|iterator
modifier|*
name|__victim
init|=
name|static_cast
operator|<
name|iterator
operator|*
operator|>
operator|(
name|__iter
operator|)
decl_stmt|;
name|__iter
operator|=
name|__iter
operator|->
name|_M_next
expr_stmt|;
if|if
condition|(
operator|!
name|__victim
operator|->
name|_M_singular
argument_list|()
condition|)
block|{
if|if
condition|(
name|__pred
argument_list|(
name|__victim
operator|->
name|base
argument_list|()
argument_list|)
condition|)
name|__victim
operator|->
name|_M_invalidate
argument_list|()
expr_stmt|;
block|}
block|}
for|for
control|(
name|_Safe_iterator_base
modifier|*
name|__iter2
init|=
name|_M_const_iterators
init|;
name|__iter2
condition|;
control|)
block|{
name|const_iterator
modifier|*
name|__victim
init|=
name|static_cast
operator|<
name|const_iterator
operator|*
operator|>
operator|(
name|__iter2
operator|)
decl_stmt|;
name|__iter2
operator|=
name|__iter2
operator|->
name|_M_next
expr_stmt|;
if|if
condition|(
operator|!
name|__victim
operator|->
name|_M_singular
argument_list|()
condition|)
block|{
if|if
condition|(
name|__pred
argument_list|(
name|__victim
operator|->
name|base
argument_list|()
argument_list|)
condition|)
name|__victim
operator|->
name|_M_invalidate
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Sequence
operator|>
name|template
operator|<
name|typename
name|_Iterator
operator|>
name|void
name|_Safe_sequence
operator|<
name|_Sequence
operator|>
operator|::
name|_M_transfer_iter
argument_list|(
argument|const _Safe_iterator<_Iterator
argument_list|,
argument|_Sequence>& __x
argument_list|)
block|{
name|_Safe_sequence_base
operator|*
name|__from
operator|=
name|__x
operator|.
name|_M_sequence
block|;
if|if
condition|(
operator|!
name|__from
condition|)
return|return;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|_Sequence
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Sequence
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_for
for|for
control|(
name|_Safe_iterator_base
modifier|*
name|__iter
init|=
name|__from
operator|->
name|_M_iterators
init|;
name|__iter
condition|;
control|)
block|{
name|iterator
modifier|*
name|__victim
init|=
name|static_cast
operator|<
name|iterator
operator|*
operator|>
operator|(
name|__iter
operator|)
decl_stmt|;
name|__iter
operator|=
name|__iter
operator|->
name|_M_next
expr_stmt|;
if|if
condition|(
operator|!
name|__victim
operator|->
name|_M_singular
argument_list|()
operator|&&
name|__victim
operator|->
name|base
argument_list|()
operator|==
name|__x
operator|.
name|base
argument_list|()
condition|)
name|__victim
operator|->
name|_M_attach
argument_list|(
name|static_cast
operator|<
name|_Sequence
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|_Safe_iterator_base
modifier|*
name|__iter2
init|=
name|__from
operator|->
name|_M_const_iterators
init|;
name|__iter2
condition|;
control|)
block|{
name|const_iterator
modifier|*
name|__victim
init|=
name|static_cast
operator|<
name|const_iterator
operator|*
operator|>
operator|(
name|__iter2
operator|)
decl_stmt|;
name|__iter2
operator|=
name|__iter2
operator|->
name|_M_next
expr_stmt|;
if|if
condition|(
operator|!
name|__victim
operator|->
name|_M_singular
argument_list|()
operator|&&
name|__victim
operator|->
name|base
argument_list|()
operator|==
name|__x
operator|.
name|base
argument_list|()
condition|)
name|__victim
operator|->
name|_M_attach
argument_list|(
name|static_cast
operator|<
name|_Sequence
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
unit|} }
comment|// namespace __gnu_debug
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

