begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/SetVector.h - Set with insert order iteration ---*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file implements a set that has insertion order iteration
end_comment

begin_comment
comment|// characteristics. This is useful for keeping a set of things that need to be
end_comment

begin_comment
comment|// visited later but in a deterministic order (insertion order). The interface
end_comment

begin_comment
comment|// is purposefully minimal.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines SetVector and SmallSetVector, which performs no allocations
end_comment

begin_comment
comment|// if the SetVector has less than a certain number of elements.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_SETVECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SETVECTOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
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
file|<iterator>
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
comment|/// \brief A vector that has set insertion semantics.
comment|///
comment|/// This adapter class provides a way to keep a set of things that also has the
comment|/// property of a deterministic iteration order. The order of iteration is the
comment|/// order of insertion.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Vector
operator|=
name|std
operator|::
name|vector
operator|<
name|T
operator|>
operator|,
name|typename
name|Set
operator|=
name|DenseSet
operator|<
name|T
operator|>>
name|class
name|SetVector
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
name|set_type
operator|=
name|Set
block|;
name|using
name|vector_type
operator|=
name|Vector
block|;
name|using
name|iterator
operator|=
name|typename
name|vector_type
operator|::
name|const_iterator
block|;
name|using
name|const_iterator
operator|=
name|typename
name|vector_type
operator|::
name|const_iterator
block|;
name|using
name|reverse_iterator
operator|=
name|typename
name|vector_type
operator|::
name|const_reverse_iterator
block|;
name|using
name|const_reverse_iterator
operator|=
name|typename
name|vector_type
operator|::
name|const_reverse_iterator
block|;
name|using
name|size_type
operator|=
name|typename
name|vector_type
operator|::
name|size_type
block|;
comment|/// \brief Construct an empty SetVector
name|SetVector
argument_list|()
operator|=
expr|default
block|;
comment|/// \brief Initialize a SetVector with a range of elements
name|template
operator|<
name|typename
name|It
operator|>
name|SetVector
argument_list|(
argument|It Start
argument_list|,
argument|It End
argument_list|)
block|{
name|insert
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
block|;   }
name|ArrayRef
operator|<
name|T
operator|>
name|getArrayRef
argument_list|()
specifier|const
block|{
return|return
name|vector_
return|;
block|}
comment|/// Clear the SetVector and return the underlying vector.
name|Vector
name|takeVector
argument_list|()
block|{
name|set_
operator|.
name|clear
argument_list|()
block|;
return|return
name|std
operator|::
name|move
argument_list|(
name|vector_
argument_list|)
return|;
block|}
comment|/// \brief Determine if the SetVector is empty or not.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|vector_
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Determine the number of elements in the SetVector.
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|vector_
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Get an iterator to the beginning of the SetVector.
name|iterator
name|begin
argument_list|()
block|{
return|return
name|vector_
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// \brief Get a const_iterator to the beginning of the SetVector.
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|vector_
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// \brief Get an iterator to the end of the SetVector.
name|iterator
name|end
argument_list|()
block|{
return|return
name|vector_
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Get a const_iterator to the end of the SetVector.
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|vector_
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Get an reverse_iterator to the end of the SetVector.
name|reverse_iterator
name|rbegin
argument_list|()
block|{
return|return
name|vector_
operator|.
name|rbegin
argument_list|()
return|;
block|}
comment|/// \brief Get a const_reverse_iterator to the end of the SetVector.
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|vector_
operator|.
name|rbegin
argument_list|()
return|;
block|}
comment|/// \brief Get a reverse_iterator to the beginning of the SetVector.
name|reverse_iterator
name|rend
argument_list|()
block|{
return|return
name|vector_
operator|.
name|rend
argument_list|()
return|;
block|}
comment|/// \brief Get a const_reverse_iterator to the beginning of the SetVector.
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|vector_
operator|.
name|rend
argument_list|()
return|;
block|}
comment|/// \brief Return the first element of the SetVector.
specifier|const
name|T
operator|&
name|front
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Cannot call front() on empty SetVector!"
argument_list|)
block|;
return|return
name|vector_
operator|.
name|front
argument_list|()
return|;
block|}
comment|/// \brief Return the last element of the SetVector.
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
literal|"Cannot call back() on empty SetVector!"
argument_list|)
block|;
return|return
name|vector_
operator|.
name|back
argument_list|()
return|;
block|}
comment|/// \brief Index into the SetVector.
name|const_reference
name|operator
index|[]
operator|(
name|size_type
name|n
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|n
operator|<
name|vector_
operator|.
name|size
argument_list|()
operator|&&
literal|"SetVector access out of range!"
argument_list|)
block|;
return|return
name|vector_
index|[
name|n
index|]
return|;
block|}
comment|/// \brief Insert a new element into the SetVector.
comment|/// \returns true if the element was inserted into the SetVector.
name|bool
name|insert
argument_list|(
argument|const value_type&X
argument_list|)
block|{
name|bool
name|result
operator|=
name|set_
operator|.
name|insert
argument_list|(
name|X
argument_list|)
operator|.
name|second
block|;
if|if
condition|(
name|result
condition|)
name|vector_
operator|.
name|push_back
argument_list|(
name|X
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
comment|/// \brief Insert a range of elements into the SetVector.
name|template
operator|<
name|typename
name|It
operator|>
name|void
name|insert
argument_list|(
argument|It Start
argument_list|,
argument|It End
argument_list|)
block|{
for|for
control|(
init|;
name|Start
operator|!=
name|End
condition|;
operator|++
name|Start
control|)
if|if
condition|(
name|set_
operator|.
name|insert
argument_list|(
operator|*
name|Start
argument_list|)
operator|.
name|second
condition|)
name|vector_
operator|.
name|push_back
argument_list|(
operator|*
name|Start
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Remove an item from the set vector.
name|bool
name|remove
parameter_list|(
specifier|const
name|value_type
modifier|&
name|X
parameter_list|)
block|{
if|if
condition|(
name|set_
operator|.
name|erase
argument_list|(
name|X
argument_list|)
condition|)
block|{
name|typename
name|vector_type
operator|::
name|iterator
name|I
operator|=
name|find
argument_list|(
name|vector_
argument_list|,
name|X
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|vector_
operator|.
name|end
argument_list|()
operator|&&
literal|"Corrupted SetVector instances!"
argument_list|)
expr_stmt|;
name|vector_
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
return|return
name|false
return|;
block|}
comment|/// Erase a single element from the set vector.
comment|/// \returns an iterator pointing to the next element that followed the
comment|/// element erased. This is the end of the SetVector if the last element is
comment|/// erased.
name|iterator
name|erase
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
specifier|const
name|key_type
modifier|&
name|V
init|=
operator|*
name|I
decl_stmt|;
name|assert
argument_list|(
name|set_
operator|.
name|count
argument_list|(
name|V
argument_list|)
operator|&&
literal|"Corrupted SetVector instances!"
argument_list|)
expr_stmt|;
name|set_
operator|.
name|erase
argument_list|(
name|V
argument_list|)
expr_stmt|;
comment|// FIXME: No need to use the non-const iterator when built with
comment|// std:vector.erase(const_iterator) as defined in C++11. This is for
comment|// compatibility with non-standard libstdc++ up to 4.8 (fixed in 4.9).
name|auto
name|NI
init|=
name|vector_
operator|.
name|begin
argument_list|()
decl_stmt|;
name|std
operator|::
name|advance
argument_list|(
name|NI
argument_list|,
name|std
operator|::
name|distance
operator|<
name|iterator
operator|>
operator|(
name|NI
operator|,
name|I
operator|)
argument_list|)
expr_stmt|;
return|return
name|vector_
operator|.
name|erase
argument_list|(
name|NI
argument_list|)
return|;
block|}
comment|/// \brief Remove items from the set vector based on a predicate function.
comment|///
comment|/// This is intended to be equivalent to the following code, if we could
comment|/// write it:
comment|///
comment|/// \code
comment|///   V.erase(remove_if(V, P), V.end());
comment|/// \endcode
comment|///
comment|/// However, SetVector doesn't expose non-const iterators, making any
comment|/// algorithm like remove_if impossible to use.
comment|///
comment|/// \returns true if any element is removed.
name|template
operator|<
name|typename
name|UnaryPredicate
operator|>
name|bool
name|remove_if
argument_list|(
argument|UnaryPredicate P
argument_list|)
block|{
name|typename
name|vector_type
operator|::
name|iterator
name|I
operator|=
name|llvm
operator|::
name|remove_if
argument_list|(
name|vector_
argument_list|,
name|TestAndEraseFromSet
operator|<
name|UnaryPredicate
operator|>
operator|(
name|P
operator|,
name|set_
operator|)
argument_list|)
block|;
if|if
condition|(
name|I
operator|==
name|vector_
operator|.
name|end
argument_list|()
condition|)
return|return
name|false
return|;
name|vector_
operator|.
name|erase
argument_list|(
name|I
argument_list|,
name|vector_
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Count the number of elements of a given key in the SetVector.
end_comment

begin_comment
comment|/// \returns 0 if the element is not in the SetVector, 1 if it is.
end_comment

begin_decl_stmt
name|size_type
name|count
argument_list|(
specifier|const
name|key_type
operator|&
name|key
argument_list|)
decl|const
block|{
return|return
name|set_
operator|.
name|count
argument_list|(
name|key
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Completely clear the SetVector
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|set_
operator|.
name|clear
argument_list|()
expr_stmt|;
name|vector_
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Remove the last element of the SetVector.
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
literal|"Cannot remove an element from an empty SetVector!"
argument_list|)
expr_stmt|;
name|set_
operator|.
name|erase
argument_list|(
name|back
argument_list|()
argument_list|)
expr_stmt|;
name|vector_
operator|.
name|pop_back
argument_list|()
expr_stmt|;
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

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SetVector
operator|&
name|that
operator|)
specifier|const
block|{
return|return
name|vector_
operator|==
name|that
operator|.
name|vector_
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SetVector
operator|&
name|that
operator|)
specifier|const
block|{
return|return
name|vector_
operator|!=
name|that
operator|.
name|vector_
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Compute This := This u S, return whether 'This' changed.
end_comment

begin_comment
comment|/// TODO: We should be able to use set_union from SetOperations.h, but
end_comment

begin_comment
comment|///       SetVector interface is inconsistent with DenseSet.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|STy
operator|>
name|bool
name|set_union
argument_list|(
argument|const STy&S
argument_list|)
block|{
name|bool
name|Changed
operator|=
name|false
block|;
for|for
control|(
name|typename
name|STy
operator|::
name|const_iterator
name|SI
operator|=
name|S
operator|.
name|begin
argument_list|()
operator|,
name|SE
operator|=
name|S
operator|.
name|end
argument_list|()
init|;
name|SI
operator|!=
name|SE
condition|;
operator|++
name|SI
control|)
if|if
condition|(
name|insert
argument_list|(
operator|*
name|SI
argument_list|)
condition|)
name|Changed
operator|=
name|true
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Changed
return|;
end_return

begin_comment
unit|}
comment|/// \brief Compute This := This - B
end_comment

begin_comment
comment|/// TODO: We should be able to use set_subtract from SetOperations.h, but
end_comment

begin_comment
comment|///       SetVector interface is inconsistent with DenseSet.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|STy
operator|>
name|void
name|set_subtract
argument_list|(
argument|const STy&S
argument_list|)
block|{
for|for
control|(
name|typename
name|STy
operator|::
name|const_iterator
name|SI
operator|=
name|S
operator|.
name|begin
argument_list|()
operator|,
name|SE
operator|=
name|S
operator|.
name|end
argument_list|()
init|;
name|SI
operator|!=
name|SE
condition|;
operator|++
name|SI
control|)
name|remove
argument_list|(
operator|*
name|SI
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief A wrapper predicate designed for use with std::remove_if.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This predicate wraps a predicate suitable for use with std::remove_if to
end_comment

begin_comment
comment|/// call set_.erase(x) on each element which is slated for removal.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|UnaryPredicate
operator|>
name|class
name|TestAndEraseFromSet
block|{
name|UnaryPredicate
name|P
block|;
name|set_type
operator|&
name|set_
block|;
name|public
operator|:
name|TestAndEraseFromSet
argument_list|(
argument|UnaryPredicate P
argument_list|,
argument|set_type&set_
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
name|set_
argument_list|(
argument|set_
argument_list|)
block|{}
name|template
operator|<
name|typename
name|ArgumentT
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|ArgumentT
operator|&
name|Arg
operator|)
block|{
if|if
condition|(
name|P
argument_list|(
name|Arg
argument_list|)
condition|)
block|{
name|set_
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
return|return
name|false
return|;
block|}
end_expr_stmt

begin_decl_stmt
unit|};
name|set_type
name|set_
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The set.
end_comment

begin_decl_stmt
name|vector_type
name|vector_
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The vector.
end_comment

begin_comment
unit|};
comment|/// \brief A SetVector that performs no allocations if smaller than
end_comment

begin_comment
comment|/// a certain size.
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
name|SmallSetVector
operator|:
name|public
name|SetVector
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
name|SmallDenseSet
operator|<
name|T
operator|,
name|N
operator|>>
block|{
name|public
operator|:
name|SmallSetVector
argument_list|()
operator|=
expr|default
block|;
comment|/// \brief Initialize a SmallSetVector with a range of elements
name|template
operator|<
name|typename
name|It
operator|>
name|SmallSetVector
argument_list|(
argument|It Start
argument_list|,
argument|It End
argument_list|)
block|{
name|this
operator|->
name|insert
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
block|;   }
block|}
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
comment|// LLVM_ADT_SETVECTOR_H
end_comment

end_unit

