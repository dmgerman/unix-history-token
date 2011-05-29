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
file|"llvm/ADT/SmallSet.h"
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
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This adapter class provides a way to keep a set of things that also has the
comment|/// property of a deterministic iteration order. The order of iteration is the
comment|/// order of insertion.
comment|/// @brief A vector that has set insertion semantics.
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
name|SmallSet
operator|<
name|T
operator|,
literal|16
operator|>
expr|>
name|class
name|SetVector
block|{
name|public
operator|:
typedef|typedef
name|T
name|value_type
typedef|;
typedef|typedef
name|T
name|key_type
typedef|;
typedef|typedef
name|T
modifier|&
name|reference
typedef|;
typedef|typedef
specifier|const
name|T
modifier|&
name|const_reference
typedef|;
typedef|typedef
name|Set
name|set_type
typedef|;
typedef|typedef
name|Vector
name|vector_type
typedef|;
typedef|typedef
name|typename
name|vector_type
operator|::
name|const_iterator
name|iterator
expr_stmt|;
typedef|typedef
name|typename
name|vector_type
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|typename
name|vector_type
operator|::
name|size_type
name|size_type
expr_stmt|;
comment|/// @brief Construct an empty SetVector
name|SetVector
argument_list|()
block|{}
comment|/// @brief Initialize a SetVector with a range of elements
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
comment|/// @brief Determine if the SetVector is empty or not.
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
comment|/// @brief Determine the number of elements in the SetVector.
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
comment|/// @brief Get an iterator to the beginning of the SetVector.
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|vector_
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// @brief Get a const_iterator to the beginning of the SetVector.
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
comment|/// @brief Get an iterator to the end of the SetVector.
name|iterator
name|end
parameter_list|()
block|{
return|return
name|vector_
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// @brief Get a const_iterator to the end of the SetVector.
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
comment|/// @brief Return the last element of the SetVector.
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
comment|/// @brief Index into the SetVector.
name|const_reference
name|operator
index|[]
argument_list|(
name|size_type
name|n
argument_list|)
decl|const
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
expr_stmt|;
return|return
name|vector_
index|[
name|n
index|]
return|;
block|}
comment|/// @returns true iff the element was inserted into the SetVector.
comment|/// @brief Insert a new element into the SetVector.
name|bool
name|insert
parameter_list|(
specifier|const
name|value_type
modifier|&
name|X
parameter_list|)
block|{
name|bool
name|result
init|=
name|set_
operator|.
name|insert
argument_list|(
name|X
argument_list|)
decl_stmt|;
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
comment|/// @brief Insert a range of elements into the SetVector.
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
comment|/// @brief Remove an item from the set vector.
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
name|std
operator|::
name|find
argument_list|(
name|vector_
operator|.
name|begin
argument_list|()
argument_list|,
name|vector_
operator|.
name|end
argument_list|()
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
comment|/// @returns 0 if the element is not in the SetVector, 1 if it is.
comment|/// @brief Count the number of elements of a given key in the SetVector.
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
comment|/// @brief Completely clear the SetVector
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
comment|/// @brief Remove the last element of the SetVector.
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
name|private
label|:
name|set_type
name|set_
decl_stmt|;
comment|///< The set.
name|vector_type
name|vector_
decl_stmt|;
comment|///< The vector.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// SmallSetVector - A SetVector that performs no allocations if smaller than
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
name|SmallSet
operator|<
name|T
operator|,
name|N
operator|>
expr|>
block|{
name|public
operator|:
name|SmallSetVector
argument_list|()
block|{}
comment|/// @brief Initialize a SmallSetVector with a range of elements
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
comment|// End llvm namespace
end_comment

begin_comment
comment|// vim: sw=2 ai
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

