begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/edit_distance.h - Array edit distance function --- C++ -*-===//
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
comment|// This file defines a Levenshtein distance function that works for any two
end_comment

begin_comment
comment|// sequences, with each element of each sequence being analogous to a character
end_comment

begin_comment
comment|// in a string.
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
name|LLVM_ADT_EDIT_DISTANCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_EDIT_DISTANCE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Determine the edit distance between two sequences.
comment|///
comment|/// \param FromArray the first sequence to compare.
comment|///
comment|/// \param ToArray the second sequence to compare.
comment|///
comment|/// \param AllowReplacements whether to allow element replacements (change one
comment|/// element into another) as a single operation, rather than as two operations
comment|/// (an insertion and a removal).
comment|///
comment|/// \param MaxEditDistance If non-zero, the maximum edit distance that this
comment|/// routine is allowed to compute. If the edit distance will exceed that
comment|/// maximum, returns \c MaxEditDistance+1.
comment|///
comment|/// \returns the minimum number of element insertions, removals, or (if
comment|/// \p AllowReplacements is \c true) replacements needed to transform one of
comment|/// the given sequences into the other. If zero, the sequences are identical.
name|template
operator|<
name|typename
name|T
operator|>
name|unsigned
name|ComputeEditDistance
argument_list|(
argument|ArrayRef<T> FromArray
argument_list|,
argument|ArrayRef<T> ToArray
argument_list|,
argument|bool AllowReplacements = true
argument_list|,
argument|unsigned MaxEditDistance =
literal|0
argument_list|)
block|{
comment|// The algorithm implemented below is the "classic"
comment|// dynamic-programming algorithm for computing the Levenshtein
comment|// distance, which is described here:
comment|//
comment|//   http://en.wikipedia.org/wiki/Levenshtein_distance
comment|//
comment|// Although the algorithm is typically described using an m x n
comment|// array, only one row plus one element are used at a time, so this
comment|// implementation just keeps one vector for the row.  To update one entry,
comment|// only the entries to the left, top, and top-left are needed.  The left
comment|// entry is in Row[x-1], the top entry is what's in Row[x] from the last
comment|// iteration, and the top-left entry is stored in Previous.
name|typename
name|ArrayRef
operator|<
name|T
operator|>
operator|::
name|size_type
name|m
operator|=
name|FromArray
operator|.
name|size
argument_list|()
block|;
name|typename
name|ArrayRef
operator|<
name|T
operator|>
operator|::
name|size_type
name|n
operator|=
name|ToArray
operator|.
name|size
argument_list|()
block|;
specifier|const
name|unsigned
name|SmallBufferSize
operator|=
literal|64
block|;
name|unsigned
name|SmallBuffer
index|[
name|SmallBufferSize
index|]
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|unsigned
index|[]
operator|>
name|Allocated
block|;
name|unsigned
operator|*
name|Row
operator|=
name|SmallBuffer
block|;
if|if
condition|(
name|n
operator|+
literal|1
operator|>
name|SmallBufferSize
condition|)
block|{
name|Row
operator|=
name|new
name|unsigned
index|[
name|n
operator|+
literal|1
index|]
expr_stmt|;
name|Allocated
operator|.
name|reset
argument_list|(
name|Row
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|unsigned
name|i
init|=
literal|1
init|;
name|i
operator|<=
name|n
condition|;
operator|++
name|i
control|)
name|Row
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
for|for
control|(
name|typename
name|ArrayRef
operator|<
name|T
operator|>
operator|::
name|size_type
name|y
operator|=
literal|1
init|;
name|y
operator|<=
name|m
condition|;
operator|++
name|y
control|)
block|{
name|Row
index|[
literal|0
index|]
operator|=
name|y
expr_stmt|;
name|unsigned
name|BestThisRow
init|=
name|Row
index|[
literal|0
index|]
decl_stmt|;
name|unsigned
name|Previous
init|=
name|y
operator|-
literal|1
decl_stmt|;
for|for
control|(
name|typename
name|ArrayRef
operator|<
name|T
operator|>
operator|::
name|size_type
name|x
operator|=
literal|1
init|;
name|x
operator|<=
name|n
condition|;
operator|++
name|x
control|)
block|{
name|int
name|OldRow
init|=
name|Row
index|[
name|x
index|]
decl_stmt|;
if|if
condition|(
name|AllowReplacements
condition|)
block|{
name|Row
index|[
name|x
index|]
operator|=
name|std
operator|::
name|min
argument_list|(
name|Previous
operator|+
operator|(
name|FromArray
index|[
name|y
operator|-
literal|1
index|]
operator|==
name|ToArray
index|[
name|x
operator|-
literal|1
index|]
condition|?
literal|0u
else|:
literal|1u
operator|)
argument_list|,
name|std
operator|::
name|min
argument_list|(
name|Row
index|[
name|x
operator|-
literal|1
index|]
argument_list|,
name|Row
index|[
name|x
index|]
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|FromArray
index|[
name|y
operator|-
literal|1
index|]
operator|==
name|ToArray
index|[
name|x
operator|-
literal|1
index|]
condition|)
name|Row
index|[
name|x
index|]
operator|=
name|Previous
expr_stmt|;
else|else
name|Row
index|[
name|x
index|]
operator|=
name|std
operator|::
name|min
argument_list|(
name|Row
index|[
name|x
operator|-
literal|1
index|]
argument_list|,
name|Row
index|[
name|x
index|]
argument_list|)
operator|+
literal|1
expr_stmt|;
block|}
name|Previous
operator|=
name|OldRow
expr_stmt|;
name|BestThisRow
operator|=
name|std
operator|::
name|min
argument_list|(
name|BestThisRow
argument_list|,
name|Row
index|[
name|x
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|MaxEditDistance
operator|&&
name|BestThisRow
operator|>
name|MaxEditDistance
condition|)
return|return
name|MaxEditDistance
operator|+
literal|1
return|;
block|}
name|unsigned
name|Result
init|=
name|Row
index|[
name|n
index|]
decl_stmt|;
return|return
name|Result
return|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

