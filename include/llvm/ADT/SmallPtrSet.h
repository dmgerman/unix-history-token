begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/SmallPtrSet.h - 'Normally small' pointer set ----*- C++ -*-===//
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
comment|// This file defines the SmallPtrSet class.  See the doxygen comment for
end_comment

begin_comment
comment|// SmallPtrSetImpl for more details on the algorithm used.
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
name|LLVM_ADT_SMALLPTRSET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SMALLPTRSET_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PointerLikeTypeTraits.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SmallPtrSetIteratorImpl
decl_stmt|;
comment|/// SmallPtrSetImpl - This is the common code shared among all the
comment|/// SmallPtrSet<>'s, which is almost everything.  SmallPtrSet has two modes, one
comment|/// for small and one for large sets.
comment|///
comment|/// Small sets use an array of pointers allocated in the SmallPtrSet object,
comment|/// which is treated as a simple array of pointers.  When a pointer is added to
comment|/// the set, the array is scanned to see if the element already exists, if not
comment|/// the element is 'pushed back' onto the array.  If we run out of space in the
comment|/// array, we grow into the 'large set' case.  SmallSet should be used when the
comment|/// sets are often small.  In this case, no memory allocation is used, and only
comment|/// light-weight and cache-efficient scanning is used.
comment|///
comment|/// Large sets use a classic exponentially-probed hash table.  Empty buckets are
comment|/// represented with an illegal pointer value (-1) to allow null pointers to be
comment|/// inserted.  Tombstones are represented with another illegal pointer value
comment|/// (-2), to allow deletion.  The hash table is resized when the table is 3/4 or
comment|/// more.  When this happens, the table is doubled in size.
comment|///
name|class
name|SmallPtrSetImpl
block|{
name|friend
name|class
name|SmallPtrSetIteratorImpl
decl_stmt|;
name|protected
label|:
comment|/// CurArray - This is the current set of buckets.  If it points to
comment|/// SmallArray, then the set is in 'small mode'.
specifier|const
name|void
modifier|*
modifier|*
name|CurArray
decl_stmt|;
comment|/// CurArraySize - The allocated size of CurArray, always a power of two.
comment|/// Note that CurArray points to an array that has CurArraySize+1 elements in
comment|/// it, so that the end iterator actually points to valid memory.
name|unsigned
name|CurArraySize
decl_stmt|;
comment|// If small, this is # elts allocated consequtively
name|unsigned
name|NumElements
decl_stmt|;
name|unsigned
name|NumTombstones
decl_stmt|;
specifier|const
name|void
modifier|*
name|SmallArray
index|[
literal|1
index|]
decl_stmt|;
comment|// Must be last ivar.
comment|// Helper to copy construct a SmallPtrSet.
name|SmallPtrSetImpl
argument_list|(
specifier|const
name|SmallPtrSetImpl
operator|&
name|that
argument_list|)
expr_stmt|;
name|explicit
name|SmallPtrSetImpl
parameter_list|(
name|unsigned
name|SmallSize
parameter_list|)
block|{
name|assert
argument_list|(
name|SmallSize
operator|&&
operator|(
name|SmallSize
operator|&
operator|(
name|SmallSize
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|&&
literal|"Initial size must be a power of two!"
argument_list|)
expr_stmt|;
name|CurArray
operator|=
operator|&
name|SmallArray
index|[
literal|0
index|]
expr_stmt|;
name|CurArraySize
operator|=
name|SmallSize
expr_stmt|;
comment|// The end pointer, always valid, is set to a valid element to help the
comment|// iterator.
name|CurArray
index|[
name|SmallSize
index|]
operator|=
literal|0
expr_stmt|;
name|clear
argument_list|()
expr_stmt|;
block|}
operator|~
name|SmallPtrSetImpl
argument_list|()
expr_stmt|;
name|public
label|:
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NumElements
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
comment|// If the capacity of the array is huge, and the # elements used is small,
comment|// shrink the array.
if|if
condition|(
operator|!
name|isSmall
argument_list|()
operator|&&
name|NumElements
operator|*
literal|4
operator|<
name|CurArraySize
operator|&&
name|CurArraySize
operator|>
literal|32
condition|)
return|return
name|shrink_and_clear
argument_list|()
return|;
comment|// Fill the array with empty markers.
name|memset
argument_list|(
name|CurArray
argument_list|,
operator|-
literal|1
argument_list|,
name|CurArraySize
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|NumElements
operator|=
literal|0
expr_stmt|;
name|NumTombstones
operator|=
literal|0
expr_stmt|;
block|}
name|protected
label|:
specifier|static
name|void
modifier|*
name|getTombstoneMarker
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|-
literal|2
operator|)
return|;
block|}
specifier|static
name|void
modifier|*
name|getEmptyMarker
parameter_list|()
block|{
comment|// Note that -1 is chosen to make clear() efficiently implementable with
comment|// memset and because it's not a valid pointer value.
return|return
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/// insert_imp - This returns true if the pointer was new to the set, false if
comment|/// it was already in the set.  This is hidden from the client so that the
comment|/// derived class can check that the right type of pointer is passed in.
name|bool
name|insert_imp
parameter_list|(
specifier|const
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
comment|/// erase_imp - If the set contains the specified pointer, remove it and
comment|/// return true, otherwise return false.  This is hidden from the client so
comment|/// that the derived class can check that the right type of pointer is passed
comment|/// in.
name|bool
name|erase_imp
parameter_list|(
specifier|const
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
name|bool
name|count_imp
argument_list|(
specifier|const
name|void
operator|*
name|Ptr
argument_list|)
decl|const
block|{
if|if
condition|(
name|isSmall
argument_list|()
condition|)
block|{
comment|// Linear search for the item.
for|for
control|(
specifier|const
name|void
modifier|*
specifier|const
modifier|*
name|APtr
init|=
name|SmallArray
init|,
modifier|*
init|const
modifier|*
name|E
init|=
name|SmallArray
operator|+
name|NumElements
init|;
name|APtr
operator|!=
name|E
condition|;
operator|++
name|APtr
control|)
if|if
condition|(
operator|*
name|APtr
operator|==
name|Ptr
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|// Big set case.
return|return
operator|*
name|FindBucketFor
argument_list|(
name|Ptr
argument_list|)
operator|==
name|Ptr
return|;
block|}
name|private
label|:
name|bool
name|isSmall
argument_list|()
specifier|const
block|{
return|return
name|CurArray
operator|==
operator|&
name|SmallArray
index|[
literal|0
index|]
return|;
block|}
name|unsigned
name|Hash
argument_list|(
specifier|const
name|void
operator|*
name|Ptr
argument_list|)
decl|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
operator|(
operator|(
name|uintptr_t
operator|)
name|Ptr
operator|>>
literal|4
operator|)
operator|&
operator|(
name|CurArraySize
operator|-
literal|1
operator|)
operator|)
return|;
block|}
specifier|const
name|void
modifier|*
specifier|const
modifier|*
name|FindBucketFor
argument_list|(
specifier|const
name|void
operator|*
name|Ptr
argument_list|)
decl|const
decl_stmt|;
name|void
name|shrink_and_clear
parameter_list|()
function_decl|;
comment|/// Grow - Allocate a larger backing store for the buckets and move it over.
name|void
name|Grow
parameter_list|()
function_decl|;
name|void
name|operator
init|=
operator|(
specifier|const
name|SmallPtrSetImpl
operator|&
name|RHS
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT.
name|protected
label|:
name|void
name|CopyFrom
parameter_list|(
specifier|const
name|SmallPtrSetImpl
modifier|&
name|RHS
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// SmallPtrSetIteratorImpl - This is the common base class shared between all
comment|/// instances of SmallPtrSetIterator.
name|class
name|SmallPtrSetIteratorImpl
block|{
name|protected
label|:
specifier|const
name|void
modifier|*
specifier|const
modifier|*
name|Bucket
decl_stmt|;
name|public
label|:
name|explicit
name|SmallPtrSetIteratorImpl
argument_list|(
specifier|const
name|void
operator|*
specifier|const
operator|*
name|BP
argument_list|)
operator|:
name|Bucket
argument_list|(
argument|BP
argument_list|)
block|{
name|AdvanceIfNotValid
argument_list|()
block|;   }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SmallPtrSetIteratorImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Bucket
operator|==
name|RHS
operator|.
name|Bucket
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SmallPtrSetIteratorImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Bucket
operator|!=
name|RHS
operator|.
name|Bucket
return|;
block|}
name|protected
label|:
comment|/// AdvanceIfNotValid - If the current bucket isn't valid, advance to a bucket
comment|/// that is.   This is guaranteed to stop because the end() bucket is marked
comment|/// valid.
name|void
name|AdvanceIfNotValid
parameter_list|()
block|{
while|while
condition|(
operator|*
name|Bucket
operator|==
name|SmallPtrSetImpl
operator|::
name|getEmptyMarker
argument_list|()
operator|||
operator|*
name|Bucket
operator|==
name|SmallPtrSetImpl
operator|::
name|getTombstoneMarker
argument_list|()
condition|)
operator|++
name|Bucket
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// SmallPtrSetIterator - This implements a const_iterator for SmallPtrSet.
name|template
operator|<
name|typename
name|PtrTy
operator|>
name|class
name|SmallPtrSetIterator
operator|:
name|public
name|SmallPtrSetIteratorImpl
block|{
typedef|typedef
name|PointerLikeTypeTraits
operator|<
name|PtrTy
operator|>
name|PtrTraits
expr_stmt|;
name|public
operator|:
typedef|typedef
name|PtrTy
name|value_type
typedef|;
typedef|typedef
name|PtrTy
name|reference
typedef|;
typedef|typedef
name|PtrTy
name|pointer
typedef|;
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
name|explicit
name|SmallPtrSetIterator
argument_list|(
specifier|const
name|void
operator|*
specifier|const
operator|*
name|BP
argument_list|)
operator|:
name|SmallPtrSetIteratorImpl
argument_list|(
argument|BP
argument_list|)
block|{}
comment|// Most methods provided by baseclass.
specifier|const
name|PtrTy
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|PtrTraits
operator|::
name|getFromVoidPointer
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|*
name|Bucket
operator|)
argument_list|)
return|;
block|}
specifier|inline
name|SmallPtrSetIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
operator|++
name|Bucket
block|;
name|AdvanceIfNotValid
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|SmallPtrSetIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|SmallPtrSetIterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// NextPowerOfTwo - This is a helper template that rounds N up to the next
end_comment

begin_comment
comment|/// power of two.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|>
expr|struct
name|NextPowerOfTwo
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// NextPowerOfTwoH - If N is not a power of two, increase it.  This is a helper
end_comment

begin_comment
comment|/// template used to implement NextPowerOfTwo.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|,
name|bool
name|isPowerTwo
operator|>
expr|struct
name|NextPowerOfTwoH
block|{   enum
block|{
name|Val
operator|=
name|N
block|}
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|>
expr|struct
name|NextPowerOfTwoH
operator|<
name|N
operator|,
name|false
operator|>
block|{   enum
block|{
comment|// We could just use NextVal = N+1, but this converges faster.  N|(N-1) sets
comment|// the right-most zero bits to one all at once, e.g. 0b0011000 -> 0b0011111.
name|Val
operator|=
name|NextPowerOfTwo
operator|<
operator|(
name|N
operator||
operator|(
name|N
operator|-
literal|1
operator|)
operator|)
operator|+
literal|1
operator|>
operator|::
name|Val
block|}
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|>
expr|struct
name|NextPowerOfTwo
block|{   enum
block|{
name|Val
operator|=
name|NextPowerOfTwoH
operator|<
name|N
block|,
operator|(
name|N
operator|&
operator|(
name|N
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|>
operator|::
name|Val
block|}
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// SmallPtrSet - This class implements a set which is optimizer for holding
end_comment

begin_comment
comment|/// SmallSize or less elements.  This internally rounds up SmallSize to the next
end_comment

begin_comment
comment|/// power of two if it is not already a power of two.  See the comments above
end_comment

begin_comment
comment|/// SmallPtrSetImpl for details of the algorithm.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|PtrType
operator|,
name|unsigned
name|SmallSize
operator|>
name|class
name|SmallPtrSet
operator|:
name|public
name|SmallPtrSetImpl
block|{
comment|// Make sure that SmallSize is a power of two, round up if not.
block|enum
block|{
name|SmallSizePowTwo
operator|=
name|NextPowerOfTwo
operator|<
name|SmallSize
operator|>
operator|::
name|Val
block|}
block|;
name|void
operator|*
name|SmallArray
index|[
name|SmallSizePowTwo
index|]
block|;
typedef|typedef
name|PointerLikeTypeTraits
operator|<
name|PtrType
operator|>
name|PtrTraits
expr_stmt|;
name|public
operator|:
name|SmallPtrSet
argument_list|()
operator|:
name|SmallPtrSetImpl
argument_list|(
argument|NextPowerOfTwo<SmallSizePowTwo>::Val
argument_list|)
block|{}
name|SmallPtrSet
argument_list|(
specifier|const
name|SmallPtrSet
operator|&
name|that
argument_list|)
operator|:
name|SmallPtrSetImpl
argument_list|(
argument|that
argument_list|)
block|{}
name|template
operator|<
name|typename
name|It
operator|>
name|SmallPtrSet
argument_list|(
argument|It I
argument_list|,
argument|It E
argument_list|)
operator|:
name|SmallPtrSetImpl
argument_list|(
argument|NextPowerOfTwo<SmallSizePowTwo>::Val
argument_list|)
block|{
name|insert
argument_list|(
name|I
argument_list|,
name|E
argument_list|)
block|;   }
comment|/// insert - This returns true if the pointer was new to the set, false if it
comment|/// was already in the set.
name|bool
name|insert
argument_list|(
argument|PtrType Ptr
argument_list|)
block|{
return|return
name|insert_imp
argument_list|(
name|PtrTraits
operator|::
name|getAsVoidPointer
argument_list|(
name|Ptr
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// erase - If the set contains the specified pointer, remove it and return
end_comment

begin_comment
comment|/// true, otherwise return false.
end_comment

begin_function
name|bool
name|erase
parameter_list|(
name|PtrType
name|Ptr
parameter_list|)
block|{
return|return
name|erase_imp
argument_list|(
name|PtrTraits
operator|::
name|getAsVoidPointer
argument_list|(
name|Ptr
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// count - Return true if the specified pointer is in the set.
end_comment

begin_decl_stmt
name|bool
name|count
argument_list|(
name|PtrType
name|Ptr
argument_list|)
decl|const
block|{
return|return
name|count_imp
argument_list|(
name|PtrTraits
operator|::
name|getAsVoidPointer
argument_list|(
name|Ptr
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|IterT
operator|>
name|void
name|insert
argument_list|(
argument|IterT I
argument_list|,
argument|IterT E
argument_list|)
block|{
for|for
control|(
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|insert
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|SmallPtrSetIterator
operator|<
name|PtrType
operator|>
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SmallPtrSetIterator
operator|<
name|PtrType
operator|>
name|const_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|inline
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|CurArray
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|CurArray
operator|+
name|CurArraySize
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Allow assignment from any smallptrset with the same element type even if it
end_comment

begin_comment
comment|// doesn't have the same smallsize.
end_comment

begin_expr_stmt
specifier|const
name|SmallPtrSet
operator|<
name|PtrType
operator|,
name|SmallSize
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SmallPtrSet
operator|<
name|PtrType
operator|,
name|SmallSize
operator|>
operator|&
name|RHS
operator|)
block|{
name|CopyFrom
argument_list|(
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_endif
unit|};  }
endif|#
directive|endif
end_endif

end_unit

