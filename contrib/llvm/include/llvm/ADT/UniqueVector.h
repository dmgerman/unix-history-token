begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/UniqueVector.h ----------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_UNIQUEVECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_UNIQUEVECTOR_H
end_define

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
file|<map>
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
comment|//===----------------------------------------------------------------------===//
comment|/// UniqueVector - This class produces a sequential ID number (base 1) for each
comment|/// unique entry that is added.  T is the type of entries in the vector. This
comment|/// class should have an implementation of operator== and of operator<.
comment|/// Entries can be fetched using operator[] with the entry ID.
name|template
operator|<
name|class
name|T
operator|>
name|class
name|UniqueVector
block|{
name|public
operator|:
name|using
name|VectorType
operator|=
name|typename
name|std
operator|::
name|vector
operator|<
name|T
operator|>
block|;
name|using
name|iterator
operator|=
name|typename
name|VectorType
operator|::
name|iterator
block|;
name|using
name|const_iterator
operator|=
name|typename
name|VectorType
operator|::
name|const_iterator
block|;
name|private
operator|:
comment|// Map - Used to handle the correspondence of entry to ID.
name|std
operator|::
name|map
operator|<
name|T
block|,
name|unsigned
operator|>
name|Map
block|;
comment|// Vector - ID ordered vector of entries. Entries can be indexed by ID - 1.
name|VectorType
name|Vector
block|;
name|public
operator|:
comment|/// insert - Append entry to the vector if it doesn't already exist.  Returns
comment|/// the entry's index + 1 to be used as a unique ID.
name|unsigned
name|insert
argument_list|(
argument|const T&Entry
argument_list|)
block|{
comment|// Check if the entry is already in the map.
name|unsigned
operator|&
name|Val
operator|=
name|Map
index|[
name|Entry
index|]
block|;
comment|// See if entry exists, if so return prior ID.
if|if
condition|(
name|Val
condition|)
return|return
name|Val
return|;
comment|// Compute ID for entry.
name|Val
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|Vector
operator|.
name|size
argument_list|()
operator|)
operator|+
literal|1
block|;
comment|// Insert in vector.
name|Vector
operator|.
name|push_back
argument_list|(
name|Entry
argument_list|)
block|;
return|return
name|Val
return|;
block|}
comment|/// idFor - return the ID for an existing entry.  Returns 0 if the entry is
comment|/// not found.
name|unsigned
name|idFor
argument_list|(
specifier|const
name|T
operator|&
name|Entry
argument_list|)
decl|const
block|{
comment|// Search for entry in the map.
name|typename
name|std
operator|::
name|map
operator|<
name|T
operator|,
name|unsigned
operator|>
operator|::
name|const_iterator
name|MI
operator|=
name|Map
operator|.
name|find
argument_list|(
name|Entry
argument_list|)
expr_stmt|;
comment|// See if entry exists, if so return ID.
if|if
condition|(
name|MI
operator|!=
name|Map
operator|.
name|end
argument_list|()
condition|)
return|return
name|MI
operator|->
name|second
return|;
comment|// No luck.
return|return
literal|0
return|;
block|}
comment|/// operator[] - Returns a reference to the entry with the specified ID.
specifier|const
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|ID
operator|-
literal|1
operator|<
name|size
argument_list|()
operator|&&
literal|"ID is 0 or out of range!"
argument_list|)
expr_stmt|;
return|return
name|Vector
index|[
name|ID
operator|-
literal|1
index|]
return|;
block|}
comment|/// \brief Return an iterator to the start of the vector.
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Vector
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// \brief Return an iterator to the start of the vector.
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Vector
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// \brief Return an iterator to the end of the vector.
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Vector
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Return an iterator to the end of the vector.
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Vector
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// size - Returns the number of entries in the vector.
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Vector
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// empty - Returns true if the vector is empty.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Vector
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// reset - Clears all the entries.
name|void
name|reset
parameter_list|()
block|{
name|Map
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Vector
operator|.
name|resize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_UNIQUEVECTOR_H
end_comment

end_unit

