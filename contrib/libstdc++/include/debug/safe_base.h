begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Safe sequence/iterator base implementation  -*- C++ -*-
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
name|_GLIBCXX_DEBUG_SAFE_BASE_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_SAFE_BASE_H
value|1
end_define

begin_decl_stmt
name|namespace
name|__gnu_debug
block|{
name|class
name|_Safe_sequence_base
decl_stmt|;
comment|/** \brief Basic functionality for a "safe" iterator.    *    *  The %_Safe_iterator_base base class implements the functionality    *  of a safe iterator that is not specific to a particular iterator    *  type. It contains a pointer back to the sequence it references    *  along with iterator version information and pointers to form a    *  doubly-linked list of iterators referenced by the container.    *    *  This class must not perform any operations that can throw an    *  exception, or the exception guarantees of derived iterators will    *  be broken.    */
name|class
name|_Safe_iterator_base
block|{
name|public
label|:
comment|/** The sequence this iterator references; may be NULL to indicate 	a singular iterator. */
name|_Safe_sequence_base
modifier|*
name|_M_sequence
decl_stmt|;
comment|/** The version number of this iterator. The sentinel value 0 is      *  used to indicate an invalidated iterator (i.e., one that is      *  singular because of an operation on the container). This      *  version number must equal the version number in the sequence      *  referenced by _M_sequence for the iterator to be      *  non-singular.      */
name|unsigned
name|int
name|_M_version
decl_stmt|;
comment|/** Pointer to the previous iterator in the sequence's list of 	iterators. Only valid when _M_sequence != NULL. */
name|_Safe_iterator_base
modifier|*
name|_M_prior
decl_stmt|;
comment|/** Pointer to the next iterator in the sequence's list of 	iterators. Only valid when _M_sequence != NULL. */
name|_Safe_iterator_base
modifier|*
name|_M_next
decl_stmt|;
name|protected
label|:
comment|/** Initializes the iterator and makes it singular. */
name|_Safe_iterator_base
argument_list|()
operator|:
name|_M_sequence
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_version
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_prior
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_next
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/** Initialize the iterator to reference the sequence pointed to      *  by @p__seq. @p __constant is true when we are initializing a      *  constant iterator, and false if it is a mutable iterator. Note      *  that @p __seq may be NULL, in which case the iterator will be      *  singular. Otherwise, the iterator will reference @p __seq and      *  be nonsingular.      */
name|_Safe_iterator_base
argument_list|(
argument|const _Safe_sequence_base* __seq
argument_list|,
argument|bool __constant
argument_list|)
operator|:
name|_M_sequence
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_version
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_prior
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_next
argument_list|(
literal|0
argument_list|)
block|{
name|this
operator|->
name|_M_attach
argument_list|(
name|const_cast
operator|<
name|_Safe_sequence_base
operator|*
operator|>
operator|(
name|__seq
operator|)
argument_list|,
name|__constant
argument_list|)
block|; }
comment|/** Initializes the iterator to reference the same sequence that 	@p __x does. @p __constant is true if this is a constant 	iterator, and false if it is mutable. */
name|_Safe_iterator_base
argument_list|(
argument|const _Safe_iterator_base& __x
argument_list|,
argument|bool __constant
argument_list|)
operator|:
name|_M_sequence
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_version
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_prior
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_next
argument_list|(
literal|0
argument_list|)
block|{
name|this
operator|->
name|_M_attach
argument_list|(
name|__x
operator|.
name|_M_sequence
argument_list|,
name|__constant
argument_list|)
block|; }
name|_Safe_iterator_base
operator|&
name|operator
operator|=
operator|(
specifier|const
name|_Safe_iterator_base
operator|&
operator|)
expr_stmt|;
name|explicit
name|_Safe_iterator_base
parameter_list|(
specifier|const
name|_Safe_iterator_base
modifier|&
parameter_list|)
function_decl|;
operator|~
name|_Safe_iterator_base
argument_list|()
block|{
name|this
operator|->
name|_M_detach
argument_list|()
block|; }
name|public
operator|:
comment|/** Attaches this iterator to the given sequence, detaching it      *	from whatever sequence it was attached to originally. If the      *	new sequence is the NULL pointer, the iterator is left      *	unattached.      */
name|void
name|_M_attach
argument_list|(
argument|_Safe_sequence_base* __seq
argument_list|,
argument|bool __constant
argument_list|)
expr_stmt|;
comment|/** Detach the iterator for whatever sequence it is attached to,      *	if any.     */
name|void
name|_M_detach
parameter_list|()
function_decl|;
comment|/** Determines if we are attached to the given sequence. */
name|bool
name|_M_attached_to
argument_list|(
specifier|const
name|_Safe_sequence_base
operator|*
name|__seq
argument_list|)
decl|const
block|{
return|return
name|_M_sequence
operator|==
name|__seq
return|;
block|}
comment|/** Is this iterator singular? */
name|bool
name|_M_singular
argument_list|()
specifier|const
expr_stmt|;
comment|/** Can we compare this iterator to the given iterator @p __x? 	Returns true if both iterators are nonsingular and reference 	the same sequence. */
name|bool
name|_M_can_compare
argument_list|(
specifier|const
name|_Safe_iterator_base
operator|&
name|__x
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/**    * @brief Base class that supports tracking of iterators that    * reference a sequence.    *    * The %_Safe_sequence_base class provides basic support for    * tracking iterators into a sequence. Sequences that track    * iterators must derived from %_Safe_sequence_base publicly, so    * that safe iterators (which inherit _Safe_iterator_base) can    * attach to them. This class contains two linked lists of    * iterators, one for constant iterators and one for mutable    * iterators, and a version number that allows very fast    * invalidation of all iterators that reference the container.    *    * This class must ensure that no operation on it may throw an    * exception, otherwise "safe" sequences may fail to provide the    * exception-safety guarantees required by the C++ standard.    */
name|class
name|_Safe_sequence_base
block|{
name|public
label|:
comment|/// The list of mutable iterators that reference this container
name|_Safe_iterator_base
modifier|*
name|_M_iterators
decl_stmt|;
comment|/// The list of constant iterators that reference this container
name|_Safe_iterator_base
modifier|*
name|_M_const_iterators
decl_stmt|;
comment|/// The container version number. This number may never be 0.
name|mutable
name|unsigned
name|int
name|_M_version
decl_stmt|;
name|protected
label|:
comment|// Initialize with a version number of 1 and no iterators
name|_Safe_sequence_base
argument_list|()
operator|:
name|_M_iterators
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_const_iterators
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_version
argument_list|(
literal|1
argument_list|)
block|{ }
comment|/** Notify all iterators that reference this sequence that the 	sequence is being destroyed. */
operator|~
name|_Safe_sequence_base
argument_list|()
block|{
name|this
operator|->
name|_M_detach_all
argument_list|()
block|; }
comment|/** Detach all iterators, leaving them singular. */
name|void
name|_M_detach_all
argument_list|()
expr_stmt|;
comment|/** Detach all singular iterators.      *  @post for all iterators i attached to this sequence,      *   i->_M_version == _M_version.      */
name|void
name|_M_detach_singular
parameter_list|()
function_decl|;
comment|/** Revalidates all attached singular iterators.  This method may      *  be used to validate iterators that were invalidated before      *  (but for some reasion, such as an exception, need to become      *  valid again).      */
name|void
name|_M_revalidate_singular
parameter_list|()
function_decl|;
comment|/** Swap this sequence with the given sequence. This operation      *  also swaps ownership of the iterators, so that when the      *  operation is complete all iterators that originally referenced      *  one container now reference the other container.      */
name|void
name|_M_swap
parameter_list|(
name|_Safe_sequence_base
modifier|&
name|__x
parameter_list|)
function_decl|;
name|public
label|:
comment|/** Invalidates all iterators. */
name|void
name|_M_invalidate_all
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|++
name|_M_version
operator|==
literal|0
condition|)
name|_M_version
operator|=
literal|1
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __gnu_debug
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

