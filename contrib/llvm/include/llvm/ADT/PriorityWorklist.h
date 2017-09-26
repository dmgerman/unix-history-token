begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PriorityWorklist.h - Worklist with insertion priority ----*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file provides a priority worklist. See the class comments for details.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_PRIORITYWORKLIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_PRIORITYWORKLIST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A FILO worklist that prioritizes on re-insertion without duplication.
comment|///
comment|/// This is very similar to a \c SetVector with the primary difference that
comment|/// while re-insertion does not create a duplicate, it does adjust the
comment|/// visitation order to respect the last insertion point. This can be useful
comment|/// when the visit order needs to be prioritized based on insertion point
comment|/// without actually having duplicate visits.
comment|///
comment|/// Note that this doesn't prevent re-insertion of elements which have been
comment|/// visited -- if you need to break cycles, a set will still be necessary.
comment|///
comment|/// The type \c T must be default constructable to a null value that will be
comment|/// ignored. It is an error to insert such a value, and popping elements will
comment|/// never produce such a value. It is expected to be used with common nullable
comment|/// types like pointers or optionals.
comment|///
comment|/// Internally this uses a vector to store the worklist and a map to identify
comment|/// existing elements in the worklist. Both of these may be customized, but the
comment|/// map must support the basic DenseMap API for mapping from a T to an integer
comment|/// index into the vector.
comment|///
comment|/// A partial specialization is provided to automatically select a SmallVector
comment|/// and a SmallDenseMap if custom data structures are not provided.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|VectorT
operator|=
name|std
operator|::
name|vector
operator|<
name|T
operator|>
operator|,
name|typename
name|MapT
operator|=
name|DenseMap
operator|<
name|T
operator|,
name|ptrdiff_t
operator|>>
name|class
name|PriorityWorklist
block|{
name|public
operator|:
name|using
name|value_type
operator|=
name|T
block|;
name|using
name|key_type
operator|=
name|T
block|;
name|using
name|reference
operator|=
name|T
operator|&
block|;
name|using
name|const_reference
operator|=
specifier|const
name|T
operator|&
block|;
name|using
name|size_type
operator|=
name|typename
name|MapT
operator|::
name|size_type
block|;
comment|/// Construct an empty PriorityWorklist
name|PriorityWorklist
argument_list|()
operator|=
expr|default
block|;
comment|/// Determine if the PriorityWorklist is empty or not.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|V
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Returns the number of elements in the worklist.
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|M
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Count the number of elements of a given key in the PriorityWorklist.
comment|/// \returns 0 if the element is not in the PriorityWorklist, 1 if it is.
name|size_type
name|count
argument_list|(
argument|const key_type&key
argument_list|)
specifier|const
block|{
return|return
name|M
operator|.
name|count
argument_list|(
name|key
argument_list|)
return|;
block|}
comment|/// Return the last element of the PriorityWorklist.
specifier|const
name|T
operator|&
name|back
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Cannot call back() on empty PriorityWorklist!"
argument_list|)
block|;
return|return
name|V
operator|.
name|back
argument_list|()
return|;
block|}
comment|/// Insert a new element into the PriorityWorklist.
comment|/// \returns true if the element was inserted into the PriorityWorklist.
name|bool
name|insert
argument_list|(
argument|const T&X
argument_list|)
block|{
name|assert
argument_list|(
name|X
operator|!=
name|T
argument_list|()
operator|&&
literal|"Cannot insert a null (default constructed) value!"
argument_list|)
block|;
name|auto
name|InsertResult
operator|=
name|M
operator|.
name|insert
argument_list|(
block|{
name|X
block|,
name|V
operator|.
name|size
argument_list|()
block|}
argument_list|)
block|;
if|if
condition|(
name|InsertResult
operator|.
name|second
condition|)
block|{
comment|// Fresh value, just append it to the vector.
name|V
operator|.
name|push_back
argument_list|(
name|X
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
name|auto
operator|&
name|Index
operator|=
name|InsertResult
operator|.
name|first
operator|->
name|second
expr_stmt|;
name|assert
argument_list|(
name|V
index|[
name|Index
index|]
operator|==
name|X
operator|&&
literal|"Value not actually at index in map!"
argument_list|)
block|;
if|if
condition|(
name|Index
operator|!=
call|(
name|ptrdiff_t
call|)
argument_list|(
name|V
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
condition|)
block|{
comment|// If the element isn't at the back, null it out and append a fresh one.
name|V
index|[
name|Index
index|]
operator|=
name|T
argument_list|()
expr_stmt|;
name|Index
operator|=
operator|(
name|ptrdiff_t
operator|)
name|V
operator|.
name|size
argument_list|()
expr_stmt|;
name|V
operator|.
name|push_back
argument_list|(
name|X
argument_list|)
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
comment|/// Insert a sequence of new elements into the PriorityWorklist.
name|template
operator|<
name|typename
name|SequenceT
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
operator|!
name|std
operator|::
name|is_convertible
operator|<
name|SequenceT
operator|,
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|type
name|insert
argument_list|(
argument|SequenceT&&Input
argument_list|)
block|{
if|if
condition|(
name|std
operator|::
name|begin
argument_list|(
name|Input
argument_list|)
operator|==
name|std
operator|::
name|end
argument_list|(
name|Input
argument_list|)
condition|)
comment|// Nothing to do for an empty input sequence.
return|return;
comment|// First pull the input sequence into the vector as a bulk append
comment|// operation.
name|ptrdiff_t
name|StartIndex
operator|=
name|V
operator|.
name|size
argument_list|()
expr_stmt|;
name|V
operator|.
name|insert
argument_list|(
name|V
operator|.
name|end
argument_list|()
argument_list|,
name|std
operator|::
name|begin
argument_list|(
name|Input
argument_list|)
argument_list|,
name|std
operator|::
name|end
argument_list|(
name|Input
argument_list|)
argument_list|)
expr_stmt|;
comment|// Now walk backwards fixing up the index map and deleting any duplicates.
for|for
control|(
name|ptrdiff_t
name|i
init|=
name|V
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
name|StartIndex
condition|;
operator|--
name|i
control|)
block|{
name|auto
name|InsertResult
init|=
name|M
operator|.
name|insert
argument_list|(
block|{
name|V
index|[
name|i
index|]
block|,
name|i
block|}
argument_list|)
decl_stmt|;
if|if
condition|(
name|InsertResult
operator|.
name|second
condition|)
continue|continue;
comment|// If the existing index is before this insert's start, nuke that one and
comment|// move it up.
name|ptrdiff_t
modifier|&
name|Index
init|=
name|InsertResult
operator|.
name|first
operator|->
name|second
decl_stmt|;
if|if
condition|(
name|Index
operator|<
name|StartIndex
condition|)
block|{
name|V
index|[
name|Index
index|]
operator|=
name|T
argument_list|()
expr_stmt|;
name|Index
operator|=
name|i
expr_stmt|;
continue|continue;
block|}
comment|// Otherwise the existing one comes first so just clear out the value in
comment|// this slot.
name|V
index|[
name|i
index|]
operator|=
name|T
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|/// Remove the last element of the PriorityWorklist.
end_comment

begin_function
name|void
name|pop_back
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Cannot remove an element when empty!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|back
argument_list|()
operator|!=
name|T
argument_list|()
operator|&&
literal|"Cannot have a null element at the back!"
argument_list|)
expr_stmt|;
name|M
operator|.
name|erase
argument_list|(
name|back
argument_list|()
argument_list|)
expr_stmt|;
do|do
block|{
name|V
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|V
operator|.
name|empty
argument_list|()
operator|&&
name|V
operator|.
name|back
argument_list|()
operator|==
name|T
argument_list|()
condition|)
do|;
block|}
end_function

begin_function
name|LLVM_NODISCARD
name|T
name|pop_back_val
parameter_list|()
block|{
name|T
name|Ret
init|=
name|back
argument_list|()
decl_stmt|;
name|pop_back
argument_list|()
expr_stmt|;
return|return
name|Ret
return|;
block|}
end_function

begin_comment
comment|/// Erase an item from the worklist.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this is constant time due to the nature of the worklist implementation.
end_comment

begin_function
name|bool
name|erase
parameter_list|(
specifier|const
name|T
modifier|&
name|X
parameter_list|)
block|{
name|auto
name|I
init|=
name|M
operator|.
name|find
argument_list|(
name|X
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|M
operator|.
name|end
argument_list|()
condition|)
return|return
name|false
return|;
name|assert
argument_list|(
name|V
index|[
name|I
operator|->
name|second
index|]
operator|==
name|X
operator|&&
literal|"Value not actually at index in map!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|I
operator|->
name|second
operator|==
call|(
name|ptrdiff_t
call|)
argument_list|(
name|V
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
condition|)
block|{
do|do
block|{
name|V
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|V
operator|.
name|empty
argument_list|()
operator|&&
name|V
operator|.
name|back
argument_list|()
operator|==
name|T
argument_list|()
condition|)
do|;
block|}
else|else
block|{
name|V
index|[
name|I
operator|->
name|second
index|]
operator|=
name|T
argument_list|()
expr_stmt|;
block|}
name|M
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/// Erase items from the set vector based on a predicate function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is intended to be equivalent to the following code, if we could
end_comment

begin_comment
comment|/// write it:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   V.erase(remove_if(V, P), V.end());
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// However, PriorityWorklist doesn't expose non-const iterators, making any
end_comment

begin_comment
comment|/// algorithm like remove_if impossible to use.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if any element is removed.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|UnaryPredicate
operator|>
name|bool
name|erase_if
argument_list|(
argument|UnaryPredicate P
argument_list|)
block|{
name|typename
name|VectorT
operator|::
name|iterator
name|E
operator|=
name|remove_if
argument_list|(
name|V
argument_list|,
name|TestAndEraseFromMap
operator|<
name|UnaryPredicate
operator|>
operator|(
name|P
operator|,
name|M
operator|)
argument_list|)
block|;
if|if
condition|(
name|E
operator|==
name|V
operator|.
name|end
argument_list|()
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_for
for|for
control|(
name|auto
name|I
init|=
name|V
operator|.
name|begin
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
operator|*
name|I
operator|!=
name|T
argument_list|()
condition|)
name|M
index|[
operator|*
name|I
index|]
operator|=
name|I
operator|-
name|V
operator|.
name|begin
argument_list|()
expr_stmt|;
end_for

begin_expr_stmt
name|V
operator|.
name|erase
argument_list|(
name|E
argument_list|,
name|V
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|/// Reverse the items in the PriorityWorklist.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This does an in-place reversal. Other kinds of reverse aren't easy to
end_comment

begin_comment
comment|/// support in the face of the worklist semantics.
end_comment

begin_comment
comment|/// Completely clear the PriorityWorklist
end_comment

begin_macro
unit|void
name|clear
argument_list|()
end_macro

begin_block
block|{
name|M
operator|.
name|clear
argument_list|()
expr_stmt|;
name|V
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_block

begin_label
name|private
label|:
end_label

begin_comment
comment|/// A wrapper predicate designed for use with std::remove_if.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This predicate wraps a predicate suitable for use with std::remove_if to
end_comment

begin_comment
comment|/// call M.erase(x) on each element which is slated for removal. This just
end_comment

begin_comment
comment|/// allows the predicate to be move only which we can't do with lambdas
end_comment

begin_comment
comment|/// today.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|UnaryPredicateT
operator|>
name|class
name|TestAndEraseFromMap
block|{
name|UnaryPredicateT
name|P
block|;
name|MapT
operator|&
name|M
block|;
name|public
operator|:
name|TestAndEraseFromMap
argument_list|(
argument|UnaryPredicateT P
argument_list|,
argument|MapT&M
argument_list|)
operator|:
name|P
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|P
argument_list|)
argument_list|)
block|,
name|M
argument_list|(
argument|M
argument_list|)
block|{}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|T
operator|&
name|Arg
operator|)
block|{
if|if
condition|(
name|Arg
operator|==
name|T
argument_list|()
condition|)
comment|// Skip null values in the PriorityWorklist.
return|return
name|false
return|;
if|if
condition|(
name|P
argument_list|(
name|Arg
argument_list|)
condition|)
block|{
name|M
operator|.
name|erase
argument_list|(
name|Arg
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_empty_stmt
unit|}   }
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// The map from value to index in the vector.
end_comment

begin_decl_stmt
name|MapT
name|M
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The vector of elements in insertion order.
end_comment

begin_decl_stmt
name|VectorT
name|V
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// A version of \c PriorityWorklist that selects small size optimized data
end_comment

begin_comment
comment|/// structures for the vector and map.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
name|N
operator|>
name|class
name|SmallPriorityWorklist
operator|:
name|public
name|PriorityWorklist
operator|<
name|T
operator|,
name|SmallVector
operator|<
name|T
operator|,
name|N
operator|>
operator|,
name|SmallDenseMap
operator|<
name|T
operator|,
name|ptrdiff_t
operator|>>
block|{
name|public
operator|:
name|SmallPriorityWorklist
argument_list|()
operator|=
expr|default
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_PRIORITYWORKLIST_H
end_comment

end_unit

